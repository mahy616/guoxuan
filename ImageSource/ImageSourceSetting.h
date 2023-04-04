#pragma once

#include <QWidget>
#include "ui_ImageSourceSetting.h"
#include "ImageSouceBase.h"
#include <QCloseEvent>

class ImageSourceSetting : public QWidget
{
	Q_OBJECT
public:
	ImageSourceSetting(ImageSourceBase *inSource,QWidget *parent = nullptr);
	~ImageSourceSetting();
protected:
	void closeEvent(QCloseEvent *);
private:
	Ui::ImageSourceSettingClass ui;
	ImageSourceBase *m_ImageSource = nullptr;
	QHBoxLayout *m_LayOut = nullptr;
private slots:
	void StatueChangeSlot();
	void SaveChoiceSlot();
	void CancelChioceSlot();
signals:
	void NewImageSourceBase(ImageSourceBase*);
};
