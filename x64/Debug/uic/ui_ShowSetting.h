/********************************************************************************
** Form generated from reading UI file 'ShowSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSETTING_H
#define UI_SHOWSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowSettingClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *radioButton_Chinese;
    QRadioButton *radioButton_English;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QPushButton *btn_ShowLogo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_SoftName;
    QLabel *label_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QRadioButton *radioButton_left;
    QRadioButton *radioButton_middle;
    QRadioButton *radioButton_right;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ShowSettingClass)
    {
        if (ShowSettingClass->objectName().isEmpty())
            ShowSettingClass->setObjectName(QString::fromUtf8("ShowSettingClass"));
        ShowSettingClass->resize(600, 400);
        ShowSettingClass->setStyleSheet(QString::fromUtf8("background: #323232;\n"
"color: #999999;"));
        gridLayout = new QGridLayout(ShowSettingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(ShowSettingClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ShowSettingClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        radioButton_Chinese = new QRadioButton(ShowSettingClass);
        radioButton_Chinese->setObjectName(QString::fromUtf8("radioButton_Chinese"));

        horizontalLayout->addWidget(radioButton_Chinese);

        radioButton_English = new QRadioButton(ShowSettingClass);
        radioButton_English->setObjectName(QString::fromUtf8("radioButton_English"));

        horizontalLayout->addWidget(radioButton_English);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        label_5 = new QLabel(ShowSettingClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(ShowSettingClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        btn_ShowLogo = new QPushButton(ShowSettingClass);
        btn_ShowLogo->setObjectName(QString::fromUtf8("btn_ShowLogo"));
        btn_ShowLogo->setMinimumSize(QSize(40, 25));
        btn_ShowLogo->setMaximumSize(QSize(40, 25));
        btn_ShowLogo->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image:url(\":/DynamicWidget/Resource/Btn_Open.png\");\n"
"	border:none;\n"
"	background:transparent;\n"
"}"));

        horizontalLayout_2->addWidget(btn_ShowLogo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        label_6 = new QLabel(ShowSettingClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(ShowSettingClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_SoftName = new QLineEdit(ShowSettingClass);
        lineEdit_SoftName->setObjectName(QString::fromUtf8("lineEdit_SoftName"));
        lineEdit_SoftName->setMinimumSize(QSize(0, 30));
        lineEdit_SoftName->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout_3->addWidget(lineEdit_SoftName);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        label_8 = new QLabel(ShowSettingClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 1, 1, 1);

        label_9 = new QLabel(ShowSettingClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(ShowSettingClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        radioButton_left = new QRadioButton(ShowSettingClass);
        radioButton_left->setObjectName(QString::fromUtf8("radioButton_left"));

        horizontalLayout_4->addWidget(radioButton_left);

        radioButton_middle = new QRadioButton(ShowSettingClass);
        radioButton_middle->setObjectName(QString::fromUtf8("radioButton_middle"));

        horizontalLayout_4->addWidget(radioButton_middle);

        radioButton_right = new QRadioButton(ShowSettingClass);
        radioButton_right->setObjectName(QString::fromUtf8("radioButton_right"));

        horizontalLayout_4->addWidget(radioButton_right);


        gridLayout->addLayout(horizontalLayout_4, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 300, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 2);


        retranslateUi(ShowSettingClass);

        QMetaObject::connectSlotsByName(ShowSettingClass);
    } // setupUi

    void retranslateUi(QWidget *ShowSettingClass)
    {
        ShowSettingClass->setWindowTitle(QCoreApplication::translate("ShowSettingClass", "ShowSetting", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("ShowSettingClass", "Display Language:", nullptr));
        radioButton_Chinese->setText(QCoreApplication::translate("ShowSettingClass", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));
        radioButton_English->setText(QCoreApplication::translate("ShowSettingClass", "English", nullptr));
        label_5->setText(QString());
        label_3->setText(QCoreApplication::translate("ShowSettingClass", "Display Logo:", nullptr));
        btn_ShowLogo->setText(QString());
        label_6->setText(QString());
        label_4->setText(QCoreApplication::translate("ShowSettingClass", "Custom Software Name:", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        label_7->setText(QCoreApplication::translate("ShowSettingClass", "\345\257\271\351\275\220\346\226\271\345\274\217", nullptr));
        radioButton_left->setText(QCoreApplication::translate("ShowSettingClass", "\345\267\246\345\257\271\351\275\220", nullptr));
        radioButton_middle->setText(QCoreApplication::translate("ShowSettingClass", "\345\261\205\344\270\255\345\257\271\351\275\220", nullptr));
        radioButton_right->setText(QCoreApplication::translate("ShowSettingClass", "\345\217\263\345\257\271\351\275\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowSettingClass: public Ui_ShowSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSETTING_H
