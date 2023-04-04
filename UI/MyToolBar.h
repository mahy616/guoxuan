#pragma once
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QSpacerItem>
#include "UI/MyWidget/MyLogoButton.h"

class MyToolBar : public QToolBar
{
	Q_OBJECT
public:
	enum RuningState { isRunning, NoRunning };
	MyToolBar(QWidget *parent);
	~MyToolBar();
	void SetRuningState(RuningState inStata);
	QAction* QAction_SignalGrab;
	QAction* QAction_ContinueGrab;
	QAction* QAction_StopGrab;
	QAction* QAction_Setting;
	QAction* QAction_sqlDataSetting;
private:
	void InintWidget();
	void InintConnet();
	QString MyStytleSheet(QString ImageName,QString DisabledImage);
private:
	QToolButton * Btn_SignalGrab;
	QToolButton * Btn_ContinueGrab;
	QToolButton * Btn_StopGrab;
	QToolButton * Btn_sqlDataSetting;
	MyLogoButton * Btn_Setting;
	QLabel* Label_SegLine;
	QLabel* Label_State;


private:
	void paintEvent(QPaintEvent *event);
signals:
	void SingleGrabSignal();
	void ContinueGrabSignal();
	void StopGrabSignal();
	void OpenSettingSignal();
	void OpenSqlDataSignal();
};

