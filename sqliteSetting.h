#pragma once
#include <QDebug>
#include <QObject>
//#include "DataManager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include "qdir.h"
#include <QFileDialog>
#include<QMutex>
struct SqlData
{
	int id;
	QString time;
	QString name;
	QString type;
	QString value;
};

class sqliteSetting : public QObject
{
	Q_OBJECT
public:

	static sqliteSetting *GetInstance();
	sqliteSetting(QObject *parent=nullptr);
	~sqliteSetting();
	void initCsv();
	void writeCsv();
	

public:

	void init();
	void createTable();
	void insertRecord(SqlData &data);
	void deleteRecord();
	void updateRecord(const QString &name, int age);
	QVector<QVector<QString>> searchRecord();
public:
	void initConnect();
private:
	static sqliteSetting *m_Instance;
	//DataManager m_sqlData;
	QSqlDatabase m_db;
	QString m_strFilePath;
	QMutex m_mutex;
};
