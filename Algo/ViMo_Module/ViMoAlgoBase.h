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
	// ��ʼ��
	virtual bool InintAlgo(ModelConfig inConfig) = 0;  
	// �����㷨 -> ����ģ��ӿ�
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI ,QString &outResultJson, double &outMilliseconds, bool &outIsOk) = 0;   
	// �����㷨 -> ����ǰ��ģ��ӿ�
	virtual bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds);   
	// ������ֵ
	virtual void SetThresholdParam(ThresholdParams inParam) = 0;   
	// ��ʾ����
	virtual void SetRenderShowParam(RenderShowParams inParam);
	// ͼƬд���֣�֧�����ģ�
	void PutTextChinese(cv::Mat &inMat, QString drawText, cv::Point wordCenter, int inWordSize, cv::Scalar inColor);
	// ��ȡ��ֵ
	virtual AllThreshold GetThresholdValue() = 0;
	// ��ȡģ����Ϣ
	virtual ViMoModelInfo GetModelInfos() = 0;
public:
	smartmore::vimo::Solution m_Solution;
	std::vector<std::string> m_LableNames;
	RenderShowParams m_RenderShow;
	TimeStatisType m_TimeType;
};

