/********************************************************************************
** Form generated from reading UI file 'ThresholdSegmentation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDSEGMENTATION_H
#define UI_THRESHOLDSEGMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThresholdSegmentationClass
{
public:

    void setupUi(QWidget *ThresholdSegmentationClass)
    {
        if (ThresholdSegmentationClass->objectName().isEmpty())
            ThresholdSegmentationClass->setObjectName(QString::fromUtf8("ThresholdSegmentationClass"));
        ThresholdSegmentationClass->resize(600, 400);

        retranslateUi(ThresholdSegmentationClass);

        QMetaObject::connectSlotsByName(ThresholdSegmentationClass);
    } // setupUi

    void retranslateUi(QWidget *ThresholdSegmentationClass)
    {
        ThresholdSegmentationClass->setWindowTitle(QCoreApplication::translate("ThresholdSegmentationClass", "ThresholdSegmentation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThresholdSegmentationClass: public Ui_ThresholdSegmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDSEGMENTATION_H
