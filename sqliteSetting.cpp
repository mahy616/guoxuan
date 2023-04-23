#include "sqliteSetting.h"
#include <QAxObject>
#include <QCoreApplication>
#include <QDateTime>
#include <QMessageBox>
sqliteSetting *sqliteSetting::m_Instance = NULL;
sqliteSetting::sqliteSetting(QObject *parent)
	:QObject(parent)
{
	init();
	createTable();
	initCsv();
}
sqliteSetting::~sqliteSetting()
{
	if (m_db.open())
	{
		//关闭数据库
		m_db.close();
	}
}
sqliteSetting * sqliteSetting::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new sqliteSetting();
	}
	return m_Instance;
}
void sqliteSetting::initCsv()
{
	// 我们都放C：//CSV文件夹里面吧
	QString strDir = QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("CSV");

	// 先检查有没有文件夹存在，没有就让程序创建文件夹先
	QDir dirCSV;
	if (!dirCSV.exists(strDir))
		dirCSV.mkpath(strDir);

	// 使用时间格式进行csv文件命名吧
	m_strFilePath = strDir + "/" + QString("csv%1.csv").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));

	// 因为是文件操作，安全一些都是加个锁
	//static QMutex mutex;
	//mutex.lock();
	QFile fileCSV;

	// 判断文件是否不存在
	if (!fileCSV.exists(m_strFilePath))
	{
		QFile file(m_strFilePath);
		if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		{
			QTextStream in(&file);
			QString strText("");
			// 文件不存在，第一次，我们就给他写个列表名字，这样csv文件打开时候查看的时候就比较清晰
			strText = QString::fromLocal8Bit("数据生成日期,") + QString::fromLocal8Bit("报警类型,") + QString::fromLocal8Bit("超限值,") + QString::fromLocal8Bit("位置");
			in << strText << '\n';
			file.close();
		}
	}
	//mutex.unlock();

}

void sqliteSetting::writeCsv()
{
	QVector<QVector<QString>>all_data = searchRecord();
	QFile file(m_strFilePath);
	if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
	{
		QTextStream in(&file);
		for (auto info =0; info<all_data.size(); info++)
		{
			if (all_data[info].size() < 4)
				continue;
			QString strMessage = QString(u8"%1,%2,%3,%4").arg(all_data[info][0]).arg(all_data[info][1]).arg(all_data[info][2]).arg(all_data[info][3]);
			in << strMessage << '\n';
		}
		file.close();
	}
}

void sqliteSetting::init()
{
	
	if (QSqlDatabase::contains("qt_sql_default_connection"))
		m_db = QSqlDatabase::database("qt_sql_default_connection");
	else
		m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("sqlite.db");

	//打开数据库
	if (m_db.open()) {
		qDebug() << "open success";
		//关闭数据库
		//db.close();
	}
}
void sqliteSetting::createTable()
{
	//sql语句不熟悉的推荐《sql必知必会》，轻松入门
	//如果不存在则创建my_table表
	//id自增,name唯一
	const QString sql = R"(
                      CREATE TABLE IF NOT EXISTS  my_table (
                      ID INTEGER   PRIMARY KEY AUTOINCREMENT NOT NULL,
                      time CHAR (50) UNIQUE NOT NULL,
                      type CHAR (50),
                      value CHAR (50),
                      name  CHAR (50)
                      );)";
	//QSqlQuery构造前，需要db已打开并连接
	//未指定db或者db无效时使用默认连接进行操作
	QSqlQuery query;

	if (query.exec(sql)) 
		qDebug() << "init table success";	
	else 
		qDebug() << "init table error" << query.lastError();
	
}
void sqliteSetting::insertRecord(SqlData &data)
{
	m_mutex.lock();
	QSqlQuery query(m_db);
	QString errMsg;
	query.setForwardOnly(true);
	bool rv = query.exec(QString(R"(INSERT INTO my_table(time,type,value,name) VALUES('%1','%2','%3','%4');)")
		.arg(data.time).arg(data.type).arg(data.value).arg(data.name));
	if (!rv)
	{
		errMsg = query.lastError().text();
		qDebug() << "insert data error:" << query.lastError().text();
	}
	else
	{
		qDebug() << "insert data success";
	}
	//方式一，直接执行SQL语句
	//方式二，绑定值，待定变量默认用问号占位,注意字符串也没有引号
	/*query.prepare(R"(INSERT INTO my_table(name,age) VALUES(?,?);)");
	query.addBindValue(name);
	query.addBindValue(age);
	query.exec();*/
	m_mutex.unlock();
}

void sqliteSetting::deleteRecord()
{
	QSqlQuery query;
	//方式一，直接执行SQL语句
	QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请确认是否要清空数据?"), QMessageBox::Yes | QMessageBox::No, NULL);
	if (message.exec() == QMessageBox::Yes)
	{
		query.exec(QString(R"(DELETE FROM my_table;)"));
	}
	//方式二，绑定值，待定变量默认用问号占位
	/*query.prepare(R"(DELETE FROM my_table WHERE name=?;)");
	query.addBindValue(name);
	query.exec();*/
}

void sqliteSetting::updateRecord(const QString & name, int age)
{
	QSqlQuery query;
	//方式一，直接执行SQL语句
	query.exec(QString(R"(UPDATE my_table SET age=%2 WHERE name='%1';)")
		.arg(name).arg(age));
	//方式二，绑定值，待定变量默认问号，可自定义
	/*query.prepare(R"(UPDATE my_table SET age=:age WHERE name=:name;)");
	query.bindValue(":name",name);//通过自定义的别名来替代
	query.bindValue(":age",age);
	query.exec();*/
}

QVector<QVector<QString>> sqliteSetting::searchRecord()
{
	SqlData sqlData;
	QSqlQuery query(m_db);
	QVector<QVector<QString>>all_data;
	QVector<QString>data;
	//query.exec(QString(R"(SELECT time FROM my_table WHERE name='%1';)")
	//	.arg(sqlData.time));

	query.exec("select * from my_table");

	//获取查询结果的第0个值，
	//如果结果是多行数据，可用while(query.next()){}遍历每一行
	int ageValue = -1;
	int row = 0;
	while (query.next())
	{
		for (int col = 1; col < query.record().count(); ++col)
		{
			//QString Data = query.value(col).toString();
			QString Data = query.value(col).toString();
			data.push_back(Data);
		}
		all_data.push_back(data);
		data.clear();
		row++;
	/*	sqlData.time = query.value(0).toString();
		sqlData.name= query.value(1).toString();
		sqlData.type = query.value(2).toString();
		sqlData.value = query.value(3).toString();
		m_*/
	}
	return all_data;
}
void sqliteSetting::initConnect()
{
	//connect(m_sqlData.)
}

