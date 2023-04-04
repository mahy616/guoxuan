#include "ThresholdDetection.h"
#include "UI/MyWidget/MyDoubleValidator.h"

ThresholdDetection::ThresholdDetection()
{
	ui.setupUi(this);
}

ThresholdDetection::~ThresholdDetection()
{
	if (m_MyLayOut != NULL)
	{
		DeleteOldWidget(m_labelArea); DeleteOldWidget(m_labelWidth); DeleteOldWidget(m_labelHeight); DeleteOldWidget(m_labelScore); DeleteOldWidget(m_labelIOU);
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
	}
}

void ThresholdDetection::InintWindow(std::vector<std::string> inLabels)
{
	//删除旧布局
	if (m_MyLayOut == NULL)
	{
		m_MyLayOut = new QGridLayout;  //递增。需要清空
	}
	else
	{
		DeleteOldWidget(m_labelArea); DeleteOldWidget(m_labelWidth); DeleteOldWidget(m_labelHeight); DeleteOldWidget(m_labelScore); DeleteOldWidget(m_labelIOU);
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
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Confidence"));
	m_MyLayOut->addWidget(m_Temp, 0, 4);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("IOU"));
	m_MyLayOut->addWidget(m_Temp, 0, 5);
	

	//按顺序添加各个标签的输入框
	for (int i = 0; i < inLabels.size(); i++)
	{
		m_MyLayOut->addWidget(new QLabel(QString::fromLocal8Bit(inLabels[i].c_str()) + ":"), i + 1, 0);
		QLineEdit *areaLabel = new QLineEdit("0"); m_MyLayOut->addWidget(areaLabel, i + 1, 1); m_labelArea.push_back(areaLabel);
		QLineEdit *widthLabel = new QLineEdit("0"); m_MyLayOut->addWidget(widthLabel, i + 1, 2); m_labelWidth.push_back(widthLabel);
		QLineEdit *heightLabel = new QLineEdit("0"); m_MyLayOut->addWidget(heightLabel, i + 1, 3); m_labelHeight.push_back(heightLabel);
		QLineEdit *sorceGrayLabel = new QLineEdit("0.5"); m_MyLayOut->addWidget(sorceGrayLabel, i + 1, 4); m_labelScore.push_back(sorceGrayLabel);
		QLineEdit *iouGrayLabel = new QLineEdit("0.5"); m_MyLayOut->addWidget(iouGrayLabel, i + 1, 5); m_labelIOU.push_back(iouGrayLabel);
	
		QValidator *validator3 = new QIntValidator(0, 99999999, this);
		areaLabel->setValidator(validator3);
		QValidator *validator4 = new QIntValidator(0, 99999999, this);
		widthLabel->setValidator(validator4);
		QValidator *validator5 = new QIntValidator(0, 99999999, this);
		heightLabel->setValidator(validator5);
		MyDoubleValidator *validator1 = new MyDoubleValidator(0, 1, 4 ,this);
		sorceGrayLabel->setValidator(validator1);
		MyDoubleValidator *validator2 = new MyDoubleValidator(0, 1, 4, this);
		iouGrayLabel->setValidator(validator2);
	}
	//设置当前界面的布局内容
	this->setLayout(m_MyLayOut);

	ConnectIOU();
}

void ThresholdDetection::ConnectIOU()
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

void ThresholdDetection::GetThreshold(ThresholdParams &inParam)
{
	DetectionThreshold returnThreshold;
	for (int i = 0; i < m_labelArea.size(); i++)
	{
		DetectionThresholdVec OneParam;
		OneParam._area = m_labelArea[i]->text().toInt();
		OneParam._width = m_labelWidth[i]->text().toInt();
		OneParam._height = m_labelHeight[i]->text().toInt();
		OneParam._score = m_labelScore[i]->text().toDouble();
		OneParam._iou = m_labelIOU[i]->text().toDouble();
		returnThreshold._detectionThresholdVec.push_back(OneParam);
	}
	inParam._detectionThreshold = returnThreshold;
}

void ThresholdDetection::LoadConfigThreshold(ThresholdParams inConfig)
{
	for (int i = 0; i < inConfig._detectionThreshold._detectionThresholdVec.size(); i++)
	{
		DetectionThresholdVec oneValue = inConfig._detectionThreshold._detectionThresholdVec[i];
		if (i < m_labelScore.size())
		{
			m_labelArea[i]->setText(QString::number(oneValue._area));
			m_labelWidth[i]->setText(QString::number(oneValue._width));
			m_labelHeight[i]->setText(QString::number(oneValue._height));
			m_labelScore[i]->setText(QString::number(oneValue._score));
			m_labelIOU[i]->setText(QString::number(oneValue._iou));
		}
	}
}