#pragma once
#include "ViMoAlgoBase.h"
class ViMoAlgoDetection : public ViMoAlgoBase
{
public:
	~ViMoAlgoDetection();
	virtual bool InintAlgo(ModelConfig inConfig) override;  //初始化
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk) override;   //运行算法
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds) override;
	virtual void SetThresholdParam(ThresholdParams inParam) override;
	virtual AllThreshold GetThresholdValue() override;
	virtual ViMoModelInfo GetModelInfos() override;
private:
	smartmore::vimo::DetectionModule m_DetectionModel;
	DetectionThreshold m_DetectionThreshold;
	smartmore::vimo::DetectionResponse rsp_1;
	bool DefectFlag[30] = { false };
private:
	int DectionPostProcessing(smartmore::vimo::DetectionResponse rsp, cv::Mat inImg, cv::Mat &RenderImage);
	QString GenSegText(cv::Mat &RenderImage);
};

