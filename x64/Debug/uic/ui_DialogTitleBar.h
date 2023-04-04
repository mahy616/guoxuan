/********************************************************************************
** Form generated from reading UI file 'DialogTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTITLEBAR_H
#define UI_DIALOGTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTitleBarClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Title;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Close;

    void setupUi(QWidget *DialogTitleBarClass)
    {
        if (DialogTitleBarClass->objectName().isEmpty())
            DialogTitleBarClass->setObjectName(QString::fromUtf8("DialogTitleBarClass"));
        DialogTitleBarClass->resize(547, 43);
        DialogTitleBarClass->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background: \"transparent\";\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"background: #E6E6E6;\n"
"border-top-left-radius:8px;\n"
"border-top-right-radius:8px;\n"
"box-shadow: inset 0px 1px 0px rgba(255, 255, 255, 0.25), inset 0px -1px 0px rgba(0, 0, 0, 0.25);\n"
"}"));
        gridLayout = new QGridLayout(DialogTitleBarClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(DialogTitleBarClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, -1, 2);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(35, 35));
        label->setMaximumSize(QSize(35, 35));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_Title = new QLabel(widget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        label_Title->setFont(font);

        horizontalLayout->addWidget(label_Title);

        horizontalSpacer_2 = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_Close = new QPushButton(widget);
        btn_Close->setObjectName(QString::fromUtf8("btn_Close"));
        btn_Close->setMinimumSize(QSize(18, 18));
        btn_Close->setMaximumSize(QSize(18, 18));
        btn_Close->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	border-image:url(\":/DynamicWidget/Resource/TitterClose.png\");	\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-image:url(\":/DynamicWidget/Resource/TitterClose.png\");\n"
"	background-color:#ADADAD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border-image:url(\":/DynamicWidget/Resource/TitterClose.png\");\n"
"	background-color:#949494;\n"
"}"));

        horizontalLayout->addWidget(btn_Close);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(DialogTitleBarClass);

        QMetaObject::connectSlotsByName(DialogTitleBarClass);
    } // setupUi

    void retranslateUi(QWidget *DialogTitleBarClass)
    {
        DialogTitleBarClass->setWindowTitle(QCoreApplication::translate("DialogTitleBarClass", "DialogTitleBar", nullptr));
        label->setText(QString());
        label_Title->setText(QCoreApplication::translate("DialogTitleBarClass", "TextLabel", nullptr));
        btn_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogTitleBarClass: public Ui_DialogTitleBarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTITLEBAR_H
