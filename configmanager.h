#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QList>
#include <QObject>
#include <QUuid>
#include <QVector>
#include <string>


enum AlignMentType
{
	LEFT = 0,
	MIDDLE,
	RIGHT
};

struct SaveConfigItem
{
    std::string ok_path;
    std::string ng_path;
    std::string pic_format;
    unsigned int save_number = 1000;
    int save_day = 30;
    bool save_pic = true;
    bool save_ok = true;
    bool save_ng = true;
    bool delete_pic = true;
};

struct SaveConfigData
{
    SaveConfigItem original;
    SaveConfigItem rendered;
};
struct CameraConfigItem
{
	QString camera_name;
	int camera_index;
	float Exposure{0};
	float Gain{0};
	bool open=false;
	int camerahandle_index;
};
struct CameraConfigData
{
	CameraConfigItem first_camera;
	CameraConfigItem second_camera;
	CameraConfigItem third_camera;
	CameraConfigItem four_camera;
	std::vector<QString>vtCameraName;
};

struct PlcAddressItem
{
	QString first_start;
	QString second_start;
	QString first_enble;
	QString second_enble;
	QString first_result;
	QString second_result;
	int first_code;
	int second_code;
	QString heart;
};

struct CommunicationConfigData
{
	QString ip;
	QString port;
	QString hearbeat;
	PlcAddressItem address;
	std::vector<QString>vtCommunicationName;
};

struct SystemConfigData
{
    int recipe;
};

struct FormulaValue
{
	AlignMentType type;
	QString value;
};

struct FormulaConfigData
{
	FormulaValue station_head;
	FormulaValue station_end;
};


struct SqliteDataItem
{
	std::string time;
	std::string location;
	std::vector<std::string>value;
	float width;
	float hight;
};

struct SqliteConfigData
{
	std::vector<SqliteDataItem>vtSql;
};

struct ThresholdConfigData
{
	int zheng_pengshang;
	int ce_huashang;
	int ce_cashang;
	int ce_yashang;
	int ce_pengshang;
	int ce_tiefen;
	std::vector<int>vt_zheng_threshold;
	std::vector<int>vt_area_threshold;
	std::vector<int>vt_ce_long_threshold;
	std::vector<int>vt_ce_short_threshold;
	std::vector<int>vt_bei_threshold;
	std::vector<QString>vtThreshold;
};
class ConfigManager : public QObject
{
    Q_OBJECT

public:
    ~ConfigManager() = default;

    static bool loadFromFile();
    static bool saveToFile();
    static ConfigManager &getInstance();
    bool init();
	void LoadConfig();
	FormulaValue setFormula(QString data);

	const SqliteConfigData &getSqliteConfigData() const
	{
		return m_sql_config_data;
	}

    const SystemConfigData &getSystemConfigData() const
    {
        return m_system_config_data;
    }

    const CameraConfigData &getCameraConfigData() const
    {
        return m_camera_config_data;
    }

	const FormulaConfigData &getFormulaConfigData() const
	{
		return m_formula_config_data;
	}

	const ThresholdConfigData &getThresholdConfigData() const
	{
		return m_threshold_config_data;
	}

	const SaveConfigData &getImageSaveConfigData() const
	{
		return m_image_save_config_data;
	}

	const CommunicationConfigData &getCommunicationConfigData() const
	{
		return m_communication_config_data;
	}

	void setSqliteConfigData(const SqliteConfigData &config)
	{
		m_sql_config_data = std::move(config);
	}

    void setSystemConfigData(const SystemConfigData &config)
    {
        m_system_config_data = std::move(config);
    }

    void setImageSaveConfigData(const SaveConfigData &config)
    {
        m_image_save_config_data = std::move(config);
    }

	void setCameraConfigData(const CameraConfigData &config)
	{
		m_camera_config_data = std::move(config);
	}

	void setThresholdConfigData(const ThresholdConfigData &config)
	{
		m_threshold_config_data = std::move(config);
	}

	void setFormulaConfigData(const FormulaConfigData &config)
	{
		m_formula_config_data = std::move(config);
	}
	void setCommunicationConfigData(const CommunicationConfigData &config)
	{
		m_communication_config_data = std::move(config);
	}

private:
    ConfigManager() = default;


private:
    static std::string sm_config_major_version;
    SystemConfigData m_system_config_data;
    SaveConfigData m_image_save_config_data;
	CameraConfigData m_camera_config_data;
	FormulaConfigData m_formula_config_data;
	ThresholdConfigData m_threshold_config_data;
	CommunicationConfigData m_communication_config_data;
	SqliteConfigData m_sql_config_data;

};

#endif  // CONFIGMANAGER_H
