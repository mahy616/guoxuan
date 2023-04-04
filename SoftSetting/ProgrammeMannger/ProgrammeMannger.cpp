#include "ProgrammeMannger.h"
#include "components/Config/ConfigProgramme.h"
#include "CreateProgrammeName.h"
#include <QMessageBox>

ProgrammeMannger::ProgrammeMannger(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	inintMyTabel();
	LoadAllPro();

	connect(ui.btn_CreatePro, &QPushButton::clicked, this, &ProgrammeMannger::CreatePragrammeSlot);
	connect(ui.btn_DeletePro, &QPushButton::clicked, this, &ProgrammeMannger::DeleteProgrammeSlot);
	connect(ui.btn_DefaultPro, &QPushButton::clicked, this, &ProgrammeMannger::DefaultProgrammeSlot);
	connect(ui.btn_SavePro, &QPushButton::clicked, this, &ProgrammeMannger::SaveProgrammeSlot);
	connect(ui.btn_ChangePro, &QPushButton::clicked, this, &ProgrammeMannger::ChangeProgrammeSlot);

	//QFileInfo _FileName(ConfigProgramme::GetInstance()->m_Selectprogramme);
	//QString SelectPro = _FileName.baseName();
	SetNowProgrammeName(ConfigProgramme::GetInstance()->m_Selectprogramme);
}

void ProgrammeMannger::SetNowProgrammeName(QString inName)
{
	ui.label_programmName->setText(inName.toStdString().c_str());
}

ProgrammeMannger::~ProgrammeMannger()
{}



void ProgrammeMannger::inintMyTabel()
{
	//���캯��û����ǰ�����ڲ������յĴ�С����Ҫ�Ӹ���������layout��activate�����ڹ��캯�����ȡʵ�ʵĴ��ڳߴ�
	layout()->activate();
	ui.horizontalLayout->activate();
	ui.verticalLayout->activate();

	ui.tableWidget_Pro->setStyleSheet("QTableWidget{ color:#E0E0E0 ;background:transparent;border:1px solid #6B6B6B; } QTableWidget::item::selected{background-color:rgb(100,100,100);} QTableCornerButton::section {background-color: rgb(50,50,50);border: 0px solid #000000;border-color: rgb(0, 0, 0);}QTableWidget::item{ background:rgb(60,60,60); }");

	QFont font; font.setPointSize(8);
	ui.tableWidget_Pro->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Pro->horizontalHeader()->setFont(font);
	ui.tableWidget_Pro->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_Pro->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(60,60,60);}"); //41,136,41
	ui.tableWidget_Pro->setColumnCount(3);
	ui.tableWidget_Pro->setAlternatingRowColors(1); //����ÿ�е���ɫ��һ��
	ui.tableWidget_Pro->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(50,50,50);}");
	QStringList header; header << tr("Recipe Name") << tr("Window Count") << tr("Pipelines");
	ui.tableWidget_Pro->horizontalHeader()->setStretchLastSection(true);
	for (int t = 0; t < 3; t++)
	{
		QTableWidgetItem    *headerItem = new QTableWidgetItem(header.at(t)); //�½�һ��QTableWidgetItem�� headerText.at(i)��ȡheaderText��i���ַ���
		ui.tableWidget_Pro->setHorizontalHeaderItem(t, headerItem); //���ñ�ͷ��Ԫ���Item
	}
	//�����п����
	int temo = ui.tableWidget_Pro->width();
	ui.tableWidget_Pro->setColumnWidth(0, ui.tableWidget_Pro->width() * 0.3);
	ui.tableWidget_Pro->setColumnWidth(1, ui.tableWidget_Pro->width() * 0.2);
	ui.tableWidget_Pro->setColumnWidth(2, ui.tableWidget_Pro->width() * 0.5);
	//�����������
	ui.tableWidget_Pro->setRowCount(0);
	ui.tableWidget_Pro->clearContents();
	ui.tableWidget_Pro->verticalScrollBar()->setSingleStep(1);
}

void ProgrammeMannger::LoadAllPro()
{
	QString JsonPath = ".//config//programme";
	QStringList JsonList;
	QStringList Formats; Formats << "json" << "JSON";
	QDirIterator it(JsonPath, QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
	while (it.hasNext())
	{
		it.next();
		QFileInfo fileInfo = it.fileInfo();
		if (Formats.contains(fileInfo.suffix()))
		{ 
			if (fileInfo.baseName() != "WhichProgramme")
			{
				JsonList << fileInfo.absoluteFilePath();
			}
		}
	}

	ui.tableWidget_Pro->setRowCount(JsonList.size());
	ui.tableWidget_Pro->setEditTriggers(QAbstractItemView::NoEditTriggers);

	QString SelectProgramme = ConfigProgramme::GetInstance()->LoadWhichPro();
	for (int i = 0; i < JsonList.size(); ++i)
	{
		QFileInfo fileInfo(JsonList.at(i));
		QString file = fileInfo.baseName();
		QTableWidgetItem *item = new QTableWidgetItem(file);
		item->setBackgroundColor(QColor(125, 125, 125));
		ui.tableWidget_Pro->setItem(i, 0, item);
		ui.tableWidget_Pro->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		std::vector<QString> m_Models = ConfigProgramme::GetInstance()->LoadModelName(JsonList.at(i));
		QString ModelStr;
		for (int j = 0; j < m_Models.size(); j++)
		{
			ModelStr = ModelStr + tr("Window%1:%2,").arg(j+1).arg(m_Models[j]);
		}
		ModelStr = ModelStr.mid(0, ModelStr.size() - 1);

		QColor m_DrawColor;
		if (fileInfo.fileName() == SelectProgramme)
			m_DrawColor = QColor(0, 255, 0);
		else
			m_DrawColor = QColor(125, 125, 125);

		QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(m_Models.size()));
		item1->setBackgroundColor(m_DrawColor);
		ui.tableWidget_Pro->setItem(i, 1, item1);
		ui.tableWidget_Pro->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		QTableWidgetItem *item2 = new QTableWidgetItem(ModelStr);
		item2->setBackgroundColor(m_DrawColor);
		ui.tableWidget_Pro->setItem(i, 2, item2);
		ui.tableWidget_Pro->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	}

	//�����ǰ�������б�ؼ���û�ҵ���˵����֮ǰ�½���
	if (ConfigProgramme::GetInstance()->m_Selectprogramme.size() == 0) return;
	//QFileInfo _FileName(ConfigProgramme::GetInstance()->m_Selectprogramme);
	//QString SelectPro = _FileName.baseName();
	bool isNewPro = false;
	for (int i = 0; i < ui.tableWidget_Pro->rowCount(); i++)
	{
		QTableWidgetItem* item = ui.tableWidget_Pro->item(i, 0);
		if (ConfigProgramme::GetInstance()->m_Selectprogramme == item->text())
		{
			isNewPro = true;
		}
	}
	if (isNewPro == false)
	{
		ui.tableWidget_Pro->setRowCount(ui.tableWidget_Pro->rowCount() + 1);
		QTableWidgetItem *item = new QTableWidgetItem(ConfigProgramme::GetInstance()->m_Selectprogramme);
		item->setBackgroundColor(QColor(255, 255, 255));
		ui.tableWidget_Pro->setItem(ui.tableWidget_Pro->rowCount() - 1, 0, item);
		ui.tableWidget_Pro->item(ui.tableWidget_Pro->rowCount() - 1, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	}
}

void ProgrammeMannger::CreatePragrammeSlot()
{
	QStringList m_AllProName;
	for (int i = 0; i < ui.tableWidget_Pro->rowCount(); i++)
	{
		m_AllProName.append(ui.tableWidget_Pro->item(i, 0)->text());
	}
	CreateProgrammeName* m_CreateWidget = new CreateProgrammeName(m_AllProName);
	connect(m_CreateWidget, &CreateProgrammeName::CreateProName, this, [=](QString inStr)
	{
		ConfigProgramme::GetInstance()->m_Selectprogramme = inStr;

		ui.tableWidget_Pro->setRowCount(ui.tableWidget_Pro->rowCount() + 1);
		QTableWidgetItem *item = new QTableWidgetItem(inStr);
		item->setBackgroundColor(QColor(255, 255, 255));
		ui.tableWidget_Pro->setItem(ui.tableWidget_Pro->rowCount()-1, 0, item);
		ui.tableWidget_Pro->item(ui.tableWidget_Pro->rowCount()-1, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		delete m_CreateWidget;
		emit CreateNewPro();

		SetNowProgrammeName(inStr);
	});
	m_CreateWidget->setWindowModality(Qt::NonModal);
	m_CreateWidget->setAttribute(Qt::WA_ShowModal, true);
	m_CreateWidget->show();
}

void ProgrammeMannger::DeleteProgrammeSlot()
{
	std::vector<int> vecItemIndex;//����ѡ���е�����
	QItemSelectionModel *selections = ui.tableWidget_Pro->selectionModel(); //���ص�ǰ��ѡ��ģʽ  
	QModelIndexList selectedsList = selections->selectedIndexes(); //��������ѡ����ģ����Ŀ�����б�  
	if (selectedsList.count() == 0)
	{
		QMessageBox::information(nullptr, tr("Tips"), tr("Please select an recipe")); return;
	}
	for (int i = 0; i < selectedsList.count(); i++)
	{
		vecItemIndex.push_back(selectedsList.at(i).row());
	}
	std::sort(vecItemIndex.begin(), vecItemIndex.end(), [=](const int &a, const int  &b) { return a > b; });
	vecItemIndex.erase(std::unique(vecItemIndex.begin(), vecItemIndex.end()), vecItemIndex.end());

	//�Ի���Tips
	QString MessTips; bool isNowProgramm = false;
	for (int i = 0; i < vecItemIndex.size(); i++)
	{
		QTableWidgetItem* item = ui.tableWidget_Pro->item(vecItemIndex[i], 0);
		MessTips = MessTips + tr("Are you sure want to delete the recipe:%1\n?").arg(item->text());
		if (item->text() == ui.label_programmName->text()) isNowProgramm = true;
	}
	if (QMessageBox::Yes != QMessageBox::question(nullptr, tr("Please confirm"), MessTips)) return;
	
	if (isNowProgramm)
	{
		ui.label_programmName->setText("");
		ConfigProgramme::GetInstance()->m_Selectprogramme = "";
		emit CreateNewPro();
		ConfigProgramme::GetInstance()->SaveWhichPro("");
	}

	//QTableWidgetɾ�� -- �����򣬴Ӻ���ǰɾ��
	for (int k = 0; k < vecItemIndex.size(); k++)
	{
		QTableWidgetItem* item = ui.tableWidget_Pro->item(vecItemIndex[k], 0);
		QFile m_DeleteFile(".//config//programme//" + item->text() + ".json");
		if (m_DeleteFile.exists()) 
			m_DeleteFile.remove();
		ui.tableWidget_Pro->removeRow(vecItemIndex[k]);   //ɾ����
	}

}

void ProgrammeMannger::DefaultProgrammeSlot()
{
	std::vector<int> vecItemIndex;//����ѡ���е�����
	QItemSelectionModel *selections = ui.tableWidget_Pro->selectionModel(); //���ص�ǰ��ѡ��ģʽ  
	QModelIndexList selectedsList = selections->selectedIndexes(); //��������ѡ����ģ����Ŀ�����б�  
	if (selectedsList.count() == 0)
	{
		QMessageBox::information(nullptr, tr("Tips"), tr("Please select an recipe")); return;
	}
	for (int i = 0; i < selectedsList.count(); i++)
	{
		vecItemIndex.push_back(selectedsList.at(i).row());
	}
	vecItemIndex.erase(std::unique(vecItemIndex.begin(), vecItemIndex.end()), vecItemIndex.end());

	if (vecItemIndex.size() > 1) { QMessageBox::information(NULL, tr("Tips"), tr("%1 recipes selected, please select 1 recipe as default").arg(vecItemIndex.size())); return; }

	QTableWidgetItem* item3 = ui.tableWidget_Pro->item(vecItemIndex[0], 0);
	QString MessTips = tr("Set %1 as default startup recipe?").arg(item3->text());
	if (QMessageBox::Yes != QMessageBox::question(nullptr, tr("Please confirm"), MessTips)) return;

	QTableWidgetItem* item = ui.tableWidget_Pro->item(vecItemIndex[0], 0);
	ConfigProgramme::GetInstance()->SaveWhichPro(item->text());
}

void ProgrammeMannger::SaveProgrammeSlot()
{
	if (ui.label_programmName->text().size() == 0)
	{
		QMessageBox::information(nullptr, tr("Tips"), tr("Please create new recipe before saving")); return;
	}

	ConfigProgramme::GetInstance()->SaveConfig(ConfigProgramme::GetInstance()->m_Selectprogramme);

	QFileInfo _FileName(ConfigProgramme::GetInstance()->m_Selectprogramme);
	QString SelectPro = _FileName.baseName();
	bool isOk = false;
	for (int i = 0; i < ui.tableWidget_Pro->rowCount(); i++)
	{
		QTableWidgetItem* item = ui.tableWidget_Pro->item(i, 0);
		if (SelectPro == item->text())
		{
			//��ֻ��һ������ʱ ������
			int windowNums = ConfigProgramme::GetInstance()->AllConfig.size();
			QTableWidgetItem *item = new QTableWidgetItem(QString::number(windowNums));
			item->setBackgroundColor(QColor(255, 255, 255));
			ui.tableWidget_Pro->setItem(i, 1, item);
			ui.tableWidget_Pro->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

			QString ModelStr;
			std::vector<WindowsConfig> m_One = ConfigProgramme::GetInstance()->AllConfig;
			for (int j = 0; j < windowNums; j++)
			{		
				if (j >= m_One[j].m_ModelChoice.RealNameValue.size()) 
					ModelStr = ModelStr + tr("Window%1:Pipeline not found,").arg(j + 1);
				else
					ModelStr = ModelStr + tr("Window%1:%2,").arg(j + 1).arg(QString::fromLocal8Bit(m_One[j].m_ModelChoice.RealNameValue[m_One[j].m_ModelChoice.RealNameValue.size()-1].c_str()));
			}
			ModelStr = ModelStr.mid(0, ModelStr.size() - 1);

			QTableWidgetItem *item2 = new QTableWidgetItem(ModelStr);
			item2->setBackgroundColor(QColor(255, 255, 255));
			ui.tableWidget_Pro->setItem(i, 2, item2);
			ui.tableWidget_Pro->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

			QMessageBox::information(NULL, tr("Tips"), tr("%1 Save Successfully").arg(SelectPro));
			isOk = true;
			break;
		}
	}
	if (isOk == false) QMessageBox::information(NULL, tr("Tips"), tr("%1 Save Fail!").arg(SelectPro));
}

void ProgrammeMannger::ChangeProgrammeSlot()
{
	std::vector<int> vecItemIndex;//����ѡ���е�����
	QItemSelectionModel *selections = ui.tableWidget_Pro->selectionModel(); //���ص�ǰ��ѡ��ģʽ  
	QModelIndexList selectedsList = selections->selectedIndexes(); //��������ѡ����ģ����Ŀ�����б�  
	if (selectedsList.count() == 0)
	{
		QMessageBox::information(nullptr, tr("Tips"), tr("Please select an recipe")); return;
	}
	for (int i = 0; i < selectedsList.count(); i++)
	{
		vecItemIndex.push_back(selectedsList.at(i).row());
	}
	vecItemIndex.erase(std::unique(vecItemIndex.begin(), vecItemIndex.end()), vecItemIndex.end());

	if (vecItemIndex.size() > 1) { QMessageBox::information(NULL, tr("Tips"), tr("%1 recipes selected, please select 1 recipe as default").arg(vecItemIndex.size())); return; }

	QTableWidgetItem* item3 = ui.tableWidget_Pro->item(vecItemIndex[0], 0);
	QString MessTips = tr("Set %1 as Current?").arg(item3->text());
	if (QMessageBox::Yes != QMessageBox::question(nullptr, tr("Please confirm"), MessTips)) return;


	QTableWidgetItem* item = ui.tableWidget_Pro->item(vecItemIndex[0], 0);
	SetNowProgrammeName(item->text());
	emit ChangeProSlot(item->text());
}