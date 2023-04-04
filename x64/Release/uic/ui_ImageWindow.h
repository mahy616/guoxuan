/********************************************************************************
** Form generated from reading UI file 'ImageWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWINDOW_H
#define UI_IMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <UI/MyWidget/mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_ImageWindowClass
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_LeftSpace;
    QLabel *label_WidonwTittle;
    QSpacerItem *horizontalSpacer;
    QLabel *label_ModelStatus;
    QLabel *label_modeType;
    QLabel *label_Line1;
    QLabel *label_UseTime;
    QLabel *label_Line2;
    QCheckBox *checkBox_ShowRender;
    QLabel *label_Line3;
    QPushButton *btn_SoftTrigger;
    QLabel *label_RightSpace;
    MyLabel *ShowImgWidget;

    void setupUi(QWidget *ImageWindowClass)
    {
        if (ImageWindowClass->objectName().isEmpty())
            ImageWindowClass->setObjectName(QString::fromUtf8("ImageWindowClass"));
        ImageWindowClass->resize(686, 591);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(13);
        ImageWindowClass->setFont(font);
        ImageWindowClass->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(ImageWindowClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(ImageWindowClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	background-color:rgb(38,38,38);\n"
"	border: 2px solid #000000;\n"
"}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 0, 3, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label_LeftSpace = new QLabel(groupBox);
        label_LeftSpace->setObjectName(QString::fromUtf8("label_LeftSpace"));
        label_LeftSpace->setMinimumSize(QSize(5, 40));
        label_LeftSpace->setSizeIncrement(QSize(5, 0));
        label_LeftSpace->setStyleSheet(QString::fromUtf8("background: \"transparent\";"));

        horizontalLayout->addWidget(label_LeftSpace);

        label_WidonwTittle = new QLabel(groupBox);
        label_WidonwTittle->setObjectName(QString::fromUtf8("label_WidonwTittle"));
        label_WidonwTittle->setMaximumSize(QSize(120, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_WidonwTittle->setFont(font1);
        label_WidonwTittle->setStyleSheet(QString::fromUtf8("color: rgb(250, 250, 250);\n"
"background: \"transparent\";"));

        horizontalLayout->addWidget(label_WidonwTittle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_ModelStatus = new QLabel(groupBox);
        label_ModelStatus->setObjectName(QString::fromUtf8("label_ModelStatus"));
        label_ModelStatus->setMinimumSize(QSize(25, 25));
        label_ModelStatus->setMaximumSize(QSize(25, 25));
        label_ModelStatus->setStyleSheet(QString::fromUtf8("background: \"transparent\";"));

        horizontalLayout->addWidget(label_ModelStatus);

        label_modeType = new QLabel(groupBox);
        label_modeType->setObjectName(QString::fromUtf8("label_modeType"));
        label_modeType->setMaximumSize(QSize(16777215, 41));
        label_modeType->setFont(font1);
        label_modeType->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"background: \"transparent\";"));

        horizontalLayout->addWidget(label_modeType);

        label_Line1 = new QLabel(groupBox);
        label_Line1->setObjectName(QString::fromUtf8("label_Line1"));
        label_Line1->setMinimumSize(QSize(3, 20));
        label_Line1->setMaximumSize(QSize(3, 20));
        label_Line1->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/ToolBarSegLine.png\");"));

        horizontalLayout->addWidget(label_Line1);

        label_UseTime = new QLabel(groupBox);
        label_UseTime->setObjectName(QString::fromUtf8("label_UseTime"));
        label_UseTime->setMaximumSize(QSize(16777215, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        font2.setKerning(true);
        label_UseTime->setFont(font2);
        label_UseTime->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"background: \"transparent\";"));

        horizontalLayout->addWidget(label_UseTime);

        label_Line2 = new QLabel(groupBox);
        label_Line2->setObjectName(QString::fromUtf8("label_Line2"));
        label_Line2->setMinimumSize(QSize(3, 20));
        label_Line2->setMaximumSize(QSize(3, 20));
        label_Line2->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/ToolBarSegLine.png\");"));

        horizontalLayout->addWidget(label_Line2);

        checkBox_ShowRender = new QCheckBox(groupBox);
        checkBox_ShowRender->setObjectName(QString::fromUtf8("checkBox_ShowRender"));
        checkBox_ShowRender->setMinimumSize(QSize(0, 0));
        checkBox_ShowRender->setMaximumSize(QSize(16777215, 41));
        checkBox_ShowRender->setFont(font1);
        checkBox_ShowRender->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"background: \"transparent\";"));
        checkBox_ShowRender->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(checkBox_ShowRender);

        label_Line3 = new QLabel(groupBox);
        label_Line3->setObjectName(QString::fromUtf8("label_Line3"));
        label_Line3->setMinimumSize(QSize(3, 20));
        label_Line3->setMaximumSize(QSize(3, 20));
        label_Line3->setStyleSheet(QString::fromUtf8("border-image:url(\":/DynamicWidget/Resource/ToolBarSegLine.png\");"));

        horizontalLayout->addWidget(label_Line3);

        btn_SoftTrigger = new QPushButton(groupBox);
        btn_SoftTrigger->setObjectName(QString::fromUtf8("btn_SoftTrigger"));
        btn_SoftTrigger->setMinimumSize(QSize(25, 25));
        btn_SoftTrigger->setMaximumSize(QSize(25, 25));
        btn_SoftTrigger->setStyleSheet(QString::fromUtf8("background: \"transparent\";"));

        horizontalLayout->addWidget(btn_SoftTrigger);

        label_RightSpace = new QLabel(groupBox);
        label_RightSpace->setObjectName(QString::fromUtf8("label_RightSpace"));
        label_RightSpace->setMinimumSize(QSize(5, 0));
        label_RightSpace->setMaximumSize(QSize(5, 40));
        label_RightSpace->setStyleSheet(QString::fromUtf8("background: \"transparent\";"));

        horizontalLayout->addWidget(label_RightSpace);


        verticalLayout->addLayout(horizontalLayout);

        ShowImgWidget = new MyLabel(groupBox);
        ShowImgWidget->setObjectName(QString::fromUtf8("ShowImgWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShowImgWidget->sizePolicy().hasHeightForWidth());
        ShowImgWidget->setSizePolicy(sizePolicy);
        ShowImgWidget->setStyleSheet(QString::fromUtf8("border-image:url(:/DynamicWidget/Resource/background.png);"));

        verticalLayout->addWidget(ShowImgWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 13);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ImageWindowClass);

        QMetaObject::connectSlotsByName(ImageWindowClass);
    } // setupUi

    void retranslateUi(QWidget *ImageWindowClass)
    {
        ImageWindowClass->setWindowTitle(QCoreApplication::translate("ImageWindowClass", "ImageWindow", nullptr));
        groupBox->setTitle(QString());
        label_LeftSpace->setText(QString());
        label_WidonwTittle->setText(QString());
        label_ModelStatus->setText(QString());
        label_modeType->setText(QCoreApplication::translate("ImageWindowClass", "None", nullptr));
        label_Line1->setText(QString());
        label_UseTime->setText(QCoreApplication::translate("ImageWindowClass", "Time Spent:0", nullptr));
        label_Line2->setText(QString());
        checkBox_ShowRender->setText(QCoreApplication::translate("ImageWindowClass", "Rendering", nullptr));
        label_Line3->setText(QString());
        btn_SoftTrigger->setText(QString());
        label_RightSpace->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageWindowClass: public Ui_ImageWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOW_H
