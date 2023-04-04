/********************************************************************************
** Form generated from reading UI file 'formulasettingpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULASETTINGPAGE_H
#define UI_FORMULASETTINGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormulaSettingPage
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *receipe_title_widget;
    QGridLayout *gridLayout_2;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QWidget *receipe_context_widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_zhengcount;
    QLineEdit *lineEdit_zheng;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_cecount;
    QLineEdit *lineEdit_ce;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_backcount;
    QLineEdit *lineEdit_bei;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *receipe_title_widget_2;
    QGridLayout *gridLayout_4;
    QLabel *label_title_model;
    QSpacerItem *horizontalSpacer_2;
    QWidget *receipe_context_widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_bright;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_bright_zheng;
    QLineEdit *lineEdit_bright_zheng;
    QPushButton *pushButton_bright_zheng;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_bright_ce;
    QLineEdit *lineEdit_bright_ce;
    QPushButton *pushButton_bright_ce;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioButton_dark;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_dark_zheng;
    QLineEdit *lineEdit_dark_zheng;
    QPushButton *pushButton_dark_zheng;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_dark_ce;
    QLineEdit *lineEdit_dark_ce;
    QPushButton *pushButton_dark_ce;

    void setupUi(QWidget *FormulaSettingPage)
    {
        if (FormulaSettingPage->objectName().isEmpty())
            FormulaSettingPage->setObjectName(QString::fromUtf8("FormulaSettingPage"));
        FormulaSettingPage->resize(645, 526);
        layoutWidget = new QWidget(FormulaSettingPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 376, 166));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        receipe_title_widget = new QWidget(layoutWidget);
        receipe_title_widget->setObjectName(QString::fromUtf8("receipe_title_widget"));
        gridLayout_2 = new QGridLayout(receipe_title_widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_title = new QLabel(receipe_title_widget);
        label_title->setObjectName(QString::fromUtf8("label_title"));

        gridLayout_2->addWidget(label_title, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout->addWidget(receipe_title_widget);

        receipe_context_widget = new QWidget(layoutWidget);
        receipe_context_widget->setObjectName(QString::fromUtf8("receipe_context_widget"));
        gridLayout = new QGridLayout(receipe_context_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_zhengcount = new QLabel(receipe_context_widget);
        label_zhengcount->setObjectName(QString::fromUtf8("label_zhengcount"));

        horizontalLayout->addWidget(label_zhengcount);

        lineEdit_zheng = new QLineEdit(receipe_context_widget);
        lineEdit_zheng->setObjectName(QString::fromUtf8("lineEdit_zheng"));
        lineEdit_zheng->setMinimumSize(QSize(200, 30));
        lineEdit_zheng->setMaximumSize(QSize(200, 30));
        lineEdit_zheng->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout->addWidget(lineEdit_zheng);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_cecount = new QLabel(receipe_context_widget);
        label_cecount->setObjectName(QString::fromUtf8("label_cecount"));

        horizontalLayout_5->addWidget(label_cecount);

        lineEdit_ce = new QLineEdit(receipe_context_widget);
        lineEdit_ce->setObjectName(QString::fromUtf8("lineEdit_ce"));
        lineEdit_ce->setMinimumSize(QSize(200, 30));
        lineEdit_ce->setMaximumSize(QSize(200, 30));
        lineEdit_ce->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout_5->addWidget(lineEdit_ce);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(30);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_backcount = new QLabel(receipe_context_widget);
        label_backcount->setObjectName(QString::fromUtf8("label_backcount"));

        horizontalLayout_6->addWidget(label_backcount);

        lineEdit_bei = new QLineEdit(receipe_context_widget);
        lineEdit_bei->setObjectName(QString::fromUtf8("lineEdit_bei"));
        lineEdit_bei->setMinimumSize(QSize(200, 30));
        lineEdit_bei->setMaximumSize(QSize(200, 30));
        lineEdit_bei->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout_6->addWidget(lineEdit_bei);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);


        verticalLayout->addWidget(receipe_context_widget);

        layoutWidget_2 = new QWidget(FormulaSettingPage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 200, 405, 252));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        receipe_title_widget_2 = new QWidget(layoutWidget_2);
        receipe_title_widget_2->setObjectName(QString::fromUtf8("receipe_title_widget_2"));
        gridLayout_4 = new QGridLayout(receipe_title_widget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_title_model = new QLabel(receipe_title_widget_2);
        label_title_model->setObjectName(QString::fromUtf8("label_title_model"));

        gridLayout_4->addWidget(label_title_model, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);


        verticalLayout_2->addWidget(receipe_title_widget_2);

        receipe_context_widget_2 = new QWidget(layoutWidget_2);
        receipe_context_widget_2->setObjectName(QString::fromUtf8("receipe_context_widget_2"));
        verticalLayout_3 = new QVBoxLayout(receipe_context_widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_bright = new QRadioButton(receipe_context_widget_2);
        radioButton_bright->setObjectName(QString::fromUtf8("radioButton_bright"));

        horizontalLayout_3->addWidget(radioButton_bright);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(30);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_bright_zheng = new QLabel(receipe_context_widget_2);
        label_bright_zheng->setObjectName(QString::fromUtf8("label_bright_zheng"));

        horizontalLayout_4->addWidget(label_bright_zheng);

        lineEdit_bright_zheng = new QLineEdit(receipe_context_widget_2);
        lineEdit_bright_zheng->setObjectName(QString::fromUtf8("lineEdit_bright_zheng"));
        lineEdit_bright_zheng->setMinimumSize(QSize(200, 30));
        lineEdit_bright_zheng->setMaximumSize(QSize(200, 30));
        lineEdit_bright_zheng->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout_4->addWidget(lineEdit_bright_zheng);

        pushButton_bright_zheng = new QPushButton(receipe_context_widget_2);
        pushButton_bright_zheng->setObjectName(QString::fromUtf8("pushButton_bright_zheng"));

        horizontalLayout_4->addWidget(pushButton_bright_zheng);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(30);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_bright_ce = new QLabel(receipe_context_widget_2);
        label_bright_ce->setObjectName(QString::fromUtf8("label_bright_ce"));

        horizontalLayout_7->addWidget(label_bright_ce);

        lineEdit_bright_ce = new QLineEdit(receipe_context_widget_2);
        lineEdit_bright_ce->setObjectName(QString::fromUtf8("lineEdit_bright_ce"));
        lineEdit_bright_ce->setMinimumSize(QSize(200, 30));
        lineEdit_bright_ce->setMaximumSize(QSize(200, 30));
        lineEdit_bright_ce->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout_7->addWidget(lineEdit_bright_ce);

        pushButton_bright_ce = new QPushButton(receipe_context_widget_2);
        pushButton_bright_ce->setObjectName(QString::fromUtf8("pushButton_bright_ce"));

        horizontalLayout_7->addWidget(pushButton_bright_ce);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(30);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        radioButton_dark = new QRadioButton(receipe_context_widget_2);
        radioButton_dark->setObjectName(QString::fromUtf8("radioButton_dark"));

        horizontalLayout_9->addWidget(radioButton_dark);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(30);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_dark_zheng = new QLabel(receipe_context_widget_2);
        label_dark_zheng->setObjectName(QString::fromUtf8("label_dark_zheng"));

        horizontalLayout_12->addWidget(label_dark_zheng);

        lineEdit_dark_zheng = new QLineEdit(receipe_context_widget_2);
        lineEdit_dark_zheng->setObjectName(QString::fromUtf8("lineEdit_dark_zheng"));
        lineEdit_dark_zheng->setMinimumSize(QSize(200, 30));
        lineEdit_dark_zheng->setMaximumSize(QSize(200, 30));
        lineEdit_dark_zheng->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout_12->addWidget(lineEdit_dark_zheng);

        pushButton_dark_zheng = new QPushButton(receipe_context_widget_2);
        pushButton_dark_zheng->setObjectName(QString::fromUtf8("pushButton_dark_zheng"));

        horizontalLayout_12->addWidget(pushButton_dark_zheng);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(30);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_dark_ce = new QLabel(receipe_context_widget_2);
        label_dark_ce->setObjectName(QString::fromUtf8("label_dark_ce"));

        horizontalLayout_8->addWidget(label_dark_ce);

        lineEdit_dark_ce = new QLineEdit(receipe_context_widget_2);
        lineEdit_dark_ce->setObjectName(QString::fromUtf8("lineEdit_dark_ce"));
        lineEdit_dark_ce->setMinimumSize(QSize(200, 30));
        lineEdit_dark_ce->setMaximumSize(QSize(200, 30));
        lineEdit_dark_ce->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	border: 1px solid #eeeeee;\n"
"	border-radius: 4px;\n"
"	color: rgba(0,0,0,0.6);\n"
"	padding-left: 20px;\n"
"    font-size: 14px;\n"
"}"));

        horizontalLayout_8->addWidget(lineEdit_dark_ce);

        pushButton_dark_ce = new QPushButton(receipe_context_widget_2);
        pushButton_dark_ce->setObjectName(QString::fromUtf8("pushButton_dark_ce"));

        horizontalLayout_8->addWidget(pushButton_dark_ce);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_2->addWidget(receipe_context_widget_2);


        retranslateUi(FormulaSettingPage);

        QMetaObject::connectSlotsByName(FormulaSettingPage);
    } // setupUi

    void retranslateUi(QWidget *FormulaSettingPage)
    {
        FormulaSettingPage->setWindowTitle(QCoreApplication::translate("FormulaSettingPage", "Form", nullptr));
        label_title->setText(QCoreApplication::translate("FormulaSettingPage", "\347\202\271\344\275\215\350\256\276\347\275\256", nullptr));
        label_zhengcount->setText(QCoreApplication::translate("FormulaSettingPage", "\346\255\243\351\235\242\347\202\271\344\275\215\346\225\260\351\207\217", nullptr));
        label_cecount->setText(QCoreApplication::translate("FormulaSettingPage", "\344\276\247\351\235\242\347\202\271\344\275\215\346\225\260\351\207\217", nullptr));
        label_backcount->setText(QCoreApplication::translate("FormulaSettingPage", "\350\203\214\351\235\242\347\202\271\344\275\215\346\225\260\351\207\217", nullptr));
        label_title_model->setText(QCoreApplication::translate("FormulaSettingPage", "\346\250\241\345\236\213\350\256\276\347\275\256", nullptr));
        radioButton_bright->setText(QCoreApplication::translate("FormulaSettingPage", "\351\253\230\345\205\211\351\235\242", nullptr));
        label_bright_zheng->setText(QCoreApplication::translate("FormulaSettingPage", "\346\255\243\351\235\242\346\250\241\345\236\213", nullptr));
        pushButton_bright_zheng->setText(QCoreApplication::translate("FormulaSettingPage", "\346\265\217\350\247\210", nullptr));
        label_bright_ce->setText(QCoreApplication::translate("FormulaSettingPage", "\344\276\247\351\235\242\346\250\241\345\236\213", nullptr));
        pushButton_bright_ce->setText(QCoreApplication::translate("FormulaSettingPage", "\346\265\217\350\247\210", nullptr));
        radioButton_dark->setText(QCoreApplication::translate("FormulaSettingPage", "\345\223\221\345\205\211\351\235\242", nullptr));
        label_dark_zheng->setText(QCoreApplication::translate("FormulaSettingPage", "\346\255\243\351\235\242\346\250\241\345\236\213", nullptr));
        pushButton_dark_zheng->setText(QCoreApplication::translate("FormulaSettingPage", "\346\265\217\350\247\210", nullptr));
        label_dark_ce->setText(QCoreApplication::translate("FormulaSettingPage", "\344\276\247\351\235\242\346\250\241\345\236\213", nullptr));
        pushButton_dark_ce->setText(QCoreApplication::translate("FormulaSettingPage", "\346\265\217\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormulaSettingPage: public Ui_FormulaSettingPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULASETTINGPAGE_H
