/********************************************************************************
** Form generated from reading UI file 'SaveImageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEIMAGEWIDGET_H
#define UI_SAVEIMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveImageWidgetClass
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *MyGroupBox;
    QGridLayout *gridLayout_4;
    QCheckBox *CheckBox_EnableSave;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_ImgPath;
    QPushButton *btn_ChangePath;
    QLabel *label;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_ImgType;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_deleteNums;
    QLineEdit *lineEdit_deleteDays;
    QLineEdit *lineEdit_deleteMemory;
    QCheckBox *checkBox_deleteDays;
    QCheckBox *checkBox_deleteNums;
    QCheckBox *checkBox_deleteMemory;
    QLabel *label_3;

    void setupUi(QWidget *SaveImageWidgetClass)
    {
        if (SaveImageWidgetClass->objectName().isEmpty())
            SaveImageWidgetClass->setObjectName(QString::fromUtf8("SaveImageWidgetClass"));
        SaveImageWidgetClass->resize(463, 517);
        SaveImageWidgetClass->setStyleSheet(QString::fromUtf8("color:#E0E0E0;\n"
""));
        gridLayout_5 = new QGridLayout(SaveImageWidgetClass);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        MyGroupBox = new QGroupBox(SaveImageWidgetClass);
        MyGroupBox->setObjectName(QString::fromUtf8("MyGroupBox"));
        gridLayout_4 = new QGridLayout(MyGroupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        CheckBox_EnableSave = new QCheckBox(MyGroupBox);
        CheckBox_EnableSave->setObjectName(QString::fromUtf8("CheckBox_EnableSave"));

        gridLayout_4->addWidget(CheckBox_EnableSave, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(MyGroupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_ImgPath = new QLineEdit(groupBox_2);
        lineEdit_ImgPath->setObjectName(QString::fromUtf8("lineEdit_ImgPath"));
        lineEdit_ImgPath->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout->addWidget(lineEdit_ImgPath, 1, 1, 1, 1);

        btn_ChangePath = new QPushButton(groupBox_2);
        btn_ChangePath->setObjectName(QString::fromUtf8("btn_ChangePath"));
        btn_ChangePath->setMinimumSize(QSize(60, 0));
        btn_ChangePath->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"}"));

        gridLayout->addWidget(btn_ChangePath, 1, 2, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(MyGroupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        comboBox_ImgType = new QComboBox(groupBox_3);
        comboBox_ImgType->setObjectName(QString::fromUtf8("comboBox_ImgType"));
        comboBox_ImgType->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout_2->addWidget(comboBox_ImgType, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(MyGroupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit_deleteNums = new QLineEdit(groupBox_4);
        lineEdit_deleteNums->setObjectName(QString::fromUtf8("lineEdit_deleteNums"));
        lineEdit_deleteNums->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout_3->addWidget(lineEdit_deleteNums, 1, 1, 1, 1);

        lineEdit_deleteDays = new QLineEdit(groupBox_4);
        lineEdit_deleteDays->setObjectName(QString::fromUtf8("lineEdit_deleteDays"));
        lineEdit_deleteDays->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout_3->addWidget(lineEdit_deleteDays, 2, 1, 1, 1);

        lineEdit_deleteMemory = new QLineEdit(groupBox_4);
        lineEdit_deleteMemory->setObjectName(QString::fromUtf8("lineEdit_deleteMemory"));
        lineEdit_deleteMemory->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        gridLayout_3->addWidget(lineEdit_deleteMemory, 3, 1, 1, 1);

        checkBox_deleteDays = new QCheckBox(groupBox_4);
        checkBox_deleteDays->setObjectName(QString::fromUtf8("checkBox_deleteDays"));

        gridLayout_3->addWidget(checkBox_deleteDays, 2, 0, 1, 1);

        checkBox_deleteNums = new QCheckBox(groupBox_4);
        checkBox_deleteNums->setObjectName(QString::fromUtf8("checkBox_deleteNums"));

        gridLayout_3->addWidget(checkBox_deleteNums, 1, 0, 1, 1);

        checkBox_deleteMemory = new QCheckBox(groupBox_4);
        checkBox_deleteMemory->setObjectName(QString::fromUtf8("checkBox_deleteMemory"));

        gridLayout_3->addWidget(checkBox_deleteMemory, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 30));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_4, 3, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 2);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setRowStretch(3, 3);

        gridLayout_5->addWidget(MyGroupBox, 0, 0, 1, 1);


        retranslateUi(SaveImageWidgetClass);

        QMetaObject::connectSlotsByName(SaveImageWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *SaveImageWidgetClass)
    {
        SaveImageWidgetClass->setWindowTitle(QCoreApplication::translate("SaveImageWidgetClass", "SaveImageWidget", nullptr));
        MyGroupBox->setTitle(QString());
        CheckBox_EnableSave->setText(QCoreApplication::translate("SaveImageWidgetClass", "Save Original Image", nullptr));
        groupBox_2->setTitle(QString());
        btn_ChangePath->setText(QCoreApplication::translate("SaveImageWidgetClass", "Browse", nullptr));
        label->setText(QCoreApplication::translate("SaveImageWidgetClass", "Image Type and Location", nullptr));
        label_4->setText(QCoreApplication::translate("SaveImageWidgetClass", "Path:", nullptr));
        groupBox_3->setTitle(QString());
        label_2->setText(QCoreApplication::translate("SaveImageWidgetClass", "Image Type", nullptr));
        groupBox_4->setTitle(QString());
        checkBox_deleteDays->setText(QCoreApplication::translate("SaveImageWidgetClass", "Days to keep Images ", nullptr));
        checkBox_deleteNums->setText(QCoreApplication::translate("SaveImageWidgetClass", "Maximum number of images", nullptr));
        checkBox_deleteMemory->setText(QCoreApplication::translate("SaveImageWidgetClass", "Disk capacity lower than", nullptr));
        label_3->setText(QCoreApplication::translate("SaveImageWidgetClass", "Delete Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveImageWidgetClass: public Ui_SaveImageWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEIMAGEWIDGET_H
