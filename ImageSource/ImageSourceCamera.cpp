#include "ImageSourceCamera.h"
#include "components/Config/ConfigProgramme.h"
#include "components/Camera/SoftTriggerConnect.h"
QString camera1 = "head";
QString camera2 = "end";
ImageSourceCamera::ImageSourceCamera()
{
	// 创建相机对象
	m_camera = new CameraHikvision;
	connect(m_camera, &Camera::connectStatusChanged, this, [=]() { m_camera->IsOpened() ? emit CameraStateChange(true) : emit CameraStateChange(false); });
	connect(m_camera, &Camera::imageReady, this, &ImageSourceCamera::ConnectImage);
}

ImageSourceCamera::~ImageSourceCamera()
{
	// 销毁相机资源
	if (m_camera != nullptr)
	{
		if (m_camera->IsOpened()) m_camera->CloseCamera();
		delete m_camera;
		m_camera = nullptr;
	}
}

void ImageSourceCamera::ConnectImage(cv::Mat inMat)
{
	emit ImageReady(inMat);
}

QWidget* ImageSourceCamera::OpenSettingDialg()
{
	m_SettingDialg = new ImageSourceCameraSetting(m_Station, this);
	return m_SettingDialg;
}

Camera * ImageSourceCamera::getCameraPtr()
{
	return m_camera;
}

void ImageSourceCamera::initCamera(int windowsIndex)
{
	QList<QString> CameraNames =m_camera->GetCameraList();
	for (auto info : CameraNames)
	{
		if (info.contains(QString::fromLocal8Bit("end"))&& windowsIndex==2)
		{
			m_camera->OpenCamera(info);
		}
		else if (info.contains(QString::fromLocal8Bit("head"))&& windowsIndex == 1)
		{
			m_camera->OpenCamera(info);
		}
	}
}



bool ImageSourceCamera::isCanStart()
{
	bool isOpen = false;
	if (m_camera->IsOpened())
	{
		isOpen = true;
	}
	else
	{
		QList<QString> CameraNames = m_camera->GetCameraList();
		if (CameraNames.size() != 0)
		{
			m_camera->OpenCamera(ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.name);
			if (m_camera->IsOpened())
			{		
				m_camera->SetEnumParamValue(Camera::TriggerMode, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerMode);
				m_camera->SetEnumParamValue(Camera::TriggerSource, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource);
				m_camera->SetNumParamValue(Camera::ExposureTime, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.exposure);
				m_camera->SetNumParamValue(Camera::Gain, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.gain);
				isOpen = true;
			}
		}
	}
	return isOpen;
}

bool ImageSourceCamera::Start()
{
	bool isOpen = false;
	if (m_camera->IsOpened())
	{
		isOpen = true;
		QString triggerMode = ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerMode;
		QString triggerSource = ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource;
		m_camera->GrabContinuous();
	}
	else
	{
		QList<QString> CameraNames = m_camera->GetCameraList();
		if (CameraNames.size() != 0)
		{
			m_camera->OpenCamera(ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.name);
			if (m_camera->IsOpened())
			{
				isOpen = true;
				m_camera->SetEnumParamValue(Camera::TriggerMode, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerMode);
				m_camera->SetEnumParamValue(Camera::TriggerSource, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource);
				m_camera->SetNumParamValue(Camera::ExposureTime, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.exposure);
				m_camera->SetNumParamValue(Camera::Gain, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.gain);
				m_camera->GrabContinuous();
			}
		}
	}
	return isOpen;
}

bool ImageSourceCamera::SingleGrab()
{
	bool isGrab = false;
	if (m_camera->IsOpened())
	{
		m_camera->GrabSingle();
		isGrab = true;
	}
	else
	{
		QList<QString> CameraNames = m_camera->GetCameraList();
		if (CameraNames.size() != 0)
		{
			m_camera->OpenCamera(ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.name);
			if (m_camera->IsOpened())
			{
				m_camera->SetEnumParamValue(Camera::TriggerMode, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerMode);
				m_camera->SetEnumParamValue(Camera::TriggerSource, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource);
				m_camera->SetNumParamValue(Camera::ExposureTime, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.exposure);
				m_camera->SetNumParamValue(Camera::Gain, ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.gain);
				m_camera->GrabSingle();
				isGrab = true;
			}
		}
	}
	return isGrab;
}

void ImageSourceCamera::Stop()
{
	if (m_camera->IsOpened())
	{
		m_camera->GrabStop();
	}
}

bool ImageSourceCamera::BtnSave()
{
	if (m_SettingDialg != nullptr)
	{
		m_SettingDialg->BtnClickedSave();
	}
	//当前选择的相机图像源，保存到单例的配置信息中
	ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.ImageSource_isCamera = true;
	return true;
}

void ImageSourceCamera::InintFromConfig(ImageSourceConfig inConfig)
{
	QList<QString> CameraNames = m_camera->GetCameraList();
	if (CameraNames.size() != 0)
	{
		m_camera->OpenCamera(inConfig.m_CameraInfo.name);
		if (m_camera->IsOpened())
		{
			m_camera->SetEnumParamValue(Camera::TriggerMode, inConfig.m_CameraInfo.triggerMode);
			m_camera->SetEnumParamValue(Camera::TriggerSource, inConfig.m_CameraInfo.triggerSource);
			m_camera->SetNumParamValue(Camera::ExposureTime, inConfig.m_CameraInfo.exposure);
			m_camera->SetNumParamValue(Camera::Gain, inConfig.m_CameraInfo.gain);
			if (inConfig.m_CameraInfo.triggerSource == "Software" && inConfig.m_CameraInfo.triggerMode == "On")
			{
				if (ConfigProgramme::GetInstance()->m_Comunicate.contains(inConfig.m_CameraInfo.SoftTrigerCommunication))
				{
					CommunicateBase* m_CommunicateBase = ConfigProgramme::GetInstance()->m_Comunicate[inConfig.m_CameraInfo.SoftTrigerCommunication];
					SoftTriggerConnect::GetInstance()->Binding(m_camera, m_CommunicateBase, inConfig.m_CameraInfo.GrabStr);
					//m_camera->GrabContinuous();
				}
			}
		}
	}
}
