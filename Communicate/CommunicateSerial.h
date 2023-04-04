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
	virtual bool Open() override; //������
	virtual bool Close() override; //�ر�����
	virtual void InitializationJson(QJsonObject inValue) override; //�������ļ���ȡ��ʼ����������
	virtual QJsonObject GetConfigJson() override; //��ȡ��ǰ���������Ϣ
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

