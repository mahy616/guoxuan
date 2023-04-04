#pragma once

#include <QWidget>
#include "ui_CreateProgrammeName.h"

class CreateProgrammeName : public QWidget
{
	Q_OBJECT

public:
	CreateProgrammeName(QStringList CurrentProgrammeName, QWidget *parent = nullptr);
	~CreateProgrammeName();

private:
	Ui::CreateProgrammeNameClass ui;

signals:
	void CreateProName(QString);
};
