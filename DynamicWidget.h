#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DynamicWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include "UI/ImageWindow.h"
#include <QEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QTableWidget>
#include <qheaderview.h>
#include <QTabWidget>
#include <qmessagebox.h>
#include <QDockWidget>
#include <qaction.h>
#include <math.h>
#include "UI/DataStatistics.h"
#include "UI/TimeStatistics.h"
#include <QCloseEvent>
#include "UI/Performance/GpuMonitor.h"
#include "UI/MyTitleBar.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QScrollBar>
#include "UI/MyWidget/MyTableWidget.h"
#include "MyStation.h"
#include "SoftSetting/SoftSetting.h"
#include "DataManager.h"
#include "ResultSetting.h"
#include "QStandardItemModel"
#include "Config.h"
class DynamicWidget : public QMainWindow
{
	Q_OBJECT
public:
	DynamicWidget(QWidget *parent = nullptr);
	~DynamicWidget();
	std::vector<MyStation*> m_Station;                   //MyStation数组：新建窗口与销毁窗口对应操作该数组
	static DynamicWidget *GetInstance();                 //单例
	void SetLogoVisuable(bool isSee);
	void SetSoftName(QString name);
	bool GetLogoVisuable();
	QString GetSoftName();
private: 
	Ui::DynamicWidgetClass ui;
	static DynamicWidget *m_Instance;
	enum RuningState { isWorking, isStop, isWaitting };  // 当前软件的运行状态：运行中，未运行，等待停止中
	QDockWidget *GpuMinoitorDock = nullptr;              // GPU性能监视类对象
	QGridLayout *m_ImagesWindow;                         // 显示窗口图像的栅格布局
	int windowsNums = 2; 
	ResultSetting *m_result_setting = nullptr;
	QDockWidget *m_DockWidget = nullptr;				//右侧结果浮动窗口
	QDockWidget *m_DockWidget1 = nullptr;// 当前工位数量（最大创建10个窗口）
	QListView *m_listView = nullptr;
	QStandardItemModel *m_LogModel;
private: 
	// 添加一个工位
	void AddOneStation(int index, bool bInint = false);
	// 设置当前软件的运行状态
	void SetRunningState(RuningState inState);
	void SetRuningState(bool isRuning);
	// 获取当前是否运行状态 - 通过toorBar的开始按钮图标使能状态判断当前软件的运行状态
	bool isRunning();
	// 获取所有工位的算法是否都初始化成功(点击运行按钮时需要判断)
	bool JudgeAlgoInintState();
	// 默认的窗口初始化
	void InintWindow();
	// 窗口关闭事件时调用销毁资源
	void closeEvent(QCloseEvent *);
	// 初始化参数
	void InintParameter();
	// 初始化信号槽
	void InintConnection();
	void ShowLog(QString log);
	void LoadParameter();
private slots:
	// 添加窗口槽函数
	void AddWindowSlot();
	// 删除窗口槽函数:: int参数传入删除的窗口ID
	void DeleteWindowSlot(int);		
	// 当切换方案或新建方案时执行的重置窗口槽函数
	void ReSetWindowSlot();
	// 加载方案槽函数:: QString参数传入方案的json名称
	void LoadProgramme(QString loadProgrammeName);
	// 监控算法线程是否运行结束的定时器槽函数
	void TimerWatchOnAlgoStop();
protected:
	void resizeEvent(QResizeEvent *event);

// ###################################################  工作栏相关（toorBar）  ########################################################
private slots:
	void ActionStartWorkSlot();   //点击连续运行按钮
	void ActionStopWorkSlot();    //点击停止工作按钮
	void Action_SingleGrab();     //点击单步执行按钮
	void Action_SystemSetSlot();  //点击系统设置按钮
	void Action_SqlDataSlot();  //点击系统设置按钮
// #######################################################################################################################


// ###################################################  标题栏相关（toorBar）  ######################################################
private:
	void inintTitteBar();          //初始化标题栏
private slots:
	void onButtonMinClicked();     //最小化事件
	void onButtonRestoreClicked(); //还原事件
	void onButtonMaxClicked();     //最大化事件
	void onButtonCloseClicked();   //关闭事件
// #######################################################################################################################
};

