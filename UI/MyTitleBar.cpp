#include "MyTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <vector>
#include "UI/MyDialog/SoftInfoDialog.h"
//#pragma execution_character_set("utf-8")
#define BUTTON_HEIGHT 40		// ��ť�߶�;
#define BUTTON_WIDTH 40			// ��ť���;
#define TITLE_HEIGHT 50			// �������߶�;

QString BtnStyleSheet = "QToolButton:hover{border:1px solid #A8A8A8;}"
"QToolButton:pressed{background-color:rgb(125,125,125);}";

MyTitleBar::MyTitleBar(QWidget *parent)
	: QToolBar(parent)
	, m_colorR(50)
	, m_colorG(50)
	, m_colorB(50)
	, m_isPressed(false)
	, m_windowBorderWidth(0)
	, m_isTransparent(false)
	, isMax(false)
	, isLogoVisuable(true)
{
	// ��ʼ��;
	//initControl();
	//initConnections();
	// ���ر�����ʽ MyTitle.css�ļ�;
	//loadStyleSheet("MyTitle");
}

MyTitleBar::~MyTitleBar()
{

}

void MyTitleBar::SetLogoVisuable(bool isSee)
{
	//QAction_Logo->setVisible(isSee);
	isLogoVisuable = isSee;
	if (isSee)
	{
		QPixmap originaPixmapl, fitpixmap;
		originaPixmapl.load(":/DynamicWidget/Resource/SoftLogo.png");
		fitpixmap = originaPixmapl.scaled(130, 15, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		m_pIcon->setPixmap(fitpixmap);
	}
	else
	{
		QPixmap originaPixmapl, fitpixmap;
		originaPixmapl.load(":/DynamicWidget/Resource/LabelNone.png");
		fitpixmap = originaPixmapl.scaled(130, 15, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		m_pIcon->setPixmap(fitpixmap);
	}
}

// ��ȡ��ǰlogo�Ƿ�ɼ�
bool MyTitleBar::GetLogoVisuable()
{
	//return QAction_Logo->isVisible();
	return isLogoVisuable;
}

// ��ȡ��������
QString MyTitleBar::GetSoftName()
{
	return m_pTitleContent->text();
}

// ��ʼ���ؼ�;
void MyTitleBar::initControl(std::vector<TittleType> tittleTypes)
{
	//QToolBar->addWidget����һ��QAction*ָ�룬ͨ�����ָ����ƿؼ��Ƿ�ɼ���ֱ�Ӷ�ԭ�ؼ�setVisible����Ч(�ӱ�)
	QWidget *spacer; QWidget * spacer2;
	QPixmap originaPixmapl, fitpixmap;
	QLabel* GapLabel;
	for (int i = 0; i < tittleTypes.size(); i++)
	{
		switch (tittleTypes[i])
		{
		case LogoImage:
			//����20�����ؼ��
			GapLabel = new QLabel;
			GapLabel->setStyleSheet("background: transparent;");
			GapLabel->setFixedSize(QSize(20, 30));
			this->addWidget(GapLabel);

			m_pIcon = new QLabel;
			//m_pIcon->setFixedSize(QSize(200, 30));
			m_pIcon->setObjectName("Labellogo");
			originaPixmapl.load(":/DynamicWidget/Resource/SoftLogo.png");
			fitpixmap = originaPixmapl.scaled(130, 15, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			m_pIcon->setAttribute(Qt::WA_TranslucentBackground);
			m_pIcon->setStyleSheet("background-color:transparent;");
			m_pIcon->setPixmap(fitpixmap);
			QAction_Logo = this->addWidget(m_pIcon);
			//this->addLayOut(new QSpacerItem(0, 160, QSizePolicy::Expanding, QSizePolicy::Fixed));
			break;
		case SoftName:
			spacer = new QWidget;
			spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			this->addWidget(spacer);

			m_pTitleContent = new QLabel;
			m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_pTitleContent->setObjectName("TitleContent");
			m_pTitleContent->setText("");
			m_pTitleContent->setStyleSheet("font-size:25x; color:white");
			m_pTitleContent->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
			this->addWidget(m_pTitleContent);

			spacer2 = new QWidget;
			spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			this->addWidget(spacer2);
			break;
		case SoftInfo:
			m_pButtonSoftInfo = new QToolButton;
			m_pButtonSoftInfo->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			m_pButtonSoftInfo->setObjectName("ButtonMin");
			m_pButtonSoftInfo->setToolTip(tr("Soft Information"));
			originaPixmapl.load(":/DynamicWidget/Resource/BtnSoftInfo.png");
			m_pButtonSoftInfo->setStyleSheet(BtnStyleSheet);
			fitpixmap = originaPixmapl.scaled(40, 40, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			m_pButtonSoftInfo->setIcon(QIcon(fitpixmap));
			//m_pButtonMin->setFlat(true);
			this->addWidget(m_pButtonSoftInfo);
			break;
		case MinBUTTON:
			m_pButtonMin = new QToolButton;
			m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			m_pButtonMin->setObjectName("ButtonMin");
			m_pButtonMin->setToolTip(tr("Minimize"));
			originaPixmapl.load(":/DynamicWidget/Resource/smallest.png");
			m_pButtonMin->setStyleSheet(BtnStyleSheet);
			fitpixmap = originaPixmapl.scaled(40, 40, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			m_pButtonMin->setIcon(QIcon(fitpixmap));
			//m_pButtonMin->setFlat(true);
			this->addWidget(m_pButtonMin);
			break;
		case RestoreBUTTON:
			m_pButtonRestore = new QToolButton;
			m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			m_pButtonRestore->setObjectName("ButtonRestore");
			m_pButtonRestore->setToolTip(tr("Reset"));
			originaPixmapl.load(":/DynamicWidget/Resource/Reduction.png");
			m_pButtonRestore->setStyleSheet(BtnStyleSheet);
			fitpixmap = originaPixmapl.scaled(40, 40, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			m_pButtonRestore->setIcon(QIcon(fitpixmap));
			//m_pButtonRestore->setFlat(true);
			m_pButtonRestore->setVisible(false); //Ĭ��ԭʼ���� -- ���ò���ʾ"��ԭ��ť"
			QAction_RestoreBtn = this->addWidget(m_pButtonRestore);
			break;
		case MaxBUTTON:
			m_pButtonMax = new QToolButton;
			m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			m_pButtonMax->setObjectName("ButtonMax");
			m_pButtonMax->setToolTip(tr("Maximize"));
			m_pButtonMax->setStyleSheet(BtnStyleSheet);
			originaPixmapl.load(":/DynamicWidget/Resource/biggest.png");
			fitpixmap = originaPixmapl.scaled(40, 40, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			m_pButtonMax->setIcon(QIcon(fitpixmap));
			QAction_MaxBtn = this->addWidget(m_pButtonMax);
			break;
		case CloseBUTTON:
			m_pButtonClose = new QToolButton;
			m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
			m_pButtonClose->setObjectName("ButtonClose");
			m_pButtonClose->setToolTip(tr("Close"));
			m_pButtonClose->setStyleSheet("QToolButton:hover{background-color:rgb(222,48,34);}QToolButton:pressed{background-color:rgb(125,125,125);}");
			originaPixmapl.load(":/DynamicWidget/Resource/close.png");
			fitpixmap = originaPixmapl.scaled(40, 40, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			m_pButtonClose->setIcon(QIcon(fitpixmap));
			//m_pButtonClose->setFlat(true);
			this->addWidget(m_pButtonClose);
			break;
		default:
			break;
		}
	}

	// �źŲ۵İ�;
	for (int i = 0; i < tittleTypes.size(); i++)
	{
		switch (tittleTypes[i])
		{
		case SoftInfo:
			connect(m_pButtonSoftInfo, SIGNAL(clicked()), this, SLOT(onButtonSoftInfo()));
			break;
		case MinBUTTON:
			connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
			break;
		case RestoreBUTTON:
			connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
			break;
		case MaxBUTTON:
			connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
			break;
		case CloseBUTTON:
			connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
			break;
		default:
			break;
		}
	}

	//m_pButtonMax->setStyleSheet("QPushButton:hover{border-image: url(:/res/images/biggest.png);background - color: blue; color:blue;}");
	//m_pButtonMin->setStyleSheet("QPushButton:hover{background-color:rgba(0,0,0,0.25);border-image: url(:/res/images/smallest_hover.png);}");
	//m_pButtonMax->setStyleSheet("QPushButton:hover{background-color:rgba(0,0,0,0.25);border-image: url(:/res/images/biggest_hover.png);}");
	//m_pButtonClose->setStyleSheet("QPushButton:hover{background-color:rgba(0,0,0,0.25);border-image: url(:/res/images/close_hover.png);}");
	//m_pButtonMin->setStyleSheet("QPushButton:pressed{background-color:rgba(0,0,0,0.25);border-image: url(:/res/images/biggest.png);}");
	/*QPushButton:pressed{background - color: #173C69;}  background - color: #3185E6;*/

	//mylayout->addSpacing(250);
	//mylayout->addStretch();
	//mylayout->setContentsMargins(5, 0, 0, 0); ���ÿؼ�����߾��������ҵ�ֵ
	this->setFixedHeight(TITLE_HEIGHT);
	this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setStyleSheet("background-color: #163B66"); ��paintevent�����ñ���ɫ
}



// ���ñ���������ɫ,��paintEvent�¼��н��л��Ʊ���������ɫ;
// �ڹ��캯���и���Ĭ��ֵ�������ⲿ������ɫֵ�ı����������ɫ;
void MyTitleBar::setBackgroundColor(int r, int g, int b, bool isTransparent)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	m_isTransparent = isTransparent;
	// ���»��ƣ�����paintEvent�¼���;
	update();
}

// ���ñ�����ͼ��;
void MyTitleBar::setTitleIcon(QString filePath, QSize IconSize)
{
	QPixmap titleIcon(filePath);
	m_pIcon->setPixmap(titleIcon.scaled(IconSize));
}

// ���ñ�������;
void MyTitleBar::setTitleContent(QString titleContent, int titleFontSize)
{
	// ���ñ��������С;
	QFont font = m_pTitleContent->font();
	font.setPointSize(titleFontSize);
	m_pTitleContent->setFont(font);
	// ���ñ�������;
	m_pTitleContent->setText(titleContent);
	m_titleContent = titleContent;
}

// ���ñ���������;
void MyTitleBar::setTitleWidth(int width)
{
	this->setFixedWidth(width);
}

// ���ô��ڱ߿���;
void MyTitleBar::setWindowBorderWidth(int borderWidth)
{
	m_windowBorderWidth = borderWidth;
}

// ���洰�����ǰ���ڵ�λ���Լ���С;
void MyTitleBar::saveRestoreInfo(const QPoint point, const QSize size)
{
	m_restorePos = point;
	m_restoreSize = size;
}

// ��ȡ�������ǰ���ڵ�λ���Լ���С;
void MyTitleBar::getRestoreInfo(QPoint& point, QSize& size)
{
	point = m_restorePos;
	size = m_restoreSize;
}

// ���Ʊ���������ɫ;
void MyTitleBar::paintEvent(QPaintEvent *event)
{
	// �Ƿ����ñ���͸��;
	if (!m_isTransparent)
	{
		//���ñ���ɫ;
		QPainter painter(this);
		QPainterPath pathBack;
		pathBack.setFillRule(Qt::WindingFill);
		pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.fillPath(pathBack, QBrush(QColor(m_colorR, m_colorG, m_colorB)));
	}
	// ��������󻯻��߻�ԭ�󣬴��ڳ��ȱ��ˣ��������ĳ���Ӧ��һ��ı�;
	// �����ȥm_windowBorderWidth ������Ϊ���ڿ��������˲�ͬ��ȵı߿�;
	// ��������б߿�����Ҫ����m_windowBorderWidth��ֵ������m_windowBorderWidthĬ��Ϊ0;
	if (this->width() != (this->parentWidget()->width() - m_windowBorderWidth))
	{
		this->setFixedWidth(this->parentWidget()->width() - m_windowBorderWidth);
	}
	QWidget::paintEvent(event);
}

// ˫����Ӧ�¼�����Ҫ��ʵ��˫��������������󻯺���С������;
void MyTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
	// ֻ�д�����󻯡���ԭ��ťʱ˫������Ч;
	if (isMax == true)
	{
		isMax = false;
		onButtonRestoreClicked();
	}
	else
	{
		isMax = true;
		onButtonMaxClicked();
	}

	//if (isMax == true)
	//{
	//	// ͨ����󻯰�ť��״̬�жϵ�ǰ�����Ǵ�����󻯻���ԭʼ��С״̬;
	//	// ����ͨ���������ñ�������ʾ��ǰ����״̬;
	//	if (m_pButtonMax->isVisible())
	//	{
	//		onButtonMaxClicked();
	//	}
	//	else
	//	{
	//		onButtonRestoreClicked();
	//	}
	//}
	return QWidget::mouseDoubleClickEvent(event);
}

// ����ͨ��mousePressEvent��mouseMoveEvent��mouseReleaseEvent�����¼�ʵ��������϶��������ƶ����ڵ�Ч��;
void MyTitleBar::mousePressEvent(QMouseEvent *event)
{
	if (isMax)
	{
		m_isPressed = true;
		m_startMovePos = event->globalPos();
	}
	else
	{
		m_isPressed = true;
		m_startMovePos = event->globalPos();
	}

	//if (isMax)
	//{
	//	// �ڴ������ʱ��ֹ�϶�����;
	//	if (isMax == true && m_pButtonMax->isVisible())
	//	{
	//		m_isPressed = true;
	//		m_startMovePos = event->globalPos();
	//	}
	//}
	//else
	//{
	//	m_isPressed = true;
	//	m_startMovePos = event->globalPos();
	//}
	return QWidget::mousePressEvent(event);
}

void MyTitleBar::mouseMoveEvent(QMouseEvent *event)
{
	if (isMax == false)
	{
		if (m_isPressed)
		{
			QPoint movePoint = event->globalPos() - m_startMovePos;
			QPoint widgetPos = this->parentWidget()->pos();
			m_startMovePos = event->globalPos();
			this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
		}
	}
	return QWidget::mouseMoveEvent(event);
}

void MyTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressed = false;
	return QWidget::mouseReleaseEvent(event);
}

// ���ر�����ʽ�ļ�;
// ���Խ���ʽֱ��д���ļ��У���������ʱֱ�Ӽ��ؽ���;
void MyTitleBar::loadStyleSheet(const QString &sheetName)
{
	QFile file(":/Resources/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}

// ����Ϊ��ť������Ӧ�Ĳ�;
void MyTitleBar::onButtonMinClicked()
{
	emit signalButtonMinClicked();
}

void MyTitleBar::onButtonRestoreClicked()
{
	isMax = false;
	emit signalButtonRestoreClicked();
	QAction_MaxBtn->setVisible(true);
	QAction_RestoreBtn->setVisible(false);
	this->update();
}

void MyTitleBar::onButtonMaxClicked()
{
	/*m_pButtonMax->setVisible(false);
	m_pButtonRestore->setVisible(true);*/
	isMax = true;
	emit signalButtonMaxClicked();
	QAction_MaxBtn->setVisible(false);
	QAction_RestoreBtn->setVisible(true);
	this->update();
}

void MyTitleBar::onButtonCloseClicked()
{
	emit signalButtonCloseClicked();
}

void MyTitleBar::onButtonSoftInfo()
{
	SoftInfoDialog* m_Temp = new SoftInfoDialog;
	m_Temp->setWindowFlags(Qt::FramelessWindowHint);//ȥ������߿�
	m_Temp->setWindowModality(Qt::ApplicationModal);//���ô���ģ̬��Ҫ��ô���û�и��࣬������Ч
	m_Temp->show();
	connect(m_Temp, &SoftInfoDialog::MyCloseEvent, this, [=]() { delete m_Temp; });
}


