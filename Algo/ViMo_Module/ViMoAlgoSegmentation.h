#pragma once
#include "ViMoAlgoBase.h"



class ViMoAlgoSegmentation : public ViMoAlgoBase
{
public:
	~ViMoAlgoSegmentation();
	virtual bool InintAlgo(ModelConfig inConfig) override;  //��ʼ��
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk) override;   //�����㷨
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds) override;
	virtual void SetThresholdParam(ThresholdParams inParam) override;
	virtual AllThreshold GetThresholdValue() override;
	virtual ViMoModelInfo GetModelInfos() override;
private:
	void DrawRender(cv::Mat &inImage, smartmore::vimo::SegmentationResponse rsp,cv::Mat &outRender); //���ڣ��ṩ����ӿں�ֻ������������������Ⱦͼ��������Ҫ�Լ��ٺ���
	smartmore::vimo::SegmentationModule m_SegModel;
	smartmore::vimo::SegmentationResponse rsp_1;
	SegThreshold m_SegThreshold;
private:
	// ********************** �ָ���� *******************************
	QString GenSegText(cv::Mat &inMat, cv::Rect targetRegion);
	void DfsToLeftRight(cv::Mat &originalMat, cv::Mat &flagMat, int maskValue, cv::Point startPoint, int &labelNums, int edgeThinkesss);
	std::vector<std::vector<cv::Point>> SearchEveryLabel(cv::Mat &originalMat, cv::Mat &flagMat, int maskValue, cv::Point startPoint, int &labelNums);
	bool PostProcessing(cv::Mat maskMat, cv::Mat &renderMat);
	void GrayValueFilter(cv::Mat inOriginal, cv::Mat &inMask);
	bool DefectFlag[30] = { false };
	cv::Mat Lut_Image; //�����е�Lutӳ���
};

