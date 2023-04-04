/********************************************************************************
** Form generated from reading UI file 'ResultsListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSLISTWIDGET_H
#define UI_RESULTSLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "UI/MyWidget/MyLogoButton.h"

QT_BEGIN_NAMESPACE

class Ui_ResultsListWidgetClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    MyLogoButton *btn_ControlVisiable;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ReSet;
    QWidget *widget_ControlVisual;

    void setupUi(QWidget *ResultsListWidgetClass)
    {
        if (ResultsListWidgetClass->objectName().isEmpty())
            ResultsListWidgetClass->setObjectName(QString::fromUtf8("ResultsListWidgetClass"));
        ResultsListWidgetClass->resize(400, 285);
        ResultsListWidgetClass->setStyleSheet(QString::fromUtf8("background-color:rgb(50,50,50);"));
        gridLayout = new QGridLayout(ResultsListWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_ControlVisiable = new MyLogoButton(ResultsListWidgetClass);
        btn_ControlVisiable->setObjectName(QString::fromUtf8("btn_ControlVisiable"));

        horizontalLayout->addWidget(btn_ControlVisiable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_ReSet = new QPushButton(ResultsListWidgetClass);
        btn_ReSet->setObjectName(QString::fromUtf8("btn_ReSet"));
        btn_ReSet->setMinimumSize(QSize(62, 28));
        btn_ReSet->setMaximumSize(QSize(62, 28));
        QFont font;
        font.setPointSize(8);
        btn_ReSet->setFont(font);
        btn_ReSet->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"	color:#999999;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background: #4A4A4A;\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #787878;\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resource/BtnReSet.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_ReSet->setIcon(icon);

        horizontalLayout->addWidget(btn_ReSet);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget_ControlVisual = new QWidget(ResultsListWidgetClass);
        widget_ControlVisual->setObjectName(QString::fromUtf8("widget_ControlVisual"));

        gridLayout->addWidget(widget_ControlVisual, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 8);

        retranslateUi(ResultsListWidgetClass);

        QMetaObject::connectSlotsByName(ResultsListWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ResultsListWidgetClass)
    {
        ResultsListWidgetClass->setWindowTitle(QCoreApplication::translate("ResultsListWidgetClass", "ResultsListWidget", nullptr));
        btn_ReSet->setText(QCoreApplication::translate("ResultsListWidgetClass", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultsListWidgetClass: public Ui_ResultsListWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSLISTWIDGET_H
