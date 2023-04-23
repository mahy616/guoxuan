#include "DataManager.h"
#include <QSqlTableModel>
#include <QAxObject>
DataManager::DataManager(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	InitVariables();
	InitConnections();
}

void DataManager::initTableView()
{


}


void DataManager::InitVariables()
{
	this->setWindowFlags(Qt::FramelessWindowHint);
	m_bConnected = false;

	//��������ɫ������tabѡ����ɫ��δѡ�л�ɫ
	ui.tableWidget->setStyleSheet("QTabBar::tab{background-color:rgba(233, 238, 242, 1);color:rgba(0, 0, 0, 0.85);font:25pt '΢���ź�'}\
                                  QTabBar::tab::selected{background-color:rgb(0,170,0);color:rgb(255,255,0);font:25pt '΢���ź�'}\
                                  QTabBar::tab{ width:200 }\
 				                 QTabBar::tab{ height:40 }");
	//�����û������б�
	//QFont font("΢���ź�", 12);

	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������������Ӧ�п�

	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//ui.tableWidget->horizontalHeader()->setFont(font);
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgba(0, 0, 0, 0.85);background:rgba(233, 238, 242, 1);}");
	ui.tableWidget->setColumnCount(4);
	ui.tableWidget->setAlternatingRowColors(1);
	QStringList header;
	header << QString::fromLocal8Bit("������������")<< QString::fromLocal8Bit("��������")<< QString::fromLocal8Bit("����ֵ")<< QString::fromLocal8Bit("λ��");
		   
	ui.tableWidget->setHorizontalHeaderLabels(header);

	ui.dateEdit_StartDate->setEnabled(false);
	ui.dateEdit_EndDate->setEnabled(false);
	ui.lineEdit_Code->hide();
	ui.toolButton_chooseTime->hide();
	ui.dateEdit_StartDate->hide();
	ui.dateEdit_EndDate->hide();

}

void DataManager::InitConnections()
{
	//connect(ui.pushButton_clear, &QPushButton::clicked, &m_sqlite, &sqliteSetting::sqlClear);
	connect(ui.pushButton_clear, &QPushButton::clicked, this, [=] {""; });

}

void DataManager::on_pushButton_clear_clicked()
{
	sqliteSetting::GetInstance()->deleteRecord();
}

void DataManager::on_pushButton_out_clicked()
{
	sqliteSetting::GetInstance()->writeCsv();
	QMessageBox msgBox;
	msgBox.setText(QString::fromLocal8Bit("�������"));
	msgBox.exec();

}

void DataManager::on_pushButton_Query_clicked()
{

		//ui.tableWidget->clear();//ÿ�β�ѯ֮ǰ�����һ��ԭ�е�����
		ui.tableWidget->setRowCount(0);
		ui.tableWidget->clearContents();
		QVector<QVector<QString>>all_data = sqliteSetting::GetInstance()->searchRecord();

		
		for (int row = 0; row < all_data.size(); row++)
		{
			ui.tableWidget->insertRow(ui.tableWidget->rowCount());
			for (int col = 0; col < all_data[row].size(); ++col)
			{
				QString Data = all_data[row][col];
				QTableWidgetItem *item = new QTableWidgetItem(Data);
				ui.tableWidget->setItem(row, col, item);
			}
		}
	
}

void DataManager::on_pushButton_close_clicked()
{
	reject();
}


