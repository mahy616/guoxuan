#pragma once
#include <QObject>
#include <QWidget>
#include "MyStation.h"
#include "components/Camera/Camera.h"
#include "PublicParamter.h"

class ImageSourceBase : public QObject
{
	Q_OBJECT
public: 
	virtual bool isCanStart() = 0; //��ǰͼ��Դ�Ƿ���ͼ�������
	virtual bool Start() = 0;      //�������� - ����ȡͼ
	virtual void Stop() = 0;       //ֹͣ���� - ֹͣȡͼ
	virtual bool SingleGrab() = 0; //����ִ�� - ץһ��ͼ
	virtual bool BtnSave() = 0;    //���浱ǰͼ��Դ������
	virtual void InintFromConfig(ImageSourceConfig inConfig) = 0;  //�������ļ���ʼ����ǰͼ��Դ - ���ط���ʱ����
	virtual QWidget* OpenSettingDialg() = 0;                       //��ͼ��Դ�����ý���
public:
	void SetMyPtr(MyStation* inStation);    //��MyStationָ�봫��
	MyStation* GetMyPtr();                  //��ȡ����󶨵�stationָ��
	bool isCameraSource();                  //��ȡ��ǰ��ͼ��Դ���ͣ�����������ļ��У�
protected:
	MyStation* m_Station;
signals:
	void ImageReady(cv::Mat);          //��ȡ����ͼ��(���ͼ��Դͨ�����źŽ����ͼ�񴫸�MyStation)
signals:
	void CameraStateChange(bool isOk); //��ǰ���ͼ��Դ�Ƿ��
};
