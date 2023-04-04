#pragma once

#include <QWidget>
#include "ui_SetingItem.h"

class SetingItem : public QWidget
{
	Q_OBJECT
public:
	SetingItem(QWidget *parent = nullptr);
	~SetingItem();
	void SetMyWidget(QString IconName, QString NameText);
	QString GetName();
private:
	Ui::SetingItemClass ui;
};
