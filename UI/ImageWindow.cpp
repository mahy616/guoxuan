#include "ImageWindow.h"
#include "components/Config/ConfigProgramme.h"
#include "ImageSourceSetting.h"
#include "ImageSouceBase.h"
#include "QGraphicsDropShadowEffect"
#include <QMessageBox>
#include <QString>
#include <QPointer>

ImageWindow::ImageWindow(int* WindowIndex, bool* inShowFlag, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	MyWindowIndex = WindowIndex;
	isShowOkNg = inShowFlag;
	SetWindowsTittle();    //设置当前标题
	InintMenu();           //设置菜单
	InintResultLabel();    //设置Ok/Ng logo
	
	InintParameter();     
	InintConnection();
	
	
	QTimer *m_delay = new QTimer(this); m_delay->start(100);
	connect(m_delay, &QTimer::timeout, this, [=]() { 
		//触发resizeEvent事件，布局Ok/Ng logo
		this->resize(this->size() - QSize(1, 1)); this->resize(this->size() + QSize(1, 1));; m_delay->stop(); delete m_delay;
		// 中英文切换不同字体
		QFont font;
		font.setPointSize(11);
		if (isChineseLanguage())
			font.setFamily("Microsoft YaHei");
		else
			font.setFamily("Roboto");
		auto listWidget = findChildren<QWidget*>();
		for (auto& widget : listWidget)
		{
			widget->setFont(font);
		}
	});
}

ImageWindow::~ImageWindow()
{
	disconnect(ui.ShowImgWidget, &QLabel::customContextMenuRequested, this, &ImageWindow::MenuBtnSlot);
	if (m_ThresholdSetDialg != nullptr) delete m_ThresholdSetDialg;
	if (m_ImgSourcePtr != nullptr) delete m_ImgSourcePtr;
	if (m_configDialg != nullptr) delete m_configDialg;
	if (buttonMenu != nullptr)  buttonMenu->deleteLater(); buttonMenu = nullptr;
}

void ImageWindow::InintParameter()
{
	m_configDialg = new ModelConfigDialg;
	m_ThresholdSetDialg = new ThresholdSet;
	m_configDialg->setAttribute(Qt::WA_ShowModal, true);

	ui.checkBox_ShowRender->setChecked(true);
	ui.label_ModelStatus->setStyleSheet("image:url(:/DynamicWidget/Resource/AlgoNone.png);background: \"transparent\";");
	ui.label_ModelStatus->setToolTip(tr("initializing"));
}

void ImageWindow::InintConnection()
{
	connect(ui.checkBox_ShowRender, &QCheckBox::clicked, this, &ImageWindow::ShowRenderFlagSlot);
	connect(m_configDialg, &ModelConfigDialg::SendModelChoice, this, &ImageWindow::GetModelChoiceSlot);
	connect(m_ThresholdSetDialg, &ThresholdSet::SendThresholdPatamter, this, &ImageWindow::SendThreshold);
}

void ImageWindow::InintResultLabel()
{
	layout()->activate();
	ui.verticalLayout->activate();
	ui.gridLayout->activate();
	ui.gridLayout_2->activate();
	ui.horizontalLayout->activate();
	m_LabelOkNg.Label_OkNg = new QLabel(ui.ShowImgWidget);
	m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/LabelNone.png);background:\"transparent\";");
	//m_LabelOkNg.Label_OkNg->setStyleSheet("border-image:url(\":/DynamicWidget/Resource/LabelNone.png\");");
	QRect rect = ui.ShowImgWidget->rect();
	m_LabelOkNg.Label_OkNg->setGeometry(rect.width() - m_LabelOkNg.LabelWidth, 0, m_LabelOkNg.LabelWidth, m_LabelOkNg.LabelHeight);
	m_LabelOkNg.OldWidth = rect.width();
	m_LabelOkNg.OldHeight = rect.height();
}

void ImageWindow::SetImageSourcePtr(ImageSourceBase *inPtr)
{
	m_ImgSourcePtr = inPtr;
}

//相机状态改变槽函数 - 设置相机logo样式
void ImageWindow::SetCameraStateSlot(bool isOpen)
{
	if (isOpen)
	{
		ui.btn_SoftTrigger->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/CameraOK.png\");border:none;background: \"transparent\";}");
		ui.btn_SoftTrigger->setToolTip(tr("Camera Conneted"));
	}
	else
	{
		ui.btn_SoftTrigger->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/CameraNG.png\");border:none;background: \"transparent\";}");
		ui.btn_SoftTrigger->setToolTip(tr("Camera Disconneted"));
	}
}

//连接算法结果信号的显示渲染图槽函数
void ImageWindow::SetShowImageSlot(cv::Mat& m_OriginalImages, cv::Mat& m_RenderImages, bool bOK, double Time)
{
	if (m_OriginalImages.rows==0|| m_OriginalImages.cols == 0)
	{
		QMessageBox::information(NULL, tr("Tips"), tr("Original image is empty"));
		return;
	}
	if (m_RenderImages.rows == 0 || m_RenderImages.cols == 0)
	{
		QMessageBox::information(NULL, tr("Tips"), tr("Result image is empty"));
		return;
	}

	if (*isShowOkNg)
	{
		if (bOK)
			m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/ResultOk.png);background:\"transparent\";");
		else
			m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/ResultNg.png);background:\"transparent\";");
	}
	else
	{
		m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/LabelNone.png);background:\"transparent\";");
	}


	if (ui.checkBox_ShowRender->isChecked())
		ui.ShowImgWidget->SetImage(MattoQImage(m_RenderImages));
	else
		ui.ShowImgWidget->SetImage(MattoQImage(m_OriginalImages));
	ui.label_UseTime->setText(tr("RunTime:") + QString::number(Time, 'f', 2) + "ms");
	m_OriginalImage = m_OriginalImages;
	m_RenderImage = m_RenderImages;
}


void ImageWindow::InintMenu()
{
	QAction* buttonAction_ImageSource = new QAction(tr("Image Source Settings"), this);
	QAction* buttonAction_ModelChoice = new QAction(tr("Pipeline Settings"), this);
	QAction* buttonAction_Threshold = new QAction(tr("Parameters Settings"), this);
	QAction* buttonAction_AddWindow = new QAction(tr("New Window"), this);
	QAction* buttonAction_Close = new QAction(tr("Delete Window"), this);

	buttonMenu = new QMenu;
	SetMenuStyleSheet(buttonMenu); //设置菜单栏样式
	buttonMenu->addAction(buttonAction_ImageSource);
	buttonMenu->addAction(buttonAction_ModelChoice);
	buttonMenu->addAction(buttonAction_Threshold);
	buttonMenu->addAction(buttonAction_AddWindow);
	buttonMenu->addAction(buttonAction_Close);

	//点击了"图像源设置"
	connect(buttonAction_ImageSource, &QAction::triggered, this, &ImageWindow::ImageSourceSlot);
	//点击了"算法方案设置"
	connect(buttonAction_ModelChoice, &QAction::triggered, this, &ImageWindow::ModelChoiceSlot);
	//点击了"判图参数设置"
	connect(buttonAction_Threshold, &QAction::triggered, this, &ImageWindow::ThresholdSetSlot);
	//点击了"新建窗口"
	connect(buttonAction_AddWindow, &QAction::triggered, this, [=]() { emit AddWindowSignal(); });
	//点击了"关闭窗口"
	connect(buttonAction_Close, &QAction::triggered, this, [=]()
	{
		if (QMessageBox::Ok == QMessageBox::information(NULL, tr("Tips"), tr("Are you sure want to delete the Window?"), QMessageBox::Ok | QMessageBox::Cancel))
			SendCloseEvent(*MyWindowIndex);
	});

	//给控件设置上下文菜单策略(绑定当前窗口与菜单)
	ui.ShowImgWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.ShowImgWidget, &QLabel::customContextMenuRequested, this, &ImageWindow::MenuBtnSlot);
}

void ImageWindow::MenuBtnSlot(const QPoint &pos)
{
	QPointer<QWidget> pointer = this;
	if (!pointer) return;
	if (buttonMenu != nullptr)
	{
		buttonMenu->exec(QCursor::pos());
	}
}

void ImageWindow::SetMenuStyleSheet(QMenu* inMenu)
{
	QFont font; font.setPointSize(11);
	if (isChineseLanguage())
		font.setFamily("Microsoft YaHei");
	else
		font.setFamily("Roboto");
	buttonMenu->setFont(font);
	inMenu->setStyleSheet(
		"QMenu{"
		"color:rgb(0,0,0);"
		"background-color:#E6E6E6;"
		"font:9pt;"
		"border-radius:10px;}"
		"QMenu::item{"
		"color:rgb(0,0,0);"
		"background-color:#E6E6E6;"
		"height:40px;}"
		"QMenu::item:hover{"
		"background-color:#C2C2C2;}"
		"QMenu::item:selected{"
		"background-color:#999999;}"
	);
	//设置阴影
	inMenu->setAttribute(Qt::WA_TranslucentBackground, true);//设置窗体透明
	QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
	shadow_effect->setOffset(0, 0);
	shadow_effect->setColor(QColor("#444444"));//阴影颜色
	shadow_effect->setBlurRadius(30);//阴影半径
	inMenu->setGraphicsEffect(shadow_effect);
	inMenu->setContentsMargins(10, 10, 10, 10);//给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
}

// 菜单栏点击了判图参数设置槽函数
void ImageWindow::ThresholdSetSlot()
{
	m_ThresholdSetDialg->m_AlgoThreadCallBack = m_AlgoThresholdCallBack;
	m_ThresholdSetDialg->m_AlgoInfoCallBack = m_AlgoInfoCallBack;
	//m_ThresholdSetDialg->inintProgramThreshold(m_AlgoThresholdCallBack());
	m_ThresholdSetDialg->show();
}

// 菜单栏点击了图像源设置槽函数
void ImageWindow::ImageSourceSlot()
{
	if (m_RunningStateCallBack())
	{
		QMessageBox::information(nullptr, tr("Tips"), tr("Please stop working")); return;
	}

	ImageSourceSetting *m_ImageSet = new ImageSourceSetting(m_ImgSourcePtr);
	connect(m_ImageSet, &ImageSourceSetting::NewImageSourceBase, this, [=](ImageSourceBase* inPtr) { 
		m_ImgSourcePtr = inPtr; 
		emit ChangeImageSourceBase(inPtr);
	});
	m_ImageSet->setWindowModality(Qt::ApplicationModal);
	m_ImageSet->show();
}

//当点击了"渲染效果"的checkBox复选框，对应显示原图或渲染图
void ImageWindow::ShowRenderFlagSlot()
{
	QImage img;
	if (ui.checkBox_ShowRender->isChecked())
	{
		img = MattoQImage(m_RenderImage);
		m_LabelOkNg.Label_OkNg->setVisible(true);
	}
	else
	{
		img = MattoQImage(m_OriginalImage);
		m_LabelOkNg.Label_OkNg->setVisible(false);
	}
	ui.ShowImgWidget->SetImage(img);
}

//菜单栏点击了算法方案设置槽函数
void ImageWindow::ModelChoiceSlot()
{	
	m_configDialg->show();
}

//当算法方案界面点击了"确定"按钮响应的槽函数
void ImageWindow::GetModelChoiceSlot(ModelChoice m_receiveChoice)
{
	// 设置当前算法logo初始化中
	ui.label_ModelStatus->setStyleSheet("image: url(:/DynamicWidget/Resource/AlgoNone.png);background: \"transparent\";");
	ui.label_ModelStatus->setToolTip(tr("initializing"));

	//保存到方案
	ConfigProgramme::GetInstance()->AllConfig[*MyWindowIndex - 1].m_ModelChoice = m_receiveChoice;

	my_ModelType = GetModelTypeFromString(m_receiveChoice.modeType[m_receiveChoice.modeType.size() - 1]);

	//传入算法类初始化模型
	emit SendModelConfig(m_receiveChoice);

	//更新阈值类的模型类型
	m_ThresholdSetDialg->SetMyParamter(m_receiveChoice.RealNameValue,m_receiveChoice.modeType, m_receiveChoice.labelsNamesVec);

	//更新现在的模型名字文本
	std::string NowName = m_receiveChoice.RealNameValue[m_receiveChoice.RealNameValue.size() - 1];
	QString ModelStr = QString::fromLocal8Bit(NowName.c_str());
	ui.label_modeType->setText(ModelStr);
}

//当算法初始化结束响应的槽函数 - 根据结果修改算法logo样式
void ImageWindow::AlgoStatusChangleSlot(bool isSuccess)
{
	if (isSuccess)
	{
		ui.label_ModelStatus->setStyleSheet("image: url(:/DynamicWidget/Resource/AlgoHave.png);background: \"transparent\";");
		ui.label_ModelStatus->setToolTip(tr("Pipeline Woring Normally"));
	}
	else
	{
		ui.label_ModelStatus->setStyleSheet("image: url(:/DynamicWidget/Resource/AlgoFail.png);background: \"transparent\";");
		ui.label_ModelStatus->setToolTip(tr("Pipeline Fail"));
		QMessageBox::information(nullptr, tr("Tips"), tr("Window%1:Pipeline initialization failed.").arg(*MyWindowIndex));
	}
}


// 获取当前窗口使用的模型类型
SdkModelType ImageWindow::GetModelType()
{
	return my_ModelType;
}

// 当StaionID改变时修改标题
void ImageWindow::SetWindowsTittle()
{
	QString strname;
	if (*MyWindowIndex == 1)
		strname = QString::fromLocal8Bit("机头");
	else if (*MyWindowIndex == 2)
		strname = QString::fromLocal8Bit("机尾");


	//"QMenu{"
	//	"color:rgb(0,0,0);"
	//	"background-color:#E6E6E6;"
	//	"font:9pt;"
	//	"border-radius:10px;}"
	//	"QMenu::item{"
	//	"color:rgb(0,0,0);"
	//	"background-color:#E6E6E6;"
	//	"height:40px;}"
	//	"QMenu::item:hover{"
	//	"background-color:#C2C2C2;}"
	//	"QMenu::item:selected{"
	//	"background-color:#999999;}"
	ui.label_WidonwTittle->setStyleSheet("background-color:rgb(50, 50, 50);color:rgb(255,0,0);font:25pt;");
	ui.label_WidonwTittle->setText(strname);
}

// 加载方案时初始化vimo模型的接口
void ImageWindow::inintLoadModelChoice(ModelChoice inChoice)
{
	this->m_configDialg->LoadModelChoice(inChoice);
}

//当图像窗口变化时重新设置Ok/Ng logo的宽高
void ImageWindow::resizeEvent(QResizeEvent *event)
{
	QRect rect = ui.ShowImgWidget->rect();
	float widthRate = (float)rect.width() / m_LabelOkNg.OldWidth;
	float heightRate = (float)rect.height() / m_LabelOkNg.OldHeight;
	m_LabelOkNg.Label_OkNg->setGeometry(rect.width() - m_LabelOkNg.LabelWidth * widthRate, 0, m_LabelOkNg.LabelWidth * widthRate, m_LabelOkNg.LabelHeight*widthRate);
}

// 传入算法类函数的指针，获取算法阈值，获取算法信息
void ImageWindow::SetAlgoThreadCallBackPtr(std::function<std::vector<AllThreshold>(void)> inThresholdPtr, std::function<std::vector<ViMoModelInfo>(void)>inInfoPtr)
{
	m_AlgoThresholdCallBack = inThresholdPtr;
	m_AlgoInfoCallBack = inInfoPtr;
	m_ThresholdSetDialg->m_AlgoInfoCallBack = m_AlgoInfoCallBack;
}

// 传入软件当前运行状态的函数指针，获取软件是否正在运行
void ImageWindow::SetSoftRunningStatePtr(std::function<bool(void)> inRuningStatePtr)
{
	m_RunningStateCallBack = inRuningStatePtr;
}
