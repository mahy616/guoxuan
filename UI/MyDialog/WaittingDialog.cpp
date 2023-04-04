#include "WaittingDialog.h"
#include <QTimer>
#include "PublicParamter.h"

WaittingDialog::WaittingDialog(QString ShowWord, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	ui.label_Name->setText(ShowWord);
	m_Clock = new QTimer(this);
	connect(m_Clock, &QTimer::timeout, this, &WaittingDialog::TimerSlot);
	m_Clock->start(400);

	//…Ë÷√”Ô—‘◊÷ÃÂ
	QFont font;
	font.setPointSize(11);
	if (isChineseLanguage())
		font.setFamily("Microsoft YaHei");
	else
		font.setFamily("Roboto");
	auto listWidget = findChildren<QWidget*>();
	for (auto& widget : listWidget)
	{
		widget->setFont(font);
	}
	this->setAttribute(Qt::WA_ShowModal, true);
}

WaittingDialog::~WaittingDialog()
{
	if (m_Clock != nullptr)
	{
		if (m_Clock->isActive())
		{
			m_Clock->stop();
			delete m_Clock;
		}
	}
}

void WaittingDialog::TimerSlot()
{
	if (drawWord.size() == 7)
	{
		drawWord = ".";
	}
	else
	{
		drawWord = drawWord + ".";
	}
	ui.label_wait->setText(drawWord);
}
