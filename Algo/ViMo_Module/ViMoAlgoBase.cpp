#include "ViMoAlgoBase.h"
#include <QPainter>

ViMoAlgoBase::~ViMoAlgoBase()
{
	m_Solution.~Solution();
}

void ViMoAlgoBase::SetRenderShowParam(RenderShowParams inParam)
{
	m_RenderShow = inParam;
}

bool ViMoAlgoBase::RunAlgo(cv::Mat inputImage, cv::Mat &outRenderImage, cv::Rect inROI, std::vector<std::pair<std::string, cv::Rect>> &outROI, double &outMilliseconds)
{
	return false;
}

void ViMoAlgoBase::PutTextChinese(cv::Mat &inMat, QString drawText, cv::Point wordCenter, int inWordSize, cv::Scalar inColor)
{
	QImage image;
	switch (inMat.type())
	{
	case CV_8UC1:
		image = QImage(inMat.data, inMat.cols, inMat.rows, inMat.cols, QImage::Format_Mono);
		break;
	case CV_8UC3:
		image = QImage(inMat.data, inMat.cols, inMat.rows, inMat.cols * 3, QImage::Format_RGB888);
		break;
	case CV_8UC4:
		image = QImage(inMat.data, inMat.cols, inMat.rows, inMat.cols * 4, QImage::Format_ARGB32);
		break;
	}
	if (inWordSize < 6) inWordSize = 6;
	QColor drawColor(inColor[0], inColor[1], inColor[2]);
	QPainter pp(&image);
	QPen pen = QPen(drawColor, inWordSize);
	QBrush brush = QBrush(drawColor);
	pp.setPen(pen);
	pp.setBrush(brush);
	QFont font; font.setPointSize(inWordSize);
	pp.setFont(font);
	pp.drawText(QPointF(wordCenter.x, wordCenter.y), drawText);
}