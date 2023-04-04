#pragma once

#include <QWidget>
#include "ui_ThresholdOCR.h"
#include "PublicParamter.h"
#include <QRadioButton>
#include "ThresholdBase.h"
#include "QTableWidget"
#include <qheaderview.h>
#include <QMessageBox>
#include <QEvent>
#include <QShowEvent>

class ThresholdOCR : public ThresholdBase
{
	Q_OBJECT
public:
	ThresholdOCR();
	~ThresholdOCR();
	virtual void InintWindow(std::vector<std::string> inLabels) override;
	virtual void GetThreshold(ThresholdParams &inParam) override;
	virtual void LoadConfigThreshold(ThresholdParams inConfig) override;
	virtual void SetModelInfo(ViMoModelInfo inInfo) override;
private:
	QVBoxLayout *m_MyLayOut = NULL;
	std::vector<QString> m_OcrStrVec;
	QTableWidget *m_TablePtr;
	QRadioButton *m_OcrRowSort;
	QRadioButton *m_OcrColumnSort;
	QGridLayout *m_GridLayout;
	std::vector<QLineEdit*> m_labelScore;
	std::vector<QLineEdit*> m_labelIOU;
private:
	Ui::ThresholdOCRClass ui;
	void InintTableWidget(QTableWidget *m_FileWidget);
	void ConnectIOU();
private slots:
	void TableClickedSlot(QModelIndex index);
//protected:
//	virtual void showEvent(QShowEvent *event) override;
};
