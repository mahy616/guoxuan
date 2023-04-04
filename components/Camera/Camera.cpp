#include "Camera.h"
#include <qdebug.h>

using namespace cv;
using namespace std;

Camera::Camera()
    : QThread(nullptr)
{
}

Camera::~Camera()
{
	qDebug() << "Camera Destroyed";
}

void Camera::onTrigger()
{
	if (IsOpened() && IsGrabbing())
	{
		qDebug() << "Camera triggered";
		Trigger();
	}
}

CameraFactory* CameraFactory::Instance()
{
	static CameraFactory factory;
	return &factory;
}

Camera* CameraFactory::Create(std::string cameraName)
{
	if (m_funcMap.find(cameraName) == m_funcMap.end()) return nullptr;
	return (Camera*)m_funcMap[cameraName]();
}

std::list<std::string> CameraFactory::CameraList()
{
	std::list<std::string> list;
	for (auto pair : m_funcMap)
	{
		list.push_back(pair.first);
	}
	return list;
}

void CameraFactory::Register(std::string cameraName, createCameraFun && func)
{
	qDebug() << "Register " << cameraName.c_str();
	m_funcMap[cameraName] = func;
}

