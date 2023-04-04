/********************************************************************************
** Form generated from reading UI file 'DataStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASTATISTICS_H
#define UI_DATASTATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <UI/MyWidget/mylogobutton.h>

QT_BEGIN_NAMESPACE

class Ui_DataStatisticsClass
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    MyLogoButton *btn_ControlVisiable;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_ReSet;
    QWidget *widget_ControlVisual;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Line;
    QLabel *label_logo;
    QLabel *label_TotalNums;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QLabel *label_ok;
    QLabel *label_4;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QLabel *label_NG;
    QLabel *label_6;
    QFrame *frame_5;
    QGridLayout *gridLayout_4;
    QLabel *label_rate;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_LabelToLeft;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btn_LabelToRight;

    void setupUi(QWidget *DataStatisticsClass)
    {
        if (DataStatisticsClass->objectName().isEmpty())
            DataStatisticsClass->setObjectName(QString::fromUtf8("DataStatisticsClass"));
        DataStatisticsClass->resize(409, 291);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DataStatisticsClass->sizePolicy().hasHeightForWidth());
        DataStatisticsClass->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(DataStatisticsClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(DataStatisticsClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color:rgb(50,50,50);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(9, 9, 9, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_ControlVisiable = new MyLogoButton(frame);
        btn_ControlVisiable->setObjectName(QString::fromUtf8("btn_ControlVisiable"));

        horizontalLayout->addWidget(btn_ControlVisiable);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

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
        gridLayout_6 = new QGridLayout(widget_ControlVisual);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget_ControlVisual);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:rgb(60,60,60);\n"
"	border-radius:8;\n"
"	border:2px solid #4F4F4F;\n"
"}\n"
"QLabel{\n"
"	background: \"transparent\";\n"
"	border:none;\n"
"    color:white\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:#999999;\n"
"font:13pt;"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_Line = new QLabel(frame_2);
        label_Line->setObjectName(QString::fromUtf8("label_Line"));
        label_Line->setMinimumSize(QSize(120, 50));
        label_Line->setMaximumSize(QSize(120, 50));
        label_Line->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/DataStatisticsLine.png\");"));

        gridLayout_3->addWidget(label_Line, 0, 3, 2, 1);

        label_logo = new QLabel(frame_2);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMinimumSize(QSize(50, 50));
        label_logo->setMaximumSize(QSize(50, 50));
        label_logo->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/DataStatisticLogo.png\");"));

        gridLayout_3->addWidget(label_logo, 0, 0, 2, 1);

        label_TotalNums = new QLabel(frame_2);
        label_TotalNums->setObjectName(QString::fromUtf8("label_TotalNums"));
        sizePolicy.setHeightForWidth(label_TotalNums->sizePolicy().hasHeightForWidth());
        label_TotalNums->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_TotalNums->setFont(font2);
        label_TotalNums->setStyleSheet(QString::fromUtf8("color:#F0CD5E;\n"
"font:13pt;\n"
"font-weight:bold;"));
        label_TotalNums->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_TotalNums, 0, 1, 1, 1);


        gridLayout_6->addWidget(frame_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_3 = new QFrame(widget_ControlVisual);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:rgb(60,60,60);\n"
"	border-radius:8;\n"
"	font:12pt;\n"
"	border:2px solid #4F4F4F;\n"
"}\n"
"QLabel{\n"
"	background: \"transparent\";\n"
"	border:none;\n"
"    color:white\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_ok = new QLabel(frame_3);
        label_ok->setObjectName(QString::fromUtf8("label_ok"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(13);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_ok->setFont(font3);
        label_ok->setStyleSheet(QString::fromUtf8("color:#74D1CE;\n"
"font:13pt;"));
        label_ok->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ok, 0, 0, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color:#999999;"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(widget_ControlVisual);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:rgb(60,60,60);\n"
"	border-radius:8;\n"
"	font:12pt;\n"
"	border:2px solid #4F4F4F;\n"
"}\n"
"QLabel{\n"
"	background: \"transparent\";\n"
"	border:none;\n"
"    color:white\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_NG = new QLabel(frame_4);
        label_NG->setObjectName(QString::fromUtf8("label_NG"));
        label_NG->setFont(font3);
        label_NG->setStyleSheet(QString::fromUtf8("color:#E3726A;\n"
"font:13pt;"));
        label_NG->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_NG, 0, 0, 1, 1);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("color:#999999;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_4);

        frame_5 = new QFrame(widget_ControlVisual);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color:rgb(60,60,60);\n"
"	border-radius:8;\n"
"	font:12pt;\n"
"	border:2px solid #4F4F4F;\n"
"}\n"
"QLabel{\n"
"	background: \"transparent\";\n"
"	border:none;\n"
"    color:white\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_rate = new QLabel(frame_5);
        label_rate->setObjectName(QString::fromUtf8("label_rate"));
        label_rate->setFont(font3);
        label_rate->setStyleSheet(QString::fromUtf8("color:#74D1CE;\n"
"font:13pt;"));
        label_rate->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_rate, 0, 0, 1, 1);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Agency FB"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("color:#999999;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_5);


        gridLayout_6->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_LabelToLeft = new QPushButton(widget_ControlVisual);
        btn_LabelToLeft->setObjectName(QString::fromUtf8("btn_LabelToLeft"));
        btn_LabelToLeft->setMinimumSize(QSize(20, 33));
        btn_LabelToLeft->setMaximumSize(QSize(20, 33));
        btn_LabelToLeft->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:rgb(60,60,60);\n"
"	border-image:url(\":/DynamicWidget/Resource/DataStatisticToLeft.png\");\n"
"	border:none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(40,40,40);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(30,30,30);\n"
"}"));

        horizontalLayout_2->addWidget(btn_LabelToLeft);

        scrollArea = new QScrollArea(widget_ControlVisual);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 50));
        scrollArea->setMaximumSize(QSize(16777215, 51));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea\n"
"{\n"
"border: 0px solid;\n"
"background-color: rgb(50,50,50);\n"
"}\n"
"QScrollBar\n"
"{\n"
"border: none;\n"
"background: #f5f5f7;\n"
"width: 5px;\n"
"margin: 0px 0 0px 0;\n"
"}\n"
"QScrollBar::handle\n"
"{\n"
"background: Gainsboro;\n"
"min-height: 20px;\n"
"border-radius: 2px;\n"
"border: none;\n"
"}\n"
"QScrollBar::add-line\n"
"{\n"
"border: 0px solid grey;\n"
"background: #32CC99;\n"
"height: 0px;\n"
"subcontrol-position: bottom;\n"
"subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line\n"
"{\n"
"border: 0px solid grey;\n"
"background: #32CC99;\n"
"height: 0px;\n"
"subcontrol-position: top;\n"
"subcontrol-origin: margin;\n"
"}\n"
""));
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 335, 51));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 50));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 51));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        btn_LabelToRight = new QPushButton(widget_ControlVisual);
        btn_LabelToRight->setObjectName(QString::fromUtf8("btn_LabelToRight"));
        btn_LabelToRight->setMinimumSize(QSize(20, 33));
        btn_LabelToRight->setMaximumSize(QSize(20, 33));
        btn_LabelToRight->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:rgb(60,60,60);\n"
"	border-image:url(\":/DynamicWidget/Resource/DataStatisticToRight.png\");\n"
"	border:none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(40,40,40);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(30,30,30);\n"
"}"));

        horizontalLayout_2->addWidget(btn_LabelToRight);


        gridLayout_6->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_6->setRowStretch(0, 1);
        gridLayout_6->setRowStretch(1, 1);
        gridLayout_6->setRowStretch(2, 1);

        gridLayout_7->addWidget(widget_ControlVisual, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(DataStatisticsClass);

        QMetaObject::connectSlotsByName(DataStatisticsClass);
    } // setupUi

    void retranslateUi(QWidget *DataStatisticsClass)
    {
        DataStatisticsClass->setWindowTitle(QCoreApplication::translate("DataStatisticsClass", "DataStatistics", nullptr));
        btn_ReSet->setText(QCoreApplication::translate("DataStatisticsClass", "Reset", nullptr));
        label_3->setText(QCoreApplication::translate("DataStatisticsClass", "Total", nullptr));
        label_Line->setText(QString());
        label_logo->setText(QString());
        label_TotalNums->setText(QCoreApplication::translate("DataStatisticsClass", "0", nullptr));
        label_ok->setText(QCoreApplication::translate("DataStatisticsClass", "0", nullptr));
        label_4->setText(QCoreApplication::translate("DataStatisticsClass", "OK", nullptr));
        label_NG->setText(QCoreApplication::translate("DataStatisticsClass", "0", nullptr));
        label_6->setText(QCoreApplication::translate("DataStatisticsClass", "NG", nullptr));
        label_rate->setText(QCoreApplication::translate("DataStatisticsClass", "0", nullptr));
        label_8->setText(QCoreApplication::translate("DataStatisticsClass", "Yield(%)", nullptr));
        btn_LabelToLeft->setText(QString());
        btn_LabelToRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataStatisticsClass: public Ui_DataStatisticsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASTATISTICS_H
