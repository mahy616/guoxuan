#pragma  once
#include "qsettings.h"

const QString DIRECTION = "Direction";
const QString HEAD = QString::fromLocal8Bit("head");
const QString END = QString::fromLocal8Bit("end");


class CConfig
{
public:
	CConfig(QString IniPath);
	~CConfig();
	bool SectionExists(QString section);
	QStringList GetChildKeys(QString Section);
	int GetInt(QString Section,QString Key);
	double GetDouble(QString Section,QString Key);
	QString GetString(QString Section,QString Key);
	bool GetBool(QString Section,QString Key);
	void Write(QString Section,QString Key,QVariant Value);
	void RemoveKey(QString Section);
private:
	QString m_IniPath;
	QSettings *m_Settings;
};