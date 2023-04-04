#include <windows.h>
#include "SaveImage.h"
#include "QFileInfoList"
#include "qdir.h"
#include "QDate"
#include "QDebug"
#include "components/Config/ConfigProgramme.h"
#include "UI/MyDialog/WaittingDialog.h"
#include <QDirIterator>
#define GB (1024*1024*1024)

CSaveImage *CSaveImage::m_Instance = NULL;
CSaveImage *CSaveImage::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CSaveImage();
	}
	return m_Instance;
}

// ��ȡ��ǰ·���µ������ļ�
void findAllFiles(const QString path, QFileInfoList &fileInfoList)
{
	QDir dir(path);
	foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Time)) {
		findAllFiles(info.filePath(), fileInfoList);
		//qDebug() << "dir:" << info.filePath();
	}
	foreach(QFileInfo info, dir.entryInfoList(QDir::Files)) {
		fileInfoList.append(info);
		//qDebug() << "fileInfo" << info;
	}
}

// ��ȡ��ǰ·���µ������ļ���
void getAllFolds(const QString& foldPath, QStringList &folds)
{
	QDir dir(foldPath);
	foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Time)) {
		getAllFolds(info.filePath(), folds);
	}
	//if (info.absoluteFilePath().isEmpty() == false) folds.append(info.absoluteFilePath());
	foreach(QFileInfo info, dir.entryInfoList(QDir::Dirs)) {
		folds.append(info.absoluteFilePath());
	}
}


CSaveImage::CSaveImage(QThread *parent /* = NULL */)
	:QThread(parent)
{
	m_bStop = false;
	SelfStartDeleteByFileNums(); //�����ʼ��ʱ�Ȱ���ͼƬ�����Զ�ɾ��
}

CSaveImage::~CSaveImage()
{
}

// �����ʼ��ʱ�Ȱ���ͼƬ�����Զ�ɾ��
void CSaveImage::SelfStartDeleteByFileNums()
{
	//����ͼƬ����ɾ��
	QFileInfoList m_CameraFileInfoList, m_RenderFileInfoList;
	findAllFiles(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr + "/CameraImage", m_CameraFileInfoList);
	findAllFiles(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr + "/RenderImage", m_RenderFileInfoList);
	CameraImageNum = m_CameraFileInfoList.count();
	RenderImageNum = m_RenderFileInfoList.count();
	DeleteSurplusNum(true); DeleteSurplusNum(false);
}

void CSaveImage::StopThread()
{
	m_bStop = true;
	//����ʱ���Զ�ɾ��
	if (ConfigProgramme::GetInstance()->m_CameraSave.isDeleteDays)
	{
		DeleteTimeBeforeDir(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr + "/CameraImage", ConfigProgramme::GetInstance()->m_CameraSave.deleteDays);
	}
	if (ConfigProgramme::GetInstance()->m_RenderSave.isDeleteDays)
	{
		int days = ConfigProgramme::GetInstance()->m_RenderSave.deleteDays;
		DeleteTimeBeforeDir(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr + "/RenderImage", ConfigProgramme::GetInstance()->m_RenderSave.deleteDays);
	}

	//���������Զ�ɾ��
	quint64 FreeSpace = GetDiskFreeSpace(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr);
	if (ConfigProgramme::GetInstance()->m_CameraSave.isDeleteMemory)
	{
		while (true)
		{
			if (FreeSpace < ConfigProgramme::GetInstance()->m_CameraSave.deleteMemory)
			{
				if (DeleteEarliestDir(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr + "/CameraImage") == false)
					break;
			}
			else
				break;
		}
	}
	quint64 FreeSpace2 = GetDiskFreeSpace(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr);
	if (ConfigProgramme::GetInstance()->m_RenderSave.isDeleteMemory)
	{
		while (true)
		{
			if (FreeSpace2 < ConfigProgramme::GetInstance()->m_RenderSave.deleteMemory)
			{
				if (DeleteEarliestDir(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr + "/RenderImage") == false)
					break;
			}
			else
				break;
		}
	}
}

void CSaveImage::SetImageInfo(s_ImageInfo ImageInfo)
{
	if (ImageInfo.image.cols == 0 || ImageInfo.image.rows == 0) return;
	m_Mutex.lock();
	if (m_ImageInfos.size() <= 20)
		m_ImageInfos.push_back(ImageInfo);
	m_Mutex.unlock();
}

void CSaveImage::SaveImage(s_ImageInfo &ImageInfo)
{
	QString SavePath = ImageInfo.SavePath /*+ "/" + ImageInfo.MiddleDir*/;
	QDir dir(SavePath);
	if (!dir.exists(SavePath))
	{
		dir.mkpath(SavePath);
	}
	SavePath += "/" + ImageInfo.FileName;
	QByteArray ba = SavePath.toLocal8Bit();
	char *file = ba.data();
	bool rv = imwrite(file, ImageInfo.image);
	if (rv)
	{
		qDebug() << "save image success:" << file;
		ImageInfo.isCameraImage ? CameraImageNum++ : RenderImageNum++;
	}
	else
	{
		qDebug() << "save image failed:" << file;
	}
	//�������Զ�ɾ��
	DeleteByMemory(ImageInfo);
	//��ͼƬ����ɾ��
	DeleteSurplusNum(ImageInfo.isCameraImage);
}

void CSaveImage::run()
{
	while (1)
	{
		if (m_bStop)
		{
			break;
		}
		if (m_ImageInfos.size() > 0)
		{
			m_Mutex.lock();
			s_ImageInfo info = m_ImageInfos.dequeue();
			m_Mutex.unlock();
			SaveImage(info);
		}
		else
		{
			Sleep(50);
		}
	}
}

quint64 CSaveImage::GetDiskFreeSpace(QString DiskName)
{
	qDebug() << "GetDiskFreeSpace";
	//iDriverΪ�̷�(����"C\")
	LPCWSTR strDriver = (LPCWSTR)DiskName.utf16();
	ULARGE_INTEGER freeDiskSpaceAvailable, totalDiskSpace, totalFreeDiskSpace;
	//���ú�����ȡ���̲���(��λΪ�ֽ�Byte),ת��ΪGB����Ҫ����(1024*1024*1024)
	GetDiskFreeSpaceEx(strDriver, &freeDiskSpaceAvailable, &totalDiskSpace, &totalFreeDiskSpace);
	return (quint64)freeDiskSpaceAvailable.QuadPart / GB;
}

// ɾ��ʱ�������һ���ļ��� - ������ɾ��ʱ����
bool CSaveImage::DeleteEarliestDir(QString Path)
{
	bool isHaveFile = false;
	QDate EarliestDate = QDate::currentDate();
	QString EarliestDir;

	QStringList m_Lists;
	getAllFolds(Path, m_Lists);
	QRegularExpression rx("\\d{4}-\\d{2}-\\d{2}");
	for (auto m_One : m_Lists)
	{
		int pos = m_One.indexOf(rx);
		if (pos <= 0) continue;
		isHaveFile = true;
		QString outResultJson = m_One.mid(pos, 10);
		QDate CurDate = QDate::fromString(outResultJson, "yyyy-MM-dd");
		if (CurDate <= EarliestDate)
		{
			EarliestDate = CurDate;
			EarliestDir = m_One;
		}
	}
	if (EarliestDir.size() != 0)
	{
		for (auto m_One : m_Lists)
		{
			if (m_One.indexOf(EarliestDir) >= 0)
			{
				QDir DeleteDir;
				DeleteDir.setPath(EarliestDir);
				DeleteDir.removeRecursively();
			}
		}
	}

	return isHaveFile;
}

// ɾ�������һ���ļ� - ��ͼƬ����ɾ��ʱ����
void CSaveImage::DeleteEarliestOneFile(QString Path, bool isCamera)
{
	QFileInfoList m_fileInfoList;
	findAllFiles(Path, m_fileInfoList);
	if (m_fileInfoList.size() == 0) return;
	QDir DeleteDir;
	if (isCamera)
	{
		if (DeleteDir.remove(m_fileInfoList[0].absoluteFilePath()))
			CameraImageNum = m_fileInfoList.size() - 1;
	}
	else
	{
		if (DeleteDir.remove(m_fileInfoList[0].absoluteFilePath()))
			RenderImageNum = m_fileInfoList.size() - 1;
	}
}

// ��Deadlineʱ��ɾ���ļ��� - ������ɾ��ʱ����
void CSaveImage::DeleteTimeBeforeDir(QString Path, int saveDays)
{
	QDate EarliestDate = QDate::currentDate();
	QStringList EarliestDir;
	QStringList m_Lists;
	getAllFolds(Path, m_Lists);
	QRegularExpression rx("\\d{4}-\\d{2}-\\d{2}");
	for (auto m_One : m_Lists)
	{
		int pos = m_One.indexOf(rx);
		if (pos <= 0) continue;
		QString outResultJson = m_One.mid(pos, 10);
		QDate ImageData = QDate::fromString(outResultJson, "yyyy-MM-dd");
		ImageData = ImageData.addDays(saveDays - 1);
		if (ImageData < EarliestDate)
		{
			EarliestDir.push_back(m_One);
		}
	}
	for (auto m_One : EarliestDir)
	{
		QDir DeleteDir;
		DeleteDir.setPath(m_One);
		DeleteDir.removeRecursively();
	}
}

void CSaveImage::DeleteByMemory(s_ImageInfo ImageInfo)
{
	if (ImageInfo.isCameraImage)
	{
		if (ConfigProgramme::GetInstance()->m_CameraSave.isDeleteMemory)
		{
			QString DiskName = ImageInfo.SavePath.left(3);
			quint64 FreeSpace = GetDiskFreeSpace(DiskName);
			if (FreeSpace < ConfigProgramme::GetInstance()->m_CameraSave.deleteMemory)
			{
				DeleteEarliestDir(ImageInfo.SavePath + "/CameraImage");
			}
		}
	}
	else
	{
		if (ConfigProgramme::GetInstance()->m_RenderSave.isDeleteMemory)
		{
			QString DiskName = ImageInfo.SavePath.left(3);
			quint64 FreeSpace = GetDiskFreeSpace(DiskName);
			if (FreeSpace < ConfigProgramme::GetInstance()->m_RenderSave.deleteMemory)
			{
				DeleteEarliestDir(ImageInfo.SavePath + "/RenderImage");
			}
		}
	}
}


void CSaveImage::DeleteSurplusNum(bool isCamera)
{
	if (isCamera)
	{
		if (ConfigProgramme::GetInstance()->m_CameraSave.isDeleteNums)
		{
			int deleteNums = CameraImageNum - ConfigProgramme::GetInstance()->m_CameraSave.deleteNums;
			for (int i = 1; i <= deleteNums; i++)
			{
				DeleteEarliestOneFile(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr + "/CameraImage", true);
			}
		}
	}
	else
	{
		if (ConfigProgramme::GetInstance()->m_RenderSave.isDeleteNums)
		{
			int deleteNums = RenderImageNum - ConfigProgramme::GetInstance()->m_RenderSave.deleteNums;
			for (int i = 1; i <= deleteNums; i++)
			{
				DeleteEarliestOneFile(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr + "/RenderImage", false);
			}
		}
	}
}