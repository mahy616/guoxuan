#pragma once
#include <QWidget>
#include "PublicParamter.h"

// ������ֵ����
class ThresholdBase : public QWidget
{
	Q_OBJECT
public:
	// ��ʼ����ֵ��ǩ
	virtual void InintWindow(std::vector<std::string> inLabels) = 0;
	// ��ȡ��ǰ���б༭���ڵ�ֵ
	virtual void GetThreshold(ThresholdParams &inParam) = 0;
	// �������ļ����õ�ǰ�༭���ֵ
	virtual void LoadConfigThreshold(ThresholdParams inConfig) = 0;
	// ����ģ����Ϣ
	virtual void SetModelInfo(ViMoModelInfo inInfo);
protected:
	ViMoModelInfo m_ModelInfo; //ģ����Ϣ
};

