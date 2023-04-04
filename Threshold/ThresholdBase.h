#pragma once
#include <QWidget>
#include "PublicParamter.h"

// 后处理阈值基类
class ThresholdBase : public QWidget
{
	Q_OBJECT
public:
	// 初始化阈值标签
	virtual void InintWindow(std::vector<std::string> inLabels) = 0;
	// 获取当前所有编辑框内的值
	virtual void GetThreshold(ThresholdParams &inParam) = 0;
	// 从配置文件设置当前编辑框的值
	virtual void LoadConfigThreshold(ThresholdParams inConfig) = 0;
	// 设置模型信息
	virtual void SetModelInfo(ViMoModelInfo inInfo);
protected:
	ViMoModelInfo m_ModelInfo; //模型信息
};

