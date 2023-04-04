/********************************************************************************
** Form generated from reading UI file 'ThresholdClassification.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDCLASSIFICATION_H
#define UI_THRESHOLDCLASSIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThresholdClassificationClass
{
public:

    void setupUi(QWidget *ThresholdClassificationClass)
    {
        if (ThresholdClassificationClass->objectName().isEmpty())
            ThresholdClassificationClass->setObjectName(QString::fromUtf8("ThresholdClassificationClass"));
        ThresholdClassificationClass->resize(600, 400);

        retranslateUi(ThresholdClassificationClass);

        QMetaObject::connectSlotsByName(ThresholdClassificationClass);
    } // setupUi

    void retranslateUi(QWidget *ThresholdClassificationClass)
    {
        ThresholdClassificationClass->setWindowTitle(QCoreApplication::translate("ThresholdClassificationClass", "ThresholdClassification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThresholdClassificationClass: public Ui_ThresholdClassificationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDCLASSIFICATION_H
