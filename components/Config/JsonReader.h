#pragma once
#include <qobject.h>
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

class JsonReader : public QObject
{
	Q_OBJECT
public:
	ConfigResult GetConfigResult(QString configPath);
	void JsonReader::GetLabelsName(QString DataJSPath, ConfigResult &AnayliszeResult);
	bool CheckModelNum(ConfigResult m_ConfigResult, std::vector<LableInfos> vec_LableInfos);
	bool GiveModelLables(ConfigResult& m_ConfigResult, std::vector<LableInfos> vec_LableInfos);
	void FindModuleNumeToInser(std::string moduleName, ConfigResult& m_ConfigResult, std::vector<std::string> inLabels);
};

