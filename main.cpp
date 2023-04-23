#include "DynamicWidget.h"
#include <QtWidgets/QApplication>
#include <QTranslator>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>
#include <QWidget>
#include "EasyDump.h"


int main(int argc, char *argv[])
{
	SetUnhandledExceptionFilter(ExceptionFilter);//�쳣���� ����dmp�ļ�
	QApplication a(argc, argv);
	QFont f("Roboto",9); a.setFont(f);

	//�ж�����ظ���
	QSystemSemaphore semaphore("BTSemap", 1);
	semaphore.acquire();
	QSharedMemory shareMemory("BTKey");//���������ڴ����BTKeyΪ�ĳ������õĹ����ڴ�keyֵ���û������Լ���Ҫ�趨
	bool isRunning = false;
	if (shareMemory.attach())//�ж�����Ƿ��Ѿ���
	{
		isRunning = true;//�Ѿ���
	}
	else
	{
		shareMemory.create(1);//���δ�򿪣��򴴽������ڴ�
		isRunning = false;
	}
	semaphore.release();

	if (isRunning == false)
	{
		////  ------  ���뷭�� -------
		QTranslator translator; // �½�������
		translator.load("ChineseLanguage_zh.qm", "./"); // �������ɵ��ļ�
		QFile fileWhitchPro(".//config//language.json");
		if (fileWhitchPro.exists())
		{
			fileWhitchPro.open(QIODevice::ReadOnly);
			auto dataWhitchPro = fileWhitchPro.readAll();
			fileWhitchPro.close();
			QJsonParseError jErrorWhitchPro;	//����QJsonParseError����
			QJsonDocument jsonDocWhitchPro = QJsonDocument::fromJson(dataWhitchPro, &jErrorWhitchPro);
			if (jErrorWhitchPro.error == QJsonParseError::NoError)
			{
				QJsonObject rootObjWhitchPro = jsonDocWhitchPro.object();
				QJsonValue valueArrayTypes = rootObjWhitchPro.value("Language");
				if (valueArrayTypes.toInt() == 1)
				{
					a.installTranslator(&translator); //װ��
					//QFont f2("Microsoft YaHei",9); a.setFont(f2);
				}
			}
		}
		DynamicWidget w;
		w.show();
		w.move((QApplication::desktop()->width() - w.width()) / 2, (QApplication::desktop()->height() - w.height()) / 2);
		return a.exec();
	}
	else
	{
		QMessageBox::information(nullptr, QObject::tr("tips"), QObject::tr("The software has been opened"));
	}
}
