#pragma once

#include <QWidget>
#include "ui_ThresholdDetection.h"
#include "PublicParamter.h"
#include "ThresholdBase.h"

class ThresholdDetection : public ThresholdBase
{
	Q_OBJECT
public:
	ThresholdDetection();
	~ThresholdDetection();
	virtual void InintWindow(std::vector<std::string> inLabels) override;
	virtual void GetThreshold(ThresholdParams &inParam) override;
	virtual void LoadConfigThreshold(ThresholdParams inConfig) override;
private:
	QGridLayout *m_MyLayOut = NULL;
	std::vector<QLineEdit*> m_labelArea;
	std::vector<QLineEdit*> m_labelWidth;
	std::vector<QLineEdit*> m_labelHeight;
	std::vector<QLineEdit*> m_labelScore;
	std::vector<QLineEdit*> m_labelIOU;
	void ConnectIOU();
private:
	Ui::ThresholdDetectionClass ui;
};
