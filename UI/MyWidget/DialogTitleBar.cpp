#include "DialogTitleBar.h"

DialogTitleBar::DialogTitleBar(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.btn_Close, &QPushButton::clicked, this, &DialogTitleBar::CloseSignal);
}

DialogTitleBar::~DialogTitleBar()
{}

void DialogTitleBar::SetName(QString TittleName)
{
	ui.label_Title->setText(TittleName);
}

// ˫����Ӧ�¼�����Ҫ��ʵ��˫��������������󻯺���С������;
void DialogTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
	// ֻ�д�����󻯡���ԭ��ťʱ˫������Ч;
	if (isMax == true)
	{
		isMax = false;
		RestoreClickedSignal();
	}
	else
	{
		isMax = true;
		MaxClickedSignal();
	}
	return QWidget::mouseDoubleClickEvent(event);
}

// ����ͨ��mousePressEvent��mouseMoveEvent��mouseReleaseEvent�����¼�ʵ��������϶��������ƶ����ڵ�Ч��;
void DialogTitleBar::mousePressEvent(QMouseEvent *event)
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

	return QWidget::mousePressEvent(event);
}

void DialogTitleBar::mouseMoveEvent(QMouseEvent *event)
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

void DialogTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressed = false;
	return QWidget::mouseReleaseEvent(event);
}

