#pragma once
#include "ImageSouceBase.h"
#include "ImageSourceFileSetting.h"
#include <QTimer>
#include <QObject>

class ImageSourceFile : public ImageSourceBase
{
	Q_OBJECT
public:
	ImageSourceFile();
	~ImageSourceFile();
	//��ǰͼ��Դ�Ƿ���ͼ�������(�ж��б����Ƿ�������)
	virtual bool isCanStart() override;
	//�������� - ������ʱ��������һ�ζ�ȡ�б�ڶ��е�ͼƬ·��
	virtual bool Start() override;
	//ֹͣ���� - ֹͣȡͼ��ʱ��
	virtual void Stop() override;
	//����ִ�� - �ֶ����ö�ʱ���ۺ���
	virtual bool SingleGrab() override;
	//���浱ǰͼ��Դ������
	virtual bool BtnSave() override;
	//�������ļ���ʼ����ǰͼ��Դ
	virtual void InintFromConfig(ImageSourceConfig inConfig) override;
	//��ͼ��Դ�����ý���
	virtual QWidget* OpenSettingDialg() override;
private:
	friend class ImageSourceFileSetting; //����LoadFileImage����
private:
	void LoadFileImage(QStringList images);
private:
	int FileIndex = 0;    //��ǰ�ļ��ж����ڼ���ͼ
	ImageSourceFileSetting* m_SettingDialg = nullptr;
	QTimer *m_ReadImgTimer = nullptr;
private slots:
	// ȡͼ�б����ļ�·���Ķ�ʱ���ۺ���
	void ReadingImageSlot();
};

