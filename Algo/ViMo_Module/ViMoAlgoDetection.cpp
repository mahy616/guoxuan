#include "ViMoAlgoDetection.h"
#include <qDebug>
#include <QMessageBox>

ViMoAlgoDetection::~ViMoAlgoDetection()
{
	m_DetectionModel.~DetectionModule();
}

bool ViMoAlgoDetection::InintAlgo(ModelConfig inConfig)
{
	try
	{
		QByteArray cdata = inConfig._jsonPath.toLocal8Bit();
		m_Solution.LoadFromFile(string(cdata));

		m_DetectionModel = m_Solution.CreateModule<smartmore::vimo::DetectionModule>(string(inConfig._moduleID.toLocal8Bit()), inConfig._useGPU, inConfig._gpuID);
		m_LableNames = inConfig._labelName;
		//���޸�
		m_TimeType = OnlyViMo;
		m_RenderShow._contourColor = { cv::Scalar(255, 255, 0),cv::Scalar(255, 0, 0) ,cv::Scalar(0, 255, 0) ,cv::Scalar(255, 0, 255) ,cv::Scalar(0, 255, 255) ,cv::Scalar(0, 0, 255),cv::Scalar(30, 150, 215) ,cv::Scalar(230, 20, 115)  ,cv::Scalar(44, 20, 215)  ,cv::Scalar(130, 210, 3) ,cv::Scalar(230, 20, 115) ,cv::Scalar(130, 220, 35)  ,cv::Scalar(55, 220, 35) ,cv::Scalar(230, 11, 55)  ,cv::Scalar(52, 72, 115) };
		m_RenderShow._contourThickness = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
		m_DetectionThreshold._detectionThresholdVec.resize(inConfig._labelName.size());

		//��ʼ���ɹ�����Ĭ����ֵ
		m_DetectionThreshold._detectionThresholdVec.resize(inConfig._labelName.size());
		auto params = m_DetectionModel.GetParams();
		for (auto &kv : params.score_thresholds)
		{
			for (int i = 0; i <= inConfig._labelName.size(); i++)
			{
				m_DetectionThreshold._detectionThresholdVec[i]._iou = params.iou_threshold;
				if (kv.first == inConfig._labelName[i])
				{
					m_DetectionThreshold._detectionThresholdVec[i]._score = kv.second;
					break;
				}				
			}
		}

		//Ĭ������һ��ͼ
		smartmore::vimo::Request req_1{ cv::Mat::zeros(500,500,CV_8UC1) };
		m_DetectionModel.Run(req_1, rsp_1);

		return true;
	}
	catch (smartmore::vimo::VimoException &e)
	{
		string a = e.what();
		//QMessageBox::information(nullptr, tr("Tips"), tr("%1δ��ʼ���ɹ�,����Tips:%2").arg(inConfig.RealNameValue.c_str()).arg(e.what()));
		return false;
	}
}

bool ViMoAlgoDetection::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk)
{
	try
	{
		bool resultState = true;
		//�㷨����
		auto algoStart = std::chrono::high_resolution_clock::now();
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_DetectionModel.GetInfo().default_shifting, m_DetectionModel.GetInfo().default_padding);
			m_DetectionModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage,inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_DetectionModel.GetInfo().default_shifting, m_DetectionModel.GetInfo().default_padding);
			m_DetectionModel.Run(req_1, rsp_1);
		}
		auto algoEnd = std::chrono::high_resolution_clock::now();
		//����
		memset(DefectFlag, false, sizeof(DefectFlag));
		if (rsp_1.boxes.size() >= 1)
		{
			if (DectionPostProcessing(rsp_1, inputImage, outRenderImage) == 0)
			{
				outResultJson = outResultJson + "OK" + ",";
				resultState = true;
			}
			else
			{
				resultState = false;
				outResultJson = outResultJson + GenSegText(outRenderImage);
			}
		}
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
		//QMessageBox::information(nullptr, tr("Tips"), tr("���ģ������ʧ��,����Tips:%2").arg(e.what()));
		return false;
	}
}

bool ViMoAlgoDetection::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds)
{
	try
	{
		//�㷨����
		auto algoStart = std::chrono::high_resolution_clock::now();
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_DetectionModel.GetInfo().default_shifting, m_DetectionModel.GetInfo().default_padding);
			m_DetectionModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage, inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_DetectionModel.GetInfo().default_shifting, m_DetectionModel.GetInfo().default_padding);
			m_DetectionModel.Run(req_1, rsp_1);
		}
		auto algoEnd = std::chrono::high_resolution_clock::now();

		//����
		//������Ⱦͼ
		if (outRenderImage.channels() == 1)
			cv::cvtColor(inputImage, outRenderImage, cv::COLOR_GRAY2BGR);
		//����-����
		if (rsp_1.boxes.size() >= 1)
		{
			std::vector<std::pair<std::string, cv::Rect>> tempROI = ConvertResponseToBoundingBox(rsp_1);
			for (int j = 0; j < tempROI.size(); j++)
			{
				int Label_ID = -1;
				for (int labelIndex = 0; labelIndex < m_LableNames.size(); labelIndex++)
				{
					if (m_LableNames[labelIndex] == tempROI[j].first)
					{
						Label_ID = labelIndex;
						break;
					}
				}
				if (Label_ID != -1)
				{
					if (tempROI[j].second.width < m_DetectionThreshold._detectionThresholdVec[Label_ID]._width)
					{
						qDebug() << "��ȱ�����";
						continue;
					}
					if (tempROI[j].second.height < m_DetectionThreshold._detectionThresholdVec[Label_ID]._height)
					{
						qDebug() << "�߶ȱ�����";
						continue;
					}
					if (tempROI[j].second.width * tempROI[j].second.height < m_DetectionThreshold._detectionThresholdVec[Label_ID]._area)
					{
						qDebug() << "���������";
						continue;
					}
					cv::rectangle(outRenderImage, tempROI[j].second, m_RenderShow._contourColor[Label_ID], m_RenderShow._contourThickness[Label_ID]);
					outROI.push_back(tempROI[j]);
				}
			}
		}

		/*for (size_t i = 0; i < rsp_1.boxes.size(); ++i)
		{
			int width = (rsp_1.boxes[i].bounding_box[2].x - rsp_1.boxes[i].bounding_box[0].x);
			int height = (rsp_1.boxes[i].bounding_box[2].y - rsp_1.boxes[i].bounding_box[0].y);
			if (width < m_DetectionThreshold._detectionThresholdVec[rsp_1.boxes[i].id - 1]._width)
			{
				qDebug() << "��ȱ�����";
				continue;
			}
			if (height < m_DetectionThreshold._detectionThresholdVec[rsp_1.boxes[i].id - 1]._height)
			{
				qDebug() << "�߶ȱ�����";
				continue;
			}
			if ((rsp_1.boxes[i].score) < m_DetectionThreshold._detectionThresholdVec[rsp_1.boxes[i].id - 1]._score)
			{
				qDebug() << "���Ŷȱ�����";
				continue;
			}
			if ((rsp_1.boxes[i].bounding_box[2].x - rsp_1.boxes[i].bounding_box[0].x)*(rsp_1.boxes[i].bounding_box[2].y - rsp_1.boxes[i].bounding_box[0].y) < m_DetectionThreshold._detectionThresholdVec[rsp_1.boxes[i].id - 1]._area)
			{
				qDebug() << "���������";
				continue;
			}
			cv::rectangle(outRenderImage, rsp_1.boxes[i].bounding_box[0], rsp_1.boxes[i].bounding_box[2], m_RenderShow._contourColor[rsp_1.boxes[i].id - 1], m_RenderShow._contourThickness[rsp_1.boxes[i].id - 1]);
			
			std::pair<std::string, cv::Rect> oneROI;
			oneROI.first = rsp_1.boxes[i].label;
			oneROI.second = cv::Rect(rsp_1.boxes[i].bounding_box[0].x, rsp_1.boxes[i].bounding_box[0].y, width, height);
			outROI.push_back(oneROI);
		}*/

		auto HouEnd = std::chrono::high_resolution_clock::now();

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
		//QMessageBox::information(nullptr, tr("Tips"), tr("���ģ������ʧ��,����Tips:%2").arg(e.what()));
		return false;
	}
}

void ViMoAlgoDetection::SetThresholdParam(ThresholdParams inParam)
{
	m_DetectionThreshold = inParam._detectionThreshold; 
	m_TimeType = inParam._timeType;

	//SDK������ֵ��������iou�ӿ� (�����ӿڿ��Ե�����ÿ����ǩ���ã�iouֻ�ܶ����б�ǩ��ͬ����)
	auto params = m_DetectionModel.GetParams();

	//����iou��ֵ
	params.iou_threshold = m_DetectionThreshold._detectionThresholdVec[0]._iou;
	//���÷�����ֵ
	for (auto &kv : params.score_thresholds)
	{
		for (int i = 0; i < m_DetectionThreshold._detectionThresholdVec.size(); i++)
		{
			if (kv.first == m_LableNames[i])
			{
				kv.second = m_DetectionThreshold._detectionThresholdVec[i]._score;
			}
		}
		std::cout << "score threshold: " << kv.first << ": " << kv.second;
	}
	//���ýӿ�������Ч
	m_DetectionModel.SetParams(params);

	//����鿴���ú����ֵ
	for (auto &kv : params.score_thresholds) //�鿴���õķ�����ֵ
	{
		std::cout << "score threshold: " << kv.first << ": " << kv.second << std::endl;
	}
	std::cout << "iou threshold: " << params.iou_threshold << std::endl;
}

int ViMoAlgoDetection::DectionPostProcessing(smartmore::vimo::DetectionResponse rsp, cv::Mat inImg, cv::Mat &RenderImage)
{
	if (RenderImage.channels() == 1)
	{
		cout << RenderImage.data << std::endl;
		cv::Mat colorImage;
		cv::cvtColor(RenderImage, colorImage, cv::COLOR_GRAY2BGR);
		RenderImage = colorImage;
		cout << RenderImage.data << std::endl;
	}

	int RectNums = 0;
	for (size_t i = 0; i < rsp.boxes.size(); ++i)
	{
		if ((rsp.boxes[i].bounding_box[2].x - rsp.boxes[i].bounding_box[0].x) < m_DetectionThreshold._detectionThresholdVec[rsp.boxes[i].id - 1]._width)
		{
			qDebug() << "��ȱ�����";
			continue;
		}
		if ((rsp.boxes[i].bounding_box[2].y - rsp.boxes[i].bounding_box[0].y) < m_DetectionThreshold._detectionThresholdVec[rsp.boxes[i].id - 1]._height)
		{
			qDebug() << "�߶ȱ�����";
			continue;
		}
		if ((rsp.boxes[i].score) < m_DetectionThreshold._detectionThresholdVec[rsp.boxes[i].id - 1]._score)
		{
			qDebug() << "���Ŷȱ�����";
			continue;
		}
		if ((rsp.boxes[i].bounding_box[2].x - rsp.boxes[i].bounding_box[0].x)*(rsp.boxes[i].bounding_box[2].y - rsp.boxes[i].bounding_box[0].y) < m_DetectionThreshold._detectionThresholdVec[rsp.boxes[i].id - 1]._area)
		{
			qDebug() << "���������";
			continue;
		}

		DefectFlag[rsp.boxes[i].id - 1] = true;
		//int WordRows = (rsp.boxes[i].bounding_box[0].y - (rsp.boxes[i].bounding_box[2].y - rsp.boxes[i].bounding_box[0].y) / 4) >= 10 ? (rsp.boxes[i].bounding_box[0].y - (rsp.boxes[i].bounding_box[2].y - rsp.boxes[i].bounding_box[0].y) / 4) : 10;
		cv::Point WordPoint(rsp.boxes[i].bounding_box[0].x, rsp.boxes[i].bounding_box[0].y);
		char DrawTextWord[150];
		sprintf_s(DrawTextWord, "%s:%0.3f", rsp.boxes[i].label.c_str(), rsp.boxes[i].score);
		
		int xx1 = (rsp.boxes[i].bounding_box[1].x - rsp.boxes[i].bounding_box[0].x);
		int xx2 = (rsp.boxes[i].bounding_box[3].y - rsp.boxes[i].bounding_box[1].y);
		//float wordSize = (rsp.boxes[i].bounding_box[1].x - rsp.boxes[i].bounding_box[0].x)*(rsp.boxes[i].bounding_box[3].y - rsp.boxes[i].bounding_box[1].y)*0.0006;

		PutTextChinese(RenderImage, QString::fromLocal8Bit(DrawTextWord), WordPoint, RenderImage.cols / 90, m_RenderShow._contourColor[rsp.boxes[i].id - 1]);
		cv::rectangle(RenderImage, rsp.boxes[i].bounding_box[0], rsp.boxes[i].bounding_box[2], m_RenderShow._contourColor[rsp.boxes[i].id - 1], m_RenderShow._contourThickness[rsp.boxes[i].id - 1]);

		RectNums++;
	}

	std::cout << "������" << std::endl;
	return RectNums;
}

QString ViMoAlgoDetection::GenSegText(cv::Mat &RenderImage)
{
	QString returnStr;
	for (int i = 0; i < m_LableNames.size(); i++)
	{
		if (DefectFlag[i])
		{
			returnStr = returnStr + QString::fromLocal8Bit(m_LableNames[i].c_str()) + tr(",");
		}
	}
	if (returnStr.size() == 0)
	{
		returnStr = "-";
	}
	//PutTextChinese(RenderImage, returnStr, Scalar(0, 0, 255), 50);
	//putTextZH(RenderImage, returnStr.toLocal8Bit().toStdString().c_str()/*tempString.toLocal8Bit().toStdString().c_str()*/, cv::Point(RenderImage.cols / 12, RenderImage.rows / 12), cv::Scalar(0, 0, 255), RenderImage.cols / 30);
	return returnStr;
}

AllThreshold ViMoAlgoDetection::GetThresholdValue()
{
	ThresholdParams returnParam;
	returnParam._detectionThreshold = m_DetectionThreshold;
	AllThreshold returnAllValue;
	returnAllValue._PostParam = returnParam;
	returnAllValue._RenderParam = m_RenderShow;
	return returnAllValue;
}

ViMoModelInfo ViMoAlgoDetection::GetModelInfos()
{
	ViMoModelInfo returnInfo;
	returnInfo.id = m_DetectionModel.GetInfo().id;
	returnInfo.features = m_DetectionModel.GetInfo().features;
	returnInfo.model_version = m_DetectionModel.GetInfo().model_version;
	returnInfo.default_shifting = m_DetectionModel.GetInfo().default_shifting;
	returnInfo.default_padding = m_DetectionModel.GetInfo().default_padding;
	return returnInfo;
}