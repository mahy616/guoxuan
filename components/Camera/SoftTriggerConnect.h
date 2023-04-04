#pragma once
#include <QObject>
#include <QMap>
#include "components/Camera/Camera.h"
#include "Communicate/CommunicateBase.h"

typedef struct ConnectInfo
{
	Camera* m_Camera;
	CommunicateBase* m_Communicate;
	QString grabStr;
}ConnectInfo;

//�������������
class SoftTriggerConnect : public QObject
{
	Q_OBJECT
public:
	SoftTriggerConnect();
	~SoftTriggerConnect();
	static SoftTriggerConnect *GetInstance();
	// �������ͨѶ���� - ��������
	bool Binding(Camera* inCamera, CommunicateBase* inCommunicate, QString grabStr);
	// ���ǰ�������������
	void UnBinding(Camera* inCamera);
	// ��ȡ��ǰ�����ӵĴ����ַ�
	QString GetGrabStr(Camera* inCamera);
	// ��ȡ��ǰ�����ӵ�ͨѶ����
	QString GetCommunication(Camera* inCamera);
	// ���Ƶ�ǰ�Ƿ񴥷��ı�־λ - ���������������вſ�������ȡͼ
	bool isCameraConnectAlgo = false;
	// �����������״̬�Ļص����� - ���ڶϿ�����ʱֹͣ����
	std::function<void(bool)> WorkStateChangePtr;
private:
	// Tcp�봮�ڵľ�������
	void TcpAndSerialBind(QString receiveData);
private slots:
	// ͨѶ����Ͽ����ӵĲۺ���
	void CommunicateDisconnectSlot();
private:
	std::vector<ConnectInfo> m_BingInfo;  
	static SoftTriggerConnect *m_Instance;
};

