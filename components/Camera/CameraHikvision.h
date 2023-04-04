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
	//错误代码解析
	QString errMsg(int nRet);
public:
	virtual void Init() override;
	//枚举相机
	virtual int EnumerateDevices() override;
	//获取相机列表
	virtual QList<QString> GetCameraList() override;
	//打开相机
	virtual void OpenCamera(QString cameraName) override;
	//相机是否打开
	virtual bool IsOpened() override;
	//相机是否处于采图状态
	virtual bool IsGrabbing() override;
	//是否支持单帧采图模式
	virtual bool IsSingleShotSupported() override;
	//启动单帧采图
	virtual cv::Mat GrabSingle() override;
	//启动连续采图
	virtual void GrabContinuous() override;
	//启动连续采图
	virtual void GrabStop() override;
	//关闭相机
	virtual void CloseCamera() override;
	//设置当前为自由采集模式
	virtual void SetFreeRunGrab() override;
	//设置当前为硬触发模式
	virtual void SetHardwareGrab(QString hardWareName) override;
	//设置当前为软触发模式
	virtual void SetSoftwareGrab() override;
	//获取数值类型参数范围
	virtual void GetNumParamRange(ParamName paramName, int& min, int& max) override;
	//获取数值类型参数的值
	virtual int GetNumParamValue(ParamName paramName) override;
	//设置数值类型参数的值
	virtual void SetNumParamValue(ParamName paramName, int value) override;
	//获取枚举类型参数的取值范围
	virtual QList<QString> GetEnumParamRange(ParamName paramName) override;
	//设置枚举类型参数的值
	virtual void SetEnumParamValue(ParamName paramName, QString value) override;
	//获取枚举类型参数的值
	virtual QString GetEnumParamValue(ParamName paramName) override;
	//触发一次
	virtual void Trigger() override;
	//获取当前选中的相机名称
	virtual QString GetCurrentCameraName() override;
	//海康图像格式转化为Opencv图像格式
	cv::Mat convertToMat(unsigned char * pData, MV_FRAME_OUT_INFO_EX * pFrameInfo);
private:
	//相机句柄
	void* m_handle;
	/*ch:状态 | en:Status*/
	bool  m_isGrabbing;							// ch:是否开始抓图 | en:Whether to start grabbing
	int   m_nTriggerMode;                       // ch:触发模式 | en:Trigger Mode
	int   m_nTriggerSource;                     // ch:触发源 | en:Trigger Source

	/*ch:设备相关 | en:Device Related*/
	MV_CC_DEVICE_INFO_LIST m_stDevList;         // ch:设备信息列表结构体变量，用来存储设备列表 | en:Device information list structure variable used to store device list

	unsigned char*  m_pGrabBuf;            // ch:用于从驱动获取图像的缓存 | en:Buffer to get image from driver
	unsigned int    m_nGrabBufSize;

	// Will be set to toggle image processing on or off.
	bool m_invertImage;
	// Protects the converted bitmap.
	std::mutex m_bmpLock;

	cv::Mat m_mat;
};


