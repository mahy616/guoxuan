#include "SetingItem.h"

SetingItem::SetingItem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

SetingItem::~SetingItem()
{}

void SetingItem::SetMyWidget(QString IconName, QString NameText)
{
	QString iconRoad = QString("background:transparent;image: url(:/DynamicWidget/Resource/%1);").arg(IconName);
	ui.label_Icon->setStyleSheet(iconRoad);
	ui.label_Text->setText(NameText);
}

QString SetingItem::GetName()
{
	return ui.label_Text->text();
}
