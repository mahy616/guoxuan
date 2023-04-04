#pragma once

#include <QWidget>
#include "ui_ShowSetting.h"
#include <QShowEvent>
#include "./../../configmanager.h"
class ShowSetting : public QWidget
{
	Q_OBJECT

public:
	ShowSetting(QWidget *parent = nullptr);
	~ShowSetting();
private slots:
	void slot_LanguageClicked(int);
protected:
	virtual void showEvent(QShowEvent *event) override;
private:
	Ui::ShowSettingClass ui;
	FormulaConfigData m_formula;
	bool isShowLogo = true;
};
