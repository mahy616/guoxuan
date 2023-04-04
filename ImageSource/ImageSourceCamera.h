#pragma once
#include "ImageSouceBase.h"
#include "ImageSourceCameraSetting.h"

class ImageSourceCamera : public ImageSourceBase
{
public:
	ImageSourceCamera();
	~ImageSourceCamera();
	//当前图像源是否有图像可启动
	virtual bool isCanStart() override;
	//连续运行 - 连续取图
	virtual bool Start() override;
	//停止运行 - 停止取图
	virtual void Stop() override;
	//单次执行 - 抓一张图
	virtual bool SingleGrab() override;
	//保存当前图像源的配置
	virtual bool BtnSave() override;
	//从配置文件初始化当前图像源 - 加载方案时调用
	virtual void InintFromConfig(ImageSourceConfig inConfig) override;
	//打开图像源的设置界面
	virtual QWidget* OpenSettingDialg() override;
	Camera * getCameraPtr();
	void initCamera(int windowsIndex);
public slots:
	void ConnectImage(cv::Mat);
private:
	friend class ImageSourceCameraSetting; //访问camera
private:
	ImageSourceCameraSetting *m_SettingDialg = nullptr;
	Camera *m_camera = nullptr; 
};

