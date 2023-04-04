#include "DialogSerialSettings.h"
#include <qdebug.h>
#include <qmessagebox.h>

DialogSerialSettings::DialogSerialSettings(CommunicateSerial *serialManager, QWidget *parent)
	: QWidget(parent)
	, m_serialManager(serialManager)
{
	ui.setupUi(this);
	InitVariables();
	InitConnections();
	UpdateCtrls(m_serialManager->GetConnectStatus());

	if (m_serialManager->isConnect)
	{
		FindIndexComBox(m_serialManager->m_ConnectInfo.ComID, ui.cmbName);
		FindIndexComBox(QString::number(m_serialManager->m_ConnectInfo.baudRate), ui.cmbBaudRate);
		FindIndexComBox(QString::number(m_serialManager->m_ConnectInfo.parity), ui.cmbParity);
		FindIndexComBox(QString::number(m_serialManager->m_ConnectInfo.dataBits), ui.cmbDataBits);
		FindIndexComBox(QString::number(m_serialManager->m_ConnectInfo.stopBits), ui.cmbStopBits);
		FindIndexComBox(QString::number(m_serialManager->m_ConnectInfo.flowControl), ui.cmbFlowControl);
		UpdateCtrls(true);
	}
}

void DialogSerialSettings::FindIndexComBox(QString targetName, QComboBox* findBox)
{
	for (int i = 0; i < findBox->count(); i++)
	{
		if (findBox->itemText(i) == targetName)
		{
			findBox->setCurrentIndex(i);
			break;
		}
	}
}

DialogSerialSettings::~DialogSerialSettings()
{
	disconnect(m_serialManager, &CommunicateSerial::receiveData, this, &DialogSerialSettings::ReceiveComData);
	disconnect(m_conn);
}

void DialogSerialSettings::InitVariables()
{
	ui.cmbBaudRate->clear();
	ui.cmbDataBits->clear();
	ui.cmbFlowControl->clear();
	ui.cmbName->clear();
	ui.cmbParity->clear();
	ui.cmbStopBits->clear();
	//串口号
	QStringList names;
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) names.append(info.portName());
	qSort(names);
	for (auto name : names) ui.cmbName->addItem(name);
	if (!m_serialManager->m_ConnectInfo.ComID.isEmpty()) ui.cmbName->setCurrentText(m_serialManager->m_ConnectInfo.ComID);
	else m_serialManager->m_ConnectInfo.ComID = ui.cmbName->currentText();
	//波特率
	ui.cmbBaudRate->addItem("1200");
	ui.cmbBaudRate->addItem("2400");
	ui.cmbBaudRate->addItem("4800");
	ui.cmbBaudRate->addItem("9600");
	ui.cmbBaudRate->addItem("19200");
	ui.cmbBaudRate->addItem("38400");
	ui.cmbBaudRate->addItem("57600");
	ui.cmbBaudRate->addItem("115200");
	ui.cmbBaudRate->setCurrentText(QString::number(m_serialManager->m_ConnectInfo.baudRate));
	//校验位
	ui.cmbParity->addItem("NoParity");
	ui.cmbParity->addItem("EvenParity");
	ui.cmbParity->addItem("OddParity");
	ui.cmbParity->addItem("SpaceParity");
	ui.cmbParity->addItem("MarkParity");
	int parity = m_serialManager->m_ConnectInfo.parity;
	ui.cmbParity->setCurrentIndex(parity == 0 ? 0 : parity - 1);
	//数据位
	ui.cmbDataBits->addItem("5");
	ui.cmbDataBits->addItem("6");
	ui.cmbDataBits->addItem("7");
	ui.cmbDataBits->addItem("8");
	ui.cmbDataBits->setCurrentText(QString::number(m_serialManager->m_ConnectInfo.dataBits));
	//停止位
	ui.cmbStopBits->addItem("1");
	ui.cmbStopBits->addItem("2");
	ui.cmbStopBits->addItem("1.5");
	ui.cmbStopBits->setCurrentIndex(m_serialManager->m_ConnectInfo.stopBits - 1);
	//流控制
	ui.cmbFlowControl->addItem("None");
	ui.cmbFlowControl->addItem("Hardware");
	ui.cmbFlowControl->addItem("Software");
	ui.cmbFlowControl->setCurrentIndex(m_serialManager->m_ConnectInfo.flowControl);
	//日志框
	ui.textEditLog->setEnabled(false);
}

void DialogSerialSettings::InitConnections()
{
	m_conn = connect(m_serialManager, &CommunicateSerial::connectStatusChanged, [&](bool isOpen) {
		UpdateCtrls(isOpen);
	});
	connect(m_serialManager, &CommunicateSerial::receiveData, this, &DialogSerialSettings::ReceiveComData);
	connect(ui.cmbName, &QComboBox::currentTextChanged, [&](QString text) {
		m_serialManager->m_ConnectInfo.ComID = text;
	});
	connect(ui.cmbBaudRate, &QComboBox::currentTextChanged, [&](QString text) {
		m_serialManager->m_ConnectInfo.baudRate = text.toInt();
	});
	connect(ui.cmbParity, qOverload<int>(&QComboBox::currentIndexChanged), [&](int index) {
		m_serialManager->m_ConnectInfo.parity = index == 0 ? index : index + 1;
	});
	connect(ui.cmbDataBits, &QComboBox::currentTextChanged, [&](QString text) {
		m_serialManager->m_ConnectInfo.dataBits = text.toInt();
	});
	connect(ui.cmbStopBits, qOverload<int>(&QComboBox::currentIndexChanged), [&](int index) {
		m_serialManager->m_ConnectInfo.stopBits = index + 1;
	});
	connect(ui.cmbFlowControl, qOverload<int>(&QComboBox::currentIndexChanged), [&](int index) {
		m_serialManager->m_ConnectInfo.flowControl = index;
	});
}

void DialogSerialSettings::ReceiveComData(QString data)
{
	ui.textEditLog->append("Receive:" + data);
}

void DialogSerialSettings::UpdateCtrls(bool isOpen)
{
	ui.btnOpenSerial->setEnabled(!isOpen);
	ui.btnCloseSerial->setEnabled(isOpen);
	ui.btnSend->setEnabled(isOpen);
	ui.cmbName->setEnabled(!isOpen);
	ui.cmbBaudRate->setEnabled(!isOpen);
	ui.cmbParity->setEnabled(!isOpen);
	ui.cmbDataBits->setEnabled(!isOpen);
	ui.cmbStopBits->setEnabled(!isOpen);
	ui.cmbFlowControl->setEnabled(!isOpen);
}

void DialogSerialSettings::on_btnOpenSerial_clicked()
{
	if (!m_serialManager->OpenSerial())
	{
		QMessageBox::information(this, "Error", QStringLiteral("Open Serial Fail!"));
	}
}

void DialogSerialSettings::on_btnCloseSerial_clicked()
{
	m_serialManager->CloseSerial();
}

void DialogSerialSettings::on_btnSend_clicked()
{
	if (!m_serialManager->GetConnectStatus()) return;
	QString data = ui.textEditSend->toPlainText();
	m_serialManager->SendData(data);
	ui.textEditLog->append("Send:" + data);
}

void DialogSerialSettings::on_btnClearLog_clicked()
{
	ui.textEditLog->clear();
}

void DialogSerialSettings::on_btnClearSend_clicked()
{
	ui.textEditSend->clear();
}
