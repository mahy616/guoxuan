#pragma  once
#include "qsettings.h"


struct CFGDATA
{
	float Alignment;       //��ͷ����ȱ���ֵ
	float AlignmentLeft;   
	float AlignmentMiddle;
	float AlignmentRight;
	float Change;
	float ChangeLeft;
	float ChangeMiddle;
	float ChangeRight;
	float Warning;
	float WarningLeft;    //��ͷ���ޱ������׼ֵ
	float WarningMiddle;  //��ͷ���ޱ����б�׼ֵ
	float WarningRight;   //��ͷ���ޱ����ұ�׼ֵ
	int type;
};


const QString DIRECTION = "Direction";
const QString HEAD = QString::fromLocal8Bit("head");
const QString END = QString::fromLocal8Bit("end");

const QString HEADSETTING= "HeadSetting";

const QString HEADALIGNMENT = "HeadAlignment";
const QString HEADCHANGE = "HeadChange";
const QString HEADWARNINGLEFT = "HeadWarningLeft";
const QString HEADWARNINGMIDDLE = "HeadWarningMiddle";
const QString HEADWARNINGRIGHT = "HeadWarningRight";






const QString ENDSETTING = "EndSetting";

const QString ENDTYPE= "EndType";
const QString ENDALIGNMENTLEFT = "EndAlignmentLeft";
const QString ENDALIGNMENTMIDDLE = "EndAlignmentMiddle";
const QString ENDALIGNMENTRIGHT = "EndAlignmentRight";

const QString ENDCHANGELEFT = "EndChangeLeft";
const QString ENDCHANGERIGHT = "EndChangeRight";

const QString ENDWARNINGMIDDLE = "EndWarningMiddle";


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