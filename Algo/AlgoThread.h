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
	// 当前算法的初始化状态
	enum AlgoState { NoInint, inIninting, InintSuccess, InintFail }; 
	CAlgoThread(int *WindowIndex);
	~CAlgoThread();
	// 控制线程启停
	bool bStart = false;
	// 算法初始化
	bool InitModule(ModelChoice JsonConfig);
	// 外部插入待检测的图片数据
	bool SetImage(ThreadQueueInfos ImageIngos);
	// 当前算法是否正在运行
	bool IsAlgoRuning();
	// 当前算法是否初始化成功
	bool IsInintDone();
	// 获取阈值
	std::vector<AllThreshold> GetThresholdValue();
	// 获取模型信息
	std::vector<ViMoModelInfo> GetAlogInfo();
	// 设置阈值
	void SetThreshold(std::vector<AllThreshold> inThreshold);
private:
	QMutex m_Mutex;
	QWaitCondition m_Condition;              //控制线程运行的条件变量
	QQueue<ThreadQueueInfos> m_ImageInfos;   //线程图片队列
	std::atomic<bool> isRuningFlag{ false }; //当前是否正在运行图片的原子变量
	AlgoState m_bInitSuccess = NoInint;      //当前算法的初始化状态
	int *MyWindowIndex;                      //当前是第几个窗口的算法
	AlgoViMo *m_AlgoViMo = nullptr;          //运行的算法实例
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
