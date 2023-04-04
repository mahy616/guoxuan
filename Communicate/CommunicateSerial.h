#pragma once
#include "CommunicateBase.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonObject>
#include "DialogSerialSettings.h"

typedef struct SerialInfo
{
	QString ComID = "Com1";
	int baudRate = QSerialPort::Baud9600;
	int dataBits = QSerialPort::Data8;
	int stopBits = QSerialPort::OneStop;
	int parity = QSerialPort::NoParity;
	int flowControl = QSerialPort::NoFlowControl;
}SerialInfo;

class CommunicateSerial : public CommunicateBase
{
	Q_OBJECT
public:
	CommunicateSerial();
	~CommunicateSerial();
	virtual bool Open() override; //打开连接
	virtual bool Close() override; //关闭连接
	virtual void InitializationJson(QJsonObject inValue) override; //从配置文件读取初始化界面配置
	virtual QJsonObject GetConfigJson() override; //获取当前类的配置信息
	virtual bool Write(QString message) override;
	virtual QWidget* OpenSetting() override;
	virtual QString GetCommunicationType() override;
public:
	bool OpenSerial();
	void CloseSerial();
	bool GetConnectStatus();
	void SendData(QString data);
	void SendData(QByteArray data);

private:
	void InitConnections();
private:
	QSerialPort m_SerialPort;
public:
	SerialInfo m_ConnectInfo;
signals:
	void connectStatusChanged(bool bConnected);
};

