#include "ConfigProgramme.h"
#include "components/Camera/SoftTriggerConnect.h"
#include "DynamicWidget.h"

ConfigProgramme *ConfigProgramme::m_Instance = NULL;
ConfigProgramme *ConfigProgramme::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new ConfigProgramme();
	}
	return m_Instance;
}

bool ConfigProgramme::LoadConfig(QString loadProName)
{
	//待修改
	m_Selectprogramme = loadProName;

	//通过名字加载的方案
	QFile file(".//config//programme//" + loadProName + ".json");
	if (!file.exists()) return false;
	file.open(QIODevice::ReadOnly);
	auto data = file.readAll();
	file.close();
	QJsonParseError jError;	//创建QJsonParseError对象
	QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &jError);
	if (jError.error != QJsonParseError::NoError) return false;

	QJsonObject rootObj = jsonDoc.object();
	QJsonValue valueArrayTypes = rootObj.value("ProgrammeCongigVec");
	QJsonArray ProgrammeArray = valueArrayTypes.toArray();
	for (int i = 0; i < ProgrammeArray.size(); i++)
	{

		QJsonValue ProgrammeValue = ProgrammeArray[i];
		QJsonObject  childObject = ProgrammeValue.toObject();
		//****当前配置方案名****
		std::string ProgrammeName = childObject.value("ProgrammeName").toString().toStdString();

		//****当前方案具体配置信息数组****
		std::vector<WindowsConfig> Programme_Info;
		QJsonValue valueWindowsArray = childObject.value("WindowsConfigArrays");
		QJsonArray ProgrammeConfigInfo = valueWindowsArray.toArray();
		//QJsonArray ProgrammeConfigInfo= childObject.value("WindowsConfigArrays").toArray();
		for (int windowIndex = 0; windowIndex < ProgrammeConfigInfo.count(); windowIndex++)
		{
			WindowsConfig OneWindowConfig;

			QJsonValue WindowValue = ProgrammeConfigInfo[windowIndex];
			QJsonObject  childObject_Window = WindowValue.toObject();

			//******************************************** 模型选择的配置读取 *************************************************
			OneWindowConfig.m_ModelChoice._jsonPath = childObject_Window["_jsonPath"].toString();
			OneWindowConfig.m_ModelChoice.TypeName = childObject_Window["TypeName"].toString().toLocal8Bit();
			OneWindowConfig.m_ModelChoice._useGPU = childObject_Window["_useGPU"].toBool();
			OneWindowConfig.m_ModelChoice._gpuID = childObject_Window["_gpuID"].toInt();
			//modileID的数组循环
			QJsonArray modileID_Array = childObject_Window["moduleID"].toArray();
			for (int Index = 0; Index < modileID_Array.size(); Index++)
			{
				string Name = modileID_Array[Index].toString().toLocal8Bit();
				OneWindowConfig.m_ModelChoice.moduleID.push_back(Name);
			}
			//modeType的数组循环
			QJsonArray modeType_Array = childObject_Window["modeType"].toArray();
			for (int Index = 0; Index < modeType_Array.size(); Index++)
			{
				string Name = modeType_Array[Index].toString().toLocal8Bit();
				OneWindowConfig.m_ModelChoice.modeType.push_back(Name);
			}
			//modeType的数组循环
			QJsonArray RealNameValue_Array = childObject_Window["RealNameValue"].toArray();
			for (int Index = 0; Index < RealNameValue_Array.size(); Index++)
			{
				string Name = RealNameValue_Array[Index].toString().toLocal8Bit();
				OneWindowConfig.m_ModelChoice.RealNameValue.push_back(Name);
			}
			//labelNames的循环
			QJsonArray labelsNamesVec_Array = childObject_Window["labelsNamesVec"].toArray();
			for (int Index = 0; Index < labelsNamesVec_Array.size(); Index++)
			{
				std::vector<std::string> OneLabel;
				QJsonArray OneLabelVec = labelsNamesVec_Array[Index].toArray();
				for (int Index2 = 0; Index2 < OneLabelVec.size(); Index2++)
				{
					string Name = OneLabelVec[Index2].toString().toLocal8Bit();
					OneLabel.push_back(Name);
				}
				OneWindowConfig.m_ModelChoice.labelsNamesVec.push_back(OneLabel);
			}
			//soutionIndex的数组循环
			QJsonArray soutionIndex_Array = childObject_Window["soutionIndex"].toArray();
			for (int Index = 0; Index < soutionIndex_Array.size(); Index++)
			{
				int Name = soutionIndex_Array[Index].toInt();
				OneWindowConfig.m_ModelChoice.soutionIndex.push_back(Name);
			}
			//*******************************************************************************************************************







			//******************************************************阈值设置的配置读取********************************************
			std::vector<AllThreshold> m_Thresholds;
			QJsonArray ThresholdInfo = childObject_Window["ThresholdParams"].toArray();
			for (int ThresholdIndex = 0; ThresholdIndex < ThresholdInfo.size(); ThresholdIndex++)
			{
				AllThreshold OneThreshold;

				QJsonObject  ThresholdObj = ThresholdInfo[ThresholdIndex].toObject();
				//分割阈值配置读取
				QJsonObject oneSegThreshold= ThresholdObj["SegThreshold"].toObject();
				OneThreshold._PostParam._segThreshold._isFilterMaxGray = oneSegThreshold["_isFilterMaxGray"].toBool();
				OneThreshold._PostParam._segThreshold._isFilterMinGray = oneSegThreshold["_isFilterMinGray"].toBool();

				QJsonArray  arrayValues = oneSegThreshold["_segThresholdVec"].toArray();
				std::vector<SegThresholdVec> VecSegThresholds;
				for (int thresholdIndex = 0; thresholdIndex < arrayValues.size(); thresholdIndex++)
				{
					SegThresholdVec oneSegValue;
					QJsonObject thresholdVaule = arrayValues[thresholdIndex].toObject();
					oneSegValue._area = thresholdVaule["_area"].toInt();
					oneSegValue._width = thresholdVaule["_width"].toInt();
					oneSegValue._height = thresholdVaule["_height"].toInt();
					oneSegValue._minGrayValue = thresholdVaule["_minGrayValue"].toInt();
					oneSegValue._maxGrayValue = thresholdVaule["_maxGrayValue"].toInt();
					VecSegThresholds.push_back(oneSegValue);
				}
				OneThreshold._PostParam._segThreshold._segThresholdVec = VecSegThresholds;

				//检测阈值配置读取
				QJsonObject oneDetectionConfig = ThresholdObj["DetectionThreshold"].toObject();
				QJsonArray  oneDetectionThreshold = oneDetectionConfig["_detectionThresholdVec"].toArray();
				std::vector<DetectionThresholdVec> OneDetectionThresholdVec;
				for (int thresholdIndex = 0; thresholdIndex < oneDetectionThreshold.size(); thresholdIndex++)
				{
					DetectionThresholdVec oneDetValue;
					QJsonObject thresholdVaule = oneDetectionThreshold[thresholdIndex].toObject();
					oneDetValue._area = thresholdVaule["_area"].toInt();
					oneDetValue._width = thresholdVaule["_width"].toInt();
					oneDetValue._height = thresholdVaule["_height"].toInt();
					oneDetValue._score = thresholdVaule["_score"].toDouble();
					oneDetValue._iou = thresholdVaule["_iou"].toDouble();
					OneDetectionThresholdVec.push_back(oneDetValue);
				}
				OneThreshold._PostParam._detectionThreshold._detectionThresholdVec = OneDetectionThresholdVec;

				//分类阈值配置读取
				QJsonObject oneClassifyThreshold = ThresholdObj["ClassifyThreshold"].toObject();
				QJsonArray  oneClassThreshold = oneClassifyThreshold["_classificationThresholdVec"].toArray();
				std::vector<ClassificationThresholdVec> m_ClassValue;
				for (int thresholdIndex = 0; thresholdIndex < oneClassThreshold.size(); thresholdIndex++)
				{
					ClassificationThresholdVec oneValue;
					QJsonObject thresholdVaule = oneClassThreshold[thresholdIndex].toObject();
					oneValue._score = thresholdVaule["_score"].toDouble();
					m_ClassValue.push_back(oneValue);
				}
				OneThreshold._PostParam._classificationThreshold._classificationThresholdVec = m_ClassValue;

				//OCR阈值配置读取
				QJsonObject oneOCRThreshold = ThresholdObj["OCRThreshold"].toObject();
				//SDK阈值
				QJsonArray  oneOcrThresholdArray = oneOCRThreshold["_OcrSdkThresholdVec"].toArray();
				std::vector<OcrSdkThreshold> m_OCRValue;
				for (int thresholdIndex = 0; thresholdIndex < oneOcrThresholdArray.size(); thresholdIndex++)
				{
					OcrSdkThreshold oneValue;
					QJsonObject thresholdVaule = oneOcrThresholdArray[thresholdIndex].toObject();
					oneValue._score = thresholdVaule["_score"].toDouble();
					oneValue._iou = thresholdVaule["_iou"].toDouble();
					m_OCRValue.push_back(oneValue);
				}
				//排序方式
				bool isSortByY = oneOCRThreshold["SortFunction"].toInt();
				//匹配字符串
				QJsonArray  oneMatchStrArray = oneOCRThreshold["MatchStrVec"].toArray();
				std::vector<QString> m_MatchStrValue;
				for (int thresholdIndex = 0; thresholdIndex < oneMatchStrArray.size(); thresholdIndex++)
				{
					QString thresholdVaule = oneMatchStrArray[thresholdIndex].toString();
					m_MatchStrValue.push_back(thresholdVaule);
				}
				OneThreshold._PostParam._ocrThreshold.SdkThreshold = m_OCRValue;
				OneThreshold._PostParam._ocrThreshold.SortFunction = isSortByY ? SortByY : SortByX;
				OneThreshold._PostParam._ocrThreshold.MatchStrVec = m_MatchStrValue;


				//显示的阈值
				QJsonObject oneRenderThreshold = ThresholdObj["RenderShowParams"].toObject();
				QJsonArray  oneContourThreshold = oneRenderThreshold["_contourThickness"].toArray();//轮廓厚度
				std::vector<int> m_ContourValue;
				for (int thresholdIndex = 0; thresholdIndex < oneContourThreshold.count(); thresholdIndex++)
				{
					int thresholdVaule = oneContourThreshold[thresholdIndex].toInt();
					m_ContourValue.push_back(thresholdVaule);
				}
				QJsonArray  oneContourColor = oneRenderThreshold["_contourColor"].toArray();//轮廓颜色
				std::vector<cv::Scalar> m_ContourColorValue;
				for (int thresholdIndex = 0; thresholdIndex < oneContourColor.count(); thresholdIndex++)
				{
					
					QJsonObject thresholdVaule = oneContourColor[thresholdIndex].toObject();
					cv::Scalar oneColor(thresholdVaule["R"].toInt(), thresholdVaule["G"].toInt(), thresholdVaule["B"].toInt());
					m_ContourColorValue.push_back(oneColor);
				}
				OneThreshold._RenderParam._contourThickness = m_ContourValue;
				OneThreshold._RenderParam._contourColor = m_ContourColorValue;

				m_Thresholds.push_back(OneThreshold);
			}
			OneWindowConfig.m_Threshold = m_Thresholds;


			//时间阈值
			if(childObject_Window.contains("OverTimeThreshold")) 
				OneWindowConfig.m_TimeThreshold.TimeThreshold = childObject_Window["OverTimeThreshold"].toInt();
			switch (childObject_Window["TimeType"].toInt())
			{
			case 0:
				OneWindowConfig.m_TimeThreshold.m_TimeType = OnlyViMo;
				break;
			case 1:
				OneWindowConfig.m_TimeThreshold.m_TimeType = OnlyPostProcess;
				break;
			case 2:
				OneWindowConfig.m_TimeThreshold.m_TimeType = ViMoAndPostProcess;
				break;
			default:
				OneWindowConfig.m_TimeThreshold.m_TimeType = OnlyViMo;
				break;
			}


			//****图像源配置信息****
			OneWindowConfig.m_ImageSourceConfig.ImageFilePath = childObject_Window["ImageFilePath"].toString();
			OneWindowConfig.m_ImageSourceConfig.ImageSource_isCamera = childObject_Window["ImageSource_isCamera"].toBool();

			//******相机配置信息******
			//****是否打开相机****
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.isGrabbing = childObject_Window["isOpenCamera"].toBool();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.exposure = childObject_Window["exposure"].toInt();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.gain = childObject_Window["gain"].toInt();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.name = childObject_Window["name"].toString();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.triggerMode = childObject_Window["triggerMode"].toString();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.triggerSource = childObject_Window["triggerSource"].toString();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.SoftTrigerCommunication = childObject_Window["SoftTrigerCommunication"].toString();
			OneWindowConfig.m_ImageSourceConfig.m_CameraInfo.GrabStr = childObject_Window["SoftTrigerStr"].toString();


			Programme_Info.push_back(OneWindowConfig);
		}
		AllConfig = Programme_Info;
	}



	QJsonValue CommunicateArrayTypes = rootObj.value("ComunicationConfig");
	QJsonArray CommunicateArray = CommunicateArrayTypes.toArray();
	for (int i = 0; i < CommunicateArray.size(); i++)
	{
		QJsonValue CommunicateValue = CommunicateArray[i];
		QJsonObject  childObject = CommunicateValue.toObject();
		//****当前通信模块名字****
		QString CommunicationName = childObject.value("CommunicationName").toString();
		QString CommunicationType = childObject.value("CommunicationType").toString();
		CommunicateBase* m_InserCommunicate = nullptr;
		if (CommunicationType == "Ethernet Port")
		{
			m_InserCommunicate = new CommunicateTCP;
		}
		if (CommunicationType == "Serial Port")
		{
			m_InserCommunicate = new CommunicateSerial;
		}
		if (CommunicationType == "Mitsubishi MC")
		{
			m_InserCommunicate = new CommunicateMC_Bin;
		}
		m_InserCommunicate->InitializationJson(childObject.value("Config").toObject());
		if (CommunicationName.size() != 0)
			m_Comunicate.insert(CommunicationName, m_InserCommunicate);
	}


	//存图模块的配置信息
	QJsonObject CameraSaveImageObj = rootObj.value("CameraSaveImage").toObject();
	if (CameraSaveImageObj.contains("isSave")) m_CameraSave.isSave = CameraSaveImageObj["isSave"].toBool();
	if (CameraSaveImageObj.contains("ImgPathStr")) m_CameraSave.ImgPathStr = CameraSaveImageObj["ImgPathStr"].toString();
	if (CameraSaveImageObj.contains("SaveType")) m_CameraSave.SaveType = CameraSaveImageObj["SaveType"].toString();
	if (CameraSaveImageObj.contains("isDeleteNums")) m_CameraSave.isDeleteNums = CameraSaveImageObj["isDeleteNums"].toBool();
	if (CameraSaveImageObj.contains("deleteNums")) m_CameraSave.deleteNums = CameraSaveImageObj["deleteNums"].toInt();
	if (CameraSaveImageObj.contains("isDeleteDays")) m_CameraSave.isDeleteDays = CameraSaveImageObj["isDeleteDays"].toBool();
	if (CameraSaveImageObj.contains("deleteDays")) m_CameraSave.deleteDays = CameraSaveImageObj["deleteDays"].toInt();
	if (CameraSaveImageObj.contains("isDeleteMemory")) m_CameraSave.isDeleteMemory = CameraSaveImageObj["isDeleteMemory"].toBool();
	if (CameraSaveImageObj.contains("deleteMemory")) m_CameraSave.deleteMemory = CameraSaveImageObj["deleteMemory"].toInt();
	QJsonObject RenderSaveImageObj = rootObj.value("RenderSaveImage").toObject();
	if (RenderSaveImageObj.contains("isSave")) m_RenderSave.isSave = RenderSaveImageObj["isSave"].toBool();
	if (RenderSaveImageObj.contains("ImgPathStr")) m_RenderSave.ImgPathStr = RenderSaveImageObj["ImgPathStr"].toString();
	if (RenderSaveImageObj.contains("SaveType")) m_RenderSave.SaveType = RenderSaveImageObj["SaveType"].toString();
	if (RenderSaveImageObj.contains("isDeleteNums")) m_RenderSave.isDeleteNums = RenderSaveImageObj["isDeleteNums"].toBool();
	if (RenderSaveImageObj.contains("deleteNums")) m_RenderSave.deleteNums = RenderSaveImageObj["deleteNums"].toInt();
	if (RenderSaveImageObj.contains("isDeleteDays")) m_RenderSave.isDeleteDays = RenderSaveImageObj["isDeleteDays"].toBool();
	if (RenderSaveImageObj.contains("deleteDays")) m_RenderSave.deleteDays = RenderSaveImageObj["deleteDays"].toInt();
	if (RenderSaveImageObj.contains("isDeleteMemory")) m_RenderSave.isDeleteMemory = RenderSaveImageObj["isDeleteMemory"].toBool();
	if (RenderSaveImageObj.contains("deleteMemory")) m_RenderSave.deleteMemory = RenderSaveImageObj["deleteMemory"].toInt();

	bool isShowLogo = true;
	if (rootObj.contains("ShowLogo"))  isShowLogo = rootObj.value("ShowLogo").toBool();
	QString SoftNameStr = rootObj.value("SoftName").toString();
	DynamicWidget::GetInstance()->SetLogoVisuable(isShowLogo);
	DynamicWidget::GetInstance()->SetSoftName(SoftNameStr);
	return true;
}

void ConfigProgramme::SaveConfig(QString programmeName)
{
	//待修改
	QJsonObject SaveJson;

	//各个窗口的配置信息
	QJsonArray JsonArrays;
	QJsonObject InserObj;
	InserObj.insert("ProgrammeName", QJsonValue("123"));
	QJsonArray WindowsConfigArrays;
	std::vector<WindowsConfig> m_WindowInfoVec = AllConfig;
	for (int WindowsIndex = 0; WindowsIndex < m_WindowInfoVec.size(); WindowsIndex++)
	{
		//****一个窗口配置*******
		WindowsConfig m_OneWindow = m_WindowInfoVec[WindowsIndex];
		QJsonObject InserOneWindow;

		//****模型选择配置*******
		InserOneWindow.insert("_jsonPath", QJsonValue(m_OneWindow.m_ModelChoice._jsonPath));
		InserOneWindow.insert("TypeName", QJsonValue(QString::fromLocal8Bit(m_OneWindow.m_ModelChoice.TypeName.c_str())));
		InserOneWindow.insert("_useGPU", QJsonValue(m_OneWindow.m_ModelChoice._useGPU));
		InserOneWindow.insert("_gpuID", QJsonValue(m_OneWindow.m_ModelChoice._gpuID));
		//moduleID
		{
			QJsonArray LabelArrays;
			for (int LabelIndex = 0; LabelIndex < m_OneWindow.m_ModelChoice.moduleID.size(); LabelIndex++)
			{
				LabelArrays.append(QJsonValue(QString::fromLocal8Bit(m_OneWindow.m_ModelChoice.moduleID[LabelIndex].c_str())));
			}
			InserOneWindow.insert("moduleID", LabelArrays);
		}
		//modeType的数组循环
		{
			QJsonArray LabelArrays;
			for (int LabelIndex = 0; LabelIndex < m_OneWindow.m_ModelChoice.modeType.size(); LabelIndex++)
			{
				LabelArrays.append(QJsonValue(QString::fromLocal8Bit(m_OneWindow.m_ModelChoice.modeType[LabelIndex].c_str())));
			}
			InserOneWindow.insert("modeType", LabelArrays);
		}
		//RealNameValue的数组循环
		{
			QJsonArray LabelArrays;
			for (int LabelIndex = 0; LabelIndex < m_OneWindow.m_ModelChoice.RealNameValue.size(); LabelIndex++)
			{
				LabelArrays.append(QJsonValue(QString::fromLocal8Bit(m_OneWindow.m_ModelChoice.RealNameValue[LabelIndex].c_str())));
			}
			InserOneWindow.insert("RealNameValue", LabelArrays);
		}
		//labelNames的循环
		{
			QJsonArray LabelArrays;
			for (int LabelIndex = 0; LabelIndex < m_OneWindow.m_ModelChoice.labelsNamesVec.size(); LabelIndex++)
			{
				QJsonArray LabelArrays2;
				std::vector<std::string> oneValue = m_OneWindow.m_ModelChoice.labelsNamesVec[LabelIndex];
				for (int labelIndex = 0; labelIndex < oneValue.size(); labelIndex++)
				{
					LabelArrays2.append(QJsonValue(QString::fromLocal8Bit(oneValue[labelIndex].c_str())));
				}
				LabelArrays.append(QJsonArray(LabelArrays2));
			}
			InserOneWindow.insert("labelsNamesVec", LabelArrays);
		}
		//soutionIndex的数组循环
		{
			QJsonArray LabelArrays;
			for (int LabelIndex = 0; LabelIndex < m_OneWindow.m_ModelChoice.soutionIndex.size(); LabelIndex++)
			{
				LabelArrays.append(QJsonValue(m_OneWindow.m_ModelChoice.soutionIndex[LabelIndex]));
			}
			InserOneWindow.insert("soutionIndex", LabelArrays);
		}

		//*****阈值设置配置****
		QJsonArray ThresholdArrays;
		for (int ThresholIndex = 0; ThresholIndex < m_OneWindow.m_Threshold.size(); ThresholIndex++)
		{
			AllThreshold oneThreshold = m_OneWindow.m_Threshold[ThresholIndex];
			QJsonObject InserOneThreshold;
			
			//插入分割阈值json
			QJsonObject SegJson;
			SegJson.insert("_isFilterMaxGray", oneThreshold._PostParam._segThreshold._isFilterMaxGray);
			SegJson.insert("_isFilterMinGray", oneThreshold._PostParam._segThreshold._isFilterMinGray);
			QJsonArray SegArrays;
			for (int i = 0; i < oneThreshold._PostParam._segThreshold._segThresholdVec.size(); i++)
			{
				SegThresholdVec oneSegValue = oneThreshold._PostParam._segThreshold._segThresholdVec[i];
				QJsonObject oneSegJsonValue;
				oneSegJsonValue.insert("_area", oneSegValue._area);
				oneSegJsonValue.insert("_width", oneSegValue._width);
				oneSegJsonValue.insert("_height", oneSegValue._height);
				oneSegJsonValue.insert("_minGrayValue", oneSegValue._minGrayValue);
				oneSegJsonValue.insert("_maxGrayValue", oneSegValue._maxGrayValue);
				SegArrays.append(oneSegJsonValue);
			}
			SegJson.insert("_segThresholdVec", SegArrays);
			InserOneThreshold.insert("SegThreshold", SegJson);

			//插入检测阈值json
			QJsonObject DetectionJson;
			QJsonArray detArrays;
			for (int i = 0; i < oneThreshold._PostParam._detectionThreshold._detectionThresholdVec.size(); i++)
			{
				DetectionThresholdVec oneDetValue = oneThreshold._PostParam._detectionThreshold._detectionThresholdVec[i];
				QJsonObject oneDetJsonValue;
				oneDetJsonValue.insert("_area", oneDetValue._area);
				oneDetJsonValue.insert("_width", oneDetValue._width);
				oneDetJsonValue.insert("_height", oneDetValue._height);
				oneDetJsonValue.insert("_score", oneDetValue._score);
				oneDetJsonValue.insert("_iou", oneDetValue._iou);
				detArrays.append(oneDetJsonValue);
			}
			DetectionJson.insert("_detectionThresholdVec", detArrays);
			InserOneThreshold.insert("DetectionThreshold", DetectionJson);

			//插入分类阈值json
			QJsonObject ClassJson;
			QJsonArray classArrays;
			for (int i = 0; i < oneThreshold._PostParam._classificationThreshold._classificationThresholdVec.size(); i++)
			{
				ClassificationThresholdVec oneClassValue = oneThreshold._PostParam._classificationThreshold._classificationThresholdVec[i];
				QJsonObject oneClassJsonValue;
				oneClassJsonValue.insert("_score", oneClassValue._score);
				classArrays.append(oneClassJsonValue);
			}
			ClassJson.insert("_classificationThresholdVec", classArrays);
			InserOneThreshold.insert("ClassifyThreshold", ClassJson);

			//插入OCR阈值json
			QJsonObject OCRJson;
			QJsonArray matchStrArrays,OcrThresholdSDKArray;
			for (int i = 0; i < oneThreshold._PostParam._ocrThreshold.MatchStrVec.size(); i++)
			{
				matchStrArrays.append(oneThreshold._PostParam._ocrThreshold.MatchStrVec[i]);
			}
			QJsonArray ocrThresholdArrays;
			for (int i = 0; i < oneThreshold._PostParam._ocrThreshold.SdkThreshold.size(); i++)
			{
				OcrSdkThreshold oneValue = oneThreshold._PostParam._ocrThreshold.SdkThreshold[i];
				QJsonObject oneOCRJsonValue;
				oneOCRJsonValue.insert("_score", oneValue._score);
				oneOCRJsonValue.insert("_iou", oneValue._iou);
				OcrThresholdSDKArray.append(oneOCRJsonValue);
			}
			OCRJson.insert("SortFunction", oneThreshold._PostParam._ocrThreshold.SortFunction);
			OCRJson.insert("MatchStrVec", matchStrArrays);
			OCRJson.insert("_OcrSdkThresholdVec", OcrThresholdSDKArray);
			InserOneThreshold.insert("OCRThreshold", OCRJson);

			//插入显示阈值json
			QJsonObject RenderJson,RenderValueJson;
			QJsonArray ContourThinknessArrays, ContourColorArray;
			for (int i = 0; i < oneThreshold._RenderParam._contourThickness.size(); i++)
			{
				ContourThinknessArrays.append(oneThreshold._RenderParam._contourThickness[i]);
			}
			for (int i = 0; i < oneThreshold._RenderParam._contourColor.size(); i++)
			{
				cv::Scalar oneValue = oneThreshold._RenderParam._contourColor[i];
				QJsonObject oneColorValue;
				oneColorValue.insert("R", oneValue[0]);
				oneColorValue.insert("G", oneValue[1]);
				oneColorValue.insert("B", oneValue[2]);
				ContourColorArray.append(oneColorValue);
			}
			RenderValueJson.insert("_contourThickness", ContourThinknessArrays);
			RenderValueJson.insert("_contourColor", ContourColorArray);
			InserOneThreshold.insert("RenderShowParams", RenderValueJson);

			ThresholdArrays.append(InserOneThreshold);
		}
		InserOneWindow.insert("ThresholdParams", ThresholdArrays);


		//插入时间阈值
		InserOneWindow.insert("OverTimeThreshold", m_OneWindow.m_TimeThreshold.TimeThreshold);
		InserOneWindow.insert("TimeType", m_OneWindow.m_TimeThreshold.m_TimeType);

		//****图像源****
		InserOneWindow.insert("ImageFilePath", m_OneWindow.m_ImageSourceConfig.ImageFilePath);
		InserOneWindow.insert("ImageSource_isCamera", m_OneWindow.m_ImageSourceConfig.ImageSource_isCamera);


		//****相机配置信息****
		InserOneWindow.insert("isOpenCamera", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.isGrabbing);
		InserOneWindow.insert("exposure", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.exposure);
		InserOneWindow.insert("gain", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.gain);
		InserOneWindow.insert("name", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.name);
		InserOneWindow.insert("triggerMode", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.triggerMode);
		InserOneWindow.insert("triggerSource", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.triggerSource);
		InserOneWindow.insert("SoftTrigerCommunication", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.SoftTrigerCommunication);
		InserOneWindow.insert("SoftTrigerStr", m_OneWindow.m_ImageSourceConfig.m_CameraInfo.GrabStr);

		//++++当前窗口信息压入队列++++
		WindowsConfigArrays.push_back(InserOneWindow);
	}
	InserObj.insert("WindowsConfigArrays", WindowsConfigArrays);
	JsonArrays.append(InserObj);
	SaveJson.insert("ProgrammeCongigVec", JsonArrays);


	//通信模块的配置信息
	QJsonArray CommunicationArrays;
	QMap<QString, CommunicateBase*>::const_iterator iterator_1 = m_Comunicate.constBegin();
	while (iterator_1 != m_Comunicate.constEnd())
	{
		QJsonObject InserOneCommunication;
		InserOneCommunication.insert("CommunicationName", QJsonValue(iterator_1.key()));
		InserOneCommunication.insert("CommunicationType", QJsonValue(iterator_1.value()->GetCommunicationType()));
		InserOneCommunication.insert("Config", iterator_1.value()->GetConfigJson());
		CommunicationArrays.push_back(InserOneCommunication);
		++iterator_1;
	}
	SaveJson.insert("ComunicationConfig", CommunicationArrays);

	//存图模块的配置信息
	QJsonObject CameraSaveImageObj;
	CameraSaveImageObj.insert("isSave", m_CameraSave.isSave);
	CameraSaveImageObj.insert("ImgPathStr", m_CameraSave.ImgPathStr);
	CameraSaveImageObj.insert("SaveType", m_CameraSave.SaveType);
	CameraSaveImageObj.insert("isDeleteNums", m_CameraSave.isDeleteNums);
	CameraSaveImageObj.insert("deleteNums", m_CameraSave.deleteNums);
	CameraSaveImageObj.insert("isDeleteDays", m_CameraSave.isDeleteDays);
	CameraSaveImageObj.insert("deleteDays", m_CameraSave.deleteDays);
	CameraSaveImageObj.insert("isDeleteMemory", m_CameraSave.isDeleteMemory);
	CameraSaveImageObj.insert("deleteMemory", m_CameraSave.deleteMemory);
	SaveJson.insert("CameraSaveImage", CameraSaveImageObj);
	QJsonObject RenderSaveImageObj;
	RenderSaveImageObj.insert("isSave", m_RenderSave.isSave);
	RenderSaveImageObj.insert("ImgPathStr", m_RenderSave.ImgPathStr);
	RenderSaveImageObj.insert("SaveType", m_RenderSave.SaveType);
	RenderSaveImageObj.insert("isDeleteNums", m_RenderSave.isDeleteNums);
	RenderSaveImageObj.insert("deleteNums", m_RenderSave.deleteNums);
	RenderSaveImageObj.insert("isDeleteDays", m_RenderSave.isDeleteDays);
	RenderSaveImageObj.insert("deleteDays", m_RenderSave.deleteDays);
	RenderSaveImageObj.insert("isDeleteMemory", m_RenderSave.isDeleteMemory);
	RenderSaveImageObj.insert("deleteMemory", m_RenderSave.deleteMemory);
	SaveJson.insert("RenderSaveImage", RenderSaveImageObj);

	SaveJson.insert("ShowLogo", DynamicWidget::GetInstance()->GetLogoVisuable());
	SaveJson.insert("SoftName", DynamicWidget::GetInstance()->GetSoftName());

	DirExistEx(".//config//programme");
	QFile file(".//config//programme//" + programmeName + ".json");
	//if (file.exists() && QMessageBox::Yes != QMessageBox::question(nullptr, tr("请确认"), tr("文件已存在，是否覆盖?"))) return;
	QJsonDocument jsonDoc;
	jsonDoc.setObject(SaveJson);
	QByteArray data = jsonDoc.toJson();
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);
	file.write(data);
	file.close();
}

QString ConfigProgramme::LoadWhichPro()
{
	//提取选择的是哪个方案
	QFile fileWhitchPro(".//config//programme//WhichProgramme.json");
	if (!fileWhitchPro.exists()) return false;
	fileWhitchPro.open(QIODevice::ReadOnly);
	auto dataWhitchPro = fileWhitchPro.readAll();
	fileWhitchPro.close();
	QJsonParseError jErrorWhitchPro;	//创建QJsonParseError对象
	QJsonDocument jsonDocWhitchPro = QJsonDocument::fromJson(dataWhitchPro, &jErrorWhitchPro);
	if (jErrorWhitchPro.error != QJsonParseError::NoError) return false;
	QJsonObject rootObjWhitchPro = jsonDocWhitchPro.object();
	QJsonValue valueArrayTypes = rootObjWhitchPro.value("ProgrammeName");

	return valueArrayTypes.toString();
}

void ConfigProgramme::SaveWhichPro(QString inSaveProgramme)
{
	QJsonObject SaveJsonWhichPro;
	SaveJsonWhichPro.insert("ProgrammeName", inSaveProgramme);
	QFile fileWhich(".//config//programme//WhichProgramme.json");
	QJsonDocument jsonDocWhich;
	jsonDocWhich.setObject(SaveJsonWhichPro);
	QByteArray dataWhich = jsonDocWhich.toJson();
	fileWhich.open(QIODevice::WriteOnly | QIODevice::Truncate);
	fileWhich.write(dataWhich);
	fileWhich.close();
}

bool ConfigProgramme::DirExistEx(QString fullPath)
{
	QDir dir(fullPath);
	if (dir.exists())
	{
		return true;
	}
	else
	{
		//不存在当前目录，创建，可创建多级目录
		bool ok = dir.mkpath(fullPath);
		return ok;
	}
}

std::vector<QString> ConfigProgramme::LoadModelName(QString programmeName)
{
	std::vector<QString> m_returnVec;
	//通过名字加载的方案
	QFile file(programmeName);
	if (!file.exists()) return m_returnVec;
	file.open(QIODevice::ReadOnly);
	auto data = file.readAll();
	file.close();
	QJsonParseError jError;	//创建QJsonParseError对象
	QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &jError);
	if (jError.error != QJsonParseError::NoError) return m_returnVec;

	QJsonObject rootObj = jsonDoc.object();
	QJsonValue valueArrayTypes = rootObj.value("ProgrammeCongigVec");
	QJsonArray ProgrammeArray = valueArrayTypes.toArray();
	for (int i = 0; i < ProgrammeArray.size(); i++)
	{

		QJsonValue ProgrammeValue = ProgrammeArray[i];
		QJsonObject  childObject = ProgrammeValue.toObject();
		//****当前配置方案名****
		std::string ProgrammeName = childObject.value("ProgrammeName").toString().toStdString();

		//qDebug() << childObject.value("WindowsConfigArrays");
		//qDebug() << childObject.value("WindowsConfigArrays").toString();

		//****当前方案具体配置信息数组****
		std::vector<WindowsConfig> Programme_Info;
		QJsonValue valueWindowsArray = childObject.value("WindowsConfigArrays");
		QJsonArray ProgrammeConfigInfo = valueWindowsArray.toArray();
		for (int windowIndex = 0; windowIndex < ProgrammeConfigInfo.count(); windowIndex++)
		{
			WindowsConfig OneWindowConfig;

			QJsonValue WindowValue = ProgrammeConfigInfo[windowIndex];
			QJsonObject  childObject_Window = WindowValue.toObject();

			QJsonArray realNameArrays = childObject_Window["RealNameValue"].toArray();

			QString  RealNameValue = realNameArrays[realNameArrays.size() - 1].toString();
			m_returnVec.push_back(RealNameValue);
		}
	}
	return m_returnVec;
}

void ConfigProgramme::deleteWindow(int windowIndex)
{
	if (AllConfig.size() < windowIndex) return;
	auto iter = AllConfig.erase(AllConfig.begin() + windowIndex - 1);
}

string ConfigProgramme::EnumToString(SdkModelType inType)
{
	switch (inType)
	{
	case Classification:
		return "classification";
	case Segmentation:
		return "segmentation";
	case Detection:
		return "detection";
	case OCR:
		return "ocr";
	}
	return "error";
}

SdkModelType ConfigProgramme::StringToEnum(string inStr)
{
	if (inStr == "segmentation")
		return Segmentation;
	else if (inStr == "detection")
		return Detection;
	else if (inStr == "classification")
		return Classification;
	else if (inStr == "ocr")
		return OCR;
	return Segmentation;
}