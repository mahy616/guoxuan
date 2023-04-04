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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultSetting
{
public:
    QHBoxLayout *horizontalLayout_25;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *spinBox_head_alignment;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_11;
    QDoubleSpinBox *spinBox_head_alignment_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QDoubleSpinBox *spinBox_head_left_warning;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *spinBox_head_middle_warning;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QDoubleSpinBox *spinBox_head_right_warning;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *lineEdit_head_test;
    QLineEdit *lineEdit_head_show;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QDoubleSpinBox *spinBox_end_middle_warning;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_left;
    QRadioButton *radioButton_middle;
    QRadioButton *radioButton_right;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_end_text;
    QLineEdit *lineEdit_end_show;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QDoubleSpinBox *spinBox_end_left_alignment;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QDoubleSpinBox *spinBox_end_middle_alignment;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QDoubleSpinBox *spinBox_end_right_alignment;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_19;
    QDoubleSpinBox *spinBox_end_left_alignment_3;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_21;
    QDoubleSpinBox *spinBox_end_right_alignment_3;

    void setupUi(QWidget *ResultSetting)
    {
        if (ResultSetting->objectName().isEmpty())
            ResultSetting->setObjectName(QString::fromUtf8("ResultSetting"));
        ResultSetting->resize(1243, 192);
        ResultSetting->setStyleSheet(QString::fromUtf8("color:yellow;\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \n"
"\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\n"
"\n"
""));
        horizontalLayout_25 = new QHBoxLayout(ResultSetting);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        groupBox = new QGroupBox(ResultSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font-size:15px; "));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_3->addWidget(label);

        spinBox_head_alignment = new QDoubleSpinBox(groupBox);
        spinBox_head_alignment->setObjectName(QString::fromUtf8("spinBox_head_alignment"));
        spinBox_head_alignment->setMaximum(1000.000000000000000);
        spinBox_head_alignment->setSingleStep(10.000000000000000);
        spinBox_head_alignment->setValue(0.500000000000000);

        horizontalLayout_3->addWidget(spinBox_head_alignment);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_19->addWidget(label_11);

        spinBox_head_alignment_2 = new QDoubleSpinBox(groupBox);
        spinBox_head_alignment_2->setObjectName(QString::fromUtf8("spinBox_head_alignment_2"));
        spinBox_head_alignment_2->setMaximum(1000.000000000000000);
        spinBox_head_alignment_2->setSingleStep(10.000000000000000);
        spinBox_head_alignment_2->setValue(0.300000000000000);

        horizontalLayout_19->addWidget(spinBox_head_alignment_2);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_11->addWidget(label_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        spinBox_head_left_warning = new QDoubleSpinBox(groupBox);
        spinBox_head_left_warning->setObjectName(QString::fromUtf8("spinBox_head_left_warning"));
        spinBox_head_left_warning->setMaximum(100000.000000000000000);
        spinBox_head_left_warning->setSingleStep(50.000000000000000);
        spinBox_head_left_warning->setValue(27.000000000000000);

        horizontalLayout_8->addWidget(spinBox_head_left_warning);


        horizontalLayout_11->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        spinBox_head_middle_warning = new QDoubleSpinBox(groupBox);
        spinBox_head_middle_warning->setObjectName(QString::fromUtf8("spinBox_head_middle_warning"));
        spinBox_head_middle_warning->setMaximum(100000.000000000000000);
        spinBox_head_middle_warning->setSingleStep(50.000000000000000);
        spinBox_head_middle_warning->setValue(199.000000000000000);

        horizontalLayout_9->addWidget(spinBox_head_middle_warning);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        spinBox_head_right_warning = new QDoubleSpinBox(groupBox);
        spinBox_head_right_warning->setObjectName(QString::fromUtf8("spinBox_head_right_warning"));
        spinBox_head_right_warning->setMaximum(100000.000000000000000);
        spinBox_head_right_warning->setValue(27.000000000000000);

        horizontalLayout_10->addWidget(spinBox_head_right_warning);


        horizontalLayout_11->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lineEdit_head_test = new QLineEdit(groupBox);
        lineEdit_head_test->setObjectName(QString::fromUtf8("lineEdit_head_test"));

        horizontalLayout_12->addWidget(lineEdit_head_test);

        lineEdit_head_show = new QLineEdit(groupBox);
        lineEdit_head_show->setObjectName(QString::fromUtf8("lineEdit_head_show"));

        horizontalLayout_12->addWidget(lineEdit_head_show);


        verticalLayout->addLayout(horizontalLayout_12);


        horizontalLayout_25->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ResultSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setStyleSheet(QString::fromUtf8("font-size:15px; "));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_15->addWidget(label_14);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_17->addWidget(label_16);

        spinBox_end_middle_warning = new QDoubleSpinBox(groupBox_2);
        spinBox_end_middle_warning->setObjectName(QString::fromUtf8("spinBox_end_middle_warning"));
        spinBox_end_middle_warning->setMaximum(1000.000000000000000);
        spinBox_end_middle_warning->setValue(199.000000000000000);

        horizontalLayout_17->addWidget(spinBox_end_middle_warning);


        horizontalLayout_15->addLayout(horizontalLayout_17);


        gridLayout_2->addLayout(horizontalLayout_15, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_2->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radioButton_left = new QRadioButton(groupBox_2);
        radioButton_left->setObjectName(QString::fromUtf8("radioButton_left"));

        horizontalLayout_4->addWidget(radioButton_left);

        radioButton_middle = new QRadioButton(groupBox_2);
        radioButton_middle->setObjectName(QString::fromUtf8("radioButton_middle"));
        radioButton_middle->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(radioButton_middle);

        radioButton_right = new QRadioButton(groupBox_2);
        radioButton_right->setObjectName(QString::fromUtf8("radioButton_right"));

        horizontalLayout_4->addWidget(radioButton_right);


        horizontalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEdit_end_text = new QLineEdit(groupBox_2);
        lineEdit_end_text->setObjectName(QString::fromUtf8("lineEdit_end_text"));

        horizontalLayout_13->addWidget(lineEdit_end_text);

        lineEdit_end_show = new QLineEdit(groupBox_2);
        lineEdit_end_show->setObjectName(QString::fromUtf8("lineEdit_end_show"));

        horizontalLayout_13->addWidget(lineEdit_end_show);


        gridLayout_2->addLayout(horizontalLayout_13, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_7->addWidget(label_3);

        spinBox_end_left_alignment = new QDoubleSpinBox(groupBox_2);
        spinBox_end_left_alignment->setObjectName(QString::fromUtf8("spinBox_end_left_alignment"));
        spinBox_end_left_alignment->setValue(0.500000000000000);

        horizontalLayout_7->addWidget(spinBox_end_left_alignment);


        horizontalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_6->addWidget(label_4);

        spinBox_end_middle_alignment = new QDoubleSpinBox(groupBox_2);
        spinBox_end_middle_alignment->setObjectName(QString::fromUtf8("spinBox_end_middle_alignment"));
        spinBox_end_middle_alignment->setValue(0.500000000000000);

        horizontalLayout_6->addWidget(spinBox_end_middle_alignment);


        horizontalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_5->addWidget(label_2);

        spinBox_end_right_alignment = new QDoubleSpinBox(groupBox_2);
        spinBox_end_right_alignment->setObjectName(QString::fromUtf8("spinBox_end_right_alignment"));
        spinBox_end_right_alignment->setValue(0.500000000000000);

        horizontalLayout_5->addWidget(spinBox_end_right_alignment);


        horizontalLayout->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_21->addWidget(label_18);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_22->addWidget(label_19);

        spinBox_end_left_alignment_3 = new QDoubleSpinBox(groupBox_2);
        spinBox_end_left_alignment_3->setObjectName(QString::fromUtf8("spinBox_end_left_alignment_3"));
        spinBox_end_left_alignment_3->setValue(0.300000000000000);

        horizontalLayout_22->addWidget(spinBox_end_left_alignment_3);


        horizontalLayout_21->addLayout(horizontalLayout_22);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font-size:15px; "));

        horizontalLayout_24->addWidget(label_21);

        spinBox_end_right_alignment_3 = new QDoubleSpinBox(groupBox_2);
        spinBox_end_right_alignment_3->setObjectName(QString::fromUtf8("spinBox_end_right_alignment_3"));
        spinBox_end_right_alignment_3->setValue(0.300000000000000);

        horizontalLayout_24->addWidget(spinBox_end_right_alignment_3);


        horizontalLayout_21->addLayout(horizontalLayout_24);


        gridLayout_2->addLayout(horizontalLayout_21, 2, 0, 1, 1);


        horizontalLayout_25->addWidget(groupBox_2);


        retranslateUi(ResultSetting);

        QMetaObject::connectSlotsByName(ResultSetting);
    } // setupUi

    void retranslateUi(QWidget *ResultSetting)
    {
        ResultSetting->setWindowTitle(QCoreApplication::translate("ResultSetting", "ResultSetting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ResultSetting", "\347\272\277\345\244\264\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("ResultSetting", "\345\257\271\351\275\220\345\272\246\346\212\245\350\255\246\345\200\274:", nullptr));
        label_11->setText(QCoreApplication::translate("ResultSetting", "\345\257\271\351\275\220\345\272\246\347\272\240\345\201\217\345\200\274:", nullptr));
        label_10->setText(QCoreApplication::translate("ResultSetting", "\350\266\205\351\231\220\346\212\245\350\255\246:", nullptr));
        label_7->setText(QCoreApplication::translate("ResultSetting", "\345\267\246\346\240\207\345\207\206\345\200\274", nullptr));
        label_8->setText(QCoreApplication::translate("ResultSetting", "\344\270\255\346\240\207\345\207\206\345\200\274", nullptr));
        label_9->setText(QCoreApplication::translate("ResultSetting", "\345\217\263\346\240\207\345\207\206\345\200\274", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ResultSetting", "\347\272\277\345\260\276\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_14->setText(QCoreApplication::translate("ResultSetting", "\350\266\205\351\231\220\346\212\245\350\255\246:", nullptr));
        label_16->setText(QCoreApplication::translate("ResultSetting", "\344\270\255\346\240\207\345\207\206\345\200\274", nullptr));
        label_5->setText(QCoreApplication::translate("ResultSetting", "\345\257\271\351\275\220\346\226\271\345\274\217\350\256\276\347\275\256:", nullptr));
        radioButton_left->setText(QCoreApplication::translate("ResultSetting", "\345\267\246\345\257\271\351\275\220", nullptr));
        radioButton_middle->setText(QCoreApplication::translate("ResultSetting", "\344\270\255\345\257\271\351\275\220", nullptr));
        radioButton_right->setText(QCoreApplication::translate("ResultSetting", "\345\217\263\345\257\271\351\275\220", nullptr));
        label_6->setText(QCoreApplication::translate("ResultSetting", "\345\257\271\351\275\220\345\272\246\346\212\245\350\255\246\345\200\274:", nullptr));
        label_3->setText(QCoreApplication::translate("ResultSetting", "\345\267\246\345\257\271\351\275\220\351\231\220\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("ResultSetting", "\345\261\205\344\270\255\345\257\271\351\275\220\351\231\220\345\200\274", nullptr));
        label_2->setText(QCoreApplication::translate("ResultSetting", "\345\217\263\345\257\271\351\275\220\351\231\220\345\200\274", nullptr));
        label_18->setText(QCoreApplication::translate("ResultSetting", "\345\257\271\351\275\220\345\272\246\347\272\240\345\201\217\345\200\274:", nullptr));
        label_19->setText(QCoreApplication::translate("ResultSetting", "\345\267\246\345\257\271\351\275\220\351\231\220\345\200\274", nullptr));
        label_21->setText(QCoreApplication::translate("ResultSetting", "\345\217\263\345\257\271\351\275\220\351\231\220\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultSetting: public Ui_ResultSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSETTING_H
