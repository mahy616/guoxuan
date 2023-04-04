#pragma once

#include <QWidget>
#include "ui_ThresholdSet.h"
#include "PublicParamter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <qpushbutton.h>
#include <QLabel>
#include <QLineEdit>
#include <qradiobutton.h>
#include <QTableWidget>
#include <qheaderview.h>
#include <QMessageBox>
#include <QCheckBox>
#include "ThresholdBase.h"
#include "RenderSetWidget.h"
#include <QColorDialog>
#include <QTableWidget>
#include <QEvent>
#include <QShowEvent>

class ThresholdSet : public QWidget
{
	Q_OBJECT
public:
	ThresholdSet(QWidget *parent = nullptr);
	~ThresholdSet();
	// ���㷨���������ı�ʱ���øú������л�������ֵ����
	void SetMyParamter(std::vector<string> RealNameVec, std::vector<string> inTypeVec, std::vector<std::vector<std::string>> inLableNamesVec);
	// ��ȡ��ǰģ�͵�������ֵ
	std::vector<AllThreshold> GetThresholdAllParam();
	// ��ȡ��ǰ�ĳ�ʱ��ֵ
	int GetTimeValue();
	TimeSetParamter GetTimeThreshold();
	// ���ط���ʱ�������ļ���ʼ����ֵ
	void inintProgramThreshold(std::vector<AllThreshold> m_Threshold, TimeSetParamter inTimeParam);
	// ��ȡ�㷨�����ֵ�ص�����
	std::function<std::vector<AllThreshold>(void)> m_AlgoThreadCallBack;
	// ��ȡ�㷨���ģ����Ϣ�ص�����
	std::function<std::vector<ViMoModelInfo>(void)> m_AlgoInfoCallBack;
protected:
	virtual void showEvent(QShowEvent *event) override; //��ʾ�¼��л�ȡ��ǰ��ģ����Ϣ����ʼ���㷨���л�ȡ����ֵ
private:
	Ui::ThresholdSetClass ui;
	std::vector<ThresholdBase*> m_ThresholdDialgVec;  //������ֵWidget���飨����ģ�ͣ����Դ��vector�������±�˳����ģ�ʹ���˳����ͬ��
	std::vector<RenderSetWidget*> RenderWidgets;      //��ʾ����Widget���飨����ģ�ͣ����Դ��vector�������±�˳����ģ�ʹ���˳����ͬ��
	TimeSetParamter m_TimeThreshold;                  //��ʱ����
private slots:
	void onDialgCurrentIndexChanged(int);             //��ComBox���л���ģ����Ӧ�Ĳۺ���
	void btnConfimSlot();                             //�����ȷ����ť
	void btnReSetSlot();                              //��������ð�ť
signals:
	void SendThresholdPatamter();                   
};
