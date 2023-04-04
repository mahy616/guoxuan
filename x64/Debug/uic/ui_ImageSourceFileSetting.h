/********************************************************************************
** Form generated from reading UI file 'ImageSourceFileSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESOURCEFILESETTING_H
#define UI_IMAGESOURCEFILESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSourceFileSettingClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Path;
    QPushButton *btn_ChangeRoad;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ImageSourceFileSettingClass)
    {
        if (ImageSourceFileSettingClass->objectName().isEmpty())
            ImageSourceFileSettingClass->setObjectName(QString::fromUtf8("ImageSourceFileSettingClass"));
        ImageSourceFileSettingClass->resize(950, 572);
        gridLayout = new QGridLayout(ImageSourceFileSettingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ImageSourceFileSettingClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(label);

        lineEdit_Path = new QLineEdit(ImageSourceFileSettingClass);
        lineEdit_Path->setObjectName(QString::fromUtf8("lineEdit_Path"));
        lineEdit_Path->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(lineEdit_Path);

        btn_ChangeRoad = new QPushButton(ImageSourceFileSettingClass);
        btn_ChangeRoad->setObjectName(QString::fromUtf8("btn_ChangeRoad"));
        btn_ChangeRoad->setMinimumSize(QSize(80, 30));
        btn_ChangeRoad->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#000426;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(65,65,65);\n"
"}\n"
""));

        horizontalLayout->addWidget(btn_ChangeRoad);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 503, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(ImageSourceFileSettingClass);

        QMetaObject::connectSlotsByName(ImageSourceFileSettingClass);
    } // setupUi

    void retranslateUi(QWidget *ImageSourceFileSettingClass)
    {
        ImageSourceFileSettingClass->setWindowTitle(QCoreApplication::translate("ImageSourceFileSettingClass", "ImageSourceFileSetting", nullptr));
        label->setText(QCoreApplication::translate("ImageSourceFileSettingClass", "Folder Location", nullptr));
        btn_ChangeRoad->setText(QCoreApplication::translate("ImageSourceFileSettingClass", "Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSourceFileSettingClass: public Ui_ImageSourceFileSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESOURCEFILESETTING_H
