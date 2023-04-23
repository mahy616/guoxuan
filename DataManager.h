#pragma once
#include "ui_DataManager.h"

#include <QDebug>
#include "QMessageBox"
#include "sqliteSetting.h"

class DataManager :public QDialog
{
	Q_OBJECT
public:
	DataManager(QDialog *parent = NULL);
	bool GetConnectStatus() { return m_bConnected; }

	void initTableView();

private:	
	Ui::DataManager ui;
	QSqlDatabase m_db;
	bool m_bConnected;
	//sqliteSetting m_sqlite;
	//QSqlTableModel *m_model;
private:

	void InitVariables();
	void InitConnections();

public slots:
	void on_pushButton_clear_clicked();
	void on_pushButton_out_clicked();
	void on_pushButton_Query_clicked();
	void on_pushButton_close_clicked();
};
