#include "GpuMonitor.h"

GpuMonitor::GpuMonitor(QWidget *parent)
	: QWidget(parent)
{
	qRegisterMetaType<std::vector<GpuInfos>>("std::vector<GpuInfos>");

	std::vector<GpuInfos> InfosResult = GetResultFromCMD();
	for (int i = 0; i < InfosResult.size(); i++)
	{
		OneMonitorWidget *m_OneMonitors = new OneMonitorWidget(i+1, InfosResult[i].MaxMemory);
		m_MonitorVec.push_back(m_OneMonitors);
		m_OneMonitors->SetGpuInfos(InfosResult[i]);
		connect(m_OneMonitors, &OneMonitorWidget::ShowStateChangeSignal, this, &GpuMonitor::WidgetShowStateSlot);
	}

	QVBoxLayout *m_V1 = new QVBoxLayout;
	for (int i = 0; i < m_MonitorVec.size(); i++)
	{
		m_V1->addWidget(m_MonitorVec[i]);
	}
	m_V1->setContentsMargins(0, 0, 0, 0);
	this->setLayout(m_V1);

	m_ReaderThread = new GpuReaderThread;
	m_ReaderThread->bStart = true;
	m_ReaderThread->start(QThread::LowPriority); //QThread::LowPriority
	connect(m_ReaderThread, &GpuReaderThread::GpuInfosSingal, this, &GpuMonitor::GetGpuInfosSlot);
}

void GpuMonitor::GetGpuInfosSlot(std::vector<GpuInfos> inVec)
{
	for (int i = 0; i < m_MonitorVec.size(); i++)
	{
		m_MonitorVec[i]->SetGpuInfos(inVec[i]);
	}
}

GpuMonitor::~GpuMonitor()
{
	m_ReaderThread->bStart = false;
	m_ReaderThread->quit();
	m_ReaderThread->wait();
	delete m_ReaderThread;
}

void GpuMonitor::WidgetShowStateSlot(bool isShow)
{
	int nowHeight = this->height();
	if (isShow)
		nowHeight = nowHeight + 135;
	else
	{
		nowHeight = nowHeight - 135;
		if (nowHeight < 25) nowHeight = 25;
	}
	emit SetWidgetHeightSignal(nowHeight);
}

void GpuReaderThread::run()
{
	//https://blog.csdn.net/m0_60721514/article/details/125241141
	while (bStart)
	{
		std::vector<GpuInfos> m_Result = GetResultFromCMD(); //平均运行120ms,开线程处理
		if (m_Result.size() != 0)
			emit GpuInfosSingal(m_Result);
		Sleep(400);
	}
}


