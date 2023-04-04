#include "ModelConfigDialg.h"
#include <QMessageBox>


ModelConfigDialg::ModelConfigDialg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_ModelChoice._useGPU = false;
	ui.comboBox->setEnabled(true);
	ui.label_ModeType->setText(tr("Please choose pipeline"));
	ui.label_LabelNames->setText(tr("Please choose pipeline"));
	inintParamters();
	inintConnection();

	//设置语言字体
	QFont font;
	font.setPointSize(11);
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

ModelConfigDialg::~ModelConfigDialg()
{

}

void ModelConfigDialg::setParamter(ConfigResult m_ConfigResult, QString jsonPath)
{
	ui.label_JsonPath->setText(jsonPath);
	//m_inserValue.ConfigJsonPath.push_back(jsonPath.toLocal8Bit().toStdString());
	m_ModelChoice._jsonPath = jsonPath;

	if (m_VecticalLayOut == NULL)
	{
		m_VecticalLayOut = new QVBoxLayout;  //递增。需要清空
	}
	else
	{
		//第一步：清空布局
		ClearLayout(m_VecticalLayOut);
		m_CheckBoxIndex.clear();
		delete m_VecticalLayOut;
		m_VecticalLayOut = NULL;
		m_VecticalLayOut = new QVBoxLayout;
	}

	for (int Index1 = 0; Index1 < m_ConfigResult.EveryModel.size(); Index1++) //Solution循环
	{
		QHBoxLayout *m_HorizontalLayOut = new QHBoxLayout;
		std::vector<QPushButton *> m_ButtonVec;
		for (int Index2 = 0; Index2 < m_ConfigResult.EveryModel[Index1].ModeType.size(); Index2++) //当前SolutionID下的模型数量
		{
			QPushButton * m_ButtonModel = new QPushButton;
			m_ButtonModel->setText(QString::fromLocal8Bit(m_ConfigResult.EveryModel[Index1].ModeType[Index2].RealNameValue.c_str()));
			m_ButtonModel->setMinimumHeight(40);
			m_ButtonModel->setMaximumHeight(40);
			m_ButtonModel->setStyleSheet("QPushButton{color:black; font: 10pt;background-color: #f5f6fa;border-color: #000854;border-radius: 20px;}");
			m_HorizontalLayOut->addWidget(m_ButtonModel);
			m_ButtonVec.push_back(m_ButtonModel);
		}

		QCheckBox *m_CheckBox = new QCheckBox;
		QCheckContents m_inserValue;
		for (int Index2 = 0; Index2 < m_ConfigResult.EveryModel[Index1].ModeType.size(); Index2++) //当前SolutionID下的module数量
		{		
			m_inserValue.soutionIndex.push_back(Index1);
			m_inserValue.moduleID.push_back(m_ConfigResult.EveryModel[Index1].ModeType[Index2].ModulesName);
			m_inserValue.modeType.push_back(m_ConfigResult.EveryModel[Index1].ModeType[Index2].m_ModeType);
			m_inserValue.labelsNamesVec.push_back(m_ConfigResult.EveryModel[Index1].ModeType[Index2].LableNames);
			m_inserValue.RealNameValue.push_back(m_ConfigResult.EveryModel[Index1].ModeType[Index2].RealNameValue);
			m_CheckBoxIndex.insert(m_CheckBox, m_inserValue);
			connect(m_CheckBox, &QCheckBox::clicked, this, &ModelConfigDialg::CheckBoxClickSlot);
			connect(m_CheckBox, &QCheckBox::stateChanged, this, [=]() {
				bool isBoxCheck = false;
				for (int i = 0; i < m_ButtonVec.size(); i++)
				{
					if (m_CheckBox->isChecked())
					{
						isBoxCheck = true;
						m_ButtonVec[i]->setStyleSheet("QPushButton{color:white; font: 10pt;background-color: #000642;border-color: #000D87;border-radius: 20px;}");
					}
					else
					{
						m_ButtonVec[i]->setStyleSheet("QPushButton{color:black; font: 10pt;background-color: #f5f6fa;border-color: #000854;border-radius: 20px;}");
					}
				}
				if (isBoxCheck == false)
				{
					ui.label_ModeType->setText(tr("Please choose pipeline"));
					ui.label_LabelNames->setText(tr("Please choose pipeline"));
				}
			});
			m_HorizontalLayOut->addWidget(m_CheckBox);
		}
		m_VecticalLayOut->addLayout(m_HorizontalLayOut);
	}
	m_ModelChoice.TypeName = m_ConfigResult.TypeName;
	//ui.groupBox->setMaximumHeight(m_ConfigResult.EveryModel.size() * 100);
	ui.groupBox->setMinimumHeight(m_ConfigResult.EveryModel.size() * 100);
	ui.groupBox->setLayout(m_VecticalLayOut);
	//ui.verticalLayoutUp->addLayout(m_VecticalLayOut);
}

void ModelConfigDialg::CheckBoxClickSlot()
{
	QObject* obj = sender();
	QCheckBox* CheckBoxSender = dynamic_cast<QCheckBox*>(obj);
	if (CheckBoxSender->isChecked())
	{
		ui.comboBox->setEnabled(true);
		QMap<QCheckBox*, QCheckContents>::const_iterator ItForech = m_CheckBoxIndex.constBegin();
		while (ItForech != m_CheckBoxIndex.constEnd())
		{
			if (ItForech.key() != CheckBoxSender)
			{
				ItForech.key()->setChecked(false);
			}
			++ItForech;
		}
		QMap<QCheckBox*, QCheckContents>::iterator it = m_CheckBoxIndex.find(CheckBoxSender);
		if (it != m_CheckBoxIndex.end())
		{
			qDebug() << it.value().soutionIndex;

			QString showModel;
			for (int modelIndex = 0; modelIndex < it.value().modeType.size(); modelIndex++)
			{
				showModel = showModel + QString::fromStdString(it.value().modeType[modelIndex]) + "+";
			}
			showModel = showModel.mid(0, showModel.size() - 1);
			ui.label_ModeType->setText(showModel);

			QString showLables;
			for (int j = 0; j < it.value().labelsNamesVec[it.value().labelsNamesVec.size()-1].size(); j++)
			{
				showLables = showLables + QString::fromLocal8Bit(it.value().labelsNamesVec[it.value().labelsNamesVec.size() - 1][j].c_str()) + " , ";
			}
			ui.label_LabelNames->setText(showLables);

			m_ModelChoice.labelsNamesVec = it.value().labelsNamesVec;
			m_ModelChoice.soutionIndex = it.value().soutionIndex;
			m_ModelChoice.RealNameValue = it.value().RealNameValue;
			m_ModelChoice.moduleID = it.value().moduleID;
			m_ModelChoice.modeType = it.value().modeType;

			/*if (it.value().modeType[it.value().modeType.size()-1] == "segmentation")
				m_ModelChoice.m_ModelType = Segmentation;
			else if (it.value().modeType == "detection")
				m_ModelChoice.m_ModelType = Detection;
			else if (it.value().modeType == "classification")
				m_ModelChoice.m_ModelType = Classification;
			else if (it.value().modeType == "ocr")
				m_ModelChoice.m_ModelType = OCR;*/
		}
	}
	else
	{
		ui.comboBox->setEnabled(false);
	}
}



void ModelConfigDialg::inintParamters()
{
	std::vector<GpuInfos> m_GpuNums = GetResultFromCMD();
	if (m_GpuNums.size() == 0)
	{
		ui.label_GpuFlag->setText(tr("No GPU Found"));
		ui.btn_GPUFlag->setEnabled(false);
		m_ModelChoice._useGPU = false;
		return;
	}
	else
	{
		for (int i = 1; i <= m_GpuNums.size(); i++)
		{
			ui.comboBox->addItem(QString::number(i - 1));
		}
		m_ModelChoice._gpuID = 0;
		ui.comboBox->setCurrentIndex(0);
	}
}

void ModelConfigDialg::inintConnection()
{
	//关联信号和槽
	connect(ui.pushButton_ChangeModel, &QPushButton::clicked, this, &ModelConfigDialg::ChangeModelBtnSlot);
	connect(ui.comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(GpuIDChangeSlot(QString)));
	connect(ui.btn_GPUFlag, &QPushButton::clicked, this, &ModelConfigDialg::BtnGpuFlagChange);
	connect(ui.btn_confirm, &QPushButton::clicked, this, &ModelConfigDialg::BtnConfirm);
	connect(ui.btn_cancel, &QPushButton::clicked, this, [=]() {this->close(); });
}

void ModelConfigDialg::BtnGpuFlagChange()
{
	gpuState = !gpuState;
	if (gpuState)
	{
		m_ModelChoice._useGPU = true;
		ui.btn_GPUFlag->setStyleSheet("border-image:url(:/DynamicWidget/Resource/Btn_Open.png);background: \"transparent\";");
	}
	else
	{
		m_ModelChoice._useGPU = false;
		ui.btn_GPUFlag->setStyleSheet("border-image:url(:/DynamicWidget/Resource/Btn_Close.png);background: \"transparent\";");
	}
}

void ModelConfigDialg::ChangeModelBtnSlot()
{
	QString RootDir = QFileDialog::getOpenFileName(this, tr("Choose json file"), "");
	if (RootDir.isEmpty())
	{
		return;
	}
	QFileInfo fileinfo = QFileInfo(RootDir);
	RootDir = fileinfo.absolutePath();

	/*QString RootDir = QFileDialog::getExistingDirectory();
	if (RootDir.size() == 0)
	{
		return;
	}*/
	JsonReader m_JsonReader;
	ConfigResult m_ConfigResults = m_JsonReader.GetConfigResult(RootDir);
	setParamter(m_ConfigResults, RootDir + "/config.json");

	ui.label_ModeType->setText(tr("Please choose pipeline"));
	ui.label_LabelNames->setText(tr("Please choose pipeline"));
}

void ModelConfigDialg::GpuIDChangeSlot(QString myChangeText)
{
	m_ModelChoice._gpuID = myChangeText.toInt();
}

void ModelConfigDialg::BtnConfirm()
{
	for (int i = 0; i < m_ModelChoice.labelsNamesVec.size(); i++)
	{
		if (m_ModelChoice.labelsNamesVec[i].size() == 0)
		{
			QString showWord = QString::fromLocal8Bit(m_ModelChoice.RealNameValue[i].c_str()) + tr("Pipeline has no features,initialization failed.");
			QMessageBox::information(NULL, tr("Tips"), showWord); return;
		}
	}
	bool isHaveCheck = false;
	QMap<QCheckBox*, QCheckContents>::const_iterator ItForech = m_CheckBoxIndex.constBegin();
	while (ItForech != m_CheckBoxIndex.constEnd())
	{
		if (ItForech.key()->isChecked() == true)
		{
			isHaveCheck = true;
		}
		++ItForech;
	}

	if (isHaveCheck == false) {
		QMessageBox::information(NULL, tr("Tips"), tr("Please choose pipeline")); return;
	}

	if (m_ModelChoice._jsonPath.size() != 0 /*&& m_ModelChoice.LableNames.size() != 0*/ && m_ModelChoice.TypeName.size() != 0)
	{
		emit SendModelChoice(m_ModelChoice);
	}	
	this->close();
}

void ModelConfigDialg::LoadModelChoice(ModelChoice inChoice)
{
	JsonReader m_JsonReader;
	QFileInfo fileinfo(inChoice._jsonPath);
	if (fileinfo.exists() == false) return;
	ConfigResult m_ConfigResults = m_JsonReader.GetConfigResult(fileinfo.absolutePath());
	setParamter(m_ConfigResults, inChoice._jsonPath);


	QMap<QCheckBox*, QCheckContents>::Iterator iter1;
	for (iter1 = m_CheckBoxIndex.begin(); iter1 != m_CheckBoxIndex.end(); ++iter1)
	{
		QCheckContents m_Temp = iter1.value();
		if (m_Temp.RealNameValue == inChoice.RealNameValue)
		{
			iter1.key()->setChecked(true);
			emit iter1.key()->clicked();
		}
	}

	//是否使用GPU
	if (inChoice._useGPU) BtnGpuFlagChange();
	//GPU的ID
	ui.comboBox->setCurrentIndex(inChoice._gpuID);

	emit SendModelChoice(inChoice);
}


