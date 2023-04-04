/********************************************************************************
** Form generated from reading UI file 'ProgrammeMannger.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMEMANNGER_H
#define UI_PROGRAMMEMANNGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammeManngerClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_Pro;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_programmName;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_CreatePro;
    QLabel *label;
    QPushButton *btn_DeletePro;
    QLabel *label_2;
    QPushButton *btn_ChangePro;
    QLabel *label_3;
    QPushButton *btn_DefaultPro;
    QLabel *label_4;
    QPushButton *btn_SavePro;

    void setupUi(QWidget *ProgrammeManngerClass)
    {
        if (ProgrammeManngerClass->objectName().isEmpty())
            ProgrammeManngerClass->setObjectName(QString::fromUtf8("ProgrammeManngerClass"));
        ProgrammeManngerClass->resize(684, 530);
        ProgrammeManngerClass->setStyleSheet(QString::fromUtf8("color:#E0E0E0;"));
        gridLayout = new QGridLayout(ProgrammeManngerClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget_Pro = new QTableWidget(ProgrammeManngerClass);
        tableWidget_Pro->setObjectName(QString::fromUtf8("tableWidget_Pro"));

        horizontalLayout->addWidget(tableWidget_Pro);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(ProgrammeManngerClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(10);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_programmName = new QLabel(ProgrammeManngerClass);
        label_programmName->setObjectName(QString::fromUtf8("label_programmName"));
        label_programmName->setMinimumSize(QSize(0, 60));
        label_programmName->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        label_programmName->setFont(font1);
        label_programmName->setStyleSheet(QString::fromUtf8("color:red;"));

        verticalLayout->addWidget(label_programmName);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_CreatePro = new QPushButton(ProgrammeManngerClass);
        btn_CreatePro->setObjectName(QString::fromUtf8("btn_CreatePro"));
        btn_CreatePro->setMinimumSize(QSize(0, 50));
        btn_CreatePro->setMaximumSize(QSize(200, 16777215));
        btn_CreatePro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout->addWidget(btn_CreatePro);

        label = new QLabel(ProgrammeManngerClass);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        btn_DeletePro = new QPushButton(ProgrammeManngerClass);
        btn_DeletePro->setObjectName(QString::fromUtf8("btn_DeletePro"));
        btn_DeletePro->setMinimumSize(QSize(0, 50));
        btn_DeletePro->setMaximumSize(QSize(200, 16777215));
        btn_DeletePro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout->addWidget(btn_DeletePro);

        label_2 = new QLabel(ProgrammeManngerClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        btn_ChangePro = new QPushButton(ProgrammeManngerClass);
        btn_ChangePro->setObjectName(QString::fromUtf8("btn_ChangePro"));
        btn_ChangePro->setMinimumSize(QSize(0, 50));
        btn_ChangePro->setMaximumSize(QSize(200, 16777215));
        btn_ChangePro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout->addWidget(btn_ChangePro);

        label_3 = new QLabel(ProgrammeManngerClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        btn_DefaultPro = new QPushButton(ProgrammeManngerClass);
        btn_DefaultPro->setObjectName(QString::fromUtf8("btn_DefaultPro"));
        btn_DefaultPro->setMinimumSize(QSize(0, 50));
        btn_DefaultPro->setMaximumSize(QSize(200, 16777215));
        btn_DefaultPro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout->addWidget(btn_DefaultPro);

        label_4 = new QLabel(ProgrammeManngerClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        btn_SavePro = new QPushButton(ProgrammeManngerClass);
        btn_SavePro->setObjectName(QString::fromUtf8("btn_SavePro"));
        btn_SavePro->setMinimumSize(QSize(0, 50));
        btn_SavePro->setMaximumSize(QSize(200, 16777215));
        btn_SavePro->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout->addWidget(btn_SavePro);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ProgrammeManngerClass);

        QMetaObject::connectSlotsByName(ProgrammeManngerClass);
    } // setupUi

    void retranslateUi(QWidget *ProgrammeManngerClass)
    {
        ProgrammeManngerClass->setWindowTitle(QCoreApplication::translate("ProgrammeManngerClass", "ProgrammeMannger", nullptr));
        label_5->setText(QCoreApplication::translate("ProgrammeManngerClass", "Current Recipe:", nullptr));
        label_programmName->setText(QString());
        btn_CreatePro->setText(QCoreApplication::translate("ProgrammeManngerClass", "New", nullptr));
        label->setText(QString());
        btn_DeletePro->setText(QCoreApplication::translate("ProgrammeManngerClass", "Delete", nullptr));
        label_2->setText(QString());
        btn_ChangePro->setText(QCoreApplication::translate("ProgrammeManngerClass", "Set as Current", nullptr));
        label_3->setText(QString());
        btn_DefaultPro->setText(QCoreApplication::translate("ProgrammeManngerClass", "Set as Default", nullptr));
        label_4->setText(QString());
        btn_SavePro->setText(QCoreApplication::translate("ProgrammeManngerClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgrammeManngerClass: public Ui_ProgrammeManngerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMEMANNGER_H
