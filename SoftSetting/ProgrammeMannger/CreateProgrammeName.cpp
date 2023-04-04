#include "CreateProgrammeName.h"
#include <QMessageBox>
#include <QFileInfo>
#include <QFile>

CreateProgrammeName::CreateProgrammeName(QStringList CurrentProgrammeName, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.btn_Create, &QPushButton::clicked, this, [=]()
	{
		if (ui.lineEdit_ProName->text().size() == 0)
		{
			QMessageBox::information(NULL, tr("Tips"), tr("Recipe name is empty!")); return;
		}
		for (int i = 0; i < CurrentProgrammeName.size(); i++)
		{
			if (ui.lineEdit_ProName->text() == CurrentProgrammeName.at(i))
			{
				QMessageBox::information(NULL, tr("Tips"), tr("Recipe already exists!")); return;
			}
		}

		QFile file(".//config//programme//" + ui.lineEdit_ProName->text() + ".json");
		if (file.exists())
		{
			QMessageBox::information(NULL, tr("Tips"), tr("Recipe already exists!")); return;
		}
		emit CreateProName(ui.lineEdit_ProName->text());
		//this->close();
	});
}

CreateProgrammeName::~CreateProgrammeName()
{}
