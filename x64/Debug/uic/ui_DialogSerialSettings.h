/********************************************************************************
** Form generated from reading UI file 'DialogSerialSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSERIALSETTINGS_H
#define UI_DIALOGSERIALSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSerialSettingsClass
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cmbName;
    QLabel *label_2;
    QComboBox *cmbBaudRate;
    QLabel *label_3;
    QComboBox *cmbParity;
    QLabel *label_4;
    QComboBox *cmbDataBits;
    QLabel *label_6;
    QComboBox *cmbStopBits;
    QLabel *label_5;
    QComboBox *cmbFlowControl;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnOpenSerial;
    QPushButton *btnCloseSerial;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClearLog;
    QTextEdit *textEditLog;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnClearSend;
    QPushButton *btnSend;
    QTextEdit *textEditSend;

    void setupUi(QWidget *DialogSerialSettingsClass)
    {
        if (DialogSerialSettingsClass->objectName().isEmpty())
            DialogSerialSettingsClass->setObjectName(QString::fromUtf8("DialogSerialSettingsClass"));
        DialogSerialSettingsClass->resize(955, 743);
        DialogSerialSettingsClass->setStyleSheet(QString::fromUtf8("color:#E0E0E0;\n"
"font-family:Microsoft YaHei;\n"
"background: #323232;\n"
""));
        gridLayout_2 = new QGridLayout(DialogSerialSettingsClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_9 = new QLabel(DialogSerialSettingsClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        groupBox = new QGroupBox(DialogSerialSettingsClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox\n"
"{\n"
"	color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QGroupBox{border:1px solid #212121;}"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cmbName = new QComboBox(groupBox);
        cmbName->setObjectName(QString::fromUtf8("cmbName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cmbName);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cmbBaudRate = new QComboBox(groupBox);
        cmbBaudRate->setObjectName(QString::fromUtf8("cmbBaudRate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cmbBaudRate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        cmbParity = new QComboBox(groupBox);
        cmbParity->setObjectName(QString::fromUtf8("cmbParity"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cmbParity);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        cmbDataBits = new QComboBox(groupBox);
        cmbDataBits->setObjectName(QString::fromUtf8("cmbDataBits"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cmbDataBits);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        cmbStopBits = new QComboBox(groupBox);
        cmbStopBits->setObjectName(QString::fromUtf8("cmbStopBits"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cmbStopBits);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        cmbFlowControl = new QComboBox(groupBox);
        cmbFlowControl->setObjectName(QString::fromUtf8("cmbFlowControl"));

        formLayout->setWidget(5, QFormLayout::FieldRole, cmbFlowControl);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnOpenSerial = new QPushButton(groupBox);
        btnOpenSerial->setObjectName(QString::fromUtf8("btnOpenSerial"));
        btnOpenSerial->setMinimumSize(QSize(70, 30));
        btnOpenSerial->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"color:white;\n"
"\n"
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
"}\n"
"QPushButton:disabled\n"
"{\n"
"	background: #ABABAB;\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"}"));

        horizontalLayout_5->addWidget(btnOpenSerial);

        btnCloseSerial = new QPushButton(groupBox);
        btnCloseSerial->setObjectName(QString::fromUtf8("btnCloseSerial"));
        btnCloseSerial->setMinimumSize(QSize(70, 30));
        btnCloseSerial->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"color:white;\n"
"\n"
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
"}\n"
"QPushButton:disabled\n"
"{\n"
"	background: #ABABAB;\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"}"));

        horizontalLayout_5->addWidget(btnCloseSerial);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_5);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 20);

        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_10 = new QLabel(DialogSerialSettingsClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        groupBox_2 = new QGroupBox(DialogSerialSettingsClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid #212121;}\n"
"QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"color:white;\n"
"\n"
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
"}\n"
"QPushButton:disabled\n"
"{\n"
"	background: #ABABAB;\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"}"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClearLog = new QPushButton(groupBox_2);
        btnClearLog->setObjectName(QString::fromUtf8("btnClearLog"));
        btnClearLog->setMinimumSize(QSize(60, 25));
        btnClearLog->setMaximumSize(QSize(60, 25));

        horizontalLayout->addWidget(btnClearLog);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        textEditLog = new QTextEdit(groupBox_2);
        textEditLog->setObjectName(QString::fromUtf8("textEditLog"));
        textEditLog->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout->addWidget(textEditLog, 1, 0, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnClearSend = new QPushButton(groupBox_2);
        btnClearSend->setObjectName(QString::fromUtf8("btnClearSend"));
        btnClearSend->setMinimumSize(QSize(60, 25));

        horizontalLayout_3->addWidget(btnClearSend);

        btnSend = new QPushButton(groupBox_2);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy);
        btnSend->setMinimumSize(QSize(60, 25));
        btnSend->setMaximumSize(QSize(60, 25));

        horizontalLayout_3->addWidget(btnSend);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        textEditSend = new QTextEdit(groupBox_2);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEditSend->sizePolicy().hasHeightForWidth());
        textEditSend->setSizePolicy(sizePolicy1);
        textEditSend->setMaximumSize(QSize(16777215, 16777215));
        textEditSend->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout->addWidget(textEditSend, 4, 0, 1, 1);

        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(4, 1);

        verticalLayout->addWidget(groupBox_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(DialogSerialSettingsClass);

        QMetaObject::connectSlotsByName(DialogSerialSettingsClass);
    } // setupUi

    void retranslateUi(QWidget *DialogSerialSettingsClass)
    {
        DialogSerialSettingsClass->setWindowTitle(QCoreApplication::translate("DialogSerialSettingsClass", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        label_9->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Serial Port Setting", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Serial port Number", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Serial port Rate", nullptr));
        label_3->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Check Bits", nullptr));
        label_4->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Data Bits", nullptr));
        label_6->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Stop Bits", nullptr));
        label_5->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Flow Control", nullptr));
        btnOpenSerial->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Open", nullptr));
        btnCloseSerial->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Close", nullptr));
        label_10->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Device Debugging", nullptr));
        groupBox_2->setTitle(QString());
        label_7->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Data Log", nullptr));
        btnClearLog->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Clear", nullptr));
        label_8->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Data Send", nullptr));
        btnClearSend->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Clear", nullptr));
        btnSend->setText(QCoreApplication::translate("DialogSerialSettingsClass", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSerialSettingsClass: public Ui_DialogSerialSettingsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSERIALSETTINGS_H
