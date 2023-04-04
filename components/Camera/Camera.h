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
	//��ʼ������
	virtual void Init() = 0;
	//ö�����
	virtual int EnumerateDevices() = 0;
	//��ȡ����б�
	virtual QList<QString> GetCameraList() = 0;
	//�����
	virtual void OpenCamera(QString) = 0;
	//����Ƿ��
	virtual bool IsOpened() = 0;
	//����Ƿ��ڲ�ͼ
	virtual bool IsGrabbing() = 0;
	//�Ƿ�֧�ֵ�֡��ͼģʽ
	virtual bool IsSingleShotSupported() = 0;
	//������֡��ͼ
	virtual cv::Mat GrabSingle() = 0;
	//����������ͼ
	virtual void GrabContinuous() = 0;
	//ֹͣ��ͼ
	virtual void GrabStop() = 0;
	//�ر����
	virtual void CloseCamera() = 0;
	//���õ�ǰΪ���ɲɼ�ģʽ
	virtual void SetFreeRunGrab() = 0;
	//���õ�ǰΪӲ����ģʽ
	virtual void SetHardwareGrab(QString hardWareName) = 0;
	//���õ�ǰΪ����ģʽ
	virtual void SetSoftwareGrab() = 0;
	//��ֵ�����
	virtual void GetNumParamRange(ParamName paramName, int& min, int& max) = 0;
	virtual int GetNumParamValue(ParamName paramName) = 0;
	virtual void SetNumParamValue(ParamName paramName, int value) = 0;
	//ö�������
	virtual QList<QString> GetEnumParamRange(ParamName paramName) = 0;
	virtual QString GetEnumParamValue(ParamName paramName) = 0;
	virtual void SetEnumParamValue(ParamName paramName, QString value) = 0;
	//����һ��
	virtual void Trigger() = 0;
	//��ȡ��ǰѡ�е��������
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

