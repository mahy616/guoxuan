#pragma once
#include "guoxuan.h"
#include <cmath>
guoxuan::guoxuan(QObject * parent)
	: QObject(parent)
{

}

guoxuan::~guoxuan()
{
}

bool guoxuan::processingData(std::string data, int station_index)
{
	    //////��ͷ
		///1:����ȱ���ֵ:����ȳ��޺��ƫ���ұ���;
		///2:����Ⱦ�ƫֵ:����ȳ��޺��ƫ������;
		///3.���ޱ���:��������,�м��׼ֵ���ޱ���.

	    ///1.���߳���:���ڱ�׼ֵ���÷����ƶ�,С�ڱ�׼ֵ���������ƶ�
   	    ///2.˫�߳������:������ֵ���,���ƶ�
	    ///3.˫�߳������,������ͬ:������  ��׼ֵ  �ķ����ƶ�
	    ///4.˫�߳��޲����:�ֱ�ͬ  ��׼ֵ  ����,����ֵ��ķ����ƶ�
	    ///***������ֵ��������λ
	    ///Ĭ���ж���

	if (m_head_test.toStdString().size() > 23)
		data = m_head_test.toStdString();
	
		std::vector<std::string>vtdata = splitstr(data, ',');
		QString log;
		if (vtdata.size() < 6)
		{
			return 0;
		}
		if (station_index == 1)
		{
			QString left,right;
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
			float head_left_value = std::stof(vtdata[0]) - m_head_left_warning;
			float head_right_value = std::stof(vtdata[2]) - m_head_right_warning;
			//if (std::stof(vtdata[0]) > std::stof(vtdata[2]))//����
			if (head_left_value > head_right_value)
			{
				//���ھ�ƫ��ֵ��С�ڱ�����ֵ
				//if (head_left_value - head_right_value > m_head_alignment2
				//	&& head_left_value - head_right_value < m_head_alignment)
				//{
				//	m_head.plc.Write("D6070", 1);
				//	emit sendLog(QString::fromLocal8Bit("��ͷA�����ȱ���"));
				//}//���ڱ�����ֵ
				//else if (head_left_value - head_right_value > m_head_alignment)
				//{
				//	m_head.plc.Write("D7022", 1);
				//	emit sendLog(QString::fromLocal8Bit("��ͷB�����ױ���"));
				//}
				m_head.plc.Write(left, 1);
				emit sendLog(QString::fromLocal8Bit("���ͻ�ͷ��ƫ�ź�"));
			}

			//else if (std::stof(vtdata[2]) > std::stof(vtdata[0]))//�ҳ���
			else if (head_left_value < head_right_value)
			{
				//////���ھ�ƫ��ֵ��С�ڱ�����ֵ
				//if (head_right_value- head_left_value > m_head_alignment2&& head_right_value- head_left_value < m_head_alignment)
				//{
				//	m_head.plc.Write("D6070", 1);
				//	emit sendLog(QString::fromLocal8Bit("��ͷA�����ȱ���"));

				//}//���ڱ�����ֵ
				//else if (head_right_value- head_left_value > m_head_alignment)//�Ҷ����
				//{

				//	m_head.plc.Write("D6072", 1);
				//	emit sendLog(QString::fromLocal8Bit("��ͷA�����ױ���"));
				//}
				m_head.plc.Write(right, 1);
				emit sendLog(QString::fromLocal8Bit("���ͻ�ͷ��ƫ�ź�"));
			}
			else//�޳���
			{
				m_head.plc.Write("M110", 0);
				m_head.plc.Write("M210", 0);
				emit sendLog(QString::fromLocal8Bit("���������ź�"));

			}



			if (abs(std::stof(vtdata[1]) - m_head_middle_warning) > m_head_alignment)//�м䳬��
			{
				m_head.plc.Write("D6068", 1);
				emit sendLog(QString::fromLocal8Bit("��ͷ�м䳬�ޱ���"));

			}

			if (abs(std::stof(vtdata[0]) - m_head_left_warning) > m_head_alignment2)//����
			{
				if (abs(std::stof(vtdata[0]) - m_head_left_warning) < m_head_alignment)
				{
					m_head.plc.Write("D6070", 1);
					emit sendLog(QString::fromLocal8Bit("��ͷ���ޱ���"));
				}
				else
				{
					m_head.plc.Write("D6072", 1);
					emit sendLog(QString::fromLocal8Bit("��ͷ���ױ���"));
				}
			}
			if (abs(std::stof(vtdata[2]) - m_head_right_warning) > m_head_alignment2)//�ҳ���
			{
				if (abs(std::stof(vtdata[0]) - m_head_right_warning) < m_head_alignment)
				{
					m_head.plc.Write("D7070", 1);
					emit sendLog(QString::fromLocal8Bit("��ͷ���ޱ���"));
				}
				else
				{
					m_head.plc.Write("D7072", 1);
					emit sendLog(QString::fromLocal8Bit("��ͷ���ױ���"));
				}
			}
		}
		//////��β
       ///1:����ȱ���ֵ:������������;�м�û�ж����;
       ///2:����Ⱦ�ƫֵ:����ȳ��޺��ƫ������;
       ///2.���ޱ���:�޷��ı���,�м䳬����׼ֵ����
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
			//�����
			if(m_type==1)	
			{
				if (std::stoi(vtdata[0]) - std::stoi(vtdata[3]) > m_end_left_alignment3)
				{
					if (std::stoi(vtdata[0]) - std::stoi(vtdata[3]) < m_end_left_alignment)
					{
						m_end.plc.Write("D6070", 1);
						emit sendLog(QString::fromLocal8Bit("��βA�����ȱ���"));
					}
					else
					{
						m_end.plc.Write("D6072", 1);
						emit sendLog(QString::fromLocal8Bit("��βA�����ױ���"));
					}		
					m_end.plc.Write(left, 1);//��λ:�������	
					m_end.plc.Write("M110", 0);
				}
				else if (std::stoi(vtdata[3]) - std::stoi(vtdata[0]) > m_end_left_alignment3)
				{
					if (std::stoi(vtdata[3]) - std::stoi(vtdata[0]) < m_end_left_alignment)
					{
						m_end.plc.Write("D6070", 1);
						emit sendLog(QString::fromLocal8Bit("��βA�����ȱ���"));
					}
					else
					{
						m_end.plc.Write("D6072", 1);
						emit sendLog(QString::fromLocal8Bit("��βA�����ױ���"));
					}
					m_end.plc.Write(right, 1);//��λ:�������
					m_end.plc.Write("M210", 0);

				}
				else
				{
					m_end.plc.Write("M210", 0);
					m_end.plc.Write("M110", 0);
				}
			}
			//���ж���
			else if(m_type==2)
			{
				int up_middle = std::stoi(vtdata[0]) - std::stoi(vtdata[2]);
				int down_middle= std::stoi(vtdata[3]) - std::stoi(vtdata[5]);
				if (up_middle - down_middle > 50)
				{
					m_end.plc.Write("D6068", 1);
					emit sendLog(QString::fromLocal8Bit("��β���ж���ȱ���"));
					m_end.plc.Write(left, 1);//��λ:�������	
					m_end.plc.Write("M110", 0);
				}
				else if (down_middle - up_middle > 50)
				{		
					m_end.plc.Write("D6068", 1);
					emit sendLog(QString::fromLocal8Bit("��β���ж���ȱ���"));
					m_end.plc.Write(right, 1);//��λ:�������
					m_end.plc.Write("M210", 0);
				}
				else
				{
					m_end.plc.Write("M210", 0);
					m_end.plc.Write("M110", 0);
				}
			}
			////�Ҷ���
			else if(m_type == 3)
			{
				if (std::stoi(vtdata[2]) - std::stoi(vtdata[5]) > m_end_right_alignment3)
				{
					if (std::stoi(vtdata[2]) - std::stoi(vtdata[5]) < m_end_right_alignment)
					{
						m_end.plc.Write("D7020", 1);
						emit sendLog(QString::fromLocal8Bit("��βB�����ȱ���"));
					}
					else
					{
						m_end.plc.Write("D7022", 1);
						emit sendLog(QString::fromLocal8Bit("��βB�����ױ���"));
					}
					m_end.plc.Write(left, 1);//��λ:�������	
					m_end.plc.Write("M110", 0);
				}
				else if (std::stoi(vtdata[5]) - std::stoi(vtdata[2]) > m_end_right_alignment3)
				{
					if (std::stoi(vtdata[5]) - std::stoi(vtdata[2]) < m_end_right_alignment)
					{
						m_end.plc.Write("D7020", 1);
						emit sendLog(QString::fromLocal8Bit("��βB�����ȱ���"));
					}
					else
					{
						m_end.plc.Write("D7022", 1);
						emit sendLog(QString::fromLocal8Bit("��βB�����ױ���"));
					}
					m_end.plc.Write(right, 1);//��λ:�������	
					m_end.plc.Write("M210", 0);
				}
				else
				{
					m_end.plc.Write("M210", 0);
					m_end.plc.Write("M110", 0);
				}
			}

			//�м䳬�ޱ���
			if (abs(std::stof(vtdata[1]) - m_end_middle_warning) > m_end_middle_alignment)
			{
				m_end.plc.Write("D6068", 1);
				emit sendLog(QString::fromLocal8Bit("��ͷ�м䱨��"));
			}
		}
		//m_sqlData
		//if (!sendPLC(station_index, QString::fromLocal8Bit(vtdata[0].c_str())))
		//{
		//	std::cout << "send faild" << std::endl;
		//}
	//}
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
			//log = QString::fromLocal8Bit("��ͷPLC���ӳɹ�");
			emit sendLog(QString::fromLocal8Bit("��ͷPLC���ӳɹ�"));
		}
		else if (data.plc.m_Config.IpStr == "192.168.1.12")
			emit sendLog(QString::fromLocal8Bit("��βPLC���ӳɹ�"));
		data.timer.start(1000);
	}
	else
	{
		if (data.plc.m_Config.IpStr == "192.168.1.11")
			emit sendLog(QString::fromLocal8Bit("��ͷPLC����ʧ��"));
		else if (data.plc.m_Config.IpStr == "192.168.1.12")
			emit sendLog(QString::fromLocal8Bit("��βPLC����ʧ��"));
	}
	//m_sqlData = new sqliteSetting(this);
}
void guoxuan::initStart()
{
	m_head.plc.m_Config.Port = 4881;
	m_head.plc.m_Config.IpStr = "192.168.1.11";
	m_end.plc.m_Config.Port = 4881;
	m_end.plc.m_Config.IpStr = "192.168.1.12";
	init(m_head);
	init(m_end);
	m_camera_timer.start(20000);
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
		std::cout << "write D6068 1 success" << std::endl;
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

void guoxuan::saveData()
{
}

std::vector<std::string> guoxuan::splitstr(const std::string & str, char tag)
{
	std::vector<std::string>  li;
	std::string subStr;

	//�����ַ�����ͬʱ��iλ�õ��ַ����뵽�Ӵ��У�������tag����Ҫ�и���ַ�ʱ�����һ���и�
	//��������֮�󼴿ɵõ��и����ַ�������
	for (size_t i = 0; i < str.length(); i++)
	{
		if (tag == str[i]) //���һ���и�
		{
			if (!subStr.empty())
			{
				li.push_back(subStr);
				subStr.clear();
			}
		}
		else //��iλ�õ��ַ������Ӵ�
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty()) //ʣ����Ӵ���Ϊ�������ַ���
	{
		li.push_back(subStr);
	}

	return li;
}

void guoxuan::set_head_alignment(float value)
{
	m_head_alignment = value*100;
}

void guoxuan::set_head_alignment2(float value)
{
	m_head_alignment2 = value * 100;
}

void guoxuan::set_head_left_warning(float value)
{
	m_head_left_warning = value*100;
}


void guoxuan::set_head_middle_warning(float value)
{
	m_head_middle_warning = value * 100;
}

void guoxuan::set_head_right_warning(float value)
{
	m_head_right_warning = value * 100;
}

void guoxuan::set_end_right_warning(float value)
{
	m_end_right_warning = value * 100;
}

void guoxuan::set_end_left_warning(float value)
{
	m_end_left_warning = value * 100;
}

void guoxuan::set_end_middle_warning(float value)
{
	m_end_middle_warning = value * 100;
}

void guoxuan::set_end_right_alignment(float value)
{
	m_end_right_alignment = value * 100;
}

void guoxuan::set_end_left_alignment(float value)
{
	m_end_left_alignment = value * 100;
}

void guoxuan::set_end_middle_alignment(float value)
{
	m_end_middle_alignment = value * 100;
}

void guoxuan::set_head_test(QString str)
{
	m_head_test = str;
}

void guoxuan::set_end_type(int type)
{
	m_type = type;
}

void guoxuan::set_head_type_direction(QString type)
{
	m_head_type_direction = type;
}

void guoxuan::set_end_type_direction(QString type)
{
	m_end_type_direction = type;
}

void guoxuan::set_end_left_alignment_3(float value)
{
	m_end_left_alignment3 = value*100;
}

void guoxuan::set_end_right_alignment_3(float value)
{
	m_end_right_alignment3 = value * 100;
}
