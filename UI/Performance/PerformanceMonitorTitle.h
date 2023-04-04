#pragma once

#include <QWidget>
#include "ui_PerformanceMonitorTitle.h"
#include <QDockWidget>

class PerformanceMonitorTitle : public QWidget
{
	Q_OBJECT

public:
	PerformanceMonitorTitle(QDockWidget* inQDockWidget,QWidget *parent = nullptr);
	~PerformanceMonitorTitle();
public slots:
	void ControlVisibleSlot();
private:
	Ui::PerformanceMonitorTitleClass ui;
	bool isShow = true;
	QDockWidget* seeDockWidget;
};
