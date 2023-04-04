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
	virtual bool Open() override; //打开连接
	virtual bool Close() override; //关闭连接
	virtual void InitializationJson(QJsonObject inValue) override; //从配置文件读取初始化界面配置
	virtual QJsonObject GetConfigJson() override; //获取当前类的配置信息
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
	//作为客户端
	QTcpSocket m_TcpClient;
	//作为服务端
	QTcpServer m_tcpServer;
	std::map<QString, QTcpSocket*> m_tcpConnections;//保存客户端连接,QString是连接的客户端IP+端口字符串

private slots:
	void ReadMessage();
signals:
	void Error(QString msg);
	void AddClient(QString client);
	void RemoveClient(QString client);
	void SendConnectStatus(bool status);
	void SendReadMessage(QString msg, QString ip, quint16 port);
};

