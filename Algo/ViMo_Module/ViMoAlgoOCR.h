#pragma once
#include "ViMoAlgoBase.h"
class ViMoAlgoOCR : public ViMoAlgoBase
{
public:
	~ViMoAlgoOCR();
	virtual bool InintAlgo(ModelConfig inConfig) override;  //初始化
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk) override;   //运行算法
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds) override;
	virtual void SetThresholdParam(ThresholdParams inParam) override;
	virtual AllThreshold GetThresholdValue() override;
	virtual ViMoModelInfo GetModelInfos() override;
private:
	smartmore::vimo::OcrModule m_OCRModel;
	smartmore::vimo::OcrResponse rsp_1;
	OCRThreshold m_OCRThreshold;
private:
	bool OcrPostProcessing(smartmore::vimo::OcrResponse rsp, cv::Mat inImg, cv::Mat &RenderImage, QString &ResultStr);
	bool guoxuan_processing(smartmore::vimo::OcrResponse rsp, cv::Mat inImg, cv::Mat &RenderImage,QString &ResultStr);
	void guoxuan_processing1(std::vector<smartmore::vimo::TextBlock>block,QString &ResultStr);
};

