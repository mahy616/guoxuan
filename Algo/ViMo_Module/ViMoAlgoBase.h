#pragma once
#include <qobject.h>
#include "opencv2/opencv.hpp"
#include <vimo_inference/vimo_inference.h>
#include <vimo_inference/any_response.h>
#include <vimo_inference/response.h>
#include "PublicParamter.h"

class ViMoAlgoBase : public QObject
{
public:
	~ViMoAlgoBase();
	// 初始化
	virtual bool InintAlgo(ModelConfig inConfig) = 0;  
	// 运行算法 -> 后置模块接口
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI ,QString &outResultJson, double &outMilliseconds, bool &outIsOk) = 0;   
	// 运行算法 -> 串联前置模块接口
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds);   
	// 设置阈值
	virtual void SetThresholdParam(ThresholdParams inParam) = 0;   
	// 显示设置
	virtual void SetRenderShowParam(RenderShowParams inParam);
	// 图片写文字（支持中文）
	void PutTextChinese(cv::Mat &inMat, QString drawText, cv::Point wordCenter, int inWordSize, cv::Scalar inColor);
	// 获取阈值
	virtual AllThreshold GetThresholdValue() = 0;
	// 获取模型信息
	virtual ViMoModelInfo GetModelInfos() = 0;
public:
	smartmore::vimo::Solution m_Solution;
	std::vector<std::string> m_LableNames;
	RenderShowParams m_RenderShow;
	TimeStatisType m_TimeType;
};

