#pragma once
#include <QThread>
#include <QQueue>
#include <QMutex>
#include "opencv2/opencv.hpp"
#include "qdebug.h"
using namespace std;
using namespace cv;

typedef struct
{
	QString SavePath; //保存目录
	QString FileName;    //文件名
	bool isCameraImage = true;
	Mat image;
}s_ImageInfo;

typedef QQueue<s_ImageInfo> QImageInfos;

class CSaveImage :public QThread
{
	Q_OBJECT
public:
	CSaveImage(QThread *parent = NULL);
	~CSaveImage();
	static CSaveImage *GetInstance();
	// 停止线程
	void StopThread();
	// 插入存图数据
	void SetImageInfo(s_ImageInfo ImageInfo);
	// 软件初始化时先按照图片数量自动删除
	void SelfStartDeleteByFileNums();
private:
	static CSaveImage *m_Instance;
	// 按Deadline时间删除文件夹 - 按天数删除时调用
	void DeleteTimeBeforeDir(QString Path, int Deadline);
	// 删除时间最早的一个文件夹 - 按容量删除时调用
	bool DeleteEarliestDir(QString Path);
	// 删除最早的一个文件 - 按图片数量删除时调用
	void DeleteEarliestOneFile(QString Path, bool isCamera);
	// 保存当前图片
	void SaveImage(s_ImageInfo &ImageInfo);
	// 按容量删除
	void DeleteByMemory(s_ImageInfo ImageInfo);
	// 按图片张数删除
	void DeleteSurplusNum(bool isCamera);
	// 获取当前磁盘容量
	quint64 GetDiskFreeSpace(QString DiskName);
private:
	QImageInfos m_ImageInfos;
	QMutex m_Mutex;
	bool m_bStop;
	int CameraImageNum = 0;
	int RenderImageNum = 0;
private:
	void run();
};