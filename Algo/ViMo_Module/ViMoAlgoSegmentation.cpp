#include "ViMoAlgoSegmentation.h"
#include <qDebug>
#include <QMessageBox>

ViMoAlgoSegmentation::~ViMoAlgoSegmentation()
{
	m_SegModel.~SegmentationModule();
}

bool ViMoAlgoSegmentation::InintAlgo(ModelConfig inConfig)
{
	try
	{
		QByteArray cdata = inConfig._jsonPath.toLocal8Bit();
		m_Solution.LoadFromFile(string(cdata));
		m_SegModel = m_Solution.CreateModule<smartmore::vimo::SegmentationModule>(inConfig._moduleID.toStdString(), inConfig._useGPU, inConfig._gpuID);
		m_LableNames = inConfig._labelName;
		//���޸�
		m_TimeType = OnlyViMo;
		m_RenderShow._contourColor = { cv::Scalar(255, 255, 0),cv::Scalar(255, 0, 0) ,cv::Scalar(0, 255, 0) ,cv::Scalar(255, 0, 255) ,cv::Scalar(0, 255, 255) ,cv::Scalar(0, 0, 255),cv::Scalar(30, 150, 215) ,cv::Scalar(230, 20, 115)  ,cv::Scalar(44, 20, 215)  ,cv::Scalar(130, 210, 3) ,cv::Scalar(230, 20, 115) ,cv::Scalar(130, 220, 35)  ,cv::Scalar(55, 220, 35) ,cv::Scalar(230, 11, 55)  ,cv::Scalar(52, 72, 115) };
		m_RenderShow._contourThickness = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
		m_SegThreshold._segThresholdVec.resize(inConfig._labelName.size());

		////��ʼ���ɹ�����Ĭ����ֵ
		//m_SegThreshold._segThresholdVec.resize(inConfig._labelName.size());
		//auto params = m_SegModel.GetParams();
		//for (auto &kv : params.score_thresholds)
		//{
		//	for (int i = 0; i <= inConfig._labelName.size(); i++)
		//	{
		//		m_OCRThreshold.SdkThreshold[i]._iou = params.iou_threshold;
		//		if (kv.first == inConfig._labelName[i])
		//		{
		//			m_OCRThreshold.SdkThreshold[i]._score = kv.second;
		//			break;
		//		}
		//	}
		//}

		////Lutӳ���
		//uchar lutTable[256 * 3];
		//memset(lutTable, 0, sizeof(lutTable));
		//for (int i = 0; i < 256; i++)
		//{
		//	if (i == 0)
		//	{
		//		lutTable[(i) * 3] = 0;
		//		lutTable[(i) * 3 + 1] = 0;
		//		lutTable[(i) * 3 + 2] = 0;
		//	}
		//	if (i <= m_RenderShow._contourColor.size())
		//	{
		//		cv::Scalar m_Color = m_RenderShow._contourColor[i];
		//		lutTable[(i) * 3] = m_Color[0];
		//		lutTable[(i) * 3 + 1] = m_Color[1];
		//		lutTable[(i) * 3 + 2] = m_Color[2];
		//	}
		//	if (i > m_RenderShow._contourColor.size())
		//	{
		//		lutTable[(i) * 3] = 0;
		//		lutTable[(i) * 3 + 1] = 0;
		//		lutTable[(i) * 3 + 2] = 0;
		//	}
		//}
		//Lut_Image = cv::Mat(1, 256, CV_8UC3, lutTable);

		//Ĭ������һ��ͼ
		smartmore::vimo::Request req_1{ cv::Mat::zeros(500,500,CV_8UC1) };
		m_SegModel.Run(req_1, rsp_1);
		return true;
	}
	catch (smartmore::vimo::VimoException &e)
	{
		//QMessageBox::information(nullptr, tr("Tips"), tr("%1δ��ʼ���ɹ�,����Tips:%2").arg(inConfig.RealNameValue.c_str()).arg(e.what()));
		return false;
	}
}

bool ViMoAlgoSegmentation::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk)
{
	try
	{
		bool resultState = true;
		//�㷨����
		auto algoStart = std::chrono::high_resolution_clock::now();
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_SegModel.GetInfo().default_shifting, m_SegModel.GetInfo().default_padding);
			m_SegModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage ,inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_SegModel.GetInfo().default_shifting, m_SegModel.GetInfo().default_padding);
			m_SegModel.Run(req_1, rsp_1);
		}
		auto algoEnd = std::chrono::high_resolution_clock::now();

		//����
		memset(DefectFlag, false, sizeof(DefectFlag));
		if (rsp_1.label_map.size() >= 1)
		{
			/*if (inROI.width != 0 && inROI.height != 0)
			{
				inputImage = inputImage(inROI);
				rsp_1.mask = rsp_1.mask(inROI);
				outRenderImage = outRenderImage(inROI);
			}*/

			//����ֵ���湴ѡ�˻Ҷ�ֵ���ˣ�������Լ�д�ĺ�������ʹ��SDK�Ĺ��˽ӿ�
			if (1/*m_SegThreshold._isFilterMaxGray == true || m_SegThreshold._isFilterMinGray == true*/)
			{
				GrayValueFilter(inputImage, rsp_1.mask);
				resultState = PostProcessing(rsp_1.mask, outRenderImage);
			}
			else
			{
				resultState = false;
				DrawRender(inputImage, rsp_1, outRenderImage); //roi���ӻ�
			}
		}
		else
			resultState = true; //��������
		if (resultState == false)
			outResultJson = outResultJson + GenSegText(outRenderImage, inROI);
		else
			outResultJson = outResultJson + "OK" + ",";
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
		QMessageBox::information(nullptr, tr("Tips"), tr("Failed to run pipeline, warning:%2").arg(e.what()));
		return false;
	}
}

bool ViMoAlgoSegmentation::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds)
{
	try
	{
		//�㷨����
		auto algoStart = std::chrono::high_resolution_clock::now();
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_SegModel.GetInfo().default_shifting, m_SegModel.GetInfo().default_padding);
			m_SegModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage,inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_SegModel.GetInfo().default_shifting, m_SegModel.GetInfo().default_padding);
			m_SegModel.Run(req_1, rsp_1);
		}
		auto algoEnd = std::chrono::high_resolution_clock::now();

		//����
		if (rsp_1.label_map.size() >= 1)
		{
			outROI = ConvertResponseToBoundingBox(rsp_1);
			//������Ⱦͼ
			if (outRenderImage.channels() == 1)
				cv::cvtColor(inputImage, outRenderImage, cv::COLOR_GRAY2BGR);

			for (int i = 0; i < outROI.size(); i++)
			{
				int Label_ID = -1;
				for (int labelIndex = 0; labelIndex < m_LableNames.size(); labelIndex++)
				{
					if (m_LableNames[labelIndex] == outROI[i].first)
					{
						Label_ID = labelIndex;
						break;
					}
				}
				if (Label_ID != -1)
				{
					//�������Ĺ���
					if (outROI[i].second.area() < m_SegThreshold._segThresholdVec[Label_ID]._area) //����
					{
						outROI.erase(outROI.begin() + i); //ɾ�������˵�ROI
						qDebug() << "ǰ��ģ���������";
						continue;
					}
					if (outROI[i].second.width < m_SegThreshold._segThresholdVec[Label_ID]._width) //����
					{
						outROI.erase(outROI.begin() + i); //ɾ�������˵�ROI
						qDebug() << "ǰ��ģ���ȹ���";
						continue;
					}
					if (outROI[i].second.height < m_SegThreshold._segThresholdVec[Label_ID]._height) //����
					{
						outROI.erase(outROI.begin() + i); //ɾ�������˵�ROI
						qDebug() << "ǰ��ģ��߶ȹ���";
						continue;
					}

					cv::rectangle(outRenderImage, outROI[i].second, m_RenderShow._contourColor[Label_ID], m_RenderShow._contourThickness[Label_ID]);
				}
			}
		}


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
		//QMessageBox::information(nullptr, tr("Tips"), tr("�ָ�ģ������ʧ��,����Tips:%2").arg(e.what()));
		return false;
	}
}

void ViMoAlgoSegmentation::SetThresholdParam(ThresholdParams inParam)
{
	m_SegThreshold = inParam._segThreshold;
	m_TimeType = inParam._timeType;

	//�����ڲ�SDK��ֵ�ӿ�
	auto params = m_SegModel.GetParams();
	for (auto &kv : params.area_thresholds)
	{
		for (int i = 0; i < m_LableNames.size(); i++)
		{
			if (kv.first == m_LableNames[i])
			{
				kv.second = m_SegThreshold._segThresholdVec[i]._area;
			}
		}
	}
	for (auto &kv : params.width_thresholds)
	{
		for (int i = 0; i < m_LableNames.size(); i++)
		{
			if (kv.first == m_LableNames[i])
			{
				kv.second = m_SegThreshold._segThresholdVec[i]._width;
			}
		}
	}
	for (auto &kv : params.height_thresholds)
	{
		for (int i = 0; i < m_LableNames.size(); i++)
		{
			if (kv.first == m_LableNames[i])
			{
				kv.second = m_SegThreshold._segThresholdVec[i]._height;
			}
		}
	}
	//���ýӿ�������Ч
	m_SegModel.SetParams(params);

	for (auto &kv : params.area_thresholds)
	{
		std::cout << "area threshold: " << kv.first << ": " << kv.second <<std::endl;
	}
	for (auto &kv : params.width_thresholds)
	{
		std::cout << "width threshold: " << kv.first << ": " << kv.second <<std::endl;
	}
	for (auto &kv : params.height_thresholds)
	{
		std::cout << "height threshold: " << kv.first << ": " << kv.second <<std::endl;
	}
}

//void ViMoAlgoSegmentation::SetRenderShowParam(RenderShowParams inParam)
//{
//	m_RenderShow = inParam;
//	uchar lutTable[256 * 3];
//	memset(lutTable, 0, sizeof(lutTable));
//
//	for (int i = 0; i < 256; i++)
//	{
//		if (i == 0)
//		{
//			lutTable[(i) * 3] = 0;
//			lutTable[(i) * 3 + 1] = 0;
//			lutTable[(i) * 3 + 2] = 0;
//		}
//		if (i <= inParam._contourColor.size())
//		{
//			cv::Scalar m_Color = inParam._contourColor[i];
//			lutTable[(i) * 3] = m_Color[0];
//			lutTable[(i) * 3 + 1] = m_Color[1];
//			lutTable[(i) * 3 + 2] = m_Color[2];
//		}
//		if (i > inParam._contourColor.size())
//		{
//			lutTable[(i) * 3] = 0;
//			lutTable[(i) * 3 + 1] = 0;
//			lutTable[(i) * 3 + 2] = 0;
//		}
//	}
//
//	for (int i = 0; i < inParam._contourColor.size(); i++)
//	{
//		cv::Scalar m_Color = inParam._contourColor[i];
//		lutTable[(i) * 3] = m_Color[2];
//		lutTable[(i) * 3 + 1] = m_Color[1];
//		lutTable[(i) * 3 + 2] = m_Color[0];
//	}
//	Lut_Image = cv::Mat(1, 256, CV_8UC3, lutTable);
//}

void ViMoAlgoSegmentation::DrawRender(cv::Mat &inImage, smartmore::vimo::SegmentationResponse rsp, cv::Mat &outRender)
{
	if (inImage.channels() == 1)
		cvtColor(inImage, outRender, cv::COLOR_GRAY2BGR);
	else
		outRender = inImage.clone();

	//Lutӳ����Ⱦͼ
	cv::Mat colorMat;
	cvtColor(rsp.mask, colorMat, cv::COLOR_GRAY2BGR);

	//����
	int rows = rsp.mask.rows;
	int cols = rsp.mask.cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (rsp.mask.at<uchar>(i, j) != 0)
			{
				//��ɫͼ���ȡ����������
				Vec3b pix = colorMat.at<Vec3b>(i, j);
				int B = pix[0];
				int G = pix[1];
				int R = pix[2];
			}
		}
	}


	cv::LUT(colorMat, Lut_Image, colorMat);
	cv::Mat smallMat; cv::resize(colorMat, smallMat, cv::Size(900, 900));
	cv::imshow("rsp.mask", smallMat);
	cv::imwrite("1.bmp", smallMat);
	cv::waitKey(20);
	//addWeighted(inImage, 0.5, colorMat, 0.5, 0, outRender);

	for (std::map<std::string, int>::iterator iter = rsp.label_map.begin(); iter != rsp.label_map.end(); iter++)
	{
		cv::Mat label_mask = (rsp.mask == static_cast<uint8_t>(iter->second));
		//outRender.setTo(cv::Scalar(0, 0, 255), label_mask);
	}
}


QString ViMoAlgoSegmentation::GenSegText(cv::Mat &inMat, cv::Rect targetRegion)
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
		returnStr = tr("No Inference Result");
	}
	cv::Point drawPoint(targetRegion.x, targetRegion.y);
	if (targetRegion.x == 0)
		drawPoint.x = targetRegion.width / 12;
	if (targetRegion.y == 0)
		drawPoint.y = targetRegion.height / 12;
	PutTextChinese(inMat, returnStr, drawPoint, targetRegion.width / 40, cv::Scalar(0, 0, 255));
	//putTextZH(RenderImage, returnStr.toLocal8Bit().toStdString().c_str()/*tempString.toLocal8Bit().toStdString().c_str()*/, cv::Point(RenderImage.cols / 12, RenderImage.rows / 12), cv::Scalar(0, 0, 255), RenderImage.cols / 30);
	return returnStr;
}

void ViMoAlgoSegmentation::GrayValueFilter(cv::Mat inOriginal, cv::Mat &inMask)
{
	if (m_SegThreshold._isFilterMinGray == false && m_SegThreshold._isFilterMaxGray == false) return;

	if (inOriginal.channels() == 3) cvtColor(inOriginal, inOriginal, cv::COLOR_BGR2GRAY);
	for (int i = 0; i < inOriginal.rows; i++)
	{
		uchar* inMaskPtr = inMask.ptr<uchar>(i);
		uchar* OriginalPtr = inOriginal.ptr<uchar>(i);
		for (int j = 0; j < inOriginal.cols; j++)
		{
			if (inMaskPtr[j] != 0)
			{
				if (OriginalPtr[j] <= m_SegThreshold._segThresholdVec[inMaskPtr[j] - 1]._minGrayValue)
				{
					inMaskPtr[j] = 0;
				}
				if (OriginalPtr[j] > m_SegThreshold._segThresholdVec[inMaskPtr[j] - 1]._maxGrayValue)
				{
					inMaskPtr[j] = 0;
				}
			}
		}
	}
}

//Function :  ��֦--�ڿ������ڲ��㼯��ֻ��һ����ȵı�Ե��
//Parameter:  originalMat��ǩͼ��flagMat���ʱ��ͼ��maskValue��ǰ��ǩֵ��edgeThinkesssԤ���ı�Ե���
void ViMoAlgoSegmentation::DfsToLeftRight(cv::Mat &originalMat, cv::Mat &flagMat, int maskValue, cv::Point startPoint, int &labelNums, int edgeThinkesss)
{
	int maxCols = originalMat.cols;
	int maxRows = originalMat.rows;

	if (startPoint.x - edgeThinkesss < 0 || startPoint.x + edgeThinkesss >= maxRows)
	{
		return;
	}

	uchar* originalMatPtr1 = originalMat.ptr<uchar>(startPoint.x);
	uchar* flagMatPtr1 = flagMat.ptr<uchar>(startPoint.x);
	if (originalMatPtr1[startPoint.y + 1] == maskValue && flagMatPtr1[startPoint.y + 1] == 0)
	{
		//����
		for (int indexY = startPoint.y; indexY < maxCols - edgeThinkesss - 1; indexY++)
		{
			if (originalMatPtr1[indexY + edgeThinkesss] == maskValue && originalMat.ptr<uchar>(startPoint.x - edgeThinkesss)[indexY] == maskValue && originalMat.ptr<uchar>(startPoint.x + edgeThinkesss)[indexY] == maskValue) //������ͬ
			{
				flagMatPtr1[indexY] = 1;
				labelNums++;
			}
			else
			{
				break;
			}
		}
	}

	if (originalMatPtr1[startPoint.y - 1] == maskValue && flagMatPtr1[startPoint.y - 1] == 0)
	{
		//����
		for (int indexY = startPoint.y; indexY - edgeThinkesss > 0; indexY--)
		{
			if (originalMatPtr1[indexY - edgeThinkesss] == maskValue && originalMat.ptr<uchar>(startPoint.x - edgeThinkesss)[indexY] == maskValue && originalMat.ptr<uchar>(startPoint.x + edgeThinkesss)[indexY] == maskValue) //������ͬ
			{
				flagMatPtr1[indexY] = 1;
				labelNums++;
			}
			else
			{
				break;
			}
		}
	}
}

//Function : �����ӵ㿪ʼ���ѱ�ǩ���򣬵õ���ǩ������������ұ�Ե��
//Parameter��originalMat��ǩͼ��flagMat���ʱ��ͼ��maskValue��ǰ��ǩֵ��startPoint�������ӵ㣬labelNums��ǩ�������С
std::vector<std::vector<cv::Point>> ViMoAlgoSegmentation::SearchEveryLabel(cv::Mat &originalMat, cv::Mat &flagMat, int maskValue, cv::Point startPoint, int &labelNums)
{
	labelNums = 0;
	std::vector<cv::Point> UpEdgePoints;
	std::vector<cv::Point> DownEdgePoints;
	std::vector<cv::Point> LeftEdgePoints;
	std::vector<cv::Point> RightEdgePoints;
	std::queue<cv::Point> searchQueue;
	searchQueue.push(startPoint);
	UpEdgePoints.push_back(startPoint);
	RightEdgePoints.push_back(startPoint);

	int ImgRows = originalMat.rows;
	int ImgCols = originalMat.cols;

	while (searchQueue.size() != 0)
	{
		cv::Point headPoint = searchQueue.front();
		//8������������
		bool leftEdgeFlag = false;
		bool rightEdgeFlag = false;
		bool upEdgeFlag = false;
		bool downEdgeFlag = false;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if ((i == 0 && j == 0) /*|| (i == 1 && j == -1) || (i == -1 && j == 1) || (i == 1 && j == 1) || (i == -1 && j == -1)*/)
				{
					continue;
				}
				if (headPoint.x + i < 0 || headPoint.x + i >= ImgRows)
				{
					continue;
				}
				if (headPoint.y + j < 0 || headPoint.y + j >= ImgCols)
				{
					continue;
				}

				cv::Point nowPoint(headPoint.x + i, headPoint.y + j);

				uchar* originalMatPtr = originalMat.ptr<uchar>(headPoint.x + i);
				uchar* flagMatPtr = flagMat.ptr<uchar>(headPoint.x + i);

				if (flagMatPtr[headPoint.y + j] == 0) //�ڽӵ�δ����ǹ� -> û�б������ʵ�
				{

					if (originalMatPtr[headPoint.y + j] == maskValue) //�����ڽӵ������ֵ����ʼ����ͬ -> ��ͬMask����
					{
						flagMatPtr[headPoint.y + j] = 1; //��Ǹõ�
						searchQueue.push(nowPoint); //����ͬMask����ĵ�ѹ�����
						labelNums++;
						DfsToLeftRight(originalMat, flagMat, maskValue, nowPoint, labelNums, 1);
					}
					else
					{
						if (i == 0 && j == 1)
						{
							rightEdgeFlag = true;
							continue;
							//RightEdgePoints.push_back(headPoint);
						}
						if (i == 0 && j == -1)
						{
							leftEdgeFlag = true;
							continue;
							//LeftEdgePoints.push_back(headPoint);
						}
						if (i == 1 && j == 0)
						{
							upEdgeFlag = true;
							continue;
							//UpEdgePoints.push_back(headPoint);
						}
						if (i == -1 && j == 0)
						{
							downEdgeFlag = true;
							continue;
							//DownEdgePoints.push_back(headPoint);
						}
					}
				}
			}
		}
		searchQueue.pop(); //�����ʹ��ĵ㵯������
		if (rightEdgeFlag == true)
		{
			RightEdgePoints.push_back(headPoint);
			continue;
		}
		if (leftEdgeFlag == true)
		{
			LeftEdgePoints.push_back(headPoint);
			continue;
		}
		if (upEdgeFlag == true)
		{
			UpEdgePoints.push_back(headPoint);
			continue;
		}
		if (downEdgeFlag == true)
		{
			DownEdgePoints.push_back(headPoint);
			continue;
		}
	}

	std::vector<std::vector<cv::Point>> edgePoints;
	edgePoints.push_back(UpEdgePoints);
	edgePoints.push_back(DownEdgePoints);
	edgePoints.push_back(LeftEdgePoints);
	edgePoints.push_back(RightEdgePoints);
	return edgePoints;
}

//Function : ���������������ص��ұ�ǩ�������ѱ�����ǩ�������ɸѡ�����
//Parameter��maskMat������ViMo�ı�ǩͼ��renderMat�������Ⱦͼ��thickness���Ƶı�ǩ�������
bool ViMoAlgoSegmentation::PostProcessing(cv::Mat maskMat, cv::Mat &renderMat)
{
	bool isOk = true;
	cv::Mat flagMat = cv::Mat::zeros(maskMat.rows, maskMat.cols, CV_8UC1);
	if (renderMat.channels() == 1)
		cv::cvtColor(renderMat, renderMat, cv::COLOR_GRAY2BGR);

	for (int i = 0; i < maskMat.rows; i++)
	{
		uchar* MatPtr = maskMat.ptr<uchar>(i);
		uchar* flagMatPtr = flagMat.ptr<uchar>(i);
		for (int j = 0; j < maskMat.cols; j++)   //�����Ż� -- �õ���ǩ��Ե��ˢ�µ�ǰCols����ʼ������ֹ��
		{
			if (MatPtr[j] != 0 && flagMatPtr[j] == 0)
			{

				int EachLabelNums = 0;
				std::vector<std::vector<cv::Point>> testPoints = SearchEveryLabel(maskMat, flagMat, MatPtr[j], cv::Point(i, j), EachLabelNums);
				int ia = (int)MatPtr[j];

				//�������
				if (EachLabelNums < m_SegThreshold._segThresholdVec[ia - 1]._area) //����
				{
					qDebug() << "�������";
					continue;
				}

				int MinRows = 100000, MinCols = 100000, MaxRows = 0, MaxCols = 0;
				for (int edgeTypeIndex = 0; edgeTypeIndex < 4; edgeTypeIndex++)
				{
					for (int edgeIndex = 0; edgeIndex < testPoints[edgeTypeIndex].size(); edgeIndex++)
					{
						for (int thinkness = 0; thinkness < m_RenderShow._contourThickness[(ia - 1) > 0 ? ia - 1 : 0]; thinkness++)
						{
							if (testPoints[edgeTypeIndex][edgeIndex].x - thinkness <= 0 || testPoints[edgeTypeIndex][edgeIndex].y - thinkness <= 0)
							{
								continue;
							}
							if (testPoints[edgeTypeIndex][edgeIndex].x + thinkness >= maskMat.rows || testPoints[edgeTypeIndex][edgeIndex].y + thinkness >= maskMat.cols)
							{
								continue;
							}
							if (MinRows >= testPoints[edgeTypeIndex][edgeIndex].x)
							{
								MinRows = testPoints[edgeTypeIndex][edgeIndex].x;
							}
							if (MaxRows <= testPoints[edgeTypeIndex][edgeIndex].x)
							{
								MaxRows = testPoints[edgeTypeIndex][edgeIndex].x;
							}
							if (MinCols >= testPoints[edgeTypeIndex][edgeIndex].y)
							{
								MinCols = testPoints[edgeTypeIndex][edgeIndex].y;
							}
							if (MaxCols <= testPoints[edgeTypeIndex][edgeIndex].y)
							{
								MaxCols = testPoints[edgeTypeIndex][edgeIndex].y;
							}
							switch (edgeTypeIndex)
							{
							case 0: //�ϱ�Ե��
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x - thinkness, testPoints[edgeTypeIndex][edgeIndex].y)[0] = m_RenderShow._contourColor[MatPtr[j] - 1][0];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x - thinkness, testPoints[edgeTypeIndex][edgeIndex].y)[1] = m_RenderShow._contourColor[MatPtr[j] - 1][1];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x - thinkness, testPoints[edgeTypeIndex][edgeIndex].y)[2] = m_RenderShow._contourColor[MatPtr[j] - 1][2];
								break;
							case 1://�±�Ե��
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x + thinkness, testPoints[edgeTypeIndex][edgeIndex].y)[0] = m_RenderShow._contourColor[MatPtr[j] - 1][0];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x + thinkness, testPoints[edgeTypeIndex][edgeIndex].y)[1] = m_RenderShow._contourColor[MatPtr[j] - 1][1];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x + thinkness, testPoints[edgeTypeIndex][edgeIndex].y)[2] = m_RenderShow._contourColor[MatPtr[j] - 1][2];
								break;
							case 2://���Ե��
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x, testPoints[edgeTypeIndex][edgeIndex].y - thinkness)[0] = m_RenderShow._contourColor[MatPtr[j] - 1][0];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x, testPoints[edgeTypeIndex][edgeIndex].y - thinkness)[1] = m_RenderShow._contourColor[MatPtr[j] - 1][1];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x, testPoints[edgeTypeIndex][edgeIndex].y - thinkness)[2] = m_RenderShow._contourColor[MatPtr[j] - 1][2];
								break;
							case 3://�ұ�Ե��
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x, testPoints[edgeTypeIndex][edgeIndex].y + thinkness)[0] = m_RenderShow._contourColor[MatPtr[j] - 1][0];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x, testPoints[edgeTypeIndex][edgeIndex].y + thinkness)[1] = m_RenderShow._contourColor[MatPtr[j] - 1][1];
								renderMat.at<cv::Vec3b>(testPoints[edgeTypeIndex][edgeIndex].x, testPoints[edgeTypeIndex][edgeIndex].y + thinkness)[2] = m_RenderShow._contourColor[MatPtr[j] - 1][2];
								break;
							default:
								break;
							}
						}
					}
				}
				/*if (MinRows == 100000 || MinCols == 100000 || MaxRows == 0 || MaxCols == 0)
				{
					continue;
				}*/
				if ((MaxCols - MinCols) >= m_SegThreshold._segThresholdVec[ia - 1]._width)
				{
					isOk = false;
					qDebug() << "��ȱ�����";
				}
				if ((MaxRows - MinRows) >= m_SegThreshold._segThresholdVec[ia - 1]._height)
				{
					isOk = false;
					qDebug() << "�߶ȱ�����";
				}
				DefectFlag[ia - 1] = true;

				//QString TextWord = QString::fromLocal8Bit("���:%1\n,��:%2,��:%3").arg(EachLabelNums).arg((MaxCols - MinCols)).arg((MaxRows - MinRows));
				//int MaxValue = (MaxRows - MinRows) > (MaxCols - MinCols) ? (MaxRows - MinRows) : (MaxCols - MinCols);
				//PutTextChinese(renderMat, TextWord, Point(MinCols/* + inROI.x*/, MinRows /*+ inROI.y*/ - 2), MaxValue / 10, m_RenderShow._contourColor[MatPtr[j] - 1]);
				/*QString TextWord = QString::fromLocal8Bit("���:%1\n,��:%2,��:%3").arg(EachLabelNums).arg((MaxCols - MinCols)).arg((MaxRows - MinRows));
				PutTextChinese(renderMat, TextWord, Point(MinRows, MinCols-20), renderMat.cols / 40, cv::Scalar(0, 0, 255));*/
				//putText(renderMat, "xiaoweiguo", Point(renderMat.rows / 2, renderMat.cols / 2), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 1, 8, false);				
			}
		}
	}
	return isOk;
}



AllThreshold ViMoAlgoSegmentation::GetThresholdValue()
{
	ThresholdParams returnParam;
	returnParam._segThreshold = m_SegThreshold;
	auto params = m_SegModel.GetParams();
	for (auto &kv : params.area_thresholds)
	{
		std::cout << "area threshold: " << kv.first << ": " << kv.second << std::endl;
	}
	for (auto &kv : params.width_thresholds)
	{
		std::cout << "width threshold: " << kv.first << ": " << kv.second << std::endl;
	}
	for (auto &kv : params.height_thresholds)
	{
		std::cout << "height threshold: " << kv.first << ": " << kv.second << std::endl;
	}
	AllThreshold returnAllValue;
	returnAllValue._PostParam = returnParam;
	returnAllValue._RenderParam = m_RenderShow;
	return returnAllValue;
}

ViMoModelInfo ViMoAlgoSegmentation::GetModelInfos()
{
	ViMoModelInfo returnInfo;
	returnInfo.id = m_SegModel.GetInfo().id;
	returnInfo.features = m_SegModel.GetInfo().features;
	returnInfo.model_version = m_SegModel.GetInfo().model_version;
	returnInfo.default_shifting = m_SegModel.GetInfo().default_shifting;
	returnInfo.default_padding = m_SegModel.GetInfo().default_padding;
	return returnInfo;
}