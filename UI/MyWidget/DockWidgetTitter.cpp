#include "DockWidgetTitter.h"
#include <QPainter>
DockWidgetTitter::DockWidgetTitter(QDockWidget* inDock, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_Dock = inDock;
}

DockWidgetTitter::~DockWidgetTitter()
{}


// 绘制标题栏背景色;
void DockWidgetTitter::paintEvent(QPaintEvent *event)
{
	//设置背景色;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(pathBack, QBrush(QColor(255, 0, 0)));
	QWidget::paintEvent(event);
}

// 双击响应事件，主要是实现双击标题栏进行最大化和最小化操作;
void DockWidgetTitter::mouseDoubleClickEvent(QMouseEvent *event)
{
	m_Dock->setFloating(false);
	return QWidget::mouseDoubleClickEvent(event);
}

// 以下通过mousePressEvent、mouseMoveEvent、mouseReleaseEvent三个事件实现了鼠标拖动标题栏移动窗口的效果;
void DockWidgetTitter::mousePressEvent(QMouseEvent *event)
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

void DockWidgetTitter::mouseMoveEvent(QMouseEvent *event)
{
	if (isMax == false)
	{
		if (m_isPressed&&m_Dock->isFloating())
		{
			QPoint movePoint = event->globalPos() - m_startMovePos;
			QPoint widgetPos = this->parentWidget()->pos();
			m_startMovePos = event->globalPos();
			this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
		}
	}
	return QWidget::mouseMoveEvent(event);
}

void DockWidgetTitter::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressed = false;
	return QWidget::mouseReleaseEvent(event);
}