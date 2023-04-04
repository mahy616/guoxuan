#include "formulasettingpage.h"
#include "ui_formulasettingpage.h"
#include "cropdetect/cfg/_utils.h"
#include "QFileDialog"



namespace vilab::display
{
	using ConfigManager = vilab::config::ConfigManager;
	FormulaSettingPage::FormulaSettingPage(QWidget *parent)
		: SettingPage(parent), ui(new Ui::FormulaSettingPage)
	{
		ui->setupUi(this);
		setStyleSheet(vilab::common::getStyleSheetString(":/style/formulasettingpage_sheet.qss"));
	}

	FormulaSettingPage::~FormulaSettingPage()
	{
	}

	void FormulaSettingPage::disableFocus()
	{
	}

	void FormulaSettingPage::initConfigData()
	{
	
		const auto &formula_config_data = ConfigManager::getInstance().getFormulaConfigData();
		ui->lineEdit_zheng->setInputMask("99-99");
		ui->lineEdit_ce->setInputMask("99-99");
		ui->lineEdit_bei->setInputMask("99-99");

		ui->lineEdit_zheng->setText(formula_config_data.zheng_number.min_value+"-"+formula_config_data.zheng_number.max_value);
		ui->lineEdit_ce->setText(formula_config_data.ce_number.min_value + "-" + formula_config_data.ce_number.max_value);
		ui->lineEdit_bei->setText(formula_config_data.bei_number.min_value + "-" + formula_config_data.bei_number.max_value);

		ui->lineEdit_bright_zheng->setText(formula_config_data.bright_zheng_model);
		ui->lineEdit_bright_ce->setText(formula_config_data.bright_ce_model);
		ui->lineEdit_dark_zheng->setText(formula_config_data.dark_zheng_model);
		ui->lineEdit_dark_ce->setText(formula_config_data.dark_ce_model);

		formula_config_data.type == "bright" ? ui->radioButton_bright->setChecked(true) : ui->radioButton_dark->setChecked(true);

		connect(ui->pushButton_bright_zheng, &QPushButton::clicked, this, [=]
		{
			QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("模型文件"), "", "*.smartmore;*.png;;All Files(*)");
			if (imagePath.isEmpty())
				return;
			m_formula_config_data.bright_zheng_model = imagePath;
			ui->lineEdit_bright_zheng->setText(imagePath);
		});
		connect(ui->pushButton_bright_ce, &QPushButton::clicked, this, [=]
		{
			QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("模型文件"), "", "*.smartmore;*.png;;All Files(*)");
			if (imagePath.isEmpty())
				return;
			m_formula_config_data.bright_ce_model = imagePath;
			ui->lineEdit_bright_ce->setText(imagePath);
		});
		connect(ui->pushButton_dark_zheng, &QPushButton::clicked, this, [=]
		{
			QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("模型文件"), "", "*.smartmore;*.png;;All Files(*)");
			if (imagePath.isEmpty())
				return;
			m_formula_config_data.dark_zheng_model = imagePath;
			ui->lineEdit_dark_zheng->setText(imagePath);
		});
		connect(ui->pushButton_dark_ce, &QPushButton::clicked, this, [=]
		{
			QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("模型文件"), "", "*.smartmore;*.png;;All Files(*)");
			if (imagePath.isEmpty())
				return;
			m_formula_config_data.dark_ce_model = imagePath;
			ui->lineEdit_dark_ce->setText(imagePath);
		});
	
	}

	void FormulaSettingPage::saveConfigData()
	{
		m_formula_config_data.zheng_number = ConfigManager::getInstance().setFormula(ui->lineEdit_zheng->text());
		m_formula_config_data.ce_number = ConfigManager::getInstance().setFormula(ui->lineEdit_ce->text());
		m_formula_config_data.bei_number = ConfigManager::getInstance().setFormula(ui->lineEdit_bei->text());
		m_formula_config_data.all_nubmer = (std::max)({ m_formula_config_data.zheng_number.max_value.toInt(), 
			m_formula_config_data.ce_number.max_value.toInt(),m_formula_config_data.bei_number.max_value.toInt() });

		m_formula_config_data.type = ui->radioButton_bright->isChecked() ? "bright" : "dark";
		m_formula_config_data.bright_zheng_model = ui->lineEdit_bright_zheng->text();
		m_formula_config_data.bright_ce_model = ui->lineEdit_bright_ce->text();
		m_formula_config_data.dark_zheng_model = ui->lineEdit_dark_zheng->text();
		m_formula_config_data.dark_ce_model = ui->lineEdit_dark_ce->text();
		ConfigManager::getInstance().setFormulaConfigData(m_formula_config_data);

		//QString a = ui->lineEdit_zheng->text();
		//IniUtil::get_instance().SetValue("Formula/zheng_number", ui->lineEdit_zheng->text());
		//IniUtil::get_instance().SetValue("Formula/ce_number", ui->lineEdit_ce->text());
		//IniUtil::get_instance().SetValue("Formula/bei_number", ui->lineEdit_bei->text());
		

	}

	void FormulaSettingPage::cancelConfigData()
	{
	}
	bool FormulaSettingPage::validatePage()
	{
		return true;
	}
}