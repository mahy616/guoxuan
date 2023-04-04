#pragma once
#include "CommunicateBase.h"
#include <QTcpSocket>
#include <QTcpServer>
#include "DialogTCPSettings.h"

typedef struct ConfigTcp
{
	QString IpStr;
	int Port;
	int m_mode;
}ConfigTcp;

class CommunicateTCP : public CommunicateBase
{
	Q_OBJECT
public:
	enum Mode { SERVER, CLIENT, UDP };
	CommunicateTCP();
	~CommunicateTCP();
	virtual bool Open() override; //������
	virtual bool Close() override; //�ر�����
	virtual void InitializationJson(QJsonObject inValue) override; //�������ļ���ȡ��ʼ����������
	virtual QJsonObject GetConfigJson() override; //��ȡ��ǰ���������Ϣ
	virtual bool Write(QString message) override;
	virtual QWidget* OpenSetting() override;
	virtual QString GetCommunicationType() override;
public:
	bool CreateServer(QString ip, quint16 port);
	bool ConnectToServer(QString ip, quint16 port);
	void DisconnectServer();
	bool IsServerConnected();
	void SendMessage2Server(QString msg);
	void SendMessage2Client(QString client, QString msg);
	QStringList GetConnectClient();
	QString LocalAddress();
	quint16 LocalPort();
	void NewConnection();
	ConfigTcp m_Config;
private:
	void InitConnections();
private:
	//��Ϊ�ͻ���
	QTcpSocket m_TcpClient;
	//��Ϊ�����
	QTcpServer m_tcpServer;
	std::map<QString, QTcpSocket*> m_tcpConnections;//����ͻ�������,QString�����ӵĿͻ���IP+�˿��ַ���

private slots:
	void ReadMessage();
signals:
	void Error(QString msg);
	void AddClient(QString client);
	void RemoveClient(QString client);
	void SendConnectStatus(bool status);
	void SendReadMessage(QString msg, QString ip, quint16 port);
};

