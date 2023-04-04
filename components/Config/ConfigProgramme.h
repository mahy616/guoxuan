#pragma once
#include "PublicParamter.h"
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <QFile>
#include <qDebug>
#include <QTextCodec>
#include <iostream>
#include <fstream>
#include <QDir>
#include "CommunicateBase.h"
#include "CommunicateSerial.h"
#include "CommunicateTCP.h"
#include "CommunicateMC_Bin.h"

class ConfigProgramme
{
public:
	bool LoadConfig(QString loadProName);
	QString LoadWhichPro();
	void SaveWhichPro(QString);
	std::vector<QString> LoadModelName(QString programmeName);
	void SaveConfig(QString programmeName);
	QString m_Selectprogramme; //不包含路径 !!!!

	static ConfigProgramme *GetInstance();
	string EnumToString(SdkModelType inType);
	SdkModelType StringToEnum(string inStr);
public:
	std::vector<WindowsConfig> AllConfig;
	void deleteWindow(int windowIndex);
	//保存信息
	SaveImageConfig m_CameraSave;
	SaveImageConfig m_RenderSave;
	QMap<QString, CommunicateBase*> m_Comunicate;
private:
	static ConfigProgramme *m_Instance;
	bool DirExistEx(QString fullPath);
};

