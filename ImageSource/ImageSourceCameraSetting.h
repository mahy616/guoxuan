#pragma once

#include <QWidget>
#include "ui_ImageSourceCameraSetting.h"
#include "components/Camera/Camera.h"
#include <qtimer.h>
#include <memory>
#include "PublicParamter.h"
#include <QCloseEvent>
#include <QButtonGroup>

typedef struct CameraInfos
{
	bool _isCameraSelected;
	bool _isOpen;
	bool _isGrabbing;
	QString _currentCameraName;
	int _exposureTime = -1;
	int _gain = -1;
	QString _pixelFormat = "Mono8";
	QString _triggerMode;
	QString _triggerSource;
	int BindCommunicationIndex;
	QString BingdTriggerStr;
}CameraInfos;

class MyStation;
class ImageSourceCamera;
class ImageSourceCameraSetting : public QWidget
{
	Q_OBJECT

public:
	ImageSourceCameraSetting(MyStation* inStation, ImageSourceCamera* inCamera, QWidget *parent = Q_NULLPTR);
	~ImageSourceCameraSetting();
private:
	void InintParam();
	void InintConnect();
	void OpenConfigCamera();
	void SetTriggerModel(bool onTrigger);
	void AddSoftTriggerItem();
	void GetOrigenConfig();
	void ReStoreCameraState();
	void ShowSoftTriggerBindState();
	void updateCtrls();
	void updateSlider(Camera::ParamName paramName);
	void updateComboBox(Camera::ParamName paramName);
	void ClearSlider(QSlider * slider, QLineEdit * label);
	void ClearComboBox(QComboBox * pCtrl);
	QImage MattoQImage(Mat image);
protected:
	void closeEvent(QCloseEvent *);
private slots:
	void onImageReady(cv::Mat image);
	void onCameraError(QString msg);
	void onConnectStatusChanged();
	void onGrabStatusChanged();
	void onParamUpdated(Camera::ParamName paramName);
	void onTimer();
	void slot_GrabTypeClicked(int);
private slots:
	void on_btnEnumCamera_clicked();
	void on_btnOpenCamera_clicked();
	void on_btnCloseCamera_clicked();
	void on_btnSingleShot_clicked();
	void on_btnContinuous_clicked();
	void on_btnStop_clicked();
	void on_btnSoftwareTrigger_clicked();
	void on_horizontalSliderExposure_valueChanged(int value);
	void on_horizontalSliderGain_valueChanged(int value);
	void on_lineEditExposure_ValueChange();
	void on_lineEditGain_ValueChange();
	void on_comboBoxPixelFormat_currentIndexChanged(QString name);
	void on_comboBoxTriggerMode_currentIndexChanged(QString name);
	void on_comboBoxTriggerSource_currentIndexChanged(QString name);
	void on_btmBindSoftTriggerSource();
private:
	Ui::ImageSourceCameraSetting ui;
	int* StationIndex;
	MyStation* m_MyStation;
	Camera* m_camera;
	QTimer m_timer;
	uint64_t m_imageCount;
	uint64_t m_imageCountLast;
	bool m_isComboboxAddingItem;
	CameraInfos m_TempConfig;
	ImageSourceCamera* inCameraPtr;
public:
	void BtnClickedSave();
};
