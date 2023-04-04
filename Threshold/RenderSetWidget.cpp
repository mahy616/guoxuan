#include "RenderSetWidget.h"
#include <QValidator>

RenderSetWidget::RenderSetWidget(std::vector<std::string> inLableNames,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	SetMyParamter(inLableNames);
}

RenderSetWidget::~RenderSetWidget()
{
	if (m_MyLayOut != NULL)
	{
		DeleteOldWidget(m_Thickness); DeleteOldWidget(m_Colors);
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
	}
}

void RenderSetWidget::SetMyParamter(std::vector<std::string> inLableNames)
{
	if (inLableNames.size() == 0)
	{
		if (m_MyLayOut != NULL) ClearLayout(m_MyLayOut);
		this->setLayout(m_MyLayOut);
		return;
	}

	if (m_MyLayOut == NULL)
	{
		m_MyLayOut = new QGridLayout;  //递增。需要清空
	}
	else
	{
		ClearLayout(m_MyLayOut);
		delete m_MyLayOut;
		m_MyLayOut = NULL;
		m_MyLayOut = new QGridLayout;
	}


	QLabel *m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Label"));
	m_Temp->setMaximumHeight(80);
	m_MyLayOut->addWidget(m_Temp, 0, 0);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Outline Width"));
	m_MyLayOut->addWidget(m_Temp, 0, 1);
	m_Temp = new QLabel;
	m_Temp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_Temp->setText(tr("Outline Color"));
	m_MyLayOut->addWidget(m_Temp, 0, 2);

	m_Thickness.clear(); m_Colors.clear();

	for (int i = 0; i < inLableNames.size(); i++)
	{
		m_MyLayOut->addWidget(new QLabel(QString::fromLocal8Bit(inLableNames[i].c_str()) + ":"), i + 1, 0);
		//m_MyLayOut->setAlignment(Qt::AlignRight);
		QLineEdit *ThicknessLabel = new QLineEdit("2"); m_MyLayOut->addWidget(ThicknessLabel, i + 1, 1); m_Thickness.push_back(ThicknessLabel);
		QIntValidator *validator1 = new QIntValidator(0, 500, this);
		ThicknessLabel->setValidator(validator1);

		QPushButton *ColorBtn = new QPushButton;
		//ColorBtn->setAutoFillBackground(true);
		//ColorBtn->setFlat(true);
		SetBtnColor(ColorBtn, ColorLut[i]);
		connect(ColorBtn, &QPushButton::clicked, this, &RenderSetWidget::ShowColorChoice);
		m_MyLayOut->addWidget(ColorBtn, i + 1, 2);
		m_Colors.push_back(ColorBtn);
	}
	// this->setMinimumHeight(inLableNames.size() * 40);
	this->setLayout(m_MyLayOut);
}

RenderShowParams RenderSetWidget::GetShowValue()
{
	RenderShowParams m_SenderParam;
	for (int i = 0; i < m_Colors.size(); i++)
	{
		m_SenderParam._contourThickness.push_back(m_Thickness[i]->text().toInt());
		m_SenderParam._contourColor.push_back(GetBtnColor(m_Colors[i]));
	}
	return m_SenderParam;
}

void RenderSetWidget::SetBtnColor(QPushButton* inBtn, QColor inColor)
{
	QString QssStyle = QString("background-color:rgb(%1,%2,%3);").arg(inColor.blue()).arg(inColor.green()).arg(inColor.red());
	QPalette p = inBtn->palette();
	p.setColor(QPalette::Button, inColor);
	inBtn->setPalette(p);
	inBtn->setStyleSheet(QssStyle);
}

cv::Scalar RenderSetWidget::GetBtnColor(QPushButton* inBtn)
{
	QPalette pal = inBtn->palette();
	QBrush brush = pal.button();
	QColor qColors = brush.color();

	int r, g, b;
	qColors.getRgb(&r, &g, &b);
	return cv::Scalar(b, g, r);
}

void RenderSetWidget::ShowColorChoice()
{
	QObject* obj = sender();
	QPushButton* BtnSender = dynamic_cast<QPushButton*>(obj);
	//颜色对话框设置
	QColorDialog::setCustomColor(0, QRgb(0x0000FF));
	//定义 QColor 接收值
	QColor color = QColorDialog::getColor(QColor(0, 255, 0));
	//定义 QPalette(调色板类)
	QPalette p = palette();
	//调色板接收颜色
	p.setColor(QPalette::WindowText, QColor(color));
	int tempR = color.red();
	int tempB = color.blue();
	color.setRgb(tempB, color.green(), tempR);
	//给 label 绑定颜色
	SetBtnColor(BtnSender, color);
}

void RenderSetWidget::LoadConfigRenderSet(RenderShowParams inConfig)
{
	for (int i = 0; i < m_Thickness.size(); i++)
	{
		if (i < inConfig._contourThickness.size()) m_Thickness[i]->setText(QString::number(inConfig._contourThickness[i]));
		if (i < inConfig._contourColor.size()) SetBtnColor(m_Colors[i], QColor(inConfig._contourColor[i][0], inConfig._contourColor[i][1], inConfig._contourColor[i][2]));
	}
}