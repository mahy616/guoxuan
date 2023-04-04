/********************************************************************************
** Form generated from reading UI file 'ThresholdSet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDSET_H
#define UI_THRESHOLDSET_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThresholdSetClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox_Models;
    QWidget *MyWidgets;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_PostProcess;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_6;
    QStackedWidget *stackedWidget_ThresholdDialog;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_7;
    QStackedWidget *stackedWidget_RenderSet;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Time;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QRadioButton *radioButton_ViMo;
    QRadioButton *radioButton_PostProcess;
    QRadioButton *radioButton_ViMoAndPost;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_ReSet;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Cancel;
    QLabel *label_4;
    QPushButton *btn_Confim;

    void setupUi(QWidget *ThresholdSetClass)
    {
        if (ThresholdSetClass->objectName().isEmpty())
            ThresholdSetClass->setObjectName(QString::fromUtf8("ThresholdSetClass"));
        ThresholdSetClass->resize(1239, 833);
        ThresholdSetClass->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size: 11pt;\n"
"background: #323232;\n"
"\n"
"QWidget#ThresholdSetClass\n"
"{\n"
"	border-radius: 8px;\n"
"}"));
        gridLayout = new QGridLayout(ThresholdSetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(ThresholdSetClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(170, 16777215));

        horizontalLayout_4->addWidget(label_3);

        comboBox_Models = new QComboBox(ThresholdSetClass);
        comboBox_Models->setObjectName(QString::fromUtf8("comboBox_Models"));
        comboBox_Models->setMinimumSize(QSize(0, 35));

        horizontalLayout_4->addWidget(comboBox_Models);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        MyWidgets = new QWidget(ThresholdSetClass);
        MyWidgets->setObjectName(QString::fromUtf8("MyWidgets"));
        QFont font;
        font.setFamily(QString::fromUtf8("KaiTi"));
        font.setPointSize(11);
        MyWidgets->setFont(font);
        gridLayout_4 = new QGridLayout(MyWidgets);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_PostProcess = new QGroupBox(MyWidgets);
        groupBox_PostProcess->setObjectName(QString::fromUtf8("groupBox_PostProcess"));
        gridLayout_5 = new QGridLayout(groupBox_PostProcess);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 3, 5, 3);
        scrollArea = new QScrollArea(groupBox_PostProcess);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 882, 615));
        gridLayout_6 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        stackedWidget_ThresholdDialog = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget_ThresholdDialog->setObjectName(QString::fromUtf8("stackedWidget_ThresholdDialog"));

        gridLayout_6->addWidget(stackedWidget_ThresholdDialog, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_PostProcess);

        groupBox = new QGroupBox(MyWidgets);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 3, 5, 3);
        scrollArea_2 = new QScrollArea(groupBox);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 285, 615));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        stackedWidget_RenderSet = new QStackedWidget(scrollAreaWidgetContents_2);
        stackedWidget_RenderSet->setObjectName(QString::fromUtf8("stackedWidget_RenderSet"));

        gridLayout_7->addWidget(stackedWidget_RenderSet, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 1, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea_2, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);

        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(MyWidgets);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_Time = new QLineEdit(groupBox_2);
        lineEdit_Time->setObjectName(QString::fromUtf8("lineEdit_Time"));

        horizontalLayout->addWidget(lineEdit_Time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        radioButton_ViMo = new QRadioButton(groupBox_2);
        radioButton_ViMo->setObjectName(QString::fromUtf8("radioButton_ViMo"));

        horizontalLayout->addWidget(radioButton_ViMo);

        radioButton_PostProcess = new QRadioButton(groupBox_2);
        radioButton_PostProcess->setObjectName(QString::fromUtf8("radioButton_PostProcess"));

        horizontalLayout->addWidget(radioButton_PostProcess);

        radioButton_ViMoAndPost = new QRadioButton(groupBox_2);
        radioButton_ViMoAndPost->setObjectName(QString::fromUtf8("radioButton_ViMoAndPost"));

        horizontalLayout->addWidget(radioButton_ViMoAndPost);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);


        gridLayout->addWidget(MyWidgets, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_ReSet = new QPushButton(ThresholdSetClass);
        btn_ReSet->setObjectName(QString::fromUtf8("btn_ReSet"));
        btn_ReSet->setMinimumSize(QSize(80, 30));
        btn_ReSet->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
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

        horizontalLayout_2->addWidget(btn_ReSet);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_Cancel = new QPushButton(ThresholdSetClass);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setMinimumSize(QSize(80, 30));
        btn_Cancel->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: #4A4A4A;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background: #858585;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #A3A3A3;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout_2->addWidget(btn_Cancel);

        label_4 = new QLabel(ThresholdSetClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(10, 0));
        label_4->setMaximumSize(QSize(10, 16777215));

        horizontalLayout_2->addWidget(label_4);

        btn_Confim = new QPushButton(ThresholdSetClass);
        btn_Confim->setObjectName(QString::fromUtf8("btn_Confim"));
        btn_Confim->setMinimumSize(QSize(80, 30));
        btn_Confim->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: #3A71DE;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background: #274B94;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #172D59;\n"
"	border-radius: 4px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(btn_Confim);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(ThresholdSetClass);

        QMetaObject::connectSlotsByName(ThresholdSetClass);
    } // setupUi

    void retranslateUi(QWidget *ThresholdSetClass)
    {
        ThresholdSetClass->setWindowTitle(QCoreApplication::translate("ThresholdSetClass", "Parameters Settings", nullptr));
        label_3->setText(QCoreApplication::translate("ThresholdSetClass", "Choose Module", nullptr));
        groupBox_PostProcess->setTitle(QCoreApplication::translate("ThresholdSetClass", "Post-Inference Threshold", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ThresholdSetClass", "Display Settings", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ThresholdSetClass", "Timer Settings", nullptr));
        label->setText(QCoreApplication::translate("ThresholdSetClass", "Timeout Threshold(ms):", nullptr));
        label_2->setText(QCoreApplication::translate("ThresholdSetClass", "Timing content:", nullptr));
        radioButton_ViMo->setText(QCoreApplication::translate("ThresholdSetClass", "ViMo Inference", nullptr));
        radioButton_PostProcess->setText(QCoreApplication::translate("ThresholdSetClass", "Post-Inference", nullptr));
        radioButton_ViMoAndPost->setText(QCoreApplication::translate("ThresholdSetClass", "ViMo-Inference + Post-Inference", nullptr));
        btn_ReSet->setText(QCoreApplication::translate("ThresholdSetClass", "Reset", nullptr));
        btn_Cancel->setText(QCoreApplication::translate("ThresholdSetClass", "Cancel", nullptr));
        label_4->setText(QString());
        btn_Confim->setText(QCoreApplication::translate("ThresholdSetClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThresholdSetClass: public Ui_ThresholdSetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDSET_H
