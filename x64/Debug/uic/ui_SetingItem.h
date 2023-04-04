/********************************************************************************
** Form generated from reading UI file 'SetingItem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETINGITEM_H
#define UI_SETINGITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetingItemClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Icon;
    QLabel *label_Text;

    void setupUi(QWidget *SetingItemClass)
    {
        if (SetingItemClass->objectName().isEmpty())
            SetingItemClass->setObjectName(QString::fromUtf8("SetingItemClass"));
        SetingItemClass->resize(210, 47);
        SetingItemClass->setStyleSheet(QString::fromUtf8("\n"
"QWidget{\n"
"color:#E0E0E0;\n"
"background:transparent;\n"
"border-top-left-radius:8;\n"
"border-top-right-radius:8;\n"
"}\n"
"QWidget:hover\n"
"{\n"
"	background-color:rgb(50,50,50);\n"
"}\n"
"QWidget:pressed\n"
"{\n"
"	background-color:rgb(100,100,100);\n"
"}\n"
"QLabel{\n"
"color:#999999;\n"
"}\n"
"QLabel:hover\n"
"{\n"
"	background-color:rgb(50,50,50);\n"
"}\n"
"QLabel:pressed\n"
"{\n"
"	background-color:rgb(100,100,100);\n"
"}\n"
""));
        gridLayout = new QGridLayout(SetingItemClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Icon = new QLabel(SetingItemClass);
        label_Icon->setObjectName(QString::fromUtf8("label_Icon"));
        label_Icon->setMaximumSize(QSize(30, 30));
        label_Icon->setStyleSheet(QString::fromUtf8("background:transparent;"));

        horizontalLayout->addWidget(label_Icon);

        label_Text = new QLabel(SetingItemClass);
        label_Text->setObjectName(QString::fromUtf8("label_Text"));
        label_Text->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:#E3E3E3;"));
        label_Text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_Text);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(SetingItemClass);

        QMetaObject::connectSlotsByName(SetingItemClass);
    } // setupUi

    void retranslateUi(QWidget *SetingItemClass)
    {
        SetingItemClass->setWindowTitle(QCoreApplication::translate("SetingItemClass", "SetingItem", nullptr));
        label_Icon->setText(QString());
        label_Text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetingItemClass: public Ui_SetingItemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETINGITEM_H
