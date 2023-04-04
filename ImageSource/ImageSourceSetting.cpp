#include "ImageSourceSetting.h"
#include "ImageSourceCamera.h"
#include "ImageSourceFile.h"
#include "PublicParamter.h"

ImageSourceSetting::ImageSourceSetting(ImageSourceBase *inSource, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_ImageSource = inSource;

	//获取基类指向哪个子类
	char *m_Temp = (char*)typeid(*m_ImageSource).name(); 
	string JudgeStr = m_Temp;
	JudgeStr = JudgeStr.substr(6, JudgeStr.size() - 6);
	if (JudgeStr=="ImageSourceCamera")
	{
		ui.radioButton_Camera->setChecked(true);
	}
	if (JudgeStr == "ImageSourceFile")
	{
		ui.radioButton_FileImage->setChecked(true);
	}
	if (JudgeStr == "QObject")
	{
		ui.radioButton_FileImage->setChecked(true);
		StatueChangeSlot();
	}

	connect(ui.btn_Save, &QPushButton::clicked, this, &ImageSourceSetting::SaveChoiceSlot);
	connect(ui.btn_Cancel, &QPushButton::clicked, this, &ImageSourceSetting::CancelChioceSlot);
	connect(ui.radioButton_Camera, &QRadioButton::clicked, this, &ImageSourceSetting::StatueChangeSlot);
	connect(ui.radioButton_FileImage, &QRadioButton::clicked, this, &ImageSourceSetting::StatueChangeSlot);

	if(m_LayOut!=nullptr)
	{
		ClearLayout(m_LayOut);
		delete m_LayOut;
	}
	m_LayOut = new QHBoxLayout;
	if (m_ImageSource != nullptr) m_LayOut->addWidget(m_ImageSource->OpenSettingDialg());
	ui.groupBox_ImageContent->setLayout(m_LayOut);

	//设置语言字体
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
}

ImageSourceSetting::~ImageSourceSetting()
{
	if (m_LayOut != nullptr)
	{
		ClearLayout(m_LayOut);
		delete m_LayOut;
	}
}

void ImageSourceSetting::StatueChangeSlot()
{
	MyStation* m_Station = m_ImageSource->GetMyPtr();

	if (ui.radioButton_Camera->isChecked()) //当前选中的是相机源
	{
		m_ImageSource = new ImageSourceCamera();
	}
	if (ui.radioButton_FileImage->isChecked()) //当前选中的是文件源
	{
		m_ImageSource = new ImageSourceFile;
	}
	m_ImageSource->SetMyPtr(m_Station);
	connect(m_ImageSource, &ImageSourceBase::ImageReady, m_Station, &MyStation::GetCameraIamge);
	connect(m_ImageSource, &ImageSourceBase::CameraStateChange, m_Station->m_ImageWindow, &ImageWindow::SetCameraStateSlot);


	if (m_LayOut != nullptr)
	{
		ClearLayout(m_LayOut);
		delete m_LayOut;
	}
	m_LayOut = new QHBoxLayout;
	if (m_ImageSource != nullptr) m_LayOut->addWidget(m_ImageSource->OpenSettingDialg());
	ui.groupBox_ImageContent->setLayout(m_LayOut);
}

void ImageSourceSetting::SaveChoiceSlot()
{
	if (m_ImageSource->BtnSave())
	{
		emit NewImageSourceBase(m_ImageSource);
	}
	this->close();
}

void ImageSourceSetting::CancelChioceSlot()
{
	//if (m_ImageSource != nullptr) delete m_ImageSource;
	this->close();
}

void ImageSourceSetting::closeEvent(QCloseEvent *e)
{
	if (m_LayOut != nullptr)
	{
		ClearLayout(m_LayOut);
		delete m_LayOut;
	}
}