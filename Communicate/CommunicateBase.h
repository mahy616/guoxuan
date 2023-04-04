#pragma once
#include <qobject.h>
#include <qjsonarray.h>
#include <QJsonObject>
class CommunicateBase : public QObject
{
	Q_OBJECT
public:
	virtual bool Open() = 0; //������
	virtual bool Close() = 0; //�ر�����
	virtual bool isConnectting(); //�Ƿ�����
	virtual void InitializationJson(QJsonObject inValue) = 0; //�������ļ���ȡ��ʼ����������
	virtual QJsonObject GetConfigJson() = 0; //��ȡ��ǰ���������Ϣ
	virtual QString GetCommunicationType() = 0;
	virtual bool Write(QString message);
	virtual bool Write(QString address,QString message);
	virtual bool Write(QString address, int inNum);
	virtual bool Write(QString address, double infloat);
	virtual bool Read(QString address, QString &input);
	virtual bool Read(QString address, int &input);
	virtual bool Read(QString address, double &input);

	virtual QWidget* OpenSetting() = 0; //�����ý���
public:
	bool isConnect = false;
signals:
	void receiveData(QString receiveData); //��ȡ����Ϣ�ź�
signals:
	void DisConnectSignals();
};

