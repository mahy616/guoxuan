#include "sqliteSetting.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriver>
sqliteSetting::sqliteSetting(QObject *parent)
	:QObject(parent)
{
	init();
	//createTable();
}
sqliteSetting::~sqliteSetting()
{
}


void sqliteSetting::init()
{
	//QSqlDatabase db;
	//if (QSqlDatabase::contains("qt_sql_default_connection"))
	//	db = QSqlDatabase::database("qt_sql_default_connection");
	//else
	//	db = QSqlDatabase::addDatabase("QSQLITE");
	//db.setDatabaseName("sqlite.db");

	////打开数据库
	//if (db.open()) {
	//	qDebug() << "open success";
	//	//关闭数据库
	//	//db.close();
	//}
}
//void sqliteSetting::createTable()
//{
//	//sql语句不熟悉的推荐《sql必知必会》，轻松入门
//	//如果不存在则创建my_table表
//	//id自增,name唯一
//	const QString sql = R"(
//                      CREATE TABLE IF NOT EXISTS  my_table (
//                      id   INTEGER   PRIMARY KEY AUTOINCREMENT NOT NULL,
//                      name CHAR (50) UNIQUE NOT NULL,
//                      age  INTEGER
//                      );)";
//	//QSqlQuery构造前，需要db已打开并连接
//	//未指定db或者db无效时使用默认连接进行操作
//	QSqlQuery query;
//
//	if (query.exec(sql)) 
//		qDebug() << "init table success";	
//	else 
//		qDebug() << "init table error" << query.lastError();
//	
//}
//void sqliteSetting::insertRecord(const QString & name, int age)
//{
//	QSqlQuery query;
//	//方式一，直接执行SQL语句
//	query.exec(QString(R"(INSERT INTO my_table(name,age) VALUES('%1',%2);)")
//		.arg(name).arg(age));
//	//方式二，绑定值，待定变量默认用问号占位,注意字符串也没有引号
//	/*query.prepare(R"(INSERT INTO my_table(name,age) VALUES(?,?);)");
//	query.addBindValue(name);
//	query.addBindValue(age);
//	query.exec();*/
//}
//
//void sqliteSetting::deleteRecord(const QString & name)
//{
//	QSqlQuery query;
//	//方式一，直接执行SQL语句
//	query.exec(QString(R"(DELETE FROM my_table WHERE name='%1';)")
//		.arg(name));
//	//方式二，绑定值，待定变量默认用问号占位
//	/*query.prepare(R"(DELETE FROM my_table WHERE name=?;)");
//	query.addBindValue(name);
//	query.exec();*/
//}
//
//void sqliteSetting::updateRecord(const QString & name, int age)
//{
//	QSqlQuery query;
//	//方式一，直接执行SQL语句
//	query.exec(QString(R"(UPDATE my_table SET age=%2 WHERE name='%1';)")
//		.arg(name).arg(age));
//	//方式二，绑定值，待定变量默认问号，可自定义
//	/*query.prepare(R"(UPDATE my_table SET age=:age WHERE name=:name;)");
//	query.bindValue(":name",name);//通过自定义的别名来替代
//	query.bindValue(":age",age);
//	query.exec();*/
//}
//
//int sqliteSetting::searchRecord(const QString & name)
//{
//	QSqlQuery query;
//	query.exec(QString(R"(SELECT age FROM my_table WHERE name='%1';)")
//		.arg(name));
//
//	//获取查询结果的第0个值，
//	//如果结果是多行数据，可用while(query.next()){}遍历每一行
//	int ageValue = -1;
//	if (query.next()) {
//		ageValue = query.value(0).toInt();
//	}
//	qDebug() << ageValue;
//	return ageValue;
//}
void sqliteSetting::initConnect()
{
	//connect(m_sqlData.)
}

