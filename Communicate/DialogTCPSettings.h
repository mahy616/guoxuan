#pragma once

#include <QDialog>
#include "ui_DialogTCPSettings.h"
#include "CommunicateTCP.h"

class CommunicateTCP;
class DialogTCPSettings : public QWidget
{
	Q_OBJECT

public:
	DialogTCPSettings(CommunicateTCP *tcp, QWidget *parent = nullptr);
	~DialogTCPSettings();
private:
	void InitVariables();
	void InitConnections();
	void updateCtrls(bool isConnected);
private slots:
	void on_btnConnect_clicked();
	void on_btnDisConnect_clicked();
	void on_btnSend_clicked();

	void ErrorSlot(QString msg);
	void AddClientSlot(QString client);
	void RemoveClientSlot(QString client);
	void SendConnectStatusSlot(bool status);
	void SendReadMessageSlot(QString msg, QString ip, quint16 port);
	void ConfigChangeEvent();
private:
	Ui::DialogTCPSettingsClass ui;
	CommunicateTCP *m_tcpManager;
};
