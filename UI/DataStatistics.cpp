#include "DataStatistics.h"
#include <QScrollBar>

DataStatistics::DataStatistics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.btn_ControlVisiable->SetMyParam("ShowCross", tr("Data Statistics"));
	ui.btn_ControlVisiable->SetWordSize(11);
	ui.btn_ControlVisiable->SetLogoSize(14, 14);

	connect(ui.btn_ReSet, &QPushButton::clicked, this, &DataStatistics::ResetDataSlot);
	connect(ui.btn_ControlVisiable, &MyLogoButton::MyClicked, this, &DataStatistics::ControlVisibleSlot);
	connect(ui.btn_LabelToLeft, &QPushButton::clicked, this, &DataStatistics::LabelsLeftClickedSlot);
	connect(ui.btn_LabelToRight, &QPushButton::clicked, this, &DataStatistics::LabelsRightClickedSlot);

	ui.btn_LabelToLeft->setVisible(false);
	ui.btn_LabelToRight->setVisible(false);
	ui.scrollArea->setVisible(false);

}

DataStatistics::~DataStatistics()
{}

void DataStatistics::ResetDataSlot()
{
	m_total = 0;
	m_ok = 0;
	m_ng = 0;
	ui.label_TotalNums->setText(QString::number(0));
	ui.label_ok->setText(QString::number(0));
	ui.label_NG->setText(QString::number(0));
	ui.label_rate->setText(QString::number(0));
	if (myModelType != OCR)
		ClearLabelsData();
}

void DataStatistics::GetAlgoResultSlot(int TableIndex, bool bOK, double Time, QString tableWord)
{
	m_total++;
	ui.label_TotalNums->setText(QString::number(m_total));

	bOK ? m_ok++ : m_ng++;
	ui.label_ok->setText(QString::number(m_ok));
	ui.label_NG->setText(QString::number(m_ng));
	float m_rate = m_ok * 100 / m_total;
	char StrRate[30]; sprintf_s(StrRate, "%0.2f", m_rate);
	ui.label_rate->setText(QString(StrRate));

	if (myModelType != OCR)
	{
		if (bOK == false)
		{
			QStringList labelList = tableWord.split(tr(","));
			for (int i = 0; i < labelList.size(); i++)
			{
				QMap<QString, DataStatis*>::iterator it = m_LabelMap.find(labelList[i]);
				if (it != m_LabelMap.end())
				{
					it.value()->Label_Nums++;
					it.value()->m_Labels->setText(QString::number(it.value()->Label_Nums));
				}
			}
		}
	}
}

void DataStatistics::GetModelChangeSlot(ModelChoice inModelChoice)
{
	if (m_LabelsLayOut == nullptr) m_LabelsLayOut = new QHBoxLayout;

	if (LastTypeName == inModelChoice.TypeName)
		return;
	ClearLayout(m_LabelsLayOut);

	m_total = 0; ui.label_TotalNums->setText(QString::number(0));
	LastTypeName = inModelChoice.TypeName;
	myModelType = GetModelTypeFromString(inModelChoice.modeType[inModelChoice.modeType.size() - 1]);
	m_LabelMap.clear();

	ClearLabelsData();

	if (myModelType != OCR) //OCR不生成标签
	{
		std::vector<std::string> LableNames = inModelChoice.labelsNamesVec[inModelChoice.labelsNamesVec.size() - 1];
		for (int i = 0; i < LableNames.size(); i++)
		{
			// ****************** 标签控件 *******************
			QFrame *m_frame = new QFrame;
			m_frame->setStyleSheet("color:white;background-color:rgb(60,60,60);border-radius:4;border:1px solid #4F4F4F;");
			m_frame->setMinimumHeight(50);
			m_frame->setMinimumWidth(50);

			DataStatis *m_TempStatis = new DataStatis;
			m_TempStatis->m_Labels = new QLabel("0");
			m_TempStatis->m_Labels->setStyleSheet("background:\"transparent\";border:none;color:white");
			QLabel *m_Words = new QLabel(QString::fromLocal8Bit(LableNames[i].c_str()));
			m_TempStatis->m_Labels->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			m_Words->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			m_Words->setStyleSheet("background:\"transparent\";border:none;color:#999999;");
			QFont ft;
			ft.setPointSize(11);
			//ft.setFamily("KaiTi");
			m_TempStatis->m_Labels->setFont(ft);
			m_Words->setFont(ft);
			QVBoxLayout *m_VeticallayOut = new QVBoxLayout;
			m_VeticallayOut->addWidget(m_TempStatis->m_Labels);
			m_VeticallayOut->addWidget(m_Words);
			m_VeticallayOut->setContentsMargins(5, 0, 5, 0);
			m_frame->setLayout(m_VeticallayOut);
			// **********************************************
			m_LabelMap.insert(QString::fromLocal8Bit(LableNames[i].c_str()), m_TempStatis);
			m_LabelsLayOut->addWidget(m_frame);
			m_LabelsLayOut->setContentsMargins(5, 0, 5, 0);
		}
		if (LableNames.size() != 0)
		{
			ui.btn_LabelToLeft->setVisible(true);
			ui.btn_LabelToRight->setVisible(true);
			ui.scrollArea->setVisible(true);
			ui.scrollAreaWidgetContents->setLayout(m_LabelsLayOut);
		}
	}
	else
	{
		ui.btn_LabelToLeft->setVisible(false);
		ui.btn_LabelToRight->setVisible(false);
		ui.scrollArea->setVisible(false);
	}
}

void DataStatistics::ClearLabelsData()
{
	QMap<QString, DataStatis*>::const_iterator itss = m_LabelMap.constBegin();
	while (itss != m_LabelMap.constEnd())
	{
		itss.value()->m_Labels->setText(QString::number(0));
		itss.value()->Label_Nums = 0;
		++itss;
	}
}

void DataStatistics::ControlVisibleSlot()
{
	isShow = !isShow;
	if (isShow) //展开
	{
		this->setMaximumHeight(1000);
		ui.btn_ControlVisiable->SetMyParam("ShowCross", tr("Data Statistics"));
		ui.widget_ControlVisual->setVisible(true);
	}
	else //折叠
	{
		ui.btn_ControlVisiable->SetMyParam("HideCross", tr("Data Statistics"));
		ui.widget_ControlVisual->setVisible(false);
		this->setMaximumHeight(50);
		this->update();
	}
}

void DataStatistics::LabelsLeftClickedSlot()
{
	SliderNums = SliderNums - 5;
	if (SliderNums < 0) SliderNums = 0;
	ui.scrollArea->horizontalScrollBar()->setSliderPosition(SliderNums);
}

void DataStatistics::LabelsRightClickedSlot()
{
	SliderNums = SliderNums + 5;
	if (SliderNums > ui.scrollArea->horizontalScrollBar()->maximum()) SliderNums = ui.scrollArea->horizontalScrollBar()->maximum();
	ui.scrollArea->horizontalScrollBar()->setSliderPosition(SliderNums);

}

void DataStatistics::WorkStateChange(bool isWork)
{
	ui.btn_ReSet->setEnabled(!isWork);
}

void DataStatistics::SetOkNgShow(bool showFlag)
{
	for (int cc = ui.horizontalLayout_3->layout()->count() - 1; cc >= 0; --cc)
	{
		QLayoutItem *it = ui.horizontalLayout_3->layout()->itemAt(cc);
		QWidget *orderHistory = it->widget();
		if (orderHistory != 0)
		{
			orderHistory->setVisible(showFlag);
		}
	}
}