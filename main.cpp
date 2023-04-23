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
	SetUnhandledExceptionFilter(ExceptionFilter);//异常处理 生成dmp文件
	QApplication a(argc, argv);
	QFont f("Roboto",9); a.setFont(f);

	//判断软件重复打开
	QSystemSemaphore semaphore("BTSemap", 1);
	semaphore.acquire();
	QSharedMemory shareMemory("BTKey");//建立共享内存对象，BTKey为改程序设置的共享内存key值，用户根据自己需要设定
	bool isRunning = false;
	if (shareMemory.attach())//判断软件是否已经打开
	{
		isRunning = true;//已经打开
	}
	else
	{
		shareMemory.create(1);//软件未打开，则创建共享内存
		isRunning = false;
	}
	semaphore.release();

	if (isRunning == false)
	{
		////  ------  载入翻译 -------
		QTranslator translator; // 新建翻译类
		translator.load("ChineseLanguage_zh.qm", "./"); // 导入生成的文件
		QFile fileWhitchPro(".//config//language.json");
		if (fileWhitchPro.exists())
		{
			fileWhitchPro.open(QIODevice::ReadOnly);
			auto dataWhitchPro = fileWhitchPro.readAll();
			fileWhitchPro.close();
			QJsonParseError jErrorWhitchPro;	//创建QJsonParseError对象
			QJsonDocument jsonDocWhitchPro = QJsonDocument::fromJson(dataWhitchPro, &jErrorWhitchPro);
			if (jErrorWhitchPro.error == QJsonParseError::NoError)
			{
				QJsonObject rootObjWhitchPro = jsonDocWhitchPro.object();
				QJsonValue valueArrayTypes = rootObjWhitchPro.value("Language");
				if (valueArrayTypes.toInt() == 1)
				{
					a.installTranslator(&translator); //装入
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
