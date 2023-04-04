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
	QString SavePath; //����Ŀ¼
	QString FileName;    //�ļ���
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
	// ֹͣ�߳�
	void StopThread();
	// �����ͼ����
	void SetImageInfo(s_ImageInfo ImageInfo);
	// �����ʼ��ʱ�Ȱ���ͼƬ�����Զ�ɾ��
	void SelfStartDeleteByFileNums();
private:
	static CSaveImage *m_Instance;
	// ��Deadlineʱ��ɾ���ļ��� - ������ɾ��ʱ����
	void DeleteTimeBeforeDir(QString Path, int Deadline);
	// ɾ��ʱ�������һ���ļ��� - ������ɾ��ʱ����
	bool DeleteEarliestDir(QString Path);
	// ɾ�������һ���ļ� - ��ͼƬ����ɾ��ʱ����
	void DeleteEarliestOneFile(QString Path, bool isCamera);
	// ���浱ǰͼƬ
	void SaveImage(s_ImageInfo &ImageInfo);
	// ������ɾ��
	void DeleteByMemory(s_ImageInfo ImageInfo);
	// ��ͼƬ����ɾ��
	void DeleteSurplusNum(bool isCamera);
	// ��ȡ��ǰ��������
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