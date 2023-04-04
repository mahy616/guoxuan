#include "ImageSourceFile.h"
#include <QFileInfo>
#include "components/Config/ConfigProgramme.h"

ImageSourceFile::ImageSourceFile()
{
	m_ReadImgTimer = new QTimer;
	connect(m_ReadImgTimer, &QTimer::timeout, this, &ImageSourceFile::ReadingImageSlot);
}

ImageSourceFile::~ImageSourceFile()
{
	if (m_ReadImgTimer != nullptr)
	{
		killTimer(m_ReadImgTimer->timerId());
		delete m_ReadImgTimer;
	}
}

QWidget* ImageSourceFile::OpenSettingDialg()
{
	m_SettingDialg = new ImageSourceFileSetting(this);
	return m_SettingDialg;
}

bool ImageSourceFile::isCanStart()
{
	if (m_Station->m_TableWidget->rowCount() == 0)
		return false;
	else
		return true;
}

bool ImageSourceFile::Start()
{
	if (m_Station->m_TableWidget->rowCount() == 0) return false; //图像列表为空，没有图片，启动失败
	m_ReadImgTimer->start(500);
	return true;
}

void ImageSourceFile::Stop()
{
	m_ReadImgTimer->stop();
}

bool ImageSourceFile::SingleGrab()
{
	if (m_Station->m_TableWidget->rowCount() == 0) return false; //图像列表为空，没有图片，启动失败
	ReadingImageSlot();
	return true;
}

bool ImageSourceFile::BtnSave()
{
	bool returnFlag = true;
	if (m_SettingDialg != nullptr)
	{
		returnFlag = m_SettingDialg->BtnClickedSave();
	}
	//当前选择的相机图像源，保存到单例的配置信息中
	ConfigProgramme::GetInstance()->AllConfig[m_Station->StationIndex - 1].m_ImageSourceConfig.ImageSource_isCamera = false;
	return returnFlag;
}

void ImageSourceFile::LoadFileImage(QStringList images) //从文件夹的图像加载到列表控件显示
{
	m_Station->m_TableWidget->GetFileImageNames(images);
}

void ImageSourceFile::ReadingImageSlot()
{
	if (FileIndex >= m_Station->m_TableWidget->rowCount()|| m_Station->m_TableWidget->rowCount() == 0) //读到文件夹的最后一张图了
	{
		m_ReadImgTimer->stop();
		killTimer(m_ReadImgTimer->timerId());
		FileIndex = 0;
		return;
	}

	QString ImagePath = m_Station->m_TableWidget->item(FileIndex, 2)->text();
	if (ImagePath.size() == 0)
	{
		QMessageBox::information(NULL, tr("Tips"), tr("Image is empty")); return;
	}
	Mat m_OriginalImage = cv::imread(ImagePath.toLocal8Bit().toStdString(), -1);

	ThreadQueueInfos inData;
	inData.m_Image = m_OriginalImage;
	inData.TableIndex = FileIndex;
	QFileInfo fileinfo(m_Station->m_TableWidget->item(inData.TableIndex, 2)->text());
	inData.ImageName = fileinfo.baseName();

	if (m_Station->m_AlgoThread->SetImage(inData))
	{
		FileIndex++;
		if (FileIndex >= m_Station->m_TableWidget->rowCount()) //读到文件夹的最后一张图了
		{
			m_ReadImgTimer->stop();
			killTimer(m_ReadImgTimer->timerId());
			FileIndex = 0;
			return;
		}
	}
}

void ImageSourceFile::InintFromConfig(ImageSourceConfig inConfig)
{
	if (inConfig.ImageFilePath.size() == 0) return;
	if (m_SettingDialg == nullptr) m_SettingDialg = new ImageSourceFileSetting(this);
	m_SettingDialg->RootDir = inConfig.ImageFilePath;
	m_SettingDialg->BtnClickedSave();
}