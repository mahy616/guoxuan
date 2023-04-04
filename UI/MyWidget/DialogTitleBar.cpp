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

// 双击响应事件，主要是实现双击标题栏进行最大化和最小化操作;
void DialogTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
	// 只有存在最大化、还原按钮时双击才有效;
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

// 以下通过mousePressEvent、mouseMoveEvent、mouseReleaseEvent三个事件实现了鼠标拖动标题栏移动窗口的效果;
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

