#include "DialogMCBinSetting.h"
#include <QMessageBox>
#include "CommunicateMC_Bin.h"

DialogMCBinSetting::DialogMCBinSetting(CommunicateMC_Bin *in_MCBin, QWidget *parent)
	: QWidget(parent)
	, m_MCBin(in_MCBin)
{
	ui.setupUi(this);
	InitVariables();
	InitConnections();
	updateCtrls(false);
}

DialogMCBinSetting::~DialogMCBinSetting()
{}

void DialogMCBinSetting::InitVariables()
{
	ui.lineEdit_IpStr->setText(m_MCBin->m_Config.IpStr);
	ui.lineEdit_Port->setText(QString::number(m_MCBin->m_Config.Port));
	ui.lineEdit_Addres->setText(m_MCBin->m_Config.Address);
}

void DialogMCBinSetting::updateCtrls(bool isConnected)
{
	ui.label->setEnabled(!isConnected);
	ui.label_2->setEnabled(!isConnected);
	ui.label_3->setEnabled(!isConnected);
	ui.lineEdit_Port->setEnabled(!isConnected);
	ui.lineEdit_IpStr->setEnabled(!isConnected);
	ui.lineEdit_Port->setEnabled(!isConnected);
	ui.btn_Connet->setEnabled(!isConnected);
	ui.btn_DisConnect->setEnabled(isConnected);

	ui.textEdit_Read->setEnabled(isConnected);
	ui.textEdit_Write->setEnabled(isConnected);
	ui.btn_DoubleRead->setEnabled(isConnected);
	ui.btn_DoubleWrite->setEnabled(isConnected);
	ui.btn_IntRead->setEnabled(isConnected);
	ui.btn_IntWrite->setEnabled(isConnected);
	ui.btn_StringRead->setEnabled(isConnected);
	ui.btn_StringWrite->setEnabled(isConnected);
	ui.textEdit_Read->setEnabled(isConnected);
}

void DialogMCBinSetting::InitConnections()
{
	connect(ui.btn_Connet, &QPushButton::clicked, this, [=]() {
		m_MCBin->m_Config.IpStr = ui.lineEdit_IpStr->text();
		m_MCBin->m_Config.Port = ui.lineEdit_Port->text().toInt();
		m_MCBin->m_Config.Address = ui.lineEdit_Addres->text();
		bool isSuccess = m_MCBin->Open();
		if (isSuccess == false)
			QMessageBox::information(NULL, tr("Tips"), tr("Connection failed!"));
		updateCtrls(isSuccess);
	});
	connect(ui.btn_DisConnect, &QPushButton::clicked, this, [=]() {
		bool isSuccess = m_MCBin->Close();
		if (isSuccess == false)
			QMessageBox::information(NULL, tr("Tips"), tr("Disconnection failed!"));
		updateCtrls(isSuccess);
	});

	connect(ui.btn_DoubleRead, &QPushButton::clicked, this, [=]() {
		double m_double;
		bool isSuccess = m_MCBin->Read(ui.lineEdit_Addres->text(),m_double);
		if (isSuccess)
			ui.textEdit_Read->append(tr("[Reading Float Successfully]: ") + QString::number(m_double));
		else
			ui.textEdit_Read->append(tr("[Reading Float Fail]"));
	});
	connect(ui.btn_DoubleWrite, &QPushButton::clicked, this, [=]() {
		if (ui.lineEdit_InputData->text().size() == 0)
		{
			QMessageBox::information(NULL, tr("Tips"), tr("Please enter data")); return;
		}
		bool isSuccess = m_MCBin->Write(ui.lineEdit_Addres->text(),ui.lineEdit_InputData->text().toDouble());
		if (isSuccess)
			ui.textEdit_Write->append(tr("[Writing Float Successfully]: Write ") + ui.lineEdit_InputData->text());
		else
			ui.textEdit_Write->append(tr("[Writing Float Fail]"));
	});
	connect(ui.btn_IntRead, &QPushButton::clicked, this, [=]() {
		int m_Int;
		bool isSuccess = m_MCBin->Read(ui.lineEdit_Addres->text(), m_Int);
		if (isSuccess)
			ui.textEdit_Read->append(tr("[Reading Int Successfully]: ") + QString::number(m_Int));
		else
			ui.textEdit_Read->append(tr("[Reading Int Fail]"));
	});
	connect(ui.btn_IntWrite, &QPushButton::clicked, this, [=]() {
		if (ui.lineEdit_InputData->text().size() == 0)
		{
			QMessageBox::information(NULL, tr("Tips"), tr("Please enter data")); return;
		}
		bool isSuccess = m_MCBin->Write(ui.lineEdit_Addres->text(), ui.lineEdit_InputData->text().toInt());
		if (isSuccess)
			ui.textEdit_Write->append(tr("[Writing Int Successfully]: Write ") + ui.lineEdit_InputData->text());
		else
			ui.textEdit_Write->append(tr("[Writing Int Fail]"));
	});
	connect(ui.btn_StringRead, &QPushButton::clicked, this, [=]() {
		QMessageBox::information(NULL, tr("Tips"), tr("No Used")); return;
	});
	connect(ui.btn_StringWrite, &QPushButton::clicked, this, [=]() {
		if (ui.lineEdit_InputData->text().size() == 0)
		{
			QMessageBox::information(NULL, tr("Tips"), tr("Please enter data")); return;
		}
		bool isSuccess = m_MCBin->Write(ui.lineEdit_Addres->text(), ui.lineEdit_InputData->text());
		if (isSuccess)
			ui.textEdit_Write->append(tr("[Writing String Successfully]: Write ") + ui.lineEdit_InputData->text());
		else
			ui.textEdit_Write->append(tr("[Writing String Fail]"));
	});
}
