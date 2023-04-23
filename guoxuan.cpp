#pragma once
#include "guoxuan.h"
#include <cmath>
#include <QDateTime>




guoxuan::guoxuan(QObject * parent)
	: QObject(parent)
{
	///m_sqlData = new sqliteSetting(this);
	//m_sqlData.init();
	//m_sqlData.
	QString IniPath = QCoreApplication::applicationDirPath() + "/parametercfg.ini";
	cfg = new CConfig(IniPath);
}

guoxuan::~guoxuan()
{
}

bool guoxuan::processingData(std::string data, int station_index)
{
	    //////机头
		///1:对齐度报警值:对齐度超限后纠偏并且报警;
		///2:对齐度纠偏值:对齐度超限后纠偏不报警;
		///3.超限报警:左右两边,中间基准值超限报警.

	    ///1.单边超限:大于标准值往该方向移动,小于标准值往反方向移动
   	    ///2.双边超限相等:超限数值相等,不移动
	    ///3.双边超限相等,但方向不同:往大于  标准值  的方向移动
	    ///4.双边超限不相等:分别同  标准值  做差,往数值大的方向移动
	    ///***所有数值均带符号位
	    ///默认中对齐

	

	if (m_head_test.toStdString().size() > 19)
		data = m_head_test.toStdString();
	    qDebug() << QString::fromStdString(data);
	    data.erase(std::remove(data.begin(), data.end(), '.'), data.end());
		data.erase(std::remove(data.begin(), data.end(), 'A'), data.end());
		data.erase(std::remove(data.begin(), data.end(), 'B'), data.end());
	    std::vector<std::string>vtdata = splitstr(data, ',');
		if (vtdata.size() < 2)
			return false;
		std::vector<std::string>vtdata_str = splitstr(data, ',');
		std::vector<float>vtdata_float;
		for (auto info : vtdata_str)
		{
			vtdata_float.push_back(std::stof(info)/100);			
		}
	//	qDebug() << QString::fromStdString(data);
		emit sendLog(QString::fromStdString(data));
		//std::string a=std::to_string(vtdata_float[0]);
		//QString log;
		if (vtdata.size() < 6|| vtdata_float.size()<6)
		{
			return 0;
		}

		if (station_index == 1)
		{
			
			QString left, right;
			if (m_head_type_direction == "left")
			{
				left = "M110";
				right = "M210";
			}
			else
			{
				left = "M210";
				right = "M110";
			}
			sendPlcShow(m_head, vtdata);
			m_head_connection++;
			float head_left_value = vtdata_float[0] - m_head_left_warning;
			float head_right_value = vtdata_float[2] - m_head_right_warning;
			//防呆
			if (abs(head_left_value) > 20 || abs(head_right_value) > 20)
			{
				emit sendLog(QString::fromLocal8Bit("触发机头防呆"));
				m_head.plc.Write("M110", 0);
				m_head.plc.Write("M210", 0);
				return false;
			}
			if (abs(vtdata_float[1] - m_head_middle_warning) > m_head_alignment)//中间超限
			{
				m_head.plc.Write("D6068", 1);
				emit sendLog(QString::fromLocal8Bit("机头中间超限报警"));
				insertSql(QString::fromLocal8Bit("中间超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机头"));
			}
			if (head_left_value > head_right_value)
			{
				if (abs(head_left_value) > m_head_alignment2)//左超限
				{
					if (abs(head_left_value) < m_head_alignment)
					{
						m_head.plc.Write("D6070", 1);
						emit sendLog(QString::fromLocal8Bit("机头超限报警"));
					}
					else
					{
						m_head.plc.Write("D6072", 1);
						emit sendLog(QString::fromLocal8Bit("机头留白报警"));
					}

				}
				else if (abs(head_right_value) > m_head_alignment2)//右超限
				{
					if (abs(head_right_value) < m_head_alignment)
					{
						m_head.plc.Write("D7020", 1);
						emit sendLog(QString::fromLocal8Bit("机头超限报警"));
					}
					else
					{
						m_head.plc.Write("D7022", 1);
						emit sendLog(QString::fromLocal8Bit("机头留白报警"));
					}
				}
				if (head_left_value - head_right_value > m_head_alignment2)
				{
					m_head.plc.Write(left, 1);
					m_head.plc.Write(right, 0);
					emit sendLog(QString::fromLocal8Bit("发送机头纠偏信号") + left);
					insertSql(QString::fromLocal8Bit("边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机头") + left);
					qDebug() <<"station_index:"<< station_index<< ",M:"<<left;
				}
				else
				{
					m_head.plc.Write("M110", 0);
					m_head.plc.Write("M210", 0);
					m_head.plc.Write("D6070", 0);
					m_head.plc.Write("D6072", 0);
					m_head.plc.Write("D7020", 0);
					m_head.plc.Write("D7022", 0);
					emit sendLog(QString::fromLocal8Bit("发送正常信号"));
				}
			}
			else if (head_right_value > head_left_value)
			{
				if (abs(head_left_value) > m_head_alignment2)//左超限
				{
					if (abs(head_left_value) < m_head_alignment)
					{
						m_head.plc.Write("D6070", 1);
						emit sendLog(QString::fromLocal8Bit("机头超限报警"));
					}
					else
					{
						m_head.plc.Write("D6072", 1);
						emit sendLog(QString::fromLocal8Bit("机头留白报警"));
					}
				}
				else if (abs(head_right_value) > m_head_alignment2)//右超限
				{
					if (abs(head_right_value) < m_head_alignment)
					{
						m_head.plc.Write("D7020", 1);
						emit sendLog(QString::fromLocal8Bit("机头超限报警"));
					}
					else
					{
						m_head.plc.Write("D7022", 1);
						emit sendLog(QString::fromLocal8Bit("机头留白报警"));
					}
				}
				if (head_right_value - head_left_value > m_head_alignment2)
				{
					m_head.plc.Write(right, 1);
					m_head.plc.Write(left, 0);
					emit sendLog(QString::fromLocal8Bit("发送机头纠偏信号") + right);
					insertSql(QString::fromLocal8Bit("边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机头") + right);
					qDebug() << "station_index:" << station_index << ",M:" << right;
				}
				else
				{
					m_head.plc.Write("M110", 0);
					m_head.plc.Write("M210", 0);
					m_head.plc.Write("D6070", 0);
					m_head.plc.Write("D6072", 0);
					emit sendLog(QString::fromLocal8Bit("发送机头正常信号"));
				}
			}
			else
			{
				m_head.plc.Write("M110", 0);
				m_head.plc.Write("M210", 0);
				m_head.plc.Write("D6070", 0);
				m_head.plc.Write("D6072", 0);
				emit sendLog(QString::fromLocal8Bit("发送机头正常信号"));
			}
		}
		
		//////机尾
       ///1:对齐度报警值:左右两侧对齐度;中间没有对齐度;
       ///2:对齐度纠偏值:对齐度超限后纠偏不报警;
       ///2.超限报警:无法改变宽度,中间超过标准值报警
		else if (station_index == 2)
		{
			sendPlcShow(m_end, vtdata);
			m_end_connection++;
			QString left, right;
			if (m_end_type_direction == "left")
			{
				left = "M110";
				right = "M210";
			}
			else
			{
				left = "M210";
				right = "M110";
			}
			//左对齐
			if (m_type == 1)
			{
				//防呆
				if (abs(vtdata_float[0] - vtdata_float[3]) > 20)
				{
					emit sendLog(QString::fromLocal8Bit("触发机尾防呆"));
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("M210", 0);
					return false;
				}
				if (vtdata_float[0] - vtdata_float[3] > m_end_left_alignment3)
				{
					if (vtdata_float[0] - vtdata_float[3] < m_end_left_alignment)
					{
						m_end.plc.Write("D6070", 1);
						emit sendLog(QString::fromLocal8Bit("机尾A面对齐度报警"));
					}
					else
					{
						m_end.plc.Write("D6072", 1);
						emit sendLog(QString::fromLocal8Bit("机尾A面留白报警"));
					}
				
					emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + left);
					insertSql(QString::fromLocal8Bit("左对齐边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾")+left);
					m_end.plc.Write(left, 1);//机位:电机往左	
					m_end.plc.Write(right, 0);
				}
				else if (vtdata_float[3] - vtdata_float[0] > m_end_left_alignment3)
				{
					if (vtdata_float[3] - vtdata_float[0] < m_end_left_alignment)
					{
						m_end.plc.Write("D6070", 1);
						emit sendLog(QString::fromLocal8Bit("机尾A面对齐度报警"));
					}
					else
					{
						m_end.plc.Write("D6072", 1);
						emit sendLog(QString::fromLocal8Bit("机尾A面留白报警"));
					}
					emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + right);
					insertSql(QString::fromLocal8Bit("左对齐边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾")+right);
					m_end.plc.Write(right, 1);//机位:电机往右
					m_end.plc.Write(left, 0);
				}
				else
				{
					emit sendLog(QString::fromLocal8Bit("发送机尾正常信号"));
					m_end.plc.Write("M210", 0);
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("D6070", 0);
					m_end.plc.Write("D6072", 0);
				}
			}
			//居中对齐
			else if (m_type == 2)
			{
				auto up_middle = abs(vtdata_float[0] - vtdata_float[3]);
				auto down_middle = abs(vtdata_float[2] - vtdata_float[5]);
				//防呆
				if (abs(up_middle-down_middle) > 20)
				{
					emit sendLog(QString::fromLocal8Bit("触发机尾防呆"));
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("M210", 0);
					return false;
				}
				if (up_middle - down_middle > m_end_middle_alignment)
				{
					m_end.plc.Write("D6068", 1);
					emit sendLog(QString::fromLocal8Bit("机尾居中对齐度报警"));
					emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + left);
					m_end.plc.Write(left, 1);//机位:电机往左	
					m_end.plc.Write(right, 0);
					insertSql(QString::fromLocal8Bit("中间对齐中超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾")+left);
				}
				else if (down_middle - up_middle > m_end_middle_alignment)
				{
					m_end.plc.Write("D6068", 1);
					emit sendLog(QString::fromLocal8Bit("机尾居中对齐度报警"));
					emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + right);
					m_end.plc.Write(right, 1);//机位:电机往右
					m_end.plc.Write(left, 0);
					insertSql(QString::fromLocal8Bit("中间对齐中超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾")+right);
				}
				else
				{
					emit sendLog(QString::fromLocal8Bit("发送机尾正常信号"));
					m_end.plc.Write("M210", 0);
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("D6068", 0);
				}
			}
			////右对齐
			else if (m_type == 3)
			{
				//防呆
				if (abs(vtdata_float[2] - vtdata_float[5]) > 20)
				{
					emit sendLog(QString::fromLocal8Bit("触发机尾防呆"));
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("M210", 0);
					return false;
				}
				if (vtdata_float[2] - vtdata_float[5] > m_end_right_alignment3)
				{
					if (vtdata_float[2] - vtdata_float[5] < m_end_right_alignment)
					{
						m_end.plc.Write("D7020", 1);
						emit sendLog(QString::fromLocal8Bit("机尾B面对齐度报警"));
					}
					else
					{
						m_end.plc.Write("D7022", 1);
						emit sendLog(QString::fromLocal8Bit("机尾B面留白报警"));
					}
					emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + right);
					insertSql(QString::fromLocal8Bit("右对齐边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾")+right);
					m_end.plc.Write(left, 0);//机位:电机往左	
					m_end.plc.Write(right, 1);
				}
				else if (vtdata_float[5] - vtdata_float[2] > m_end_right_alignment3)
				{
					if (vtdata_float[5] - vtdata_float[2] < m_end_right_alignment)
					{
						m_end.plc.Write("D7020", 1);
						emit sendLog(QString::fromLocal8Bit("机尾B面对齐度报警"));
					}
					else
					{
						m_end.plc.Write("D7022", 1);
						emit sendLog(QString::fromLocal8Bit("机尾B面留白报警"));
					}
					emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号")+ left);
					insertSql(QString::fromLocal8Bit("右对齐边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾") + left);
					m_end.plc.Write(right, 0);//机位:电机往右	
					m_end.plc.Write(left, 1);
				}
				else
				{
					emit sendLog(QString::fromLocal8Bit("发送机尾正常信号"));
					m_end.plc.Write("M210", 0);
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("D7020", 0);
					m_end.plc.Write("D7022", 0);
				}
			}
			else if (m_type == 4)
			{

				float head_left_value = vtdata_float[0] - m_head_left_warning;
				float head_right_value = vtdata_float[2] - m_head_right_warning;
				//防呆
				if (abs(head_left_value) > 20 || abs(head_right_value) > 20)
				{
					emit sendLog(QString::fromLocal8Bit("触发机尾防呆"));
					m_end.plc.Write("M110", 0);
					m_end.plc.Write("M210", 0);
					return false;
				}
				if (abs(vtdata_float[1] - m_head_middle_warning) > m_head_alignment)//中间超限
				{
					m_end.plc.Write("D6068", 1);
					emit sendLog(QString::fromLocal8Bit("机尾中间超限报警"));
					insertSql(QString::fromLocal8Bit("单相机中间超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾"));
				}
				else
				{
					m_end.plc.Write("D6068", 0);
				}
				if (head_left_value > head_right_value)
				{
					if (abs(head_left_value) > m_head_alignment2)//左超限
					{
						if (abs(head_left_value) < m_head_alignment)
						{
							m_end.plc.Write("D6070", 1);
							emit sendLog(QString::fromLocal8Bit("机尾超限报警"));
						}
						else
						{
							m_end.plc.Write("D6072", 1);
							emit sendLog(QString::fromLocal8Bit("机尾留白报警"));
						}
					}
					else if (abs(head_right_value) > m_head_alignment2)//右超限
					{
						if (abs(head_right_value) < m_head_alignment)
						{
							m_end.plc.Write("D7020", 1);
							emit sendLog(QString::fromLocal8Bit("机尾超限报警"));
						}
						else
						{
							m_end.plc.Write("D7022", 1);
							emit sendLog(QString::fromLocal8Bit("机尾留白报警"));
						}
					}
					if (head_left_value - head_right_value > m_head_alignment2)
					{
						m_end.plc.Write(left, 1);
						m_end.plc.Write(right, 0);
						emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + left);
						insertSql(QString::fromLocal8Bit("单相机边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾") + left);
						qDebug() << "station_index:" <<station_index << "type:" << m_type << ",M:" << left;
					}
					else
					{
						m_end.plc.Write("M110", 0);
						m_end.plc.Write("M210", 0);
						m_end.plc.Write("D6070", 0);
						m_end.plc.Write("D6072", 0);
						m_end.plc.Write("D7020", 0);
						m_end.plc.Write("D7022", 0);
						emit sendLog(QString::fromLocal8Bit("发送机尾正常信号"));
					}
				}
				else if (head_right_value > head_left_value)
				{
					if (abs(head_left_value) > m_head_alignment2)//左超限
					{
						if (abs(head_left_value) < m_head_alignment)
						{
							m_end.plc.Write("D6070", 1);
							emit sendLog(QString::fromLocal8Bit("机尾超限报警"));
						}
						else
						{
							m_end.plc.Write("D6072", 1);
							emit sendLog(QString::fromLocal8Bit("机尾留白报警"));
						}
					}
					else if (abs(head_right_value) > m_head_alignment2)//右超限
					{
						if (abs(head_right_value) < m_head_alignment)
						{
							m_end.plc.Write("D7020", 1);
							emit sendLog(QString::fromLocal8Bit("机尾超限报警"));
						}
						else
						{
							m_end.plc.Write("D7022", 1);
							emit sendLog(QString::fromLocal8Bit("机尾留白报警"));
						}
					}

					if (head_right_value - head_left_value > m_head_alignment2)
					{
						m_end.plc.Write(right, 1);
						m_end.plc.Write(left, 0);
						emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号") + right);
						insertSql(QString::fromLocal8Bit("单相机边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾") + right);
						qDebug() << "station_index:" << station_index << "type:" << m_type << ",M:" << right;
					}
					else
					{
						m_end.plc.Write("M110", 0);
						m_end.plc.Write("M210", 0);
						m_end.plc.Write("D6070", 0);
						m_end.plc.Write("D6072", 0);
						m_end.plc.Write("D7020", 0);
						m_end.plc.Write("D7022", 0);
						emit sendLog(QString::fromLocal8Bit("发送机尾正常信号"));
					}
				}
				else
				{
						m_end.plc.Write("M110", 0);
						m_end.plc.Write("M210", 0);
						m_end.plc.Write("D6070", 0);
						m_end.plc.Write("D6072", 0);
						m_end.plc.Write("D7020", 0);
						m_end.plc.Write("D7022", 0);
						emit sendLog(QString::fromLocal8Bit("发送机尾正常信号"));
				}

				//float end_left_value = std::stof(vtdata[0]);
				//float end_right_value = std::stof(vtdata[2]);
				//if (end_left_value > end_right_value)
				//{
				//	m_end.plc.Write(left, 1);
				//	emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号"));
				//}
				//else if (end_left_value < end_right_value)
				//{
				//	m_end.plc.Write(right, 1);
				//	emit sendLog(QString::fromLocal8Bit("发送机尾纠偏信号"));
				//}
				//else//无超限
				//{
				//	m_end.plc.Write("M110", 0);
				//	m_end.plc.Write("M210", 0);
				//	emit sendLog(QString::fromLocal8Bit("发送正常信号"));
				//}
				//if (abs(std::stof(vtdata[1]) - m_end_middle_warning) > m_end_middle_alignment)//中间超限
				//{
				//	m_end.plc.Write("D6068", 1);
				//	emit sendLog(QString::fromLocal8Bit("机尾中间超限报警"));
				//	insertSql(QString::fromLocal8Bit("单相机中间超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾"));
				//}
				//if (abs(std::stof(vtdata[0]) - m_head_left_warning) > m_end_left_alignment)//左超限
				//{
				//	if (abs(std::stof(vtdata[0]) - m_head_left_warning) < m_end_left_alignment3)
				//	{
				//		m_end.plc.Write("D6070", 1);
				//		emit sendLog(QString::fromLocal8Bit("机尾超限报警"));
				//	}
				//	else
				//	{
				//		m_end.plc.Write("D6072", 1);
				//		emit sendLog(QString::fromLocal8Bit("机尾留白报警"));
				//	}
				//	insertSql(QString::fromLocal8Bit("单相机边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾"));
				//}
				//if (abs(std::stof(vtdata[2]) - m_head_right_warning) > m_end_right_alignment)//右超限
				//{
				//	if (abs(std::stof(vtdata[0]) - m_head_right_warning) < m_end_right_alignment3)
				//	{
				//		m_end.plc.Write("D7020", 1);
				//		emit sendLog(QString::fromLocal8Bit("机尾超限报警"));
				//	}
				//	else
				//	{
				//		m_end.plc.Write("D7022", 1);
				//		emit sendLog(QString::fromLocal8Bit("机尾留白报警"));
				//	}
				//	insertSql(QString::fromLocal8Bit("单相机边缘超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾"));
				//}
				//}
				////中间超限报警
				//if (abs(std::stof(vtdata[1]) - m_end_middle_warning) > m_end_middle_alignment)
				//{
				//	m_end.plc.Write("D6068", 1);
				//	emit sendLog(QString::fromLocal8Bit("机头中间报警"));
				//	insertSql(QString::fromLocal8Bit("中间对齐中超限"), vtdata[0] + "." + vtdata[1] + "." + vtdata[2], QString::fromLocal8Bit("机尾"));
				//}
			}
		}
	return true;
}
void guoxuan::init(PlcData &data)
{
	QString log;
	if (data.plc.Open())
	{
		data.connect = true;
		if (data.plc.m_Config.IpStr == "192.168.1.11")
		{
			//log = QString::fromLocal8Bit("机头PLC连接成功");
			emit sendLog(QString::fromLocal8Bit("机头PLC连接成功"));
		}
		else if (data.plc.m_Config.IpStr == "192.168.1.12")
			emit sendLog(QString::fromLocal8Bit("机尾PLC连接成功"));
		data.timer.start(1000);
	}
	else
	{
		if (data.plc.m_Config.IpStr == "192.168.1.11")
			emit sendLog(QString::fromLocal8Bit("机头PLC连接失败"));
		else if (data.plc.m_Config.IpStr == "192.168.1.12")
			emit sendLog(QString::fromLocal8Bit("机尾PLC连接失败"));
	}
	//m_sqlData = new sqliteSetting(this);
}
void guoxuan::initStart()
{
	m_head.plc.m_Config.Port = 4881;
	m_head.plc.m_Config.IpStr = "192.168.1.11";
	//m_head.plc.m_Config.IpStr = "127.0.0.1";
	m_end.plc.m_Config.Port = 4881;
	m_end.plc.m_Config.IpStr = "192.168.1.12";
	//m_end.plc.m_Config.IpStr = "127.0.0.1";
	//init(m_head);
	//init(m_end);
	//m_camera_timer.start(20000);
	initConnect();
}
void guoxuan::initConnect()
{
	connect(&m_head.timer, &QTimer::timeout, this, [=] {
		readPLC(m_head);
		if (!writeHeart(m_head))
			qDebug() << "m_data head false:";
	});
	connect(&m_end.timer, &QTimer::timeout, this, [this] {
		readPLC(m_end);
		if (!writeHeart(m_end))
			qDebug() << "m_data end false";
	});
	connect(&m_camera_timer, &QTimer::timeout, this, [this] {
		sendPlcConnect(m_head, m_head_connection, m_head_temp);
		sendPlcConnect(m_end, m_end_connection, m_end_temp);
	});
}
void guoxuan::sendPlcConnect(PlcData & data,int &connection, int &temp)
{
	if (temp != connection)
	{
		temp = connection;
	}
	else
	{
		if (!data.plc.Write("D6066", 1))
			qDebug() << "write plc D6066 false";
		qDebug() << "camera or other connect false";
	}
}
bool guoxuan::sendPLC(int station_index,QString data)
{
	if (!m_head.plc.Write("D1000", data))
		return false;
}

bool guoxuan::alignment_head(float left, float right)
{
	return false;
}

bool guoxuan::alignment_end(float value, AlignMentType type)
{
	return false;
}



bool guoxuan::readPLC(PlcData &data)
{
	int a;
	if (data.plc.Read("D6010",a))
	{
		m_data = QString::number(a);
		emit sendShow(m_data);
	}
	else
	{
		//data.plc.Read("D6010", 1);
		qDebug() << "m_data:" << m_data;
	}
	//if(is_ok)
	return false;
}

bool guoxuan::writeHeart(PlcData & data)
{
	m_Mutex.lock();
	bool is_success = data.plc.Write("D6064", 1);
	m_Mutex.unlock();
	if (!is_success)
	{
		qDebug() << "PLC heart wirte flase:";
		return false;
	}
	return true;
}

void guoxuan::sendPlcShow(PlcData & data, std::vector<std::string>value)
{
	if (!data.plc.Write("D6052", std::stoi(value[0])))
	{
		//data.plc.Close();
		//data.timer.stop();
		//data.connect = false;
		//init(data);
	}
	if (!data.plc.Write("D6054", std::stoi(value[3])))
		std::cout << "write D6068 1 success" << std::endl;
	if (!data.plc.Write("D6056", std::stoi(value[1])))
		std::cout << "write D6068 1 success" << std::endl;
	if (!data.plc.Write("D6058", std::stoi(value[4])))
		std::cout << "write D6068 1 success" << std::endl;
	if (!data.plc.Write("D6060", std::stoi(value[2])))
		std::cout << "write D6068 1 success" << std::endl;
	if (!data.plc.Write("D6062", std::stoi(value[5])))
		std::cout << "write D6068 1 success" << std::endl;


}

void guoxuan::insertSql(QString type, std::string value, QString station)
{
	SqlData sqldata;
	sqldata.time = QDateTime::currentDateTime().toString("yyyy-MM-dd.hh:mm:ss.zzz");
	sqldata.name = station;
	sqldata.type = type;
	sqldata.value = QString::fromStdString(value);
	sqliteSetting::GetInstance()->insertRecord(sqldata);
}

void guoxuan::saveData()
{
	cfg->Write(HEADSETTING, HEADALIGNMENT, m_head_alignment);
	cfg->Write(HEADSETTING, HEADCHANGE, m_head_alignment2 );
	cfg->Write(HEADSETTING, HEADWARNINGLEFT, m_head_left_warning );
	cfg->Write(HEADSETTING, HEADWARNINGMIDDLE, m_head_middle_warning );
	cfg->Write(HEADSETTING, HEADWARNINGRIGHT, m_head_right_warning );
	cfg->Write(ENDSETTING, ENDTYPE, m_type);
	cfg->Write(ENDSETTING, ENDALIGNMENTLEFT, m_end_left_alignment );
	cfg->Write(ENDSETTING, ENDALIGNMENTMIDDLE, m_end_middle_alignment);
	cfg->Write(ENDSETTING, ENDALIGNMENTRIGHT, m_end_right_alignment);
	cfg->Write(ENDSETTING, ENDCHANGELEFT, m_end_left_alignment3);
	cfg->Write(ENDSETTING, ENDCHANGERIGHT, m_end_right_alignment3);
	cfg->Write(ENDSETTING, ENDWARNINGMIDDLE, m_end_middle_warning);
}

std::vector<std::string> guoxuan::splitstr(const std::string & str, char tag)
{
	std::vector<std::string>  li;
	std::string subStr;

	//遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
	//遍历结束之后即可得到切割后的字符串数组
	for (size_t i = 0; i < str.length(); i++)
	{
		if (tag == str[i]) //完成一次切割
		{
			if (!subStr.empty())
			{
				li.push_back(subStr);
				subStr.clear();
			}
		}
		else //将i位置的字符放入子串
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty()) //剩余的子串作为最后的子字符串
	{
		li.push_back(subStr);
	}

	return li;
}

void guoxuan::set_head_alignment(float value)
{
	m_head_alignment = value;
	saveData();
}

void guoxuan::set_head_alignment2(float value)
{
	m_head_alignment2 = value ;
	saveData();
}

void guoxuan::set_head_left_warning(float value)
{
	m_head_left_warning = value;
	saveData();
}


void guoxuan::set_head_middle_warning(float value)
{
	m_head_middle_warning = value;
	saveData();
}

void guoxuan::set_head_right_warning(float value)
{
	m_head_right_warning = value;
	saveData();
}

//void guoxuan::set_end_right_warning(float value)
//{
//	m_end_right_warning = value * 100;
//}
//
//void guoxuan::set_end_left_warning(float value)
//{
//	m_end_left_warning = value * 100;
//}

void guoxuan::set_end_middle_warning(float value)
{
	m_end_middle_warning = value;
	saveData();
}

void guoxuan::set_end_right_alignment(float value)
{
	m_end_right_alignment = value;
	saveData();
}

void guoxuan::set_end_left_alignment(float value)
{
	m_end_left_alignment = value;
	saveData();
}

void guoxuan::set_end_middle_alignment(float value)
{
	m_end_middle_alignment = value;
	saveData();
}

void guoxuan::set_head_test(QString str)
{
	m_head_test = str;
}

void guoxuan::set_end_type(int type)
{
	m_type = type;
	saveData();
}

void guoxuan::set_head_type_direction(QString type)
{
	m_head_type_direction = type;
}

void guoxuan::set_end_type_direction(QString type)
{
	m_end_type_direction = type;
}

void guoxuan::set_head_data(CFGDATA & data)
{
	m_head_data = data;
	m_head_alignment = m_head_data.Alignment;
	m_head_alignment2 = m_head_data.Change;
	m_head_left_warning = m_head_data.WarningLeft;
	m_head_middle_warning = m_head_data.WarningMiddle;
	m_head_right_warning = m_head_data.WarningRight;
}

void guoxuan::set_end_data(CFGDATA & data)
{
	m_end_data = data;
	m_end_left_alignment = m_end_data.AlignmentLeft;
	m_end_middle_alignment = m_end_data.AlignmentMiddle;
	m_end_right_alignment = m_end_data.AlignmentRight;
	m_type = m_end_data.type;

	m_end_left_alignment3= m_end_data.ChangeLeft;
	m_end_right_alignment3= m_end_data.ChangeRight;
	m_end_middle_warning = m_end_data.WarningMiddle;
}

CFGDATA guoxuan::get_head_data()
{
	return m_head_data;
}

CFGDATA guoxuan::get_end_data()
{
	return m_end_data;
}

void guoxuan::set_end_left_alignment_3(float value)
{
	m_end_left_alignment3 = value;
	saveData();
}

void guoxuan::set_end_right_alignment_3(float value)
{
	m_end_right_alignment3 = value;
	saveData();
}

