#pragma once

#include <QWidget>
#include "ui_ThresholdSegmentation.h"
#include "PublicParamter.h"
#include <QCheckBox>
#include "ThresholdBase.h"

class ThresholdSegmentation : public ThresholdBase
{
	Q_OBJECT
public:
	ThresholdSegmentation(bool FrontModelFlag);
	~ThresholdSegmentation();
	virtual void InintWindow(std::vector<std::string> inLabels) override;
	virtual void GetThreshold(ThresholdParams &inParam) override;
	virtual void LoadConfigThreshold(ThresholdParams inConfig) override;
private:
	QGridLayout *m_MyLayOut = NULL;
	std::vector<QLineEdit*> m_labelArea;
	std::vector<QLineEdit*> m_labelWidth;
	std::vector<QLineEdit*> m_labelHeight;
	std::vector<QLineEdit*> m_MinGrayThreshold;
	std::vector<QLineEdit*> m_MaxGrayThreshold;
	QCheckBox *m_MinGrayCheck = nullptr;
	QCheckBox *m_MaxGrayCheck = nullptr;
	bool isFrontModel; //�Ƿ�ǰ��ģ��(ǰ��ģ��û����С�Ҷ�ֵ�����Ҷ�ֵ)
private:
	void SetGrayEnable(bool isEnable, bool isMin);
private:
	Ui::ThresholdSegmentationClass ui;
};
