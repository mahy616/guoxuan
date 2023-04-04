#pragma once

#include <QWidget>
#include "ui_ResultSetting.h"
#include "guoxuan.h"
#include "QButtonGroup"
class ResultSetting : public QWidget
{
	Q_OBJECT

public:
	ResultSetting(QWidget *parent = Q_NULLPTR);
	~ResultSetting();
	void initConnection();
	void initShow();
private slots:
	void SwitchMode(int index, bool bchecked);
private:
	Ui::ResultSetting ui;
	QButtonGroup m_GroupBox;
};
