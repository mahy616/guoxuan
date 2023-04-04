#include "TimeStatistics.h"

TimeStatistics::TimeStatistics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.btn_ControlVisiable->SetMyParam("ShowCross", tr("Time Statistics"));
	ui.btn_ControlVisiable->SetWordSize(11);
	ui.btn_ControlVisiable->SetLogoSize(14, 14);

	connect(ui.btn_ReSet, &QPushButton::clicked, this, &TimeStatistics::ResetDataSlot);
	connect(ui.btn_ControlVisiable, &MyLogoButton::MyClicked, this, &TimeStatistics::ControlVisibleSlot);
	InintShowThresholdLabel();
}

TimeStatistics::~TimeStatistics()
{}

void TimeStatistics::ResetDataSlot()
{
	MaxTimes = -1;
	MinTimes = 999999;
	TotalTimes = 0;
	totalNums = 0;
	OverTimeNum = 0;
	ui.label_AverageTime->setText(QString::number(0));
	ui.label_MaxTime->setText(QString::number(0));
	ui.label_MinTime->setText(QString::number(0));
	ui.label_Overtimes->setText(QString::number(0));
}

void TimeStatistics::GetAlgoResultSlot(int TableIndex, bool bOK, double Time, QString tableWord)
{
	totalNums++;
	TotalTimes = TotalTimes + Time;
	if (Time > MaxTimes)
		MaxTimes = Time;
	if (Time < MinTimes)
		MinTimes = Time;
	int m_average = TotalTimes / totalNums ;
	ui.label_AverageTime->setText(QString(" %1").arg(m_average));
	ui.label_MaxTime->setText(QString(" %1").arg(MaxTimes));
	ui.label_MinTime->setText(QString(" %1").arg(MinTimes));

	if (Time > ThresholdInfo.MyTimeThreshold)
	{
		OverTimeNum++;
		ui.label_Overtimes->setText(QString(" %1").arg(OverTimeNum));
	}
}

void TimeStatistics::SetTimeExplain(int inTime)
{
	//ui.label_Explain->setText(tr("时间统计(耗时阈值%1)").arg(inTime));
	ThresholdInfo.MyTimeThreshold = inTime;
	ThresholdInfo.ShowThresholdLabel->setText(tr("Threshold:%1").arg(ThresholdInfo.MyTimeThreshold));
	ThresholdInfo.ShowThresholdLabel->setToolTip(tr("Threshold:%1").arg(ThresholdInfo.MyTimeThreshold));
}

void TimeStatistics::ControlVisibleSlot()
{
	isShow = !isShow;
	if (isShow) //展开
	{
		this->setMaximumHeight(1000);
		ui.btn_ControlVisiable->SetMyParam("ShowCross", tr("Time Statistics"));
		ui.widget_ControlVisual->setVisible(true);
	}
	else //折叠
	{
		this->setMaximumHeight(50);
		ui.btn_ControlVisiable->SetMyParam("HideCross", tr("Time Statistics"));
		ui.widget_ControlVisual->setVisible(false);
		this->update();
	}
}

void TimeStatistics::InintShowThresholdLabel()
{
	layout()->activate();
	ui.gridLayout_7->activate();
	ui.gridLayout->activate();
	ui.horizontalLayout->activate();
	ui.horizontalLayout_2->activate();
	ui.gridLayout_6->activate();

	ThresholdInfo.ShowThresholdLabel = new QLabel(ui.frame_5);
	ThresholdInfo.ShowThresholdLabel->setStyleSheet("background-color:rgb(80,80,80);border-radius:8;color:white;font-size:5pt;");
	ThresholdInfo.ShowThresholdLabel->setText(tr("Threshold:%1").arg(ThresholdInfo.MyTimeThreshold));
	ThresholdInfo.ShowThresholdLabel->setToolTip(tr("Threshold:%1").arg(ThresholdInfo.MyTimeThreshold));
	QRect rect = ui.frame_5->rect();
	ThresholdInfo.ShowThresholdLabel->setGeometry(rect.width() - ThresholdInfo.LabelWidth, 0, ThresholdInfo.LabelWidth, ThresholdInfo.LabelHeight);
	ThresholdInfo.OldWidth = rect.width();
	ThresholdInfo.OldHeight = rect.height();
}

void TimeStatistics::WorkStateChange(bool isWork)
{
	ui.btn_ReSet->setEnabled(!isWork);
}

void TimeStatistics::resizeEvent(QResizeEvent *event)
{
	QRect rect = ui.frame_5->rect();
	float widthRate = (float)rect.width() / ThresholdInfo.OldWidth;
	float heightRate = (float)rect.height() / ThresholdInfo.OldHeight;
	ThresholdInfo.ShowThresholdLabel->setGeometry(rect.width() - ThresholdInfo.LabelWidth * widthRate, 0, ThresholdInfo.LabelWidth * widthRate, ThresholdInfo.LabelHeight * heightRate);
}