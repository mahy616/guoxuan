/********************************************************************************
** Form generated from reading UI file 'DynamicWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMICWIDGET_H
#define UI_DYNAMICWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "UI/mytitlebar.h"
#include "UI/mytoolbar.h"

QT_BEGIN_NAMESPACE

class Ui_DynamicWidgetClass
{
public:
    QAction *actionCameraStart;
    QAction *actionCameraStop;
    QAction *actionAddWindow;
    QAction *actionSystemSet;
    QAction *actionFileStart;
    QAction *actionFileStop;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *MyWindowWidget;
    MyTitleBar *toolBar_TitleBar;
    MyToolBar *toolBar_Tool;

    void setupUi(QMainWindow *DynamicWidgetClass)
    {
        if (DynamicWidgetClass->objectName().isEmpty())
            DynamicWidgetClass->setObjectName(QString::fromUtf8("DynamicWidgetClass"));
        DynamicWidgetClass->resize(1415, 937);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/DynamicWidget/Resource/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DynamicWidgetClass->setWindowIcon(icon);
        DynamicWidgetClass->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 32, 32);\n"
""));
        actionCameraStart = new QAction(DynamicWidgetClass);
        actionCameraStart->setObjectName(QString::fromUtf8("actionCameraStart"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/DynamicWidget/Resource/CameraStart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCameraStart->setIcon(icon1);
        actionCameraStop = new QAction(DynamicWidgetClass);
        actionCameraStop->setObjectName(QString::fromUtf8("actionCameraStop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/DynamicWidget/Resource/CameraStop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCameraStop->setIcon(icon2);
        actionAddWindow = new QAction(DynamicWidgetClass);
        actionAddWindow->setObjectName(QString::fromUtf8("actionAddWindow"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/DynamicWidget/Resource/AddWindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddWindow->setIcon(icon3);
        actionSystemSet = new QAction(DynamicWidgetClass);
        actionSystemSet->setObjectName(QString::fromUtf8("actionSystemSet"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/DynamicWidget/Resource/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSystemSet->setIcon(icon4);
        actionFileStart = new QAction(DynamicWidgetClass);
        actionFileStart->setObjectName(QString::fromUtf8("actionFileStart"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/DynamicWidget/Resource/FileStart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileStart->setIcon(icon5);
        actionFileStop = new QAction(DynamicWidgetClass);
        actionFileStop->setObjectName(QString::fromUtf8("actionFileStop"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/DynamicWidget/Resource/FileStop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileStop->setIcon(icon6);
        centralWidget = new QWidget(DynamicWidgetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMaximumSize(QSize(100000, 100000));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MyWindowWidget = new QWidget(centralWidget);
        MyWindowWidget->setObjectName(QString::fromUtf8("MyWindowWidget"));
        MyWindowWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 32, 32);\n"
""));

        gridLayout->addWidget(MyWindowWidget, 0, 0, 1, 1);

        DynamicWidgetClass->setCentralWidget(centralWidget);
        toolBar_TitleBar = new MyTitleBar(DynamicWidgetClass);
        toolBar_TitleBar->setObjectName(QString::fromUtf8("toolBar_TitleBar"));
        toolBar_TitleBar->setMinimumSize(QSize(0, 50));
        toolBar_TitleBar->setMaximumSize(QSize(16777215, 50));
        DynamicWidgetClass->addToolBar(Qt::TopToolBarArea, toolBar_TitleBar);
        toolBar_Tool = new MyToolBar(DynamicWidgetClass);
        toolBar_Tool->setObjectName(QString::fromUtf8("toolBar_Tool"));
        toolBar_Tool->setMinimumSize(QSize(0, 50));
        toolBar_Tool->setMaximumSize(QSize(16777215, 50));
        DynamicWidgetClass->addToolBar(Qt::TopToolBarArea, toolBar_Tool);
        DynamicWidgetClass->insertToolBarBreak(toolBar_Tool);

        retranslateUi(DynamicWidgetClass);

        QMetaObject::connectSlotsByName(DynamicWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *DynamicWidgetClass)
    {
        DynamicWidgetClass->setWindowTitle(QCoreApplication::translate("DynamicWidgetClass", "DynamicWidget", nullptr));
        actionCameraStart->setText(QCoreApplication::translate("DynamicWidgetClass", "\347\233\270\346\234\272\345\274\200\345\247\213\345\267\245\344\275\234", nullptr));
        actionCameraStop->setText(QCoreApplication::translate("DynamicWidgetClass", "\347\233\270\346\234\272\345\201\234\346\255\242\345\267\245\344\275\234", nullptr));
        actionAddWindow->setText(QCoreApplication::translate("DynamicWidgetClass", "\346\267\273\345\212\240\347\252\227\345\217\243", nullptr));
        actionSystemSet->setText(QCoreApplication::translate("DynamicWidgetClass", "\350\256\276\347\275\256", nullptr));
        actionFileStart->setText(QCoreApplication::translate("DynamicWidgetClass", "\345\276\252\347\216\257\350\257\273\345\217\226\346\226\207\344\273\266\345\244\271", nullptr));
        actionFileStop->setText(QCoreApplication::translate("DynamicWidgetClass", "\345\201\234\346\255\242\350\257\273\345\217\226\346\226\207\344\273\266\345\244\271", nullptr));
        toolBar_TitleBar->setWindowTitle(QCoreApplication::translate("DynamicWidgetClass", "toolBar", nullptr));
        toolBar_Tool->setWindowTitle(QCoreApplication::translate("DynamicWidgetClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DynamicWidgetClass: public Ui_DynamicWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMICWIDGET_H
