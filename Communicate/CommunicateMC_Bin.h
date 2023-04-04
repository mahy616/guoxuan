#pragma once
#include "CommunicateBase.h"
#include <mutex>
#include <string>
#include <iostream>
#include "DialogMCBinSetting.h"

typedef struct MC_Config
{
	QString IpStr = "192.168.2.100";
	int Port = 4995;
	QString Address = "D50";
}MC_Config;

class CommunicateMC_Bin : public CommunicateBase
{
	Q_OBJECT
public:
	CommunicateMC_Bin();
	~CommunicateMC_Bin();
	virtual bool Open() override; //打开连接
	virtual bool Close() override; //关闭连接
	virtual void InitializationJson(QJsonObject inValue) override; //从配置文件读取初始化界面配置
	virtual QJsonObject GetConfigJson() override; //获取当前类的配置信息
	virtual QString GetCommunicationType() override;
	virtual QWidget* OpenSetting() override;
	virtual bool Write(QString address, QString message) override;
	virtual bool Write(QString address, int inNum) override;
	virtual bool Write(QString address, double infloat) override;
	virtual bool Read(QString address, QString &input) override;
	virtual bool Read(QString address, int &input) override;
	virtual bool Read(QString address, double &input) override;
	bool write_bool(const char* address, bool val);

public:
	MC_Config m_Config;
private:
	void InitVariables();
	int m_fd;
	std::mutex m_Mutex;
};

