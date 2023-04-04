#include "ViMoAlgoOCR.h"

ViMoAlgoOCR::~ViMoAlgoOCR()
{
	m_OCRModel.~OcrModule();
}

bool ViMoAlgoOCR::InintAlgo(ModelConfig inConfig)
{
	try
	{
		QByteArray cdata = inConfig._jsonPath.toLocal8Bit();
		m_Solution.LoadFromFile(string(cdata));
		m_OCRModel = m_Solution.CreateModule<smartmore::vimo::OcrModule>(inConfig._moduleID.toStdString(), inConfig._useGPU, inConfig._gpuID);
		m_LableNames = inConfig._labelName;
				
		//待修改 - 赋初始值
		m_TimeType = OnlyViMo;
		m_RenderShow._contourColor = { cv::Scalar(255, 255, 0),cv::Scalar(255, 0, 0) ,cv::Scalar(0, 255, 0) ,cv::Scalar(255, 0, 255) ,cv::Scalar(0, 255, 255) ,cv::Scalar(0, 0, 255),cv::Scalar(30, 150, 215) ,cv::Scalar(230, 20, 115)  ,cv::Scalar(44, 20, 215)  ,cv::Scalar(130, 210, 3) ,cv::Scalar(230, 20, 115) ,cv::Scalar(130, 220, 35)  ,cv::Scalar(55, 220, 35) ,cv::Scalar(230, 11, 55)  ,cv::Scalar(52, 72, 115),cv::Scalar(88,45,12),cv::Scalar(255,45,12) };
		m_RenderShow._contourThickness = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
		if (inConfig._labelName.size() >= m_RenderShow._contourColor.size())
		{
			cv::RNG rng(12345);
			m_RenderShow._contourColor.clear();
			for (int i = 0; i <= inConfig._labelName.size(); i++)
			{
				cv::Scalar m_OneColor(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
				m_RenderShow._contourColor.push_back(m_OneColor);
				m_RenderShow._contourThickness.push_back(2);
			}
		}
		
		//初始化成功后求默认阈值
		m_OCRThreshold.SdkThreshold.resize(inConfig._labelName.size());
		auto params = m_OCRModel.GetParams();
		for (auto &kv : params.score_thresholds)
		{
			for (int i = 0; i <= inConfig._labelName.size(); i++)
			{
				m_OCRThreshold.SdkThreshold[i]._iou = params.iou_threshold;
				if (kv.first == inConfig._labelName[i])
				{
					m_OCRThreshold.SdkThreshold[i]._score = kv.second;
					break;
				}
			}
		}

		//默认推理一张图
		smartmore::vimo::Request req_1{ cv::Mat::zeros(500,500,CV_8UC1) };
		m_OCRModel.Run(req_1, rsp_1);
		//m_OCRThreshold.MatchStrVec.resize(inConfig._labelName.size());
		return true;
	}
	catch (smartmore::vimo::VimoException &e)
	{
		std::cerr << "catch error: " << e.what() << std::endl;
		return false;
	}
}

bool ViMoAlgoOCR::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, QString &outResultJson, double &outMilliseconds, bool &outIsOk)
{
	try
	{
		bool resultState = true;
		//算法运行
		auto algoStart = std::chrono::high_resolution_clock::now();
		int a = inputImage.type();
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_OCRModel.GetInfo().default_shifting, m_OCRModel.GetInfo().default_padding);
			m_OCRModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage ,inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_OCRModel.GetInfo().default_shifting, m_OCRModel.GetInfo().default_padding);
			m_OCRModel.Run(req_1, rsp_1);
		}
		auto algoEnd = std::chrono::high_resolution_clock::now();

		//后处理
		QString outStr;
		guoxuan_processing(rsp_1, inputImage, outRenderImage, outStr) ? resultState = true : resultState = false;
		//OcrPostProcessing(rsp_1, inputImage, outRenderImage, outStr) ? resultState = true : resultState = false;
		outResultJson = outResultJson + outStr + ",";

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

bool ViMoAlgoOCR::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds)
{
	try
	{
		//算法运行
		auto algoStart = std::chrono::high_resolution_clock::now();
		if (inROI.width == inputImage.cols)
		{
			smartmore::vimo::Request req_1{ inputImage };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_OCRModel.GetInfo().default_shifting, m_OCRModel.GetInfo().default_padding);
			m_OCRModel.Run(req_1, rsp_1);
		}
		else
		{
			smartmore::vimo::Request req_1{ inputImage,inROI };
			req_1.roi = smartmore::vimo::RoiAlign(req_1.roi, m_OCRModel.GetInfo().default_shifting, m_OCRModel.GetInfo().default_padding);
			m_OCRModel.Run(req_1, rsp_1);
		}
		auto algoEnd = std::chrono::high_resolution_clock::now();

		if (rsp_1.blocks.size() >= 1)
		{
			outROI = ConvertResponseToBoundingBox(rsp_1);
			//后处理
			//绘制渲染图
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
		return false;
	}
}

void ViMoAlgoOCR::SetThresholdParam(ThresholdParams inParam)
{
	m_OCRThreshold = inParam._ocrThreshold;
	m_TimeType = inParam._timeType;

	//SDK后处理阈值：分数与iou接口 (分数接口可以单独对每个标签设置，iou只能对所有标签共同设置)
	auto params = m_OCRModel.GetParams();
	//设置iou阈值
	params.iou_threshold = m_OCRThreshold.SdkThreshold[0]._iou;
	//设置分数阈值
	for (auto &kv : params.score_thresholds)
	{
		for (int i = 0; i < m_OCRThreshold.SdkThreshold.size(); i++)
		{
			if (kv.first == m_LableNames[i])
			{
				kv.second = m_OCRThreshold.SdkThreshold[i]._score;
			}
		}
		std::cout << "score threshold: " << kv.first << ": " << kv.second;
	}
	//调用接口设置生效
	m_OCRModel.SetParams(params);

	//输出查看设置后的阈值
	for (auto &kv : params.score_thresholds) //查看设置的分数阈值
	{
		std::cout << "score threshold: " << kv.first << ": " << kv.second << std::endl;
	}
	std::cout << "iou threshold: " << params.iou_threshold << std::endl;
}

bool myCompareByX(const smartmore::vimo::TextBlock A, const smartmore::vimo::TextBlock B)
{
	double A_x{ 0 }, B_x{ 0 };
	for (auto item : A.polygon)
	{
		A_x += item.x;
	}
	for (auto item : B.polygon)
	{
		B_x += item.x;
	}
	A_x /= A.polygon.size();
	B_x /= B.polygon.size();
	return A_x < B_x;//升序排列
}

bool myCompareByY(const smartmore::vimo::TextBlock A, const smartmore::vimo::TextBlock B)
{
	double A_y{ 0 }, B_y{ 0 };
	for (auto item : A.polygon)
	{
		A_y += item.y;
	}
	for (auto item : B.polygon)
	{
		B_y += item.y;
	}
	A_y /= A.polygon.size();
	B_y /= B.polygon.size();
	return A_y < B_y;//升序排列
}

bool ViMoAlgoOCR::OcrPostProcessing(smartmore::vimo::OcrResponse rsp, cv::Mat inImg, cv::Mat &RenderImage, QString &ResultStr)
{
	std::string returnStr;
	if (RenderImage.channels() == 1)
		cv::cvtColor(RenderImage, RenderImage, cv::COLOR_GRAY2BGR);
	if (rsp.blocks.empty())
	{
		std::cerr << "no ocr result!\n";
		return false;
	}

	for (const auto &block : rsp.blocks)
	{
		//目前SDK的Bug:推理的ID并不等于标签标注时的下标
		//暂时解决：通过labelname匹配标签数组，记录下标
		int Label_ID = -1;

		for (int labelIndex = 0; labelIndex < m_LableNames.size(); labelIndex++)
		{
			string VecLabel = m_LableNames[labelIndex];
			string nowStr = block.label;
			if (m_LableNames[labelIndex] == block.label)
			{
				Label_ID = labelIndex;
				break;
			}
		}

		if (Label_ID == -1) continue;
		int xx1 = (block.polygon[1].x - block.polygon[3].x);
		int xx2 = (block.polygon[3].y - block.polygon[0].y);
		int wordSize = (block.polygon[1].x - block.polygon[3].x)*(block.polygon[3].y - block.polygon[0].y)*0.0025;	if (wordSize < 0.2) wordSize = 0.2;
		cv::rectangle(RenderImage, cv::Point(block.polygon[1].x, block.polygon[1].y), cv::Point(block.polygon[3].x, block.polygon[3].y), m_RenderShow._contourColor[Label_ID], m_RenderShow._contourThickness[Label_ID]);
		int WordRows = (block.polygon[1].y - (block.polygon[3].y - block.polygon[1].y) / 4) >= 10 ? (block.polygon[1].y - (block.polygon[3].y - block.polygon[1].y) / 4) : 10;
		//cv::putText(RenderImage, block.label, cv::Point(block.polygon[3].x /*+ (block.polygon[3].x - block.polygon[1].x) / 2*/, WordRows), cv::FONT_HERSHEY_COMPLEX, wordSize, m_RenderShow._contourColor[Label_ID], wordSize, 8, 0);
		PutTextChinese(RenderImage, QString::fromLocal8Bit(block.label.c_str()), cv::Point(block.polygon[3].x + (block.polygon[1].x - block.polygon[3].x) / 3, WordRows), wordSize, m_RenderShow._contourColor[Label_ID]);
	}
	smartmore::vimo::OcrResponse tempResponse = rsp;

	sort(tempResponse.blocks.begin(), tempResponse.blocks.end(), m_OCRThreshold.SortFunction == SortByX ? myCompareByX : myCompareByY);//升序排列
	for (auto item : tempResponse.blocks)
	{
		returnStr += item.label;
	}

	ResultStr = QString::fromLocal8Bit(returnStr.c_str());

	std::vector<QString>::iterator itStr;
	itStr = find(m_OCRThreshold.MatchStrVec.begin(), m_OCRThreshold.MatchStrVec.end(), ResultStr);
	if (itStr == m_OCRThreshold.MatchStrVec.end())
		return false;
	else
		return true;
}

bool ViMoAlgoOCR::guoxuan_processing(smartmore::vimo::OcrResponse rsp, cv::Mat inImg, cv::Mat & RenderImage, QString & ResultStr)
{
	//if (rsp.blocks.size() == 26 || rsp.blocks.size() == 13)
	//{
		if (RenderImage.channels() == 1)
			cv::cvtColor(RenderImage, RenderImage, cv::COLOR_GRAY2BGR);
		if (rsp.blocks.empty())
		{
			std::cerr << "no ocr result!\n";
			return false;
		}

		for (const auto &block : rsp.blocks)
		{
			//目前SDK的Bug:推理的ID并不等于标签标注时的下标
			//暂时解决：通过labelname匹配标签数组，记录下标
			int Label_ID = -1;

			for (int labelIndex = 0; labelIndex < m_LableNames.size(); labelIndex++)
			{
				string VecLabel = m_LableNames[labelIndex];
				string nowStr = block.label;
				if (m_LableNames[labelIndex] == block.label)
				{
					Label_ID = labelIndex;
					break;
				}
			}

			if (Label_ID == -1) continue;
			int xx1 = (block.polygon[1].x - block.polygon[3].x);
			int xx2 = (block.polygon[3].y - block.polygon[0].y);
			int wordSize = (block.polygon[1].x - block.polygon[3].x)*(block.polygon[3].y - block.polygon[0].y)*0.0025;	if (wordSize < 0.2) wordSize = 0.2;
			cv::rectangle(RenderImage, cv::Point(block.polygon[1].x, block.polygon[1].y), cv::Point(block.polygon[3].x, block.polygon[3].y), m_RenderShow._contourColor[Label_ID], m_RenderShow._contourThickness[Label_ID]);
			int WordRows = (block.polygon[1].y - (block.polygon[3].y - block.polygon[1].y) / 4) >= 10 ? (block.polygon[1].y - (block.polygon[3].y - block.polygon[1].y) / 4) : 10;
			//cv::putText(RenderImage, block.label, cv::Point(block.polygon[3].x /*+ (block.polygon[3].x - block.polygon[1].x) / 2*/, WordRows), cv::FONT_HERSHEY_COMPLEX, wordSize, m_RenderShow._contourColor[Label_ID], wordSize, 8, 0);
			PutTextChinese(RenderImage, QString::fromLocal8Bit(block.label.c_str()), cv::Point(block.polygon[3].x + (block.polygon[1].x - block.polygon[3].x) / 3, WordRows), wordSize, m_RenderShow._contourColor[Label_ID]);
		}
		smartmore::vimo::OcrResponse tempResponse = rsp;
		m_OCRThreshold.SortFunction = SortByY;
		sort(tempResponse.blocks.begin(), tempResponse.blocks.end(), m_OCRThreshold.SortFunction == SortByX ? myCompareByX : myCompareByY);//升序排列
		float size=0;
		int number = 0;
		for (auto info =0;info< tempResponse.blocks.size();info++)
		{
			if (tempResponse.blocks[info].polygon[0].y - size > 40&&size!=0)
				number = info;
			size = tempResponse.blocks[info].polygon[0].y;
		}
		std::vector<smartmore::vimo::TextBlock> above_blocks;
		std::vector<smartmore::vimo::TextBlock> under_blocks;
		above_blocks.assign(tempResponse.blocks.begin(), tempResponse.blocks.end() - (tempResponse.blocks.size()-number));
		under_blocks.assign(tempResponse.blocks.begin() + number, tempResponse.blocks.end());
		m_OCRThreshold.SortFunction = SortByX;
		QString above_str, under_str;
		guoxuan_processing1(above_blocks, above_str);
		guoxuan_processing1(under_blocks, under_str);
		ResultStr = above_str + "," + under_str;
		//sort(above_blocks.begin(), above_blocks.end(), m_OCRThreshold.SortFunction == SortByX ? myCompareByX : myCompareByY);//升序排列
		//sort(under_blocks.begin(), under_blocks.end(), m_OCRThreshold.SortFunction == SortByX ? myCompareByX : myCompareByY);//升序排列
		//for (auto item : above_blocks)
		//{
		//	returnStr += item.label;
		//}
		//ResultStr.push_back(QString::fromLocal8Bit(returnStr.c_str()));

		return true;
	//}
	//else
	//{
	//	return false;
	//}
}

void ViMoAlgoOCR::guoxuan_processing1(std::vector<smartmore::vimo::TextBlock> block, QString& ResultStr)
{
	float value = 0;
	for (auto info : block)
	{
		if (info.label == "0" || info.label == "3" || info.label == "4" || info.label == "5"
			|| info.label == "6" || info.label == "7" || info.label == "8" || info.label == "9")
		{
			value = abs(info.polygon[2].y - info.polygon[0].y);
			break;
		}
	}
	std::string returnStr;
	float size=0;
	sort(block.begin(), block.end(), m_OCRThreshold.SortFunction == SortByX ? myCompareByX : myCompareByY);
	for (auto item : block)
	{
		float value_filter = value / (item.polygon[2].y - item.polygon[0].y);
		if (value_filter > 1.1)
			continue;
		//if ((item.polygon[2].y - item.polygon[0].y) > 0 && (item.polygon[2].y - item.polygon[0].y) < 32)
			//continue;
		if (item.polygon[0].x - size > 200 && size != 0)
		{
			returnStr = returnStr + ",";
		}
		size = item.polygon[0].x;
		returnStr += item.label;

	}
	ResultStr = QString::fromLocal8Bit(returnStr.c_str());
}

AllThreshold ViMoAlgoOCR::GetThresholdValue()
{
	ThresholdParams returnParam;
	returnParam._ocrThreshold = m_OCRThreshold;
	AllThreshold returnAllValue;
	returnAllValue._PostParam = returnParam;
	returnAllValue._RenderParam = m_RenderShow;
	return returnAllValue;
}

ViMoModelInfo ViMoAlgoOCR::GetModelInfos()
{
	ViMoModelInfo returnInfo;
	returnInfo.id = m_OCRModel.GetInfo().id;
	returnInfo.features = m_OCRModel.GetInfo().features;
	returnInfo.model_version = m_OCRModel.GetInfo().model_version;
	returnInfo.default_shifting = m_OCRModel.GetInfo().default_shifting;
	returnInfo.default_padding = m_OCRModel.GetInfo().default_padding;
	return returnInfo;
}