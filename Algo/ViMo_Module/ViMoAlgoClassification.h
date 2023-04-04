#pragma once
#include "ViMoAlgoBase.h"

class ViMoAlgoClassification : public ViMoAlgoBase
{
public:
	~ViMoAlgoClassification();
	virtual bool InintAlgo(ModelConfig inConfig) override;  //初始化
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk) override;   //运行算法
	virtual void SetThresholdParam(ThresholdParams inParam) override;
	virtual AllThreshold GetThresholdValue() override;
	virtual ViMoModelInfo GetModelInfos() override;
private:
	smartmore::vimo::ClassificationModule m_ClassificationModel;
	ClassificationThreshold m_ClassificationThreshold;
private:
	std::string ClassifyPostProcessing(smartmore::vimo::ClassificationResponse rsp, cv::Mat inImg, cv::Mat &RenderImage, cv::Rect targetRegion);
};

