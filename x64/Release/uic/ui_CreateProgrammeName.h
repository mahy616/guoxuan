/********************************************************************************
** Form generated from reading UI file 'CreateProgrammeName.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROGRAMMENAME_H
#define UI_CREATEPROGRAMMENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateProgrammeNameClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ProName;
    QPushButton *btn_Create;

    void setupUi(QWidget *CreateProgrammeNameClass)
    {
        if (CreateProgrammeNameClass->objectName().isEmpty())
            CreateProgrammeNameClass->setObjectName(QString::fromUtf8("CreateProgrammeNameClass"));
        CreateProgrammeNameClass->resize(602, 160);
        gridLayout = new QGridLayout(CreateProgrammeNameClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CreateProgrammeNameClass);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit_ProName = new QLineEdit(CreateProgrammeNameClass);
        lineEdit_ProName->setObjectName(QString::fromUtf8("lineEdit_ProName"));
        lineEdit_ProName->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        lineEdit_ProName->setFont(font1);

        horizontalLayout->addWidget(lineEdit_ProName);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        btn_Create = new QPushButton(CreateProgrammeNameClass);
        btn_Create->setObjectName(QString::fromUtf8("btn_Create"));
        btn_Create->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        btn_Create->setFont(font2);

        gridLayout->addWidget(btn_Create, 1, 0, 1, 1);


        retranslateUi(CreateProgrammeNameClass);

        QMetaObject::connectSlotsByName(CreateProgrammeNameClass);
    } // setupUi

    void retranslateUi(QWidget *CreateProgrammeNameClass)
    {
        CreateProgrammeNameClass->setWindowTitle(QCoreApplication::translate("CreateProgrammeNameClass", "New Programme", nullptr));
        label->setText(QCoreApplication::translate("CreateProgrammeNameClass", "Recipe Name:", nullptr));
        btn_Create->setText(QCoreApplication::translate("CreateProgrammeNameClass", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateProgrammeNameClass: public Ui_CreateProgrammeNameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROGRAMMENAME_H
