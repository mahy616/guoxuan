#pragma once
#include <QGraphicsView>
#include <QtWidgets/QGraphicsView>
#include <qevent.h>
#include <opencv.hpp>
#include <vector>

class SimpleView : public QGraphicsView
{
	Q_OBJECT

public:
	SimpleView(QWidget *parent = nullptr);
	~SimpleView();
	//显示图像
	void showMat(cv::Mat mat);
private:
	//初始化成员变量
	void InitVariables();
	//设置图片
	void SetMat(cv::Mat mat_set);
	//鼠标滚轮事件
	void wheelEvent(QWheelEvent * ev);
	//鼠标移动事件
	void mouseMoveEvent(QMouseEvent *ev);
	//鼠标按下事件
	void mousePressEvent(QMouseEvent *ev);
	//键盘按下事件
	void keyPressEvent(QKeyEvent *event);
	//键盘释放事件
	void keyReleaseEvent(QKeyEvent *event);
	//重绘事件
	void resizeEvent(QResizeEvent *event);
	//cv::Mat转QImage
	QImage Mat2QImage(cv::Mat mat);
	//刷新绘图区
	void RefreshClient();
	//当前界面坐标转化为cv::Mat坐标
	cv::Point Client2Mat(QPoint pt);
	//cv::Mat坐标转化为当前界面坐标
	QPoint Mat2Client(cv::Point pt);
	//颜色数据类型转换
	QColor Scalar2QColor(cv::Scalar color);
signals:
	void finishDraw(int);
private:
	//鼠标是否按下
	bool m_bMouseDown;
	//鼠标是否正在拖拽
	bool m_isDragging;
	//按键移动时的步长
	int m_nStep;
	//记录鼠标按下时的坐标
	QPoint m_ptOrg;
	//场景
	QGraphicsScene* m_scence;
	std::vector<cv::Mat> m_mats;//金字塔图像
	cv::Rect m_rectWindowWheel;//取图框的矩形区域
	cv::Rect m_rectWindowWheelTemp;//取图框的矩形区域，临时缓存，用于拖拽
	cv::Rect m_rectView;
	QImage m_imgShow;
	bool m_isShowing;
};
