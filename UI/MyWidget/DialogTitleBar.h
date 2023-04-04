#pragma once

#include <QWidget>
#include "ui_DialogTitleBar.h"
#include <QMouseEvent>

class DialogTitleBar : public QWidget
{
	Q_OBJECT

public:
	DialogTitleBar(QWidget *parent = nullptr);
	~DialogTitleBar();
	void SetName(QString TittleName);
private:
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	// 最大化，最小化变量;
	QPoint m_restorePos;
	QSize m_restoreSize;
	// 移动窗口的变量;
	bool m_isPressed = false;
	QPoint m_startMovePos;
	bool isMax = false;
private:
	Ui::DialogTitleBarClass ui;
signals:
	void CloseSignal();
signals:
	void RestoreClickedSignal();
signals:
	void MaxClickedSignal();
};
