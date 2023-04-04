#pragma once

#include <QWidget>
#include "ui_SoftSetting.h"
#include "UI/MyWidget/SetingItem.h"
#include "SoftSetting/SaveImageMannger/SaveImageWidget.h"
#include <QMessageBox>
#include "SoftSetting/ProgrammeMannger/ProgrammeMannger.h"
#include "SoftSetting/CommunicationMannger/CommunicationSetting.h"
#include "SoftSetting/DisplaySetMannger/ShowSetting.h"

class SoftSetting : public QWidget
{
	Q_OBJECT

public:
	SoftSetting();
	~SoftSetting();
	void inintWindow();
protected:
	void closeEvent(QCloseEvent *);
private:
	Ui::SoftSettingClass ui;
	//SystenSetDialg *m_SystemSet;    //流程设计
	QWidget* m_SaveWidget;			//图片保存
	ProgrammeMannger* m_ProgrammeMannger;
	CommunicationSetting *m_Communicate;
	ShowSetting* m_ShowSetting;
signals:
	void CreateNewProSingal();
signals:
	void ChangleNewProSingal(QString NewProName);
};
