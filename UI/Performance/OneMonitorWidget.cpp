#include "OneMonitorWidget.h"

OneMonitorWidget::OneMonitorWidget(int GpuID, int inMaxMemory,QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::OneMonitorWidgetClass())
{
	ui->setupUi(this);
	ui->label_GPUID->setText(QString("GPU%1").arg(GpuID-1));
	ui->progressBar_MemoryBar->setMinimum(0);
	ui->progressBar_MemoryBar->setMaximum(inMaxMemory);

	connect(ui->btn_ControlVisiable, &QPushButton::clicked, this, &OneMonitorWidget::ControlVisibleSlot);
}

OneMonitorWidget::~OneMonitorWidget()
{
	delete ui;
}

void OneMonitorWidget::SetGpuInfos(GpuInfos inInfos)
{
	ui->Label_PerformanceWord->setText(QString::fromStdString(inInfos.Performance) + " ");
	ui->Label_TemperatureWord->setText(QString::fromStdString(inInfos.Temperature) + " ");
	ui->Label_UtilizationWord->setText(QString::fromStdString(inInfos.Utilization) + " ");
	ui->Label_PowerWord->setText(QString::fromStdString(inInfos.Power));
	ui->Label_MemoryNumWord->setText(QString::number(inInfos.AvailableMemory) + "/" + QString::number(inInfos.MaxMemory) + "(MiB)");
	ui->progressBar_MemoryBar->setValue(inInfos.AvailableMemory);


	if (inInfos.Performance != "P0")
		ui->Label_PerformanceWord->setStyleSheet("color:rgba(255,0,0,0.8);");
	else
		ui->Label_PerformanceWord->setStyleSheet("color:white;");
	if (inInfos.AvailableMemory * 10 / inInfos.MaxMemory > 8)
		ui->Label_MemoryNumWord->setStyleSheet("color:rgba(255,0,0,0.8);");
	else
		ui->Label_MemoryNumWord->setStyleSheet("color:white;");
}

void OneMonitorWidget::ControlVisibleSlot()
{
	isShow = !isShow;
	if (isShow) //Õ¹¿ª
	{
		this->setMaximumHeight(1000);
		ui->btn_ControlVisiable->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/GPU_Open.png\");border:none;}"
			"QPushButton:hover{background-color:rgb(45,45,45);}"
			"QPushButton:pressed{background-color:rgb(35,35,35);}");
		ui->widget->setVisible(true);
		emit ShowStateChangeSignal(true);
	}
	else //ÕÛµþ
	{
		this->setMaximumHeight(50);
		ui->btn_ControlVisiable->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/GPU_Hide.png\");border:none;}"
			"QPushButton:hover{background-color:rgb(45,45,45);}"
			"QPushButton:pressed{background-color:rgb(35,35,35);}");
		ui->widget->setVisible(false);
		this->update();
		emit ShowStateChangeSignal(false);
	}
}