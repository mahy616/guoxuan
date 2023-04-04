
#include "configmanager.h"
#include "_utils.h"
#include <QCoreApplication>
std::string ConfigManager::sm_config_major_version = "1";

ConfigManager &ConfigManager::getInstance()
{
    static ConfigManager s_config_manager;
    return s_config_manager;
}

bool ConfigManager::init()
{
	//CLog read_log;
	//if (read_log.init()!="smartmore-wentai2.0-victory")
	//{
	//	LOGE(ConfigManager, "encryption dog error");
	//	return false;
	//}
	QString IniPath = QCoreApplication::applicationDirPath() + "/cfg/config.ini";
	if (!Utils::CheckFile(IniPath))

	if (IniUtil::get_instance().LoadFile(IniPath.toStdString().c_str()))
	{
		LoadConfig();
		return true;
	}
	else
	{
		return false;
	}
	
}

void ConfigManager::LoadConfig()
{
	ThresholdConfigData threshold_data;
	threshold_data.vt_zheng_threshold.push_back(0);
	threshold_data.vt_zheng_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Zheng_Area_HuaShang").toInt());
	threshold_data.vt_zheng_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Zheng_Area_CaShang").toInt());
	threshold_data.vt_zheng_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Zheng_Area_YaShang").toInt());
	threshold_data.vt_zheng_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Zheng_Area_PengShang").toInt());
	threshold_data.vt_zheng_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Zheng_Area_TieFen").toInt());

	threshold_data.vt_area_threshold.push_back(0);
	threshold_data.vt_area_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_Area_HuaShang").toInt());
	threshold_data.vt_area_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_Area_CaShang").toInt());
	threshold_data.vt_area_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_Area_YaShang").toInt());
	threshold_data.vt_area_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_Area_PengShang").toInt());
	threshold_data.vt_area_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_Area_TieFen").toInt());
	threshold_data.vt_area_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_Area_low_PengShang").toInt());

	threshold_data.vt_ce_long_threshold.push_back(0);
	threshold_data.vt_ce_long_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_long_HuaShang").toInt());
	threshold_data.vt_ce_long_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_long_CaShang").toInt());
	threshold_data.vt_ce_long_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_long_YaShang").toInt());
	threshold_data.vt_ce_long_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_long_PengShang").toInt());
	threshold_data.vt_ce_long_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_long_TieFen").toInt());
	threshold_data.vt_ce_long_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_long_low_PengShang").toInt());

	threshold_data.vt_ce_short_threshold.push_back(0);
	threshold_data.vt_ce_short_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_short_HuaShang").toInt());
	threshold_data.vt_ce_short_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_short_CaShang").toInt());
	threshold_data.vt_ce_short_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_short_YaShang").toInt());
	threshold_data.vt_ce_short_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_short_PengShang").toInt());
	threshold_data.vt_ce_short_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_short_TieFen").toInt());
	threshold_data.vt_ce_short_threshold.push_back(IniUtil::get_instance().GetIniConfigQStr("Ce_short_low_PengShang").toInt());
	ConfigManager::getInstance().setThresholdConfigData(threshold_data);

	//CameraConfigData camera_data;
	//for (auto configdata : ConfigManager::getInstance().getCamera())
	//{
	//	camera_data.vtCameraName.push_back(IniUtil::get_instance().GetIniConfigQStr(configdata).toString());
	//}
	//ConfigManager::getInstance().setCameraConfigData(camera_data);

	CommunicationConfigData communication_data;
	communication_data.address.first_start = IniUtil::get_instance().GetIniConfigQStr("1#_start").toString();
	communication_data.address.second_start = IniUtil::get_instance().GetIniConfigQStr("2#_start").toString();
	communication_data.address.first_enble = IniUtil::get_instance().GetIniConfigQStr("1#_enble").toString();
	communication_data.address.second_enble = IniUtil::get_instance().GetIniConfigQStr("2#_enble").toString();
	communication_data.address.first_result = IniUtil::get_instance().GetIniConfigQStr("1#_result").toString();
	communication_data.address.second_result = IniUtil::get_instance().GetIniConfigQStr("2#_result").toString();
	communication_data.address.first_code = IniUtil::get_instance().GetIniConfigQStr("1#_code").toInt();
	communication_data.address.second_code = IniUtil::get_instance().GetIniConfigQStr("2#_code").toInt();
	communication_data.address.heart = IniUtil::get_instance().GetIniConfigQStr("Heart_address").toString();
	communication_data.ip = IniUtil::get_instance().GetIniConfigQStr("Ip").toString();
	communication_data.port = IniUtil::get_instance().GetIniConfigQStr("Port").toString();
	ConfigManager::getInstance().setCommunicationConfigData(communication_data);

	FormulaConfigData formula_data;

	ConfigManager::getInstance().setFormulaConfigData(formula_data);

	SaveConfigData save_image_data;
	save_image_data.original.ok_path = IniUtil::get_instance().GetIniConfigQStr("src_ok_path").toString().toStdString();
	save_image_data.original.ng_path = IniUtil::get_instance().GetIniConfigQStr("src_ng_path").toString().toStdString();
	save_image_data.rendered.ok_path = IniUtil::get_instance().GetIniConfigQStr("ai_ok_path").toString().toStdString();
	save_image_data.rendered.ng_path = IniUtil::get_instance().GetIniConfigQStr("ai_ng_path").toString().toStdString();
	save_image_data.original.pic_format = IniUtil::get_instance().GetIniConfigQStr("src_format").toString().toStdString();
	save_image_data.rendered.pic_format = IniUtil::get_instance().GetIniConfigQStr("ai_format").toString().toStdString();
	ConfigManager::getInstance().setImageSaveConfigData(save_image_data);
}

FormulaValue ConfigManager::setFormula(QString  data)
{
	FormulaValue value;

	return value;
}


bool ConfigManager::loadFromFile()
{
	return true;
}

bool ConfigManager::saveToFile()
{
	FormulaConfigData formula_data = ConfigManager::getInstance().getFormulaConfigData();


	SaveConfigData save_image_data = ConfigManager::getInstance().getImageSaveConfigData();
	IniUtil::get_instance().SetValue("SaveImage/src_ok_path", save_image_data.original.ok_path.c_str());
	IniUtil::get_instance().SetValue("SaveImage/src_ng_path", save_image_data.original.ng_path.c_str());
	IniUtil::get_instance().SetValue("SaveImage/ai_ok_path", save_image_data.rendered.ok_path.c_str());
	IniUtil::get_instance().SetValue("SaveImage/ai_ng_path", save_image_data.rendered.ng_path.c_str());
	IniUtil::get_instance().SetValue("SaveImage/src_format", save_image_data.original.pic_format.c_str());
	IniUtil::get_instance().SetValue("SaveImage/ai_format", save_image_data.rendered.pic_format.c_str());

	ThresholdConfigData threshold_data = ConfigManager::getInstance().getThresholdConfigData();
	IniUtil::get_instance().SetValue("Threshold/Zheng_Area_HuaShang", threshold_data.vt_zheng_threshold[1]);
	IniUtil::get_instance().SetValue("Threshold/Zheng_Area_CaShang", threshold_data.vt_zheng_threshold[2]);
	IniUtil::get_instance().SetValue("Threshold/Zheng_Area_YaShang", threshold_data.vt_zheng_threshold[3]);
	IniUtil::get_instance().SetValue("Threshold/Zheng_Area_PengShang", threshold_data.vt_zheng_threshold[4]);
	IniUtil::get_instance().SetValue("Threshold/Zheng_Area_TieFen", threshold_data.vt_zheng_threshold[5]);


	IniUtil::get_instance().SetValue("Threshold/Ce_Area_HuaShang", threshold_data.vt_area_threshold[1]);
	IniUtil::get_instance().SetValue("Threshold/Ce_Area_CaShang", threshold_data.vt_area_threshold[2]);
	IniUtil::get_instance().SetValue("Threshold/Ce_Area_YaShang", threshold_data.vt_area_threshold[3]);
	IniUtil::get_instance().SetValue("Threshold/Ce_Area_PengShang", threshold_data.vt_area_threshold[4]);
	IniUtil::get_instance().SetValue("Threshold/Ce_Area_TieFen", threshold_data.vt_area_threshold[5]);
	IniUtil::get_instance().SetValue("Threshold/Ce_Area_low_PengShang", threshold_data.vt_area_threshold[6]);

	IniUtil::get_instance().SetValue("Threshold/Ce_long_HuaShang", threshold_data.vt_ce_long_threshold[1]);
	IniUtil::get_instance().SetValue("Threshold/Ce_long_CaShang", threshold_data.vt_ce_long_threshold[2]);
	IniUtil::get_instance().SetValue("Threshold/Ce_long_YaShang", threshold_data.vt_ce_long_threshold[3]);
	IniUtil::get_instance().SetValue("Threshold/Ce_long_PengShang", threshold_data.vt_ce_long_threshold[4]);
	IniUtil::get_instance().SetValue("Threshold/Ce_long_TieFen", threshold_data.vt_ce_long_threshold[5]);
	IniUtil::get_instance().SetValue("Threshold/Ce_long_low_PengShang", threshold_data.vt_ce_long_threshold[6]);

	IniUtil::get_instance().SetValue("Threshold/Ce_short_HuaShang", threshold_data.vt_ce_short_threshold[1]);
	IniUtil::get_instance().SetValue("Threshold/Ce_short_CaShang", threshold_data.vt_ce_short_threshold[2]);
	IniUtil::get_instance().SetValue("Threshold/Ce_short_YaShang", threshold_data.vt_ce_short_threshold[3]);
	IniUtil::get_instance().SetValue("Threshold/Ce_short_PengShang", threshold_data.vt_ce_short_threshold[4]);
	IniUtil::get_instance().SetValue("Threshold/Ce_short_TieFen", threshold_data.vt_ce_short_threshold[5]);
	IniUtil::get_instance().SetValue("Threshold/Ce_short_low_PengShang", threshold_data.vt_ce_short_threshold[6]);
	return 1;
}


