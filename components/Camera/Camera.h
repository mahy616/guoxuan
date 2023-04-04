#pragma once
#include <QObject>
#include <opencv.hpp>
#include <QThread>

class Camera : public QThread
{
	Q_OBJECT

public:
	enum ParamName { ExposureTime, Gain, PixelFormat, TriggerMode, TriggerSource };
	Camera();
	virtual ~Camera();
	//初始化工作
	virtual void Init() = 0;
	//枚举相机
	virtual int EnumerateDevices() = 0;
	//获取相机列表
	virtual QList<QString> GetCameraList() = 0;
	//打开相机
	virtual void OpenCamera(QString) = 0;
	//相机是否打开
	virtual bool IsOpened() = 0;
	//相机是否在采图
	virtual bool IsGrabbing() = 0;
	//是否支持单帧采图模式
	virtual bool IsSingleShotSupported() = 0;
	//启动单帧采图
	virtual cv::Mat GrabSingle() = 0;
	//启动连续采图
	virtual void GrabContinuous() = 0;
	//停止采图
	virtual void GrabStop() = 0;
	//关闭相机
	virtual void CloseCamera() = 0;
	//设置当前为自由采集模式
	virtual void SetFreeRunGrab() = 0;
	//设置当前为硬触发模式
	virtual void SetHardwareGrab(QString hardWareName) = 0;
	//设置当前为软触发模式
	virtual void SetSoftwareGrab() = 0;
	//数值类参数
	virtual void GetNumParamRange(ParamName paramName, int& min, int& max) = 0;
	virtual int GetNumParamValue(ParamName paramName) = 0;
	virtual void SetNumParamValue(ParamName paramName, int value) = 0;
	//枚举类参数
	virtual QList<QString> GetEnumParamRange(ParamName paramName) = 0;
	virtual QString GetEnumParamValue(ParamName paramName) = 0;
	virtual void SetEnumParamValue(ParamName paramName, QString value) = 0;
	//触发一次
	virtual void Trigger() = 0;
	//获取当前选中的相机名称
	virtual QString GetCurrentCameraName() = 0;
signals:
	void imageReady(cv::Mat);
	void connectStatusChanged();
	void grabStatusChanged();
	void cameraError(QString);
	void paramUpdated(Camera::ParamName);
private slots:
	void onTrigger();
protected:
	QList<QString> m_cameraNameList;
	QList<QString> m_pixelFormatList;
	QList<QString> m_triggerModeList;
	QList<QString> m_triggerSourceList;
	QString m_currentCameraName;
};

#define REGISTER_CAMERA(ClassName,CameraName)\
static RegisterCameraAction register_class_##ClassName(CameraName, []() {return new ClassName(); });

typedef std::function<void*(void)> createCameraFun;

class CameraFactory
{
public:
	static CameraFactory* Instance();
	~CameraFactory() = default;
	Camera* Create(std::string cameraName);
	std::list<std::string> CameraList();
	void Register(std::string cameraName, createCameraFun &&func);
private:
	CameraFactory() = default;
	std::map<std::string, createCameraFun> m_funcMap;
};

class RegisterCameraAction
{
public:
	RegisterCameraAction(const std::string &cameraName, createCameraFun && generator)
	{
		CameraFactory::Instance()->Register(cameraName, std::forward<createCameraFun>(generator));
	}
};

