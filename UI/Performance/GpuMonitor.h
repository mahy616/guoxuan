#pragma once
#include <qwidget.h>
#include <QLabel>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include "PublicParamter.h"
#include <QThread>
#include "OneMonitorWidget.h"

class GpuReaderThread :public QThread
{
	Q_OBJECT
public:
	bool bStart = false;
private:
	void run();
signals:
	void GpuInfosSingal(std::vector<GpuInfos>);
};

class GpuMonitor : public QWidget
{
	Q_OBJECT
public:
	GpuMonitor(QWidget *parent = nullptr);
	~GpuMonitor();
	std::vector<OneMonitorWidget*> m_MonitorVec;
private:
	GpuReaderThread *m_ReaderThread;
public slots:
	void GetGpuInfosSlot(std::vector<GpuInfos>);
	void WidgetShowStateSlot(bool isShow);
signals:
	void SetWidgetHeightSignal(int nowHeight);
};

