#include "SimpleView.h"
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <qdebug.h>

using namespace cv;

SimpleView::SimpleView(QWidget *parent)
	: QGraphicsView(parent)
{
	InitVariables();
}

SimpleView::~SimpleView()
{
}

void SimpleView::InitVariables()
{
	m_nStep = 1;
	m_isShowing = false;
	m_bMouseDown = false;
	m_isDragging = false;
	m_scence = new QGraphicsScene(this);
	setScene(m_scence);
}

void SimpleView::showMat(Mat mat)
{
	if (m_isShowing) return;
	m_isShowing = true;
	//qDebug() << "image size" << mat.size().width << "   " << mat.size().height;
	double time = getTickCount();
	SetMat(mat);
	//qDebug() << "SetMat time=" << (getTickCount() - time) / getTickFrequency();
	time = getTickCount();
	RefreshClient();
	time = (getTickCount() - time) / getTickFrequency();
	//qDebug() << " RefreshClient time=" << time;
	m_isShowing = false;
}

void SimpleView::wheelEvent(QWheelEvent * ev)
{
	if (!m_mats.empty())
	{
		auto pt = ev->pos();
		double rate_x = 1.0 * pt.x() / width();
		double rate_y = 1.0 * pt.y() / height();
		int width = m_rectWindowWheel.width;
		int height = m_rectWindowWheel.height;
		if (ev->delta() < 0)
		{
			int w = cvRound(m_rectWindowWheel.width * 1.1);
			if (m_mats[0].cols > w*0.1) m_rectWindowWheel.width = w;
		}
		else//放大
		{
			int w = cvRound(m_rectWindowWheel.width / 1.1);
			if (w > 10) m_rectWindowWheel.width = w;
		}
		m_rectWindowWheel.height = m_rectWindowWheel.width * this->height() / this->width();
		m_rectWindowWheel.x = cvRound(m_rectWindowWheel.x + width * rate_x - m_rectWindowWheel.width*rate_x);
		m_rectWindowWheel.y = cvRound(m_rectWindowWheel.y + height * rate_y - m_rectWindowWheel.height*rate_y);
		RefreshClient();
	}
}

void SimpleView::mouseMoveEvent(QMouseEvent * ev)
{
	if (m_bMouseDown && m_isDragging)
	{
		auto point = ev->pos();
		double scale = 1.0 *  m_rectWindowWheel.width / width();
		double dx = (m_ptOrg.x() - point.x())*scale;
		double dy = (m_ptOrg.y() - point.y())*scale;
		m_rectWindowWheel = m_rectWindowWheelTemp + Point(dx, dy);
		RefreshClient();
	}
}

void SimpleView::mousePressEvent(QMouseEvent * ev)
{
	switch (ev->button())
	{
	case Qt::MouseButton::LeftButton:
		m_bMouseDown = true;
		m_ptOrg = ev->pos();
		m_rectWindowWheelTemp = m_rectWindowWheel;
		break;
	case Qt::MouseButton::RightButton:
		break;
	default:
		break;
	}
}

void SimpleView::keyPressEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Control:
		m_isDragging = true;
		break;
	}
}

void SimpleView::keyReleaseEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Control:
		m_isDragging = false;
		break;
	}
}

void SimpleView::resizeEvent(QResizeEvent * event)
{
	if (width() == 0 || height() == 0 || m_rectWindowWheel.area() == 0) return;
	QPoint pt(width() / 2, height() / 2);
	double rate_x = 1.0 * pt.x() / width();
	double rate_y = 1.0 * pt.y() / height();
	int width = m_rectWindowWheel.width;
	int height = m_rectWindowWheel.height;

	int w = cvRound(m_rectWindowWheel.width);
	if (m_mats[0].cols > w*0.1) m_rectWindowWheel.width = w;

	m_rectWindowWheel.height = m_rectWindowWheel.width * this->height() / this->width();
	m_rectWindowWheel.x = cvRound(m_rectWindowWheel.x + width * rate_x - m_rectWindowWheel.width*rate_x);
	m_rectWindowWheel.y = cvRound(m_rectWindowWheel.y + height * rate_y - m_rectWindowWheel.height*rate_y);
	RefreshClient();
}

QImage SimpleView::Mat2QImage(cv::Mat mtx)
{
	switch (mtx.type())
	{
	case CV_8UC1:
		return QImage((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols, QImage::Format_Grayscale8);
	case CV_8UC3:
		return QImage((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 3, QImage::Format_RGB888).rgbSwapped();
	case CV_8UC4:
		return QImage((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 4, QImage::Format_ARGB32);
	default:
		return QImage();
	}
}

void SimpleView::RefreshClient()
{
	if (m_mats.empty()) return;
	//选择接近的金字塔图像
	int index = int(log2(1.0* m_rectWindowWheel.width / width()));
	if (index < 0) index = 0;
	if (index >= m_mats.size()) index = m_mats.size() - 1;
	double scale = pow(2, index);
	//计算相应的滑动窗口
	Rect rect_wheel;
	rect_wheel.x = cvRound(m_rectWindowWheel.x / scale);
	rect_wheel.y = cvRound(m_rectWindowWheel.y / scale);
	rect_wheel.width = cvRound(m_rectWindowWheel.width / scale);
	rect_wheel.height = cvRound(m_rectWindowWheel.height / scale);
	//计算相应的图像ROI
	Mat canvas(rect_wheel.size(), CV_8UC3);
	canvas.setTo(Scalar(100, 10, 10));
	Rect rect_insect = rect_wheel & Rect(0, 0, m_mats[index].cols, m_mats[index].rows);
	if (rect_insect.area() <= 0) return;
	Rect roi(rect_insect.x - rect_wheel.x, rect_insect.y - rect_wheel.y, rect_insect.width, rect_insect.height);
	Mat mat_insect = m_mats[index](rect_insect), mat_convert;
	switch (mat_insect.type())
	{
	case CV_8UC1:
		cvtColor(mat_insect, mat_convert, COLOR_GRAY2BGR);
		break;
	case CV_8UC3:
		mat_convert = mat_insect.clone();
		break;
	case CV_8UC4:
		cvtColor(mat_insect, mat_convert, COLOR_RGBA2BGR);
		break;
	default:
		break;
	}
	if (mat_convert.empty()) return;
	mat_convert.copyTo(canvas(roi));
	m_imgShow = Mat2QImage(canvas);
	if (m_imgShow.isNull()) return;
	////计算相应的目的窗口区域
	//Rect rectDraw;
	//rectDraw.x = (rect_insect.x - rect_wheel.x) * width / rect_wheel.width;
	//rectDraw.y = (rect_insect.y - rect_wheel.y)* height / rect_wheel.height;
	//rectDraw.width = (rect_insect.x + rect_insect.width - rect_wheel.x) * width / rect_wheel.width - rectDraw.x;
	//rectDraw.height = (rect_insect.y + rect_insect.height - rect_wheel.y)* height / rect_wheel.height - rectDraw.y;
	//绘制图像
	m_scence->clear();
	QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(m_imgShow.scaled(width(), height(), Qt::KeepAspectRatio, Qt::FastTransformation)));
	m_scence->addItem(pixmapItem);
	//namedWindow("image", 0); imshow("image", canvas); waitKey(1);
	show();
}

Point SimpleView::Client2Mat(QPoint pt)
{
	int x = pt.x() * m_rectWindowWheel.width / width() + m_rectWindowWheel.x;
	int y = pt.y() * m_rectWindowWheel.height / height() + m_rectWindowWheel.y;
	return Point(x, y);
}

QPoint SimpleView::Mat2Client(Point pt)
{
	int x = (pt.x - m_rectWindowWheel.x) * width() / m_rectWindowWheel.width;
	int y = (pt.y - m_rectWindowWheel.y) * height() / m_rectWindowWheel.height;
	return QPoint(x, y);
}

QColor SimpleView::Scalar2QColor(cv::Scalar color)
{
	return QColor(color[2], color[1], color[0]);
}

void SimpleView::SetMat(Mat mat_set)
{
	if (mat_set.empty()) return;
	bool calc_window = true;
	if (m_mats.size() && mat_set.size() == m_mats[0].size()) calc_window = false;
	//金字塔采样
	m_mats.clear();
	m_mats.push_back(mat_set);
	for (int i = 1; i < 10; i++)
	{
		Mat mat;
		pyrDown(m_mats[i - 1], mat);
		m_mats.push_back(mat);
	}
	//初始化滑动窗口
	int width = this->width();
	int height = this->height();

	if (calc_window)
	{
		double scale1 = 1.0 * width / m_mats[0].cols;//宽度方向的比例系数
		double scale2 = 1.0 * height / m_mats[0].rows;//高度方向的比例系数
		if (scale1 < scale2)
		{
			//横向铺满
			m_rectWindowWheel.width = m_mats[0].cols;
			m_rectWindowWheel.height = m_rectWindowWheel.width * height / width;
			m_rectWindowWheel.x = 0;
			m_rectWindowWheel.y = (m_mats[0].rows - m_rectWindowWheel.height) / 2;
		}
		else
		{
			//纵向铺满
			m_rectWindowWheel.height = m_mats[0].rows;
			m_rectWindowWheel.width = m_rectWindowWheel.height * width / height;
			m_rectWindowWheel.y = 0;
			m_rectWindowWheel.x = (m_mats[0].cols - m_rectWindowWheel.width) / 2;
		}
	}
	m_isDragging = false;
}
