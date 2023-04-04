#include "SoftSetting.h"
#include "components/Config/ConfigProgramme.h"


SoftSetting::SoftSetting()
{
	ui.setupUi(this);

	inintWindow();
}

SoftSetting::~SoftSetting()
{
	delete m_ProgrammeMannger;
	delete m_SaveWidget;
	//todo::遍历删除
}

void SoftSetting::inintWindow()
{
	QListWidgetItem* pListWidgetItemSaveImage = new QListWidgetItem;
	QListWidgetItem* pListWidgetItemProgramme = new QListWidgetItem;
	//QListWidgetItem* pListWidgetItemStationProcess = new QListWidgetItem;
	QListWidgetItem* pListWidgetItemCommunication = new QListWidgetItem;
	QListWidgetItem* pListWidgetItemLanguage = new QListWidgetItem;

	//新增
	//QListWidgetItem* pListWidgetItemFormula = new QListWidgetItem;
	//pListWidgetItemFormula->setSizeHint(QSize(150, 50));
	//SetingItem* pDeviceItemFormula = new SetingItem;
	//pDeviceItemFormula->SetMyWidget("ProgrammeIcon.png", tr("Recipe Management"));
	//ui.listWidget_Icon->addItem(pListWidgetItemFormula);
	//ui.listWidget_Icon->setItemWidget(pListWidgetItemFormula, pDeviceItemFormula);
	//
	pListWidgetItemSaveImage->setSizeHint(QSize(150, 50));
	pListWidgetItemProgramme->setSizeHint(QSize(150, 50));
	pListWidgetItemLanguage->setSizeHint(QSize(150, 50));
	pListWidgetItemCommunication->setSizeHint(QSize(150, 50));

	SetingItem* pDeviceItemSaveImage = new SetingItem;
	pDeviceItemSaveImage->SetMyWidget("SaveImageIcon.png", tr("SaveImage"));
	SetingItem* pDeviceItemProgramme = new SetingItem;
	pDeviceItemProgramme->SetMyWidget("ProgrammeIcon.png", tr("Recipe Management"));
	//SetingItem* pDeviceItemStationProcess = new SetingItem;
	//pDeviceItemStationProcess->SetMyWidget("StationProcess.png", tr("流程设计"));
	SetingItem* pDeviceItemCommunication = new SetingItem;
	pDeviceItemCommunication->SetMyWidget("Communicate.png", tr("Communication"));
	SetingItem* pDeviceItemLanguage = new SetingItem;
	pDeviceItemLanguage->SetMyWidget("Language.png", tr("Display"));

	ui.listWidget_Icon->addItem(pListWidgetItemProgramme);
	ui.listWidget_Icon->addItem(pListWidgetItemSaveImage);
	//ui.listWidget_Icon->addItem(pListWidgetItemStationProcess);
	ui.listWidget_Icon->addItem(pListWidgetItemCommunication);
	ui.listWidget_Icon->addItem(pListWidgetItemLanguage);
	
	ui.listWidget_Icon->setItemWidget(pListWidgetItemProgramme, pDeviceItemProgramme);
	ui.listWidget_Icon->setItemWidget(pListWidgetItemSaveImage, pDeviceItemSaveImage);
	//ui.listWidget_Icon->setItemWidget(pListWidgetItemStationProcess, pDeviceItemStationProcess);
	ui.listWidget_Icon->setItemWidget(pListWidgetItemCommunication, pDeviceItemCommunication);
	ui.listWidget_Icon->setItemWidget(pListWidgetItemLanguage, pDeviceItemLanguage);

	//图片保存
	m_SaveWidget = new QWidget(this);
	QHBoxLayout *m_HLayOut = new QHBoxLayout(this);
	SaveImageWidget *m_CameraSaveWidget = new SaveImageWidget(true,this);
	m_CameraSaveWidget->inintLoadParam(ConfigProgramme::GetInstance()->m_CameraSave);
	SaveImageWidget *m_RenderSaveWidget = new SaveImageWidget(false, this);
	m_RenderSaveWidget->inintLoadParam(ConfigProgramme::GetInstance()->m_RenderSave);
	m_HLayOut->addWidget(m_CameraSaveWidget);
	m_HLayOut->addWidget(m_RenderSaveWidget);
	m_SaveWidget->setLayout(m_HLayOut);

	
	//方案管理
	m_ProgrammeMannger = new ProgrammeMannger;
	connect(m_ProgrammeMannger, &ProgrammeMannger::CreateNewPro, this, &SoftSetting::CreateNewProSingal);
	connect(m_ProgrammeMannger, &ProgrammeMannger::ChangeProSlot, this, &SoftSetting::ChangleNewProSingal);

	//通信设置
	m_Communicate = new CommunicationSetting;
	
	//显示设置
	m_ShowSetting = new ShowSetting;


	ui.stackedWidget_Widget->addWidget(m_ProgrammeMannger);
	ui.stackedWidget_Widget->addWidget(m_SaveWidget);
	//ui.stackedWidget_Widget->addWidget(new QLabel(tr("待开发")));
	ui.stackedWidget_Widget->addWidget(m_Communicate);
	ui.stackedWidget_Widget->addWidget(m_ShowSetting);
	
	connect(ui.listWidget_Icon, SIGNAL(currentRowChanged(int)), ui.stackedWidget_Widget, SLOT(setCurrentIndex(int)));
	connect(ui.listWidget_Icon, &QListWidget::currentRowChanged, ui.stackedWidget_Widget, [=](int index) {
		if (index != 1)
		{
			m_CameraSaveWidget->UpdateSaveConfig();
			m_RenderSaveWidget->UpdateSaveConfig();
		}
	});
	ui.listWidget_Icon->setCurrentRow(0);
}

void SoftSetting::closeEvent(QCloseEvent *e)
{
	disconnect(ui.listWidget_Icon, SIGNAL(currentRowChanged(int)), ui.stackedWidget_Widget, SLOT(setCurrentIndex(int)));
	//把所有StackWidget的Widget释放掉
	for (int i = ui.stackedWidget_Widget->count(); i >= 0; i--)
	{
		QWidget* widget = ui.stackedWidget_Widget->widget(i);
		ui.stackedWidget_Widget->removeWidget(widget);
		widget->deleteLater();
	}
	//把所有listWidget的Widget释放掉
	int counter = ui.listWidget_Icon->count();
	QListWidgetItem *item;
	for (int index = 0; index < counter; index++)
	{
		item = ui.listWidget_Icon->takeItem(0);
		if (item != NULL)
			delete item;
	}

	delete m_SaveWidget;
}
