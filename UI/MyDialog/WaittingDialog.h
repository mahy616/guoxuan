#pragma once

#include <QWidget>
#include "ui_WaittingDialog.h"

class WaittingDialog : public QWidget
{
	Q_OBJECT

public:
	WaittingDialog(QString ShowWord, QWidget *parent = nullptr);
	~WaittingDialog();
private slots:
	void TimerSlot();
private:
	Ui::WaittingDialogClass ui;
	QTimer* m_Clock = nullptr;
	QString drawWord;
};
