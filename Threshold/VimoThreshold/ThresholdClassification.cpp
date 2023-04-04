#include "ThresholdClassification.h"
#include "UI/MyWidget/MyDoubleValidator.h"

ThresholdClassification::ThresholdClassification()
{
	ui.setupUi(this);
}

ThresholdClassification::~ThresholdClassification()
{
	if (m_MyLayOut != NULL)
	{
		DeleteOldWidget(m_labelScore);
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
	}
}

void ThresholdClassification::InintWindow(std::vector<std::string> inLabels)
{
	//删除旧布局
	if (m_MyLayOut == NULL)
	{
		m_MyLayOut = new QGridLayout(this);  //递增。需要清空
	}
	else
	{
		DeleteOldWidget(m_labelScore);
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
	m_Temp->setText(tr("Confidence"));
	m_MyLayOut->addWidget(m_Temp, 0, 1);


	//按顺序添加各个标签的输入框
	for (int i = 0; i < inLabels.size(); i++)
	{
		m_MyLayOut->addWidget(new QLabel(QString::fromLocal8Bit(inLabels[i].c_str()) + ":"), i + 1, 0);
		QLineEdit *sorceLabel = new QLineEdit("0"); m_MyLayOut->addWidget(sorceLabel, i + 1, 1); m_labelScore.push_back(sorceLabel);		
		MyDoubleValidator *validator1 = new MyDoubleValidator(0.0, 1.0, 4, this);
		sorceLabel->setValidator(validator1);
	}

	//设置当前界面的布局内容
	this->setLayout(m_MyLayOut);
}

void ThresholdClassification::GetThreshold(ThresholdParams &inParam)
{
	ClassificationThreshold returnThreshold;
	for (int i = 0; i < m_labelScore.size(); i++)
	{
		ClassificationThresholdVec OneParam;
		OneParam._score = m_labelScore[i]->text().toDouble();
		returnThreshold._classificationThresholdVec.push_back(OneParam);
	}
	inParam._classificationThreshold = returnThreshold;
}

void ThresholdClassification::LoadConfigThreshold(ThresholdParams inConfig)
{
	for (int i = 0; i < inConfig._classificationThreshold._classificationThresholdVec.size(); i++)
	{
		ClassificationThresholdVec oneValue = inConfig._classificationThreshold._classificationThresholdVec[i];
		if (i < m_labelScore.size())
		{
			m_labelScore[i]->setText(QString::number(oneValue._score));
		}
	}
}