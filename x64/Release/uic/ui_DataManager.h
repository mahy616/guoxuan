/********************************************************************************
** Form generated from reading UI file 'DataManager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMANAGER_H
#define UI_DATAMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataManager
{
public:
    QWidget *widget_content;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_out;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Code;
    QToolButton *toolButton_chooseTime;
    QDateEdit *dateEdit_StartDate;
    QDateEdit *dateEdit_EndDate;
    QPushButton *pushButton_Query;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_close;
    QWidget *widget_title;
    QLabel *label;

    void setupUi(QDialog *DataManager)
    {
        if (DataManager->objectName().isEmpty())
            DataManager->setObjectName(QString::fromUtf8("DataManager"));
        DataManager->setEnabled(true);
        DataManager->resize(1008, 608);
        DataManager->setMinimumSize(QSize(1008, 608));
        DataManager->setMaximumSize(QSize(1008, 608));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CMainWindow/Resources/data.png"), QSize(), QIcon::Normal, QIcon::Off);
        DataManager->setWindowIcon(icon);
        DataManager->setStyleSheet(QString::fromUtf8(""));
        widget_content = new QWidget(DataManager);
        widget_content->setObjectName(QString::fromUtf8("widget_content"));
        widget_content->setGeometry(QRect(0, 29, 1011, 581));
        widget_content->setStyleSheet(QString::fromUtf8("background: white;"));
        verticalLayout = new QVBoxLayout(widget_content);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_content);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setEnabled(true);
        widget_3->setMinimumSize(QSize(0, 50));
        widget_3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(24, -1, -1, -1);
        pushButton_clear = new QPushButton(widget_3);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(80, 24));
        pushButton_clear->setMaximumSize(QSize(80, 24));
        pushButton_clear->setStyleSheet(QString::fromUtf8("	border: 1px solid rgba(22, 59, 102, 1);\n"
"	border-radius: 4px;\n"
"color: rgba(22, 59, 102, 1);\n"
"font-size:16px;"));
        pushButton_clear->setFlat(true);

        horizontalLayout->addWidget(pushButton_clear);

        pushButton_out = new QPushButton(widget_3);
        pushButton_out->setObjectName(QString::fromUtf8("pushButton_out"));
        pushButton_out->setMinimumSize(QSize(80, 24));
        pushButton_out->setMaximumSize(QSize(80, 24));
        pushButton_out->setStyleSheet(QString::fromUtf8("	border: 1px solid rgba(22, 59, 102, 1);\n"
"	border-radius: 4px;\n"
"color: rgba(22, 59, 102, 1);\n"
"font-size:16px;"));
        pushButton_out->setFlat(true);

        horizontalLayout->addWidget(pushButton_out);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_content);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(24, -1, 24, -1);
        lineEdit_Code = new QLineEdit(widget_4);
        lineEdit_Code->setObjectName(QString::fromUtf8("lineEdit_Code"));
        lineEdit_Code->setMinimumSize(QSize(400, 32));
        lineEdit_Code->setMaximumSize(QSize(400, 32));
        lineEdit_Code->setStyleSheet(QString::fromUtf8("	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;"));

        horizontalLayout_2->addWidget(lineEdit_Code);

        toolButton_chooseTime = new QToolButton(widget_4);
        toolButton_chooseTime->setObjectName(QString::fromUtf8("toolButton_chooseTime"));
        toolButton_chooseTime->setMinimumSize(QSize(16, 16));
        toolButton_chooseTime->setMaximumSize(QSize(16, 16));
        toolButton_chooseTime->setStyleSheet(QString::fromUtf8("	border: 1px solid rgba(22, 59, 102, 1);\n"
"	border-radius: 4px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/config/no_selected.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/config/selected.svg"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_chooseTime->setIcon(icon1);
        toolButton_chooseTime->setCheckable(true);

        horizontalLayout_2->addWidget(toolButton_chooseTime);

        dateEdit_StartDate = new QDateEdit(widget_4);
        dateEdit_StartDate->setObjectName(QString::fromUtf8("dateEdit_StartDate"));
        dateEdit_StartDate->setStyleSheet(QString::fromUtf8("	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"color:rgba(0, 0, 0, 0.25);"));
        dateEdit_StartDate->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_StartDate);

        dateEdit_EndDate = new QDateEdit(widget_4);
        dateEdit_EndDate->setObjectName(QString::fromUtf8("dateEdit_EndDate"));
        dateEdit_EndDate->setStyleSheet(QString::fromUtf8("	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"color:rgba(0, 0, 0, 0.25);"));
        dateEdit_EndDate->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_EndDate);

        pushButton_Query = new QPushButton(widget_4);
        pushButton_Query->setObjectName(QString::fromUtf8("pushButton_Query"));
        pushButton_Query->setMinimumSize(QSize(80, 32));
        pushButton_Query->setMaximumSize(QSize(80, 32));
        pushButton_Query->setStyleSheet(QString::fromUtf8("	border: 1px solid rgba(22, 59, 102, 1);\n"
"	border-radius: 4px;\n"
"	color: #FFFFFF;\n"
"    font-size: 14px;\n"
"	background-color:rgba(22, 59, 102, 1);"));

        horizontalLayout_2->addWidget(pushButton_Query);


        verticalLayout->addWidget(widget_4);

        widget = new QWidget(widget_content);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 300));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(24, -1, 24, 24);
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"\n"
""));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        frame = new QFrame(widget_content);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background: white;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 24, 24);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_close = new QPushButton(frame);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(80, 32));
        pushButton_close->setMaximumSize(QSize(80, 32));
        pushButton_close->setStyleSheet(QString::fromUtf8("	border: 1px solid rgba(22, 59, 102, 1);\n"
"	border-radius: 4px;\n"
"	color: rgba(22, 59, 102, 1);\n"
"    font-size: 14px;"));

        horizontalLayout_3->addWidget(pushButton_close);


        verticalLayout->addWidget(frame);

        widget_title = new QWidget(DataManager);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setGeometry(QRect(-10, 0, 1021, 32));
        widget_title->setMinimumSize(QSize(1008, 32));
        widget_title->setMaximumSize(QSize(16777215, 32));
        widget_title->setStyleSheet(QString::fromUtf8("	background: rgba(233, 238, 242, 1);\n"
"	border: 1px solid #eeeeee;"));
        label = new QLabel(widget_title);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 4, 72, 21));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:rgba(0, 0, 0, 1);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(DataManager);
        QObject::connect(pushButton_Query, SIGNAL(clicked()), DataManager, SLOT(QueryData()));

        pushButton_clear->setDefault(false);
        pushButton_out->setDefault(false);


        QMetaObject::connectSlotsByName(DataManager);
    } // setupUi

    void retranslateUi(QDialog *DataManager)
    {
        DataManager->setWindowTitle(QCoreApplication::translate("DataManager", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("DataManager", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        pushButton_out->setText(QCoreApplication::translate("DataManager", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        lineEdit_Code->setPlaceholderText(QCoreApplication::translate("DataManager", "\350\257\267\350\276\223\345\205\245\347\211\251\346\226\231\345\217\267", nullptr));
        toolButton_chooseTime->setText(QString());
        dateEdit_StartDate->setDisplayFormat(QCoreApplication::translate("DataManager", "yyyy-MM-dd hh:mm:ss", nullptr));
        dateEdit_EndDate->setDisplayFormat(QCoreApplication::translate("DataManager", "yyyy-MM-dd hh:mm:ss", nullptr));
        pushButton_Query->setText(QCoreApplication::translate("DataManager", "\346\237\245\350\257\242", nullptr));
        pushButton_close->setText(QCoreApplication::translate("DataManager", "\345\205\263\351\227\255", nullptr));
        label->setText(QCoreApplication::translate("DataManager", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataManager: public Ui_DataManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMANAGER_H
