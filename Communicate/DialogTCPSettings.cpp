#include "DialogTCPSettings.h"
#include <QNetworkInterface>
#include <qmessagebox.h>

DialogTCPSettings::DialogTCPSettings(CommunicateTCP *tcp, QWidget *parent)
	: QWidget(parent)
	, m_tcpManager(tcp)
{
	ui.setupUi(this);
	InitVariables();
	InitConnections();
	updateCtrls(false);

	if (tcp->IsServerConnected()) //已连接
	{
		ui.cmbProtocol->setCurrentIndex(tcp->m_Config.m_mode);
		ui.lineEditIP->setText(m_tcpManager->m_Config.IpStr);
		ui.lineEditPort->setText(QString::number(m_tcpManager->m_Config.Port));
		updateCtrls(true);
		if (tcp->m_Config.m_mode == 0) //服务器
			ui.cmbClient->addItems(tcp->GetConnectClient());
	}

	connect(ui.cmbProtocol, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, [=](int index)
	{
		if (index == 1)
		{
			ui.labelAddress->setText(tr("Target IP Adress"));
			ui.labelPort->setText(tr("Target Port"));
		}
		else
		{
			ui.labelAddress->setText(tr("Local IP Adress"));
			ui.labelPort->setText(tr("Local Port"));
		}
	});

	// 正在表达式限制输入
	QRegExp rx("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
	QRegExpValidator *m_IP = new QRegExpValidator(rx, this);
	ui.lineEditIP->setValidator(m_IP);

	ui.lineEditPort->setValidator(new QIntValidator(0, 99999999, this));
}

DialogTCPSettings::~DialogTCPSettings()
{
	/*disconnect(m_tcpManager, &CommunicateTCP::SendConnectStatus, this, &DialogTCPSettings::SendConnectStatusSlot);
	disconnect(m_tcpManager, &CommunicateTCP::SendReadMessage, this, &DialogTCPSettings::SendReadMessageSlot);
	disconnect(m_tcpManager, &CommunicateTCP::Error, this, &DialogTCPSettings::ErrorSlot);
	disconnect(m_tcpManager, &CommunicateTCP::AddClient, this, &DialogTCPSettings::AddClientSlot);
	disconnect(m_tcpManager, &CommunicateTCP::RemoveClient, this, &DialogTCPSettings::RemoveClientSlot);*/
}

QString GetLocalIP()
{
	QList<QHostAddress> list = QNetworkInterface::allAddresses();
	foreach(QHostAddress address, list)
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			return address.toString();
		}
	}
	return "";
}

void DialogTCPSettings::InitVariables()
{
	ui.cmbProtocol->addItem("TCP Server");
	ui.cmbProtocol->addItem("TCP Client");
	ui.cmbProtocol->addItem("UDP");


	if (m_tcpManager->m_Config.IpStr.size() != 0)
	{
		ui.cmbProtocol->setCurrentIndex(m_tcpManager->m_Config.m_mode);
		ui.lineEditIP->setText(m_tcpManager->m_Config.IpStr);
		ui.lineEditPort->setText(QString::number(m_tcpManager->m_Config.Port));
	}
	else
	{
		ui.lineEditIP->setText(GetLocalIP());
		ui.lineEditPort->setText("8080");
	}
}

void DialogTCPSettings::InitConnections()
{
	/*connect(ui.cmbProtocol, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index) {
		updateCtrls(false);
	});*/
	connect(m_tcpManager, &CommunicateTCP::SendConnectStatus,this, &DialogTCPSettings::SendConnectStatusSlot);
	connect(m_tcpManager, &CommunicateTCP::SendReadMessage, this, &DialogTCPSettings::SendReadMessageSlot);
	connect(m_tcpManager, &CommunicateTCP::Error, this, &DialogTCPSettings::ErrorSlot);
	connect(m_tcpManager, &CommunicateTCP::AddClient, this, &DialogTCPSettings::AddClientSlot);
	connect(m_tcpManager, &CommunicateTCP::RemoveClient, this, &DialogTCPSettings::RemoveClientSlot);

	connect(ui.btn_ReceiveClear, &QPushButton::clicked, this, [=]() { ui.textEditReceive->clear(); });
	connect(ui.btn_SendClear, &QPushButton::clicked, this, [=]() { ui.textEditSend->clear(); });
	//connect(ui.btnDisConnect, &QPushButton::clicked, this, &DialogTCPSettings::on_btnDisConnect_clicked);

	connect(ui.lineEditIP, &QLineEdit::editingFinished, this, &DialogTCPSettings::ConfigChangeEvent);
	connect(ui.lineEditPort, &QLineEdit::editingFinished, this, &DialogTCPSettings::ConfigChangeEvent);
	connect(ui.cmbProtocol, &QComboBox::currentTextChanged, this, [=](QString text) { ConfigChangeEvent(); });
}

void DialogTCPSettings::ErrorSlot(QString msg)
{
	QMessageBox::information(this, "Error", msg);
}
void DialogTCPSettings::AddClientSlot(QString client)
{
	ui.cmbClient->addItem(client);
}
void DialogTCPSettings::RemoveClientSlot(QString client)
{
	ui.cmbClient->removeItem(ui.cmbClient->findText(client));
}
void DialogTCPSettings::SendConnectStatusSlot(bool status)
{
	updateCtrls(status);
}
void DialogTCPSettings::SendReadMessageSlot(QString msg, QString ip, quint16 port)
{
	QString text = "[Receive from " + ip + ":" + QString::number(port) + "]:" + msg;
	ui.textEditReceive->append(text);
}

void DialogTCPSettings::updateCtrls(bool isConnected)
{
	ui.widgetConnectors->setVisible(ui.cmbProtocol->currentIndex() == 0 && isConnected);
	ui.widgetLocal->setVisible(ui.cmbProtocol->currentIndex() == 1 && isConnected);
	ui.btnConnect->setEnabled(!isConnected);
	ui.btnDisConnect->setEnabled(isConnected);
	ui.cmbProtocol->setEnabled(!isConnected);
	ui.lineEditIP->setEnabled(!isConnected);
	ui.lineEditPort->setEnabled(!isConnected);
	ui.lineEditLocalIP->setText(isConnected ? m_tcpManager->LocalAddress() : "");
	ui.lineEditLocalPort->setText(QString::number(isConnected ? m_tcpManager->LocalPort() : 0));
	ui.labelAddress->setText(ui.cmbProtocol->currentIndex() == 1 ? QStringLiteral("Server IP Address") : QStringLiteral("Local IP Address"));
	ui.labelPort->setText(ui.cmbProtocol->currentIndex() == 1 ? QStringLiteral("Server Port") : QStringLiteral("Local Port"));
}

void DialogTCPSettings::on_btnConnect_clicked()
{
	if (ui.lineEditIP->text().size() == 0) QMessageBox::information(nullptr, tr("tips"), tr("Ip input cannot be empty"));
	if (ui.lineEditPort->text().size() == 0) QMessageBox::information(nullptr, tr("tips"), tr("Port input cannot be empty"));

	switch (ui.cmbProtocol->currentIndex())
	{
	case 0:
		m_tcpManager->isConnect = m_tcpManager->CreateServer(ui.lineEditIP->text(), ui.lineEditPort->text().toInt());
		break;
	case 1:
		m_tcpManager->isConnect = m_tcpManager->ConnectToServer(ui.lineEditIP->text(), ui.lineEditPort->text().toInt());
		break;
	case 2:	
		break;
	}
	if (m_tcpManager->isConnect)
	{
		m_tcpManager->m_Config.IpStr = ui.lineEditIP->text();
		m_tcpManager->m_Config.Port = ui.lineEditPort->text().toInt();
		m_tcpManager->m_Config.m_mode = ui.cmbProtocol->currentIndex();
	}
}

void DialogTCPSettings::on_btnDisConnect_clicked()
{
	m_tcpManager->DisconnectServer();
}

void DialogTCPSettings::on_btnSend_clicked()
{
	switch (ui.cmbProtocol->currentIndex())
	{
	case 0:
		m_tcpManager->SendMessage2Client(ui.cmbClient->currentText(), ui.textEditSend->toPlainText());
		break;
	case 1:
		m_tcpManager->SendMessage2Server(ui.textEditSend->toPlainText());
		break;
	case 2:		
		break;
	default:
		break;
	}
}

void DialogTCPSettings::ConfigChangeEvent()
{
	m_tcpManager->m_Config.IpStr = ui.lineEditIP->text();
	m_tcpManager->m_Config.Port = ui.lineEditPort->text().toInt();
	m_tcpManager->m_Config.m_mode = ui.cmbProtocol->currentIndex();
}
