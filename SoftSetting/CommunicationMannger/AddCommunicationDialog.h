#pragma once

#include <QWidget>
#include "ui_AddCommunicationDialog.h"

class AddCommunicationDialog : public QWidget
{
	Q_OBJECT

public:
	AddCommunicationDialog(int defaultIndex, QWidget *parent = nullptr);
	~AddCommunicationDialog();

private:
	Ui::AddCommunicationDialogClass ui;
signals:
	void SendAddCommunicate(QString Name, QString type);
};
