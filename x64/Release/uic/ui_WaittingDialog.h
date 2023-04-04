/********************************************************************************
** Form generated from reading UI file 'WaittingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITTINGDIALOG_H
#define UI_WAITTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaittingDialogClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label_Name;
    QLabel *label_wait;

    void setupUi(QWidget *WaittingDialogClass)
    {
        if (WaittingDialogClass->objectName().isEmpty())
            WaittingDialogClass->setObjectName(QString::fromUtf8("WaittingDialogClass"));
        WaittingDialogClass->resize(247, 40);
        WaittingDialogClass->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(70, 70, 70);\n"
""));
        gridLayout = new QGridLayout(WaittingDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(8, 0, 5, 0);
        label_Name = new QLabel(WaittingDialogClass);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Name, 0, 0, 1, 1);

        label_wait = new QLabel(WaittingDialogClass);
        label_wait->setObjectName(QString::fromUtf8("label_wait"));
        QFont font;
        font.setFamily(QString::fromUtf8("KaiTi"));
        font.setPointSize(12);
        label_wait->setFont(font);

        gridLayout->addWidget(label_wait, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);

        retranslateUi(WaittingDialogClass);

        QMetaObject::connectSlotsByName(WaittingDialogClass);
    } // setupUi

    void retranslateUi(QWidget *WaittingDialogClass)
    {
        WaittingDialogClass->setWindowTitle(QCoreApplication::translate("WaittingDialogClass", "WaittingDialog", nullptr));
        label_Name->setText(QString());
        label_wait->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WaittingDialogClass: public Ui_WaittingDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITTINGDIALOG_H
