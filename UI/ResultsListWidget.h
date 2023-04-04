#pragma once

#include <QWidget>
#include "ui_ResultsListWidget.h"
#include "UI/MyWidget/MyTableWidget.h"

class ResultsListWidget : public QWidget
{
	Q_OBJECT

public:
	ResultsListWidget(MyTableWidget* inTableWidgetPtr, QWidget *parent = nullptr);
	~ResultsListWidget();
	void WorkStateChange(bool isWork);
private:
	Ui::ResultsListWidgetClass ui;
	MyTableWidget* tableWidgetPtr;
	QVBoxLayout* m_WidgetLayOut = nullptr;
	bool isShow = true;
private slots:
	void ReSetBtnClickedSlot();
	void ControlVisibleSlot();
};
