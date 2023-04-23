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
		//�ر����ݿ�
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
	// ���Ƕ���C��//CSV�ļ��������
	QString strDir = QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("CSV");

	// �ȼ����û���ļ��д��ڣ�û�о��ó��򴴽��ļ�����
	QDir dirCSV;
	if (!dirCSV.exists(strDir))
		dirCSV.mkpath(strDir);

	// ʹ��ʱ���ʽ����csv�ļ�������
	m_strFilePath = strDir + "/" + QString("csv%1.csv").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));

	// ��Ϊ���ļ���������ȫһЩ���ǼӸ���
	//static QMutex mutex;
	//mutex.lock();
	QFile fileCSV;

	// �ж��ļ��Ƿ񲻴���
	if (!fileCSV.exists(m_strFilePath))
	{
		QFile file(m_strFilePath);
		if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		{
			QTextStream in(&file);
			QString strText("");
			// �ļ������ڣ���һ�Σ����Ǿ͸���д���б����֣�����csv�ļ���ʱ��鿴��ʱ��ͱȽ�����
			strText = QString::fromLocal8Bit("������������,") + QString::fromLocal8Bit("��������,") + QString::fromLocal8Bit("����ֵ,") + QString::fromLocal8Bit("λ��");
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

	//�����ݿ�
	if (m_db.open()) {
		qDebug() << "open success";
		//�ر����ݿ�
		//db.close();
	}
}
void sqliteSetting::createTable()
{
	//sql��䲻��Ϥ���Ƽ���sql��֪�ػᡷ����������
	//����������򴴽�my_table��
	//id����,nameΨһ
	const QString sql = R"(
                      CREATE TABLE IF NOT EXISTS  my_table (
                      ID INTEGER   PRIMARY KEY AUTOINCREMENT NOT NULL,
                      time CHAR (50) UNIQUE NOT NULL,
                      type CHAR (50),
                      value CHAR (50),
                      name  CHAR (50)
                      );)";
	//QSqlQuery����ǰ����Ҫdb�Ѵ򿪲�����
	//δָ��db����db��Чʱʹ��Ĭ�����ӽ��в���
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
	//��ʽһ��ֱ��ִ��SQL���
	//��ʽ������ֵ����������Ĭ�����ʺ�ռλ,ע���ַ���Ҳû������
	/*query.prepare(R"(INSERT INTO my_table(name,age) VALUES(?,?);)");
	query.addBindValue(name);
	query.addBindValue(age);
	query.exec();*/
	m_mutex.unlock();
}

void sqliteSetting::deleteRecord()
{
	QSqlQuery query;
	//��ʽһ��ֱ��ִ��SQL���
	QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ȷ���Ƿ�Ҫ�������?"), QMessageBox::Yes | QMessageBox::No, NULL);
	if (message.exec() == QMessageBox::Yes)
	{
		query.exec(QString(R"(DELETE FROM my_table;)"));
	}
	//��ʽ������ֵ����������Ĭ�����ʺ�ռλ
	/*query.prepare(R"(DELETE FROM my_table WHERE name=?;)");
	query.addBindValue(name);
	query.exec();*/
}

void sqliteSetting::updateRecord(const QString & name, int age)
{
	QSqlQuery query;
	//��ʽһ��ֱ��ִ��SQL���
	query.exec(QString(R"(UPDATE my_table SET age=%2 WHERE name='%1';)")
		.arg(name).arg(age));
	//��ʽ������ֵ����������Ĭ���ʺţ����Զ���
	/*query.prepare(R"(UPDATE my_table SET age=:age WHERE name=:name;)");
	query.bindValue(":name",name);//ͨ���Զ���ı��������
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

	//��ȡ��ѯ����ĵ�0��ֵ��
	//�������Ƕ������ݣ�����while(query.next()){}����ÿһ��
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

