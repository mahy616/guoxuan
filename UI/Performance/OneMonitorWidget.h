#pragma once

#include <QWidget>
#include "ui_OneMonitorWidget.h"
#include "PublicParamter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OneMonitorWidgetClass; };
QT_END_NAMESPACE

class OneMonitorWidget : public QWidget
{
	Q_OBJECT

public:
	OneMonitorWidget(int GpuID, int inMaxMemory,QWidget *parent = nullptr);
	~OneMonitorWidget();
	void SetGpuInfos(GpuInfos inInfos);
private slots:
	void ControlVisibleSlot();
private:
	Ui::OneMonitorWidgetClass *ui;
	bool isShow = true;
signals:
	void ShowStateChangeSignal(bool isShow);
};
