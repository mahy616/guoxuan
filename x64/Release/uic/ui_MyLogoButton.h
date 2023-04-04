/********************************************************************************
** Form generated from reading UI file 'MyLogoButton.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLOGOBUTTON_H
#define UI_MYLOGOBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyLogoButtonClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Logo;
    QLabel *label_Name;

    void setupUi(QWidget *MyLogoButtonClass)
    {
        if (MyLogoButtonClass->objectName().isEmpty())
            MyLogoButtonClass->setObjectName(QString::fromUtf8("MyLogoButtonClass"));
        MyLogoButtonClass->resize(112, 29);
        gridLayout = new QGridLayout(MyLogoButtonClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MyLogoButtonClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("color: #999999;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label_Logo = new QLabel(widget);
        label_Logo->setObjectName(QString::fromUtf8("label_Logo"));
        label_Logo->setMinimumSize(QSize(18, 18));
        label_Logo->setMaximumSize(QSize(60, 60));
        label_Logo->setStyleSheet(QString::fromUtf8("background:transparent;\n"
""));

        horizontalLayout->addWidget(label_Logo);

        label_Name = new QLabel(widget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(6);
        label_Name->setFont(font);
        label_Name->setStyleSheet(QString::fromUtf8("background:transparent;\n"
""));

        horizontalLayout->addWidget(label_Name);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(MyLogoButtonClass);

        QMetaObject::connectSlotsByName(MyLogoButtonClass);
    } // setupUi

    void retranslateUi(QWidget *MyLogoButtonClass)
    {
        MyLogoButtonClass->setWindowTitle(QCoreApplication::translate("MyLogoButtonClass", "MyLogoButton", nullptr));
        label_Logo->setText(QString());
        label_Name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyLogoButtonClass: public Ui_MyLogoButtonClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLOGOBUTTON_H
