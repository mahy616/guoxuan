#pragma once

#include <QWidget>
#include "ui_TimeStatistics.h"
#include <QResizeEvent>

typedef struct TimeThresholdInfo
{
	float MyTimeThreshold = 150;
	QLabel* ShowThresholdLabel;
	int OldWidth;
	int OldHeight;
	const int LabelWidth = 75;
	const int LabelHeight = 30;
}TimeThresholdInfo;

class TimeStatistics : public QWidget
{
	Q_OBJECT

public:
	TimeStatistics(QWidget *parent = nullptr);
	~TimeStatistics();
	void SetTimeExplain(int inTime);
	void InintShowThresholdLabel();
	TimeThresholdInfo ThresholdInfo;
	void WorkStateChange(bool isWork);
private:
	Ui::TimeStatisticsClass ui;
	float MaxTimes = -1;
	float MinTimes = 999999;
	double TotalTimes = 0;
	int totalNums = 0;
	int OverTimeNum = 0;
	bool isShow = true;
protected:
	virtual void resizeEvent(QResizeEvent *event) override;
public slots:
	void GetAlgoResultSlot(int TableIndex, bool bOK, double Time, QString tableWord);
	void ControlVisibleSlot();
	void ResetDataSlot();
};
