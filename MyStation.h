#pragma once
#include <qobject.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include "UI/ImageWindow.h"
#include <QEvent>
#include <QMouseEvent>
#include <QTableWidget>
#include <qheaderview.h>
#include <QTabWidget>
#include <qmessagebox.h>
#include <QDockWidget>
#include <qaction.h>
#include <math.h>
#include "Algo/AlgoThread.h"
#include "PublicParamter.h"
#include "UI/DataStatistics.h"
#include "UI/TimeStatistics.h"
#include <QCloseEvent>
#include "UI/Performance/GpuMonitor.h"
#include "UI/MyTitleBar.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QScrollBar>
#include "UI/MyWidget/MyTableWidget.h"
#include <QModelIndex>
#include <QMessageBox>
#include "UI/ResultsListWidget.h"
#include "ResultSetting.h"
class ImageSouceBase;
class MyStation : public QObject
{
	Q_OBJECT
public:
	MyStation(int windowsIndex,QWidget *parent);
	~MyStation();
	void initAlgo(int windowsIndex);
	void inintVariable(int windowsIndex);
	void inintConnection();
	// 从配置文件加载MyStation
	void LoadImageSourceFromConfig(WindowsConfig inConfig);
	// 当前的运行状态下设置按钮的使能 - DynamicWidget运行状态改变使用该函数
	void WorkStateChange(bool isWork);
	// 将DynamicWidget的运行状态函数指针传入图像窗口
	void SetRunningStateChange(std::function<bool(void)> inStatePtr);
	// 设置当前窗口是否输出Ok/Ng
	void SetOkNgVisible(bool isShow);
public:
	int StationIndex;
	ResultSetting *m_result_setting = nullptr;
	QDockWidget *m_DockWidget = nullptr;				//右侧结果浮动窗口
	QDockWidget *m_DockWidget1 = nullptr;
	MyTableWidget *m_TableWidget = nullptr;				//结果列表控件
	ImageWindow *m_ImageWindow = nullptr;				//图像窗口
	CAlgoThread *m_AlgoThread = nullptr;				//算法线程
	DataStatistics *m_DataStatistic = nullptr;			//数据统计
	TimeStatistics *m_TimeStatistic = nullptr;			//时间统计
	ImageSourceBase *m_ImageSource = nullptr;			//图像源
	ResultsListWidget* m_ResultListWidget = nullptr;	//结果列表
	bool isShowOkNg = true;                             //当前是否显示Ok/Ng

public slots:
	// 结果列表行点击槽函数，读取这一行的文件路径送入算法队列
	void TableWidgetClickedSlot(QModelIndex index);
	// 获取到相机图像槽函数，插入算法并保存相机图片
	void GetCameraIamge(cv::Mat);
	// 阈值界面的确定按钮槽函数
	void GetThresholdAllParam();
	// 获取到算法类结果的槽函数，保存相机图与渲染图
	void SaveImageSlot(cv::Mat& OriginalImage, cv::Mat& RenderImage, bool bOK, QString tableText, int TableIndex,QString ImageFileName);
	// 获取到算法方案改变的槽函数
	void GetModelChangeSlot(ModelChoice ConfigParamter);
private:
	// 退出算法线程
	void CloseAlgo();
signals:
	void AddOneWindowSignals();
	void sendLog(QString);
};


