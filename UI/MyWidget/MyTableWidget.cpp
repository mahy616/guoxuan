#include "MyTableWidget.h"

MyTableWidget::MyTableWidget(bool* inShowFlag, QWidget *parent)
{
	isShowOkNg = inShowFlag;
	inintMyTabel();
}

MyTableWidget::~MyTableWidget()
{
	
}

void MyTableWidget::GetFileImageNames(QStringList m_ImageList)
{
	int rows = this->rowCount();
	for (int i = 0; i < rows; ++i)
	{
		this->removeRow(i);
	}
	this->setRowCount(m_ImageList.size());
	for (int i = 0; i < m_ImageList.size(); ++i)
	{
		QString file = m_ImageList.at(i);
		QTableWidgetItem *item = new QTableWidgetItem(file);
		item->setBackgroundColor(QColor(50, 50, 50));
		this->setItem(i, 2, item);

		item = new QTableWidgetItem(QString("0"));
		item->setBackgroundColor(QColor(50, 50, 50));
		this->setItem(i, 0, item);

		item = new QTableWidgetItem(tr("Not recognized"));
		item->setBackgroundColor(QColor(50, 50, 50));
		this->setItem(i, 1, item);

		this->item(i, 0)->setTextColor(QColor(255, 255, 255));
		this->item(i, 1)->setTextColor(QColor(255, 255, 255));
		this->item(i, 2)->setTextColor(QColor(255, 255, 255));
		this->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		this->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	}
	if (m_ImageList.size() == 0)
	{
		QMessageBox::information(NULL, tr("Error"), tr("Folder is empty!"));
		return;
	}
	this->update();
}

int MyTableWidget::GetCameraImage(cv::Mat inCameraImg,QString ImageName)
{
	
	//插入列表控件
	if (this->rowCount() > 200)
	{
		for (int removeIndex = 0; removeIndex < (this->rowCount() - 200); removeIndex++)
		{
			this->removeRow(0);
		}
	}
	int rows = this->rowCount();
	this->setRowCount(rows + 1);

	QTableWidgetItem *item = new QTableWidgetItem(ImageName);
	item->setBackgroundColor(QColor(50, 50, 50));
	this->setItem(rows, 2, item);

	item = new QTableWidgetItem(QString("0"));
	item->setBackgroundColor(QColor(50, 50, 50));
	this->setItem(rows, 0, item);

	item = new QTableWidgetItem(tr("Not recognized"));
	item->setBackgroundColor(QColor(50, 50, 50));
	this->setItem(rows, 1, item);

	this->item(rows, 0)->setTextColor(QColor(255, 255, 255));
	this->item(rows, 1)->setTextColor(QColor(255, 255, 255));
	this->item(rows, 2)->setTextColor(QColor(255, 255, 255));
	this->item(rows, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->item(rows, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->scrollToBottom();
	return rows;
}

void MyTableWidget::TableGetAlgoResult(int TableIndex, bool bOK, double Time, QString tableWord)
{
	QTableWidgetItem *item = new QTableWidgetItem(this->item(TableIndex, 2)->text());
	this->setItem(TableIndex, 2, item);
	if (*isShowOkNg) bOK ? this->item(TableIndex, 2)->setTextColor(QColor(0, 255, 0)) : this->item(TableIndex, 2)->setTextColor(QColor(255, 0, 0));

	item = new QTableWidgetItem(QString::number(Time));
	this->setItem(TableIndex, 0, item);
	Time < TimeThreshold ? this->item(TableIndex, 0)->setTextColor(QColor(0, 255, 0)) : this->item(TableIndex, 0)->setTextColor(QColor(255, 0, 0));

	/*if (tableWord.size() == 0) tableWord = "OK";*/
	item = new QTableWidgetItem(tableWord.toStdString().c_str());
	this->setItem(TableIndex, 1, item);
	if (*isShowOkNg) bOK ? this->item(TableIndex, 1)->setTextColor(QColor(0, 255, 0)) : this->item(TableIndex, 1)->setTextColor(QColor(255, 0, 0));

	this->item(TableIndex, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->item(TableIndex, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->item(TableIndex, 0)->setBackground(QColor(50, 50, 50));
	this->item(TableIndex, 1)->setBackground(QColor(50, 50, 50));
	this->item(TableIndex, 2)->setBackground(QColor(50, 50, 50));
	this->verticalScrollBar()->setSliderPosition(TableIndex);
}

void MyTableWidget::inintMyTabel()
{
	this->setStyleSheet("QTableWidget{ background-color:rgb(60,60,60);border:1px solid #6B6B6B; color:#E3E3E3;} QTableCornerButton::section {background-color: rgb(60,60,60);border: 1px solid #000000;border-color: rgb(0, 0, 0);}");

	QFont font; font.setPointSize(10);
	this->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->horizontalHeader()->setFont(font);
	this->horizontalHeader()->setHighlightSections(false);
	this->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(60,60,60);}"); //41,136,41
	this->setColumnCount(3);
	this->setAlternatingRowColors(1); //设置每行的颜色不一样
	this->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(50,50,50);color:#E3E3E3;}");
	QStringList header; header << tr("Time") << tr("Result") << tr("FileName");
	this->horizontalHeader()->setStretchLastSection(true);
	for (int t = 0; t < 3; t++)
	{
		QTableWidgetItem    *headerItem = new QTableWidgetItem(header.at(t)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
		this->setHorizontalHeaderItem(t, headerItem); //设置表头单元格的Item

		//QFont font2; font2.setPointSize(9);
		//this->horizontalHeaderItem(0)->setFont(font2);
	}
	//设置列宽比例
	this->setColumnWidth(0, this->width()*0.15);
	this->setColumnWidth(1, this->width()*0.25);
	this->setColumnWidth(2, this->width()*0.4);
	//m_FileWidget->setColumnWidth(1, 300);
	//清除所有内容
	this->setRowCount(0);
	this->clearContents();
	this->verticalScrollBar()->setSingleStep(1);
}

void MyTableWidget::resizeEvent(QResizeEvent *event)
{
	this->setColumnWidth(0, this->width()*0.15);
	this->setColumnWidth(1, this->width()*0.25);
	this->setColumnWidth(2, this->width()*0.4);
	QTableWidget::resizeEvent(event);
}