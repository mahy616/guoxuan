#include "MyStation.h"
#include "components/Config/ConfigProgramme.h"
#include "ImageSouceBase.h"
#include "ImageSourceCamera.h"
#include "ImageSourceFile.h"
#include "UI/MyWidget/DockWidgetTitter.h"
#include "UI/MyDialog/WaittingDialog.h"

MyStation::MyStation(int windowsIndex, QWidget *parent)
{
	inintVariable(windowsIndex);
	inintConnection();
	//initAlgo(windowsIndex);
}

// �˳��㷨�߳�
void MyStation::CloseAlgo()
{
	if (m_AlgoThread->bStart == true)
	{
		// �����ǰ�㷨���ڳ�ʼ���У��ȳ�ʼ�����������
		if (m_AlgoThread->IsInintDone() == false)
		{
			WaittingDialog* m_WaittingDialog = new WaittingDialog(tr("Pipeline initializing... Window will be deleted when initialization completed"));
			m_WaittingDialog->show();
			//�ȴ���
			while (true)
			{
				if (m_AlgoThread->IsInintDone())
				{
					delete m_WaittingDialog;
					break;
				}		
				Sleep(50);
				QCoreApplication::processEvents();
			}
		}

		m_AlgoThread->bStart = false;
		//��Ҫ��������ѹ��һ���������ݣ���ѹ�볤��Ϊ0��ͼ���������̻߳�continue,����bStartΪfalse�Զ��˳��߳�
		ThreadQueueInfos inData;
		inData.m_Image = cv::Mat::zeros(0, 0, CV_8UC1);
		inData.TableIndex = 0;
		inData.ImageName = "end";
		m_AlgoThread->SetImage(inData);
		m_AlgoThread->quit(); m_AlgoThread->wait();
	}
}

MyStation::~MyStation()
{
	CloseAlgo();
	if (m_TableWidget != nullptr)	delete m_TableWidget; m_TableWidget = nullptr;
	if (m_ImageWindow != nullptr) delete m_ImageWindow; m_ImageWindow = nullptr;
	if (m_AlgoThread != nullptr) delete m_AlgoThread; m_AlgoThread = nullptr;
	if (m_DataStatistic != nullptr) delete m_DataStatistic; m_DataStatistic = nullptr;
	if (m_TimeStatistic != nullptr) delete m_TimeStatistic; m_TimeStatistic = nullptr;
	if (m_DockWidget != nullptr) delete m_DockWidget; m_DockWidget = nullptr;
	//���޸� if (m_ResultListWidget != NULL) delete m_ResultListWidget; m_ResultListWidget = nullptr;
}

void MyStation::initAlgo(int windowsIndex)
{
	ModelChoice ConfigParamter;

	JsonReader m_JsonReader;
	QString path;
	if (windowsIndex == 0)
		path = "./solution_head";
	else if (windowsIndex == 1)
		path = "./solution_end";
	ConfigResult m_ConfigResults = m_JsonReader.GetConfigResult(path);
	if (m_ConfigResults.EveryModel.size() > 0)
	{
		std::vector<int>soutionIndex{ 0 };
		ConfigParamter.soutionIndex = soutionIndex;
		ConfigParamter.TypeName = m_ConfigResults.TypeName;
		ConfigParamter.moduleID.push_back(m_ConfigResults.EveryModel[0].ModeType[0].ModulesName);
		ConfigParamter.modeType.push_back(m_ConfigResults.EveryModel[0].ModeType[0].m_ModeType);
		ConfigParamter.RealNameValue.push_back(m_ConfigResults.EveryModel[0].ModeType[0].RealNameValue);
		ConfigParamter.labelsNamesVec.push_back(m_ConfigResults.EveryModel[0].ModeType[0].LableNames);
		ConfigParamter._jsonPath = path+"/config.json";
	}
	else
	{
		return;
	}
	//�㷨���ʼ��ģ��
	if (m_AlgoThread->InitModule(ConfigParamter))
	{
		QString msg;
		if (windowsIndex == 0)
			msg = QString::fromLocal8Bit("��ͷOCR��ʼ���ɹ�");
		else if(windowsIndex == 1)
			msg = QString::fromLocal8Bit("��βOCR��ʼ���ɹ�");
		emit sendLog(msg);
	}
	if (ConfigParamter.modeType[ConfigParamter.modeType.size() - 1] == "OCR" || ConfigParamter.modeType[ConfigParamter.modeType.size() - 1] == "ocr")
	{
		isShowOkNg = false;
	}
	else
	{
		isShowOkNg = true;
	}
}

void MyStation::inintVariable(int windowsIndex)
{
	StationIndex = windowsIndex;

	//������ͼ�߳�
	if (CSaveImage::GetInstance()->isRunning() == false)
		CSaveImage::GetInstance()->start();

	//��������б�ؼ�
	m_TableWidget = new MyTableWidget(&isShowOkNg, NULL);
	m_ResultListWidget = new ResultsListWidget(m_TableWidget);

	//��������ͳ��
	//m_DataStatistic = new DataStatistics;

	//������ʱͳ��
	//m_TimeStatistic = new TimeStatistics;
	//m_result_setting = new ResultSetting(windowsIndex);
	//�����㷨�̲߳�����
	m_AlgoThread = new CAlgoThread(&StationIndex);
	m_AlgoThread->start();
	m_AlgoThread->bStart = true;

	//����ͼ��Դ(Ĭ��ָ�����Դ)
	m_ImageSource = new ImageSourceCamera;
	m_ImageSource->SetMyPtr(this);
	auto camera_setting = dynamic_cast<ImageSourceCamera *>(m_ImageSource);
	//Camera *camera_station = camera_setting->getCameraPtr();
	camera_setting->initCamera(windowsIndex);

	//����ͼ�񴰿�
	m_ImageWindow = new ImageWindow(&StationIndex, &isShowOkNg);
	m_ImageWindow->SetImageSourcePtr(m_ImageSource);              //���뵱ǰͼ��Դ�����
	std::function<std::vector<AllThreshold>(void)> algoThreadPtr = std::bind(&CAlgoThread::GetThresholdValue, m_AlgoThread); //���㷨��ȡ��ֵ�ĺ���ָ��
	std::function<std::vector<ViMoModelInfo>(void)> algoInfoPtr = std::bind(&CAlgoThread::GetAlogInfo, m_AlgoThread);        //���㷨��ȡģ����Ϣ�ĺ���ָ��
	m_ImageWindow->SetAlgoThreadCallBackPtr(algoThreadPtr, algoInfoPtr);   //������ָ�봫��ͼ�񴰿�

	////����QDockWidget��Widget
	//QVBoxLayout *rightLayOut = new QVBoxLayout;
	////rightLayOut->addWidget(m_DataStatistic);
	//rightLayOut->addWidget(m_result_setting);
	////rightLayOut->addWidget(m_TimeStatistic);
	////rightLayOut->addWidget(m_ResultListWidget);
	//QSpacerItem * sparcer_item = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
	//rightLayOut->addItem(sparcer_item);
	//rightLayOut->setStretch(0, 1);
	//rightLayOut->setStretch(1, 1);
	//rightLayOut->setStretch(2, 4);
	//rightLayOut->setContentsMargins(0, 0, 0, 0);
	//QWidget *InserWidget = new QWidget;
	//InserWidget->setLayout(rightLayOut);
	//InserWidget->setStyleSheet("background-color:rgb(50, 50, 50);}");

	//����QDockWidget
	//QString name;
	//if (windowsIndex == 1)
		//name = QString::fromLocal8Bit("��ͷ��������");
	if (windowsIndex == 2)
		return;
		//name = QString::fromLocal8Bit("��β��������");

	//m_DockWidget = new QDockWidget();
	//m_DockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	//m_DockWidget->setWidget(InserWidget);
	//m_DockWidget->setStyleSheet("QDockWidget{ border: 2px solid black;background:rgb(32, 32, 32);color: white;font-size:12;}background:rgb(32, 32, 32);");
	//m_DockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	//m_DockWidget->setAllowedAreas(Qt::DockWidgetArea::BottomDockWidgetArea);

	//QVBoxLayout *rightLayOut1 = new QVBoxLayout;
	////rightLayOut1->addWidget(m_DataStatistic);
	////rightLayOut->addWidget(m_result_setting);
	////rightLayOut->addWidget(m_TimeStatistic);
	//rightLayOut1->addWidget(m_ResultListWidget);
	//QSpacerItem * sparcer_item1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
	//rightLayOut1->addItem(sparcer_item1);
	//rightLayOut1->setStretch(0, 1);
	//rightLayOut1->setStretch(1, 1);
	//rightLayOut1->setStretch(2, 4);
	//rightLayOut1->setContentsMargins(0, 0, 0, 0);
	//QWidget *InserWidget1 = new QWidget;
	//InserWidget1->setLayout(rightLayOut1);
	//InserWidget1->setStyleSheet("background-color:rgb(50, 50, 50);}");

	//m_DockWidget1 = new QDockWidget();
	//m_DockWidget1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	//m_DockWidget1->setWidget(InserWidget1);
	//m_DockWidget1->setStyleSheet("QDockWidget{ border: 2px solid black;background:rgb(32, 32, 32);color: white;font-size:12;}background:rgb(32, 32, 32);");
	//m_DockWidget1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	//m_DockWidget1->setAllowedAreas(Qt::DockWidgetArea::RightDockWidgetArea);
}

void MyStation::inintConnection()
{
	// ******************************* ͼ��Դ����źŰ� ***********************************
	// �ٻ�ȡ�����ͼ���źţ������㷨���������ͼƬ
	connect(m_ImageSource, &ImageSourceBase::ImageReady, this, &MyStation::GetCameraIamge);
	// �ڻ�ȡ���������״̬�ı��źţ�ͼ�񴰿ڵ����Ͻ����logo��ʽ�ı�
	connect(m_ImageSource, &ImageSourceBase::CameraStateChange, m_ImageWindow, &ImageWindow::SetCameraStateSlot);


	// ******************************* �б�����źŰ� ***********************************
	// �ٵ��������б��е�һ�У���ȡ��һ�е��ļ�·�������㷨����
	connect(m_TableWidget, &MyTableWidget::clicked, this, &MyStation::TableWidgetClickedSlot);


	// ******************************* �㷨����źŰ� *************************************
	// �ٷ��͸�ͼ�񴰿���ʾ
	connect(m_AlgoThread, &CAlgoThread::SendDetectionResult, m_ImageWindow, &ImageWindow::SetShowImageSlot);
	// �ڷ��͸�����б�����ʾ
	connect(m_AlgoThread, &CAlgoThread::SendResultToTable, m_TableWidget, &MyTableWidget::TableGetAlgoResult);
	// �۷��͸�ʱ��ͳ��
	connect(m_AlgoThread, &CAlgoThread::SendResultToTable, m_TimeStatistic, &TimeStatistics::GetAlgoResultSlot);
	// �ܷ��͸�����ͳ��
	connect(m_AlgoThread, &CAlgoThread::SendResultToTable, m_DataStatistic, &DataStatistics::GetAlgoResultSlot);
	// �ݷ��͸�����ͼ��
	connect(m_AlgoThread, &CAlgoThread::SendToSaveImg, this, &MyStation::SaveImageSlot);
	// �޷��͸����ڸ����㷨��ʼ�����
	connect(m_AlgoThread, &CAlgoThread::inintSuccessSiganl, m_ImageWindow, &ImageWindow::AlgoStatusChangleSlot);


	// ******************************* ͼ�񴰿�����źŰ� *************************************
	// �ٻ�ȡ���㷨�����ı䣬�޸�����ͳ�Ƶı�ǩ
	connect(m_ImageWindow, &ImageWindow::SendModelConfig, m_DataStatistic, &DataStatistics::GetModelChangeSlot);
	// �ڻ�ȡ���㷨�����ı䣬��ʼ���㷨��ģ��������ͳ��
	connect(m_ImageWindow, &ImageWindow::SendModelConfig, this, &MyStation::GetModelChangeSlot);
	// �ۻ�ȡ����ֵ����ȷ���¼�����ȡ��ֵ�������ֵ�������㷨��
	connect(m_ImageWindow, &ImageWindow::SendThreshold, this, &MyStation::GetThresholdAllParam);
	// �ܻ�ȡ���½������¼�
	connect(m_ImageWindow, &ImageWindow::AddWindowSignal, this, &MyStation::AddOneWindowSignals);
	// �ݻ�ȡ��ͼ��Դ�����ı��¼�
	connect(m_ImageWindow, &ImageWindow::ChangeImageSourceBase, this, [=](ImageSourceBase* inPtr) { m_ImageSource = inPtr; });
}

//��ȡ���㷨�����ı�Ĳۺ���
void MyStation::GetModelChangeSlot(ModelChoice ConfigParamter)
{
	//�㷨���ʼ��ģ��
	m_AlgoThread->InitModule(ConfigParamter); 
	if (ConfigParamter.modeType[ConfigParamter.modeType.size() - 1] == "OCR" || ConfigParamter.modeType[ConfigParamter.modeType.size() - 1] == "ocr")
	{
		isShowOkNg = false;
	}
	else
	{
		isShowOkNg = true;
	}
	//SetOkNgVisible(isShowOkNg);
	//����ͳ��
	//m_DataStatistic->ResetDataSlot();
	//m_TimeStatistic->ResetDataSlot();
}

//����б��е���ۺ�������ȡ��һ�е��ļ�·�������㷨����
void MyStation::TableWidgetClickedSlot(QModelIndex index)
{
	/*QObject* obj = sender();
	QTableWidget* TableWidgetPtr = dynamic_cast<QTableWidget*>(obj);*/
	int row = index.row();
	int nowRowsNum = m_TableWidget->rowCount();
	if (row >= m_TableWidget->rowCount()) return;
	QString ImagePath = m_TableWidget->item(row, 2)->text();
	if (ImagePath.size() == 0)
	{
		//QMessageBox::information(this, tr("Tips"), tr("ͼ��Ϊ��")); return;
	}
	//��ȡ�ļ���
	Mat m_OriginalImage = cv::imread(ImagePath.toLocal8Bit().toStdString(), -1);
	ThreadQueueInfos inData;
	inData.m_Image = m_OriginalImage;
	inData.TableIndex = row;
	inData.ImageName = ImagePath;
	m_AlgoThread->SetImage(inData);
}

//��ȡ�����ͼ��ۺ����������㷨���������ͼƬ
void MyStation::GetCameraIamge(cv::Mat GetImg)
{
	s_ImageInfo ImageInfo;
	ImageInfo.SavePath = tr("%1/CameraImage/Station%2/%3").arg(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr).arg(StationIndex).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
	ImageInfo.FileName = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss-zzz") + "." + ConfigProgramme::GetInstance()->m_CameraSave.SaveType;

	ThreadQueueInfos inData;
	inData.m_Image = GetImg;
	inData.TableIndex = m_TableWidget->rowCount() >= 200 ? 200 : m_TableWidget->rowCount();
	inData.ImageName = ImageInfo.SavePath + "/" + ImageInfo.FileName;
	if (m_AlgoThread->SetImage(inData)) //����ǰͼƬ�����㷨�̶߳���
	{
		m_TableWidget->GetCameraImage(GetImg, ImageInfo.SavePath + "/" + ImageInfo.FileName);
		//�������ͼƬ
		if (ConfigProgramme::GetInstance()->m_CameraSave.isSave)
		{
			ImageInfo.image = GetImg.clone();
			ImageInfo.isCameraImage = true;
			CSaveImage::GetInstance()->SetImageInfo(ImageInfo);
		}
	}
	else
	{
		qDebug() << QString::fromLocal8Bit("���л������������޶���������ͼ����");
	}
}

//��ȡ���㷨�����Ĳۺ������������ͼ����Ⱦͼ
void MyStation::SaveImageSlot(cv::Mat& OriginalImage, cv::Mat& RenderImage, bool bOK, QString tableText, int TableIndex,QString ImageFileName)
{
	if (ConfigProgramme::GetInstance()->m_RenderSave.isSave)
	{
		//������Ⱦͼ
		s_ImageInfo ImageInfo;
		if (isShowOkNg)
		{
			if (bOK)
			{
				ImageInfo.SavePath = tr("%1/RenderImage/%2/Station%3/%4/OK").arg(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr).arg(ConfigProgramme::GetInstance()->m_Selectprogramme).arg(StationIndex).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
			}
			else
			{
				ImageInfo.SavePath = tr("%1/RenderImage/%2/Station%3/%4/NG/%5").arg(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr).arg(ConfigProgramme::GetInstance()->m_Selectprogramme).arg(StationIndex).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd")).arg(tableText);
				if (m_ImageWindow->GetModelType() == OCR)
					ImageInfo.SavePath = tr("%1/RenderImage/%2/Station%3/%4/NG").arg(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr).arg(ConfigProgramme::GetInstance()->m_Selectprogramme).arg(StationIndex).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
			}
		}
		else
		{
			ImageInfo.SavePath = tr("%1/RenderImage/%2/Station%3/%4").arg(ConfigProgramme::GetInstance()->m_RenderSave.ImgPathStr).arg(ConfigProgramme::GetInstance()->m_Selectprogramme).arg(StationIndex).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
		}
		ImageInfo.isCameraImage = false;
		//��ȡͼƬ����
		QFileInfo fileinfo(ImageFileName);
		ImageInfo.FileName = fileinfo.baseName() + "." + ConfigProgramme::GetInstance()->m_RenderSave.SaveType;
		ImageInfo.image = RenderImage.clone();
		CSaveImage::GetInstance()->SetImageInfo(ImageInfo);
	}
}

//��ֵ�����ȷ����ť�ۺ���
void MyStation::GetThresholdAllParam()
{
	std::vector<AllThreshold> insertThreshold = m_ImageWindow->m_ThresholdSetDialg->GetThresholdAllParam(); //����ֵ�����ȡ��ǰ��ֵ
	m_AlgoThread->SetThreshold(insertThreshold);  //���㷨��������ֵ
	m_TimeStatistic->SetTimeExplain(m_ImageWindow->m_ThresholdSetDialg->GetTimeValue()); //��ʱ��ͳ�����ó�ʱ��ֵ
	m_TableWidget->TimeThreshold = m_ImageWindow->m_ThresholdSetDialg->GetTimeValue();   //�����б����ó�ʱ��ֵ

	//������ģ����OCR�㷨ʱ�ж��Ƿ���ƥ���ַ�����û��ƥ���ַ��������Ok/Ng
	if (insertThreshold.size() != 0)
	{
		if (insertThreshold[insertThreshold.size() - 1]._PostParam._ocrThreshold.SdkThreshold.size() != 0)
		{
			if (insertThreshold[insertThreshold.size() - 1]._PostParam._ocrThreshold.MatchStrVec.size() != 0)
				SetOkNgVisible(true);
			else
				SetOkNgVisible(false);
		}
	}

	ConfigProgramme::GetInstance()->AllConfig[StationIndex - 1].m_Threshold = insertThreshold;
	ConfigProgramme::GetInstance()->AllConfig[StationIndex - 1].m_TimeThreshold = m_ImageWindow->m_ThresholdSetDialg->GetTimeThreshold();
}

//�ӷ������û�ԭͼ��Դ����
void MyStation::LoadImageSourceFromConfig(WindowsConfig inConfig)
{
	if (m_ImageSource != nullptr) delete m_ImageSource;

	if (inConfig.m_ImageSourceConfig.ImageSource_isCamera) //��ǰͼ��Դ�����
	{
		m_ImageSource = new ImageSourceCamera;
	}
	else //��ǰͼ��Դ�Ǳ���ͼƬ�ļ���
	{
		m_ImageSource = new ImageSourceFile;
	}
	// �ٻ�ȡ�����ͼ���źţ������㷨���������ͼƬ
	bool isOks = connect(m_ImageSource, &ImageSourceBase::ImageReady, this, &MyStation::GetCameraIamge);
	// �ڻ�ȡ���������״̬�ı��źţ�ͼ�񴰿ڵ����Ͻ����logo��ʽ�ı�
	bool isOks2 = connect(m_ImageSource, &ImageSourceBase::CameraStateChange, m_ImageWindow, &ImageWindow::SetCameraStateSlot);

	m_ImageSource->SetMyPtr(this);
	m_ImageSource->InintFromConfig(inConfig.m_ImageSourceConfig);
	m_ImageWindow->SetImageSourcePtr(m_ImageSource); //���¸�ͼ�񴰿�����ָ��

	//���㷨�̸߳�ֵ
	m_AlgoThread->SetThreshold(inConfig.m_Threshold);
}

//��ǰ���ð�ť�Ƿ�ɵ��(�����в�����������)��DynamicWidget�е���
void MyStation::WorkStateChange(bool isWork)
{
	//m_TimeStatistic->WorkStateChange(isWork);
	m_ResultListWidget->WorkStateChange(isWork);
	//->WorkStateChange(isWork);
}

//��DynamicWidget������״̬����ָ�봫��ͼ�񴰿�
void MyStation::SetRunningStateChange(std::function<bool(void)> inStatePtr)
{
	m_ImageWindow->SetSoftRunningStatePtr(inStatePtr);
}

//���õ�ǰ�����Ƿ����Ok/Ng
void MyStation::SetOkNgVisible(bool isShow)
{
	isShowOkNg = isShow;
	m_DataStatistic->SetOkNgShow(isShow);
}