#include "DynamicWidget.h"
#include "components/Config/ConfigProgramme.h"
#include "UI/Performance/PerformanceMonitorTitle.h"
#include "ImageSouceBase.h"
#include "components/Camera/SoftTriggerConnect.h"
#include "UI/MyDialog/WaittingDialog.h"
#include "PublicParamter.h"
#include <QSplitter>
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	static QMutex mutex;
	mutex.lock();

	QString text;
	switch (type)
	{
	case QtDebugMsg:
		text = QString("Debug:");
		break;

	case QtWarningMsg:
		text = QString("Warning:");
		break;

	case QtCriticalMsg:
		text = QString("Critical:");
		break;

	case QtFatalMsg:
		text = QString("Fatal:");
	}

	QString context_info = QString("File:(%1) Line:(%2)").arg(QString::fromLocal8Bit(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ddd");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1          %2 %3 %4").arg(current_date).arg(text).arg(context_info).arg(msg);
	QString LogPath = QCoreApplication::applicationDirPath();
	LogPath.append("/log");
	QDir dir(LogPath);
	if (!dir.exists(LogPath))
	{
		dir.mkdir(LogPath);
	}
	QString logFile = LogPath + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd");
	logFile.append(".txt");
	QFile file(logFile);
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();

	mutex.unlock();
}
DynamicWidget *DynamicWidget::m_Instance = nullptr;
DynamicWidget *DynamicWidget::GetInstance()
{
	return m_Instance;
}

DynamicWidget::DynamicWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_Instance = this;
	qInstallMessageHandler(outputMessage);
	inintTitteBar();
	InintWindow();	
	InintConnection();
	InintParameter();
	guoxuan::get_instance().initStart();
	sqliteSetting::GetInstance();
	LoadParameter();
	//guoxuan::get_instance();
	//等构造函数执行完加载方案(构造函数没结束就加载方案重新布局页面会导致有些样式设置不成功) 
	QTimer *m_delay = new QTimer(this); m_delay->start(10);
	connect(m_delay, &QTimer::timeout, this, [=]() { LoadProgramme(ConfigProgramme::GetInstance()->LoadWhichPro()); m_delay->stop(); delete m_delay; });
	ActionStartWorkSlot();
}

DynamicWidget::~DynamicWidget()
{
	CSaveImage::GetInstance()->StopThread();
}

void DynamicWidget::inintTitteBar()
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	ui.toolBar_TitleBar->initControl({ LogoImage ,SoftName ,SoftInfo ,MinBUTTON ,MaxBUTTON ,RestoreBUTTON ,CloseBUTTON });
	connect(ui.toolBar_TitleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
	connect(ui.toolBar_TitleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
	connect(ui.toolBar_TitleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
	connect(ui.toolBar_TitleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

	ui.toolBar_TitleBar->setMovable(false);
	ui.toolBar_Tool->setMovable(false);
}

void DynamicWidget::InintWindow()
{
	//设置CMD不弹窗显示(GPU性能监视通过CMD交互，界面会每隔时间段闪出控制台 -- 通过申请一个控制台并且屏蔽次控制台以解决)
	//AllocConsole();
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	//设置主窗口样式，选项卡样式，悬浮窗口分割线样式
	this->setStyleSheet("QWidget{background-color:rgb(50,50,50);}QTabBar{background-color:rgb(65,65,65);}"
		"QTabBar:tab { min-height:20px;min-width:60px; font-size: 10pt; color: white; border: 2px solid #000000;  background-color: rgb(60,60,60);}"
		"QTabBar::tab:selected{min-height:20px;min-width:60px; font-size: 10pt; color: white; border: 2px solid #000000;background-color: rgb(30,30,30);}"
		"QMainWindow::separator{ width: 0px;height: 0px;margin: 0px;padding: 0px; background-color: rgb(32,32,32); }"); 

	//如果有GPU->添加GPU性能监视DockWidget
	//std::vector<GpuInfos> m_GpuNums = GetResultFromCMD();
	//if (m_GpuNums.size() != 0)
	//{
	//	GpuMinoitorDock = new QDockWidget(tr("GPU Performance Monitoring"), ui.MyWindowWidget);
	//	/*GpuMinoitorDock->setMaximumWidth(450);
	//	GpuMinoitorDock->setMaximumHeight(160);*/
	//	GpuMinoitorDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable); //去掉关闭按钮
	//	addDockWidget(Qt::RightDockWidgetArea, GpuMinoitorDock);
	//	GpuMonitor *m_GpuMonitor = new GpuMonitor(this);
	//	// 更新性能监视窗口高度的槽函数：根据GPU数量动态调整浮动窗口的高度，30是标题栏高度+现在高度
	//	connect(m_GpuMonitor, &GpuMonitor::SetWidgetHeightSignal, this, [=](int nowHeight) { GpuMinoitorDock->setMaximumHeight(30 + nowHeight); GpuMinoitorDock->update(); });
	//	//必须在外面套一层QWidget才能使得QDockWidget铺满控件
	//	QVBoxLayout *m_V3 = new QVBoxLayout;
	//	m_V3->addWidget(m_GpuMonitor);
	//	m_V3->setContentsMargins(0, 0, 0, 0);
	//	QWidget *InserWidget2 = new QWidget;
	//	InserWidget2->setLayout(m_V3);
	//	InserWidget2->setStyleSheet("color:white;background-color:rgb(50, 50, 50);}");
	//	GpuMinoitorDock->setWidget(InserWidget2);
	//	GpuMinoitorDock->setAutoFillBackground(true);
	//	GpuMinoitorDock->setStyleSheet("QDockWidget{ margin: 0px;padding: 0px;color: white; background: rgb(32, 32, 32);}"); //QDockWidget之间的间距调整
	//	QFont curFont = GpuMinoitorDock->font();
	//	curFont.setPointSize(11);  //curFont.setBold(true);
	//	GpuMinoitorDock->setFont(curFont);
	//	//重设浮动窗口的标题
	//	QWidget *oldTitalbar = GpuMinoitorDock->titleBarWidget();
	//	PerformanceMonitorTitle *newTitalbar = new PerformanceMonitorTitle(GpuMinoitorDock, this);
	//	GpuMinoitorDock->setTitleBarWidget(newTitalbar);
	//	//删除原有的标题栏
	//	delete oldTitalbar;
	//}

	//设置软件的最大尺寸
	/*QRect desktopRect = QApplication::desktop()->availableGeometry();
	this->setMaximumHeight(desktopRect.height());
	this->setMaximumWidth(desktopRect.width() - 450);*/

	//QSplitter *splitter = new QSplitter();
	//splitter->addWidget(ui.MyWindowWidget);
	//splitter->addWidget(GpuMinoitorDock);

		//创建QDockWidget的Widget
	m_result_setting = new ResultSetting;
	QVBoxLayout *rightLayOut = new QVBoxLayout;
	//rightLayOut->addWidget(m_DataStatistic);
	rightLayOut->addWidget(m_result_setting);
	//rightLayOut->addWidget(m_TimeStatistic);
	//rightLayOut->addWidget(m_ResultListWidget);
	QSpacerItem * sparcer_item = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);
	rightLayOut->addItem(sparcer_item);
	rightLayOut->setStretch(0, 1);
	rightLayOut->setStretch(1, 1);
	rightLayOut->setStretch(2, 4);
	rightLayOut->setContentsMargins(1, 1, 1, 1);
	QWidget *InserWidget = new QWidget;
	InserWidget->setLayout(rightLayOut);
	InserWidget->setStyleSheet("background-color:rgb(50, 50, 50);}");
	m_DockWidget = new QDockWidget();
	m_DockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	m_DockWidget->setWidget(InserWidget);
	m_DockWidget->setStyleSheet("QDockWidget{ border: 2px solid black;background:rgb(32, 32, 32);color: white;font-size:12;}background:rgb(32, 32, 32);");
	m_DockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	m_DockWidget->setAllowedAreas(Qt::DockWidgetArea::BottomDockWidgetArea);

	QVBoxLayout *rightLayOut1 = new QVBoxLayout;
	m_listView=new QListView;
	m_listView->setStyleSheet("color: white;font-size:12;");
	rightLayOut1->addWidget(m_listView,1);
	QSpacerItem * sparcer_item1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
	rightLayOut1->addItem(sparcer_item1);
	QWidget *InserWidget1 = new QWidget;
	InserWidget1->setLayout(rightLayOut1);
	InserWidget1->setStyleSheet("background-color:rgb(50, 50, 50);}");

	m_DockWidget1 = new QDockWidget(QString::fromLocal8Bit("日志信息"));
	m_DockWidget1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	m_DockWidget1->setWidget(InserWidget1);
	m_DockWidget1->setStyleSheet("QDockWidget{ border: 2px solid black;background:rgb(32, 32, 32);color: white;font-size:12;}background:rgb(32, 32, 32);");
	m_DockWidget1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	m_DockWidget1->setAllowedAreas(Qt::DockWidgetArea::RightDockWidgetArea);

	addDockWidget(Qt::RightDockWidgetArea, m_DockWidget1);
	addDockWidget(Qt::BottomDockWidgetArea, m_DockWidget);
	setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
	m_LogModel = new QStandardItemModel();
	m_listView->setModel(m_LogModel);
}

void DynamicWidget::InintParameter()
{
	qRegisterMetaType<cv::Mat>("cv::Mat");
	qRegisterMetaType<cv::Mat>("cv::Mat&");
	qRegisterMetaType<Mat>("Mat");
	qRegisterMetaType<ModelChoice>("ModelChoice");
	qRegisterMetaType<std::vector<ThresholdParams>>("std::vector<ThresholdParams>");
	qRegisterMetaType<std::vector<RenderShowParams>>("std::vector<RenderShowParams>");
	qRegisterMetaType<CameraInfoConfig>("CameraInfoConfig");
	qRegisterMetaType<ImageSourceBase*>("ImageSourceBase*");

	// 图像窗口栅格布局
	m_ImagesWindow = new QGridLayout();
	// 关联Qt设计师中的Widget内容->设置其内容为m_ImagesWindow(图像窗口栅格布局)
	QVBoxLayout *layouts = new QVBoxLayout(this);
	layouts->addLayout(m_ImagesWindow);
	layouts->setContentsMargins(0, 0, 0, 0);
	ui.MyWindowWidget->setLayout(layouts); 
	// windowsNums默认为1：即初始化一个工位
	for (int i = 1; i <= windowsNums; i++)
	{
		AddOneStation(i);
		connect(m_Station[i - 1], &MyStation::sendLog, this, [=](QString log) {ShowLog(log); });
		connect(m_Station[i - 1]->m_AlgoThread, &CAlgoThread::sendLog, this, [=](QString log) {ShowLog(log); });
		m_Station[i-1]->initAlgo(i-1);
	}

}

void DynamicWidget::InintConnection()
{
	connect(ui.toolBar_Tool, &MyToolBar::ContinueGrabSignal, this, &DynamicWidget::ActionStartWorkSlot);
	connect(ui.toolBar_Tool, &MyToolBar::StopGrabSignal, this, &DynamicWidget::ActionStopWorkSlot);
	connect(ui.toolBar_Tool, &MyToolBar::OpenSettingSignal, this, &DynamicWidget::Action_SystemSetSlot);
	connect(ui.toolBar_Tool, &MyToolBar::SingleGrabSignal, this, &DynamicWidget::Action_SingleGrab);
	connect(ui.toolBar_Tool, &MyToolBar::OpenSqlDataSignal, this, &DynamicWidget::Action_SqlDataSlot);
	//将设置软件运行状态的函数指针赋值给软触发连接类，用于通讯断开时自动停止工作
	SoftTriggerConnect::GetInstance()->WorkStateChangePtr = std::bind(&DynamicWidget::SetRuningState, this, std::placeholders::_1);
	connect(&guoxuan::get_instance(), &guoxuan::sendLog, this, [=](QString msg) {ShowLog(msg); });
}

void DynamicWidget::ShowLog(QString log)
{
	int rows = m_LogModel->rowCount();
	if (rows > 1000)
	{
		m_LogModel->removeRows(0, rows);
	}
	QString CurTime = QDateTime::currentDateTime().toString("hh-mm-ss-zzz");
	m_LogModel->insertRow(0, new QStandardItem(CurTime + "  " + log));
}

void DynamicWidget::LoadParameter()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/parametercfg.ini";
	CConfig *cfg = new CConfig(IniPath);
	QString head_direction = cfg->GetString(DIRECTION, HEAD);
	QString end_direction = cfg->GetString(DIRECTION, END);
	guoxuan::get_instance().set_head_type_direction(head_direction);
	guoxuan::get_instance().set_end_type_direction(end_direction);


	CFGDATA head,end;
	head.Alignment = cfg->GetDouble(HEADSETTING, HEADALIGNMENT);
	head.Change = cfg->GetDouble(HEADSETTING, HEADCHANGE);
	head.WarningLeft = cfg->GetDouble(HEADSETTING, HEADWARNINGLEFT);
	head.WarningMiddle = cfg->GetDouble(HEADSETTING, HEADWARNINGMIDDLE);
	head.WarningRight = cfg->GetDouble(HEADSETTING, HEADWARNINGRIGHT);

	end.type= cfg->GetInt(ENDSETTING, ENDTYPE);
	end.AlignmentLeft = cfg->GetDouble(ENDSETTING, ENDALIGNMENTLEFT);
	end.AlignmentMiddle = cfg->GetDouble(ENDSETTING, ENDALIGNMENTMIDDLE);
	end.AlignmentRight = cfg->GetDouble(ENDSETTING, ENDALIGNMENTRIGHT);

	end.ChangeLeft = cfg->GetDouble(ENDSETTING, ENDCHANGELEFT);
	end.ChangeRight = cfg->GetDouble(ENDSETTING, ENDCHANGERIGHT);

	end.WarningMiddle = cfg->GetDouble(ENDSETTING, ENDWARNINGMIDDLE);
	guoxuan::get_instance().set_head_data(head);
	guoxuan::get_instance().set_end_data(end);
	m_result_setting->initShow();
}


//点击了连续运行按钮响应的槽函数
void DynamicWidget::ActionStartWorkSlot()
{
	//判断算法是否都初始化成功
	if (JudgeAlgoInintState() == false)
	{
		QMessageBox::information(nullptr, tr("tips"), tr("Algorithm waiting timeout"));
		return;
	}
	
	//判断当前是否有图像源
	bool haveImageFlag = true; QString errorMessage;
	for (int i = 0; i < m_Station.size(); i++)
	{
		if (m_Station[i]->m_ImageSource->isCanStart() == false)
		{
			haveImageFlag = false;
			errorMessage = errorMessage + tr("Please set image source for Window %1\n").arg(i + 1);
		}
	}
	if (haveImageFlag == false) //如果有窗口没设置图像源，则启动失败
	{
		errorMessage = errorMessage + tr("Stating failed");
		QMessageBox::information(nullptr, tr("Tips"), errorMessage);
		return;
	}
	//调用图像源连续运行接口，开始获取图像接口
	bool isFileSource = false;
	for (int i = 0; i < m_Station.size(); i++)
	{
		m_Station[i]->m_ImageSource->Start();
		if (m_Station[i]->m_ImageSource->isCameraSource()==false)
		{
			isFileSource = true;
		}
	}

	//UI显示运行中
	SetRunningState(isWorking); 

	//如果图像源是图片文件夹,开启定时器监视算法运行状态
	if (isFileSource)
	{
		QTimer *m_WatchOnAlgo = new QTimer(this); m_WatchOnAlgo->start(600);
		connect(m_WatchOnAlgo, &QTimer::timeout, this, &DynamicWidget::TimerWatchOnAlgoStop);
	}
	else 
	{
		SoftTriggerConnect::GetInstance()->isCameraConnectAlgo = true;
	}
}

//点击单步执行按钮
void DynamicWidget::Action_SingleGrab()
{
	//判断算法是否都初始化成功
	if (JudgeAlgoInintState() == false)
	{
		QMessageBox::information(nullptr, tr("tips"), tr("Algorithm waiting timeout"));
		return;
	}

	//判断当前是否有图像源
	bool haveImageFlag = true; QString errorMessage; 
	for (int i = 0; i < m_Station.size(); i++)
	{
		if (m_Station[i]->m_ImageSource->isCanStart() == false)
		{
			haveImageFlag = false;
			errorMessage = errorMessage + tr("Please set image source for Window %1\n").arg(i + 1);
		}
	}
	if (haveImageFlag == false) //如果有窗口没设置图像源，则启动失败
	{
		errorMessage = errorMessage + tr("Stating failed");
		QMessageBox::information(nullptr, tr("Tips"), errorMessage);
		return;
	}


	//调用图像源单步执行接口
	for (int i = 0; i < m_Station.size(); i++)
	{
		m_Station[i]->m_ImageSource->SingleGrab();
	}
	//UI显示运行中
	SetRunningState(isWorking); 

	//开启定时器监视算法运行状态
	QTimer *m_WatchOnAlgo = new QTimer(this); m_WatchOnAlgo->start(600);
	connect(m_WatchOnAlgo, &QTimer::timeout, this, &DynamicWidget::TimerWatchOnAlgoStop);
}

//点击停止工作按钮
void DynamicWidget::ActionStopWorkSlot()
{
	for (int i = 0; i < m_Station.size(); i++)
	{
		m_Station[i]->m_ImageSource->Stop();
	}
	SetRunningState(isWaitting);
	QTimer *m_WatchOnAlgo = new QTimer(this); m_WatchOnAlgo->start(600);
	connect(m_WatchOnAlgo, &QTimer::timeout, this, &DynamicWidget::TimerWatchOnAlgoStop);
	SoftTriggerConnect::GetInstance()->isCameraConnectAlgo = false;
}

// 点击系统设置按钮响应的槽函数
void DynamicWidget::Action_SystemSetSlot()
{
	SoftSetting *m_TempPtr = new SoftSetting;
	connect(m_TempPtr, &SoftSetting::CreateNewProSingal, this, &DynamicWidget::ReSetWindowSlot);  //新建方案信号::重置当前所有窗口
	connect(m_TempPtr, &SoftSetting::ChangleNewProSingal, this, &DynamicWidget::LoadProgramme);   //切换方案信号::重新加载方案改变窗口
	//m_TempPtr->setAttribute(Qt::WA_DeleteOnClose, true);//窗口关闭时自动销毁
	m_TempPtr->setAttribute(Qt::WA_ShowModal, true);
	m_TempPtr->show();
}

void DynamicWidget::Action_SqlDataSlot()
{
	DataManager *m_sqlData = new DataManager;
	m_sqlData->setAttribute(Qt::WA_DeleteOnClose, true);//窗口关闭时自动销毁
	m_sqlData->setAttribute(Qt::WA_ShowModal, true);
	m_sqlData->show();
}

// 获取所有工位的算法是否都初始化成功(点击运行按钮时需要判断)
bool DynamicWidget::JudgeAlgoInintState()
{
	bool isAlogInint = true;
	for (auto m_OneStation : m_Station)
	{
		if (m_OneStation->m_AlgoThread->IsInintDone() == false) isAlogInint = false;
	}
	// 如果当前有一个工位没有初始化成功
	if (isAlogInint == false)
	{
		//创建等待对话框
		WaittingDialog* m_WaittingDialog = new WaittingDialog(tr("Wait for algorithm initialization"));
		m_WaittingDialog->show();
		while (true)
		{
			bool isAlogInintDone = true;
			for (auto m_OneStation : m_Station)
			{
				if (m_OneStation->m_AlgoThread->IsInintDone() == false) isAlogInintDone = false;
			}
			if (isAlogInintDone)
			{
				delete m_WaittingDialog;
				break;
			}
			QCoreApplication::processEvents();
			Sleep(50);
		}
	}
	return true;
}

//在窗口右键点击新建窗口按钮响应的槽函数
void DynamicWidget::AddWindowSlot()
{
	if (windowsNums >= 9)
	{
		QMessageBox::information(NULL, tr("Tips"), tr("The number of windows has reached upper limit!"));
		return;
	}
	windowsNums++;
	int windosCols = (int)(sqrt(windowsNums) * 10) % 10 == 0 ? sqrt(windowsNums) : sqrt(windowsNums) + 1;

	for (int i = 0; i < windowsNums-1; i++)
	{
		m_ImagesWindow->addWidget(m_Station[i]->m_ImageWindow, (i) / windosCols, (i) % windosCols);
	}
	AddOneStation(windowsNums);
}
// 新增工位
void DynamicWidget::AddOneStation(int index, bool bInint)
{
	if (bInint == false)
		ConfigProgramme::GetInstance()->AllConfig.resize(index);

	//添加新控件时需要重新布局
	int windosCols = (int)(sqrt(windowsNums) * 10) % 10 == 0 ? sqrt(windowsNums) : sqrt(windowsNums) + 1;
	if (windosCols <= 0) windosCols = 1;
	MyStation* m_TempStation = new MyStation(index, NULL);
	std::function<bool(void)> m_RuningStateCallBack = std::bind(&DynamicWidget::isRunning, this);
	m_TempStation->SetRunningStateChange(m_RuningStateCallBack);
	m_Station.push_back(m_TempStation);

	m_ImagesWindow->addWidget(m_TempStation->m_ImageWindow, (index-1) / windosCols, (index-1) % windosCols);

	if (windowsNums>=5)
	{
		QRect desktopRect = QApplication::desktop()->availableGeometry();
		this->resize(desktopRect.width() - 50, desktopRect.height() - 25);
	}

	//addDockWidget(Qt::RightDockWidgetArea, m_TempStation->m_DockWidget);
	//if (index != 1)
		//tabifyDockWidget(m_Station[index - 1 - 1]->m_DockWidget, m_Station[index - 1]->m_DockWidget);
	//if (index == 1)
	//{
		//addDockWidget(Qt::RightDockWidgetArea, m_DockWidget1);
		//addDockWidget(Qt::BottomDockWidgetArea, m_DockWidget);
		//setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
		
		//if (GpuMinoitorDock != nullptr)
			//splitDockWidget(m_TempStation->m_DockWidget, GpuMinoitorDock, Qt::Vertical);
	//}

	//绑定窗口的新建与关闭信号
	connect(m_TempStation->m_ImageWindow, &ImageWindow::SendCloseEvent, this, &DynamicWidget::DeleteWindowSlot);
	connect(m_TempStation, &MyStation::AddOneWindowSignals, this, &DynamicWidget::AddWindowSlot);

	if (windowsNums >= 10)
	{		
		for (int i = 1; i <= m_Station.size(); i++)
	    {
			QRect desktopRect = QApplication::desktop()->availableGeometry();
			int MaxHeight = (desktopRect.height() - 80) / ((index - 1) / windosCols + 1);
			int MaxWidth = (desktopRect.width() - 500) / windosCols;
			m_Station[i - 1]->m_ImageWindow->setMaximumHeight(MaxHeight);
			m_Station[i - 1]->m_ImageWindow->setMaximumWidth(MaxWidth);
	    }
	}

	//this->setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::North);//设置本界面中所有的qdockwidget的标签位置在顶部
	setDockOptions(GroupedDragging); //设置可以通过tab页将DockWidget拉出来!!!
	

	//设置语言字体
	QFont font;
	if (isChineseLanguage())
		font.setFamily("Microsoft YaHei");
	else
		font.setFamily("Roboto");
	auto listWidget = findChildren<QWidget*>();
	for (auto& widget : listWidget)
	{
		widget->setFont(font);
	}
}

// 删除窗口槽函数:: int参数传入删除的窗口ID
void DynamicWidget::DeleteWindowSlot(int windowIndex)
{
	//重设各个类的窗口下标
	for (int i = windowIndex; i < windowsNums; i++)
	{
		m_Station[i]->StationIndex = m_Station[i]->StationIndex - 1;
		m_Station[i]->m_ImageWindow->SetWindowsTittle();
	}
	//窗口总数-1
	windowsNums--;

	//删除指定窗口
	delete m_Station[windowIndex - 1];
	auto it = m_Station.begin();
	m_Station.erase(it + windowIndex - 1);

	//重新布局与重设DoceWidget下标
	int windosCols = (int)(sqrt(windowsNums) * 10) % 10 == 0 ? sqrt(windowsNums) : sqrt(windowsNums) + 1;
	for (int i = 1; i <= m_Station.size(); i++)
	{
		m_ImagesWindow->addWidget(m_Station[i - 1]->m_ImageWindow, (i - 1) / windosCols, (i - 1) % windosCols);
		QString strname;
		if (windowIndex == 1)
			strname = QString::fromLocal8Bit("机头");
		else if (windowIndex == 2)
			strname = QString::fromLocal8Bit("机尾");
	

		

		m_Station[i - 1]->m_DockWidget->setWindowTitle(strname);
	}

	//单例中的当前配置需要跟着删除窗口
	ConfigProgramme::GetInstance()->deleteWindow(windowIndex);

	//当窗口没有时新建一个默认窗口
	if (windowsNums == 0)
	{
		AddOneStation(1);
		windowsNums = 1;
	}
}

// 当切换方案或新建方案时执行的重置窗口槽函数
void DynamicWidget::ReSetWindowSlot()
{
	int WindowNumsss = windowsNums;
	for (int i = 1; i <= WindowNumsss; i++) //保留第一个窗口
	{
		DeleteWindowSlot(1);
	}
	for (auto OneCommunicate : ConfigProgramme::GetInstance()->m_Comunicate)
	{
		delete OneCommunicate;
	}
	ConfigProgramme::GetInstance()->m_Comunicate.clear();
	SaveImageConfig newSaveImageConfig;
	ConfigProgramme::GetInstance()->m_CameraSave = newSaveImageConfig;
	ConfigProgramme::GetInstance()->m_RenderSave = newSaveImageConfig;

	SetLogoVisuable(true);
	SetSoftName("");
}


void DynamicWidget::LoadProgramme(QString loadProgrammeName)
{
	//ReSetWindowSlot();
	try
	{
		if (ConfigProgramme::GetInstance()->LoadConfig(loadProgrammeName) == false)
			return;
		int ss1 = ConfigProgramme::GetInstance()->AllConfig.size();
		for (int i = 0; i < ConfigProgramme::GetInstance()->AllConfig.size(); i++)
		{
			WindowsConfig TempConfig = ConfigProgramme::GetInstance()->AllConfig[i];
			if (i != 0)
			{
				windowsNums++;
				int windosCols = (int)(sqrt(windowsNums) * 10) % 10 == 0 ? sqrt(windowsNums) : sqrt(windowsNums) + 1;
				for (int j = 0; j < windowsNums - 1; j++)
				{
					m_ImagesWindow->addWidget(m_Station[j]->m_ImageWindow, (j) / windosCols, (j) % windosCols);
				}
				AddOneStation(i + 1, true);
			}


			//初始化模型选择并发送模型信号
			m_Station[i]->m_ImageWindow->inintLoadModelChoice(TempConfig.m_ModelChoice);
			if (TempConfig.m_ModelChoice.modeType.size() != 0) m_Station[i]->SetOkNgVisible(TempConfig.m_ModelChoice.modeType[TempConfig.m_ModelChoice.modeType.size() - 1] != "OCR");
			//重置统计数据
			m_Station[i]->m_DataStatistic->ResetDataSlot();
			m_Station[i]->m_TimeStatistic->ResetDataSlot();

			//设置阈值设置界面 
			m_Station[i]->m_ImageWindow->m_ThresholdSetDialg->inintProgramThreshold(TempConfig.m_Threshold, TempConfig.m_TimeThreshold);
			//图像源
			m_Station[i]->LoadImageSourceFromConfig(TempConfig);
		}
		CSaveImage::GetInstance()->SelfStartDeleteByFileNums();
	}
	catch (exception&a)
	{
		return;
	}
}

void DynamicWidget::SetRunningState(RuningState inState)
{
	switch (inState)
	{
	case isWorking:
		ui.toolBar_Tool->setStyleSheet("QLabel#Label_State { border-image:url(\":/DynamicWidget/Resource/State_IsRuning.png\"); }");
		ui.toolBar_Tool->QAction_SignalGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_ContinueGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_StopGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_Setting->setEnabled(false);
		for (auto m_OneStation : m_Station) m_OneStation->WorkStateChange(true);
		break;
	case isStop:
		ui.toolBar_Tool->setStyleSheet("QLabel#Label_State { border-image:url(\":/DynamicWidget/Resource/State_NoRunning.png\"); }");
		ui.toolBar_Tool->QAction_SignalGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_ContinueGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_StopGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_Setting->setEnabled(true);
		for (auto m_OneStation : m_Station) m_OneStation->WorkStateChange(false);
		break;
	case isWaitting:
		ui.toolBar_Tool->setStyleSheet("QLabel#Label_State { border-image:url(\":/DynamicWidget/Resource/State_Waitting.png\"); }");
		ui.toolBar_Tool->QAction_SignalGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_ContinueGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_StopGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_Setting->setEnabled(false);
		break;
	}
}

void DynamicWidget::SetRuningState(bool isRuning)
{
	if (isRuning)
	{
		ui.toolBar_Tool->setStyleSheet("QLabel#Label_State { border-image:url(\":/DynamicWidget/Resource/State_IsRuning.png\"); }");
		ui.toolBar_Tool->QAction_SignalGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_ContinueGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_StopGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_Setting->setEnabled(false);
		for (auto m_OneStation : m_Station) m_OneStation->WorkStateChange(true);
	}
	else
	{
		ui.toolBar_Tool->setStyleSheet("QLabel#Label_State { border-image:url(\":/DynamicWidget/Resource/State_NoRunning.png\"); }");
		ui.toolBar_Tool->QAction_SignalGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_ContinueGrab->setEnabled(true);
		ui.toolBar_Tool->QAction_StopGrab->setEnabled(false);
		ui.toolBar_Tool->QAction_Setting->setEnabled(true);
		for (auto m_OneStation : m_Station) m_OneStation->WorkStateChange(false);
	}
}

// 监控算法线程是否运行结束的定时器槽函数
void DynamicWidget::TimerWatchOnAlgoStop()
{
	bool isAlgoRunning = false;
	for (int i = 0; i < m_Station.size(); i++)
	{
		if (m_Station[i]->m_AlgoThread->IsAlgoRuning() == true)
		{
			isAlgoRunning = true;
		}
	}

	if (isAlgoRunning == false) //所有的算法都已经结束了
	{
		SetRunningState(isStop);
		QTimer* TimerPtr = qobject_cast<QTimer*>(sender());
		TimerPtr->stop();
		killTimer(TimerPtr->timerId());
		delete TimerPtr;
	}
}

// 获取当前是否运行状态
bool DynamicWidget::isRunning()
{
	return !(ui.toolBar_Tool->QAction_SignalGrab->isEnabled());
}

// 窗口关闭事件时调用销毁资源
void DynamicWidget::closeEvent(QCloseEvent *e)
{
	if (GpuMinoitorDock != nullptr) delete GpuMinoitorDock->widget();
	for (int i = 0; i < m_Station.size(); i++)
	{
		delete m_Station[i];
	}
}

void DynamicWidget::resizeEvent(QResizeEvent *event)
{
	int width1 = int(this->width()*0.25);//左边的停靠窗宽是主界面的0.15倍
	if (m_Station.size() != 0)
		this->resizeDocks({ m_Station[0]->m_DockWidget }, { width1 }, Qt::Horizontal);//左右水平布局015:0.85
}



void DynamicWidget::onButtonMinClicked()
{
	showMinimized();
}

void DynamicWidget::onButtonRestoreClicked()
{
	showNormal();
}

void DynamicWidget::onButtonMaxClicked()
{
	showMaximized();
	showFullScreen();
}

void DynamicWidget::onButtonCloseClicked()
{
	close();
}

void DynamicWidget::SetLogoVisuable(bool isSee)
{
	ui.toolBar_TitleBar->SetLogoVisuable(isSee);
}

void DynamicWidget::SetSoftName(QString name)
{
	ui.toolBar_TitleBar->setTitleContent(name);
}

bool DynamicWidget::GetLogoVisuable()
{
	return ui.toolBar_TitleBar->GetLogoVisuable();
}

QString DynamicWidget::GetSoftName()
{
	return ui.toolBar_TitleBar->GetSoftName();
}