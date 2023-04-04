#include "CommunicateSerial.h"

CommunicateSerial::CommunicateSerial()
{
	InitConnections();
}

CommunicateSerial::~CommunicateSerial()
{
	CloseSerial();
}

bool CommunicateSerial::OpenSerial()
{
	m_SerialPort.setPortName(m_ConnectInfo.ComID);
	m_SerialPort.setBaudRate(m_ConnectInfo.baudRate);
	m_SerialPort.setDataBits(QSerialPort::DataBits(m_ConnectInfo.dataBits));
	m_SerialPort.setStopBits(QSerialPort::StopBits(m_ConnectInfo.stopBits));
	m_SerialPort.setParity(QSerialPort::Parity(m_ConnectInfo.parity));
	m_SerialPort.setFlowControl(QSerialPort::FlowControl(m_ConnectInfo.flowControl));
	isConnect = m_SerialPort.open(QSerialPort::ReadWrite);
	emit connectStatusChanged(m_SerialPort.isOpen());
	return isConnect;
}

void CommunicateSerial::CloseSerial()
{
	if (m_SerialPort.isOpen())
	{
		m_SerialPort.close();
		isConnect = m_SerialPort.isOpen();
		emit connectStatusChanged(isConnect);
		emit DisConnectSignals();
	}
}

bool CommunicateSerial::GetConnectStatus()
{
	return m_SerialPort.isOpen();
}

void CommunicateSerial::SendData(QString data)
{
	QByteArray ba = data.toLatin1();
	m_SerialPort.write(ba);
}

void CommunicateSerial::SendData(QByteArray data)
{
	m_SerialPort.write(data);
}

QWidget* CommunicateSerial::OpenSetting()
{
	DialogSerialSettings *m_SettingDialg = new DialogSerialSettings(this);
	return m_SettingDialg;
}

bool CommunicateSerial::Write(QString message)
{
	QByteArray ba = message.toLatin1();
	m_SerialPort.write(ba);
	return true;
}

void CommunicateSerial::InitConnections()
{
	connect(&m_SerialPort, &QSerialPort::readyRead, [&]() {
		QByteArray ba = m_SerialPort.readAll();
		if (ba.size() > 0)
		{
			QString str = ba.data();
			emit receiveData(str);
		}
	});
}

void CommunicateSerial::InitializationJson(QJsonObject inValue)
{
	m_ConnectInfo.baudRate = inValue["baudRate"].toInt();
	m_ConnectInfo.dataBits = inValue["dataBits"].toInt();
	m_ConnectInfo.stopBits = inValue["stopBits"].toInt();
	m_ConnectInfo.parity = inValue["parity"].toInt();
	m_ConnectInfo.flowControl = inValue["flowControl"].toInt();
	isConnect = inValue["isOpen"].toBool();
	if (isConnect)
	{
		OpenSerial();
	}
}

QJsonObject CommunicateSerial::GetConfigJson()
{
	QJsonObject json;
	json.insert("baudRate", QJsonValue(m_ConnectInfo.baudRate));
	json.insert("dataBits", QJsonValue(m_ConnectInfo.dataBits));
	json.insert("stopBits", QJsonValue(m_ConnectInfo.stopBits));
	json.insert("parity", QJsonValue(m_ConnectInfo.parity));
	json.insert("flowControl", QJsonValue(m_ConnectInfo.flowControl));
	json.insert("isOpen", QJsonValue(m_SerialPort.isOpen()));
	return json;
}

bool CommunicateSerial::Open()
{
	OpenSerial();
	return true;
}
bool CommunicateSerial::Close()
{
	CloseSerial();
	return true;
}

QString CommunicateSerial::GetCommunicationType()
{
	return tr("Serial Port");
}