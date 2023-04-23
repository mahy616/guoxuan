#include "MyToolBar.h"
#include <QPainter>

#pragma execution_character_set("utf-8")
#define BUTTON_HEIGHT 40		// 按钮高度;
#define BUTTON_WIDTH 40			// 按钮宽度;

QString BtnStyleSheet2 = "QToolButton:hover{border:1px solid #A8A8A8;}"
"QToolButton:pressed{background-color:rgb(125,125,125);}";

MyToolBar::MyToolBar(QWidget *parent)
	: QToolBar(parent)
{
	InintWidget();
	InintConnet();
	QAction_StopGrab->setEnabled(false);
	//this->setStyleSheet("MyToolBar{border-bottom:5px solid #4F4F4F;border-top:5px solid #4F4F4F;}");
}

MyToolBar::~MyToolBar()
{

}


void MyToolBar::InintWidget()
{
	QPixmap originaPixmapl, fitpixmap;

	//创建单步按钮
	Btn_SignalGrab = new QToolButton;
	Btn_SignalGrab->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	Btn_SignalGrab->setObjectName("ButtonSignalGrab");
	Btn_SignalGrab->setToolTip(tr("Once"));
	Btn_SignalGrab->setStyleSheet(MyStytleSheet("BtnSignalGrab","GrabSingle_CannotPress"));
	QAction_SignalGrab = this->addWidget(Btn_SignalGrab);

	//创建开始按钮
	Btn_ContinueGrab = new QToolButton;
	Btn_ContinueGrab->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	Btn_ContinueGrab->setObjectName("ButtonContinueGrab");
	Btn_ContinueGrab->setToolTip(tr("Continuously"));
	Btn_ContinueGrab->setStyleSheet(MyStytleSheet("BtnContinueGrab","GrabContinue_CannotPress"));
	QAction_ContinueGrab = this->addWidget(Btn_ContinueGrab);

	//创建停止按钮
	Btn_StopGrab = new QToolButton;
	Btn_StopGrab->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	Btn_StopGrab->setObjectName("ButtonStopGrab");
	Btn_StopGrab->setToolTip(tr("Stop"));
	Btn_StopGrab->setStyleSheet(MyStytleSheet("BtnStopGrab","GrabStop_CannotPress"));
	QAction_StopGrab = this->addWidget(Btn_StopGrab);

	QLabel* GapLabel = new QLabel;
	GapLabel->setStyleSheet("background: transparent;");
	GapLabel->setFixedSize(QSize(10, 30));
	this->addWidget(GapLabel);

	//创建分割线按钮
	Label_SegLine = new QLabel;
	Label_SegLine->setFixedSize(QSize(12, 30));
	Label_SegLine->setObjectName("Label_SegLine");
	originaPixmapl.load(":/DynamicWidget/Resource/ToolBarSegLine.png");
	Label_SegLine->setStyleSheet("background: transparent;");
	fitpixmap = originaPixmapl.scaled(2, 30, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	Label_SegLine->setPixmap(fitpixmap);
	this->addWidget(Label_SegLine);

	//创建运行状态
	Label_State = new QLabel;
	Label_State->setFixedSize(QSize(35, 35));
	Label_State->setObjectName("Label_State");
	Label_State->setStyleSheet("background: transparent;");
	//Label_State->setToolTip(QString::fromUtf8("未运行"));
	this->addWidget(Label_State);

	//创建弹簧效果
	QWidget *spacer = new QWidget;
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->addWidget(spacer);

	//创建系统设置
	Btn_Setting = new MyLogoButton;
	Btn_Setting->SetMyParam("SystemSetIcon", tr("Setting"));
	Btn_Setting->SetWordSize(11);
	Btn_Setting->SetLogoSize(25, 25);
	Btn_Setting->setFixedSize(QSize(110, 30));
	Btn_Setting->setObjectName("ButtonSetting");
	Btn_Setting->setToolTip(tr("System Settings"));
	//Btn_Setting->setStyleSheet(MyStytleSheet("BtnSetting",""));
	QAction_Setting = this->addWidget(Btn_Setting);

	Btn_sqlDataSetting = new QToolButton;
	Btn_sqlDataSetting->setStyleSheet(MyStytleSheet("AlgoNone", "AlgoNone"));
	QAction_sqlDataSetting = this->addWidget(Btn_sqlDataSetting);

	this->setStyleSheet("QLabel#Label_State { border-image:url(\":/DynamicWidget/Resource/State_NoRunning.png\"); }");
}

void MyToolBar::InintConnet()
{
	connect(Btn_SignalGrab, &QToolButton::clicked, this, &MyToolBar::SingleGrabSignal);
	connect(Btn_ContinueGrab, &QToolButton::clicked, this, &MyToolBar::ContinueGrabSignal);
	connect(Btn_StopGrab, &QToolButton::clicked, this, &MyToolBar::StopGrabSignal);
	connect(Btn_Setting, &MyLogoButton::MyClicked, this, &MyToolBar::OpenSettingSignal);
	connect(Btn_sqlDataSetting, &QToolButton::clicked, this, &MyToolBar::OpenSqlDataSignal);
}

void MyToolBar::SetRuningState(RuningState inStata)
{
	QPixmap originaPixmapl, fitpixmap;
	switch (inStata)
	{
	case MyToolBar::isRunning:
		originaPixmapl.load(":/DynamicWidget/Resource/State_IsRuning.png");
		fitpixmap = originaPixmapl.scaled(BUTTON_WIDTH, BUTTON_HEIGHT, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		Label_State->setPixmap(fitpixmap);
		fitpixmap = originaPixmapl.scaled(BUTTON_WIDTH, BUTTON_HEIGHT, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		Label_State->setPixmap(fitpixmap);
		break;
	case MyToolBar::NoRunning:
		originaPixmapl.load(":/DynamicWidget/Resource/State_NoRunning.png");
		fitpixmap = originaPixmapl.scaled(BUTTON_WIDTH, BUTTON_HEIGHT, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		Label_State->setPixmap(fitpixmap);
		break;
	default:
		break;
	}
}

// 绘制标题栏背景色;
void MyToolBar::paintEvent(QPaintEvent *event)
{
	int MarginHeight = 2;

	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, MarginHeight, this->width(), this->height() - 2 * MarginHeight), 3, 3);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(pathBack, QBrush(QColor(50, 50, 50)));

	//上边缘绘制
	QPainterPath pathTop;
	pathTop.setFillRule(Qt::WindingFill);
	pathTop.addRoundedRect(QRect(0, 0, this->width(), MarginHeight), 3, 3);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(pathTop, QBrush(QColor(10, 10, 10)));

	//下边缘绘制
	QPainterPath pathBottom;
	pathBottom.setFillRule(Qt::WindingFill);
	pathBottom.addRoundedRect(QRect(0, this->height() - MarginHeight, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(pathBottom, QBrush(QColor(10, 10, 10)));

	QWidget::paintEvent(event);
}

QString MyToolBar::MyStytleSheet(QString ImageName, QString DisabledImage)
{
	QString BtnStyleSheet2 = QString("QToolButton{border-image:url(\":/DynamicWidget/Resource/%1.png\");border:none;}"
		"QToolButton:hover{background-color:rgb(80,80,80);}"
		"QToolButton:pressed{background-color:rgb(125,125,125);}"
		"QToolButton:disabled{border-image:url(\":/DynamicWidget/Resource/%2.png\");border:none;}").arg(ImageName).arg(DisabledImage);
	return BtnStyleSheet2;
}
