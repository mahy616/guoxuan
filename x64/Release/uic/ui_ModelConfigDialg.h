/********************************************************************************
** Form generated from reading UI file 'ModelConfigDialg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELCONFIGDIALG_H
#define UI_MODELCONFIGDIALG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelConfigDialgClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_JsonPath;
    QPushButton *pushButton_ChangeModel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_ModeType;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_LabelNames;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_GpuFlag;
    QPushButton *btn_GPUFlag;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_cancel;
    QLabel *label_5;
    QPushButton *btn_confirm;

    void setupUi(QWidget *ModelConfigDialgClass)
    {
        if (ModelConfigDialgClass->objectName().isEmpty())
            ModelConfigDialgClass->setObjectName(QString::fromUtf8("ModelConfigDialgClass"));
        ModelConfigDialgClass->resize(708, 499);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModelConfigDialgClass->sizePolicy().hasHeightForWidth());
        ModelConfigDialgClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("KaiTi"));
        font.setPointSize(11);
        ModelConfigDialgClass->setFont(font);
        ModelConfigDialgClass->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size: 11pt;\n"
"background: #323232;"));
        gridLayout = new QGridLayout(ModelConfigDialgClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ModelConfigDialgClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(150, 35));

        horizontalLayout->addWidget(label);

        label_JsonPath = new QLabel(ModelConfigDialgClass);
        label_JsonPath->setObjectName(QString::fromUtf8("label_JsonPath"));
        label_JsonPath->setMinimumSize(QSize(50, 40));
        label_JsonPath->setFont(font);
        label_JsonPath->setStyleSheet(QString::fromUtf8("background: #262626;\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;"));

        horizontalLayout->addWidget(label_JsonPath);

        pushButton_ChangeModel = new QPushButton(ModelConfigDialgClass);
        pushButton_ChangeModel->setObjectName(QString::fromUtf8("pushButton_ChangeModel"));
        pushButton_ChangeModel->setMinimumSize(QSize(65, 32));
        pushButton_ChangeModel->setMaximumSize(QSize(65, 32));
        pushButton_ChangeModel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid rgba(255, 255, 255, 0.2);\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#000426;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(65,65,65);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_ChangeModel);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(ModelConfigDialgClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ModelConfigDialgClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(200, 30));

        horizontalLayout_2->addWidget(label_2);

        label_ModeType = new QLabel(ModelConfigDialgClass);
        label_ModeType->setObjectName(QString::fromUtf8("label_ModeType"));
        label_ModeType->setMinimumSize(QSize(35, 40));

        horizontalLayout_2->addWidget(label_ModeType);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(ModelConfigDialgClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(200, 30));

        horizontalLayout_3->addWidget(label_4);

        label_LabelNames = new QLabel(ModelConfigDialgClass);
        label_LabelNames->setObjectName(QString::fromUtf8("label_LabelNames"));
        label_LabelNames->setMinimumSize(QSize(35, 40));

        horizontalLayout_3->addWidget(label_LabelNames);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_GpuFlag = new QLabel(ModelConfigDialgClass);
        label_GpuFlag->setObjectName(QString::fromUtf8("label_GpuFlag"));
        label_GpuFlag->setMinimumSize(QSize(130, 0));
        label_GpuFlag->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(label_GpuFlag);

        btn_GPUFlag = new QPushButton(ModelConfigDialgClass);
        btn_GPUFlag->setObjectName(QString::fromUtf8("btn_GPUFlag"));
        btn_GPUFlag->setMinimumSize(QSize(40, 25));
        btn_GPUFlag->setMaximumSize(QSize(40, 25));
        btn_GPUFlag->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image:url(\":/DynamicWidget/Resource/Btn_Close.png\");\n"
"	border:none;\n"
"	background:transparent;\n"
"}"));

        horizontalLayout_4->addWidget(btn_GPUFlag);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_3 = new QLabel(ModelConfigDialgClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(35, 40));
        label_3->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_4->addWidget(label_3);

        comboBox = new QComboBox(ModelConfigDialgClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(200, 0));
        comboBox->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btn_cancel = new QPushButton(ModelConfigDialgClass);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setMinimumSize(QSize(100, 35));
        btn_cancel->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	background: #4A4A4A;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background: #858585;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #A3A3A3;\n"
"	border-radius: 4px;\n"
"}\n"
""));

        horizontalLayout_5->addWidget(btn_cancel);

        label_5 = new QLabel(ModelConfigDialgClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(10, 0));
        label_5->setMaximumSize(QSize(10, 16777215));

        horizontalLayout_5->addWidget(label_5);

        btn_confirm = new QPushButton(ModelConfigDialgClass);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(100, 35));
        btn_confirm->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	background: #3A71DE;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background: #274B94;\n"
"	border-radius: 4px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #172D59;\n"
"	border-radius: 4px;\n"
"}"));

        horizontalLayout_5->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ModelConfigDialgClass);

        QMetaObject::connectSlotsByName(ModelConfigDialgClass);
    } // setupUi

    void retranslateUi(QWidget *ModelConfigDialgClass)
    {
        ModelConfigDialgClass->setWindowTitle(QCoreApplication::translate("ModelConfigDialgClass", "Pipeline Settings", nullptr));
        label->setText(QCoreApplication::translate("ModelConfigDialgClass", "File Location", nullptr));
        label_JsonPath->setText(QCoreApplication::translate("ModelConfigDialgClass", "choose file location", nullptr));
        pushButton_ChangeModel->setText(QCoreApplication::translate("ModelConfigDialgClass", "Open", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ModelConfigDialgClass", "Choose Pipeline", nullptr));
        label_2->setText(QCoreApplication::translate("ModelConfigDialgClass", "Pipeline type:", nullptr));
        label_ModeType->setText(QCoreApplication::translate("ModelConfigDialgClass", "To be selected", nullptr));
        label_4->setText(QCoreApplication::translate("ModelConfigDialgClass", "Label Feature:", nullptr));
        label_LabelNames->setText(QCoreApplication::translate("ModelConfigDialgClass", "To be selected", nullptr));
        label_GpuFlag->setText(QCoreApplication::translate("ModelConfigDialgClass", "Run with GPU:", nullptr));
        btn_GPUFlag->setText(QString());
        label_3->setText(QCoreApplication::translate("ModelConfigDialgClass", "Gpu_ID\357\274\232", nullptr));
        btn_cancel->setText(QCoreApplication::translate("ModelConfigDialgClass", "Cancel", nullptr));
        label_5->setText(QString());
        btn_confirm->setText(QCoreApplication::translate("ModelConfigDialgClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelConfigDialgClass: public Ui_ModelConfigDialgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELCONFIGDIALG_H
