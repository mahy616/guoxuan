#include "CommunicateMC_Bin.h"
#include "MC_Bin/melsec_mc_bin.h"
#include "MC_Bin/melsec_mc_ascii.h"

#ifdef _WIN32
#include <WinSock2.h>
#endif

CommunicateMC_Bin::CommunicateMC_Bin()
{
#ifdef _WIN32
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
	InitVariables();
}

CommunicateMC_Bin::~CommunicateMC_Bin()
{

}

void CommunicateMC_Bin::InitVariables()
{
	m_fd = -1;
	isConnect = false;
}

void CommunicateMC_Bin::InitializationJson(QJsonObject inValue)
{
	m_Config.IpStr = inValue["IP"].toString();
	m_Config.Port = inValue["Port"].toInt();
	m_Config.Address = inValue["Address"].toString();
	isConnect = inValue["isConnect"].toBool();
	if (isConnect)
	{
		isConnect = Open();
	}
}

QJsonObject CommunicateMC_Bin::GetConfigJson()
{
	QJsonObject json;
	json.insert("IP", QJsonValue(m_Config.IpStr));
	json.insert("Port", QJsonValue(m_Config.Port));
	json.insert("Address", QJsonValue(m_Config.Address));
	json.insert("isConnect", QJsonValue(isConnect));
	return json;
}

bool CommunicateMC_Bin::Open()
{
	m_Mutex.lock();
	m_fd = mc_connect((char*)m_Config.IpStr.toStdString().c_str(), m_Config.Port, 0, 0);
	isConnect = m_fd > 0;

	std::cout << "plcÁ¬½Ó£º" << m_fd << std::endl;
	//std::cout << "IP£º" << m_Config.IpStr.toStdString << ", inPORT£º" << m_Config.Port << ", MyAddr£º" << m_Config.Address.toStdString() << std::endl;

	m_Mutex.unlock();

	return isConnect;
}

bool CommunicateMC_Bin::Close()
{
	if (isConnect)
	{
		bool rv = false;
		mc_disconnect(m_fd);
		isConnect = !rv;
		return rv;
	}
	return false;
}

bool CommunicateMC_Bin::Write(QString address, QString message)
{
	bool flag = false;
	m_Mutex.lock();
	if (m_fd > 0)
	{
		flag = mc_write_string(m_fd, address.toStdString().c_str(), message.toStdString().size(), message.toStdString().c_str());
	}
	else
	{
		m_Mutex.unlock();
		return false;
	}
	m_Mutex.unlock();
	return flag;
}

bool CommunicateMC_Bin::Write(QString address, int inNum)
{
	bool flag = false;
	m_Mutex.lock();
	if (m_fd > 0)
	{
		flag = mc_write_int32(m_fd, address.toStdString().c_str(), inNum);
	}
	else
	{
		m_Mutex.unlock();
		return false;
	}
	m_Mutex.unlock();
	return flag;
}

bool CommunicateMC_Bin::Write(QString address, double infloat)
{
	bool flag = false;
	m_Mutex.lock();
	if (m_fd > 0)
	{
		flag = mc_write_double(m_fd, address.toStdString().c_str(), infloat);
	}
	else
	{
		m_Mutex.unlock();
		return false;
	}
	m_Mutex.unlock();
	return flag;
}

bool CommunicateMC_Bin::Read(QString address, QString &input)
{
	
	return true;
}

bool CommunicateMC_Bin::Read(QString address, int &input)
{
	bool flag = false;
	m_Mutex.lock();
	if (m_fd > 0)
	{
		flag = mc_read_int32(m_fd, address.toStdString().c_str(), &input);
	}
	else
	{
		m_Mutex.unlock();
		return false;
	}
	m_Mutex.unlock();
	return flag;
}

bool CommunicateMC_Bin::Read(QString address, double &input)
{
	bool flag = false;
	m_Mutex.lock();
	if (m_fd > 0)
	{
		flag = mc_read_double(m_fd, address.toStdString().c_str(), &input);
	}
	else
	{
		m_Mutex.unlock();
		return false;
	}
	m_Mutex.unlock();
	return flag;
}

bool CommunicateMC_Bin::write_bool(const char * address, bool val)
{
	return  mc_write_bool(m_fd, address, val);
}

QWidget* CommunicateMC_Bin::OpenSetting()
{
	DialogMCBinSetting *m_Test = new DialogMCBinSetting(this);
	return m_Test;
}

QString CommunicateMC_Bin::GetCommunicationType()
{
	return tr("Mitsubishi MC");
}