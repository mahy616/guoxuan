#include "ThresholdSegmentation.h"
#include <QMessageBox>
#include <QValidator>

ThresholdSegmentation::ThresholdSegmentation(bool FrontModelFlag)
{
	isFrontModel = FrontModelFlag;
	ui.setupUi(this);
}

ThresholdSegmentation::~ThresholdSegmentation()
{
	if (m_MyLayOut != NULL)
	{
		DeleteOldWidget(m_labelArea); DeleteOldWidget(m_labelWidth); DeleteOldWidget(m_labelHeight); DeleteOldWidget(m_MinGrayThreshold); DeleteOldWidget(m_MaxGrayThreshold);
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
	}
}

void ThresholdSegmentation::InintWindow(std::vector<std::string> inLabels)
{
	//删除旧布局
	if (m_MyLayOut == NULL)
	{
		m_MyLayOut = new QGridLayout(this);  //递增。需要清空
	}
	else
	{
		DeleteOldWidget(m_labelArea); DeleteOldWidget(m_labelWidth); DeleteOldWidget(m_labelHeight); DeleteOldWidget(m_MinGrayThreshold); DeleteOldWidget(m_MaxGrayThreshold);
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
		m_MyLayOut = new QGridLayout;
	}

	//添加标签标题
	QLabel *m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Features"));
	m_Temp->setMaximumHeight(80);
	m_MyLayOut->addWidget(m_Temp, 0, 0);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Area"));
	m_MyLayOut->addWidget(m_Temp, 0, 1);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Width"));
	m_MyLayOut->addWidget(m_Temp, 0, 2);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Height"));
	m_MyLayOut->addWidget(m_Temp, 0, 3);
	if (isFrontModel==false) //后置模块才有灰度值的过滤
	{
		m_MinGrayCheck = new QCheckBox(tr("Min Grayscale Value"));
		m_MyLayOut->addWidget(m_MinGrayCheck, 0, 4);
		connect(m_MinGrayCheck, &QCheckBox::stateChanged, this, [=](bool isEnable) { SetGrayEnable(isEnable, true); });

		m_MaxGrayCheck = new QCheckBox(tr("Max Grayscale Value"));
		m_MyLayOut->addWidget(m_MaxGrayCheck, 0, 5);
		connect(m_MaxGrayCheck, &QCheckBox::stateChanged, this, [=](bool isEnable) { SetGrayEnable(isEnable, false); });
	}

	//按顺序添加各个标签的输入框
	for (int i = 0; i < inLabels.size(); i++)
	{
		m_MyLayOut->addWidget(new QLabel(QString::fromLocal8Bit(inLabels[i].c_str()) + ":"), i + 1, 0);
		QLineEdit *areaLabel = new QLineEdit("0"); m_MyLayOut->addWidget(areaLabel, i + 1, 1); m_labelArea.push_back(areaLabel);
		QLineEdit *widthLabel = new QLineEdit("0"); m_MyLayOut->addWidget(widthLabel, i + 1, 2); m_labelWidth.push_back(widthLabel);
		QLineEdit *heightLabel = new QLineEdit("0"); m_MyLayOut->addWidget(heightLabel, i + 1, 3); m_labelHeight.push_back(heightLabel);
		QLineEdit *minGrayLabel = new QLineEdit("0"); if (isFrontModel == false) { m_MyLayOut->addWidget(minGrayLabel, i + 1, 4); }; m_MinGrayThreshold.push_back(minGrayLabel);
		QLineEdit *maxGrayLabel = new QLineEdit("255"); if (isFrontModel == false) { m_MyLayOut->addWidget(maxGrayLabel, i + 1, 5); }; m_MaxGrayThreshold.push_back(maxGrayLabel);

		QValidator *validator1 = new QIntValidator(0, 255, this); 
		minGrayLabel->setValidator(validator1);
		QValidator *validator2 = new QIntValidator(0, 255, this);
		maxGrayLabel->setValidator(validator2);
		QValidator *validator3 = new QIntValidator(0, 99999999, this);
		areaLabel->setValidator(validator3);
		QValidator *validator4 = new QIntValidator(0, 99999999, this);
		widthLabel->setValidator(validator4);
		QValidator *validator5 = new QIntValidator(0, 99999999, this);
		heightLabel->setValidator(validator5);
	}
	
	//设置当前界面的布局内容
	this->setLayout(m_MyLayOut);

	if (isFrontModel == false)
	{
		emit m_MinGrayCheck->stateChanged(false);
		emit m_MaxGrayCheck->stateChanged(false);
	}
}

void ThresholdSegmentation::GetThreshold(ThresholdParams &inParam)
{
	SegThreshold returnThreshold;
	if (isFrontModel == false)
	{
		returnThreshold._isFilterMaxGray = m_MaxGrayCheck->isChecked();
		returnThreshold._isFilterMinGray = m_MinGrayCheck->isChecked();
	}
	for (int i = 0; i < m_labelArea.size(); i++)
	{
		SegThresholdVec OneParam;
		if (m_labelArea[i]->text().toLong() >= 2147483647)
		{
			QMessageBox::information(nullptr, tr("Tips"), tr("Area Threshold has reached the upper limit. Failed to set Area Threshold."));
		}
		OneParam._area = m_labelArea[i]->text().toInt();
		OneParam._width = m_labelWidth[i]->text().toInt();
		OneParam._height = m_labelHeight[i]->text().toInt();
		OneParam._minGrayValue = m_MinGrayThreshold[i]->text().toInt();
		OneParam._maxGrayValue = m_MaxGrayThreshold[i]->text().toInt();
		returnThreshold._segThresholdVec.push_back(OneParam);
	}
	inParam._segThreshold = returnThreshold;
}

void ThresholdSegmentation::SetGrayEnable(bool isEnable, bool isMin)
{
	if (isMin)
	{
		for (int i = 0; i < m_MinGrayThreshold.size(); i++)
		{
			m_MinGrayThreshold[i]->setEnabled(isEnable);
		}
	}
	else
	{
		for (int i = 0; i < m_MaxGrayThreshold.size(); i++)
		{
			m_MaxGrayThreshold[i]->setEnabled(isEnable);
		}
	}
}

void ThresholdSegmentation::LoadConfigThreshold(ThresholdParams inConfig)
{
	if (isFrontModel == false)
	{
		m_MinGrayCheck->setChecked(inConfig._segThreshold._isFilterMinGray);
		m_MaxGrayCheck->setChecked(inConfig._segThreshold._isFilterMaxGray);
	}
	for (int i = 0; i < inConfig._segThreshold._segThresholdVec.size(); i++)
	{
		SegThresholdVec oneValue = inConfig._segThreshold._segThresholdVec[i];
		if (i < m_labelArea.size())
		{
			m_labelArea[i]->setText(QString::number(oneValue._area));
			m_labelWidth[i]->setText(QString::number(oneValue._width));
			m_labelHeight[i]->setText(QString::number(oneValue._height));
			m_MinGrayThreshold[i]->setText(QString::number(oneValue._minGrayValue));
			m_MaxGrayThreshold[i]->setText(QString::number(oneValue._maxGrayValue));
		}
	}
}