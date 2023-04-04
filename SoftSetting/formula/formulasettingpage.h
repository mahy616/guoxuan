#pragma once
#include <QWidget>
#include <configuiset/settingpage.h>
#include "configdatamanager/configmanager.h"


namespace Ui {
	class FormulaSettingPage;
}
namespace vilab::display
{
using FormulaConfigData = vilab::config::FormulaConfigData;
class FormulaSettingPage : public SettingPage
{
	Q_OBJECT

public:
	explicit FormulaSettingPage(QWidget *parent);
	~FormulaSettingPage();
	void disableFocus() override;

	void initConfigData() override;

	void saveConfigData() override;

	void cancelConfigData() override;

	bool validatePage() override;
private:
	Ui::FormulaSettingPage *ui;
	FormulaConfigData m_formula_config_data;
	};
}
