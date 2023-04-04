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

//相机软触发连接类
class SoftTriggerConnect : public QObject
{
	Q_OBJECT
public:
	SoftTriggerConnect();
	~SoftTriggerConnect();
	static SoftTriggerConnect *GetInstance();
	// 绑定相机与通讯对象 - 软触发连接
	bool Binding(Camera* inCamera, CommunicateBase* inCommunicate, QString grabStr);
	// 解绑当前相机的软触发连接
	void UnBinding(Camera* inCamera);
	// 获取当前绑定连接的触发字符
	QString GetGrabStr(Camera* inCamera);
	// 获取当前绑定连接的通讯对象
	QString GetCommunication(Camera* inCamera);
	// 控制当前是否触发的标志位 - 软件点击了连续运行才可以软触发取图
	bool isCameraConnectAlgo = false;
	// 设置软件运行状态的回调函数 - 用于断开连接时停止工作
	std::function<void(bool)> WorkStateChangePtr;
private:
	// Tcp与串口的具体连接
	void TcpAndSerialBind(QString receiveData);
private slots:
	// 通讯对象断开连接的槽函数
	void CommunicateDisconnectSlot();
private:
	std::vector<ConnectInfo> m_BingInfo;  
	static SoftTriggerConnect *m_Instance;
};

