/********************************************************************************
** Form generated from reading UI file 'ImageSourceSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESOURCESETTING_H
#define UI_IMAGESOURCESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSourceSettingClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_3;
    QRadioButton *radioButton_Camera;
    QLabel *label_4;
    QRadioButton *radioButton_FileImage;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_ImageContent;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Cancel;
    QLabel *label_2;
    QPushButton *btn_Save;

    void setupUi(QWidget *ImageSourceSettingClass)
    {
        if (ImageSourceSettingClass->objectName().isEmpty())
            ImageSourceSettingClass->setObjectName(QString::fromUtf8("ImageSourceSettingClass"));
        ImageSourceSettingClass->resize(1088, 802);
        ImageSourceSettingClass->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size: 11pt;\n"
"background: #323232;"));
        gridLayout = new QGridLayout(ImageSourceSettingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ImageSourceSettingClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("KaiTi"));
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(ImageSourceSettingClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(30, 0));

        horizontalLayout->addWidget(label_3);

        radioButton_Camera = new QRadioButton(ImageSourceSettingClass);
        radioButton_Camera->setObjectName(QString::fromUtf8("radioButton_Camera"));
        radioButton_Camera->setMaximumSize(QSize(120, 16777215));
        radioButton_Camera->setFont(font);

        horizontalLayout->addWidget(radioButton_Camera);

        label_4 = new QLabel(ImageSourceSettingClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(30, 0));

        horizontalLayout->addWidget(label_4);

        radioButton_FileImage = new QRadioButton(ImageSourceSettingClass);
        radioButton_FileImage->setObjectName(QString::fromUtf8("radioButton_FileImage"));
        radioButton_FileImage->setFont(font);

        horizontalLayout->addWidget(radioButton_FileImage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        groupBox_ImageContent = new QGroupBox(ImageSourceSettingClass);
        groupBox_ImageContent->setObjectName(QString::fromUtf8("groupBox_ImageContent"));

        gridLayout->addWidget(groupBox_ImageContent, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_Cancel = new QPushButton(ImageSourceSettingClass);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setMinimumSize(QSize(100, 35));
        btn_Cancel->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
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

        label_2 = new QLabel(ImageSourceSettingClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(10, 0));

        horizontalLayout_2->addWidget(label_2);

        btn_Save = new QPushButton(ImageSourceSettingClass);
        btn_Save->setObjectName(QString::fromUtf8("btn_Save"));
        btn_Save->setMinimumSize(QSize(100, 35));
        btn_Save->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
"}"));

        horizontalLayout_2->addWidget(btn_Save);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 13);
        gridLayout->setRowStretch(2, 1);

        retranslateUi(ImageSourceSettingClass);

        QMetaObject::connectSlotsByName(ImageSourceSettingClass);
    } // setupUi

    void retranslateUi(QWidget *ImageSourceSettingClass)
    {
        ImageSourceSettingClass->setWindowTitle(QCoreApplication::translate("ImageSourceSettingClass", "Image Source Settings", nullptr));
        label->setText(QCoreApplication::translate("ImageSourceSettingClass", "Choose Image Source:", nullptr));
        label_3->setText(QString());
        radioButton_Camera->setText(QCoreApplication::translate("ImageSourceSettingClass", "Camera", nullptr));
        label_4->setText(QString());
        radioButton_FileImage->setText(QCoreApplication::translate("ImageSourceSettingClass", "Local Image", nullptr));
        groupBox_ImageContent->setTitle(QString());
        btn_Cancel->setText(QCoreApplication::translate("ImageSourceSettingClass", "Cancel", nullptr));
        label_2->setText(QString());
        btn_Save->setText(QCoreApplication::translate("ImageSourceSettingClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSourceSettingClass: public Ui_ImageSourceSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESOURCESETTING_H
