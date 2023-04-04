#pragma once

#include <QWidget>
#include "ui_ModelConfigDialg.h"
//#include "PublicParamter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include <QFileDialog>
#include "components/Config/JsonReader.h"
#include <QCloseEvent>
#include <QCheckBox>

typedef struct QCheckContents
{
	std::vector<std::string> moduleID;
	std::vector<std::string> modeType;
	std::vector<std::string> RealNameValue;
	std::vector<std::vector<std::string>> labelsNamesVec;
	std::vector<int> soutionIndex;
}QCheckContents;

class ModelConfigDialg : public QWidget
{
	Q_OBJECT

public:
	ModelConfigDialg(QWidget *parent = nullptr);
	~ModelConfigDialg();
	void setParamter(ConfigResult m_ConfigResult, QString jsonPath);
	QMap<QCheckBox*, QCheckContents> m_CheckBoxIndex;
	ModelChoice m_ModelChoice;
	//void closeEvent(QCloseEvent *);
	void LoadModelChoice(ModelChoice inChoice);
private:
	Ui::ModelConfigDialgClass ui;
	QVBoxLayout *m_VecticalLayOut = NULL;
	bool gpuState = false;
	void inintConnection();
	void inintParamters();
public slots:
	void CheckBoxClickSlot();
	void GpuIDChangeSlot(QString myChangeText);
	void ChangeModelBtnSlot();
	void BtnGpuFlagChange();
	void BtnConfirm();
signals:
	void SendModelChoice(ModelChoice);
};
