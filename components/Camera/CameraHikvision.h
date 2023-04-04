#pragma once


#include "Camera.h"
#include <MvCameraControl.h>
#include "Camera.h"

class CameraHikvision : public Camera
{
	Q_OBJECT

public:
	CameraHikvision();
	~CameraHikvision();
	//����������
	QString errMsg(int nRet);
public:
	virtual void Init() override;
	//ö�����
	virtual int EnumerateDevices() override;
	//��ȡ����б�
	virtual QList<QString> GetCameraList() override;
	//�����
	virtual void OpenCamera(QString cameraName) override;
	//����Ƿ��
	virtual bool IsOpened() override;
	//����Ƿ��ڲ�ͼ״̬
	virtual bool IsGrabbing() override;
	//�Ƿ�֧�ֵ�֡��ͼģʽ
	virtual bool IsSingleShotSupported() override;
	//������֡��ͼ
	virtual cv::Mat GrabSingle() override;
	//����������ͼ
	virtual void GrabContinuous() override;
	//����������ͼ
	virtual void GrabStop() override;
	//�ر����
	virtual void CloseCamera() override;
	//���õ�ǰΪ���ɲɼ�ģʽ
	virtual void SetFreeRunGrab() override;
	//���õ�ǰΪӲ����ģʽ
	virtual void SetHardwareGrab(QString hardWareName) override;
	//���õ�ǰΪ����ģʽ
	virtual void SetSoftwareGrab() override;
	//��ȡ��ֵ���Ͳ�����Χ
	virtual void GetNumParamRange(ParamName paramName, int& min, int& max) override;
	//��ȡ��ֵ���Ͳ�����ֵ
	virtual int GetNumParamValue(ParamName paramName) override;
	//������ֵ���Ͳ�����ֵ
	virtual void SetNumParamValue(ParamName paramName, int value) override;
	//��ȡö�����Ͳ�����ȡֵ��Χ
	virtual QList<QString> GetEnumParamRange(ParamName paramName) override;
	//����ö�����Ͳ�����ֵ
	virtual void SetEnumParamValue(ParamName paramName, QString value) override;
	//��ȡö�����Ͳ�����ֵ
	virtual QString GetEnumParamValue(ParamName paramName) override;
	//����һ��
	virtual void Trigger() override;
	//��ȡ��ǰѡ�е��������
	virtual QString GetCurrentCameraName() override;
	//����ͼ���ʽת��ΪOpencvͼ���ʽ
	cv::Mat convertToMat(unsigned char * pData, MV_FRAME_OUT_INFO_EX * pFrameInfo);
private:
	//������
	void* m_handle;
	/*ch:״̬ | en:Status*/
	bool  m_isGrabbing;							// ch:�Ƿ�ʼץͼ | en:Whether to start grabbing
	int   m_nTriggerMode;                       // ch:����ģʽ | en:Trigger Mode
	int   m_nTriggerSource;                     // ch:����Դ | en:Trigger Source

	/*ch:�豸��� | en:Device Related*/
	MV_CC_DEVICE_INFO_LIST m_stDevList;         // ch:�豸��Ϣ�б�ṹ������������洢�豸�б� | en:Device information list structure variable used to store device list

	unsigned char*  m_pGrabBuf;            // ch:���ڴ�������ȡͼ��Ļ��� | en:Buffer to get image from driver
	unsigned int    m_nGrabBufSize;

	// Will be set to toggle image processing on or off.
	bool m_invertImage;
	// Protects the converted bitmap.
	std::mutex m_bmpLock;

	cv::Mat m_mat;
};


