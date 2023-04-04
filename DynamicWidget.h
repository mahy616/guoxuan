#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DynamicWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include "UI/ImageWindow.h"
#include <QEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QTableWidget>
#include <qheaderview.h>
#include <QTabWidget>
#include <qmessagebox.h>
#include <QDockWidget>
#include <qaction.h>
#include <math.h>
#include "UI/DataStatistics.h"
#include "UI/TimeStatistics.h"
#include <QCloseEvent>
#include "UI/Performance/GpuMonitor.h"
#include "UI/MyTitleBar.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QScrollBar>
#include "UI/MyWidget/MyTableWidget.h"
#include "MyStation.h"
#include "SoftSetting/SoftSetting.h"
#include "DataManager.h"
#include "ResultSetting.h"
#include "QStandardItemModel"
#include "Config.h"
class DynamicWidget : public QMainWindow
{
	Q_OBJECT
public:
	DynamicWidget(QWidget *parent = nullptr);
	~DynamicWidget();
	std::vector<MyStation*> m_Station;                   //MyStation���飺�½����������ٴ��ڶ�Ӧ����������
	static DynamicWidget *GetInstance();                 //����
	void SetLogoVisuable(bool isSee);
	void SetSoftName(QString name);
	bool GetLogoVisuable();
	QString GetSoftName();
private: 
	Ui::DynamicWidgetClass ui;
	static DynamicWidget *m_Instance;
	enum RuningState { isWorking, isStop, isWaitting };  // ��ǰ���������״̬�������У�δ���У��ȴ�ֹͣ��
	QDockWidget *GpuMinoitorDock = nullptr;              // GPU���ܼ��������
	QGridLayout *m_ImagesWindow;                         // ��ʾ����ͼ���դ�񲼾�
	int windowsNums = 2; 
	ResultSetting *m_result_setting = nullptr;
	QDockWidget *m_DockWidget = nullptr;				//�Ҳ�����������
	QDockWidget *m_DockWidget1 = nullptr;// ��ǰ��λ��������󴴽�10�����ڣ�
	QListView *m_listView = nullptr;
	QStandardItemModel *m_LogModel;
private: 
	// ���һ����λ
	void AddOneStation(int index, bool bInint = false);
	// ���õ�ǰ���������״̬
	void SetRunningState(RuningState inState);
	void SetRuningState(bool isRuning);
	// ��ȡ��ǰ�Ƿ�����״̬ - ͨ��toorBar�Ŀ�ʼ��ťͼ��ʹ��״̬�жϵ�ǰ���������״̬
	bool isRunning();
	// ��ȡ���й�λ���㷨�Ƿ񶼳�ʼ���ɹ�(������а�ťʱ��Ҫ�ж�)
	bool JudgeAlgoInintState();
	// Ĭ�ϵĴ��ڳ�ʼ��
	void InintWindow();
	// ���ڹر��¼�ʱ����������Դ
	void closeEvent(QCloseEvent *);
	// ��ʼ������
	void InintParameter();
	// ��ʼ���źŲ�
	void InintConnection();
	void ShowLog(QString log);
	void LoadParameter();
private slots:
	// ��Ӵ��ڲۺ���
	void AddWindowSlot();
	// ɾ�����ڲۺ���:: int��������ɾ���Ĵ���ID
	void DeleteWindowSlot(int);		
	// ���л��������½�����ʱִ�е����ô��ڲۺ���
	void ReSetWindowSlot();
	// ���ط����ۺ���:: QString�������뷽����json����
	void LoadProgramme(QString loadProgrammeName);
	// ����㷨�߳��Ƿ����н����Ķ�ʱ���ۺ���
	void TimerWatchOnAlgoStop();
protected:
	void resizeEvent(QResizeEvent *event);

// ###################################################  ��������أ�toorBar��  ########################################################
private slots:
	void ActionStartWorkSlot();   //����������а�ť
	void ActionStopWorkSlot();    //���ֹͣ������ť
	void Action_SingleGrab();     //�������ִ�а�ť
	void Action_SystemSetSlot();  //���ϵͳ���ð�ť
	void Action_SqlDataSlot();  //���ϵͳ���ð�ť
// #######################################################################################################################


// ###################################################  ��������أ�toorBar��  ######################################################
private:
	void inintTitteBar();          //��ʼ��������
private slots:
	void onButtonMinClicked();     //��С���¼�
	void onButtonRestoreClicked(); //��ԭ�¼�
	void onButtonMaxClicked();     //����¼�
	void onButtonCloseClicked();   //�ر��¼�
// #######################################################################################################################
};

