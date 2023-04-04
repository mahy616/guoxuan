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
	//��ʾͼ��
	void showMat(cv::Mat mat);
private:
	//��ʼ����Ա����
	void InitVariables();
	//����ͼƬ
	void SetMat(cv::Mat mat_set);
	//�������¼�
	void wheelEvent(QWheelEvent * ev);
	//����ƶ��¼�
	void mouseMoveEvent(QMouseEvent *ev);
	//��갴���¼�
	void mousePressEvent(QMouseEvent *ev);
	//���̰����¼�
	void keyPressEvent(QKeyEvent *event);
	//�����ͷ��¼�
	void keyReleaseEvent(QKeyEvent *event);
	//�ػ��¼�
	void resizeEvent(QResizeEvent *event);
	//cv::MatתQImage
	QImage Mat2QImage(cv::Mat mat);
	//ˢ�»�ͼ��
	void RefreshClient();
	//��ǰ��������ת��Ϊcv::Mat����
	cv::Point Client2Mat(QPoint pt);
	//cv::Mat����ת��Ϊ��ǰ��������
	QPoint Mat2Client(cv::Point pt);
	//��ɫ��������ת��
	QColor Scalar2QColor(cv::Scalar color);
signals:
	void finishDraw(int);
private:
	//����Ƿ���
	bool m_bMouseDown;
	//����Ƿ�������ק
	bool m_isDragging;
	//�����ƶ�ʱ�Ĳ���
	int m_nStep;
	//��¼��갴��ʱ������
	QPoint m_ptOrg;
	//����
	QGraphicsScene* m_scence;
	std::vector<cv::Mat> m_mats;//������ͼ��
	cv::Rect m_rectWindowWheel;//ȡͼ��ľ�������
	cv::Rect m_rectWindowWheelTemp;//ȡͼ��ľ���������ʱ���棬������ק
	cv::Rect m_rectView;
	QImage m_imgShow;
	bool m_isShowing;
};
