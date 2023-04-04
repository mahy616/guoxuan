#pragma once
#include "ImageSouceBase.h"
#include "ImageSourceFileSetting.h"
#include <QTimer>
#include <QObject>

class ImageSourceFile : public ImageSourceBase
{
	Q_OBJECT
public:
	ImageSourceFile();
	~ImageSourceFile();
	//当前图像源是否有图像可启动(判断列表内是否有行数)
	virtual bool isCanStart() override;
	//连续运行 - 开启定时器按行数一次读取列表第二行的图片路径
	virtual bool Start() override;
	//停止运行 - 停止取图定时器
	virtual void Stop() override;
	//单次执行 - 手动调用定时器槽函数
	virtual bool SingleGrab() override;
	//保存当前图像源的配置
	virtual bool BtnSave() override;
	//从配置文件初始化当前图像源
	virtual void InintFromConfig(ImageSourceConfig inConfig) override;
	//打开图像源的设置界面
	virtual QWidget* OpenSettingDialg() override;
private:
	friend class ImageSourceFileSetting; //访问LoadFileImage函数
private:
	void LoadFileImage(QStringList images);
private:
	int FileIndex = 0;    //当前文件夹读到第几张图
	ImageSourceFileSetting* m_SettingDialg = nullptr;
	QTimer *m_ReadImgTimer = nullptr;
private slots:
	// 取图列表内文件路径的定时器槽函数
	void ReadingImageSlot();
};

