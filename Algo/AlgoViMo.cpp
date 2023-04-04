#include "AlgoViMo.h"
#include "ViMoAlgoClassification.h"
#include "ViMoAlgoDetection.h"
#include "ViMoAlgoOCR.h"
#include "ViMoAlgoSegmentation.h"

AlgoViMo::~AlgoViMo()
{
	//清除旧模型
	for (int i = 0; i < m_ViMoAlogVec.size(); i++)
	{
		delete m_ViMoAlogVec[i];
	}
	m_ViMoAlogVec.clear();
}

bool AlgoViMo::InintAlgo(std::vector<ModelConfig> inConfig)
{
	try
	{
		//清除旧模型
		for (int i = 0; i < m_ViMoAlogVec.size(); i++)
		{
			delete m_ViMoAlogVec[i];
		}
		m_ViMoAlogVec.clear();
		bool isSuccess = true;
		//添加新模型
		for (int i = 0; i < inConfig.size(); i++)
		{
			ViMoAlgoBase* m_OneModule;
			switch (inConfig[i]._type)
			{
			case Classification:
				m_OneModule = new ViMoAlgoClassification;
				break;
			case Segmentation:
				m_OneModule = new ViMoAlgoSegmentation;
				break;
			case Detection:
				m_OneModule = new ViMoAlgoDetection;
				break;
			case OCR:
				m_OneModule = new ViMoAlgoOCR;
				break;
			default:
				break;
			}
			if (m_OneModule->InintAlgo(inConfig[i]) == false) 
				isSuccess = false;
			m_ViMoAlogVec.push_back(m_OneModule);
		}

		return isSuccess;
	}
	catch (...)
	{
		return false;
	}
}

bool AlgoViMo::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, QString &outResultJson, double &outMilliseconds, bool &outIsOk)
{
	//SDK的BUG:后置模块的输入图像必须是“原图+ROI”,如果输入的是裁剪后的小图，推理效果混乱
	//暂时解决:记录每个前置模块的ROI

	outIsOk = true;
	std::queue<cv::Rect> ImageVec;									  //前置模块推理结果的Roi队列
	ImageVec.push(cv::Rect(0, 0, inputImage.cols, inputImage.rows));  //ViMo输入的图是原图，队列推入原图ROI

	//按照数组循序依次推理
	for (int i = 0; i < m_ViMoAlogVec.size(); i++)
	{
		double totalTime = 0;
		if (i == m_ViMoAlogVec.size() - 1) //后置模块
		{
			//依次运行前置模块的所有Roi图像
			int ImageNums = ImageVec.size();
			for (int queueIndex = 0; queueIndex < ImageNums; queueIndex++)
			{
				cv::Rect oneData = ImageVec.front();
				m_ViMoAlogVec[i]->RunAlgo(inputImage, outRenderImage, oneData, outResultJson, totalTime, outIsOk);
				outMilliseconds = outMilliseconds + totalTime;
				ImageVec.pop();
			}
		}
		else //前置模块
		{
			int ImageNums = ImageVec.size();  //当前模块的前置模块ROI
			for (int queueIndex = 0; queueIndex < ImageNums; queueIndex++)
			{
				//队列依次弹出前置模块的Roi，送入算法队列运行
				cv::Rect oneData = ImageVec.front(); ImageVec.pop(); 
				std::vector<std::pair<std::string, cv::Rect>> ResultROI;  //当前模块推理转ROI的结构体
				m_ViMoAlogVec[i]->RunAlgo(inputImage, outRenderImage, oneData, ResultROI, totalTime); 
				outMilliseconds = outMilliseconds + totalTime;
				//将当前推理Roi压入队列
				for (int roiIndex = 0; roiIndex < ResultROI.size(); roiIndex++)
				{
					ImageVec.push(ResultROI[roiIndex].second);
				}
			}
		}
	}
	if (outResultJson.size() == 0|| outResultJson==",") //前置模块被过滤时
	{
		outResultJson = QObject::tr("No Inference Result");
		outIsOk = true;
	}
	else
	{
		outResultJson = outResultJson.mid(0, outResultJson.size() - 1);
	}
	return true;
}

// 设置阈值参数
void AlgoViMo::SetThresholdParam(std::vector<ThresholdParams> inParam)
{
	for (int i = 0; i < inParam.size() && i < m_ViMoAlogVec.size(); i++)
	{
		m_ViMoAlogVec[i]->SetThresholdParam(inParam[i]);
	}
}

// 显示设置
void AlgoViMo::SetRenderShowParam(std::vector<RenderShowParams> inParam)
{
	for (int i = 0; i < inParam.size() && i < m_ViMoAlogVec.size(); i++)
	{
		m_ViMoAlogVec[i]->SetRenderShowParam(inParam[i]);
	}
}

std::vector<AllThreshold> AlgoViMo::GetThresholdValue()
{
	std::vector<AllThreshold> m_Return;
	for (int i = 0; i < m_ViMoAlogVec.size(); i++)
	{
		m_Return.push_back(m_ViMoAlogVec[i]->GetThresholdValue());
	}
	return m_Return;
}

std::vector<ViMoModelInfo> AlgoViMo::GetModelInfo()
{
	std::vector<ViMoModelInfo> m_Return;
	for (int i = 0; i < m_ViMoAlogVec.size(); i++)
	{
		m_Return.push_back(m_ViMoAlogVec[i]->GetModelInfos());
	}
	return m_Return;
}