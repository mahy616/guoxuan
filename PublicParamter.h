#pragma once
#include <QObject>
#include <qmutex.h>
#include "opencv2/opencv.hpp"
#include "qdebug.h"
#include <Windows.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgroupbox.h>
#include "qgridlayout.h"
#include <QImage>
#include "components/Camera/Camera.h"
#include "components/Camera/CameraHikvision.h"
#include "components/SaveImage/SaveImage.h"
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <qlabel.h>
#include "guoxuan.h"
using namespace std;
using namespace cv;

typedef enum
{
	Classification,
	Segmentation,
	Detection,
	OCR
}SdkModelType;

typedef enum
{
	SortByX,
	SortByY
}OcrSortType;

typedef enum
{
	OnlyViMo=0,
	OnlyPostProcess,
	ViMoAndPostProcess
}TimeStatisType;



// *************** 算法线程类的队列数据 ***********************
typedef struct ThreadQueueInfos
{
	cv::Mat m_Image;
	int TableIndex;
	QString ImageName;
}ThreadQueueInfos;
//*************************************************************




//************************ 模型信息结构体 *************************
typedef struct ViMoModelInfo
{
	std::string id;
	std::vector<std::string> features;
	std::string model_version;
	cv::Point default_shifting;
	cv::Size default_padding;
}ViMoModelInfo;
//*****************************************************************




// ********************** 模型配置信息结构体 ******************
typedef struct OneModelInfo
{
	std::string m_ModeType;
	std::string RealNameValue;
	std::string ModulesName;
	std::vector<std::string> LableNames;
}OneModelInfo;

typedef struct ModelInfos
{
	int SolutionID;
	std::vector<OneModelInfo> ModeType;
}ModelInfos;

typedef struct LableInfos
{
	int SolutionID;
	std::vector<std::string> LableNames;
}LableInfos;

typedef struct ConfigResult
{
	std::string TypeName;
	std::vector< ModelInfos> EveryModel;
}ConfigResult;

typedef struct ModelChoice
{
	bool _useGPU = false;//是否使用GPU
	int _gpuID = 0; //第几个GPU
	std::string TypeName;		//typeName
	QString _jsonPath;//json路径

	std::vector<std::string> moduleID;
	std::vector<std::string> modeType;
	std::vector<std::string> RealNameValue;
	std::vector<std::vector<std::string>> labelsNamesVec;
	std::vector<int> soutionIndex;
}ModelChoice;

typedef struct ModelConfig
{
	bool _useGPU = false;
	int _gpuID = 0;
	QString _jsonPath;
	SdkModelType _type;
	QString _moduleID;
	std::vector<std::string> _labelName;
	std::string RealNameValue;
}ModelConfig;
//***********************************************************


// ********************** 显示设置 **************************
typedef struct RenderShowParams
{
	std::vector<cv::Scalar> _contourColor; //标签颜色
	std::vector<int> _contourThickness; //轮廓厚度
}RenderShowParams;
// ********************************************************


// ************************* 阈值设置 **************************
typedef struct TimeSetParamter
{
	float TimeThreshold = 2000;
	TimeStatisType m_TimeType = OnlyViMo;
}TimeSetParamter;

typedef struct SegThresholdVec
{
	int _area = 5;
	int _width;
	int _height;
	int _minGrayValue = 0;
	int _maxGrayValue = 255;
}SegThresholdVec;

typedef struct DetectionThresholdVec
{
	int _area;
	int _width;
	int _height;
	float _score;
	float _iou;
}DetectionThresholdVec;

typedef struct ClassificationThresholdVec
{
	float _score = 0.5;
}ClassificationThresholdVec;

typedef struct SegThreshold
{
	std::vector<SegThresholdVec> _segThresholdVec;
	bool _isFilterMinGray = false;
	bool _isFilterMaxGray = false;
}SegThreshold;

typedef struct DetectionThreshold
{
	std::vector<DetectionThresholdVec> _detectionThresholdVec;
}DetectionThreshold;

typedef struct OcrSdkThreshold
{
	float _score = 0.5;
	float _iou = 0.5;
}OcrSdkThreshold;

typedef struct OCRThreshold
{
	OcrSortType SortFunction = SortByX;
	std::vector<QString> MatchStrVec;
	std::vector<OcrSdkThreshold> SdkThreshold;
}OCRThreshold;

typedef struct ClassificationThreshold
{
	std::vector<ClassificationThresholdVec> _classificationThresholdVec;
}ClassificationThreshold;

typedef struct ThresholdParams
{
	SegThreshold _segThreshold;
	DetectionThreshold _detectionThreshold;
	ClassificationThreshold _classificationThreshold;
	OCRThreshold _ocrThreshold;
	TimeStatisType _timeType = OnlyViMo;
}ThresholdParams;

typedef struct AllThreshold
{
	ThresholdParams _PostParam;
	RenderShowParams _RenderParam;
}AllThreshold;
// ************************************************************








// ********************** 流程控制 ************************
typedef struct SystemSetResult
{
	int timeThreshold = 0;
	int timeContents = 1;
}SystemSetResult;
typedef struct FlowControl
{
	std::vector<int> WindowIndexVec;
	std::vector<float> TntervalTimeVec;
	int ThreadFrequency = 0;
}FlowControl;
// *********************************************************





// ************** GPU信息 *********************
typedef struct GpuInfos
{
	string Temperature = "UnKnow";
	string Performance = "UnKnow";
	string Power = "UnKnow";
	int AvailableMemory = -1;
	int MaxMemory = 1;
	string Utilization = "UnKnow";
}GpuInfos;
// *******************************************




// *******************方案配置信息 *************
//待修改
typedef struct CameraInfoConfig
{
	int exposure;
	int gain;
	QString name;
	QString triggerMode;
	QString triggerSource;
	bool isGrabbing;
	QString SoftTrigerCommunication;
	QString GrabStr;
}CameraInfoConfig;
typedef struct ImageSourceConfig
{
	CameraInfoConfig m_CameraInfo;
	bool ImageSource_isCamera = true;
	QString ImageFilePath;
}ImageSourceConfig;
typedef struct WindowsConfig
{
	ModelChoice m_ModelChoice;
	std::vector<AllThreshold> m_Threshold;
	ImageSourceConfig m_ImageSourceConfig;
	TimeSetParamter m_TimeThreshold;
}WindowsConfig;
typedef struct ProgrammeCongig
{
	string ProgrammeName;
	std::vector<WindowsConfig> m_WindowsConfig;
}ProgrammeCongig;
// *****************************************




// *************** 保存图片信息 *********************
typedef struct SaveImageConfig
{
	bool isSave=true;
	QString ImgPathStr = QApplication::applicationDirPath();
	QString SaveType="jpg";
	bool isDeleteNums=false;
	int deleteNums=1000;
	bool isDeleteDays=true;
	int deleteDays=30;
	bool isDeleteMemory=true;
	int deleteMemory=10;
}SaveImageConfig;
//*************************************



// ***************** 全局函数 *****************
std::string UTF8ToGBK(const std::string& strUTF8);
void ClearLayout(QLayout* m_pMainLayout);
string StrReader(string inStr, int nPos, bool isLeft);
std::vector<GpuInfos> GetResultFromCMD();
SdkModelType GetModelTypeFromString(string inStr);
QString GetStringFromModelType(SdkModelType inType);
void DeleteOldWidget(std::vector<QLineEdit*> inParam);
void DeleteOldWidget(std::vector<QPushButton*> inParam);
bool isChineseLanguage();
QImage MattoQImage(cv::Mat image);
