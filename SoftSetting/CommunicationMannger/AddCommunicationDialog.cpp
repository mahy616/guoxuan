#include "AddCommunicationDialog.h"

AddCommunicationDialog::AddCommunicationDialog(int defaultIndex, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit_CommunicateName->setText(tr("Communication%1").arg(defaultIndex));
	ui.comboBox_CommunicateType->addItem(tr("Ethernet Port"));
	ui.comboBox_CommunicateType->addItem(tr("Serial Port"));
	ui.comboBox_CommunicateType->addItem(tr("Mitsubishi MC"));

	connect(ui.btn_Cancel, &QPushButton::clicked, this, [=]()
	{
		this->close();
	});
	connect(ui.btn_Determine, &QPushButton::clicked, this, [=]()
	{
		QString SendTypeStr;
		switch (ui.comboBox_CommunicateType->currentIndex())
		{
		case 0:
			SendTypeStr = "Ethernet Port";
			break;
		case 1:
			SendTypeStr = "Serial Port";
			break;
		case 2:
			SendTypeStr = "Mitsubishi MC";
			break;
		default:
			break;
		}
		emit SendAddCommunicate(ui.lineEdit_CommunicateName->text(), SendTypeStr);
		this->close();
	});
}

AddCommunicationDialog::~AddCommunicationDialog()
{}
