#include "PerformanceMonitorTitle.h"

PerformanceMonitorTitle::PerformanceMonitorTitle(QDockWidget* inQDockWidget,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.btn_ControlVisiable->SetLogoSize(16, 16);
	ui.btn_ControlVisiable->SetMyParam("PerformanceOpen", tr("Performance Monitoring"));
	seeDockWidget = inQDockWidget;
	connect(ui.btn_ControlVisiable, &MyLogoButton::MyClicked, this, &PerformanceMonitorTitle::ControlVisibleSlot);
}

PerformanceMonitorTitle::~PerformanceMonitorTitle()
{}

void PerformanceMonitorTitle::ControlVisibleSlot()
{
	isShow = !isShow;
	if (isShow) //Õ¹¿ª
	{
		seeDockWidget->setMaximumHeight(1000);
		ui.btn_ControlVisiable->SetMyParam("PerformanceOpen", tr("Performance Monitoring"));
		//this->setMaximumHeight(1000);
		//ui.btn_ControlVisiable->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/PerformanceOpen.png\");border:none;}"
		//	"QPushButton:hover{background-color:rgb(45,45,45);}"
		//	"QPushButton:pressed{background-color:rgb(35,35,35);}");
		this->update();
		seeDockWidget->update();
	}
	else //ÕÛµş
	{
		ui.btn_ControlVisiable->SetMyParam("PerformanceHide", tr("Performance Monitoring"));
		//this->setMaximumHeight(50);
		//ui.btn_ControlVisiable->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/PerformanceHide.png\");border:none;}"
		//	"QPushButton:hover{background-color:rgb(45,45,45);}"
		//	"QPushButton:pressed{background-color:rgb(35,35,35);}");
		seeDockWidget->setMaximumHeight(30);
		this->update();
		seeDockWidget->update();
	}
}
