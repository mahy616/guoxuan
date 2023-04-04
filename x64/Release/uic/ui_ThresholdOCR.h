/********************************************************************************
** Form generated from reading UI file 'ThresholdOCR.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDOCR_H
#define UI_THRESHOLDOCR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThresholdOCRClass
{
public:

    void setupUi(QWidget *ThresholdOCRClass)
    {
        if (ThresholdOCRClass->objectName().isEmpty())
            ThresholdOCRClass->setObjectName(QString::fromUtf8("ThresholdOCRClass"));
        ThresholdOCRClass->resize(600, 400);

        retranslateUi(ThresholdOCRClass);

        QMetaObject::connectSlotsByName(ThresholdOCRClass);
    } // setupUi

    void retranslateUi(QWidget *ThresholdOCRClass)
    {
        ThresholdOCRClass->setWindowTitle(QCoreApplication::translate("ThresholdOCRClass", "ThresholdOCR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThresholdOCRClass: public Ui_ThresholdOCRClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDOCR_H
