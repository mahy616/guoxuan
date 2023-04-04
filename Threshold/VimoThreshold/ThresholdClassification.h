#pragma once

#include <QWidget>
#include "ui_ThresholdClassification.h"
#include "PublicParamter.h"
#include "ThresholdBase.h"

class ThresholdClassification : public ThresholdBase
{
	Q_OBJECT
public:
	ThresholdClassification();
	~ThresholdClassification();
	virtual void InintWindow(std::vector<std::string> inLabels) override;
	virtual void GetThreshold(ThresholdParams &inParam) override;
	virtual void LoadConfigThreshold(ThresholdParams inConfig) override;
private:
	QGridLayout *m_MyLayOut = NULL;
	std::vector<QLineEdit*> m_labelScore;
private:
	Ui::ThresholdClassificationClass ui;
};
