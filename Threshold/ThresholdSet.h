#pragma once

#include <QWidget>
#include "ui_ThresholdSet.h"
#include "PublicParamter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include <QLabel>
#include <QLineEdit>
#include <qradiobutton.h>
#include <QTableWidget>
#include <qheaderview.h>
#include <QMessageBox>
#include <QCheckBox>
#include "ThresholdBase.h"
#include "RenderSetWidget.h"
#include <QColorDialog>
#include <QTableWidget>
#include <QEvent>
#include <QShowEvent>

class ThresholdSet : public QWidget
{
	Q_OBJECT
public:
	ThresholdSet(QWidget *parent = nullptr);
	~ThresholdSet();
	// 在算法方案发生改变时调用该函数，切换各个阈值对象
	void SetMyParamter(std::vector<string> RealNameVec, std::vector<string> inTypeVec, std::vector<std::vector<std::string>> inLableNamesVec);
	// 获取当前模型的所有阈值
	std::vector<AllThreshold> GetThresholdAllParam();
	// 获取当前的超时阈值
	int GetTimeValue();
	TimeSetParamter GetTimeThreshold();
	// 加载方案时从配置文件初始化阈值
	void inintProgramThreshold(std::vector<AllThreshold> m_Threshold, TimeSetParamter inTimeParam);
	// 获取算法类的阈值回调函数
	std::function<std::vector<AllThreshold>(void)> m_AlgoThreadCallBack;
	// 获取算法类的模型信息回调函数
	std::function<std::vector<ViMoModelInfo>(void)> m_AlgoInfoCallBack;
protected:
	virtual void showEvent(QShowEvent *event) override; //显示事件中获取当前的模型信息并初始化算法类中获取的阈值
private:
	Ui::ThresholdSetClass ui;
	std::vector<ThresholdBase*> m_ThresholdDialgVec;  //后处理阈值Widget数组（因串联模型，所以存放vector，数组下标顺序与模型串联顺序相同）
	std::vector<RenderSetWidget*> RenderWidgets;      //显示设置Widget数组（因串联模型，所以存放vector，数组下标顺序与模型串联顺序相同）
	TimeSetParamter m_TimeThreshold;                  //计时内容
private slots:
	void onDialgCurrentIndexChanged(int);             //在ComBox中切换了模型响应的槽函数
	void btnConfimSlot();                             //点击了确定按钮
	void btnReSetSlot();                              //点击了重置按钮
signals:
	void SendThresholdPatamter();                   
};
