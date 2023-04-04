/********************************************************************************
** Form generated from reading UI file 'PerformanceMonitorTitle.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFORMANCEMONITORTITLE_H
#define UI_PERFORMANCEMONITORTITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "UI/MyWidget/MyLogoButton.h"

QT_BEGIN_NAMESPACE

class Ui_PerformanceMonitorTitleClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    MyLogoButton *btn_ControlVisiable;

    void setupUi(QWidget *PerformanceMonitorTitleClass)
    {
        if (PerformanceMonitorTitleClass->objectName().isEmpty())
            PerformanceMonitorTitleClass->setObjectName(QString::fromUtf8("PerformanceMonitorTitleClass"));
        PerformanceMonitorTitleClass->resize(330, 30);
        PerformanceMonitorTitleClass->setMaximumSize(QSize(16777215, 30));
        PerformanceMonitorTitleClass->setStyleSheet(QString::fromUtf8("background-color:rgb(50,50,50);\n"
"color:white;\n"
""));
        gridLayout = new QGridLayout(PerformanceMonitorTitleClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(PerformanceMonitorTitleClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 30));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(50,50,50);\n"
"color:white;\n"
"border-bottom:1px solid #4F4F4F;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, 5, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color:rgb(50,50,50);\n"
"color:white;\n"
""));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_ControlVisiable = new MyLogoButton(widget);
        btn_ControlVisiable->setObjectName(QString::fromUtf8("btn_ControlVisiable"));
        btn_ControlVisiable->setMinimumSize(QSize(70, 28));
        btn_ControlVisiable->setMaximumSize(QSize(70, 28));
        btn_ControlVisiable->setStyleSheet(QString::fromUtf8("font:10px;"));

        horizontalLayout->addWidget(btn_ControlVisiable);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(PerformanceMonitorTitleClass);

        QMetaObject::connectSlotsByName(PerformanceMonitorTitleClass);
    } // setupUi

    void retranslateUi(QWidget *PerformanceMonitorTitleClass)
    {
        PerformanceMonitorTitleClass->setWindowTitle(QCoreApplication::translate("PerformanceMonitorTitleClass", "PerformanceMonitorTitle", nullptr));
        label->setText(QCoreApplication::translate("PerformanceMonitorTitleClass", "Performance Monitoring", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PerformanceMonitorTitleClass: public Ui_PerformanceMonitorTitleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFORMANCEMONITORTITLE_H
