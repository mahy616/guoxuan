#include "SoftInfoDialog.h"
#include "PublicParamter.h"

SoftInfoDialog::SoftInfoDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	ui.TitterBar->SetName(tr("About"));
	connect(ui.TitterBar, &DialogTitleBar::CloseSignal, this, [=]() {emit MyCloseEvent(); this->close(); });
	connect(ui.btn_IKnow, &QPushButton::clicked, this, [=]() {emit MyCloseEvent(); this->close(); });

	//…Ë÷√”Ô—‘◊÷ÃÂ
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

SoftInfoDialog::~SoftInfoDialog()
{}
