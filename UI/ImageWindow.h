#pragma once

#include <QWidget>
#include "ui_ImageWindow.h"
#include <opencv2/opencv.hpp>
#include "PublicParamter.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QDirIterator>
#include "components/Config/JsonReader.h"
#include "UI/Menu/ModelConfigDialg.h"
#include "ThresholdSet.h"
#include <QAction>
#include <QMenu>
#include <QResizeEvent>

// ͼ�񴰿����Ͻ�Ok/Ng��logo
typedef struct LabelOkNg_Info
{
	QLabel* Label_OkNg;
	int OldWidth;
	int OldHeight;
	const int LabelWidth = 50;
	const int LabelHeight = 50;
}LabelOkNg_Info;

class ImageSourceBase;
class ImageWindow : public QWidget
{
	Q_OBJECT
public:
	// WindowIndex��ǰStaion��ID ��inShowFlag�Ƿ���ʾOK/Ng���
	ImageWindow(int* WindowIndex, bool* inShowFlag, QWidget *parent = nullptr);
	~ImageWindow();
	// ��StaionID�ı�ʱ�޸ı���
	void SetWindowsTittle();
	// ��ȡ��ǰ����ʹ�õ�ģ������
	SdkModelType GetModelType();
	// ��MyStation��ͼ��Դ���󴫽��������"ͼ��Դ����"���ʵ�ͼ��Դ��Ķ���
	void SetImageSourcePtr(ImageSourceBase *inPtr);
	// ���ط���ʱ��ʼ��vimoģ�͵Ľӿ�
	void inintLoadModelChoice(ModelChoice inChoice);
	// �����㷨�ຯ����ָ�룬��ȡ�㷨��ֵ����ȡ�㷨��Ϣ
	void SetAlgoThreadCallBackPtr(std::function<std::vector<AllThreshold>(void)> inThresholdPtr, std::function<std::vector<ViMoModelInfo>(void)>inInfoPtr);
	// ���������ǰ����״̬�ĺ���ָ�룬��ȡ����Ƿ���������
	void SetSoftRunningStatePtr(std::function<bool(void)> inRuningStatePtr);
private:
	std::function<std::vector<AllThreshold>(void)> m_AlgoThresholdCallBack;   //��ȡ�㷨����ֵ�Ļص�����   - ����ֵ�����г�ʼ����Ҫ����ģ�͵�Ĭ����ֵ�������ð�ťʱ��Ҫ���㷨���ȡ��ǰ����ֵ
	std::function<std::vector<ViMoModelInfo>(void)> m_AlgoInfoCallBack;       //��ȡ�㷨ģ����Ϣ�Ļص����� - ����ֵ���е�OCRģ��Ϊ2.xʱ������ֵ�༭��
	std::function<bool(void)> m_RunningStateCallBack;                         //��ȡ�������״̬�Ļص����� - �ڵ��ͼ��Դ����ʱ����������������ʾֹͣ����
private:
	Ui::ImageWindowClass ui;
	int *MyWindowIndex;             //��ǰ���ڵ�StaionID
	bool* isShowOkNg;               //��ǰ�����Ƿ���ʾOk/Ng���
	SdkModelType my_ModelType;      //��ǰ���ڵ�ģ������
	cv::Mat m_OriginalImage;        //��ǰ��ʾ��ͼ��ԭͼ
	cv::Mat m_RenderImage;          //��ǰ��ʾ���㷨��Ⱦͼ
	LabelOkNg_Info m_LabelOkNg;     //��ǰͼ�񴰿����Ͻ�Ok/Ng��logo
	QMenu* buttonMenu = nullptr;    //�˵���
private:
	void InintMenu();                       //��ʼ���˵���
	void SetMenuStyleSheet(QMenu* inMenu);  //���ò˵�����ʽ
	void InintResultLabel();                //��ʼ��Ok/Ng��logo
	void InintParameter();
	void InintConnection();
public:
	ThresholdSet *m_ThresholdSetDialg = nullptr; //��ǰ��ͼ���������ö���
	ImageSourceBase *m_ImgSourcePtr = nullptr;	 //��ǰͼ��Դ����󣬴�MyStaion����
	ModelConfigDialg *m_configDialg = nullptr;   //��ǰ�㷨�������ö���
protected:
	virtual void resizeEvent(QResizeEvent *event) override; //��ͼ�񴰿ڱ仯ʱ��������Ok/Ng logo�Ŀ��
public slots:
	void SetCameraStateSlot(bool isOpen);   //���״̬�ı�ۺ��� - �������logo��ʽ
	void ImageSourceSlot();             //�˵��������ͼ��Դ���òۺ���
	void ModelChoiceSlot();             //�˵���������㷨�������òۺ���
	void ThresholdSetSlot();            //�˵����������ͼ�������òۺ���
	void SetShowImageSlot(cv::Mat& m_OriginalImages, cv::Mat& m_RenderImages, bool bOK, double Time); //�����㷨����źŵ���ʾ��Ⱦͼ�ۺ���
	void GetModelChoiceSlot(ModelChoice);                  //���㷨������������"ȷ��"��ť��Ӧ�Ĳۺ���
	void AlgoStatusChangleSlot(bool);                      //���㷨��ʼ��������Ӧ�Ĳۺ��� - ���ݽ���޸��㷨logo��ʽ
	void ShowRenderFlagSlot();                             //�������"��ȾЧ��"��checkBox��ѡ�򣬶�Ӧ��ʾԭͼ����Ⱦͼ
	void MenuBtnSlot(const QPoint &pos);
signals:
	void SendModelConfig(ModelChoice);			  //�����㷨������ƽ�������ȷ����ť
signals:
	void SendThreshold();                         //������ֵ��������ȷ����ť
signals:
	void ChangeImageSourceBase(ImageSourceBase*); //��ͼ��Դ�����е��ȷ����ť���͵�ͼ��Դ���������ź�
signals:
	void AddWindowSignal();  //��Ӵ����ź�
signals:
	void SendCloseEvent(int);//ɾ�������ź�
};
