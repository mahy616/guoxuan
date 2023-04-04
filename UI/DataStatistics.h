#pragma once

#include <QWidget>
#include "ui_DataStatistics.h"
#include "PublicParamter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qframe.h>


typedef struct DataStatis
{
	QLabel* m_Labels;
	int Label_Nums = 0;
}DataStatis;

class DataStatistics : public QWidget
{
	Q_OBJECT
public:
	DataStatistics(QWidget *parent = nullptr);
	~DataStatistics();
	void ClearLabelsData();
	void WorkStateChange(bool isWork);
	void SetOkNgShow(bool showFlag);
public slots:
	void GetAlgoResultSlot(int TableIndex, bool bOK, double Time, QString tableWord);
	void GetModelChangeSlot(ModelChoice);
	void ControlVisibleSlot();
	void LabelsLeftClickedSlot();
	void LabelsRightClickedSlot();
	void ResetDataSlot();
private:
	Ui::DataStatisticsClass ui;
	QMap<QString, DataStatis*> m_LabelMap;
	QHBoxLayout *m_LabelsLayOut = nullptr;
	SdkModelType myModelType;
	std::string LastTypeName = "";
	long m_total = 0;
	int m_ok = 0;
	int m_ng = 0;
	bool isShow = true;
	int SliderNums = 0;
};
