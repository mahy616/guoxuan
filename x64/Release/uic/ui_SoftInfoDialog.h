/********************************************************************************
** Form generated from reading UI file 'SoftInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTINFODIALOG_H
#define UI_SOFTINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "UI/MyWidget/dialogtitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_SoftInfoDialogClass
{
public:
    QGridLayout *gridLayout;
    DialogTitleBar *TitterBar;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_IKnow;

    void setupUi(QWidget *SoftInfoDialogClass)
    {
        if (SoftInfoDialogClass->objectName().isEmpty())
            SoftInfoDialogClass->setObjectName(QString::fromUtf8("SoftInfoDialogClass"));
        SoftInfoDialogClass->resize(562, 263);
        SoftInfoDialogClass->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(SoftInfoDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TitterBar = new DialogTitleBar(SoftInfoDialogClass);
        TitterBar->setObjectName(QString::fromUtf8("TitterBar"));
        TitterBar->setMinimumSize(QSize(0, 40));
        TitterBar->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(TitterBar, 0, 0, 1, 1);

        widget_2 = new QWidget(SoftInfoDialogClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("\n"
"QWidget\n"
"{\n"
"	background:\"transparent\";\n"
"}\n"
"\n"
"QWidget#widget_2\n"
"{\n"
"background: #323232;\n"
"border-bottom-left-radius:8px;\n"
"border-bottom-right-radius:8px;\n"
"box-shadow: inset 0px 1px 0px rgba(255, 255, 255, 0.25), inset 0px -1px 0px rgba(0, 0, 0, 0.25);\n"
"}"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("Albertus Extra Bold"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"line-height: 23px;\n"
"display: flex;\n"
"align-items: center;\n"
"text-align: center;\n"
"color: #FFFFFF;"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 35));
        label_2->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: center;\n"
"\n"
""));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"font-style: normal;\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: center;\n"
"\n"
"color: #FFFFFF;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_IKnow = new QPushButton(widget_2);
        btn_IKnow->setObjectName(QString::fromUtf8("btn_IKnow"));
        btn_IKnow->setMinimumSize(QSize(100, 35));
        btn_IKnow->setMaximumSize(QSize(100, 35));
        btn_IKnow->setSizeIncrement(QSize(103, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        btn_IKnow->setFont(font1);
        btn_IKnow->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:white;\n"
"	background: #3A71DE;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:white;\n"
"	background: #274B94;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"color:white;\n"
"	background: #172D59;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout->addWidget(btn_IKnow);


        gridLayout_2->addLayout(horizontalLayout, 3, 0, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(SoftInfoDialogClass);

        QMetaObject::connectSlotsByName(SoftInfoDialogClass);
    } // setupUi

    void retranslateUi(QWidget *SoftInfoDialogClass)
    {
        SoftInfoDialogClass->setWindowTitle(QCoreApplication::translate("SoftInfoDialogClass", "SoftInfoDialog", nullptr));
        label->setText(QCoreApplication::translate("SoftInfoDialogClass", "SMore ViMo Vision Application Software ViLab", nullptr));
        label_2->setText(QCoreApplication::translate("SoftInfoDialogClass", "Version: V1.0.1", nullptr));
        label_3->setText(QCoreApplication::translate("SoftInfoDialogClass", "Copyright \302\251 2022 SmartMore Corporation Limited. All Rights Reserved.", nullptr));
        btn_IKnow->setText(QCoreApplication::translate("SoftInfoDialogClass", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoftInfoDialogClass: public Ui_SoftInfoDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTINFODIALOG_H
