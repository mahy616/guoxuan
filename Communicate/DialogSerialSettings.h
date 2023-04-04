#pragma once

#include <QDialog>
#include "ui_DialogSerialSettings.h"
#include "CommunicateSerial.h"

class CommunicateSerial;
class DialogSerialSettings : public QWidget
{
	Q_OBJECT

public:
	DialogSerialSettings(CommunicateSerial *serialManager, QWidget *parent = nullptr);
	~DialogSerialSettings();
private:
	void InitVariables();
	void InitConnections();
	void UpdateCtrls(bool isOpen);
	void FindIndexComBox(QString targetName, QComboBox* findBox);
private slots:
	void on_btnOpenSerial_clicked();
	void on_btnCloseSerial_clicked();
	void on_btnSend_clicked();
	void on_btnClearLog_clicked();
	void on_btnClearSend_clicked();
	void ReceiveComData(QString data);
private:
	CommunicateSerial *m_serialManager;
	Ui::DialogSerialSettingsClass ui;
	QMetaObject::Connection m_conn;
};
