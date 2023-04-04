#pragma once
#include <qobject.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include "UI/ImageWindow.h"
#include <QEvent>
#include <QMouseEvent>
#include <QTableWidget>
#include <qheaderview.h>
#include <QTabWidget>
#include <qmessagebox.h>
#include <QDockWidget>
#include <qaction.h>
#include <math.h>
#include "Algo/AlgoThread.h"
#include "PublicParamter.h"
#include "UI/DataStatistics.h"
#include "UI/TimeStatistics.h"
#include <QCloseEvent>
#include "UI/Performance/GpuMonitor.h"
#include "UI/MyTitleBar.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QScrollBar>
#include "UI/MyWidget/MyTableWidget.h"
#include <QModelIndex>
#include <QMessageBox>
#include "UI/ResultsListWidget.h"
#include "ResultSetting.h"
class ImageSouceBase;
class MyStation : public QObject
{
	Q_OBJECT
public:
	MyStation(int windowsIndex,QWidget *parent);
	~MyStation();
	void initAlgo(int windowsIndex);
	void inintVariable(int windowsIndex);
	void inintConnection();
	// �������ļ�����MyStation
	void LoadImageSourceFromConfig(WindowsConfig inConfig);
	// ��ǰ������״̬�����ð�ť��ʹ�� - DynamicWidget����״̬�ı�ʹ�øú���
	void WorkStateChange(bool isWork);
	// ��DynamicWidget������״̬����ָ�봫��ͼ�񴰿�
	void SetRunningStateChange(std::function<bool(void)> inStatePtr);
	// ���õ�ǰ�����Ƿ����Ok/Ng
	void SetOkNgVisible(bool isShow);
public:
	int StationIndex;
	ResultSetting *m_result_setting = nullptr;
	QDockWidget *m_DockWidget = nullptr;				//�Ҳ�����������
	QDockWidget *m_DockWidget1 = nullptr;
	MyTableWidget *m_TableWidget = nullptr;				//����б�ؼ�
	ImageWindow *m_ImageWindow = nullptr;				//ͼ�񴰿�
	CAlgoThread *m_AlgoThread = nullptr;				//�㷨�߳�
	DataStatistics *m_DataStatistic = nullptr;			//����ͳ��
	TimeStatistics *m_TimeStatistic = nullptr;			//ʱ��ͳ��
	ImageSourceBase *m_ImageSource = nullptr;			//ͼ��Դ
	ResultsListWidget* m_ResultListWidget = nullptr;	//����б�
	bool isShowOkNg = true;                             //��ǰ�Ƿ���ʾOk/Ng

public slots:
	// ����б��е���ۺ�������ȡ��һ�е��ļ�·�������㷨����
	void TableWidgetClickedSlot(QModelIndex index);
	// ��ȡ�����ͼ��ۺ����������㷨���������ͼƬ
	void GetCameraIamge(cv::Mat);
	// ��ֵ�����ȷ����ť�ۺ���
	void GetThresholdAllParam();
	// ��ȡ���㷨�����Ĳۺ������������ͼ����Ⱦͼ
	void SaveImageSlot(cv::Mat& OriginalImage, cv::Mat& RenderImage, bool bOK, QString tableText, int TableIndex,QString ImageFileName);
	// ��ȡ���㷨�����ı�Ĳۺ���
	void GetModelChangeSlot(ModelChoice ConfigParamter);
private:
	// �˳��㷨�߳�
	void CloseAlgo();
signals:
	void AddOneWindowSignals();
	void sendLog(QString);
};


