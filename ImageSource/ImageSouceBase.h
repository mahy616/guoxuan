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
	virtual bool isCanStart() = 0; //当前图像源是否有图像可启动
	virtual bool Start() = 0;      //连续运行 - 连续取图
	virtual void Stop() = 0;       //停止运行 - 停止取图
	virtual bool SingleGrab() = 0; //单次执行 - 抓一张图
	virtual bool BtnSave() = 0;    //保存当前图像源的配置
	virtual void InintFromConfig(ImageSourceConfig inConfig) = 0;  //从配置文件初始化当前图像源 - 加载方案时调用
	virtual QWidget* OpenSettingDialg() = 0;                       //打开图像源的设置界面
public:
	void SetMyPtr(MyStation* inStation);    //将MyStation指针传入
	MyStation* GetMyPtr();                  //获取此类绑定的station指针
	bool isCameraSource();                  //获取当前的图像源类型（相机，本地文件夹）
protected:
	MyStation* m_Station;
signals:
	void ImageReady(cv::Mat);          //获取到的图像(相机图像源通过此信号将相机图像传给MyStation)
signals:
	void CameraStateChange(bool isOk); //当前相机图像源是否打开
};
