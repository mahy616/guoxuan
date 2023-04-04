#pragma once
#include <qobject.h>
#include <qjsonarray.h>
#include <QJsonObject>
class CommunicateBase : public QObject
{
	Q_OBJECT
public:
	virtual bool Open() = 0; //打开连接
	virtual bool Close() = 0; //关闭连接
	virtual bool isConnectting(); //是否连接
	virtual void InitializationJson(QJsonObject inValue) = 0; //从配置文件读取初始化界面配置
	virtual QJsonObject GetConfigJson() = 0; //获取当前类的配置信息
	virtual QString GetCommunicationType() = 0;
	virtual bool Write(QString message);
	virtual bool Write(QString address,QString message);
	virtual bool Write(QString address, int inNum);
	virtual bool Write(QString address, double infloat);
	virtual bool Read(QString address, QString &input);
	virtual bool Read(QString address, int &input);
	virtual bool Read(QString address, double &input);

	virtual QWidget* OpenSetting() = 0; //打开设置界面
public:
	bool isConnect = false;
signals:
	void receiveData(QString receiveData); //读取到消息信号
signals:
	void DisConnectSignals();
};

