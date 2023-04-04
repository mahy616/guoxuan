#include "AlgoViMo.h"
#include "ViMoAlgoClassification.h"
#include "ViMoAlgoDetection.h"
#include "ViMoAlgoOCR.h"
#include "ViMoAlgoSegmentation.h"

AlgoViMo::~AlgoViMo()
{
	//�����ģ��
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
		//�����ģ��
		for (int i = 0; i < m_ViMoAlogVec.size(); i++)
		{
			delete m_ViMoAlogVec[i];
		}
		m_ViMoAlogVec.clear();
		bool isSuccess = true;
		//�����ģ��
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
	//SDK��BUG:����ģ�������ͼ������ǡ�ԭͼ+ROI��,���������ǲü����Сͼ������Ч������
	//��ʱ���:��¼ÿ��ǰ��ģ���ROI

	outIsOk = true;
	std::queue<cv::Rect> ImageVec;									  //ǰ��ģ����������Roi����
	ImageVec.push(cv::Rect(0, 0, inputImage.cols, inputImage.rows));  //ViMo�����ͼ��ԭͼ����������ԭͼROI

	//��������ѭ����������
	for (int i = 0; i < m_ViMoAlogVec.size(); i++)
	{
		double totalTime = 0;
		if (i == m_ViMoAlogVec.size() - 1) //����ģ��
		{
			//��������ǰ��ģ�������Roiͼ��
			int ImageNums = ImageVec.size();
			for (int queueIndex = 0; queueIndex < ImageNums; queueIndex++)
			{
				cv::Rect oneData = ImageVec.front();
				m_ViMoAlogVec[i]->RunAlgo(inputImage, outRenderImage, oneData, outResultJson, totalTime, outIsOk);
				outMilliseconds = outMilliseconds + totalTime;
				ImageVec.pop();
			}
		}
		else //ǰ��ģ��
		{
			int ImageNums = ImageVec.size();  //��ǰģ���ǰ��ģ��ROI
			for (int queueIndex = 0; queueIndex < ImageNums; queueIndex++)
			{
				//�������ε���ǰ��ģ���Roi�������㷨��������
				cv::Rect oneData = ImageVec.front(); ImageVec.pop(); 
				std::vector<std::pair<std::string, cv::Rect>> ResultROI;  //��ǰģ������תROI�Ľṹ��
				m_ViMoAlogVec[i]->RunAlgo(inputImage, outRenderImage, oneData, ResultROI, totalTime); 
				outMilliseconds = outMilliseconds + totalTime;
				//����ǰ����Roiѹ�����
				for (int roiIndex = 0; roiIndex < ResultROI.size(); roiIndex++)
				{
					ImageVec.push(ResultROI[roiIndex].second);
				}
			}
		}
	}
	if (outResultJson.size() == 0|| outResultJson==",") //ǰ��ģ�鱻����ʱ
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

// ������ֵ����
void AlgoViMo::SetThresholdParam(std::vector<ThresholdParams> inParam)
{
	for (int i = 0; i < inParam.size() && i < m_ViMoAlogVec.size(); i++)
	{
		m_ViMoAlogVec[i]->SetThresholdParam(inParam[i]);
	}
}

// ��ʾ����
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