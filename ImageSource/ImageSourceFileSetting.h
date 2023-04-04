#pragma once

#include <QWidget>
#include "ui_ImageSourceFileSetting.h"


class ImageSourceFile;
class ImageSourceFileSetting : public QWidget
{
	Q_OBJECT

public:
	ImageSourceFileSetting(ImageSourceFile *m_SourcePtr,QWidget *parent = nullptr);
	~ImageSourceFileSetting();
	bool BtnClickedSave();
	QString RootDir;
private:
	Ui::ImageSourceFileSettingClass ui;
	void getAllFiles(const QString& foldPath, QStringList &ImageFiles, const QStringList& formats);
	ImageSourceFile* m_ImageSource;
};
