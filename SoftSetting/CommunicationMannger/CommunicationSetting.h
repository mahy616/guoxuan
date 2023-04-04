#pragma once

#include <QWidget>
#include "ui_CommunicationSetting.h"
#include "AddCommunicationDialog.h"
#include "components/Config/ConfigProgramme.h"
#include <QShowEvent>

class CommunicationSetting : public QWidget
{
	Q_OBJECT

public:
	CommunicationSetting(QWidget *parent = nullptr);
	~CommunicationSetting();
	void inintWindow();
public slots:
	void BtnAddCommunicate();
	void BtnDeleteCommunicata();
protected:
	virtual void showEvent(QShowEvent *event) override;
private:
	Ui::CommunicationSettingClass ui;
	void AddOneCommunicate(QString newName, QString newType);
	void ReSetOneCommunicate(QString newName, CommunicateBase* m_Communicate);
	void ClearAllCommunication();
};
