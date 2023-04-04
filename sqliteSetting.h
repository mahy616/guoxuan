#pragma once

#include <QObject>
#include "DataManager.h"

class sqliteSetting : public QObject
{
	Q_OBJECT

public:
	sqliteSetting(QObject *parent);
	~sqliteSetting();
	void init();
	//void createTable();
	//void insertRecord(const QString &name, int age);
	//void deleteRecord(const QString &name);
	//void updateRecord(const QString &name, int age);
	//int searchRecord(const QString &name);
public:
	void initConnect();
private:
	DataManager m_sqlData;
};
