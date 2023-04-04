/********************************************************************************
** Form generated from reading UI file 'DialogMCBinSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMCBINSETTING_H
#define UI_DIALOGMCBINSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogMCBinSettingClass
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_IpStr;
    QLabel *label_2;
    QLineEdit *lineEdit_Port;
    QLabel *label_3;
    QLineEdit *lineEdit_Addres;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_Connet;
    QPushButton *btn_DisConnect;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_Read;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_IntRead;
    QLabel *label_5;
    QPushButton *btn_DoubleRead;
    QLabel *label_4;
    QPushButton *btn_StringRead;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_Write;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_InputData;
    QLabel *label_8;
    QPushButton *btn_IntWrite;
    QLabel *label_6;
    QPushButton *btn_DoubleWrite;
    QLabel *label_7;
    QPushButton *btn_StringWrite;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *DialogMCBinSettingClass)
    {
        if (DialogMCBinSettingClass->objectName().isEmpty())
            DialogMCBinSettingClass->setObjectName(QString::fromUtf8("DialogMCBinSettingClass"));
        DialogMCBinSettingClass->resize(761, 552);
        DialogMCBinSettingClass->setStyleSheet(QString::fromUtf8("color:#E0E0E0;\n"
"font-family:Microsoft YaHei;\n"
"background: #323232;\n"
"\n"
"\n"
"\n"
"\n"
""));
        gridLayout_4 = new QGridLayout(DialogMCBinSettingClass);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(DialogMCBinSettingClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"color:white;\n"
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
"}\n"
"QLineEdit\n"
"{\n"
"	color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_IpStr = new QLineEdit(groupBox);
        lineEdit_IpStr->setObjectName(QString::fromUtf8("lineEdit_IpStr"));

        horizontalLayout->addWidget(lineEdit_IpStr);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_Port = new QLineEdit(groupBox);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));

        horizontalLayout->addWidget(lineEdit_Port);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_Addres = new QLineEdit(groupBox);
        lineEdit_Addres->setObjectName(QString::fromUtf8("lineEdit_Addres"));

        horizontalLayout->addWidget(lineEdit_Addres);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_Connet = new QPushButton(groupBox);
        btn_Connet->setObjectName(QString::fromUtf8("btn_Connet"));
        btn_Connet->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(btn_Connet);

        btn_DisConnect = new QPushButton(groupBox);
        btn_DisConnect->setObjectName(QString::fromUtf8("btn_DisConnect"));
        btn_DisConnect->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(btn_DisConnect);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_2 = new QGroupBox(DialogMCBinSettingClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"color:white;\n"
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
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        textEdit_Read = new QTextEdit(groupBox_2);
        textEdit_Read->setObjectName(QString::fromUtf8("textEdit_Read"));
        textEdit_Read->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_4->addWidget(textEdit_Read);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_IntRead = new QPushButton(groupBox_2);
        btn_IntRead->setObjectName(QString::fromUtf8("btn_IntRead"));
        btn_IntRead->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(btn_IntRead);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        btn_DoubleRead = new QPushButton(groupBox_2);
        btn_DoubleRead->setObjectName(QString::fromUtf8("btn_DoubleRead"));
        btn_DoubleRead->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(btn_DoubleRead);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        btn_StringRead = new QPushButton(groupBox_2);
        btn_StringRead->setObjectName(QString::fromUtf8("btn_StringRead"));
        btn_StringRead->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(btn_StringRead);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(DialogMCBinSettingClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: 1px solid rgba(255, 255, 255, 0.2);\n"
"	border-radius: 5px;\n"
"color:white;\n"
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
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textEdit_Write = new QTextEdit(groupBox_3);
        textEdit_Write->setObjectName(QString::fromUtf8("textEdit_Write"));
        textEdit_Write->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_3->addWidget(textEdit_Write);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 100));
        groupBox_4->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_InputData = new QLineEdit(groupBox_4);
        lineEdit_InputData->setObjectName(QString::fromUtf8("lineEdit_InputData"));

        gridLayout_5->addWidget(lineEdit_InputData, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        btn_IntWrite = new QPushButton(groupBox_3);
        btn_IntWrite->setObjectName(QString::fromUtf8("btn_IntWrite"));
        btn_IntWrite->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btn_IntWrite);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        btn_DoubleWrite = new QPushButton(groupBox_3);
        btn_DoubleWrite->setObjectName(QString::fromUtf8("btn_DoubleWrite"));
        btn_DoubleWrite->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btn_DoubleWrite);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        btn_StringWrite = new QPushButton(groupBox_3);
        btn_StringWrite->setObjectName(QString::fromUtf8("btn_StringWrite"));
        btn_StringWrite->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btn_StringWrite);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(6, 1);

        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 1, 1, 1);


        retranslateUi(DialogMCBinSettingClass);

        QMetaObject::connectSlotsByName(DialogMCBinSettingClass);
    } // setupUi

    void retranslateUi(QWidget *DialogMCBinSettingClass)
    {
        DialogMCBinSettingClass->setWindowTitle(QCoreApplication::translate("DialogMCBinSettingClass", "DialogMCBinSetting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogMCBinSettingClass", "Connection Configuration", nullptr));
        label->setText(QCoreApplication::translate("DialogMCBinSettingClass", "IP:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogMCBinSettingClass", "Port:", nullptr));
        label_3->setText(QCoreApplication::translate("DialogMCBinSettingClass", "Address:", nullptr));
        btn_Connet->setText(QCoreApplication::translate("DialogMCBinSettingClass", "connect", nullptr));
        btn_DisConnect->setText(QCoreApplication::translate("DialogMCBinSettingClass", "disconnect", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogMCBinSettingClass", "Reading Data Test", nullptr));
        btn_IntRead->setText(QCoreApplication::translate("DialogMCBinSettingClass", "Int Read", nullptr));
        label_5->setText(QString());
        btn_DoubleRead->setText(QCoreApplication::translate("DialogMCBinSettingClass", "Float Read", nullptr));
        label_4->setText(QString());
        btn_StringRead->setText(QCoreApplication::translate("DialogMCBinSettingClass", "String Read", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogMCBinSettingClass", "Writting Data Test", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DialogMCBinSettingClass", "Input Data", nullptr));
        label_8->setText(QString());
        btn_IntWrite->setText(QCoreApplication::translate("DialogMCBinSettingClass", "Int Write", nullptr));
        label_6->setText(QString());
        btn_DoubleWrite->setText(QCoreApplication::translate("DialogMCBinSettingClass", "Float Write", nullptr));
        label_7->setText(QString());
        btn_StringWrite->setText(QCoreApplication::translate("DialogMCBinSettingClass", "String Write", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogMCBinSettingClass: public Ui_DialogMCBinSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMCBINSETTING_H
