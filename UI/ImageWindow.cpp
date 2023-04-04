#include "ImageWindow.h"
#include "components/Config/ConfigProgramme.h"
#include "ImageSourceSetting.h"
#include "ImageSouceBase.h"
#include "QGraphicsDropShadowEffect"
#include <QMessageBox>
#include <QString>
#include <QPointer>

ImageWindow::ImageWindow(int* WindowIndex, bool* inShowFlag, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	MyWindowIndex = WindowIndex;
	isShowOkNg = inShowFlag;
	SetWindowsTittle();    //���õ�ǰ����
	InintMenu();           //���ò˵�
	InintResultLabel();    //����Ok/Ng logo
	
	InintParameter();     
	InintConnection();
	
	
	QTimer *m_delay = new QTimer(this); m_delay->start(100);
	connect(m_delay, &QTimer::timeout, this, [=]() { 
		//����resizeEvent�¼�������Ok/Ng logo
		this->resize(this->size() - QSize(1, 1)); this->resize(this->size() + QSize(1, 1));; m_delay->stop(); delete m_delay;
		// ��Ӣ���л���ͬ����
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
	});
}

ImageWindow::~ImageWindow()
{
	disconnect(ui.ShowImgWidget, &QLabel::customContextMenuRequested, this, &ImageWindow::MenuBtnSlot);
	if (m_ThresholdSetDialg != nullptr) delete m_ThresholdSetDialg;
	if (m_ImgSourcePtr != nullptr) delete m_ImgSourcePtr;
	if (m_configDialg != nullptr) delete m_configDialg;
	if (buttonMenu != nullptr)  buttonMenu->deleteLater(); buttonMenu = nullptr;
}

void ImageWindow::InintParameter()
{
	m_configDialg = new ModelConfigDialg;
	m_ThresholdSetDialg = new ThresholdSet;
	m_configDialg->setAttribute(Qt::WA_ShowModal, true);

	ui.checkBox_ShowRender->setChecked(true);
	ui.label_ModelStatus->setStyleSheet("image:url(:/DynamicWidget/Resource/AlgoNone.png);background: \"transparent\";");
	ui.label_ModelStatus->setToolTip(tr("initializing"));
}

void ImageWindow::InintConnection()
{
	connect(ui.checkBox_ShowRender, &QCheckBox::clicked, this, &ImageWindow::ShowRenderFlagSlot);
	connect(m_configDialg, &ModelConfigDialg::SendModelChoice, this, &ImageWindow::GetModelChoiceSlot);
	connect(m_ThresholdSetDialg, &ThresholdSet::SendThresholdPatamter, this, &ImageWindow::SendThreshold);
}

void ImageWindow::InintResultLabel()
{
	layout()->activate();
	ui.verticalLayout->activate();
	ui.gridLayout->activate();
	ui.gridLayout_2->activate();
	ui.horizontalLayout->activate();
	m_LabelOkNg.Label_OkNg = new QLabel(ui.ShowImgWidget);
	m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/LabelNone.png);background:\"transparent\";");
	//m_LabelOkNg.Label_OkNg->setStyleSheet("border-image:url(\":/DynamicWidget/Resource/LabelNone.png\");");
	QRect rect = ui.ShowImgWidget->rect();
	m_LabelOkNg.Label_OkNg->setGeometry(rect.width() - m_LabelOkNg.LabelWidth, 0, m_LabelOkNg.LabelWidth, m_LabelOkNg.LabelHeight);
	m_LabelOkNg.OldWidth = rect.width();
	m_LabelOkNg.OldHeight = rect.height();
}

void ImageWindow::SetImageSourcePtr(ImageSourceBase *inPtr)
{
	m_ImgSourcePtr = inPtr;
}

//���״̬�ı�ۺ��� - �������logo��ʽ
void ImageWindow::SetCameraStateSlot(bool isOpen)
{
	if (isOpen)
	{
		ui.btn_SoftTrigger->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/CameraOK.png\");border:none;background: \"transparent\";}");
		ui.btn_SoftTrigger->setToolTip(tr("Camera Conneted"));
	}
	else
	{
		ui.btn_SoftTrigger->setStyleSheet("QPushButton{border-image:url(\":/DynamicWidget/Resource/CameraNG.png\");border:none;background: \"transparent\";}");
		ui.btn_SoftTrigger->setToolTip(tr("Camera Disconneted"));
	}
}

//�����㷨����źŵ���ʾ��Ⱦͼ�ۺ���
void ImageWindow::SetShowImageSlot(cv::Mat& m_OriginalImages, cv::Mat& m_RenderImages, bool bOK, double Time)
{
	if (m_OriginalImages.rows==0|| m_OriginalImages.cols == 0)
	{
		QMessageBox::information(NULL, tr("Tips"), tr("Original image is empty"));
		return;
	}
	if (m_RenderImages.rows == 0 || m_RenderImages.cols == 0)
	{
		QMessageBox::information(NULL, tr("Tips"), tr("Result image is empty"));
		return;
	}

	if (*isShowOkNg)
	{
		if (bOK)
			m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/ResultOk.png);background:\"transparent\";");
		else
			m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/ResultNg.png);background:\"transparent\";");
	}
	else
	{
		m_LabelOkNg.Label_OkNg->setStyleSheet("border-image: url(:/DynamicWidget/Resource/LabelNone.png);background:\"transparent\";");
	}


	if (ui.checkBox_ShowRender->isChecked())
		ui.ShowImgWidget->SetImage(MattoQImage(m_RenderImages));
	else
		ui.ShowImgWidget->SetImage(MattoQImage(m_OriginalImages));
	ui.label_UseTime->setText(tr("RunTime:") + QString::number(Time, 'f', 2) + "ms");
	m_OriginalImage = m_OriginalImages;
	m_RenderImage = m_RenderImages;
}


void ImageWindow::InintMenu()
{
	QAction* buttonAction_ImageSource = new QAction(tr("Image Source Settings"), this);
	QAction* buttonAction_ModelChoice = new QAction(tr("Pipeline Settings"), this);
	QAction* buttonAction_Threshold = new QAction(tr("Parameters Settings"), this);
	QAction* buttonAction_AddWindow = new QAction(tr("New Window"), this);
	QAction* buttonAction_Close = new QAction(tr("Delete Window"), this);

	buttonMenu = new QMenu;
	SetMenuStyleSheet(buttonMenu); //���ò˵�����ʽ
	buttonMenu->addAction(buttonAction_ImageSource);
	buttonMenu->addAction(buttonAction_ModelChoice);
	buttonMenu->addAction(buttonAction_Threshold);
	buttonMenu->addAction(buttonAction_AddWindow);
	buttonMenu->addAction(buttonAction_Close);

	//�����"ͼ��Դ����"
	connect(buttonAction_ImageSource, &QAction::triggered, this, &ImageWindow::ImageSourceSlot);
	//�����"�㷨��������"
	connect(buttonAction_ModelChoice, &QAction::triggered, this, &ImageWindow::ModelChoiceSlot);
	//�����"��ͼ��������"
	connect(buttonAction_Threshold, &QAction::triggered, this, &ImageWindow::ThresholdSetSlot);
	//�����"�½�����"
	connect(buttonAction_AddWindow, &QAction::triggered, this, [=]() { emit AddWindowSignal(); });
	//�����"�رմ���"
	connect(buttonAction_Close, &QAction::triggered, this, [=]()
	{
		if (QMessageBox::Ok == QMessageBox::information(NULL, tr("Tips"), tr("Are you sure want to delete the Window?"), QMessageBox::Ok | QMessageBox::Cancel))
			SendCloseEvent(*MyWindowIndex);
	});

	//���ؼ����������Ĳ˵�����(�󶨵�ǰ������˵�)
	ui.ShowImgWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.ShowImgWidget, &QLabel::customContextMenuRequested, this, &ImageWindow::MenuBtnSlot);
}

void ImageWindow::MenuBtnSlot(const QPoint &pos)
{
	QPointer<QWidget> pointer = this;
	if (!pointer) return;
	if (buttonMenu != nullptr)
	{
		buttonMenu->exec(QCursor::pos());
	}
}

void ImageWindow::SetMenuStyleSheet(QMenu* inMenu)
{
	QFont font; font.setPointSize(11);
	if (isChineseLanguage())
		font.setFamily("Microsoft YaHei");
	else
		font.setFamily("Roboto");
	buttonMenu->setFont(font);
	inMenu->setStyleSheet(
		"QMenu{"
		"color:rgb(0,0,0);"
		"background-color:#E6E6E6;"
		"font:9pt;"
		"border-radius:10px;}"
		"QMenu::item{"
		"color:rgb(0,0,0);"
		"background-color:#E6E6E6;"
		"height:40px;}"
		"QMenu::item:hover{"
		"background-color:#C2C2C2;}"
		"QMenu::item:selected{"
		"background-color:#999999;}"
	);
	//������Ӱ
	inMenu->setAttribute(Qt::WA_TranslucentBackground, true);//���ô���͸��
	QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
	shadow_effect->setOffset(0, 0);
	shadow_effect->setColor(QColor("#444444"));//��Ӱ��ɫ
	shadow_effect->setBlurRadius(30);//��Ӱ�뾶
	inMenu->setGraphicsEffect(shadow_effect);
	inMenu->setContentsMargins(10, 10, 10, 10);//����ֱ���������ñ߾�(�˲�����Ҫ, ���ÿ��Ϊ��Ӱ�Ŀ��)
}

// �˵����������ͼ�������òۺ���
void ImageWindow::ThresholdSetSlot()
{
	m_ThresholdSetDialg->m_AlgoThreadCallBack = m_AlgoThresholdCallBack;
	m_ThresholdSetDialg->m_AlgoInfoCallBack = m_AlgoInfoCallBack;
	//m_ThresholdSetDialg->inintProgramThreshold(m_AlgoThresholdCallBack());
	m_ThresholdSetDialg->show();
}

// �˵��������ͼ��Դ���òۺ���
void ImageWindow::ImageSourceSlot()
{
	if (m_RunningStateCallBack())
	{
		QMessageBox::information(nullptr, tr("Tips"), tr("Please stop working")); return;
	}

	ImageSourceSetting *m_ImageSet = new ImageSourceSetting(m_ImgSourcePtr);
	connect(m_ImageSet, &ImageSourceSetting::NewImageSourceBase, this, [=](ImageSourceBase* inPtr) { 
		m_ImgSourcePtr = inPtr; 
		emit ChangeImageSourceBase(inPtr);
	});
	m_ImageSet->setWindowModality(Qt::ApplicationModal);
	m_ImageSet->show();
}

//�������"��ȾЧ��"��checkBox��ѡ�򣬶�Ӧ��ʾԭͼ����Ⱦͼ
void ImageWindow::ShowRenderFlagSlot()
{
	QImage img;
	if (ui.checkBox_ShowRender->isChecked())
	{
		img = MattoQImage(m_RenderImage);
		m_LabelOkNg.Label_OkNg->setVisible(true);
	}
	else
	{
		img = MattoQImage(m_OriginalImage);
		m_LabelOkNg.Label_OkNg->setVisible(false);
	}
	ui.ShowImgWidget->SetImage(img);
}

//�˵���������㷨�������òۺ���
void ImageWindow::ModelChoiceSlot()
{	
	m_configDialg->show();
}

//���㷨������������"ȷ��"��ť��Ӧ�Ĳۺ���
void ImageWindow::GetModelChoiceSlot(ModelChoice m_receiveChoice)
{
	// ���õ�ǰ�㷨logo��ʼ����
	ui.label_ModelStatus->setStyleSheet("image: url(:/DynamicWidget/Resource/AlgoNone.png);background: \"transparent\";");
	ui.label_ModelStatus->setToolTip(tr("initializing"));

	//���浽����
	ConfigProgramme::GetInstance()->AllConfig[*MyWindowIndex - 1].m_ModelChoice = m_receiveChoice;

	my_ModelType = GetModelTypeFromString(m_receiveChoice.modeType[m_receiveChoice.modeType.size() - 1]);

	//�����㷨���ʼ��ģ��
	emit SendModelConfig(m_receiveChoice);

	//������ֵ���ģ������
	m_ThresholdSetDialg->SetMyParamter(m_receiveChoice.RealNameValue,m_receiveChoice.modeType, m_receiveChoice.labelsNamesVec);

	//�������ڵ�ģ�������ı�
	std::string NowName = m_receiveChoice.RealNameValue[m_receiveChoice.RealNameValue.size() - 1];
	QString ModelStr = QString::fromLocal8Bit(NowName.c_str());
	ui.label_modeType->setText(ModelStr);
}

//���㷨��ʼ��������Ӧ�Ĳۺ��� - ���ݽ���޸��㷨logo��ʽ
void ImageWindow::AlgoStatusChangleSlot(bool isSuccess)
{
	if (isSuccess)
	{
		ui.label_ModelStatus->setStyleSheet("image: url(:/DynamicWidget/Resource/AlgoHave.png);background: \"transparent\";");
		ui.label_ModelStatus->setToolTip(tr("Pipeline Woring Normally"));
	}
	else
	{
		ui.label_ModelStatus->setStyleSheet("image: url(:/DynamicWidget/Resource/AlgoFail.png);background: \"transparent\";");
		ui.label_ModelStatus->setToolTip(tr("Pipeline Fail"));
		QMessageBox::information(nullptr, tr("Tips"), tr("Window%1:Pipeline initialization failed.").arg(*MyWindowIndex));
	}
}


// ��ȡ��ǰ����ʹ�õ�ģ������
SdkModelType ImageWindow::GetModelType()
{
	return my_ModelType;
}

// ��StaionID�ı�ʱ�޸ı���
void ImageWindow::SetWindowsTittle()
{
	QString strname;
	if (*MyWindowIndex == 1)
		strname = QString::fromLocal8Bit("��ͷ");
	else if (*MyWindowIndex == 2)
		strname = QString::fromLocal8Bit("��β");


	//"QMenu{"
	//	"color:rgb(0,0,0);"
	//	"background-color:#E6E6E6;"
	//	"font:9pt;"
	//	"border-radius:10px;}"
	//	"QMenu::item{"
	//	"color:rgb(0,0,0);"
	//	"background-color:#E6E6E6;"
	//	"height:40px;}"
	//	"QMenu::item:hover{"
	//	"background-color:#C2C2C2;}"
	//	"QMenu::item:selected{"
	//	"background-color:#999999;}"
	ui.label_WidonwTittle->setStyleSheet("background-color:rgb(50, 50, 50);color:rgb(255,0,0);font:25pt;");
	ui.label_WidonwTittle->setText(strname);
}

// ���ط���ʱ��ʼ��vimoģ�͵Ľӿ�
void ImageWindow::inintLoadModelChoice(ModelChoice inChoice)
{
	this->m_configDialg->LoadModelChoice(inChoice);
}

//��ͼ�񴰿ڱ仯ʱ��������Ok/Ng logo�Ŀ��
void ImageWindow::resizeEvent(QResizeEvent *event)
{
	QRect rect = ui.ShowImgWidget->rect();
	float widthRate = (float)rect.width() / m_LabelOkNg.OldWidth;
	float heightRate = (float)rect.height() / m_LabelOkNg.OldHeight;
	m_LabelOkNg.Label_OkNg->setGeometry(rect.width() - m_LabelOkNg.LabelWidth * widthRate, 0, m_LabelOkNg.LabelWidth * widthRate, m_LabelOkNg.LabelHeight*widthRate);
}

// �����㷨�ຯ����ָ�룬��ȡ�㷨��ֵ����ȡ�㷨��Ϣ
void ImageWindow::SetAlgoThreadCallBackPtr(std::function<std::vector<AllThreshold>(void)> inThresholdPtr, std::function<std::vector<ViMoModelInfo>(void)>inInfoPtr)
{
	m_AlgoThresholdCallBack = inThresholdPtr;
	m_AlgoInfoCallBack = inInfoPtr;
	m_ThresholdSetDialg->m_AlgoInfoCallBack = m_AlgoInfoCallBack;
}

// ���������ǰ����״̬�ĺ���ָ�룬��ȡ����Ƿ���������
void ImageWindow::SetSoftRunningStatePtr(std::function<bool(void)> inRuningStatePtr)
{
	m_RunningStateCallBack = inRuningStatePtr;
}
