/********************************************************************************
** Form generated from reading UI file 'SoftSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTSETTING_H
#define UI_SOFTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoftSettingClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_Icon;
    QStackedWidget *stackedWidget_Widget;

    void setupUi(QWidget *SoftSettingClass)
    {
        if (SoftSettingClass->objectName().isEmpty())
            SoftSettingClass->setObjectName(QString::fromUtf8("SoftSettingClass"));
        SoftSettingClass->resize(1215, 828);
        SoftSettingClass->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));
        gridLayout = new QGridLayout(SoftSettingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget_Icon = new QListWidget(SoftSettingClass);
        listWidget_Icon->setObjectName(QString::fromUtf8("listWidget_Icon"));
        listWidget_Icon->setStyleSheet(QString::fromUtf8("\n"
"QListWidget\n"
"{\n"
"	color:white;\n"
"    background-color: rgb(85, 85, 85);\n"
"    border:0px;\n"
"    outline:0px;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"    background-color: rgb(85, 85, 85);    \n"
"}\n"
"QListWidget::item:hover\n"
"{\n"
"    background-color: rgb(65, 65, 65);\n"
"}\n"
"QListWidget::item::selected:active\n"
"{ \n"
"   background-color: rgb(50, 50, 50);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color: rgb(50, 50, 50);\n"
"}\n"
""));

        horizontalLayout->addWidget(listWidget_Icon);

        stackedWidget_Widget = new QStackedWidget(SoftSettingClass);
        stackedWidget_Widget->setObjectName(QString::fromUtf8("stackedWidget_Widget"));
        stackedWidget_Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

        horizontalLayout->addWidget(stackedWidget_Widget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 9);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(SoftSettingClass);

        QMetaObject::connectSlotsByName(SoftSettingClass);
    } // setupUi

    void retranslateUi(QWidget *SoftSettingClass)
    {
        SoftSettingClass->setWindowTitle(QCoreApplication::translate("SoftSettingClass", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoftSettingClass: public Ui_SoftSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTSETTING_H
