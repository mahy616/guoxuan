#pragma once

#include <QWidget>
#include "ui_RenderSetWidget.h"
#include "PublicParamter.h"
#include <QColorDialog>

class RenderSetWidget : public QWidget
{
	Q_OBJECT

public:
	RenderSetWidget(std::vector<std::string> inLableNames, QWidget *parent = nullptr);
	~RenderSetWidget();
	void LoadConfigRenderSet(RenderShowParams inConfig);
	void SetMyParamter(std::vector<std::string> inLableNames);
	RenderShowParams GetShowValue();
private:
	QGridLayout *m_MyLayOut = NULL;
	std::vector<QLineEdit*> m_Thickness;
	std::vector<QPushButton*> m_Colors;
	void SetBtnColor(QPushButton* inBtn, QColor inColor);
	cv::Scalar GetBtnColor(QPushButton* inBtn);
	std::vector<QColor> ColorLut = { QColor(255, 255, 0),QColor(255, 0, 0) ,QColor(0, 255, 0) ,QColor(255, 0, 255) ,QColor(0, 255, 255) ,QColor(0, 0, 255),QColor(30, 150, 215) ,QColor(230, 20, 115)  ,QColor(44, 20, 215)  ,QColor(130, 210, 3) ,QColor(230, 20, 115) ,QColor(130, 220, 35)  ,QColor(55, 220, 35) ,QColor(230, 11, 55)  ,QColor(52, 72, 115) };
public slots:
	void ShowColorChoice();
private:
	Ui::RenderSetWidgetClass ui;
};
