#include "ThresholdOCR.h"
#include "QTableWidget"
#include "UI/MyWidget/MyDoubleValidator.h"

ThresholdOCR::ThresholdOCR()
{
	ui.setupUi(this);
}

ThresholdOCR::~ThresholdOCR()
{
	if (m_MyLayOut != NULL)
	{
		delete m_OcrRowSort; delete m_OcrColumnSort;
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
	}
}

void ThresholdOCR::InintWindow(std::vector<std::string> inLabels)
{
	//删除旧布局
	if (m_MyLayOut == NULL)
	{
		m_MyLayOut = new QVBoxLayout(this);  //递增。需要清空
	}
	else
	{
		delete m_OcrRowSort; delete m_OcrColumnSort;
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
		m_MyLayOut = new QVBoxLayout;
	}


	//SDK阈值接口
	m_GridLayout = new QGridLayout(this);
	//①添加标签标题
	QLabel *m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Features"));
	m_Temp->setMaximumHeight(80);
	m_GridLayout->addWidget(m_Temp, 0, 0);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Confidence"));
	m_GridLayout->addWidget(m_Temp, 0, 1);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("IOU"));
	m_GridLayout->addWidget(m_Temp, 0, 2);
	//②添加字符标签内容
	for (int i = 0; i < inLabels.size(); i++)
	{
		m_GridLayout->addWidget(new QLabel(QString::fromLocal8Bit(inLabels[i].c_str()) + ":"), i + 1, 0);
		QLineEdit *sorceGrayLabel = new QLineEdit("0.5"); m_GridLayout->addWidget(sorceGrayLabel, i + 1, 1); m_labelScore.push_back(sorceGrayLabel);
		QLineEdit *iouGrayLabel = new QLineEdit("0.5"); m_GridLayout->addWidget(iouGrayLabel, i + 1, 2); m_labelIOU.push_back(iouGrayLabel);
		MyDoubleValidator *validator1 = new MyDoubleValidator(0, 1, 4, this);
		sorceGrayLabel->setValidator(validator1);
		MyDoubleValidator *validator2 = new MyDoubleValidator(0, 1, 4, this);
		iouGrayLabel->setValidator(validator2);
	}

	//字符串排序方式
	QHBoxLayout *m_H1 = new QHBoxLayout(this);
	QLabel *RadioLabel = new QLabel(tr("Sort By:")); RadioLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); RadioLabel->setMaximumHeight(80);
	m_H1->addWidget(RadioLabel);
	m_OcrRowSort = new QRadioButton(tr("Sort by X Coordinate")); m_OcrRowSort->setChecked(true);
	m_OcrColumnSort = new QRadioButton(tr("Sort by Y Coordinate"));
	m_H1->addWidget(m_OcrRowSort);
	m_H1->addWidget(m_OcrColumnSort);

	//字符串匹配
	QGroupBox *m_MatchRect = new QGroupBox(tr("Matched Strings"));
	//第二行输入的字符串列表
	m_TablePtr = new QTableWidget(this);
	InintTableWidget(m_TablePtr);
	connect(m_TablePtr, &QTableWidget::clicked, this, &ThresholdOCR::TableClickedSlot);
	//第一行输入编辑框
	QHBoxLayout *m_H1Hlayout = new QHBoxLayout;
	QLabel *m_Temp2 = new QLabel(tr("Enter Matched String:"));
	m_Temp2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp2->setMaximumHeight(80);
	m_H1Hlayout->addWidget(m_Temp2);
	QLineEdit* m_EditInStr = new QLineEdit;
	QPushButton *m_StrBtn = new QPushButton(tr("Add"));
	m_StrBtn->setMaximumWidth(120);
	connect(m_StrBtn, &QPushButton::clicked, this, [=]() {
		bool isContain = false;
		for (int i = 0; i < m_OcrStrVec.size(); i++)
		{
			if (m_EditInStr->text() == m_OcrStrVec[i])
			{
				isContain = true;
			}
		}
		if (isContain == false)
		{
			m_OcrStrVec.push_back(m_EditInStr->text());

			int iRow = m_TablePtr->rowCount();
			m_TablePtr->setRowCount(iRow + 1);//总行数增加1
			QString tempShow = m_EditInStr->text();
			QTableWidgetItem *item = new QTableWidgetItem(m_EditInStr->text());
			m_TablePtr->setItem(iRow, 0, item); //添加到界面
			m_TablePtr->item(iRow, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
	});
	m_H1Hlayout->addWidget(m_EditInStr);
	m_H1Hlayout->addWidget(m_StrBtn);
	//字符串匹配控件布局
	QVBoxLayout* m_V1Layout = new QVBoxLayout;
	m_V1Layout->addLayout(m_H1Hlayout);
	m_V1Layout->addWidget(m_TablePtr);
	m_MatchRect->setLayout(m_V1Layout);


	m_MyLayOut->addLayout(m_GridLayout);
	m_MyLayOut->addLayout(m_H1);
	m_MyLayOut->addWidget(m_MatchRect);

	//设置当前界面的布局内容
	this->setLayout(m_MyLayOut);
	ConnectIOU();
}

void ThresholdOCR::GetThreshold(ThresholdParams &inParam)
{
	OCRThreshold returnThreshold;
	//sdk接口阈值
	for (int i = 0; i < m_labelScore.size(); i++)
	{
		OcrSdkThreshold OneParam;
		OneParam._score = m_labelScore[i]->text().toDouble();
		OneParam._iou = m_labelIOU[i]->text().toDouble();
		returnThreshold.SdkThreshold.push_back(OneParam);
	}

	//字符串排序方式
	if (m_OcrColumnSort->isChecked())
		returnThreshold.SortFunction = SortByY;
	else
		returnThreshold.SortFunction = SortByX;

	//匹配字符串
	returnThreshold.MatchStrVec = m_OcrStrVec;

	inParam._ocrThreshold = returnThreshold;
}

void ThresholdOCR::LoadConfigThreshold(ThresholdParams inConfig)
{
	for (int i = 0; i < inConfig._ocrThreshold.SdkThreshold.size(); i++)
	{
		OcrSdkThreshold oneValue = inConfig._ocrThreshold.SdkThreshold[i];
		if (i < m_labelScore.size())
		{
			m_labelScore[i]->setText(QString::number(oneValue._score));
			m_labelIOU[i]->setText(QString::number(oneValue._iou));
		}
	}
	//添加匹配字符串
	//m_TablePtr->clear();
	m_TablePtr->setRowCount(0);
	m_OcrStrVec = inConfig._ocrThreshold.MatchStrVec;
	for (int i = 0; i < m_OcrStrVec.size(); i++)
	{
		int iRow = m_TablePtr->rowCount();
		m_TablePtr->setRowCount(iRow + 1);//总行数增加1
		QTableWidgetItem *item = new QTableWidgetItem(m_OcrStrVec[i]);
		m_TablePtr->setItem(iRow, 0, item); //添加到界面
		m_TablePtr->item(iRow, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	}


	//字符串排序方式
	if (inConfig._ocrThreshold.SortFunction == SortByX)
		m_OcrRowSort->setChecked(true);
	else
		m_OcrColumnSort->setChecked(true);
}

void ThresholdOCR::ConnectIOU()
{
	if (m_labelIOU.size() <= 1) return;
	for (int i = 0; i < m_labelIOU.size(); i++)
	{
		connect(m_labelIOU[i], &QLineEdit::textChanged, this, [=](const QString & inStr)
		{
			for (int j = 0; j < m_labelIOU.size(); j++)
			{
				if (m_labelIOU[j] != m_labelIOU[i])
				{
					m_labelIOU[j]->setText(inStr);
				}
			}
		});
	}
}

void ThresholdOCR::InintTableWidget(QTableWidget *m_FileWidget)
{
	m_FileWidget->setStyleSheet("QTableWidget{ border:1px solid #6B6B6B; } QTableCornerButton::section {background-color: rgb(60,60,60);border: 1px solid #000000;border-color: rgb(0, 0, 0);}");

	QFont font; font.setPointSize(11);
	m_FileWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_FileWidget->horizontalHeader()->setFont(font);
	m_FileWidget->horizontalHeader()->setHighlightSections(false);
	m_FileWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(60,60,60);}"); //41,136,41
	m_FileWidget->setColumnCount(1);
	//m_FileWidget->setAlternatingRowColors(1); //设置每行的颜色不一样
	m_FileWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(50,50,50);}");
	QStringList header; header << tr("Matched Strings");
	m_FileWidget->horizontalHeader()->setStretchLastSection(true);
	for (int t = 0; t < 1; t++)
	{
		QTableWidgetItem    *headerItem = new QTableWidgetItem(header.at(t)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
		m_FileWidget->setHorizontalHeaderItem(t, headerItem); //设置表头单元格的Item
	}

	//清除所有内容
	m_FileWidget->setRowCount(0);
	m_FileWidget->clearContents();
	m_FileWidget->setMaximumHeight(400);
}

void ThresholdOCR::TableClickedSlot(QModelIndex index)
{
	if (QMessageBox::Ok != QMessageBox::information(nullptr, tr("Tips"), tr("Are you sure you want to delete the matched string?"), QMessageBox::Ok | QMessageBox::Cancel))
		return;

	QObject* obj = sender();
	QTableWidget* TableWidgetPtr = dynamic_cast<QTableWidget*>(obj);
	int row = index.row();
	QString ImagePath = TableWidgetPtr->item(row, 0)->text();
	if (ImagePath.size() == 0)
	{
		return;
	}

	for (vector<QString>::iterator iter = m_OcrStrVec.begin(); iter != m_OcrStrVec.end(); iter++) //从vector中删除指定的某一个元素 
	{
		if (*iter == m_OcrStrVec[row])
		{
			m_OcrStrVec.erase(iter);
			break;
		}
	}
	TableWidgetPtr->removeRow(row);
}

//void ThresholdOCR::showEvent(QShowEvent *event)
//{
//	//获取当前模型版本（2.x的模型没有IOU阈值）
//	int ModelVersionIndex = std::atoi(m_ModelInfo.model_version.substr(0, 1).c_str());
//
//	if (ModelVersionIndex <= 2)
//	{
//		for (int cc = m_GridLayout->layout()->count() - 1; cc >= 0; --cc)
//		{
//			QLayoutItem *it = m_GridLayout->layout()->itemAt(cc);
//			QWidget *orderHistory = it->widget();
//			if (orderHistory != 0)
//			{
//				orderHistory->setVisible(false);
//			}
//		}
//	}
//	else
//	{
//		for (int cc = m_GridLayout->layout()->count() - 1; cc >= 0; --cc)
//		{
//			QLayoutItem *it = m_GridLayout->layout()->itemAt(cc);
//			QWidget *orderHistory = it->widget();
//			if (orderHistory != 0)
//			{
//				orderHistory->setVisible(true);
//			}
//		}
//	}
//	int trmpee1 = 0;
//}

void ThresholdOCR::SetModelInfo(ViMoModelInfo inInfo)
{
	//获取当前模型版本（2.x的模型没有IOU阈值）
	int ModelVersionIndex = std::atoi(inInfo.model_version.substr(0, 1).c_str());

	if (ModelVersionIndex <= 2)
	{
		for (int cc = m_GridLayout->layout()->count() - 1; cc >= 0; --cc)
		{
			QLayoutItem *it = m_GridLayout->layout()->itemAt(cc);
			QWidget *orderHistory = it->widget();
			if (orderHistory != 0)
			{
				orderHistory->setVisible(false);
			}
		}
	}
	else
	{
		for (int cc = m_GridLayout->layout()->count() - 1; cc >= 0; --cc)
		{
			QLayoutItem *it = m_GridLayout->layout()->itemAt(cc);
			QWidget *orderHistory = it->widget();
			if (orderHistory != 0)
			{
				orderHistory->setVisible(true);
			}
		}
	}
}