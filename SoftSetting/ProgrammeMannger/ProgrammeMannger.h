#pragma once

#include <QWidget>
#include "ui_ProgrammeMannger.h"
#include <qheaderview.h>
#include <QScrollBar>
#include <QDirIterator>

class ProgrammeMannger : public QWidget
{
	Q_OBJECT

public:
	ProgrammeMannger(QWidget *parent = nullptr);
	~ProgrammeMannger();
private:
	void inintMyTabel();
	void LoadAllPro();
	void SetNowProgrammeName(QString inName);
public slots:
	void CreatePragrammeSlot();
	void DeleteProgrammeSlot();
	void DefaultProgrammeSlot();
	void SaveProgrammeSlot();
	void ChangeProgrammeSlot();
private:
	Ui::ProgrammeManngerClass ui;
signals:
	void CreateNewPro();
signals:
	void ChangeProSlot(QString NewProName);
};
