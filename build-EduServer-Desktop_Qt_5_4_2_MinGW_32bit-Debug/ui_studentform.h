/********************************************************************************
** Form generated from reading UI file 'studentform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTFORM_H
#define UI_STUDENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentForm
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb_condition;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QLineEdit *le_condition;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_search;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *le_name;
    QLineEdit *le_degree;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *le_id;
    QLineEdit *le_major;
    QPushButton *pb_modify;
    QPushButton *pb_delete;
    QPushButton *pb_cancel;
    QPushButton *pb_add;
    QPushButton *pb_save;

    void setupUi(QWidget *StudentForm)
    {
        if (StudentForm->objectName().isEmpty())
            StudentForm->setObjectName(QStringLiteral("StudentForm"));
        StudentForm->resize(540, 450);
        gridLayout_3 = new QGridLayout(StudentForm);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_4 = new QGroupBox(StudentForm);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cb_condition = new QComboBox(groupBox_4);
        cb_condition->setObjectName(QStringLiteral("cb_condition"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cb_condition->sizePolicy().hasHeightForWidth());
        cb_condition->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cb_condition);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        le_condition = new QLineEdit(groupBox_4);
        le_condition->setObjectName(QStringLiteral("le_condition"));
        le_condition->setEnabled(true);
        le_condition->setClearButtonEnabled(true);

        horizontalLayout->addWidget(le_condition);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pb_search = new QPushButton(groupBox_4);
        pb_search->setObjectName(QStringLiteral("pb_search"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pb_search->sizePolicy().hasHeightForWidth());
        pb_search->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pb_search);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox = new QGroupBox(StudentForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);

        gridLayout_5->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(StudentForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        le_name = new QLineEdit(groupBox_2);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setEnabled(false);
        le_name->setClearButtonEnabled(true);

        gridLayout->addWidget(le_name, 0, 3, 1, 1);

        le_degree = new QLineEdit(groupBox_2);
        le_degree->setObjectName(QStringLiteral("le_degree"));
        le_degree->setEnabled(false);
        le_degree->setClearButtonEnabled(true);

        gridLayout->addWidget(le_degree, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        le_id = new QLineEdit(groupBox_2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setEnabled(false);

        gridLayout->addWidget(le_id, 0, 1, 1, 1);

        le_major = new QLineEdit(groupBox_2);
        le_major->setObjectName(QStringLiteral("le_major"));
        le_major->setEnabled(false);
        le_major->setClearButtonEnabled(true);

        gridLayout->addWidget(le_major, 1, 3, 1, 1);

        pb_modify = new QPushButton(groupBox_2);
        pb_modify->setObjectName(QStringLiteral("pb_modify"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_modify->sizePolicy().hasHeightForWidth());
        pb_modify->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_modify, 0, 4, 1, 1);

        pb_delete = new QPushButton(groupBox_2);
        pb_delete->setObjectName(QStringLiteral("pb_delete"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pb_delete->sizePolicy().hasHeightForWidth());
        pb_delete->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pb_delete, 0, 5, 1, 1);

        pb_cancel = new QPushButton(groupBox_2);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setEnabled(true);

        gridLayout->addWidget(pb_cancel, 1, 5, 1, 1);

        pb_add = new QPushButton(groupBox_2);
        pb_add->setObjectName(QStringLiteral("pb_add"));

        gridLayout->addWidget(pb_add, 1, 4, 1, 1);

        pb_save = new QPushButton(groupBox_2);
        pb_save->setObjectName(QStringLiteral("pb_save"));
        pb_save->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pb_save->sizePolicy().hasHeightForWidth());
        pb_save->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pb_save, 0, 6, 2, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 0, 1, 1);


        retranslateUi(StudentForm);

        QMetaObject::connectSlotsByName(StudentForm);
    } // setupUi

    void retranslateUi(QWidget *StudentForm)
    {
        StudentForm->setWindowTitle(QApplication::translate("StudentForm", "Form", 0));
        groupBox_4->setTitle(QApplication::translate("StudentForm", "\346\235\241\344\273\266\346\237\245\350\257\242\357\274\232", 0));
        label->setText(QApplication::translate("StudentForm", "\351\200\211\346\213\251\357\274\232", 0));
        cb_condition->clear();
        cb_condition->insertItems(0, QStringList()
         << QApplication::translate("StudentForm", "\346\227\240\346\235\241\344\273\266", 0)
         << QApplication::translate("StudentForm", "\345\255\246\345\217\267", 0)
         << QApplication::translate("StudentForm", "\345\247\223\345\220\215", 0)
         << QApplication::translate("StudentForm", "\345\271\264\347\272\247", 0)
         << QApplication::translate("StudentForm", "\344\270\223\344\270\232", 0)
        );
        label_6->setText(QApplication::translate("StudentForm", "\346\235\241\344\273\266\357\274\232", 0));
        pb_search->setText(QApplication::translate("StudentForm", "\346\220\234\347\264\242", 0));
        groupBox->setTitle(QApplication::translate("StudentForm", "\346\237\245\350\257\242\347\273\223\346\236\234\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("StudentForm", "\347\233\270\345\205\263\346\223\215\344\275\234\357\274\232", 0));
        label_4->setText(QApplication::translate("StudentForm", "\345\271\264\347\272\247\357\274\232", 0));
        label_2->setText(QApplication::translate("StudentForm", "\345\255\246\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("StudentForm", "\345\247\223\345\220\215\357\274\232", 0));
        label_5->setText(QApplication::translate("StudentForm", "\344\270\223\344\270\232\357\274\232", 0));
        pb_modify->setText(QApplication::translate("StudentForm", "\344\277\256\346\224\271", 0));
        pb_delete->setText(QApplication::translate("StudentForm", "\345\210\240\351\231\244", 0));
        pb_cancel->setText(QApplication::translate("StudentForm", "\345\217\226\346\266\210", 0));
        pb_add->setText(QApplication::translate("StudentForm", "\346\226\260\345\242\236", 0));
        pb_save->setText(QApplication::translate("StudentForm", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentForm: public Ui_StudentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTFORM_H
