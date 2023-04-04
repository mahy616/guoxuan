#include "ImageSourceCameraSetting.h"
#include <qdebug.h>
#include <QMetaType>
#include <qmessagebox.h>
#include "components/Config/ConfigProgramme.h"
#include "MyStation.h"
#include "components/Camera/SoftTriggerConnect.h"
#include "ImageSourceCamera.h"
using namespace cv;

ImageSourceCameraSetting::ImageSourceCameraSetting(MyStation* inStation, ImageSourceCamera* inCamera, QWidget *parent)
	: QWidget(parent)
	, m_MyStation(inStation)
	, StationIndex(&(inStation->StationIndex))
	, m_imageCount(0)
	, m_imageCountLast(0)
	, m_isComboboxAddingItem(false)
	, inCameraPtr(inCamera)
{
	ui.setupUi(this);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
	m_timer.start(1000);
	if (inCamera->m_camera == nullptr) return;
	m_camera = inCamera->m_camera;
	//先获取相机初始状态的各参数
	GetOrigenConfig();
	//先断开相机信号与工位的连接
	disconnect(m_camera, &Camera::imageReady, inCamera, &ImageSourceCamera::ConnectImage);
	SoftTriggerConnect::GetInstance()->isCameraConnectAlgo = true;

	qRegisterMetaType<cv::Mat>("cv::Mat");
	qRegisterMetaType<Camera::ParamName>("Camera::ParamName");
	qRegisterMetaType<CameraInfoConfig>("CameraInfoConfig");

	OpenConfigCamera();
	updateCtrls();

	InintParam();
	InintConnect();
}

ImageSourceCameraSetting::~ImageSourceCameraSetting()
{
	disconnect(this->m_camera, SIGNAL(connectStatusChanged()), this, SLOT(onConnectStatusChanged()));
	disconnect(this->m_camera, SIGNAL(grabStatusChanged()), this, SLOT(onGrabStatusChanged()));

	SoftTriggerConnect::GetInstance()->isCameraConnectAlgo = false;
	ui.horizontalSliderExposure->disconnect();
	ui.lineEditExposure->disconnect();
	ui.horizontalSliderGain->disconnect();
	ui.lineEditGain->disconnect();
	ReStoreCameraState();

	if (m_camera != nullptr)
	{
		connect(m_camera, &Camera::imageReady, inCameraPtr, &ImageSourceCamera::ConnectImage);
		//connect(m_camera, &Camera::imageReady, m_MyStation, &MyStation::GetCameraIamge);
	}
	if (m_timer.isActive())
	{
		m_timer.stop();
		killTimer(m_timer.timerId());
	}
}

void ImageSourceCameraSetting::OpenConfigCamera()
{
	auto list = m_camera->GetCameraList();
	if (!list.empty())
	{
		if (m_camera->IsOpened() == false)
		{
			m_camera->OpenCamera(ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.name);
			if (m_camera->IsOpened())
			{
				QString triggerSource = ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource;
				m_camera->SetEnumParamValue(Camera::TriggerMode, ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerMode);
				m_camera->SetEnumParamValue(Camera::TriggerSource, ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource);
				m_camera->SetNumParamValue(Camera::ExposureTime, ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.exposure);
				m_camera->SetNumParamValue(Camera::Gain, ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.gain);
			}
		}

		ui.comboBoxCameras->clear();
		for (auto name : list) ui.comboBoxCameras->addItem(name);
	}
}

void ImageSourceCameraSetting::ShowSoftTriggerBindState()
{
	QString m_BindCommunication = SoftTriggerConnect::GetInstance()->GetCommunication(m_camera);
	if (m_BindCommunication.isEmpty())
	{
		ui.label_SoftTriggerState->setStyleSheet("background:#AB251A;border-radius:4px;");
		ui.label_SoftTriggerState->setToolTip(tr("Binding failed"));
	}
	else
	{
		ui.comboBoxTriggerSource->setCurrentText(m_BindCommunication);
		//int Indexx = ui.comboBoxTriggerSource->findText(m_BindCommunication);
		QString m_ConnectStr = SoftTriggerConnect::GetInstance()->GetGrabStr(m_camera);
		if (m_ConnectStr.size() == 0)
		{
			ui.label_SoftTriggerState->setStyleSheet("background:#AB251A;border-radius:4px;");
			ui.label_SoftTriggerState->setToolTip(tr("Binding failed"));
		}
		else
		{
			ui.label_SoftTriggerState->setStyleSheet("background:#377D22;border-radius:4px;");
			ui.label_SoftTriggerState->setToolTip(tr("Bind successfully"));
			ui.lineEdit_TriggerStr->setText(SoftTriggerConnect::GetInstance()->GetGrabStr(m_camera));
		}
	}
}

void ImageSourceCameraSetting::InintParam()
{
	ui.label_5->setVisible(false);
	ui.comboBoxTriggerMode->setVisible(false);
	QButtonGroup* m_GrabType = new QButtonGroup(this);
	m_GrabType->addButton(ui.radioButton_free, 1);
	m_GrabType->addButton(ui.radioButton_hard, 2);
	m_GrabType->addButton(ui.radioButton_soft, 3);
	connect(m_GrabType, SIGNAL(buttonClicked(int)), this, SLOT(slot_GrabTypeClicked(int)));

	//先找TriggerModel是否为on判断是否自由采集
	QString TriggerModeName = m_camera->GetEnumParamValue(Camera::ParamName::TriggerMode);
	if (TriggerModeName == "Off" || TriggerModeName == "off" || TriggerModeName == "OFF")
	{
		ui.radioButton_free->setChecked(true);
		emit ui.radioButton_free->clicked();
		slot_GrabTypeClicked(1);
	}
	else//再找TriggerSource是否为软触发
	{
		QString TriggerSourceName = m_camera->GetEnumParamValue(Camera::ParamName::TriggerSource);
		if (TriggerSourceName == "SoftWare" || TriggerSourceName == "Software" || TriggerSourceName == "SOFTWARE")
		{
			emit ui.radioButton_soft->setChecked(true);
			ui.radioButton_soft->clicked();
			slot_GrabTypeClicked(3);
		}
		else
		{
			emit ui.radioButton_hard->setChecked(true);
			ui.radioButton_hard->clicked();
			slot_GrabTypeClicked(2);
		}
	}

	ui.label_4->setVisible(false);
	ui.comboBoxPixelFormat->setVisible(false);

	ShowSoftTriggerBindState();
}

void ImageSourceCameraSetting::InintConnect()
{
	connect(ui.lineEditExposure, &QLineEdit::editingFinished, this, &ImageSourceCameraSetting::on_lineEditExposure_ValueChange);
	connect(ui.lineEditGain, &QLineEdit::editingFinished, this, &ImageSourceCameraSetting::on_lineEditGain_ValueChange);
	connect(ui.btn_ConnectCommunicate, &QPushButton::clicked, this, &ImageSourceCameraSetting::on_btmBindSoftTriggerSource);
	connect(this->m_camera, SIGNAL(connectStatusChanged()), this, SLOT(onConnectStatusChanged()));
	connect(this->m_camera, SIGNAL(grabStatusChanged()), this, SLOT(onGrabStatusChanged()));
	connect(this->m_camera, SIGNAL(imageReady(cv::Mat)), this, SLOT(onImageReady(cv::Mat)));
	connect(this->m_camera, SIGNAL(cameraError(QString)), this, SLOT(onCameraError(QString)));
	connect(this->m_camera, SIGNAL(paramUpdated(Camera::ParamName)), this, SLOT(onParamUpdated(Camera::ParamName)));
}

void ImageSourceCameraSetting::SetTriggerModel(bool onTrigger)
{
	if (onTrigger)
	{
		m_camera->SetEnumParamValue(Camera::TriggerMode, "On");
	}
	else
	{
		m_camera->SetEnumParamValue(Camera::TriggerMode, "Off");
	}
}

void ImageSourceCameraSetting::slot_GrabTypeClicked(int inID)
{
	switch (inID)
	{
	case 1: //自由采集
		ui.widget_Trigger->setVisible(false);
		SetTriggerModel(false);
		if (m_camera->IsGrabbing() == false) m_camera->GrabContinuous();
		//SoftTriggerConnect::GetInstance()->UnBinding(m_camera);
		ui.btnSingleShot->setVisible(true);
		ui.btnContinuous->setVisible(true);
		ui.btnStop->setVisible(true);
		break;
	case 2: //硬触发
		SetTriggerModel(true);
		ui.widget_Trigger->setVisible(true);
		ui.widget_SoftTrigger->setVisible(false);
		ui.comboBoxTriggerSource->clear();
		updateComboBox(Camera::ParamName::TriggerSource);
		if (ui.comboBoxTriggerSource->count()) m_camera->SetEnumParamValue(Camera::TriggerSource, ui.comboBoxTriggerSource->currentText());
		if (m_camera->IsGrabbing() == false) m_camera->GrabContinuous();
		ui.btnSingleShot->setVisible(false);
		ui.btnContinuous->setVisible(false);
		ui.btnStop->setVisible(false);
		break;
	case 3: //软触发
		ui.widget_Trigger->setVisible(true);
		ui.widget_SoftTrigger->setVisible(true);
		if (m_camera->IsGrabbing() == false) m_camera->GrabContinuous();
		ui.comboBoxTriggerSource->clear();
		AddSoftTriggerItem();
		SetTriggerModel(true);
		m_camera->SetEnumParamValue(Camera::TriggerSource, "Software");
		ui.btnSingleShot->setVisible(false);
		ui.btnContinuous->setVisible(false);
		ui.btnStop->setVisible(false);
		break;
	default:
		break;
	}
	ShowSoftTriggerBindState();
}

void ImageSourceCameraSetting::AddSoftTriggerItem()
{
	QMap<QString, CommunicateBase*>::Iterator iter = ConfigProgramme::GetInstance()->m_Comunicate.begin();
	for (; iter != ConfigProgramme::GetInstance()->m_Comunicate.end(); ++iter)
	{
		ui.comboBoxTriggerSource->addItem(iter.key());
	}
}

void ImageSourceCameraSetting::on_btmBindSoftTriggerSource()
{
	SoftTriggerConnect::GetInstance()->UnBinding(m_camera);

	if (ui.comboBoxTriggerSource->count() == 0)
	{
		QMessageBox::information(nullptr, tr("Warning"), tr("Please add communication module"));
		return;
	}
	QString CommuniCateName = ui.comboBoxTriggerSource->currentText();
	CommunicateBase* m_CommunicateModuel = ConfigProgramme::GetInstance()->m_Comunicate[CommuniCateName];

	bool isSuccess = SoftTriggerConnect::GetInstance()->Binding(m_camera, m_CommunicateModuel, ui.lineEdit_TriggerStr->text());
	if (isSuccess)
	{
		ui.label_SoftTriggerState->setStyleSheet("background:#377D22;border-radius:4px;");
		ui.label_SoftTriggerState->setToolTip(tr("Bind successfully"));
		QMessageBox::information(nullptr, tr("Tips"), tr("Bind successfully"));
	}
	else
	{
		ui.label_SoftTriggerState->setStyleSheet("background:#AB251A;border-radius:4px;");
		ui.label_SoftTriggerState->setToolTip(tr("Binding failed"));
		QMessageBox::information(nullptr, tr("Tips"), tr("Binding failed"));
	}
}


void ImageSourceCameraSetting::updateCtrls()
{
	bool isCameraSelected = (ui.comboBoxCameras->currentIndex() != -1);
	bool isOpen = m_camera->IsOpened();
	bool isGrabbing = isOpen && m_camera->IsGrabbing();
	bool isSingleShotSupported = m_camera->IsSingleShotSupported();
	if (isOpen)
	{
		ui.comboBoxCameras->setCurrentText(m_camera->GetCurrentCameraName());
	}

	ui.btnEnumCamera->setEnabled(!isOpen);
	ui.btnOpenCamera->setEnabled(!isOpen && isCameraSelected);
	ui.btnCloseCamera->setEnabled(isOpen);
	ui.btnSingleShot->setEnabled(isOpen && !isGrabbing && isSingleShotSupported);
	ui.btnContinuous->setEnabled(isOpen && !isGrabbing);
	ui.btnStop->setEnabled(isGrabbing);
	ui.btnSoftwareTrigger->setEnabled(isOpen);
	ui.comboBoxCameras->setEnabled(!isOpen);
	updateSlider(Camera::ParamName::ExposureTime);
	updateSlider(Camera::ParamName::Gain);
	updateComboBox(Camera::ParamName::PixelFormat);
	updateComboBox(Camera::ParamName::TriggerMode);
	updateComboBox(Camera::ParamName::TriggerSource);
	ui.comboBoxPixelFormat->setEnabled(isOpen && !isGrabbing);

	ui.radioButton_free->setEnabled(isOpen);
	ui.radioButton_hard->setEnabled(isOpen);
	ui.radioButton_soft->setEnabled(isOpen);
	ui.lineEdit_TriggerStr->setEnabled(isOpen);
}

void ImageSourceCameraSetting::GetOrigenConfig()
{
	m_TempConfig._isCameraSelected = (ui.comboBoxCameras->currentIndex() != -1);
	m_TempConfig._isOpen = m_camera->IsOpened();
	m_TempConfig._isGrabbing = m_camera->IsOpened() && m_camera->IsGrabbing();
	m_TempConfig._currentCameraName = m_camera->GetCurrentCameraName();
	m_TempConfig._exposureTime = m_camera->GetNumParamValue(Camera::ParamName::ExposureTime);
	m_TempConfig._gain = m_camera->GetNumParamValue(Camera::ParamName::Gain);
	m_TempConfig._pixelFormat = m_camera->GetEnumParamValue(Camera::ParamName::PixelFormat);
	m_TempConfig._triggerMode = m_camera->GetEnumParamValue(Camera::ParamName::TriggerMode);
	m_TempConfig._triggerSource = m_camera->GetEnumParamValue(Camera::ParamName::TriggerSource);
}

void ImageSourceCameraSetting::ReStoreCameraState()
{
	if (m_camera == nullptr) return;
	if (m_TempConfig._triggerMode.size() != 0) m_camera->SetEnumParamValue(Camera::TriggerMode, m_TempConfig._triggerMode);
	if (m_TempConfig._triggerSource.size() != 0 && m_camera->IsOpened()) m_camera->SetEnumParamValue(Camera::TriggerSource, m_TempConfig._triggerSource);
	if (m_TempConfig._pixelFormat.size() != 0) m_camera->SetEnumParamValue(Camera::PixelFormat, m_TempConfig._pixelFormat);
	if (m_TempConfig._exposureTime != -1) m_camera->SetNumParamValue(Camera::ExposureTime, m_TempConfig._exposureTime);
	if (m_TempConfig._gain != -1) m_camera->SetNumParamValue(Camera::Gain, m_TempConfig._gain);

	if (m_camera->IsOpened() == true)
	{
		m_camera->CloseCamera();
	}
}

void ImageSourceCameraSetting::updateSlider(Camera::ParamName paramName)
{
	QSlider *slider = nullptr;
	QLineEdit *edit = nullptr;
	QString type;
	switch (paramName)
	{
	case Camera::ExposureTime:
		slider = ui.horizontalSliderExposure;
		edit = ui.lineEditExposure;
		type = "ExposureTime";
		break;
	case Camera::Gain:
		slider = ui.horizontalSliderGain;
		edit = ui.lineEditGain;
		type = "Gain";
		break;
	default:
		break;
	}
	if (!m_camera->IsOpened())
	{
		ClearSlider(slider, edit);
		return;
	}
	//qDebug() << "Update " << type << " Ctrl";
	slider->setEnabled(true);
	int min, max; m_camera->GetNumParamRange(paramName, min, max);
	int value = m_camera->GetNumParamValue(paramName);
	if (slider->minimum() != min || slider->maximum() != max)
	{
		//qDebug() << type << " slider range " << slider->minimum() << " " << slider->maximum();
		//qDebug() << "Set " << type << " slider range " << min << " " << max;
		slider->setRange(min, max);
		//qDebug() << "Set " << type << " slider range finish";
	}
	if (value != slider->value())
	{
		//qDebug() << type << " slider value " << slider->value();
		//qDebug() << "Set " << type << " slider value to " << value;
		slider->setValue(value);
		//qDebug() << "Set " << type << " slider value finish " << value;
	}
	edit->setText(QString::number(value));
	//qDebug() << "update " << type << " Ctrl Finish";

}

void ImageSourceCameraSetting::updateComboBox(Camera::ParamName paramName)
{
	QComboBox * comboBox = nullptr;
	switch (paramName)
	{
	case Camera::PixelFormat:
		comboBox = ui.comboBoxPixelFormat;
		break;
	case Camera::TriggerMode:
		comboBox = ui.comboBoxTriggerMode;
		break;
	case Camera::TriggerSource:
		comboBox = ui.comboBoxTriggerSource;
		break;
	default:
		break;
	}
	if (!m_camera->IsOpened())
	{
		ClearComboBox(comboBox);
		return;
	}
	comboBox->setEnabled(true);
	auto value = m_camera->GetEnumParamValue(paramName);
	if (comboBox->currentText() != value)
	{
		comboBox->clear();
		m_isComboboxAddingItem = true;
		for (auto text : m_camera->GetEnumParamRange(paramName))
		{
			comboBox->addItem(text);
		}
		comboBox->setCurrentText(value);
		if (paramName == Camera::TriggerSource)
		{
			QString nowSource = ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource;
			if (nowSource.size() != 0)
			{
				comboBox->setCurrentText(nowSource);
			}
		}
		m_isComboboxAddingItem = false;
	}
	if (paramName == Camera::TriggerSource && m_camera != nullptr)
	{
		if (m_camera->IsOpened())
		{
			if (comboBox->currentText().size() != 0)
				m_camera->SetEnumParamValue(Camera::TriggerSource, value);
		}
	}
}

void ImageSourceCameraSetting::ClearSlider(QSlider *slider, QLineEdit *label)
{
	slider->setSliderPosition(0);
	slider->setRange(0, 0);
	slider->setEnabled(false);
	label->setText("");
}

void ImageSourceCameraSetting::ClearComboBox(QComboBox *pCtrl)
{
	pCtrl->clear();
	pCtrl->setEnabled(false);
}

void ImageSourceCameraSetting::onCameraError(QString msg)
{
	//QMessageBox::information(NULL, tr("camera error"), msg);
}

void ImageSourceCameraSetting::on_btnEnumCamera_clicked()
{
	if (m_camera->EnumerateDevices())
	{
		updateCtrls();
		//ui.comboBoxCameras->setCurrentIndex(0);
	}
}

void ImageSourceCameraSetting::on_btnOpenCamera_clicked()
{
	m_camera->OpenCamera(ui.comboBoxCameras->currentText());
	InintParam();
}

void ImageSourceCameraSetting::on_btnCloseCamera_clicked()
{
	m_camera->CloseCamera();
}

void ImageSourceCameraSetting::on_btnSingleShot_clicked()
{
	m_camera->GrabSingle();
}

void ImageSourceCameraSetting::on_btnContinuous_clicked()
{
	QString temp = m_camera->GetEnumParamValue(Camera::ParamName::TriggerMode);
	if (m_camera->GetEnumParamValue(Camera::ParamName::TriggerMode) == "On")
	{
		QMessageBox::information(nullptr, tr("tips"), tr("The trigger mode is currently on, continuous grabbing operation fails"));
		return;
	}
	m_camera->GrabContinuous();
}

void ImageSourceCameraSetting::on_btnStop_clicked()
{
	m_camera->GrabStop();
}

void ImageSourceCameraSetting::on_btnSoftwareTrigger_clicked()
{
	m_camera->Trigger();
}

void ImageSourceCameraSetting::on_horizontalSliderExposure_valueChanged(int value)
{
	m_camera->SetNumParamValue(Camera::ExposureTime, value);
}

void ImageSourceCameraSetting::on_horizontalSliderGain_valueChanged(int value)
{
	m_camera->SetNumParamValue(Camera::Gain, value);
}

void ImageSourceCameraSetting::on_lineEditExposure_ValueChange()
{
	m_camera->SetNumParamValue(Camera::ExposureTime, ui.lineEditExposure->text().toInt());
}

void ImageSourceCameraSetting::on_lineEditGain_ValueChange()
{
	m_camera->SetNumParamValue(Camera::Gain, ui.lineEditGain->text().toInt());
}

void ImageSourceCameraSetting::on_comboBoxPixelFormat_currentIndexChanged(QString name)
{
	if (name.isEmpty() || m_isComboboxAddingItem) return;
	m_camera->SetEnumParamValue(Camera::PixelFormat, name);
}

void ImageSourceCameraSetting::on_comboBoxTriggerMode_currentIndexChanged(QString name)
{
	if (name.isEmpty() || m_isComboboxAddingItem) return;
	m_camera->SetEnumParamValue(Camera::TriggerMode, name);
}

void ImageSourceCameraSetting::on_comboBoxTriggerSource_currentIndexChanged(QString name)
{
	if (name.isEmpty() || m_isComboboxAddingItem) return;
	m_camera->SetEnumParamValue(Camera::TriggerSource, name);
}

void ImageSourceCameraSetting::onConnectStatusChanged()
{
	updateCtrls();
}

void ImageSourceCameraSetting::onGrabStatusChanged()
{
	updateCtrls();
}

void ImageSourceCameraSetting::onParamUpdated(Camera::ParamName paramName)
{
	switch (paramName)
	{
	case Camera::ExposureTime:
	case Camera::Gain:
		updateSlider(paramName);
		break;
	case Camera::PixelFormat:
	case Camera::TriggerMode:
	case Camera::TriggerSource:
		updateComboBox(paramName);
		break;
	default:
		break;
	}
}

void ImageSourceCameraSetting::onImageReady(cv::Mat image)
{
	m_imageCount++;
	ui.ShowWidget->SetImage(MattoQImage(image));
}

void ImageSourceCameraSetting::onTimer()
{
	if (m_camera == nullptr)
	{
		QMessageBox::information(NULL, "error", "camera pointer is null");
		close();
	}
	// Update the status bars.
	else if (m_camera->IsOpened())
	{
		// Very simple approximation. The timer is triggerd every second.
		double fpsEstimate = (double)(m_imageCount - m_imageCountLast);
		m_imageCountLast = m_imageCount;
		QString status = QString("Frame rate: %1 fps\tImages: %2").arg(fpsEstimate).arg(m_imageCount);
		ui.lineEditStatistic->setText(status);
	}
	else
	{
		ui.lineEditStatistic->setText("");
	}
}

void ImageSourceCameraSetting::BtnClickedSave()
{
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.exposure = m_camera->GetNumParamValue(Camera::ExposureTime);
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.gain = m_camera->GetNumParamValue(Camera::Gain);
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.name = m_camera->GetCurrentCameraName();
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerMode = m_camera->GetEnumParamValue(Camera::TriggerMode);
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.triggerSource = m_camera->GetEnumParamValue(Camera::TriggerSource);
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.isGrabbing = m_camera->IsGrabbing();
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.SoftTrigerCommunication = ui.comboBoxTriggerSource->currentText();
	ConfigProgramme::GetInstance()->AllConfig[*StationIndex - 1].m_ImageSourceConfig.m_CameraInfo.GrabStr = ui.lineEdit_TriggerStr->text();
	GetOrigenConfig();
}

void ImageSourceCameraSetting::closeEvent(QCloseEvent *e)
{
	//if (m_MyStation->m_camera != nullptr)
	//	connect(m_MyStation->m_camera, &Camera::imageReady, m_MyStation, &MyStation::GetCameraIamge);
}

QImage ImageSourceCameraSetting::MattoQImage(Mat image)
{
	switch (image.type())
	{
	case CV_8UC1:
	{
		QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols, QImage::Format_Grayscale8);
		return img;
	}
	break;
	case CV_8UC3:
	{
		QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols * 3, QImage::Format_RGB888);
		return img.rgbSwapped();
	}
	break;
	default:
	{
		QImage img;
		return img;
	}
	break;
	}
}