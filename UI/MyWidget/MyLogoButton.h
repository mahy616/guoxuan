#pragma once

#include <QWidget>
#include "ui_MyLogoButton.h"
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>

class MyLogoButton : public QWidget
{
	Q_OBJECT

public:
	MyLogoButton(QWidget *parent = nullptr);
	~MyLogoButton();
	void SetMyParam(QString logoName, QString titter);
	void SetLogoSize(int width, int height);
	void SetWordSize(int size);
protected:
	void paintEvent(QPaintEvent*);
private:
	Ui::MyLogoButtonClass ui;
private:
	void mousePressEvent(QMouseEvent *event);
signals:
	void MyClicked();
};
