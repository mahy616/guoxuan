#include "ViMoAlgoClassification.h"
#include <qDebug>

ViMoAlgoClassification::~ViMoAlgoClassification()
{
	m_ClassificationModel.~ClassificationModule();
}

bool ViMoAlgoClassification::InintAlgo(ModelConfig inConfig)
{
	try
	{
		QByteArray cdata = inConfig._jsonPath.toLocal8Bit();
		m_Solution.LoadFromFile(string(cdata));
		m_ClassificationModel = m_Solution.CreateModule<smartmore::vimo::ClassificationModule>(inConfig._moduleID.toStdString(), inConfig._useGPU, inConfig._gpuID);
		m_LableNames = inConfig._labelName;
		//待修改
		m_TimeType = OnlyViMo;
		m_RenderShow._contourColor = { cv::Scalar(255, 255, 0),cv::Scalar(255, 0, 0) ,cv::Scalar(0, 255, 0) ,cv::Scalar(255, 0, 255) ,cv::Scalar(0, 255, 255) ,cv::Scalar(0, 0, 255),cv::Scalar(30, 150, 215) ,cv::Scalar(230, 20, 115)  ,cv::Scalar(44, 20, 215)  ,cv::Scalar(130, 210, 3) ,cv::Scalar(230, 20, 115) ,cv::Scalar(130, 220, 35)  ,cv::Scalar(55, 220, 35) ,cv::Scalar(230, 11, 55)  ,cv::Scalar(52, 72, 115) };
		m_RenderShow._contourThickness = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
		m_ClassificationThreshold._classificationThresholdVec.resize(inConfig._labelName.size());

		//初始化成功后求默认阈值
		m_ClassificationThreshold._classificationThresholdVec.resize(inConfig._labelName.size());
		auto params = m_ClassificationModel.GetParams();
		for (auto &kv : params.score_thresholds)
		{
			for (int i = 0; i <= inConfig._labelName.size(); i++)
			{
				if (kv.first == inConfig._labelName[i])
				{
					m_ClassificationThreshold._classificationThresholdVec[i]._score = kv.second;
					break;
				}
			}
		}

		//默认推理一张图
		smartmore::vimo::Request req_1{ cv::Mat::zeros(500,500,CV_8UC1) };
		smartmore::vimo::ClassificationResponse rsp_1;
		m_ClassificationModel.Run(req_1, rsp_1);
		return true;
	}
	catch (smartmore::vimo::VimoException &e)
	{
		return false;
	}
}

bool ViMoAlgoClassification::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk)
{
	try
	{
		bool resultState = true;
		//算法运行
		auto algoStart = std::chrono::high_resolution_clock::now();
		smartmore::vimo::ClassificationResponse rsp_1;
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };		
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_ClassificationModel.GetInfo().default_shifting, m_ClassificationModel.GetInfo().default_padding);
			m_ClassificationModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage, inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_ClassificationModel.GetInfo().default_shifting, m_ClassificationModel.GetInfo().default_padding);
			m_ClassificationModel.Run(req_1, rsp_1);
		}		
		auto algoEnd = std::chrono::high_resolution_clock::now();

		//后处理
		QString ResultStr =QString::fromLocal8Bit(ClassifyPostProcessing(rsp_1, inputImage, outRenderImage, inROI).c_str());
		if (ResultStr == "Score is ignored" || ResultStr == "OK")
			resultState = true;
		else
			resultState = false;
		outResultJson = outResultJson + ResultStr + ",";
		auto HouEnd = std::chrono::high_resolution_clock::now();

		outIsOk = outIsOk && resultState;

		if (m_TimeType == OnlyViMo)
			outMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(algoEnd - algoStart).count();
		if (m_TimeType == OnlyPostProcess)
			outMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(HouEnd - algoEnd).count();
		if (m_TimeType == ViMoAndPostProcess)
			outMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(HouEnd - algoStart).count();
		return true;
	}
	catch (smartmore::vimo::VimoException &e)
	{
		return false;
	}
}

void ViMoAlgoClassification::SetThresholdParam(ThresholdParams inParam)
{
	m_ClassificationThreshold = inParam._classificationThreshold;
	m_TimeType = inParam._timeType;

	//SDK后处理阈值：分数与iou接口 (分数接口可以单独对每个标签设置，iou只能对所有标签共同设置)
	auto params = m_ClassificationModel.GetParams();
	//设置分数阈值
	for (auto &kv : params.score_thresholds)
	{
		for (int i = 0; i < m_ClassificationThreshold._classificationThresholdVec.size(); i++)
		{
			if (kv.first == m_LableNames[i])
			{
				kv.second = m_ClassificationThreshold._classificationThresholdVec[i]._score;
			}
		}
		std::cout << "score threshold: " << kv.first << ": " << kv.second;
	}
	//调用接口设置生效
	m_ClassificationModel.SetParams(params);
}

std::string ViMoAlgoClassification::ClassifyPostProcessing(smartmore::vimo::ClassificationResponse rsp, cv::Mat inImg, cv::Mat &RenderImage, cv::Rect targetRegion)
{
	if (RenderImage.channels() == 1)
		cv::cvtColor(RenderImage, RenderImage, cv::COLOR_GRAY2BGR);
	float MaxScore = -1; std::string returnStr;

	for (const auto &l : rsp.labels)
	{
		std::cout << "label name: " << l.label << "[" << l.id << "]: " << l.score << std::endl;
		std::string NowName = l.label;
		if (l.score < m_ClassificationThreshold._classificationThresholdVec[l.id-1]._score)
		{
			qDebug() << "置信度被过滤";
			continue;
		}
		else
		{
			if (l.score > MaxScore)
			{
				MaxScore = l.score;
				returnStr = NowName;
			}
		}
	}

	char DrawTextWord[150];
	sprintf_s(DrawTextWord, "推理结果：%s,置信度：%0.3f", returnStr.c_str(), MaxScore);
	cv::Point drawPoint(targetRegion.x, targetRegion.y);
	if (targetRegion.x == 0)
		drawPoint.x = targetRegion.width / 12;
	if (targetRegion.y == 0)
		drawPoint.y = targetRegion.height / 12;

	if (MaxScore == -1)
	{
		sprintf_s(DrawTextWord, "OK");
		returnStr = "OK";
		PutTextChinese(RenderImage, tr("OK"), drawPoint, targetRegion.width / 40, cv::Scalar(0, 255, 0));
	}
	else
	{
		if (returnStr == "OK")
			PutTextChinese(RenderImage, tr("OK"), drawPoint, targetRegion.width / 40, cv::Scalar(0, 255, 0));
		else
			PutTextChinese(RenderImage, QString::fromLocal8Bit(DrawTextWord), drawPoint, targetRegion.width / 40,cv::Scalar(0, 0, 255));
	}

	return returnStr;
}

AllThreshold ViMoAlgoClassification::GetThresholdValue()
{
	ThresholdParams returnParam;
	returnParam._classificationThreshold = m_ClassificationThreshold;
	AllThreshold returnAllValue;
	returnAllValue._PostParam = returnParam;
	returnAllValue._RenderParam = m_RenderShow;
	return returnAllValue;
}

ViMoModelInfo ViMoAlgoClassification::GetModelInfos()
{
	ViMoModelInfo returnInfo;
	returnInfo.id = m_ClassificationModel.GetInfo().id;
	returnInfo.features = m_ClassificationModel.GetInfo().features;
	returnInfo.model_version = m_ClassificationModel.GetInfo().model_version;
	returnInfo.default_shifting = m_ClassificationModel.GetInfo().default_shifting;
	returnInfo.default_padding = m_ClassificationModel.GetInfo().default_padding;
	return returnInfo;
}