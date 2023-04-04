#pragma once

#include <QWidget>
#include "ui_DockWidgetTitter.h"
#include <QMouseEvent>
#include <QDockWidget>

class DockWidgetTitter : public QWidget
{
	Q_OBJECT

public:
	DockWidgetTitter(QDockWidget* inDock,QWidget *parent = nullptr);
	~DockWidgetTitter();
private:
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	// 移动窗口的变量;
	bool m_isPressed;
	bool isMax;
	QPoint m_startMovePos;
private:
	Ui::DockWidgetTitterClass ui;
	QDockWidget* m_Dock;
};
