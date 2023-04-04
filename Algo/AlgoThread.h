#pragma once
#include "qthread.h"
#include "qmutex.h"
#include "QQueue"
#include <QWaitCondition>
#include <queue>
#include "opencv2/imgproc/types_c.h"
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include "PublicParamter.h"
#include <vector>
#include <iostream>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <vimo_inference/vimo_inference.h>
#include <vimo_inference/any_response.h>
#include "Algo/AlgoViMo.h"
#include <atomic>

using namespace std;
using namespace smartmore;

class CAlgoThread :public QThread
{
	Q_OBJECT
public:
	// ��ǰ�㷨�ĳ�ʼ��״̬
	enum AlgoState { NoInint, inIninting, InintSuccess, InintFail }; 
	CAlgoThread(int *WindowIndex);
	~CAlgoThread();
	// �����߳���ͣ
	bool bStart = false;
	// �㷨��ʼ��
	bool InitModule(ModelChoice JsonConfig);
	// �ⲿ���������ͼƬ����
	bool SetImage(ThreadQueueInfos ImageIngos);
	// ��ǰ�㷨�Ƿ���������
	bool IsAlgoRuning();
	// ��ǰ�㷨�Ƿ��ʼ���ɹ�
	bool IsInintDone();
	// ��ȡ��ֵ
	std::vector<AllThreshold> GetThresholdValue();
	// ��ȡģ����Ϣ
	std::vector<ViMoModelInfo> GetAlogInfo();
	// ������ֵ
	void SetThreshold(std::vector<AllThreshold> inThreshold);
private:
	QMutex m_Mutex;
	QWaitCondition m_Condition;              //�����߳����е���������
	QQueue<ThreadQueueInfos> m_ImageInfos;   //�߳�ͼƬ����
	std::atomic<bool> isRuningFlag{ false }; //��ǰ�Ƿ���������ͼƬ��ԭ�ӱ���
	AlgoState m_bInitSuccess = NoInint;      //��ǰ�㷨�ĳ�ʼ��״̬
	int *MyWindowIndex;                      //��ǰ�ǵڼ������ڵ��㷨
	AlgoViMo *m_AlgoViMo = nullptr;          //���е��㷨ʵ��
private:
	void run();
signals:
	void inintSuccessSiganl(bool);
signals:
	void SendDetectionResult(cv::Mat& OriginalImage,cv::Mat& RenderImage, bool bOK, double Time);
signals:
	void SendResultToTable(int TableIndex, bool bOK, double Time, QString tableText);
	void sendLog(QString);
signals:
	void SendToSaveImg(cv::Mat& OriginalImage,cv::Mat& RenderImage, bool bOK, QString tableText, int TableIndex,QString ImageFileName);
};
