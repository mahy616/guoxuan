/********************************************************************************
** Form generated from reading UI file 'AddCommunicationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMMUNICATIONDIALOG_H
#define UI_ADDCOMMUNICATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCommunicationDialogClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_CommunicateName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_CommunicateType;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Cancel;
    QPushButton *btn_Determine;

    void setupUi(QWidget *AddCommunicationDialogClass)
    {
        if (AddCommunicationDialogClass->objectName().isEmpty())
            AddCommunicationDialogClass->setObjectName(QString::fromUtf8("AddCommunicationDialogClass"));
        AddCommunicationDialogClass->resize(469, 255);
        gridLayout = new QGridLayout(AddCommunicationDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AddCommunicationDialogClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(180, 30));
        label->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_2->addWidget(label);

        lineEdit_CommunicateName = new QLineEdit(AddCommunicationDialogClass);
        lineEdit_CommunicateName->setObjectName(QString::fromUtf8("lineEdit_CommunicateName"));
        lineEdit_CommunicateName->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(lineEdit_CommunicateName);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(AddCommunicationDialogClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(180, 16777215));
        QFont font;
        font.setPointSize(8);
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        comboBox_CommunicateType = new QComboBox(AddCommunicationDialogClass);
        comboBox_CommunicateType->setObjectName(QString::fromUtf8("comboBox_CommunicateType"));
        comboBox_CommunicateType->setMinimumSize(QSize(200, 30));

        horizontalLayout_3->addWidget(comboBox_CommunicateType);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_Cancel = new QPushButton(AddCommunicationDialogClass);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(btn_Cancel);

        btn_Determine = new QPushButton(AddCommunicationDialogClass);
        btn_Determine->setObjectName(QString::fromUtf8("btn_Determine"));
        btn_Determine->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(btn_Determine);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(AddCommunicationDialogClass);

        QMetaObject::connectSlotsByName(AddCommunicationDialogClass);
    } // setupUi

    void retranslateUi(QWidget *AddCommunicationDialogClass)
    {
        AddCommunicationDialogClass->setWindowTitle(QCoreApplication::translate("AddCommunicationDialogClass", "Add Communication Object", nullptr));
        label->setText(QCoreApplication::translate("AddCommunicationDialogClass", "Communication Name\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddCommunicationDialogClass", "Communication Protocol:", nullptr));
        btn_Cancel->setText(QCoreApplication::translate("AddCommunicationDialogClass", "Cancel", nullptr));
        btn_Determine->setText(QCoreApplication::translate("AddCommunicationDialogClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCommunicationDialogClass: public Ui_AddCommunicationDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMMUNICATIONDIALOG_H
