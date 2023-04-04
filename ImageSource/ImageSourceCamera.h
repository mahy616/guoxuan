#pragma once
#include "ImageSouceBase.h"
#include "ImageSourceCameraSetting.h"

class ImageSourceCamera : public ImageSourceBase
{
public:
	ImageSourceCamera();
	~ImageSourceCamera();
	//��ǰͼ��Դ�Ƿ���ͼ�������
	virtual bool isCanStart() override;
	//�������� - ����ȡͼ
	virtual bool Start() override;
	//ֹͣ���� - ֹͣȡͼ
	virtual void Stop() override;
	//����ִ�� - ץһ��ͼ
	virtual bool SingleGrab() override;
	//���浱ǰͼ��Դ������
	virtual bool BtnSave() override;
	//�������ļ���ʼ����ǰͼ��Դ - ���ط���ʱ����
	virtual void InintFromConfig(ImageSourceConfig inConfig) override;
	//��ͼ��Դ�����ý���
	virtual QWidget* OpenSettingDialg() override;
	Camera * getCameraPtr();
	void initCamera(int windowsIndex);
public slots:
	void ConnectImage(cv::Mat);
private:
	friend class ImageSourceCameraSetting; //����camera
private:
	ImageSourceCameraSetting *m_SettingDialg = nullptr;
	Camera *m_camera = nullptr; 
};

