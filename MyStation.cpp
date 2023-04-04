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

// 退出算法线程
void MyStation::CloseAlgo()
{
	if (m_AlgoThread->bStart == true)
	{
		// 如果当前算法正在初始化中，等初始化完成再销毁
		if (m_AlgoThread->IsInintDone() == false)
		{
			WaittingDialog* m_WaittingDialog = new WaittingDialog(tr("Pipeline initializing... Window will be deleted when initialization completed"));
			m_WaittingDialog->show();
			//等待中
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
		//需要先往队列压入一个结束数据，即压入长宽为0的图像，消费者线程会continue,后因bStart为false自动退出线程
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
	//待修改 if (m_ResultListWidget != NULL) delete m_ResultListWidget; m_ResultListWidget = nullptr;
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
	//算法类初始化模型
	if (m_AlgoThread->InitModule(ConfigParamter))
	{
		QString msg;
		if (windowsIndex == 0)
			msg = QString::fromLocal8Bit("机头OCR初始化成功");
		else if(windowsIndex == 1)
			msg = QString::fromLocal8Bit("机尾OCR初始化成功");
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

	//启动存图线程
	if (CSaveImage::GetInstance()->isRunning() == false)
		CSaveImage::GetInstance()->start();

	//创建结果列表控件
	m_TableWidget = new MyTableWidget(&isShowOkNg, NULL);
	m_ResultListWidget = new ResultsListWidget(m_TableWidget);

	//创建数据统计
	//m_DataStatistic = new DataStatistics;

	//创建耗时统计
	//m_TimeStatistic = new TimeStatistics;
	//m_result_setting = new ResultSetting(windowsIndex);
	//创建算法线程并启动
	m_AlgoThread = new CAlgoThread(&StationIndex);
	m_AlgoThread->start();
	m_AlgoThread->bStart = true;

	//创建图像源(默认指向相机源)
	m_ImageSource = new ImageSourceCamera;
	m_ImageSource->SetMyPtr(this);
	auto camera_setting = dynamic_cast<ImageSourceCamera *>(m_ImageSource);
	//Camera *camera_station = camera_setting->getCameraPtr();
	camera_setting->initCamera(windowsIndex);

	//创建图像窗口
	m_ImageWindow = new ImageWindow(&StationIndex, &isShowOkNg);
	m_ImageWindow->SetImageSourcePtr(m_ImageSource);              //传入当前图像源类对象
	std::function<std::vector<AllThreshold>(void)> algoThreadPtr = std::bind(&CAlgoThread::GetThresholdValue, m_AlgoThread); //从算法获取阈值的函数指针
	std::function<std::vector<ViMoModelInfo>(void)> algoInfoPtr = std::bind(&CAlgoThread::GetAlogInfo, m_AlgoThread);        //从算法获取模型信息的函数指针
	m_ImageWindow->SetAlgoThreadCallBackPtr(algoThreadPtr, algoInfoPtr);   //将函数指针传入图像窗口

	////创建QDockWidget的Widget
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

	//创建QDockWidget
	//QString name;
	//if (windowsIndex == 1)
		//name = QString::fromLocal8Bit("线头参数设置");
	if (windowsIndex == 2)
		return;
		//name = QString::fromLocal8Bit("线尾参数设置");

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
	// ******************************* 图像源类的信号绑定 ***********************************
	// ①获取到相机图像信号，插入算法并保存相机图片
	connect(m_ImageSource, &ImageSourceBase::ImageReady, this, &MyStation::GetCameraIamge);
	// ②获取到相机连接状态改变信号，图像窗口的右上角相机logo样式改变
	connect(m_ImageSource, &ImageSourceBase::CameraStateChange, m_ImageWindow, &ImageWindow::SetCameraStateSlot);


	// ******************************* 列表类的信号绑定 ***********************************
	// ①当触发了列表中的一行，读取这一行的文件路径送入算法队列
	connect(m_TableWidget, &MyTableWidget::clicked, this, &MyStation::TableWidgetClickedSlot);


	// ******************************* 算法类的信号绑定 *************************************
	// ①发送给图像窗口显示
	connect(m_AlgoThread, &CAlgoThread::SendDetectionResult, m_ImageWindow, &ImageWindow::SetShowImageSlot);
	// ②发送给结果列表窗口显示
	connect(m_AlgoThread, &CAlgoThread::SendResultToTable, m_TableWidget, &MyTableWidget::TableGetAlgoResult);
	// ③发送给时间统计
	connect(m_AlgoThread, &CAlgoThread::SendResultToTable, m_TimeStatistic, &TimeStatistics::GetAlgoResultSlot);
	// ④发送给数据统计
	connect(m_AlgoThread, &CAlgoThread::SendResultToTable, m_DataStatistic, &DataStatistics::GetAlgoResultSlot);
	// ⑤发送给保存图像
	connect(m_AlgoThread, &CAlgoThread::SendToSaveImg, this, &MyStation::SaveImageSlot);
	// ⑥发送给窗口更新算法初始化结果
	connect(m_AlgoThread, &CAlgoThread::inintSuccessSiganl, m_ImageWindow, &ImageWindow::AlgoStatusChangleSlot);


	// ******************************* 图像窗口类的信号绑定 *************************************
	// ①获取到算法方案改变，修改数据统计的标签
	connect(m_ImageWindow, &ImageWindow::SendModelConfig, m_DataStatistic, &DataStatistics::GetModelChangeSlot);
	// ②获取到算法方案改变，初始化算法类模型与重置统计
	connect(m_ImageWindow, &ImageWindow::SendModelConfig, this, &MyStation::GetModelChangeSlot);
	// ③获取到阈值界面确定事件，获取阈值界面的阈值并传入算法类
	connect(m_ImageWindow, &ImageWindow::SendThreshold, this, &MyStation::GetThresholdAllParam);
	// ④获取到新建窗口事件
	connect(m_ImageWindow, &ImageWindow::AddWindowSignal, this, &MyStation::AddOneWindowSignals);
	// ⑤获取到图像源类对象改变事件
	connect(m_ImageWindow, &ImageWindow::ChangeImageSourceBase, this, [=](ImageSourceBase* inPtr) { m_ImageSource = inPtr; });
}

//获取到算法方案改变的槽函数
void MyStation::GetModelChangeSlot(ModelChoice ConfigParamter)
{
	//算法类初始化模型
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
	//重置统计
	//m_DataStatistic->ResetDataSlot();
	//m_TimeStatistic->ResetDataSlot();
}

//结果列表行点击槽函数，读取这一行的文件路径送入算法队列
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
		//QMessageBox::information(this, tr("Tips"), tr("图像为空")); return;
	}
	//获取文件名
	Mat m_OriginalImage = cv::imread(ImagePath.toLocal8Bit().toStdString(), -1);
	ThreadQueueInfos inData;
	inData.m_Image = m_OriginalImage;
	inData.TableIndex = row;
	inData.ImageName = ImagePath;
	m_AlgoThread->SetImage(inData);
}

//获取到相机图像槽函数，插入算法并保存相机图片
void MyStation::GetCameraIamge(cv::Mat GetImg)
{
	s_ImageInfo ImageInfo;
	ImageInfo.SavePath = tr("%1/CameraImage/Station%2/%3").arg(ConfigProgramme::GetInstance()->m_CameraSave.ImgPathStr).arg(StationIndex).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
	ImageInfo.FileName = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss-zzz") + "." + ConfigProgramme::GetInstance()->m_CameraSave.SaveType;

	ThreadQueueInfos inData;
	inData.m_Image = GetImg;
	inData.TableIndex = m_TableWidget->rowCount() >= 200 ? 200 : m_TableWidget->rowCount();
	inData.ImageName = ImageInfo.SavePath + "/" + ImageInfo.FileName;
	if (m_AlgoThread->SetImage(inData)) //将当前图片插入算法线程队列
	{
		m_TableWidget->GetCameraImage(GetImg, ImageInfo.SavePath + "/" + ImageInfo.FileName);
		//保存相机图片
		if (ConfigProgramme::GetInstance()->m_CameraSave.isSave)
		{
			ImageInfo.image = GetImg.clone();
			ImageInfo.isCameraImage = true;
			CSaveImage::GetInstance()->SetImageInfo(ImageInfo);
		}
	}
	else
	{
		qDebug() << QString::fromLocal8Bit("队列缓存数量大于限定个数，此图丢弃");
	}
}

//获取到算法类结果的槽函数，保存相机图与渲染图
void MyStation::SaveImageSlot(cv::Mat& OriginalImage, cv::Mat& RenderImage, bool bOK, QString tableText, int TableIndex,QString ImageFileName)
{
	if (ConfigProgramme::GetInstance()->m_RenderSave.isSave)
	{
		//保存渲染图
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
		//获取图片名字
		QFileInfo fileinfo(ImageFileName);
		ImageInfo.FileName = fileinfo.baseName() + "." + ConfigProgramme::GetInstance()->m_RenderSave.SaveType;
		ImageInfo.image = RenderImage.clone();
		CSaveImage::GetInstance()->SetImageInfo(ImageInfo);
	}
}

//阈值界面的确定按钮槽函数
void MyStation::GetThresholdAllParam()
{
	std::vector<AllThreshold> insertThreshold = m_ImageWindow->m_ThresholdSetDialg->GetThresholdAllParam(); //从阈值界面获取当前阈值
	m_AlgoThread->SetThreshold(insertThreshold);  //向算法类设置阈值
	m_TimeStatistic->SetTimeExplain(m_ImageWindow->m_ThresholdSetDialg->GetTimeValue()); //向时间统计设置超时阈值
	m_TableWidget->TimeThreshold = m_ImageWindow->m_ThresholdSetDialg->GetTimeValue();   //向结果列表设置超时阈值

	//当后置模块是OCR算法时判断是否有匹配字符串，没有匹配字符串则不输出Ok/Ng
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

//从方案配置还原图像源对象
void MyStation::LoadImageSourceFromConfig(WindowsConfig inConfig)
{
	if (m_ImageSource != nullptr) delete m_ImageSource;

	if (inConfig.m_ImageSourceConfig.ImageSource_isCamera) //当前图像源是相机
	{
		m_ImageSource = new ImageSourceCamera;
	}
	else //当前图像源是本地图片文件夹
	{
		m_ImageSource = new ImageSourceFile;
	}
	// ①获取到相机图像信号，插入算法并保存相机图片
	bool isOks = connect(m_ImageSource, &ImageSourceBase::ImageReady, this, &MyStation::GetCameraIamge);
	// ②获取到相机连接状态改变信号，图像窗口的右上角相机logo样式改变
	bool isOks2 = connect(m_ImageSource, &ImageSourceBase::CameraStateChange, m_ImageWindow, &ImageWindow::SetCameraStateSlot);

	m_ImageSource->SetMyPtr(this);
	m_ImageSource->InintFromConfig(inConfig.m_ImageSourceConfig);
	m_ImageWindow->SetImageSourcePtr(m_ImageSource); //重新给图像窗口设置指针

	//给算法线程赋值
	m_AlgoThread->SetThreshold(inConfig.m_Threshold);
}

//当前重置按钮是否可点击(运行中不允许点击重置)，DynamicWidget中调用
void MyStation::WorkStateChange(bool isWork)
{
	//m_TimeStatistic->WorkStateChange(isWork);
	m_ResultListWidget->WorkStateChange(isWork);
	//->WorkStateChange(isWork);
}

//将DynamicWidget的运行状态函数指针传入图像窗口
void MyStation::SetRunningStateChange(std::function<bool(void)> inStatePtr)
{
	m_ImageWindow->SetSoftRunningStatePtr(inStatePtr);
}

//设置当前窗口是否输出Ok/Ng
void MyStation::SetOkNgVisible(bool isShow)
{
	isShowOkNg = isShow;
	m_DataStatistic->SetOkNgShow(isShow);
}