#pragma once

#include <QWidget>
#include "ui_ImageWindow.h"
#include <opencv2/opencv.hpp>
#include "PublicParamter.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QDirIterator>
#include "components/Config/JsonReader.h"
#include "UI/Menu/ModelConfigDialg.h"
#include "ThresholdSet.h"
#include <QAction>
#include <QMenu>
#include <QResizeEvent>

// 图像窗口右上角Ok/Ng的logo
typedef struct LabelOkNg_Info
{
	QLabel* Label_OkNg;
	int OldWidth;
	int OldHeight;
	const int LabelWidth = 50;
	const int LabelHeight = 50;
}LabelOkNg_Info;

class ImageSourceBase;
class ImageWindow : public QWidget
{
	Q_OBJECT
public:
	// WindowIndex当前Staion的ID ；inShowFlag是否显示OK/Ng结果
	ImageWindow(int* WindowIndex, bool* inShowFlag, QWidget *parent = nullptr);
	~ImageWindow();
	// 当StaionID改变时修改标题
	void SetWindowsTittle();
	// 获取当前窗口使用的模型类型
	SdkModelType GetModelType();
	// 将MyStation的图像源对象传进来（点击"图像源设置"访问到图像源类的对象）
	void SetImageSourcePtr(ImageSourceBase *inPtr);
	// 加载方案时初始化vimo模型的接口
	void inintLoadModelChoice(ModelChoice inChoice);
	// 传入算法类函数的指针，获取算法阈值，获取算法信息
	void SetAlgoThreadCallBackPtr(std::function<std::vector<AllThreshold>(void)> inThresholdPtr, std::function<std::vector<ViMoModelInfo>(void)>inInfoPtr);
	// 传入软件当前运行状态的函数指针，获取软件是否正在运行
	void SetSoftRunningStatePtr(std::function<bool(void)> inRuningStatePtr);
private:
	std::function<std::vector<AllThreshold>(void)> m_AlgoThresholdCallBack;   //获取算法类阈值的回调函数   - 在阈值设置中初始化需要加载模型的默认阈值或点击重置按钮时需要从算法类获取当前的阈值
	std::function<std::vector<ViMoModelInfo>(void)> m_AlgoInfoCallBack;       //获取算法模型信息的回调函数 - 在阈值类中当OCR模型为2.x时屏蔽阈值编辑框
	std::function<bool(void)> m_RunningStateCallBack;                         //获取软件运行状态的回调函数 - 在点击图像源设置时如果软件在运行中提示停止工作
private:
	Ui::ImageWindowClass ui;
	int *MyWindowIndex;             //当前窗口的StaionID
	bool* isShowOkNg;               //当前窗口是否显示Ok/Ng结果
	SdkModelType my_ModelType;      //当前窗口的模型类型
	cv::Mat m_OriginalImage;        //当前显示的图像原图
	cv::Mat m_RenderImage;          //当前显示的算法渲染图
	LabelOkNg_Info m_LabelOkNg;     //当前图像窗口右上角Ok/Ng的logo
	QMenu* buttonMenu = nullptr;    //菜单栏
private:
	void InintMenu();                       //初始化菜单栏
	void SetMenuStyleSheet(QMenu* inMenu);  //设置菜单栏样式
	void InintResultLabel();                //初始化Ok/Ng的logo
	void InintParameter();
	void InintConnection();
public:
	ThresholdSet *m_ThresholdSetDialg = nullptr; //当前判图参数类设置对象
	ImageSourceBase *m_ImgSourcePtr = nullptr;	 //当前图像源类对象，从MyStaion传入
	ModelConfigDialg *m_configDialg = nullptr;   //当前算法方案设置对象
protected:
	virtual void resizeEvent(QResizeEvent *event) override; //当图像窗口变化时重新设置Ok/Ng logo的宽高
public slots:
	void SetCameraStateSlot(bool isOpen);   //相机状态改变槽函数 - 设置相机logo样式
	void ImageSourceSlot();             //菜单栏点击了图像源设置槽函数
	void ModelChoiceSlot();             //菜单栏点击了算法方案设置槽函数
	void ThresholdSetSlot();            //菜单栏点击了判图参数设置槽函数
	void SetShowImageSlot(cv::Mat& m_OriginalImages, cv::Mat& m_RenderImages, bool bOK, double Time); //连接算法结果信号的显示渲染图槽函数
	void GetModelChoiceSlot(ModelChoice);                  //当算法方案界面点击了"确定"按钮响应的槽函数
	void AlgoStatusChangleSlot(bool);                      //当算法初始化结束响应的槽函数 - 根据结果修改算法logo样式
	void ShowRenderFlagSlot();                             //当点击了"渲染效果"的checkBox复选框，对应显示原图或渲染图
	void MenuBtnSlot(const QPoint &pos);
signals:
	void SendModelConfig(ModelChoice);			  //当在算法方案设计界面点击了确定按钮
signals:
	void SendThreshold();                         //当在阈值界面点击了确定按钮
signals:
	void ChangeImageSourceBase(ImageSourceBase*); //在图像源设置中点击确定按钮发送的图像源类对象更新信号
signals:
	void AddWindowSignal();  //添加窗口信号
signals:
	void SendCloseEvent(int);//删除窗口信号
};
