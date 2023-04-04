/********************************************************************************
** Form generated from reading UI file 'DockWidgetTitter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKWIDGETTITTER_H
#define UI_DOCKWIDGETTITTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DockWidgetTitterClass
{
public:

    void setupUi(QWidget *DockWidgetTitterClass)
    {
        if (DockWidgetTitterClass->objectName().isEmpty())
            DockWidgetTitterClass->setObjectName(QString::fromUtf8("DockWidgetTitterClass"));
        DockWidgetTitterClass->resize(600, 400);

        retranslateUi(DockWidgetTitterClass);

        QMetaObject::connectSlotsByName(DockWidgetTitterClass);
    } // setupUi

    void retranslateUi(QWidget *DockWidgetTitterClass)
    {
        DockWidgetTitterClass->setWindowTitle(QCoreApplication::translate("DockWidgetTitterClass", "DockWidgetTitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DockWidgetTitterClass: public Ui_DockWidgetTitterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKWIDGETTITTER_H
