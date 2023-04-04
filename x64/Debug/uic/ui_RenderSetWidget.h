/********************************************************************************
** Form generated from reading UI file 'RenderSetWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERSETWIDGET_H
#define UI_RENDERSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderSetWidgetClass
{
public:

    void setupUi(QWidget *RenderSetWidgetClass)
    {
        if (RenderSetWidgetClass->objectName().isEmpty())
            RenderSetWidgetClass->setObjectName(QString::fromUtf8("RenderSetWidgetClass"));
        RenderSetWidgetClass->resize(600, 400);

        retranslateUi(RenderSetWidgetClass);

        QMetaObject::connectSlotsByName(RenderSetWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *RenderSetWidgetClass)
    {
        RenderSetWidgetClass->setWindowTitle(QCoreApplication::translate("RenderSetWidgetClass", "RenderSetWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderSetWidgetClass: public Ui_RenderSetWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERSETWIDGET_H
