#pragma once
#include <qtablewidget.h>
#include <qheaderview.h>
#include <QTabWidget>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include <QScrollBar>
#include "PublicParamter.h"
#include <QDateTime>
#include <QResizeEvent>

class MyTableWidget : public QTableWidget
{
	Q_OBJECT
public:
	MyTableWidget(bool* inShowFlag, QWidget *parent);
	~MyTableWidget();
	float TimeThreshold = 150;
	int GetCameraImage(cv::Mat,QString);
	bool* isShowOkNg;
private:
	void inintMyTabel();
protected:
	virtual void resizeEvent(QResizeEvent *event) override;
public slots:
	void GetFileImageNames(QStringList);
	void TableGetAlgoResult(int TableIndex, bool bOK, double Time, QString tableWord);
};

