#include "AlgoThread.h"
#include "QCoreApplication"
#include "QDebug"
#include "QDateTime"
#include <QMessageBox>
#include "UI/MyDialog/WaittingDialog.h"
#include "components/Config/ConfigProgramme.h"
using namespace smartmore;


CAlgoThread::CAlgoThread(int *WindowIndex)
{
	MyWindowIndex = WindowIndex;
	m_bInitSuccess = AlgoState::NoInint;
}

CAlgoThread::~CAlgoThread()
{
	if (m_AlgoViMo != nullptr)
	{
		delete m_AlgoViMo;
	}
}


bool CAlgoThread::InitModule(ModelChoice JsonConfig)
{
	std::vector<ModelConfig> m_InintConfigVec;
	for (int i = 0; i < JsonConfig.moduleID.size(); i++)
	{
		ModelConfig oneConfig;
		oneConfig._useGPU = JsonConfig._useGPU;
		oneConfig._gpuID = JsonConfig._gpuID;
		oneConfig._jsonPath = JsonConfig._jsonPath;
		oneConfig._type = GetModelTypeFromString(JsonConfig.modeType[i]);
		oneConfig._moduleID = tr(JsonConfig.moduleID[i].c_str());
		oneConfig._labelName = JsonConfig.labelsNamesVec[i];
		oneConfig.RealNameValue = JsonConfig.RealNameValue[i];
		m_InintConfigVec.push_back(oneConfig);
	}

	std::thread inintAlgoThread([=]() {
		try
		{
			m_bInitSuccess = AlgoState::inIninting;
			if (m_AlgoViMo != nullptr)
			{
				delete m_AlgoViMo;
			}
			m_AlgoViMo = new AlgoViMo;
			bool isSuccess = m_AlgoViMo->InintAlgo(m_InintConfigVec);
			inintSuccessSiganl(isSuccess);
			if(isSuccess)
				m_bInitSuccess = AlgoState::InintSuccess;
			else
				m_bInitSuccess = AlgoState::InintFail;
			ConfigProgramme::GetInstance()->AllConfig[*MyWindowIndex - 1].m_Threshold = GetThresholdValue();
		}
		catch (vimo::VimoException &e)
		{
			std::cerr << "catch error: " << e.what() << std::endl;
			inintSuccessSiganl(false);
			m_bInitSuccess = AlgoState::InintFail;
		}
	});
	inintAlgoThread.detach();
	return m_bInitSuccess;
}

bool CAlgoThread::SetImage(ThreadQueueInfos ImageIngos)
{
	bool returnFlag = true;
	m_Mutex.lock();
	if (m_ImageInfos.size() <= 1) //���д���2������ѹ�룬����false�ⲿ�ȴ�
		m_ImageInfos.push_back(ImageIngos);
	else
		returnFlag = false;
	m_Mutex.unlock();
	if (returnFlag) m_Condition.wakeAll();
	return returnFlag;
}

void CAlgoThread::run()
{
	//SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	while (bStart)
	{
		if (m_bInitSuccess != AlgoState::InintSuccess)//û��ʼ���ɹ�������£�����
		{
			Sleep(10); continue;
		}
		m_Mutex.lock();
		while (m_ImageInfos.empty() == true)
			m_Condition.wait(&m_Mutex);
		ThreadQueueInfos ImageIngos = m_ImageInfos.dequeue();
		cv::Mat copyMat = ImageIngos.m_Image;
		int nowTableIndex = ImageIngos.TableIndex;
		QString ImageFileName = ImageIngos.ImageName;
		m_Mutex.unlock();

		isRuningFlag = true; //��ǰ�߳�������ͼ

		if (copyMat.cols == 0 || copyMat.rows == 0)
			continue;
		if (copyMat.channels() == 4) //ViMo��֧��4ͨ��ͼ��
			cvtColor(copyMat, copyMat, cv::COLOR_RGBA2RGB);

		//cv::Mat inputImage = copyMat(cv::Rect(25, 40, 1250, 280));
		//cv::Mat RenderImage = inputImage.clone();
		cv::Mat RenderImage = copyMat.clone();

		if (RenderImage.channels() == 1) //�����ں����⸳ֵΪ��ɫͼ!!! cvtColor���������run�����ڲ����õĲ�ɫͼ����Ⱦ��rendenr������ͬһ���ڴ棬������Ⱦʧ��
			cv::cvtColor(RenderImage, RenderImage, cv::COLOR_GRAY2BGR);
		

		double SendTime = 0; QString outStr; bool isGood;
		m_AlgoViMo->RunAlgo(copyMat, RenderImage, outStr, SendTime, isGood);
		guoxuan::get_instance().processingData(outStr.toStdString(), *MyWindowIndex);
		emit SendDetectionResult(copyMat, RenderImage, isGood, SendTime);
		emit SendResultToTable(nowTableIndex, isGood, SendTime, outStr);
		//emit SendToSaveImg(copyMat, RenderImage, isGood, outStr, nowTableIndex, ImageFileName);
		if (outStr.size() < 23)
		{
			QString msg;
			if (*MyWindowIndex == 1)
				msg = QString::fromLocal8Bit("��ͷOCRʶ��ȫ");
			else if (*MyWindowIndex == 2)
				msg = QString::fromLocal8Bit("��βOCRʶ��ȫ");
			emit sendLog(msg);
			emit SendToSaveImg(copyMat, RenderImage, isGood, outStr, nowTableIndex, ImageFileName);
		}
		

		isRuningFlag = false; //��ǰ�߳̽�����ͼ
	}
}

bool CAlgoThread::IsAlgoRuning()
{
	int QueueNum;
	m_Mutex.lock();
	QueueNum = m_ImageInfos.size();
	m_Mutex.unlock();

	if (QueueNum == 0 && isRuningFlag == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void CAlgoThread::SetThreshold(std::vector<AllThreshold> inThreshold)
{
	std::vector<ThresholdParams> inThresholdParam; std::vector<RenderShowParams>  inRenderParam;
	for (auto oneValue : inThreshold)
	{
		inThresholdParam.push_back(oneValue._PostParam);
		inRenderParam.push_back(oneValue._RenderParam);
	}
	if (m_bInitSuccess == InintSuccess)
	{
		m_AlgoViMo->SetThresholdParam(inThresholdParam);
		m_AlgoViMo->SetRenderShowParam(inRenderParam);
	}
	else
	{
		WaittingDialog* m_WaittingDialog;
		switch (m_bInitSuccess)
		{
		case inIninting:
			m_WaittingDialog = new WaittingDialog(tr("Pipeline initializing...,One moment please"));
			m_WaittingDialog->show();		
			while (true)//�ȴ���
			{
				if (m_bInitSuccess != inIninting)
				{
					delete m_WaittingDialog;				
					if (m_bInitSuccess == InintFail) QMessageBox::information(nullptr, tr("Tips"), tr("Pipeline initialization failed. Failed to set threshold values."));
					break;
				}
				Sleep(50);
				QCoreApplication::processEvents();
			}
			m_AlgoViMo->SetThresholdParam(inThresholdParam);
			m_AlgoViMo->SetRenderShowParam(inRenderParam);
			break;
		case InintFail:
			QMessageBox::information(nullptr, tr("Tips"), tr("Pipeline initialization failed. Failed to set threshold values."));
			break;
		default:
			break;
		}
	}
}


bool CAlgoThread::IsInintDone()
{
	if (m_bInitSuccess == AlgoState::inIninting)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::vector<AllThreshold> CAlgoThread::GetThresholdValue()
{
	std::vector<AllThreshold> m_return;
	if (m_bInitSuccess == InintSuccess)
	{
		return m_AlgoViMo->GetThresholdValue();
	}
	else
	{
		WaittingDialog* m_WaittingDialog;
		switch (m_bInitSuccess)
		{
		case inIninting:
			m_WaittingDialog = new WaittingDialog(tr("Pipeline initializing...,One moment please"));
			m_WaittingDialog->show();
			while (true)//�ȴ���
			{
				if (m_bInitSuccess != inIninting)
				{
					delete m_WaittingDialog;
					if (m_bInitSuccess == InintFail) 
						QMessageBox::information(nullptr, tr("Tips"), tr("Pipeline initialization failed. Failed to get threshold values."));
					else
					{
						return m_AlgoViMo->GetThresholdValue();
					}
					break;
				}
				Sleep(50);
				QCoreApplication::processEvents();
			}
			break;
		case InintFail:
			QMessageBox::information(nullptr, tr("Tips"), tr("Pipeline initialization failed. Failed to get threshold values."));
			break;
		default:
			break;
		}
	}	
	return m_return;
}

std::vector<ViMoModelInfo> CAlgoThread::GetAlogInfo()
{
	std::vector<ViMoModelInfo> m_return;
	if (m_bInitSuccess == InintSuccess)
	{
		return m_AlgoViMo->GetModelInfo();
	}
	else
	{
		WaittingDialog* m_WaittingDialog;
		switch (m_bInitSuccess)
		{
		case inIninting:
			m_WaittingDialog = new WaittingDialog(tr("Pipeline initializing...,One moment please"));
			m_WaittingDialog->show();
			while (true)//�ȴ���
			{
				if (m_bInitSuccess != inIninting)
				{
					delete m_WaittingDialog;
					if (m_bInitSuccess == InintFail)
						QMessageBox::information(nullptr, tr("Tips"), tr("Pipeline initialization failed. Failed to get pipeline information."));
					else
						return m_AlgoViMo->GetModelInfo();
					break;
				}
				Sleep(50);
				QCoreApplication::processEvents();
			}
			break;
		case InintFail:
			QMessageBox::information(nullptr, tr("Tips"), tr("Pipeline initialization failed. Failed to get pipeline information."));
			break;
		default:
			break;
		}
	}
	return m_return;
}
