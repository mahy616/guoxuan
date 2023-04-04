/********************************************************************************
** Form generated from reading UI file 'TimeStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESTATISTICS_H
#define UI_TIMESTATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "UI/MyWidget/MyLogoButton.h"

QT_BEGIN_NAMESPACE

class Ui_TimeStatisticsClass
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    MyLogoButton *btn_ControlVisiable;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ReSet;
    QWidget *widget_ControlVisual;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_Average;
    QLabel *label_AverageTime;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QLabel *label_Max;
    QLabel *label_MaxTime;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QLabel *label_Min;
    QLabel *label_MinTime;
    QLabel *label_7;
    QFrame *frame_5;
    QGridLayout *gridLayout_6;
    QLabel *label_OverTime;
    QLabel *label_Overtimes;
    QLabel *label_4;

    void setupUi(QWidget *TimeStatisticsClass)
    {
        if (TimeStatisticsClass->objectName().isEmpty())
            TimeStatisticsClass->setObjectName(QString::fromUtf8("TimeStatisticsClass"));
        TimeStatisticsClass->resize(403, 227);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TimeStatisticsClass->sizePolicy().hasHeightForWidth());
        TimeStatisticsClass->setSizePolicy(sizePolicy);
        TimeStatisticsClass->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:rgb(60,60,60);\n"
"	border-radius:12;\n"
"	border:2px solid #4F4F4F;\n"
"}\n"
"\n"
"QFrame#frame{\n"
"	background-color:rgb(50,50,50);\n"
"	border:none;\n"
"	border-radius:0;\n"
"}\n"
"\n"
"QLabel{\n"
"	background: \"transparent\";\n"
"	border:none;\n"
"    color:white\n"
"}"));
        gridLayout_2 = new QGridLayout(TimeStatisticsClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(TimeStatisticsClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_ControlVisiable = new MyLogoButton(frame);
        btn_ControlVisiable->setObjectName(QString::fromUtf8("btn_ControlVisiable"));
        btn_ControlVisiable->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(btn_ControlVisiable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_ReSet = new QPushButton(frame);
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


        gridLayout_7->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget_ControlVisual = new QWidget(frame);
        widget_ControlVisual->setObjectName(QString::fromUtf8("widget_ControlVisual"));
        gridLayout = new QGridLayout(widget_ControlVisual);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_2 = new QFrame(widget_ControlVisual);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font:10pt;\n"
"color:#999999;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 1, 1, 1, 1);

        label_Average = new QLabel(frame_2);
        label_Average->setObjectName(QString::fromUtf8("label_Average"));
        label_Average->setMinimumSize(QSize(48, 48));
        label_Average->setMaximumSize(QSize(48, 48));
        label_Average->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/TimeStatisticAverage.png\");"));

        gridLayout_3->addWidget(label_Average, 0, 0, 2, 1);

        label_AverageTime = new QLabel(frame_2);
        label_AverageTime->setObjectName(QString::fromUtf8("label_AverageTime"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_AverageTime->setFont(font2);
        label_AverageTime->setStyleSheet(QString::fromUtf8("font:13pt;"));
        label_AverageTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_AverageTime, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(frame_2);

        frame_3 = new QFrame(widget_ControlVisual);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_Max = new QLabel(frame_3);
        label_Max->setObjectName(QString::fromUtf8("label_Max"));
        label_Max->setMinimumSize(QSize(48, 48));
        label_Max->setMaximumSize(QSize(48, 48));
        label_Max->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/TimeStatisticMax.png\");"));

        gridLayout_4->addWidget(label_Max, 0, 0, 2, 1);

        label_MaxTime = new QLabel(frame_3);
        label_MaxTime->setObjectName(QString::fromUtf8("label_MaxTime"));
        label_MaxTime->setFont(font2);
        label_MaxTime->setStyleSheet(QString::fromUtf8("font:13pt;"));
        label_MaxTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_MaxTime, 0, 1, 1, 1);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("font:10pt;\n"
"color:#999999;"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_5, 1, 1, 1, 1);


        horizontalLayout_3->addWidget(frame_3);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_4 = new QFrame(widget_ControlVisual);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_Min = new QLabel(frame_4);
        label_Min->setObjectName(QString::fromUtf8("label_Min"));
        label_Min->setMinimumSize(QSize(48, 48));
        label_Min->setMaximumSize(QSize(48, 48));
        label_Min->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/TimeStatisticMin.png\");"));

        gridLayout_5->addWidget(label_Min, 0, 0, 2, 1);

        label_MinTime = new QLabel(frame_4);
        label_MinTime->setObjectName(QString::fromUtf8("label_MinTime"));
        label_MinTime->setFont(font2);
        label_MinTime->setStyleSheet(QString::fromUtf8("font:13pt;"));
        label_MinTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_MinTime, 0, 1, 1, 1);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("font:10pt;\n"
"color:#999999;"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_7, 1, 1, 1, 1);


        horizontalLayout_2->addWidget(frame_4);

        frame_5 = new QFrame(widget_ControlVisual);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_OverTime = new QLabel(frame_5);
        label_OverTime->setObjectName(QString::fromUtf8("label_OverTime"));
        label_OverTime->setMinimumSize(QSize(48, 48));
        label_OverTime->setMaximumSize(QSize(48, 48));
        label_OverTime->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/TimeStatisticOverTimes.png\");"));

        gridLayout_6->addWidget(label_OverTime, 0, 0, 2, 1);

        label_Overtimes = new QLabel(frame_5);
        label_Overtimes->setObjectName(QString::fromUtf8("label_Overtimes"));
        label_Overtimes->setFont(font2);
        label_Overtimes->setStyleSheet(QString::fromUtf8("font:13pt;"));
        label_Overtimes->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_Overtimes, 0, 1, 1, 1);

        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font:10pt;\n"
"color:#999999;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_4, 1, 1, 1, 1);


        horizontalLayout_2->addWidget(frame_5);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_7->addWidget(widget_ControlVisual, 1, 0, 1, 1);

        gridLayout_7->setRowStretch(0, 1);
        gridLayout_7->setRowStretch(1, 6);

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(TimeStatisticsClass);

        QMetaObject::connectSlotsByName(TimeStatisticsClass);
    } // setupUi

    void retranslateUi(QWidget *TimeStatisticsClass)
    {
        TimeStatisticsClass->setWindowTitle(QCoreApplication::translate("TimeStatisticsClass", "TimeStatistics", nullptr));
        btn_ReSet->setText(QCoreApplication::translate("TimeStatisticsClass", "Reset", nullptr));
        label_3->setText(QCoreApplication::translate("TimeStatisticsClass", "Average", nullptr));
        label_Average->setText(QString());
        label_AverageTime->setText(QCoreApplication::translate("TimeStatisticsClass", " 0", nullptr));
        label_Max->setText(QString());
        label_MaxTime->setText(QCoreApplication::translate("TimeStatisticsClass", " 0", nullptr));
        label_5->setText(QCoreApplication::translate("TimeStatisticsClass", "Max", nullptr));
        label_Min->setText(QString());
        label_MinTime->setText(QCoreApplication::translate("TimeStatisticsClass", " 0", nullptr));
        label_7->setText(QCoreApplication::translate("TimeStatisticsClass", "Min", nullptr));
        label_OverTime->setText(QString());
        label_Overtimes->setText(QCoreApplication::translate("TimeStatisticsClass", " 0", nullptr));
        label_4->setText(QCoreApplication::translate("TimeStatisticsClass", "Timeout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeStatisticsClass: public Ui_TimeStatisticsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESTATISTICS_H
