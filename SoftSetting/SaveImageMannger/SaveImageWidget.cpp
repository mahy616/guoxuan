#include "SaveImageWidget.h"
#include "components/Config/ConfigProgramme.h"
#include <QFileInfo>
#include <QFileDialog>

SaveImageWidget::SaveImageWidget(bool isCameraWidget, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	isCameraWidgets = isCameraWidget;
	if (isCameraWidget)
		ui.CheckBox_EnableSave->setText(tr("Save Original Image"));
	else
		ui.CheckBox_EnableSave->setText(tr("Save Result Image"));

	connect(ui.CheckBox_EnableSave, &QCheckBox::stateChanged, [=]()
	{
		SetWidgetEnable(ui.CheckBox_EnableSave->isChecked());
	});
	connect(ui.checkBox_deleteNums, &QCheckBox::stateChanged, [=]()
	{
		SetDeleteNumsEnable(ui.checkBox_deleteNums->isChecked());
	});
	connect(ui.checkBox_deleteDays, &QCheckBox::stateChanged, [=]()
	{
		SetDeleteDaysEnable(ui.checkBox_deleteDays->isChecked());
	});
	connect(ui.checkBox_deleteMemory, &QCheckBox::stateChanged, [=]()
	{
		SetDeleteMemoryEnable(ui.checkBox_deleteMemory->isChecked());
	});

	connect(ui.btn_ChangePath, &QPushButton::clicked, this, [=]()
	{
		QString RootDir = QFileDialog::getExistingDirectory();
		if (RootDir.length() != 0)
		{
			ui.lineEdit_ImgPath->setText(RootDir);
		}
	});


	ui.comboBox_ImgType->addItem("jpg");
	ui.comboBox_ImgType->addItem("bmp");
	ui.comboBox_ImgType->addItem("png");
	ui.lineEdit_deleteNums->setValidator(new QIntValidator(0, 99999999, this));
	ui.lineEdit_deleteDays->setValidator(new QIntValidator(0, 99999999, this));
	ui.lineEdit_deleteMemory->setValidator(new QIntValidator(0, 99999999, this));

	SetWidgetEnable(ui.CheckBox_EnableSave->isChecked());
	if(isCameraWidget)
		inintLoadParam(ConfigProgramme::GetInstance()->m_CameraSave);
	else
		inintLoadParam(ConfigProgramme::GetInstance()->m_RenderSave);
}

void SaveImageWidget::inintLoadParam(SaveImageConfig m_InParam)
{
	if (m_InParam.isSave)
		ui.CheckBox_EnableSave->setChecked(true);
	else
		ui.CheckBox_EnableSave->setChecked(false);

	if (m_InParam.isDeleteNums)
		ui.checkBox_deleteNums->setChecked(true);
	else
		ui.checkBox_deleteNums->setChecked(false);

	if (m_InParam.isDeleteDays)
		ui.checkBox_deleteDays->setChecked(true);
	else
		ui.checkBox_deleteDays->setChecked(false);

	if (m_InParam.isDeleteMemory)
		ui.checkBox_deleteMemory->setChecked(true);
	else
		ui.checkBox_deleteMemory->setChecked(false);
	//ui.checkBox_deleteMemory->setCheckState(m_InParam.deleteMemory ? Qt::Checked : Qt::Unchecked);

	if (m_InParam.SaveType == "jpg")
	{
		ui.comboBox_ImgType->setCurrentIndex(0);
	}
	if (m_InParam.SaveType == "bmp")
	{
		ui.comboBox_ImgType->setCurrentIndex(1);
	}
	if (m_InParam.SaveType == "png")
	{
		ui.comboBox_ImgType->setCurrentIndex(2);
	}

	ui.lineEdit_ImgPath->setText(m_InParam.ImgPathStr);
	ui.lineEdit_deleteDays->setText(QString::number(m_InParam.deleteDays));
	ui.lineEdit_deleteNums->setText(QString::number(m_InParam.deleteNums));
	ui.lineEdit_deleteMemory->setText(QString::number(m_InParam.deleteMemory));
}



SaveImageWidget::~SaveImageWidget()
{
	UpdateSaveConfig();
}

void SaveImageWidget::SetWidgetEnable(bool isEnable)
{
	ui.lineEdit_ImgPath->setEnabled(isEnable);
	ui.btn_ChangePath->setEnabled(isEnable);
	ui.comboBox_ImgType->setEnabled(isEnable);
	ui.checkBox_deleteNums->setEnabled(isEnable);
	ui.checkBox_deleteDays->setEnabled(isEnable);
	ui.checkBox_deleteMemory->setEnabled(isEnable);
	ui.lineEdit_deleteNums->setEnabled(isEnable);
	ui.lineEdit_deleteDays->setEnabled(isEnable);
	ui.lineEdit_deleteMemory->setEnabled(isEnable);
	ui.label->setEnabled(isEnable);
	ui.label_2->setEnabled(isEnable);
	ui.label_3->setEnabled(isEnable);
	ui.label_4->setEnabled(isEnable);

	if (isEnable)
	{
		SetDeleteNumsEnable(ui.checkBox_deleteNums->isChecked());
		SetDeleteDaysEnable(ui.checkBox_deleteDays->isChecked());
		SetDeleteMemoryEnable(ui.checkBox_deleteMemory->isChecked());
	}
}

void SaveImageWidget::SetDeleteNumsEnable(bool isEnable)
{
	ui.lineEdit_deleteNums->setEnabled(isEnable);
}

void SaveImageWidget::SetDeleteDaysEnable(bool isEnable)
{
	ui.lineEdit_deleteDays->setEnabled(isEnable);

}

void SaveImageWidget::SetDeleteMemoryEnable(bool isEnable)
{
	ui.lineEdit_deleteMemory->setEnabled(isEnable);
}

void SaveImageWidget::UpdateSaveConfig()
{
	SaveImageConfig m_Param;
	if (ui.CheckBox_EnableSave->isChecked())
	{
		m_Param.isSave = true;

		//保存路径
		QFileInfo isFile(ui.lineEdit_ImgPath->text());
		if (isFile.exists())
		{
			m_Param.ImgPathStr = ui.lineEdit_ImgPath->text();
		}

		//自动删除数量
		if (ui.checkBox_deleteNums->isChecked())
		{
			m_Param.isDeleteNums = true;
			m_Param.deleteNums = ui.lineEdit_deleteNums->text().toInt();
		}
		else
		{
			m_Param.isDeleteNums = false;
		}
		//自动删除天数
		if (ui.checkBox_deleteDays->isChecked())
		{
			m_Param.isDeleteDays = true;
			m_Param.deleteDays = ui.lineEdit_deleteDays->text().toInt();
		}
		else
		{
			m_Param.isDeleteDays = false;
		}
		//自动删除容量
		if (ui.checkBox_deleteMemory->isChecked())
		{
			m_Param.isDeleteMemory = true;
			m_Param.deleteMemory = ui.lineEdit_deleteMemory->text().toInt();
		}
		else
		{
			m_Param.isDeleteMemory = false;
		}
		//图片类型
		m_Param.SaveType = ui.comboBox_ImgType->currentText();
	}
	else
	{
		m_Param.isSave = false;
	}

	if (isCameraWidgets)
		ConfigProgramme::GetInstance()->m_CameraSave = m_Param;
	else
		ConfigProgramme::GetInstance()->m_RenderSave = m_Param;
}

void SaveImageWidget::showEvent(QShowEvent *event)
{
	if (isCameraWidgets)
		inintLoadParam(ConfigProgramme::GetInstance()->m_CameraSave);
	else
		inintLoadParam(ConfigProgramme::GetInstance()->m_RenderSave);
	return QWidget::showEvent(event);
}

//void SaveImageWidget::InintConfig(bool isCamera)
//{
//	SaveImageConfig m_Config;
//	if (isCamera)
//		m_Config = ConfigProgramme::GetInstance()->m_CameraSave;
//	else
//		m_Config = ConfigProgramme::GetInstance()->m_RenderSave;
//
//	ui.CheckBox_EnableSave->setChecked(m_Config.isSave);
//	ui.lineEdit_ImgPath->setText(m_Config.ImgPathStr);
//	if (m_Config.SaveType == "jpg")
//	{
//		ui.comboBox_ImgType->setCurrentIndex(0);
//	}
//	if (m_Config.SaveType == "bmp")
//	{
//		ui.comboBox_ImgType->setCurrentIndex(1);
//	}
//	if (m_Config.SaveType == "png")
//	{
//		ui.comboBox_ImgType->setCurrentIndex(2);
//	}
//	ui.checkBox_deleteNums->setChecked(m_Config.isDeleteNums);
//	ui.checkBox_deleteDays->setChecked(m_Config.isDeleteDays);
//	ui.checkBox_deleteMemory->setChecked(m_Config.isDeleteMemory);
//	ui.lineEdit_deleteNums->setText(QString::number(m_Config.deleteNums));
//	ui.lineEdit_deleteDays->setText(QString::number(m_Config.deleteDays));
//	ui.lineEdit_deleteMemory->setText(QString::number(m_Config.deleteMemory));
//	ui.checkBox_deleteMemory->setChecked(m_Config.isDeleteMemory);
//}