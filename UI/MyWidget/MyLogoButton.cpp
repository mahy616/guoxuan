#include "MyLogoButton.h"

MyLogoButton::MyLogoButton(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setStyleSheet("QWidget:hover{background:\"transparent\";background-color:rgba(255,255,255,0.1);}QWidget:pressed{background:\"transparent\";background-color:rgba(255,255,255,0.2);}QWidget:disable{color:rgb(255,0,0);background:\"transparent\";background-color:rgba(255,255,255,0.6);}QLabel:hover{background:\"transparent\";background-color:rgba(255,255,255,0.1);}QLabel:pressed{background:\"transparent\";background-color:rgba(255,255,255,0.2);}");
}

MyLogoButton::~MyLogoButton()
{}

void MyLogoButton::SetMyParam(QString logoName, QString titter)
{
	QString logoPath = QString("background:\"transparent\";border-image:url(:/DynamicWidget/Resource/%1.png);}").arg(logoName);
	ui.label_Logo->setStyleSheet(logoPath);
	ui.label_Name->setText(titter);
}

void MyLogoButton::SetWordSize(int size)
{
	QFont font; font.setPointSize(size);
	ui.label_Name->setFont(font);
}

void MyLogoButton::SetLogoSize(int width, int height)
{
	ui.label_Logo->setFixedSize(width, height);
}

void MyLogoButton::mousePressEvent(QMouseEvent *event)
{
	emit MyClicked();
	return QWidget::mousePressEvent(event);
}

void MyLogoButton::paintEvent(QPaintEvent*)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

