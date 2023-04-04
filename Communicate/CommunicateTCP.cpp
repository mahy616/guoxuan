#include "CommunicateTCP.h"

CommunicateTCP::CommunicateTCP()
{
	m_Config.m_mode = CLIENT;
	InitConnections();
}

CommunicateTCP::~CommunicateTCP()
{
	if (IsServerConnected())
	{
		DisconnectServer();
	}
}

bool CommunicateTCP::Open()
{
	switch (m_Config.m_mode)
	{
	case 0: //SERVER
		isConnect = CreateServer(m_Config.IpStr, m_Config.Port);
		break;
	case 1: //CLIENT
		isConnect = ConnectToServer(m_Config.IpStr, m_Config.Port);
		break;
	case 2: //UDP
		break;
	default:
		break;
	}
	return isConnect;
}

bool CommunicateTCP::Close()
{
	if (IsServerConnected())
	{
		DisconnectServer();
		isConnect = false;
	}
	return true;
}

void CommunicateTCP::InitializationJson(QJsonObject inValue)
{
	m_Config.IpStr = inValue["IP"].toString();
	m_Config.Port = inValue["Port"].toInt();
	m_Config.m_mode = inValue["Mode"].toInt();

	isConnect = inValue["isConnect"].toBool();
	if (isConnect)
	{
		Open();
	}
}

QJsonObject CommunicateTCP::GetConfigJson()
{
	QJsonObject json;
	json.insert("IP", QJsonValue(m_Config.IpStr));
	json.insert("Port", QJsonValue(m_Config.Port));
	json.insert("Mode", QJsonValue(m_Config.m_mode));
	json.insert("isConnect", QJsonValue(isConnect));
	return json;
}

bool CommunicateTCP::Write(QString message)
{
	switch (m_Config.m_mode)
	{
	case SERVER:
		//对每个连接的客户端都发送消息
		for (std::map<QString, QTcpSocket*>::iterator iter1 = m_tcpConnections.begin(); iter1 != m_tcpConnections.end(); iter1++)
		{
			QByteArray ba = message.toLocal8Bit();
			m_tcpConnections[iter1->first]->write(ba);
			m_tcpConnections[iter1->first]->waitForBytesWritten(100);
			m_tcpConnections[iter1->first]->flush();
		}
		//SendMessage2Client(ui.cmbClient->currentText(), message);
		break;
	case CLIENT:
		SendMessage2Server(message);
		break;
	case UDP:
		break;
	default:
		break;
	}
	return true;
}

void CommunicateTCP::InitConnections()
{
	
	connect(&m_TcpClient, &QTcpSocket::connected, this,[&]() { emit SendConnectStatus(true); isConnect = true; });
	connect(&m_TcpClient, &QTcpSocket::disconnected, [&]() { 
		emit SendConnectStatus(false); 
		emit DisConnectSignals(); 
		isConnect = false; });
	connect(&m_TcpClient, SIGNAL(readyRead()), this, SLOT(ReadMessage()));
	connect(&m_TcpClient, qOverload<QAbstractSocket::SocketError>(&QTcpSocket::error), [&](QAbstractSocket::SocketError) { emit Error(m_TcpClient.errorString()); });
	connect(&m_tcpServer, &QTcpServer::newConnection, this, &CommunicateTCP::NewConnection);
}


bool CommunicateTCP::CreateServer(QString ip, quint16 port)
{
	if (!m_tcpServer.listen(QHostAddress(ip), port))
	{
		emit Error(m_tcpServer.errorString());
	}
	m_Config.m_mode = SERVER;
	emit SendConnectStatus(m_tcpServer.isListening());
	return m_tcpServer.isListening();
}

bool CommunicateTCP::ConnectToServer(QString ip, quint16 port)
{
	if (IsServerConnected())
	{
		m_TcpClient.abort();
		_sleep(100);
	}
	m_TcpClient.connectToHost(ip, port);
	m_TcpClient.waitForConnected(500);
	m_Config.m_mode = CLIENT;

	return m_TcpClient.state() == QAbstractSocket::ConnectedState;
}

void CommunicateTCP::DisconnectServer()
{
	switch (m_Config.m_mode)
	{
	case CLIENT:
		m_TcpClient.disconnectFromHost();
		m_TcpClient.waitForDisconnected(500);
		emit DisConnectSignals();
		break;
	case SERVER:
		m_tcpServer.close();
		for (auto &kv : m_tcpConnections)
		{
			kv.second->close();
			kv.second->deleteLater();
		}
		m_tcpConnections.clear();
		emit SendConnectStatus(m_tcpServer.isListening());
		emit DisConnectSignals();
		break;
	case UDP:
		break;
	default:
		break;
	}
}

bool CommunicateTCP::IsServerConnected()
{
	if(m_Config.m_mode== CLIENT)
		return m_TcpClient.state() == QAbstractSocket::ConnectedState;
	if (m_Config.m_mode == SERVER)
		return m_tcpServer.isListening();
	return false;
}

void CommunicateTCP::SendMessage2Server(QString msg)
{
	if (IsServerConnected())
	{
		QByteArray ba = msg.toLocal8Bit();
		m_TcpClient.write(ba);
		m_TcpClient.waitForBytesWritten(100);
		m_TcpClient.flush();
	}
}

void CommunicateTCP::SendMessage2Client(QString client, QString msg)
{
	if (m_tcpConnections.count(client))
	{
		QByteArray ba = msg.toLocal8Bit();
		m_tcpConnections[client]->write(ba);
		m_tcpConnections[client]->waitForBytesWritten(100);
		m_tcpConnections[client]->flush();
	}
}

//void CommunicateTCP::Settings()
//{
//	DialogTCPSettings dlg(this);
//	dlg.exec();
//}

QString CommunicateTCP::LocalAddress()
{
	if (IsServerConnected()) return m_TcpClient.localAddress().toString();
	return "";
}

quint16 CommunicateTCP::LocalPort()
{
	if (IsServerConnected()) return m_TcpClient.localPort();
	return 0;
}

void CommunicateTCP::ReadMessage()
{
	if (m_TcpClient.state() == QAbstractSocket::ConnectedState)
	{
		QByteArray ba = m_TcpClient.readAll();
		if (ba.size() > 0)
		{			
			auto address = m_TcpClient.peerAddress().toString();
			quint16 port = m_TcpClient.peerPort();
			emit SendReadMessage(ba, address, port);	
			emit receiveData(ba);
		}
	}
}

void CommunicateTCP::NewConnection()
{
	//保存连接实例
	auto socket = m_tcpServer.nextPendingConnection();
	QString clientName = socket->peerAddress().toString() + ":" + QString::number(socket->peerPort());
	m_tcpConnections[clientName] = socket;
	emit AddClient(clientName);

	connect(socket, &QTcpSocket::readyRead, [&]() {
		for (auto pair : m_tcpConnections)
		{
			QByteArray ba = pair.second->readAll();
			if (ba.size() > 0)
			{
				emit SendReadMessage(ba, pair.second->peerAddress().toString(), pair.second->peerPort());
				emit receiveData(ba);
				break;
			}
		}
	});

	QObject::connect(socket, &QTcpSocket::disconnected, this, [&]() {
		QTcpSocket *ss = (QTcpSocket*)sender();
		auto client = ss->peerAddress().toString() + ":" + QString::number(ss->peerPort());
		m_tcpConnections.erase(client);
		emit RemoveClient(client);
	});
}

QWidget* CommunicateTCP::OpenSetting()
{
	DialogTCPSettings *m_SettingDialg = new DialogTCPSettings(this);
	return m_SettingDialg;
}

QStringList CommunicateTCP::GetConnectClient()
{
	QStringList returnStrList;
	for (std::map<QString, QTcpSocket*>::iterator iter1 = m_tcpConnections.begin(); iter1 != m_tcpConnections.end(); iter1++)
	{
		returnStrList.push_back(iter1->first);
	}
	return returnStrList;
}

QString CommunicateTCP::GetCommunicationType()
{
	return "Ethernet Port";
}
