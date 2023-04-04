#include "DataManager.h"
#include "qdir.h"

DataManager::DataManager(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	InitVariables();
	InitConnections();
}

void DataManager::InitVariables()
{
	this->setWindowFlags(Qt::FramelessWindowHint);
	m_bConnected = false;

	//标题栏红色背景，tab选中蓝色，未选中灰色
	ui.tableWidget->setStyleSheet("QTabBar::tab{background-color:rgba(233, 238, 242, 1);color:rgba(0, 0, 0, 0.85);font:25pt '微软雅黑'}\
                                  QTabBar::tab::selected{background-color:rgb(0,170,0);color:rgb(255,255,0);font:25pt '微软雅黑'}\
                                  QTabBar::tab{ width:200 }\
 				                 QTabBar::tab{ height:40 }");
	//设置用户管理列表
	//QFont font("微软雅黑", 12);

	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//可伸缩，自适应列宽

	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//ui.tableWidget->horizontalHeader()->setFont(font);
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgba(0, 0, 0, 0.85);background:rgba(233, 238, 242, 1);}");
	ui.tableWidget->setColumnCount(6);
	ui.tableWidget->setAlternatingRowColors(1);
	QStringList header;
	header << QString::fromLocal8Bit("数据生成日期")
		<< QString::fromLocal8Bit("区域宽度1")
		<< QString::fromLocal8Bit("区域宽度2")
		<< QString::fromLocal8Bit("区域宽度3")
		<< QString::fromLocal8Bit("总宽度")
		<< QString::fromLocal8Bit("不良位置");
		   
	ui.tableWidget->setHorizontalHeaderLabels(header);

	ui.dateEdit_StartDate->setEnabled(false);
	ui.dateEdit_EndDate->setEnabled(false);

}

void DataManager::InitConnections()
{
	//connect(ui.pushButton_clear, &QPushButton::clicked, &m_sqlite, &sqliteSetting::sqlClear);
	connect(ui.pushButton_clear, &QPushButton::clicked, this, [=] {""; });

}

void DataManager::on_pushButton_clear_clicked()
{
	QMessageBox::information(nullptr, tr("tips"), tr("clear success"));
}

void DataManager::on_pushButton_out_clicked()
{
}

void DataManager::on_pushButton_Query_clicked()
{

}


