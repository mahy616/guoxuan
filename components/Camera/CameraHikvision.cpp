

#include "CameraHikvision.h"
#include <opencv.hpp>
#include <qdebug.h>
#include <process.h>
#include <functional>
#include <Windows.h>
//#include <QMessageBox>
using namespace std;
using namespace cv;

#ifndef MV_NULL
#define MV_NULL    0
#endif

void __stdcall ImageCallBackEx(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser);
QString pixelFormatTranslator(int value);
QString triggerModeTranslator(int value);
QString triggerSourceTranslator(int value);

CameraHikvision::CameraHikvision()
	: Camera()
	, m_handle(NULL)
	, m_isGrabbing(false)
	, m_pGrabBuf(NULL)
{
	Init();
	EnumerateDevices();
}

CameraHikvision::~CameraHikvision()
{
	if (IsOpened())
		CloseCamera();
}

QString CameraHikvision::errMsg(int nRet)
{
	switch (nRet)
	{
	case MV_E_HANDLE: return QString::fromLocal8Bit("错误或无效的句柄 (Error or invalid handle)");
	case MV_E_SUPPORT:return QString::fromLocal8Bit("不支持的功能 (Not supported function)");
	case MV_E_BUFOVER:return QString::fromLocal8Bit("缓存已满 (Buffer overflow)");
	case MV_E_CALLORDER:return QString::fromLocal8Bit("函数调用顺序错误 (Function calling order error)");
	case MV_E_PARAMETER:return QString::fromLocal8Bit("错误的参数 (Incorrect parameter)");
	case MV_E_RESOURCE:return QString::fromLocal8Bit("资源申请失败 (Applying resource failed)");
	case MV_E_NODATA:return QString::fromLocal8Bit("无数据 (No data)");
	case MV_E_PRECONDITION:return QString::fromLocal8Bit("前置条件有误，或运行环境已发生变化 (Precondition error, or running environment changed)");
	case MV_E_VERSION:return QString::fromLocal8Bit("版本不匹配 (Version mismatches)");
	case MV_E_NOENOUGH_BUF:return QString::fromLocal8Bit("传入的内存空间不足 (Insufficient memory)");
	case MV_E_ABNORMAL_IMAGE:return QString::fromLocal8Bit("异常图像，可能是丢包导致图像不完整 (Abnormal image, maybe incomplete image because of lost packet)");
	case MV_E_LOAD_LIBRARY:return QString::fromLocal8Bit("动态导入DLL失败 (Load library failed)");
	case MV_E_NOOUTBUF:return QString::fromLocal8Bit("没有可输出的缓存 (No Avaliable Buffer)");
	case MV_E_ENCRYPT:return QString::fromLocal8Bit("加密错误 (Encryption error)");
	case MV_E_UNKNOW:return QString::fromLocal8Bit("未知的错误 (Unknown error)");
	case MV_E_GC_GENERIC:return QString::fromLocal8Bit("通用错误 (General error)");
	case MV_E_GC_ARGUMENT:return QString::fromLocal8Bit("参数非法 (Illegal parameters)");
	case MV_E_GC_RANGE:return QString::fromLocal8Bit("值超出范围 (The value is out of range)");
	case MV_E_GC_PROPERTY:return QString::fromLocal8Bit("属性 (Property)");
	case MV_E_GC_RUNTIME:return QString::fromLocal8Bit("运行环境有问题 (Running environment error)");
	case MV_E_GC_LOGICAL:return QString::fromLocal8Bit("逻辑错误 (Logical error)");
	case MV_E_GC_ACCESS:return QString::fromLocal8Bit("节点访问条件有误 (Node accessing condition error)");
	case MV_E_GC_TIMEOUT:return QString::fromLocal8Bit("超时 (Timeout)");
	case MV_E_GC_DYNAMICCAST:return QString::fromLocal8Bit("转换异常 (Transformation exception)");
	case MV_E_GC_UNKNOW:return QString::fromLocal8Bit("GenICam未知错误 (GenICam unknown error)");
	case MV_E_NOT_IMPLEMENTED:return QString::fromLocal8Bit("命令不被设备支持 (The command is not supported by device)");
	case MV_E_INVALID_ADDRESS:return QString::fromLocal8Bit("访问的目标地址不存在 (english The target address being accessed does not exist)");
	case MV_E_WRITE_PROTECT:return QString::fromLocal8Bit("目标地址不可写 (The target address is not writable)");
	case MV_E_ACCESS_DENIED:return QString::fromLocal8Bit("设备无访问权限 (No permission)");
	case MV_E_BUSY:return QString::fromLocal8Bit("设备忙，或网络断开 (Device is busy, or network disconnected)");
	case MV_E_PACKET:return QString::fromLocal8Bit("网络包数据错误 (Network data packet error)");
	case MV_E_NETER:return QString::fromLocal8Bit("网络相关错误 (Network error)");
	case MV_E_IP_CONFLICT:return QString::fromLocal8Bit("设备IP冲突 (Device IP conflict)");
	case MV_E_USB_READ:return QString::fromLocal8Bit("读usb出错 (Reading USB error)");
	case MV_E_USB_WRITE:return QString::fromLocal8Bit("写usb出错 (Writing USB error)");
	case MV_E_USB_DEVICE:return QString::fromLocal8Bit("设备异常 (Device exception)");
	case MV_E_USB_GENICAM:return QString::fromLocal8Bit("GenICam相关错误 (GenICam error)");
	case MV_E_USB_BANDWIDTH:return QString::fromLocal8Bit("带宽不足  该错误码新增 (Insufficient bandwidth, this error code is newly added)");
	case MV_E_USB_DRIVER:return QString::fromLocal8Bit("驱动不匹配或者未装驱动 (Driver mismatch or unmounted drive)");
	case MV_E_USB_UNKNOW:return QString::fromLocal8Bit("USB未知的错误 (USB unknown error)");
	case MV_E_UPG_FILE_MISMATCH:return QString::fromLocal8Bit("升级固件不匹配 (Firmware mismatches)");
	case MV_E_UPG_LANGUSGE_MISMATCH:return QString::fromLocal8Bit("升级固件语言不匹配 (Firmware language mismatches)");
	case MV_E_UPG_CONFLICT:return QString::fromLocal8Bit("升级冲突（设备已经在升级了再次请求升级即返回此错误）(Upgrading conflicted (repeated upgrading requests during device upgrade))");
	case MV_E_UPG_INNER_ERR:return QString::fromLocal8Bit("升级时设备内部出现错误 (Camera internal error during upgrade)");
	case MV_E_UPG_UNKNOW:return QString::fromLocal8Bit("升级时未知错误 (Unknown error during upgrade)");
	}
	return QString("海康相机未知错误");
}

void CameraHikvision::Init()
{
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
}

// Helper function to get a list of all attached devices and store it in m_devices.
int CameraHikvision::EnumerateDevices()
{
	// ch:枚举设备 | Enum device
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);
	if (MV_OK != nRet || m_stDevList.nDeviceNum == 0)
	{
		emit cameraError("Enum Devices fail!");
		return 0;
	}
	return  m_stDevList.nDeviceNum;
}

QList<QString> CameraHikvision::GetCameraList()
{
	// Remove all items from the combo box.
	QList<QString> list;

	// ch:将值加入到信息列表框中并显示出来 | en:Add value to the information list box and display
	for (unsigned int i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
		if (NULL == pDeviceInfo)
		{
			continue;
		}

		QString deviceName;
		if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
		{
			int nIp1 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
			int nIp2 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
			int nIp3 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
			int nIp4 = (m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

			auto userDefinedName = (char*)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName);
			if (strcmp("", userDefinedName) != 0)
			{
				deviceName = tr(userDefinedName);
			}
			else
			{
				char strUserName[256] = { 0 };
				sprintf_s(strUserName, "%s %s (%s)", pDeviceInfo->SpecialInfo.stGigEInfo.chManufacturerName,
					pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
					pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);
				deviceName = tr(strUserName);
			}
			deviceName = QString("[%1]GigE: %2(%3.%4.%5.%6)").arg(i).arg(deviceName).arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);
		}
		else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
		{
			auto userDefinedName = (char*)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName);
			if (strcmp("", userDefinedName) != 0)
			{
				deviceName = tr(userDefinedName);
			}
			else
			{
				char strUserName[256];
				sprintf_s(strUserName, "%s %s (%s)", pDeviceInfo->SpecialInfo.stUsb3VInfo.chManufacturerName,
					pDeviceInfo->SpecialInfo.stUsb3VInfo.chModelName,
					pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);
				deviceName = tr(strUserName);
			}
			deviceName = QString("[%1]USB_V3: %2").arg(i).arg(deviceName);
		}
		else
		{
			emit cameraError("Unknown device enumerated");
		}
		list.push_back(deviceName);
	}
	return list;
}

void CameraHikvision::OpenCamera(QString cameraName)
{
	if (IsOpened())
	{
		emit cameraError("Camera aready opened!");
		return;
	}
	int nIndex = GetCameraList().indexOf(cameraName);
	if ((nIndex < 0) | (nIndex >= MV_MAX_DEVICE_NUM))
	{
		emit cameraError("Please select device");
		return;
	}
	if (NULL == m_stDevList.pDeviceInfo[nIndex])
	{
		emit cameraError("Device does not exist");
		return;
	}

	// ch:选择设备并创建句柄 | Select device and create handle
	int nRet = MV_CC_CreateHandle(&m_handle, m_stDevList.pDeviceInfo[nIndex]);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Create Handle fail![%1]").arg(nRet));
		return;
	}

	// ch:打开设备 | Open device
	nRet = MV_CC_OpenDevice(m_handle);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Open Device fail!\n%1").arg(errMsg(nRet)));
		return;
	}
	m_currentCameraName = cameraName;
	// ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
	if (m_stDevList.pDeviceInfo[nIndex]->nTLayerType == MV_GIGE_DEVICE)
	{
		int nPacketSize = MV_CC_GetOptimalPacketSize(m_handle);
		if (nPacketSize > 0)
		{
			nRet = MV_CC_SetIntValue(m_handle, "GevSCPSPacketSize", nPacketSize);
			if (nRet != MV_OK)
			{
				emit cameraError("Warning: Set Packet Size fail!");
			}
		}
		else
		{
			emit cameraError("Warning: Get Packet Size fail!");
		}
	} 
	
	
	// Set trigger mode as off
	nRet = MV_CC_SetEnumValue(m_handle, "TriggerMode", 0);

	//初始化图像缓存区
	MVCC_INTVALUE_EX stIntValue = { 0 };
	nRet = MV_CC_GetIntValueEx(m_handle, "PayloadSize", &stIntValue);
	if (nRet != MV_OK)
	{
		emit cameraError("failed in get PayloadSize");
		return;
	}
	unsigned int nDataSize = (unsigned int)stIntValue.nCurValue;
	if (NULL == m_pGrabBuf || nDataSize > m_nGrabBufSize)
	{
		if (m_pGrabBuf)
		{
			free(m_pGrabBuf);
			m_pGrabBuf = NULL;
		}

		m_pGrabBuf = (unsigned char *)malloc(sizeof(unsigned char) * nDataSize);
		if (m_pGrabBuf == NULL)
		{
			return;
		}
		m_nGrabBufSize = nDataSize;
	}
	emit connectStatusChanged();
}

bool CameraHikvision::IsOpened()
{
	if (m_handle == NULL) return false;
	return MV_CC_IsDeviceConnected(m_handle);
}

bool CameraHikvision::IsGrabbing()
{
	qDebug() << "isGrabbing=" << m_isGrabbing;
	return m_isGrabbing;
}

bool CameraHikvision::IsSingleShotSupported()
{
	return true;
}

cv::Mat CameraHikvision::GrabSingle()
{
	bool ModelChangeFlag = false;
	if (GetEnumParamValue(Camera::TriggerMode) != "Off")	ModelChangeFlag = true;

	int nRet = MV_CC_SetEnumValue(m_handle, "TriggerMode", 0);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
		return Mat();
	}
	MV_FRAME_OUT_INFO_EX stImageInfo;
	memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
	unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * (m_nGrabBufSize));
	MV_CC_StartGrabbing(m_handle);
	nRet = MV_CC_GetOneFrameTimeout(m_handle, pData, m_nGrabBufSize, &stImageInfo, 1000);
	if (nRet != MV_OK)
	{
		emit cameraError(QString("GrabSingle failed!\n%1").arg(errMsg(nRet)));
		return Mat();
	}
	Mat image = convertToMat(pData, &stImageInfo);
	emit imageReady(image);
	MV_CC_StopGrabbing(m_handle);
	if (ModelChangeFlag)
	{
		int nRet2 = MV_CC_SetEnumValue(m_handle, "TriggerMode", 1);
		if (MV_OK != nRet2) emit cameraError(QString("GrabSingle failed!\n%1").arg(errMsg(nRet)));
	}
	return image;
}

void CameraHikvision::GrabContinuous()
{ 
	// ch:注册抓图回调 | en:Register image callback
	int nRet = MV_CC_RegisterImageCallBackEx(m_handle, ImageCallBackEx, this);
	if (MV_OK != nRet)
	{
		emit cameraError("Register Image CallBack fail!\n");
		return;
	}
	// ch:开始取流 | en:Start grab image
	nRet = MV_CC_StartGrabbing(m_handle);
	if (MV_OK != nRet)
	{
		emit cameraError("Start Grabbing fail!\n");
		return;
	}
	m_isGrabbing = true;
	emit grabStatusChanged();
}

void CameraHikvision::GrabStop()
{
	// ch:停止取流 | en:Stop grab image
	if (m_isGrabbing)
	{
		int nRet = MV_CC_StopGrabbing(m_handle);
		if (MV_OK != nRet)
		{
			emit cameraError("Stop Grabbing fail!");
		}
		m_isGrabbing = false;
		emit grabStatusChanged();

		nRet = MV_CC_RegisterImageCallBackEx(m_handle, nullptr, this);
		if (MV_OK != nRet)
		{
			emit cameraError("Register Image CallBack fail!\n");
			return;
		}
	}
}

void CameraHikvision::CloseCamera()
{
	if (IsGrabbing()) GrabStop();
	if (MV_NULL == m_handle)
	{
		emit cameraError("Close Device fail!");
		return;
	}
	// ch:关闭设备 | en:Close device
	int nRet = MV_CC_CloseDevice(m_handle);
	if (MV_OK != nRet)
	{
		emit cameraError("Close Device fail!");
		m_handle = MV_NULL;
		return;
	}
	// ch:销毁句柄 | en:Destroy handle
	nRet = MV_CC_DestroyHandle(m_handle);
	if (MV_OK != nRet)
	{
		emit cameraError("Destroy Handle fail!");
		m_handle = MV_NULL;
		return;
	}
	m_handle = MV_NULL;
	emit connectStatusChanged();
	m_currentCameraName = "";
}

void CameraHikvision::GetNumParamRange(ParamName paramName, int & min, int & max)
{
	MVCC_FLOATVALUE value;
	switch (paramName)
	{
	case Camera::ExposureTime:
		MV_CC_GetFloatValue(m_handle, "ExposureTime", &value);
		min = value.fMin;
		max = value.fMax;
		break;
	case Camera::Gain:
		MV_CC_GetFloatValue(m_handle, "Gain", &value);
		min = value.fMin;
		max = value.fMax;
		break;
	default:
		emit cameraError("ParamName out of Range{ExposureTime,Gain}");
		break;
	}
}

int CameraHikvision::GetNumParamValue(ParamName paramName)
{
	MVCC_FLOATVALUE value;
	switch (paramName)
	{
	case Camera::ExposureTime:
		MV_CC_GetFloatValue(m_handle, "ExposureTime", &value);
		return value.fCurValue;
	case Camera::Gain:
		MV_CC_GetFloatValue(m_handle, "Gain", &value);
		return value.fCurValue;
	default:
		emit cameraError("ParamName out of Range{ExposureTime,Gain}");
		break;
	}
	return 0;
}

void CameraHikvision::SetNumParamValue(ParamName paramName, int value)
{
	int ReturnOk;
	switch (paramName)
	{
	case Camera::ExposureTime:
		ReturnOk = MV_CC_SetFloatValue(m_handle, "ExposureTime",value);
		emit paramUpdated(ExposureTime);
		break;
	case Camera::Gain:
		ReturnOk = MV_CC_SetFloatValue(m_handle, "Gain", value);
		emit paramUpdated(Gain);
		break;
	default:
		emit cameraError("ParamName out of Range{ExposureTime,Gain}");
		break;
	}
}

QList<QString> CameraHikvision::GetEnumParamRange(ParamName paramName)
{
	MVCC_ENUMVALUE value;
	function<QString(int)> translator;
	switch (paramName)
	{
	case Camera::PixelFormat:
		MV_CC_GetEnumValue(m_handle, "PixelFormat", &value);
		translator = pixelFormatTranslator;
		break;
	case Camera::TriggerMode:
		MV_CC_GetEnumValue(m_handle, "TriggerMode", &value);
		translator = triggerModeTranslator;
		break;
	case Camera::TriggerSource:
		MV_CC_GetEnumValue(m_handle, "TriggerSource", &value);
		translator = triggerSourceTranslator;
		break;
	default:
		emit cameraError("ParamName out of Range{PixelFormat,TriggerMode,TriggerSource}");
		break;
	}
	QList<QString> range;
	for (int i = 0; i < value.nSupportedNum; i++)
	{
		auto text = translator(value.nSupportValue[i]);
		if (text.isEmpty()) continue;
		if (text == "Software" || text == "Counter0") continue;
		range.push_back(text);
	}
	return range;
}

void CameraHikvision::SetEnumParamValue(ParamName paramName, QString value)
{
	function<QString(int)> translator;
	QString strKey;
	switch (paramName)
	{
	case Camera::PixelFormat:
		translator = pixelFormatTranslator;
		strKey = "PixelFormat";
		break;
	case Camera::TriggerMode:
		translator = triggerModeTranslator;
		strKey = "TriggerMode";
		break;
	case Camera::TriggerSource:
		translator = triggerSourceTranslator;
		strKey = "TriggerSource";
		break;
	default:
		emit cameraError("ParamName out of Range{ExposureTime,Gain}");
		return;
	}
	MVCC_ENUMVALUE curValue; MV_CC_GetEnumValue(m_handle, strKey.toStdString().c_str(), &curValue);
	auto curString = translator(curValue.nCurValue);
	//if (curString != value)
	{
		int a = MV_CC_SetEnumValueByString(m_handle, strKey.toStdString().c_str(), value.toStdString().c_str());
		if (a != 0)
		{
			//QMessageBox::information(nullptr, "tips", QString("MV_CC_SetEnumValueByString fail!\n%1").arg(errMsg(a)));
			emit cameraError(errMsg(a));
		}
		//emit paramUpdated(PixelFormat);
	}
}

QString CameraHikvision::GetEnumParamValue(ParamName paramName)
{
	MVCC_ENUMVALUE value;
	function<QString(int)> translator;
	switch (paramName)
	{
	case Camera::PixelFormat:
		MV_CC_GetEnumValue(m_handle, "PixelFormat", &value);
		translator = pixelFormatTranslator;
		break;
	case Camera::TriggerMode:
		MV_CC_GetEnumValue(m_handle, "TriggerMode", &value);
		translator = triggerModeTranslator;
		break;
	case Camera::TriggerSource:
		MV_CC_GetEnumValue(m_handle, "TriggerSource", &value);
		translator = triggerSourceTranslator;
		break;
	default:
		emit cameraError("ParamName out of Range{PixelFormat,TriggerMode,TriggerSource}");
		return "";
	}
	return translator(value.nCurValue);
}

void CameraHikvision::Trigger()
{
	int nRet = MV_CC_SetCommandValue(m_handle, "TriggerSoftware");
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Send Trigger Software command fail!\n%1").arg(errMsg(nRet)));
	}
	/*int nRet = MV_CC_SetEnumValue(m_handle, "TriggerMode", 0);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
	}
	MV_FRAME_OUT_INFO_EX stImageInfo;
	memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
	unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * (m_nGrabBufSize));
	MV_CC_StartGrabbing(m_handle);
	nRet = MV_CC_GetOneFrameTimeout(m_handle, pData, m_nGrabBufSize, &stImageInfo, 1000);
	if (nRet != MV_OK)
	{
		emit cameraError(QString("GrabSingle failed!\n%1").arg(errMsg(nRet)));
		qDebug() << errMsg(nRet);
		return;
	}
	Mat image = convertToMat(pData, &stImageInfo);
	emit imageReady(image);
	MV_CC_StopGrabbing(m_handle);
	SetEnumParamValue(TriggerMode, "On");
	SetEnumParamValue(TriggerSource, "Software");*/
}

QString CameraHikvision::GetCurrentCameraName()
{
	return m_currentCameraName;
}

cv::Mat CameraHikvision::convertToMat(unsigned char * pData, MV_FRAME_OUT_INFO_EX * pFrameInfo)
{
	cv::Mat img;
	int convert_type;
	int width = pFrameInfo->nWidth;
	int height = pFrameInfo->nHeight;
	switch (pFrameInfo->enPixelType)
	{
	case PixelType_Gvsp_Mono8:
		img.create(height, width, CV_8UC1);
		memcpy(img.data, pData, pFrameInfo->nFrameLen);
		return img;
	case PixelType_Gvsp_BayerRG8:
		img.create(height, width, CV_8UC1);
		convert_type = cv::COLOR_BayerRG2RGB;
		break;
	case PixelType_Gvsp_BayerGB8:
		img.create(height, width, CV_8UC1);
		convert_type = cv::COLOR_BayerGB2RGB;
		break;
	case PixelType_Gvsp_BayerBG8:
		img.create(height, width, CV_8UC1);
		convert_type = cv::COLOR_BayerBG2RGB;
		break;
	case PixelType_Gvsp_YUV422_YUYV_Packed:
		img.create(height, width, CV_8UC2);
		convert_type = cv::COLOR_YUV2RGB_YUYV;
		break;
	default:
		return cv::Mat::zeros(height, width, CV_8UC3);
	}
	memcpy(img.data, pData, pFrameInfo->nFrameLen);
	cv::Mat img_convert; cvtColor(img, img_convert, convert_type);
	return img_convert;
}

void __stdcall ImageCallBackEx(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser)
{
	if (pFrameInfo)
	{
		CameraHikvision *pCam = (CameraHikvision *)pUser;
		cv::Mat srcImage = pCam->convertToMat(pData, pFrameInfo);

		emit pCam->imageReady(srcImage);
		//Sleep(10000);
	}
}

QString pixelFormatTranslator(int value)
{
	switch (value)
	{
	case PixelType_Gvsp_Undefined:
		return "Undefined";
	case PixelType_Gvsp_Mono1p:
		return "Mono1p";
	case PixelType_Gvsp_Mono2p:
		return "Mono2p";
	case PixelType_Gvsp_Mono4p:
		return "Mono4p";
	case PixelType_Gvsp_Mono8:
		return "Mono8";
	case PixelType_Gvsp_Mono8_Signed:
		return "Mono8_Signed";
	case PixelType_Gvsp_Mono10:
		return "Mono10";
	case PixelType_Gvsp_Mono10_Packed:
		return "Mono10_Packed";
	case PixelType_Gvsp_Mono12:
		return "Gvsp_Mono12";
	case PixelType_Gvsp_Mono12_Packed:
		return "Mono12_Packed";
	case PixelType_Gvsp_Mono14:
		return "Mono14";
	case PixelType_Gvsp_Mono16:
		return "Mono16";
	case PixelType_Gvsp_BayerGR8:
		return "BayerGR8";
	case PixelType_Gvsp_BayerRG8:
		return "BayerRG8";
	case PixelType_Gvsp_BayerGB8:
		return "BayerGB8";
	case PixelType_Gvsp_BayerBG8:
		return "BayerBG8";
	case PixelType_Gvsp_BayerGR10:
		return "BayerGR10";
	case PixelType_Gvsp_BayerRG10:
		return "BayerRG10";
	case PixelType_Gvsp_BayerGB10:
		return "BayerGB10";
	case PixelType_Gvsp_BayerBG10:
		return "BayerBG10";
	case PixelType_Gvsp_BayerGR12:
		return "BayerGR12";
	case PixelType_Gvsp_BayerRG12:
		return "BayerRG12";
	case PixelType_Gvsp_BayerGB12:
		return "BayerGB12";
	case PixelType_Gvsp_BayerBG12:
		return "BayerBG12";
	case PixelType_Gvsp_BayerGR10_Packed:
		return "BayerGR10_Packed";
	case PixelType_Gvsp_BayerRG10_Packed:
		return "BayerRG10_Packed";
	case PixelType_Gvsp_BayerGB10_Packed:
		return "BayerGB10_Packed";
	case PixelType_Gvsp_BayerBG10_Packed:
		return "BayerBG10_Packed";
	case PixelType_Gvsp_BayerGR12_Packed:
		return "BayerGR12_Packed";
	case PixelType_Gvsp_BayerRG12_Packed:
		return "BayerRG12_Packed";
	case PixelType_Gvsp_BayerGB12_Packed:
		return "BayerGB12_Packed";
	case PixelType_Gvsp_BayerBG12_Packed:
		return "BayerBG12_Packed";
	case PixelType_Gvsp_BayerGR16:
		return "BayerGR16";
	case PixelType_Gvsp_BayerRG16:
		return "BayerRG16";
	case PixelType_Gvsp_BayerGB16:
		return "BayerGB16";
	case PixelType_Gvsp_BayerBG16:
		return "BayerBG16";
	case PixelType_Gvsp_RGB8_Packed:
		return "RGB8_Packed";
	case PixelType_Gvsp_BGR8_Packed:
		return "BGR8_Packed";
	case PixelType_Gvsp_RGBA8_Packed:
		return "RGBA8_Packed";
	case PixelType_Gvsp_BGRA8_Packed:
		return "BGRA8_Packed";
	case PixelType_Gvsp_RGB10_Packed:
		return "RGB10_Packed";
	case PixelType_Gvsp_BGR10_Packed:
		return "BGR10_Packed";
	case PixelType_Gvsp_RGB12_Packed:
		return "RGB12_Packed";
	case PixelType_Gvsp_BGR12_Packed:
		return "BGR12_Packed";
	case PixelType_Gvsp_RGB16_Packed:
		return "RGB16_Packed";
	case PixelType_Gvsp_RGB10V1_Packed:
		return "RGB10V1_Packed";
	case PixelType_Gvsp_RGB10V2_Packed:
		return "";
	case PixelType_Gvsp_RGB12V1_Packed:
		return "";
	case PixelType_Gvsp_RGB565_Packed:
		return "";
	case PixelType_Gvsp_BGR565_Packed:
		return "";
	case PixelType_Gvsp_YUV411_Packed:
		return "";
	case PixelType_Gvsp_YUV422_Packed:
		return "";
	case PixelType_Gvsp_YUV422_YUYV_Packed:
		return "";
	case PixelType_Gvsp_YUV444_Packed:
		return "";
	case PixelType_Gvsp_YCBCR8_CBYCR:
		return "";
	case PixelType_Gvsp_YCBCR422_8:
		return "";
	case PixelType_Gvsp_YCBCR422_8_CBYCRY:
		return "";
	case PixelType_Gvsp_YCBCR411_8_CBYYCRYY:
		return "";
	case PixelType_Gvsp_YCBCR601_8_CBYCR:
		return "";
	case PixelType_Gvsp_YCBCR601_422_8:
		return "";
	case PixelType_Gvsp_YCBCR601_422_8_CBYCRY:
		return "";
	case PixelType_Gvsp_YCBCR601_411_8_CBYYCRYY:
		return "";
	case PixelType_Gvsp_YCBCR709_8_CBYCR:
		return "";
	case PixelType_Gvsp_YCBCR709_422_8:
		return "";
	case PixelType_Gvsp_YCBCR709_422_8_CBYCRY:
		return "";
	case PixelType_Gvsp_YCBCR709_411_8_CBYYCRYY:
		return "";
	case PixelType_Gvsp_RGB8_Planar:
		return "";
	case PixelType_Gvsp_RGB10_Planar:
		return "";
	case PixelType_Gvsp_RGB12_Planar:
		return "";
	case PixelType_Gvsp_RGB16_Planar:
		return "";
	case PixelType_Gvsp_Jpeg:
		return "";
	case PixelType_Gvsp_Coord3D_ABC32f:
		return "";
	case PixelType_Gvsp_Coord3D_ABC32f_Planar:
		return "";
	case PixelType_Gvsp_Coord3D_AC32f:
		return "";
	case PixelType_Gvsp_COORD3D_DEPTH_PLUS_MASK:
		return "";
	case PixelType_Gvsp_Coord3D_ABC32:
		return "";
	case PixelType_Gvsp_Coord3D_AB32f:
		return "";
	case PixelType_Gvsp_Coord3D_AB32:
		return "";
	case PixelType_Gvsp_Coord3D_AC32f_64:
		return "";
	case PixelType_Gvsp_Coord3D_AC32f_Planar:
		return "";
	case PixelType_Gvsp_Coord3D_AC32:
		return "";
	case PixelType_Gvsp_Coord3D_A32f:
		return "";
	case PixelType_Gvsp_Coord3D_A32:
		return "";
	case PixelType_Gvsp_Coord3D_C32f:
		return "";
	case PixelType_Gvsp_Coord3D_C32:
		return "";
	case PixelType_Gvsp_Coord3D_ABC16:
		return "";
	case PixelType_Gvsp_Coord3D_C16:
		return "";
	case PixelType_Gvsp_HB_Mono8:
		return "";
	case PixelType_Gvsp_HB_Mono10:
		return "";
	case PixelType_Gvsp_HB_Mono10_Packed:
		return "";
	case PixelType_Gvsp_HB_Mono12:
		return "";
	case PixelType_Gvsp_HB_Mono12_Packed:
		return "";
	case PixelType_Gvsp_HB_Mono16:
		return "";
	case PixelType_Gvsp_HB_BayerGR8:
		return "";
	case PixelType_Gvsp_HB_BayerRG8:
		return "";
	case PixelType_Gvsp_HB_BayerGB8:
		return "";
	case PixelType_Gvsp_HB_BayerBG8:
		return "";
	case PixelType_Gvsp_HB_BayerGR10:
		return "";
	case PixelType_Gvsp_HB_BayerRG10:
		return "";
	case PixelType_Gvsp_HB_BayerGB10:
		return "";
	case PixelType_Gvsp_HB_BayerBG10:
		return "";
	case PixelType_Gvsp_HB_BayerGR12:
		return "";
	case PixelType_Gvsp_HB_BayerRG12:
		return "";
	case PixelType_Gvsp_HB_BayerGB12:
		return "";
	case PixelType_Gvsp_HB_BayerBG12:
		return "";
	case PixelType_Gvsp_HB_BayerGR10_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerRG10_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerGB10_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerBG10_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerGR12_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerRG12_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerGB12_Packed:
		return "";
	case PixelType_Gvsp_HB_BayerBG12_Packed:
		return "";
	case PixelType_Gvsp_HB_YUV422_Packed:
		return "";
	case PixelType_Gvsp_HB_YUV422_YUYV_Packed:
		return "";
	case PixelType_Gvsp_HB_RGB8_Packed:
		return "";
	case PixelType_Gvsp_HB_BGR8_Packed:
		return "";
	case PixelType_Gvsp_HB_RGBA8_Packed:
		return "";
	case PixelType_Gvsp_HB_BGRA8_Packed:
		return "";
	default:
		return "";
	}
}
QString triggerModeTranslator(int value)
{
	MV_CAM_TRIGGER_MODE mode = (MV_CAM_TRIGGER_MODE)value;
	switch (mode)
	{
	case MV_TRIGGER_MODE_OFF:
		return "Off";
	case MV_TRIGGER_MODE_ON:
		return "On";
	default:
		return "";
	}
}
QString triggerSourceTranslator(int value)
{
	MV_CAM_TRIGGER_SOURCE source = (MV_CAM_TRIGGER_SOURCE)value;
	switch (source)
	{
	case MV_TRIGGER_SOURCE_LINE0:
		return "Line0";
	case MV_TRIGGER_SOURCE_LINE1:
		return "Line1";
	case MV_TRIGGER_SOURCE_LINE2:
		return "Line2";
	case MV_TRIGGER_SOURCE_LINE3:
		return "Line3";
	case MV_TRIGGER_SOURCE_COUNTER0:
		return "Counter0";
	case MV_TRIGGER_SOURCE_SOFTWARE:
		return "Software";
	case MV_TRIGGER_SOURCE_FrequencyConverter:
		return "FrequencyConverter";
	default:
		return "";
	}
}

//设置当前为自由采集模式
void CameraHikvision::SetFreeRunGrab()
{
	int nRet = MV_CC_SetEnumValue(m_handle, "TriggerMode", 0);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
		//QMessageBox::information(nullptr, "tips", QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
	}
}

//设置当前为硬触发模式
void CameraHikvision::SetHardwareGrab(QString hardWareName)
{
	int nRet = MV_CC_SetEnumValue(m_handle, "TriggerMode", 1);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
		//QMessageBox::information(nullptr, "tips", QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
	}
	int nRet2 = MV_CC_SetEnumValueByString(m_handle, "TriggerSource", hardWareName.toStdString().c_str());
	if (MV_OK != nRet2)
	{
		emit cameraError(QString("Set TriggerSource fail!\n%1").arg(errMsg(nRet2)));
		//QMessageBox::information(nullptr, "tips", QString("Set TriggerSource fail!\n%1").arg(errMsg(nRet2)));
	}
}

//设置当前为软触发模式
void CameraHikvision::SetSoftwareGrab()
{
	int nRet = MV_CC_SetEnumValue(m_handle, "TriggerMode", 1);
	if (MV_OK != nRet)
	{
		emit cameraError(QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
		//QMessageBox::information(nullptr, "tips", QString("Set Trigger Mode fail!\n%1").arg(errMsg(nRet)));
	}
	int nRet2 = MV_CC_SetEnumValueByString(m_handle, "TriggerSource", "Software");
	if (MV_OK != nRet2)
	{
		emit cameraError(QString("Set TriggerSource fail!\n%1").arg(errMsg(nRet2)));
		//QMessageBox::information(nullptr, "tips", QString("Set TriggerSource fail!\n%1").arg(errMsg(nRet2)));
	}
}