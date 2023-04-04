#pragma once

#include <QWidget>
#include "ui_SaveImageWidget.h"
#include <QCloseEvent>
#include "PublicParamter.h"
#include <QShowEvent>

class SaveImageWidget : public QWidget
{
	Q_OBJECT
public:
	static SaveImageWidget *GetInstance();
	SaveImageWidget(bool isCameraWidget, QWidget *parent = nullptr);
	~SaveImageWidget();
	void UpdateSaveConfig();
	void inintLoadParam(SaveImageConfig);
private:
	Ui::SaveImageWidgetClass ui;
	static SaveImageWidget *m_Instance;
	bool isCameraWidgets;
protected:
	virtual void showEvent(QShowEvent *event) override;
private:
	void SetWidgetEnable(bool);
	void SetDeleteNumsEnable(bool);
	void SetDeleteDaysEnable(bool);
	void SetDeleteMemoryEnable(bool);
	//void InintConfig(bool isCamera);
};
