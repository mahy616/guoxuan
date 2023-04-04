#include "SoftTriggerConnect.h"
#include "components/Config/ConfigProgramme.h"

SoftTriggerConnect *SoftTriggerConnect::m_Instance = NULL;
SoftTriggerConnect *SoftTriggerConnect::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new SoftTriggerConnect();
	}
	return m_Instance;
}

SoftTriggerConnect::SoftTriggerConnect()
{

}

SoftTriggerConnect::~SoftTriggerConnect()
{
	for (auto ConnectInfo : m_BingInfo)
	{
		if (ConnectInfo.m_Communicate != nullptr)
		{
			disconnect(ConnectInfo.m_Communicate, &CommunicateBase::receiveData, this, &SoftTriggerConnect::TcpAndSerialBind);
		}
	}
}

bool SoftTriggerConnect::Binding(Camera* inCamera, CommunicateBase* inCommunicate, QString grabStr)
{
	if (inCamera == nullptr || inCommunicate == nullptr) return false;

	ConnectInfo connectInfos; 
	connectInfos.grabStr = grabStr; 
	connectInfos.m_Communicate = inCommunicate;
	connectInfos.m_Camera = inCamera;
	m_BingInfo.push_back(connectInfos);

	bool isSuccess = false;
	if (inCommunicate->GetCommunicationType() == "Serial Port" || inCommunicate->GetCommunicationType() == "Ethernet Port")
	{
		isSuccess = connect(inCommunicate, &CommunicateBase::receiveData, this, &SoftTriggerConnect::TcpAndSerialBind);
		if (isSuccess)
		{
			connect(inCommunicate, &CommunicateBase::DisConnectSignals, this, &SoftTriggerConnect::CommunicateDisconnectSlot);
		}
	}
	return isSuccess;
}

void SoftTriggerConnect::UnBinding(Camera* inCamera)
{
	for (int i=0;i< m_BingInfo.size();i++)
	{
		ConnectInfo infos = m_BingInfo[i];
		if (infos.m_Camera== inCamera)
		{
			if (infos.m_Communicate->GetCommunicationType() == "Serial Port" || infos.m_Communicate->GetCommunicationType() == "Ethernet Port")
			{
				disconnect(infos.m_Communicate, &CommunicateBase::receiveData, this, &SoftTriggerConnect::TcpAndSerialBind);
			}
			m_BingInfo.erase(m_BingInfo.begin() + i);
		}
	}
}

void SoftTriggerConnect::TcpAndSerialBind(QString receiveData)
{
	CommunicateBase* CommunicatePtr = qobject_cast<CommunicateBase*>(sender());
	for (auto ConnectInfo : m_BingInfo)
	{
		if (ConnectInfo.m_Communicate == CommunicatePtr)
		{
			if (receiveData == ConnectInfo.grabStr)
			{
				if (isCameraConnectAlgo)
				{
					//ConnectInfo.m_Camera->GrabSingle();
					ConnectInfo.m_Camera->Trigger();
				}
			}
			break;
		}
	}
}


QString SoftTriggerConnect::GetGrabStr(Camera* inCamera)
{
	QString returnStr;
	for (auto ConnectInfo : m_BingInfo)
	{
		if (ConnectInfo.m_Camera == inCamera)
		{
			returnStr = ConnectInfo.grabStr;
			break;
		}
	}
	return returnStr;
}

QString SoftTriggerConnect::GetCommunication(Camera* inCamera)
{
	QString MapKey;
	CommunicateBase* GetCommunicate = nullptr;
	for (auto ConnectInfo : m_BingInfo)
	{
		if (ConnectInfo.m_Camera == inCamera)
		{
			GetCommunicate = ConnectInfo.m_Communicate;
			break;
		}
	}
	QMap<QString, CommunicateBase*>::Iterator it = ConfigProgramme::GetInstance()->m_Comunicate.begin();
	while (it != ConfigProgramme::GetInstance()->m_Comunicate.end())
	{
		if (it.value() == GetCommunicate)
			MapKey = it.key();
		it++;
	}
	return MapKey;
}

void SoftTriggerConnect::CommunicateDisconnectSlot()
{
	WorkStateChangePtr(false);
	//UnBinding(m_camera);
}