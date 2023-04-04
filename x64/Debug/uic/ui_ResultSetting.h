/********************************************************************************
** Form generated from reading UI file 'ResultSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSETTING_H
#define UI_RESULTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultSetting
{
public:

    void setupUi(QWidget *ResultSetting)
    {
        if (ResultSetting->objectName().isEmpty())
            ResultSetting->setObjectName(QString::fromUtf8("ResultSetting"));
        ResultSetting->resize(400, 300);

        retranslateUi(ResultSetting);

        QMetaObject::connectSlotsByName(ResultSetting);
    } // setupUi

    void retranslateUi(QWidget *ResultSetting)
    {
        ResultSetting->setWindowTitle(QCoreApplication::translate("ResultSetting", "ResultSetting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultSetting: public Ui_ResultSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSETTING_H
