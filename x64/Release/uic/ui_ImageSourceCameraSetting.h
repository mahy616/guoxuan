/********************************************************************************
** Form generated from reading UI file 'ImageSourceCameraSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESOURCECAMERASETTING_H
#define UI_IMAGESOURCECAMERASETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "UI/MyWidget/mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_ImageSourceCameraSetting
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEnumCamera;
    QComboBox *comboBoxCameras;
    QPushButton *btnOpenCamera;
    QPushButton *btnCloseCamera;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditStatistic;
    MyLabel *ShowWidget;
    QGridLayout *gridLayout_3;
    QPushButton *btnStop;
    QPushButton *btnSingleShot;
    QPushButton *btnContinuous;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_12;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *horizontalSliderExposure;
    QLineEdit *lineEditExposure;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *horizontalSliderGain;
    QLineEdit *lineEditGain;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBoxPixelFormat;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *comboBoxTriggerMode;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_free;
    QRadioButton *radioButton_hard;
    QRadioButton *radioButton_soft;
    QWidget *widget_Trigger;
    QGridLayout *gridLayout_5;
    QLabel *label_TriggerLabel;
    QGroupBox *groupBox_Trigger;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QComboBox *comboBoxTriggerSource;
    QWidget *widget_SoftTrigger;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QPushButton *btnSoftwareTrigger;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *lineEdit_TriggerStr;
    QPushButton *btn_ConnectCommunicate;
    QLabel *label_SoftTriggerState;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ImageSourceCameraSetting)
    {
        if (ImageSourceCameraSetting->objectName().isEmpty())
            ImageSourceCameraSetting->setObjectName(QString::fromUtf8("ImageSourceCameraSetting"));
        ImageSourceCameraSetting->resize(1091, 660);
        ImageSourceCameraSetting->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size: 11pt;\n"
"background: #323232;"));
        gridLayout_2 = new QGridLayout(ImageSourceCameraSetting);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnEnumCamera = new QPushButton(ImageSourceCameraSetting);
        btnEnumCamera->setObjectName(QString::fromUtf8("btnEnumCamera"));
        btnEnumCamera->setMinimumSize(QSize(90, 30));
        btnEnumCamera->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        horizontalLayout->addWidget(btnEnumCamera);

        comboBoxCameras = new QComboBox(ImageSourceCameraSetting);
        comboBoxCameras->setObjectName(QString::fromUtf8("comboBoxCameras"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxCameras->sizePolicy().hasHeightForWidth());
        comboBoxCameras->setSizePolicy(sizePolicy);
        comboBoxCameras->setMinimumSize(QSize(0, 30));
        comboBoxCameras->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout->addWidget(comboBoxCameras);

        btnOpenCamera = new QPushButton(ImageSourceCameraSetting);
        btnOpenCamera->setObjectName(QString::fromUtf8("btnOpenCamera"));
        btnOpenCamera->setMinimumSize(QSize(90, 30));
        btnOpenCamera->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        horizontalLayout->addWidget(btnOpenCamera);

        btnCloseCamera = new QPushButton(ImageSourceCameraSetting);
        btnCloseCamera->setObjectName(QString::fromUtf8("btnCloseCamera"));
        btnCloseCamera->setMinimumSize(QSize(90, 30));
        btnCloseCamera->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        horizontalLayout->addWidget(btnCloseCamera);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEditStatistic = new QLineEdit(ImageSourceCameraSetting);
        lineEditStatistic->setObjectName(QString::fromUtf8("lineEditStatistic"));
        lineEditStatistic->setEnabled(false);
        lineEditStatistic->setMinimumSize(QSize(0, 30));
        lineEditStatistic->setMaximumSize(QSize(16777215, 30));
        lineEditStatistic->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        verticalLayout->addWidget(lineEditStatistic);

        ShowWidget = new MyLabel(ImageSourceCameraSetting);
        ShowWidget->setObjectName(QString::fromUtf8("ShowWidget"));
        ShowWidget->setStyleSheet(QString::fromUtf8("border-image:url(:/DynamicWidget/Resource/background.png);"));

        verticalLayout->addWidget(ShowWidget);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnStop = new QPushButton(ImageSourceCameraSetting);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(0, 30));
        btnStop->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        gridLayout_3->addWidget(btnStop, 0, 2, 1, 1);

        btnSingleShot = new QPushButton(ImageSourceCameraSetting);
        btnSingleShot->setObjectName(QString::fromUtf8("btnSingleShot"));
        btnSingleShot->setMinimumSize(QSize(0, 30));
        btnSingleShot->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        gridLayout_3->addWidget(btnSingleShot, 0, 0, 1, 1);

        btnContinuous = new QPushButton(ImageSourceCameraSetting);
        btnContinuous->setObjectName(QString::fromUtf8("btnContinuous"));
        btnContinuous->setMinimumSize(QSize(0, 30));
        btnContinuous->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        gridLayout_3->addWidget(btnContinuous, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_12 = new QLabel(ImageSourceCameraSetting);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 30));
        label_12->setMaximumSize(QSize(16777215, 30));

        verticalLayout_4->addWidget(label_12);

        groupBox = new QGroupBox(ImageSourceCameraSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border:2px solid #1C1C1C;\n"
"border-radius: 3px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_2->addWidget(label);

        horizontalSliderExposure = new QSlider(groupBox);
        horizontalSliderExposure->setObjectName(QString::fromUtf8("horizontalSliderExposure"));
        horizontalSliderExposure->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border-radius: 4px;\n"
"    height: 18px;\n"
"    background: \"transparent\";\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    height: 18px;\n"
"    width:18px;\n"
"    background: #FFFFFF;\n"
"        border:1px solid #330052D9;\n"
"        border-radius:9px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    border-radius: 4px;\n"
"    height: 8px;\n"
"    margin-top:5px;\n"
"    margin-bottom:5px;\n"
"    background: #E7E7E7;\n"
"    \n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    border-radius: 4px;\n"
"    height: 8px;\n"
"    margin-top:5px;\n"
"    margin-bottom:5px;\n"
"    background: #0052D9;\n"
"}"));
        horizontalSliderExposure->setMaximum(999999999);
        horizontalSliderExposure->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderExposure);

        lineEditExposure = new QLineEdit(groupBox);
        lineEditExposure->setObjectName(QString::fromUtf8("lineEditExposure"));
        lineEditExposure->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_2->addWidget(lineEditExposure);

        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSliderGain = new QSlider(groupBox);
        horizontalSliderGain->setObjectName(QString::fromUtf8("horizontalSliderGain"));
        horizontalSliderGain->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border-radius: 4px;\n"
"    height: 18px;\n"
"    background: \"transparent\";\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    height: 18px;\n"
"    width:18px;\n"
"    background: #FFFFFF;\n"
"        border:1px solid #330052D9;\n"
"        border-radius:9px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    border-radius: 4px;\n"
"    height: 8px;\n"
"    margin-top:5px;\n"
"    margin-bottom:5px;\n"
"    background: #E7E7E7;\n"
"    \n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    border-radius: 4px;\n"
"    height: 8px;\n"
"    margin-top:5px;\n"
"    margin-bottom:5px;\n"
"    background: #0052D9;\n"
"}"));
        horizontalSliderGain->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSliderGain);

        lineEditGain = new QLineEdit(groupBox);
        lineEditGain->setObjectName(QString::fromUtf8("lineEditGain"));
        lineEditGain->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_3->addWidget(lineEditGain);

        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_5->addWidget(label_4);

        comboBoxPixelFormat = new QComboBox(groupBox);
        comboBoxPixelFormat->setObjectName(QString::fromUtf8("comboBoxPixelFormat"));
        comboBoxPixelFormat->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_5->addWidget(comboBoxPixelFormat);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_6->addWidget(label_5);

        comboBoxTriggerMode = new QComboBox(groupBox);
        comboBoxTriggerMode->setObjectName(QString::fromUtf8("comboBoxTriggerMode"));
        comboBoxTriggerMode->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_6->addWidget(comboBoxTriggerMode);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_7->addWidget(label_9);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_free = new QRadioButton(widget);
        radioButton_free->setObjectName(QString::fromUtf8("radioButton_free"));

        gridLayout->addWidget(radioButton_free, 0, 0, 1, 1);

        radioButton_hard = new QRadioButton(widget);
        radioButton_hard->setObjectName(QString::fromUtf8("radioButton_hard"));

        gridLayout->addWidget(radioButton_hard, 0, 1, 1, 1);

        radioButton_soft = new QRadioButton(widget);
        radioButton_soft->setObjectName(QString::fromUtf8("radioButton_soft"));

        gridLayout->addWidget(radioButton_soft, 0, 2, 1, 1);


        horizontalLayout_7->addWidget(widget);


        verticalLayout_3->addLayout(horizontalLayout_7);

        widget_Trigger = new QWidget(groupBox);
        widget_Trigger->setObjectName(QString::fromUtf8("widget_Trigger"));
        gridLayout_5 = new QGridLayout(widget_Trigger);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(0);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_TriggerLabel = new QLabel(widget_Trigger);
        label_TriggerLabel->setObjectName(QString::fromUtf8("label_TriggerLabel"));
        label_TriggerLabel->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_5->addWidget(label_TriggerLabel, 0, 0, 1, 1);

        groupBox_Trigger = new QGroupBox(widget_Trigger);
        groupBox_Trigger->setObjectName(QString::fromUtf8("groupBox_Trigger"));
        groupBox_Trigger->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border:2px solid #1C1C1C;\n"
"border-radius: 3px;\n"
"}"));
        gridLayout_4 = new QGridLayout(groupBox_Trigger);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_6 = new QLabel(groupBox_Trigger);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        comboBoxTriggerSource = new QComboBox(groupBox_Trigger);
        comboBoxTriggerSource->setObjectName(QString::fromUtf8("comboBoxTriggerSource"));
        comboBoxTriggerSource->setMinimumSize(QSize(0, 30));
        comboBoxTriggerSource->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout_4->addWidget(comboBoxTriggerSource, 0, 1, 1, 1);

        widget_SoftTrigger = new QWidget(groupBox_Trigger);
        widget_SoftTrigger->setObjectName(QString::fromUtf8("widget_SoftTrigger"));
        verticalLayout_2 = new QVBoxLayout(widget_SoftTrigger);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(widget_SoftTrigger);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_8->addWidget(label_7);

        btnSoftwareTrigger = new QPushButton(widget_SoftTrigger);
        btnSoftwareTrigger->setObjectName(QString::fromUtf8("btnSoftwareTrigger"));
        btnSoftwareTrigger->setMinimumSize(QSize(0, 30));
        btnSoftwareTrigger->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        horizontalLayout_8->addWidget(btnSoftwareTrigger);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(widget_SoftTrigger);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: #999999;"));

        horizontalLayout_9->addWidget(label_10);

        lineEdit_TriggerStr = new QLineEdit(widget_SoftTrigger);
        lineEdit_TriggerStr->setObjectName(QString::fromUtf8("lineEdit_TriggerStr"));
        lineEdit_TriggerStr->setMinimumSize(QSize(0, 30));
        lineEdit_TriggerStr->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_9->addWidget(lineEdit_TriggerStr);

        btn_ConnectCommunicate = new QPushButton(widget_SoftTrigger);
        btn_ConnectCommunicate->setObjectName(QString::fromUtf8("btn_ConnectCommunicate"));
        btn_ConnectCommunicate->setMinimumSize(QSize(100, 30));
        btn_ConnectCommunicate->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.1);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(255, 255, 255, 0.2);\n"
"}"));

        horizontalLayout_9->addWidget(btn_ConnectCommunicate);

        label_SoftTriggerState = new QLabel(widget_SoftTrigger);
        label_SoftTriggerState->setObjectName(QString::fromUtf8("label_SoftTriggerState"));
        label_SoftTriggerState->setMinimumSize(QSize(30, 30));
        label_SoftTriggerState->setMaximumSize(QSize(30, 30));

        horizontalLayout_9->addWidget(label_SoftTriggerState);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout_4->addWidget(widget_SoftTrigger, 1, 0, 1, 2);


        gridLayout_5->addWidget(groupBox_Trigger, 1, 0, 1, 1);


        verticalLayout_3->addWidget(widget_Trigger);

        verticalSpacer = new QSpacerItem(20, 159, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addWidget(groupBox);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 1);


        retranslateUi(ImageSourceCameraSetting);

        QMetaObject::connectSlotsByName(ImageSourceCameraSetting);
    } // setupUi

    void retranslateUi(QWidget *ImageSourceCameraSetting)
    {
        ImageSourceCameraSetting->setWindowTitle(QCoreApplication::translate("ImageSourceCameraSetting", "\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
        btnEnumCamera->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Search for Camera(s)", nullptr));
        btnOpenCamera->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Open", nullptr));
        btnCloseCamera->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Close", nullptr));
        btnStop->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Stop", nullptr));
        btnSingleShot->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Single Capture", nullptr));
        btnContinuous->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Continuous Capture", nullptr));
        label_12->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Parameters Settings", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Exposure Time", nullptr));
        label_8->setText(QString());
        label_2->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Gain", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Pixel Format", nullptr));
        label_5->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Trigger Mode", nullptr));
        label_9->setText(QCoreApplication::translate("ImageSourceCameraSetting", " Trigger Type", nullptr));
        radioButton_free->setText(QCoreApplication::translate("ImageSourceCameraSetting", "FreeRun", nullptr));
        radioButton_hard->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Hardware", nullptr));
        radioButton_soft->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Software", nullptr));
        label_TriggerLabel->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Trigger Settings", nullptr));
        groupBox_Trigger->setTitle(QString());
        label_6->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Trigger Source", nullptr));
        label_7->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Software", nullptr));
        btnSoftwareTrigger->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Manual Trigger", nullptr));
        label_10->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Trigger String", nullptr));
        btn_ConnectCommunicate->setText(QCoreApplication::translate("ImageSourceCameraSetting", "Bind", nullptr));
        label_SoftTriggerState->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageSourceCameraSetting: public Ui_ImageSourceCameraSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESOURCECAMERASETTING_H
