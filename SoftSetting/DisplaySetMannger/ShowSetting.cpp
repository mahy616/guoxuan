#include "ShowSetting.h"
#include <QButtonGroup>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <qmessagebox.h>
#include <DynamicWidget.h>

ShowSetting::ShowSetting(QWidget *parent)
	: QWidget(parent)	
{
	ui.setupUi(this);
	QButtonGroup *m_Group = new QButtonGroup(this);
	m_Group->addButton(ui.radioButton_Chinese,1);
	m_Group->addButton(ui.radioButton_English,2);
	connect(m_Group, SIGNAL(buttonClicked(int)), this, SLOT(slot_LanguageClicked(int)));
	ui.radioButton_English->setChecked(true);

	QFile fileWhitchPro(".//config//language.json");
	if (fileWhitchPro.exists())
	{
		fileWhitchPro.open(QIODevice::ReadOnly);
		auto dataWhitchPro = fileWhitchPro.readAll();
		fileWhitchPro.close();
		QJsonParseError jErrorWhitchPro;	//创建QJsonParseError对象
		QJsonDocument jsonDocWhitchPro = QJsonDocument::fromJson(dataWhitchPro, &jErrorWhitchPro);
		if (jErrorWhitchPro.error == QJsonParseError::NoError)
		{
			QJsonObject rootObjWhitchPro = jsonDocWhitchPro.object();
			QJsonValue valueArrayTypes = rootObjWhitchPro.value("Language");
			if (valueArrayTypes.toInt() == 1)
			{
				ui.radioButton_Chinese->setChecked(true);
			}
		}
	}

	connect(ui.btn_ShowLogo, &QPushButton::clicked, this, [=]()
	{
		isShowLogo = !isShowLogo;
		if (DynamicWidget::GetInstance() != nullptr) DynamicWidget::GetInstance()->SetLogoVisuable(isShowLogo);
		if (isShowLogo)
		{
			ui.btn_ShowLogo->setStyleSheet("border-image:url(:/DynamicWidget/Resource/Btn_Open.png);background: \"transparent\";");
		}
		else
		{
			ui.btn_ShowLogo->setStyleSheet("border-image:url(:/DynamicWidget/Resource/Btn_Close.png);background: \"transparent\";");
		}
	});

	connect(ui.lineEdit_SoftName, &QLineEdit::editingFinished, this, [=]()
	{
		if (DynamicWidget::GetInstance() != nullptr) DynamicWidget::GetInstance()->SetSoftName(ui.lineEdit_SoftName->text());
	});

	if (DynamicWidget::GetInstance()->GetLogoVisuable() == false) emit ui.btn_ShowLogo->clicked();
	ui.lineEdit_SoftName->setText(DynamicWidget::GetInstance()->GetSoftName());
	ui.lineEdit_SoftName->setMaxLength(20);
}

ShowSetting::~ShowSetting()
{}

void ShowSetting::showEvent(QShowEvent *event)
{
	if (DynamicWidget::GetInstance()->GetLogoVisuable() != isShowLogo) emit ui.btn_ShowLogo->clicked();
	ui.lineEdit_SoftName->setText(DynamicWidget::GetInstance()->GetSoftName());
	return QWidget::showEvent(event);
}

void ShowSetting::slot_LanguageClicked(int inIndex)
{
	QJsonObject json;
	json.insert("Language", QJsonValue(inIndex));
	QFile file(".//config//language.json");
	QJsonDocument jsonDoc;
	jsonDoc.setObject(json);
	QByteArray data = jsonDoc.toJson();
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);
	file.write(data);
	file.close();

	if (QMessageBox::Yes != QMessageBox::question(nullptr, tr("Please confirm"), tr("Restart the software to take effect"))) return;
	qApp->quit();
}
