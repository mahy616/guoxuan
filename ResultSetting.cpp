#include "ResultSetting.h"

ResultSetting::ResultSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initConnection();
	initShow();
	//if (windowsindex == 1)
	//{
	//	ui.groupBox_2->hide();
	//}
	//if (windowsindex == 2)
	//{
	//	ui.groupBox->hide();
	//}
	m_GroupBox.addButton(ui.radioButton_left, 1);
	m_GroupBox.addButton(ui.radioButton_middle, 2);
	m_GroupBox.addButton(ui.radioButton_right, 3);
	ui.radioButton_middle->setChecked(1);
}

ResultSetting::~ResultSetting()
{
}

void ResultSetting::initConnection()
{
	connect(&m_GroupBox, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchMode(int, bool)));

	//editingFinished
	connect(ui.spinBox_head_alignment, &QSpinBox::editingFinished, this, [=]() {
		float value=ui.spinBox_head_alignment->text().toFloat();
		guoxuan::get_instance().set_head_alignment(value);});

	connect(ui.spinBox_head_alignment_2, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_head_alignment_2->text().toFloat();
		guoxuan::get_instance().set_head_alignment2(value); });

	connect(ui.spinBox_head_left_warning, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_head_left_warning->text().toFloat();
		guoxuan::get_instance().set_head_left_warning(value); });

	connect(ui.spinBox_head_middle_warning, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_head_middle_warning->text().toFloat();
		guoxuan::get_instance().set_head_middle_warning(value); });

	connect(ui.spinBox_head_right_warning, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_head_alignment->text().toFloat();
		guoxuan::get_instance().set_head_alignment(value); });


	//connect(ui.spinBox_end_left_warning, &QSpinBox::editingFinished, this, [=]() {
	//	float value = ui.spinBox_head_alignment->text().toFloat();
	//	guoxuan::get_instance().set_head_alignment(value); });

	connect(ui.spinBox_end_middle_warning, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_end_middle_warning->text().toFloat();
		guoxuan::get_instance().set_end_middle_warning(value); });

	//connect(ui.spinBox_end_right_warning, &QSpinBox::editingFinished, this, [=]() {
	//	float value = ui.spinBox_head_alignment->text().toFloat();
	//	guoxuan::get_instance().set_head_alignment(value); });


	connect(ui.spinBox_end_left_alignment, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_end_left_alignment->text().toFloat();
		guoxuan::get_instance().set_end_left_alignment(value); });

	connect(ui.spinBox_end_middle_alignment, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_end_middle_alignment->text().toFloat();
		guoxuan::get_instance().set_end_middle_alignment(value); });

	connect(ui.spinBox_end_right_alignment, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_end_right_alignment->text().toFloat();
		guoxuan::get_instance().set_end_right_alignment(value); });

	connect(ui.lineEdit_head_test, &QLineEdit::textChanged, this, [=]() {
		QString str = ui.lineEdit_head_test->text();
		guoxuan::get_instance().set_head_test(str); });
	
	
	connect(ui.spinBox_end_left_alignment_3, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_end_left_alignment_3->text().toFloat();
		guoxuan::get_instance().set_end_left_alignment_3(value); });

	connect(ui.spinBox_end_right_alignment_3, &QSpinBox::editingFinished, this, [=]() {
		float value = ui.spinBox_end_right_alignment_3->text().toFloat();
		guoxuan::get_instance().set_end_right_alignment_3(value); });



	connect(&guoxuan::get_instance(), &guoxuan::sendShow, this, [=](QString str) {
		ui.lineEdit_head_show->setText(str); });
}

void ResultSetting::initShow()
{
	guoxuan::get_instance().set_head_alignment(0.5);
	guoxuan::get_instance().set_head_alignment2(0.3);
	guoxuan::get_instance().set_head_left_warning(27.00);
	guoxuan::get_instance().set_head_middle_warning(199.00);
	guoxuan::get_instance().set_head_right_warning(27.00);

	guoxuan::get_instance().set_end_left_alignment(0.5);
	guoxuan::get_instance().set_end_right_alignment(0.5);
	guoxuan::get_instance().set_end_middle_alignment(0.5);	

	guoxuan::get_instance().set_end_left_alignment_3(0.3);
	guoxuan::get_instance().set_end_right_alignment_3(0.3);

	guoxuan::get_instance().set_end_middle_warning(199.00);

}

void ResultSetting::SwitchMode(int index, bool bchecked)
{
	if (bchecked)
	{
		guoxuan::get_instance().set_end_type(index);
		switch (index)
		{
		case 1:
			ui.radioButton_left->setChecked(1);	
			break;
		case 2:
			ui.radioButton_middle->setChecked(1);
			break;
		case 3:
			ui.radioButton_right->setChecked(1);
			break;
		}
	}
}
