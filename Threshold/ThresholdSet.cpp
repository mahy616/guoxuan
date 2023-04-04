#include "ThresholdSet.h"
#include "VimoThreshold/ThresholdClassification.h"
#include "VimoThreshold/ThresholdDetection.h"
#include "VimoThreshold/ThresholdOCR.h"
#include "VimoThreshold/ThresholdSegmentation.h"

ThresholdSet::ThresholdSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QValidator *validator1 = new QIntValidator(0, 9999999, this);
	ui.lineEdit_Time->setValidator(validator1);

	connect(ui.btn_Confim, &QPushButton::clicked, this, &ThresholdSet::btnConfimSlot);
	connect(ui.btn_ReSet, &QPushButton::clicked, this, &ThresholdSet::btnReSetSlot);
	connect(ui.btn_Cancel, &QPushButton::clicked, this, [=]() { this->close(); });
}

ThresholdSet::~ThresholdSet()
{
	qDebug() << "~ThresholdSet";
}

void ThresholdSet::SetMyParamter(std::vector<string> RealNameVec, std::vector<string> inTypeVec, std::vector<std::vector<std::string>> inLableNamesVec)
{
	//清空旧的阈值对话框
	for (int i = 0; i < m_ThresholdDialgVec.size(); i++)
	{
		delete m_ThresholdDialgVec[i];
		delete RenderWidgets[i];
	}
	//把所有StackWidget的Widget释放掉
	for (int i = ui.stackedWidget_ThresholdDialog->count(); i >= 0; i--)
	{
		//后处理
		QWidget* widget = ui.stackedWidget_ThresholdDialog->widget(i);
		ui.stackedWidget_ThresholdDialog->removeWidget(widget);
		widget->deleteLater();
		//渲染显示设置
		QWidget* widget2 = ui.stackedWidget_RenderSet->widget(i);
		ui.stackedWidget_RenderSet->removeWidget(widget2);
		widget2->deleteLater();
	}
	m_ThresholdDialgVec.clear(); 
	RenderWidgets.clear(); 
	ui.comboBox_Models->clear();

	//根据当前模型重新创建阈值对象
	for (int i = 0; i < RealNameVec.size(); i++)
	{
		// 下拉框添加选择项
		QString ModelText = QString::fromLocal8Bit(RealNameVec[i].c_str()) + QString::fromLocal8Bit("(Model:%2)").arg(inTypeVec[i].c_str());
		ui.comboBox_Models->addItem(ModelText);

		// 创建后处理阈值Widget
		ThresholdBase* OneThresholdDialg;
		switch (GetModelTypeFromString(inTypeVec[i]))
		{
		case Segmentation:
			OneThresholdDialg = new ThresholdSegmentation((i == RealNameVec.size() - 1) ? false : true);
			break;
		case Detection:
			OneThresholdDialg = new ThresholdDetection;
			break;
		case Classification:
			OneThresholdDialg = new ThresholdClassification;
			break;
		case OCR:
			OneThresholdDialg = new ThresholdOCR;
			break;
		default:
			break;
		}

		OneThresholdDialg->InintWindow(inLableNamesVec[i]);
		m_ThresholdDialgVec.push_back(OneThresholdDialg);
		ui.stackedWidget_ThresholdDialog->addWidget(OneThresholdDialg);

		// 创建渲染显示Widget
		RenderSetWidget* OneDialg = new RenderSetWidget(inLableNamesVec[i]);
		RenderWidgets.push_back(OneDialg);
		ui.stackedWidget_RenderSet->addWidget(OneDialg);
	}

	connect(ui.comboBox_Models, SIGNAL(currentIndexChanged(int)), this, SLOT(onDialgCurrentIndexChanged(int)));

	//默认选择后置模块模型
	ui.comboBox_Models->setCurrentIndex(RealNameVec.size() - 1);

}

//在ComBox中切换了模型响应的槽函数 - 切换显示的Widget
void ThresholdSet::onDialgCurrentIndexChanged(int index)
{
	if (index < 0 || index >= m_ThresholdDialgVec.size()) return;
	ui.stackedWidget_ThresholdDialog->setCurrentIndex(index);
	ui.stackedWidget_RenderSet->setCurrentIndex(index);
}

//点击了确定按钮 - 设置阈值
void ThresholdSet::btnConfimSlot()
{
	m_TimeThreshold.TimeThreshold = ui.lineEdit_Time->text().toInt();
	if (ui.radioButton_ViMo->isChecked()) m_TimeThreshold.m_TimeType = OnlyViMo;
	if (ui.radioButton_PostProcess->isChecked()) m_TimeThreshold.m_TimeType = OnlyPostProcess;
	if (ui.radioButton_ViMoAndPost->isChecked()) m_TimeThreshold.m_TimeType = ViMoAndPostProcess;
	emit SendThresholdPatamter();
	this->close();
}

//获取当前模型的所有阈值
std::vector<AllThreshold> ThresholdSet::GetThresholdAllParam()
{
	std::vector <AllThreshold> returnAllParam;

	//后处理阈值参数
	TimeSetParamter m_timeParam;
	m_timeParam.TimeThreshold = ui.lineEdit_Time->text().toInt();
	if (ui.radioButton_ViMo->isChecked()) m_timeParam.m_TimeType = OnlyViMo;
	if (ui.radioButton_PostProcess->isChecked()) m_timeParam.m_TimeType = OnlyPostProcess;
	if (ui.radioButton_ViMoAndPost->isChecked()) m_timeParam.m_TimeType = ViMoAndPostProcess;

	for (int i = 0; i < m_ThresholdDialgVec.size(); i++)
	{
		AllThreshold oneThreshold;
		if (i < RenderWidgets.size()) oneThreshold._RenderParam = RenderWidgets[i]->GetShowValue();
		ThresholdParams inPostThreshold;
		m_ThresholdDialgVec[i]->GetThreshold(inPostThreshold);
		oneThreshold._PostParam = inPostThreshold;
		oneThreshold._PostParam._timeType = m_timeParam.m_TimeType;
		oneThreshold._RenderParam = RenderWidgets[i]->GetShowValue();
		returnAllParam.push_back(oneThreshold);
	}

	return returnAllParam;
}

//获取当前的超时阈值
int ThresholdSet::GetTimeValue()
{
	return ui.lineEdit_Time->text().toInt();
}

TimeSetParamter ThresholdSet::GetTimeThreshold()
{
	return m_TimeThreshold;
}

//加载方案时从配置文件初始化阈值
void ThresholdSet::inintProgramThreshold(std::vector<AllThreshold> m_Threshold, TimeSetParamter inTimeParam)
{
	
	for (int i = 0; i < m_Threshold.size(); i++)
	{
		if (i < m_ThresholdDialgVec.size())
		{
			m_ThresholdDialgVec[i]->LoadConfigThreshold(m_Threshold[i]._PostParam);//阈值类赋值
		}
		if (i < RenderWidgets.size())
		{
			RenderWidgets[i]->LoadConfigRenderSet(m_Threshold[i]._RenderParam);//阈值类赋值
		}
	}


	//计时内容赋值
	m_TimeThreshold = inTimeParam;
	ui.lineEdit_Time->setText(QString::number(m_TimeThreshold.TimeThreshold));
	switch (m_TimeThreshold.m_TimeType)
	{
	case OnlyViMo:
		ui.radioButton_ViMo->setChecked(true);
		break;
	case OnlyPostProcess:
		ui.radioButton_PostProcess->setChecked(true);
		break;
	case ViMoAndPostProcess:
		ui.radioButton_ViMoAndPost->setChecked(true);
		break;
	}
	emit SendThresholdPatamter();
}

//显示事件中获取当前的模型信息并初始化算法类中获取的阈值
void ThresholdSet::showEvent(QShowEvent *event)
{
	//获取当前模型信息
	std::vector<ViMoModelInfo> ModelInfos = m_AlgoInfoCallBack();
	for (int i = 0; i < m_ThresholdDialgVec.size(); i++)
	{
		m_ThresholdDialgVec[i]->SetModelInfo(ModelInfos[i]);
	}
	//获取算法类对象的阈值并初始化阈值界面
	inintProgramThreshold(m_AlgoThreadCallBack(), m_TimeThreshold);
}

//重置按钮
void ThresholdSet::btnReSetSlot()
{
	inintProgramThreshold(m_AlgoThreadCallBack(), m_TimeThreshold);
}


