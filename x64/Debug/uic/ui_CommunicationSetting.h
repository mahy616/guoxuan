/********************************************************************************
** Form generated from reading UI file 'CommunicationSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATIONSETTING_H
#define UI_COMMUNICATIONSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "UI/MyWidget/MyLogoButton.h"

QT_BEGIN_NAMESPACE

class Ui_CommunicationSettingClass
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_AddContents;
    QFrame *frame_AddControl;
    QGridLayout *gridLayout;
    MyLogoButton *btn_Reduce;
    MyLogoButton *btn_Add;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget_Communication;

    void setupUi(QWidget *CommunicationSettingClass)
    {
        if (CommunicationSettingClass->objectName().isEmpty())
            CommunicationSettingClass->setObjectName(QString::fromUtf8("CommunicationSettingClass"));
        CommunicationSettingClass->resize(914, 637);
        gridLayout_2 = new QGridLayout(CommunicationSettingClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget_AddContents = new QListWidget(CommunicationSettingClass);
        listWidget_AddContents->setObjectName(QString::fromUtf8("listWidget_AddContents"));
        listWidget_AddContents->setMaximumSize(QSize(170, 16777215));
        listWidget_AddContents->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	color:#DBDBDB;\n"
"    background-color: rgb(50, 50, 50);\n"
"    border:1px solid back;\n"
"    border-top-left-radius:8;\n"
"    border-top-right-radius:8;\n"
"    outline:0px;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"    background-color: rgb(50, 50, 50);    \n"
"}\n"
"QListWidget::item:hover\n"
"{\n"
"    background-color: rgb(65, 65, 65);\n"
"}\n"
"QListWidget::item::selected:active\n"
"{ \n"
"   background-color: rgb(75, 75, 75);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color: rgb(75, 75, 75);\n"
"}"));

        verticalLayout->addWidget(listWidget_AddContents);

        frame_AddControl = new QFrame(CommunicationSettingClass);
        frame_AddControl->setObjectName(QString::fromUtf8("frame_AddControl"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_AddControl->sizePolicy().hasHeightForWidth());
        frame_AddControl->setSizePolicy(sizePolicy);
        frame_AddControl->setMinimumSize(QSize(0, 32));
        frame_AddControl->setMaximumSize(QSize(170, 32));
        frame_AddControl->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border-bottom-left-radius:8;\n"
"border-bottom-right-radius:8;"));
        frame_AddControl->setFrameShape(QFrame::StyledPanel);
        frame_AddControl->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_AddControl);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_Reduce = new MyLogoButton(frame_AddControl);
        btn_Reduce->setObjectName(QString::fromUtf8("btn_Reduce"));
        btn_Reduce->setMinimumSize(QSize(75, 25));
        btn_Reduce->setMaximumSize(QSize(60, 25));

        gridLayout->addWidget(btn_Reduce, 0, 2, 1, 1);

        btn_Add = new MyLogoButton(frame_AddControl);
        btn_Add->setObjectName(QString::fromUtf8("btn_Add"));
        btn_Add->setMinimumSize(QSize(75, 25));
        btn_Add->setMaximumSize(QSize(60, 25));

        gridLayout->addWidget(btn_Add, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout->addWidget(frame_AddControl);


        horizontalLayout->addLayout(verticalLayout);

        stackedWidget_Communication = new QStackedWidget(CommunicationSettingClass);
        stackedWidget_Communication->setObjectName(QString::fromUtf8("stackedWidget_Communication"));

        horizontalLayout->addWidget(stackedWidget_Communication);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(CommunicationSettingClass);

        QMetaObject::connectSlotsByName(CommunicationSettingClass);
    } // setupUi

    void retranslateUi(QWidget *CommunicationSettingClass)
    {
        CommunicationSettingClass->setWindowTitle(QCoreApplication::translate("CommunicationSettingClass", "CommunicationSetting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommunicationSettingClass: public Ui_CommunicationSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONSETTING_H
