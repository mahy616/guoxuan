/********************************************************************************
** Form generated from reading UI file 'DialogTCPSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTCPSETTINGS_H
#define UI_DIALOGTCPSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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

class Ui_DialogTCPSettingsClass
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cmbProtocol;
    QLabel *labelAddress;
    QLineEdit *lineEditIP;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConnect;
    QPushButton *btnDisConnect;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_ReceiveClear;
    QTextEdit *textEditReceive;
    QFrame *line;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QWidget *widgetLocal;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditLocalIP;
    QLabel *label_6;
    QLineEdit *lineEditLocalPort;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widgetConnectors;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelClient;
    QComboBox *cmbClient;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnSend;
    QPushButton *btn_SendClear;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEditSend;

    void setupUi(QWidget *DialogTCPSettingsClass)
    {
        if (DialogTCPSettingsClass->objectName().isEmpty())
            DialogTCPSettingsClass->setObjectName(QString::fromUtf8("DialogTCPSettingsClass"));
        DialogTCPSettingsClass->resize(759, 607);
        DialogTCPSettingsClass->setStyleSheet(QString::fromUtf8("background: #323232;\n"
"color: #999999;\n"
"font-family: KaiTi;"));
        gridLayout_4 = new QGridLayout(DialogTCPSettingsClass);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(DialogTCPSettingsClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 20));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout_3->addWidget(label_2);

        groupBox = new QGroupBox(DialogTCPSettingsClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid #212121;}"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        cmbProtocol = new QComboBox(groupBox);
        cmbProtocol->setObjectName(QString::fromUtf8("cmbProtocol"));
        cmbProtocol->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        verticalLayout->addWidget(cmbProtocol);

        labelAddress = new QLabel(groupBox);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));

        verticalLayout->addWidget(labelAddress);

        lineEditIP = new QLineEdit(groupBox);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        verticalLayout->addWidget(lineEditIP);

        labelPort = new QLabel(groupBox);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        verticalLayout->addWidget(labelPort);

        lineEditPort = new QLineEdit(groupBox);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        verticalLayout->addWidget(lineEditPort);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setMinimumSize(QSize(100, 25));
        btnConnect->setMaximumSize(QSize(100, 25));
        btnConnect->setStyleSheet(QString::fromUtf8("\n"
"\n"
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

        horizontalLayout->addWidget(btnConnect);

        btnDisConnect = new QPushButton(groupBox);
        btnDisConnect->setObjectName(QString::fromUtf8("btnDisConnect"));
        btnDisConnect->setMinimumSize(QSize(100, 25));
        btnDisConnect->setMaximumSize(QSize(100, 25));
        btnDisConnect->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout->addWidget(btnDisConnect);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addWidget(groupBox);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(DialogTCPSettingsClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 20));
        label_4->setMaximumSize(QSize(16777215, 20));
        label_4->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout_2->addWidget(label_4);

        groupBox_2 = new QGroupBox(DialogTCPSettingsClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid #212121;}"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_ReceiveClear = new QPushButton(widget);
        btn_ReceiveClear->setObjectName(QString::fromUtf8("btn_ReceiveClear"));
        btn_ReceiveClear->setMinimumSize(QSize(60, 25));
        btn_ReceiveClear->setMaximumSize(QSize(60, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("KaiTi"));
        btn_ReceiveClear->setFont(font);
        btn_ReceiveClear->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
"}\n"
""));

        horizontalLayout_4->addWidget(btn_ReceiveClear);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        textEditReceive = new QTextEdit(widget);
        textEditReceive->setObjectName(QString::fromUtf8("textEditReceive"));
        textEditReceive->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout->addWidget(textEditReceive, 1, 0, 1, 1);


        verticalLayout_4->addWidget(widget);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("border-top: 3px solid #141414;   "));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widgetLocal = new QWidget(widget_2);
        widgetLocal->setObjectName(QString::fromUtf8("widgetLocal"));
        horizontalLayout_2 = new QHBoxLayout(widgetLocal);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widgetLocal);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEditLocalIP = new QLineEdit(widgetLocal);
        lineEditLocalIP->setObjectName(QString::fromUtf8("lineEditLocalIP"));
        lineEditLocalIP->setEnabled(false);
        lineEditLocalIP->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_2->addWidget(lineEditLocalIP);

        label_6 = new QLabel(widgetLocal);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEditLocalPort = new QLineEdit(widgetLocal);
        lineEditLocalPort->setObjectName(QString::fromUtf8("lineEditLocalPort"));
        lineEditLocalPort->setEnabled(false);
        lineEditLocalPort->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_2->addWidget(lineEditLocalPort);

        horizontalSpacer_2 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widgetLocal, 1, 0, 1, 1);

        widgetConnectors = new QWidget(widget_2);
        widgetConnectors->setObjectName(QString::fromUtf8("widgetConnectors"));
        horizontalLayout_5 = new QHBoxLayout(widgetConnectors);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelClient = new QLabel(widgetConnectors);
        labelClient->setObjectName(QString::fromUtf8("labelClient"));

        horizontalLayout_5->addWidget(labelClient);

        cmbClient = new QComboBox(widgetConnectors);
        cmbClient->setObjectName(QString::fromUtf8("cmbClient"));
        cmbClient->setMinimumSize(QSize(150, 0));
        cmbClient->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_5->addWidget(cmbClient);

        horizontalSpacer = new QSpacerItem(417, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout_2->addWidget(widgetConnectors, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        btnSend = new QPushButton(widget_2);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy);
        btnSend->setMinimumSize(QSize(60, 25));
        btnSend->setMaximumSize(QSize(60, 25));
        btnSend->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_6->addWidget(btnSend);

        btn_SendClear = new QPushButton(widget_2);
        btn_SendClear->setObjectName(QString::fromUtf8("btn_SendClear"));
        btn_SendClear->setMinimumSize(QSize(60, 25));
        btn_SendClear->setMaximumSize(QSize(60, 25));
        btn_SendClear->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_6->addWidget(btn_SendClear);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textEditSend = new QTextEdit(widget_2);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));
        textEditSend->setMaximumSize(QSize(16777215, 16777215));
        textEditSend->setStyleSheet(QString::fromUtf8("color:white;\n"
"background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_3->addWidget(textEditSend);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 1);


        verticalLayout_4->addWidget(widget_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(2, 1);

        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);


        gridLayout_4->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(DialogTCPSettingsClass);

        QMetaObject::connectSlotsByName(DialogTCPSettingsClass);
    } // setupUi

    void retranslateUi(QWidget *DialogTCPSettingsClass)
    {
        DialogTCPSettingsClass->setWindowTitle(QCoreApplication::translate("DialogTCPSettingsClass", "DialogTCPSettings", nullptr));
        label_2->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Communication Protocol", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Protocol Type", nullptr));
        labelAddress->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Local IP Adress", nullptr));
        labelPort->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Local Port", nullptr));
        btnConnect->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Connect", nullptr));
        btnDisConnect->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Disconnect", nullptr));
        label_4->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Device Debugging", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Receive Data", nullptr));
        btn_ReceiveClear->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Clear", nullptr));
        label_5->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Local Host:", nullptr));
        label_6->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Local Port:", nullptr));
        labelClient->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Connect Objects:", nullptr));
        label_7->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Send Data", nullptr));
        btnSend->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Send", nullptr));
        btn_SendClear->setText(QCoreApplication::translate("DialogTCPSettingsClass", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTCPSettingsClass: public Ui_DialogTCPSettingsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTCPSETTINGS_H
