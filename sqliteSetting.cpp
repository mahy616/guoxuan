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

	////�����ݿ�
	//if (db.open()) {
	//	qDebug() << "open success";
	//	//�ر����ݿ�
	//	//db.close();
	//}
}
//void sqliteSetting::createTable()
//{
//	//sql��䲻��Ϥ���Ƽ���sql��֪�ػᡷ����������
//	//����������򴴽�my_table��
//	//id����,nameΨһ
//	const QString sql = R"(
//                      CREATE TABLE IF NOT EXISTS  my_table (
//                      id   INTEGER   PRIMARY KEY AUTOINCREMENT NOT NULL,
//                      name CHAR (50) UNIQUE NOT NULL,
//                      age  INTEGER
//                      );)";
//	//QSqlQuery����ǰ����Ҫdb�Ѵ򿪲�����
//	//δָ��db����db��Чʱʹ��Ĭ�����ӽ��в���
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
//	//��ʽһ��ֱ��ִ��SQL���
//	query.exec(QString(R"(INSERT INTO my_table(name,age) VALUES('%1',%2);)")
//		.arg(name).arg(age));
//	//��ʽ������ֵ����������Ĭ�����ʺ�ռλ,ע���ַ���Ҳû������
//	/*query.prepare(R"(INSERT INTO my_table(name,age) VALUES(?,?);)");
//	query.addBindValue(name);
//	query.addBindValue(age);
//	query.exec();*/
//}
//
//void sqliteSetting::deleteRecord(const QString & name)
//{
//	QSqlQuery query;
//	//��ʽһ��ֱ��ִ��SQL���
//	query.exec(QString(R"(DELETE FROM my_table WHERE name='%1';)")
//		.arg(name));
//	//��ʽ������ֵ����������Ĭ�����ʺ�ռλ
//	/*query.prepare(R"(DELETE FROM my_table WHERE name=?;)");
//	query.addBindValue(name);
//	query.exec();*/
//}
//
//void sqliteSetting::updateRecord(const QString & name, int age)
//{
//	QSqlQuery query;
//	//��ʽһ��ֱ��ִ��SQL���
//	query.exec(QString(R"(UPDATE my_table SET age=%2 WHERE name='%1';)")
//		.arg(name).arg(age));
//	//��ʽ������ֵ����������Ĭ���ʺţ����Զ���
//	/*query.prepare(R"(UPDATE my_table SET age=:age WHERE name=:name;)");
//	query.bindValue(":name",name);//ͨ���Զ���ı��������
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
//	//��ȡ��ѯ����ĵ�0��ֵ��
//	//�������Ƕ������ݣ�����while(query.next()){}����ÿһ��
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

