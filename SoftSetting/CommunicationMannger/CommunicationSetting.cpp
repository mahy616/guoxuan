#include "CommunicationSetting.h"
#include "UI/MyWidget/SetingItem.h"
#include <QMessageBox>
#include "UI/MyWidget/MyLogoButton.h"

CommunicationSetting::CommunicationSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	inintWindow();
	ui.btn_Add->SetLogoSize(18, 18);
	ui.btn_Add->SetWordSize(8);
	ui.btn_Add->SetMyParam("BtnAdd", tr("Add"));
	connect(ui.btn_Add, &MyLogoButton::MyClicked, this, &CommunicationSetting::BtnAddCommunicate);

	ui.btn_Reduce->SetLogoSize(18, 18);
	ui.btn_Reduce->SetWordSize(8);
	ui.btn_Reduce->SetMyParam("Btn_Reduce", tr("Reduce"));
	connect(ui.btn_Reduce, &MyLogoButton::MyClicked, this, &CommunicationSetting::BtnDeleteCommunicata);
	//connect(ui.btn_DeleteCommunication, &QPushButton::clicked, this, &CommunicationSetting::BtnDeleteCommunicata);
	connect(ui.listWidget_AddContents, SIGNAL(currentRowChanged(int)), ui.stackedWidget_Communication, SLOT(setCurrentIndex(int)));
}

CommunicationSetting::~CommunicationSetting()
{
	disconnect(ui.listWidget_AddContents, SIGNAL(currentRowChanged(int)), ui.stackedWidget_Communication, SLOT(setCurrentIndex(int)));
	ClearAllCommunication();
}

void CommunicationSetting::ClearAllCommunication()
{
	int n = ui.listWidget_AddContents->count();
	for (int i = 0; i < n; i++)
	{
		QListWidgetItem *item = ui.listWidget_AddContents->takeItem(0);
		delete item;
	}
	for (int i = ui.stackedWidget_Communication->count(); i >= 0; i--)
	{
		QWidget* widget = ui.stackedWidget_Communication->widget(i);
		ui.stackedWidget_Communication->removeWidget(widget);
		widget->deleteLater();
	}
}

void CommunicationSetting::showEvent(QShowEvent *event)
{
	inintWindow();
	return QWidget::showEvent(event);
}

void CommunicationSetting::inintWindow()
{
	ClearAllCommunication();
	QMap<QString, CommunicateBase*>::const_iterator iterator_1 = ConfigProgramme::GetInstance()->m_Comunicate.constBegin();
	while (iterator_1 != ConfigProgramme::GetInstance()->m_Comunicate.constEnd())
	{
		ReSetOneCommunicate(iterator_1.key(), iterator_1.value());
		++iterator_1;
	}

}

void CommunicationSetting::BtnAddCommunicate()
{
	AddCommunicationDialog * m_AddItem = new AddCommunicationDialog(ui.listWidget_AddContents->count() + 1);
	connect(m_AddItem, &AddCommunicationDialog::SendAddCommunicate, this, [=](QString name, QString type) { AddOneCommunicate(name, type); });
	m_AddItem->setAttribute(Qt::WA_ShowModal, true);
	m_AddItem->show();
}

void CommunicationSetting::BtnDeleteCommunicata()
{

	int row = ui.listWidget_AddContents->currentRow();//获取当前鼠标所选行

	if (row < 0)
	{
		QMessageBox::information(nullptr, tr("tips"), tr("Please select the communication object"));
		return;
	}
	else
	{
		/*QString MessTips = tr("Are you sure want to delete the communication:%1\n?").arg(ui.listWidget_AddContents->currentItem()->GetName());
		if (QMessageBox::Yes != QMessageBox::question(nullptr, tr("Please confirm"), MessTips)) return;*/
	}

	//删除单例里的通信模块
	QListWidgetItem*m_DeleteItem = ui.listWidget_AddContents->item(row);
	SetingItem* pDeviceItem = dynamic_cast<SetingItem*>(ui.listWidget_AddContents->itemWidget(m_DeleteItem));
	QMap<QString, CommunicateBase*>::iterator it;
	for (it = ConfigProgramme::GetInstance()->m_Comunicate.begin(); it != ConfigProgramme::GetInstance()->m_Comunicate.end();)
	{
		if (it.key() == pDeviceItem->GetName())
		{
			it = ConfigProgramme::GetInstance()->m_Comunicate.erase(it);
			continue;
		}
		++it;
	}

	//删除列表里的名称
	ui.listWidget_AddContents->takeItem(row);//删除该行

	//删除stackedWidget里的页
	QWidget* widgetsss = ui.stackedWidget_Communication->widget(row);
	ui.stackedWidget_Communication->removeWidget(widgetsss);
	widgetsss->deleteLater();
}

void CommunicationSetting::AddOneCommunicate(QString newName, QString newType)
{
	if (ConfigProgramme::GetInstance()->m_Comunicate.count(newName)) //如果已存在命名
	{
		QMessageBox::information(NULL, tr("Tips"), tr("Communication name exists, please rename the module")); return;
	}

	QString logoName;
	CommunicateBase* m_InserCommunicate;
	if (newType == "Ethernet Port")
	{
		m_InserCommunicate = new CommunicateTCP;
		logoName = "Scoket.png";
	}
	if (newType == "Serial Port")
	{
		m_InserCommunicate = new CommunicateSerial;
		logoName = "Com.png";
	}
	if (newType == "Mitsubishi MC")
	{
		m_InserCommunicate = new CommunicateMC_Bin;
		logoName = "MC.png";
	}

	QListWidgetItem* pListWidgetItem = new QListWidgetItem;
	pListWidgetItem->setSizeHint(QSize(100, 50));
	SetingItem* pDeviceItem = new SetingItem;
	pDeviceItem->SetMyWidget(logoName, newName);

	ui.listWidget_AddContents->addItem(pListWidgetItem);
	ui.listWidget_AddContents->setItemWidget(pListWidgetItem, pDeviceItem);
	

	ui.stackedWidget_Communication->addWidget(m_InserCommunicate->OpenSetting());

	ConfigProgramme::GetInstance()->m_Comunicate.insert(newName, m_InserCommunicate);

	ui.listWidget_AddContents->setCurrentItem(pListWidgetItem);
}

void CommunicationSetting::ReSetOneCommunicate(QString newName, CommunicateBase* m_Communicate)
{
	QString logoName;
	if (m_Communicate->GetCommunicationType() == "Ethernet Port")
	{
		logoName = "Scoket.png";
	}
	if (m_Communicate->GetCommunicationType() == "Serial Port")
	{
		logoName = "Com.png";
	}
	if (m_Communicate->GetCommunicationType() == "Mitsubishi MC")
	{
		logoName = "MC.png";
	}


	QListWidgetItem* pListWidgetItem = new QListWidgetItem;
	pListWidgetItem->setSizeHint(QSize(100, 50));
	SetingItem* pDeviceItem = new SetingItem;
	pDeviceItem->SetMyWidget(logoName, newName);

	ui.listWidget_AddContents->addItem(pListWidgetItem);
	ui.listWidget_AddContents->setItemWidget(pListWidgetItem, pDeviceItem);
	ui.stackedWidget_Communication->addWidget(m_Communicate->OpenSetting());
	ui.listWidget_AddContents->setCurrentRow(0);
}
