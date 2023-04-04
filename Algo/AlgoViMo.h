#pragma once
#include "ViMoAlgoBase.h"

class AlgoViMo
{
public:
	~AlgoViMo();
	// �������һ��module������Ϣ���飬���Դ������ģ��
	bool InintAlgo(std::vector<ModelConfig> inConfig);  
	// �����㷨:: outRenderImage��Ⱦͼ��outResultJson����ַ�����outMilliseconds�㷨����ʱ�䣬outIsOk���Ok/Ng
	bool RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, QString &outResultJson, double &outMilliseconds, bool &outIsOk);   
	// ������ֵ -> �����������������ֵ�����Ľṹ�壬�������ٰѽṹ���Ӧ����ֵ��ֵ������m_Threshold
	void SetThresholdParam(std::vector<ThresholdParams> inParam); 
	// ��ʾ����
	void SetRenderShowParam(std::vector<RenderShowParams> inParam);
	// ��ȡ��ǰ��ֵ
	std::vector<AllThreshold> GetThresholdValue();
	// ��ȡ��ǰģ����Ϣ
	std::vector<ViMoModelInfo> GetModelInfo();
private:
	std::vector<ViMoAlgoBase*> m_ViMoAlogVec; //moduleʵ�����飬��Ӧ�����ĸ���ģ��ʵ��
};

