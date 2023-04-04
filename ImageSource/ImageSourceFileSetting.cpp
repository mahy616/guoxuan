#include "ImageSourceFileSetting.h"
#include <QFileDialog>
#include <QDirIterator>
#include <QMessageBox>
#include "components/Config/ConfigProgramme.h"
#include "ImageSourceFile.h"

ImageSourceFileSetting::ImageSourceFileSetting(ImageSourceFile *m_SourcePtr, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_ImageSource = m_SourcePtr;

	//获取原来的图像路径
	if (m_SourcePtr->m_Station->m_TableWidget->rowCount() >= 1)
	{
		QString ImagePath = m_SourcePtr->m_Station->m_TableWidget->item(0, 2)->text();
		QFileInfo fileInfo(ImagePath);
		ImagePath = fileInfo.absolutePath();
		ui.lineEdit_Path->setText(ImagePath);
	}

	connect(ui.btn_ChangeRoad, &QPushButton::clicked, this, [=]()
	{
		RootDir = QFileDialog::getExistingDirectory();
		if (RootDir.size() == 0)
		{
			return;
		}
		ui.lineEdit_Path->setText(RootDir);
	});
}

ImageSourceFileSetting::~ImageSourceFileSetting()
{}

bool ImageSourceFileSetting::BtnClickedSave()
{
	if (ui.lineEdit_Path->text().size() != 0)
	{
		RootDir = ui.lineEdit_Path->text();
	}
	QStringList images;
	QStringList Formats;
	Formats << "jpg" << "jpeg" << "png" << "bmp" << "JPG" << "PNG" << "BMP" << "tif" << "TIF";
	getAllFiles(RootDir, images, Formats);
	if (images.size() == 0)
	{
		//先清空原来的图像列表
		m_ImageSource->m_Station->m_TableWidget->clear();
		QMessageBox::information(NULL, tr("error"), tr("No images in folder!"));
		return false;
	}
	else
	{
		m_ImageSource->LoadFileImage(images);
	}

	//当前图像路径
	ConfigProgramme::GetInstance()->AllConfig[m_ImageSource->m_Station->StationIndex - 1].m_ImageSourceConfig.ImageFilePath = RootDir;
	return true;
}

void ImageSourceFileSetting::getAllFiles(const QString& foldPath, QStringList &ImageFiles, const QStringList& formats)
{
	QDirIterator it(foldPath, QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
	while (it.hasNext())
	{
		it.next();
		QFileInfo fileInfo = it.fileInfo();
		if (formats.contains(fileInfo.suffix()))
		{ //检测格式，按需保存
			ImageFiles << fileInfo.absoluteFilePath();
		}
	}
}


