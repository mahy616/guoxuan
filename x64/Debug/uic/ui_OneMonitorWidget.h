/********************************************************************************
** Form generated from reading UI file 'OneMonitorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEMONITORWIDGET_H
#define UI_ONEMONITORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OneMonitorWidgetClass
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ControlVisiable;
    QLabel *label_GPUID;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *Label_PerformanceWord;
    QLabel *label_Line1;
    QLabel *label_2;
    QLabel *Label_TemperatureWord;
    QLabel *label_Line2;
    QLabel *label_3;
    QLabel *Label_UtilizationWord;
    QLabel *label_Line3;
    QLabel *label_5;
    QLabel *Label_PowerWord;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QProgressBar *progressBar_MemoryBar;
    QLabel *Label_MemoryNumWord;

    void setupUi(QWidget *OneMonitorWidgetClass)
    {
        if (OneMonitorWidgetClass->objectName().isEmpty())
            OneMonitorWidgetClass->setObjectName(QString::fromUtf8("OneMonitorWidgetClass"));
        OneMonitorWidgetClass->resize(524, 131);
        OneMonitorWidgetClass->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"background-color:rgb(50,50,50);\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"	background-color:rgb(65,65,65);\n"
"	border-radius:8;\n"
"	border:2px solid #4F4F4F;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	color:white;\n"
"	font-family:KaiTi;\n"
"	background: \"transparent\";\n"
"	border:none;\n"
"}"));
        gridLayout = new QGridLayout(OneMonitorWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(OneMonitorWidgetClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 1, 5, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_ControlVisiable = new QPushButton(frame);
        btn_ControlVisiable->setObjectName(QString::fromUtf8("btn_ControlVisiable"));
        btn_ControlVisiable->setMaximumSize(QSize(20, 18));
        btn_ControlVisiable->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image:url(\":/DynamicWidget/Resource/GPU_Open.png\");\n"
"	border:none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(10,10,10);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(35,35,35);\n"
"}"));

        horizontalLayout->addWidget(btn_ControlVisiable);

        label_GPUID = new QLabel(frame);
        label_GPUID->setObjectName(QString::fromUtf8("label_GPUID"));
        QFont font;
        font.setFamily(QString::fromUtf8("KaiTi"));
        font.setPointSize(8);
        label_GPUID->setFont(font);

        horizontalLayout->addWidget(label_GPUID);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("KaiTi"));
        font1.setPointSize(7);
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        Label_PerformanceWord = new QLabel(widget);
        Label_PerformanceWord->setObjectName(QString::fromUtf8("Label_PerformanceWord"));
        Label_PerformanceWord->setFont(font);

        horizontalLayout_2->addWidget(Label_PerformanceWord);

        label_Line1 = new QLabel(widget);
        label_Line1->setObjectName(QString::fromUtf8("label_Line1"));
        label_Line1->setMinimumSize(QSize(2, 0));
        label_Line1->setMaximumSize(QSize(2, 16777215));
        label_Line1->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/ToolBarSegLine.png\");"));

        horizontalLayout_2->addWidget(label_Line1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        Label_TemperatureWord = new QLabel(widget);
        Label_TemperatureWord->setObjectName(QString::fromUtf8("Label_TemperatureWord"));
        Label_TemperatureWord->setFont(font);

        horizontalLayout_2->addWidget(Label_TemperatureWord);

        label_Line2 = new QLabel(widget);
        label_Line2->setObjectName(QString::fromUtf8("label_Line2"));
        label_Line2->setMinimumSize(QSize(2, 0));
        label_Line2->setMaximumSize(QSize(2, 16777215));
        label_Line2->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/ToolBarSegLine.png\");"));

        horizontalLayout_2->addWidget(label_Line2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        Label_UtilizationWord = new QLabel(widget);
        Label_UtilizationWord->setObjectName(QString::fromUtf8("Label_UtilizationWord"));
        Label_UtilizationWord->setFont(font);

        horizontalLayout_2->addWidget(Label_UtilizationWord);

        label_Line3 = new QLabel(widget);
        label_Line3->setObjectName(QString::fromUtf8("label_Line3"));
        label_Line3->setMinimumSize(QSize(2, 0));
        label_Line3->setMaximumSize(QSize(2, 16777215));
        label_Line3->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/ToolBarSegLine.png\");"));

        horizontalLayout_2->addWidget(label_Line3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        Label_PowerWord = new QLabel(widget);
        Label_PowerWord->setObjectName(QString::fromUtf8("Label_PowerWord"));
        Label_PowerWord->setFont(font);

        horizontalLayout_2->addWidget(Label_PowerWord);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_3->addWidget(label_7);

        progressBar_MemoryBar = new QProgressBar(widget);
        progressBar_MemoryBar->setObjectName(QString::fromUtf8("progressBar_MemoryBar"));
        progressBar_MemoryBar->setMinimumSize(QSize(0, 12));
        progressBar_MemoryBar->setMaximumSize(QSize(16777215, 10));
        QFont font2;
        font2.setPointSize(8);
        progressBar_MemoryBar->setFont(font2);
        progressBar_MemoryBar->setStyleSheet(QString::fromUtf8("QProgressBar\n"
"{\n"
"		color:yellow;\n"
"		text-align: center;\n"
"		background: rgba(248,248,255,180);\n"
"		border-radius: 6px;\n"
"}\n"
"QProgressBar::chunk:enabled \n"
"{\n"
"		border-radius: 6px; \n"
"		background: qlineargradient(x1:0, y1:0, x2:1, y2:0 ,stop:0 #00AB00, stop:1 #BF0000);\n"
"}"));
        progressBar_MemoryBar->setValue(24);

        horizontalLayout_3->addWidget(progressBar_MemoryBar);

        Label_MemoryNumWord = new QLabel(widget);
        Label_MemoryNumWord->setObjectName(QString::fromUtf8("Label_MemoryNumWord"));
        Label_MemoryNumWord->setFont(font);

        horizontalLayout_3->addWidget(Label_MemoryNumWord);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 6);

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(OneMonitorWidgetClass);

        QMetaObject::connectSlotsByName(OneMonitorWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *OneMonitorWidgetClass)
    {
        OneMonitorWidgetClass->setWindowTitle(QCoreApplication::translate("OneMonitorWidgetClass", "OneMonitorWidget", nullptr));
        btn_ControlVisiable->setText(QString());
        label_GPUID->setText(QCoreApplication::translate("OneMonitorWidgetClass", "GPU1", nullptr));
        label->setText(QCoreApplication::translate("OneMonitorWidgetClass", "Performance:", nullptr));
        Label_PerformanceWord->setText(QCoreApplication::translate("OneMonitorWidgetClass", "UnKonw", nullptr));
        label_Line1->setText(QString());
        label_2->setText(QCoreApplication::translate("OneMonitorWidgetClass", "Temperature:", nullptr));
        Label_TemperatureWord->setText(QCoreApplication::translate("OneMonitorWidgetClass", "UnKonw", nullptr));
        label_Line2->setText(QString());
        label_3->setText(QCoreApplication::translate("OneMonitorWidgetClass", "Utilization:", nullptr));
        Label_UtilizationWord->setText(QCoreApplication::translate("OneMonitorWidgetClass", "UnKonw", nullptr));
        label_Line3->setText(QString());
        label_5->setText(QCoreApplication::translate("OneMonitorWidgetClass", "Power:", nullptr));
        Label_PowerWord->setText(QCoreApplication::translate("OneMonitorWidgetClass", "UnKonw", nullptr));
        label_7->setText(QCoreApplication::translate("OneMonitorWidgetClass", "GPU Memory", nullptr));
        Label_MemoryNumWord->setText(QCoreApplication::translate("OneMonitorWidgetClass", "UnKonw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OneMonitorWidgetClass: public Ui_OneMonitorWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEMONITORWIDGET_H
