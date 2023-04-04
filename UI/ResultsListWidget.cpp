#include "ResultsListWidget.h"

ResultsListWidget::ResultsListWidget(MyTableWidget* inTableWidgetPtr, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	tableWidgetPtr = inTableWidgetPtr;
	m_WidgetLayOut = new QVBoxLayout(this);
	m_WidgetLayOut->setContentsMargins(0, 0, 0, 0);
	m_WidgetLayOut->addWidget(tableWidgetPtr);
	ui.widget_ControlVisual->setLayout(m_WidgetLayOut);
	ui.btn_ControlVisiable->SetMyParam("ShowCross", tr("Result List"));
	ui.btn_ControlVisiable->SetWordSize(11);
	ui.btn_ControlVisiable->SetLogoSize(14, 14);

	connect(ui.btn_ReSet, &QPushButton::clicked, this, &ResultsListWidget::ReSetBtnClickedSlot);
	connect(ui.btn_ControlVisiable, &MyLogoButton::MyClicked, this, &ResultsListWidget::ControlVisibleSlot);
}

ResultsListWidget::~ResultsListWidget()
{
	
}


void ResultsListWidget::ControlVisibleSlot()
{
	isShow = !isShow;
	if (isShow) //Õ¹¿ª
	{
		this->setMaximumHeight(2000);
		ui.btn_ControlVisiable->SetMyParam("ShowCross", tr("Result List"));
		//ui.btn_ControlVisiable->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/ResultListShow.png\");border:none;}"
		//	"QPushButton:hover{background-color:rgb(45,45,45);}"
		//	"QPushButton:pressed{background-color:rgb(35,35,35);}");
		ui.widget_ControlVisual->setVisible(true);

	}
	else //ÕÛµþ
	{
		/*ui.btn_ControlVisiable->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/ResultListHide.png\");border:none;}"
			"QPushButton:hover{background-color:rgb(45,45,45);}"
			"QPushButton:pressed{background-color:rgb(35,35,35);}");*/
		ui.btn_ControlVisiable->SetMyParam("HideCross", tr("Result List"));
		ui.widget_ControlVisual->setVisible(false);
		this->setMaximumHeight(50);
		this->update();
	}
}

void ResultsListWidget::ReSetBtnClickedSlot()
{
	for (int row = tableWidgetPtr->rowCount() - 1; row >= 0; row--)
	{
		tableWidgetPtr->removeRow(row);
	}
}

void ResultsListWidget::WorkStateChange(bool isWork)
{
	ui.btn_ReSet->setEnabled(!isWork);
}