#pragma once
#include <qobject.h>
#include "CommunicateMC_Bin.h"
#include "sqliteSetting.h"
#include <QTimer>
#include <Qdebug>
#include "configmanager.h"
#include "QMutex"
#include "config.h"
class guoxuan : public QObject
{
	Q_OBJECT
	struct PlcData
	{
		CommunicateMC_Bin plc;
		QTimer timer;
		bool connect;
	};


private:
	guoxuan(QObject * parent = nullptr);
	~guoxuan();
public:

	static guoxuan& get_instance()
	{
		static guoxuan instance;
		return instance;
	}

public:
	bool processingData(std::string data, int station_index);
	void init(PlcData &data);
	void initStart();
	void initConnect();
	void sendPlcConnect(PlcData &data,int &connection,int &temp);
	bool sendPLC(int station_index, QString data);
	bool alignment_head(float left, float right);
	bool alignment_end(float value, AlignMentType type);
	bool readPLC(PlcData &data);
	bool writeHeart(PlcData &data);
	void sendPlcShow(PlcData &data, std::vector<std::string>value);
	void insertSql(QString type, std::string value,QString station);

	void saveData();
	std::vector<std::string> splitstr(const std::string& str, char tag);
	void set_head_alignment(float value);
	void set_head_alignment2(float value);
	void set_head_left_warning(float value);
	void set_head_middle_warning(float value);
	void set_head_right_warning(float value);
	//void set_end_right_warning(float value);
	//void set_end_left_warning(float value);
	void set_end_middle_warning(float value);
	void set_end_right_alignment(float value);
	void set_end_left_alignment(float value);
	void set_end_middle_alignment(float value);
	void set_head_test(QString str);
	void set_end_type(int type);
	void set_head_type_direction(QString type);
	void set_end_type_direction(QString type);
	void set_head_data(CFGDATA&data);
	void set_end_data(CFGDATA&data);
	CFGDATA get_head_data();
	CFGDATA get_end_data();
	void set_end_left_alignment_3(float value);
	void set_end_right_alignment_3(float value);
public:
	PlcData m_head;
	PlcData m_end;
	//sqliteSetting m_sqlData;
	QString m_data;

private:
	float m_head_alignment = 0;        //机头对齐度报警值
	float m_head_alignment2 = 0;       //机头对齐度纠偏值
	float m_head_left_warning = 0;     //机头左标准值    
	float m_head_middle_warning = 0;   //机头中标准值 
	float m_head_right_warning = 0;    //机头右标准值 
	float m_end_left_alignment = 0;    //机尾左对齐限值
	float m_end_middle_alignment = 0;  //机尾中对齐限值
	float m_end_right_alignment = 0;   //机尾右对齐限值
	//float m_end_left_warning = 0;
	float m_end_middle_warning = 0;    //机尾中标准值
	//float m_end_right_warning = 0;
	QString m_head_test;
	QMutex m_Mutex;
	QTimer m_camera_timer;
	int m_head_connection = 0;
	int m_end_connection = 0;
	int m_head_temp = 0;
	int m_end_temp = 0;
	int m_type = 0;
	QString m_head_type_direction = 0;
	QString m_end_type_direction = 0;
	CFGDATA m_head_data;
	CFGDATA m_end_data;
	float m_end_left_alignment3 = 0;   //机尾左对齐限值
	float m_end_right_alignment3 = 0;  //机尾右对齐限值
	CConfig *cfg;
signals:
	void sendLog(QString);
	void sendShow(QString);
};

//