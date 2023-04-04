#pragma once

#include <QWidget>
#include "ui_SoftInfoDialog.h"

class SoftInfoDialog : public QWidget
{
	Q_OBJECT

public:
	SoftInfoDialog(QWidget *parent = nullptr);
	~SoftInfoDialog();
private:
	Ui::SoftInfoDialogClass ui;
signals:
	void MyCloseEvent();
};
