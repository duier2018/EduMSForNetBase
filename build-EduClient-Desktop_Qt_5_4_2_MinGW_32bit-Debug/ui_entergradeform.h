/********************************************************************************
** Form generated from reading UI file 'entergradeform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERGRADEFORM_H
#define UI_ENTERGRADEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterGradeForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_stuid;
    QLineEdit *le_stuid;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_classid;
    QLineEdit *le_classid;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_courseid;
    QLineEdit *le_courseid;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lb_grade;
    QLineEdit *le_grade;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pb_sure;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *EnterGradeForm)
    {
        if (EnterGradeForm->objectName().isEmpty())
            EnterGradeForm->setObjectName(QStringLiteral("EnterGradeForm"));
        EnterGradeForm->resize(540, 450);
        gridLayout = new QGridLayout(EnterGradeForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 81, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lb_stuid = new QLabel(EnterGradeForm);
        lb_stuid->setObjectName(QStringLiteral("lb_stuid"));

        horizontalLayout_2->addWidget(lb_stuid);

        le_stuid = new QLineEdit(EnterGradeForm);
        le_stuid->setObjectName(QStringLiteral("le_stuid"));

        horizontalLayout_2->addWidget(le_stuid);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lb_classid = new QLabel(EnterGradeForm);
        lb_classid->setObjectName(QStringLiteral("lb_classid"));

        horizontalLayout_3->addWidget(lb_classid);

        le_classid = new QLineEdit(EnterGradeForm);
        le_classid->setObjectName(QStringLiteral("le_classid"));

        horizontalLayout_3->addWidget(le_classid);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lb_courseid = new QLabel(EnterGradeForm);
        lb_courseid->setObjectName(QStringLiteral("lb_courseid"));

        horizontalLayout_4->addWidget(lb_courseid);

        le_courseid = new QLineEdit(EnterGradeForm);
        le_courseid->setObjectName(QStringLiteral("le_courseid"));

        horizontalLayout_4->addWidget(le_courseid);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lb_grade = new QLabel(EnterGradeForm);
        lb_grade->setObjectName(QStringLiteral("lb_grade"));

        horizontalLayout_5->addWidget(lb_grade);

        le_grade = new QLineEdit(EnterGradeForm);
        le_grade->setObjectName(QStringLiteral("le_grade"));

        horizontalLayout_5->addWidget(le_grade);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 1, 1, 4, 1);

        horizontalSpacer_6 = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(162, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(162, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 4, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 81, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(153, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pb_sure = new QPushButton(EnterGradeForm);
        pb_sure->setObjectName(QStringLiteral("pb_sure"));

        horizontalLayout->addWidget(pb_sure);

        horizontalSpacer_10 = new QSpacerItem(153, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 81, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 1, 1);


        retranslateUi(EnterGradeForm);

        QMetaObject::connectSlotsByName(EnterGradeForm);
    } // setupUi

    void retranslateUi(QWidget *EnterGradeForm)
    {
        EnterGradeForm->setWindowTitle(QApplication::translate("EnterGradeForm", "Form", 0));
        lb_stuid->setText(QApplication::translate("EnterGradeForm", "\345\255\246\345\217\267\357\274\232", 0));
        le_stuid->setText(QApplication::translate("EnterGradeForm", "SN18-401", 0));
        lb_classid->setText(QApplication::translate("EnterGradeForm", "\347\217\255\345\217\267\357\274\232", 0));
        le_classid->setText(QApplication::translate("EnterGradeForm", "UG-1901", 0));
        lb_courseid->setText(QApplication::translate("EnterGradeForm", "\350\257\276\345\217\267\357\274\232", 0));
        le_courseid->setText(QApplication::translate("EnterGradeForm", "AC-101", 0));
        lb_grade->setText(QApplication::translate("EnterGradeForm", "\346\210\220\347\273\251\357\274\232", 0));
        le_grade->setText(QApplication::translate("EnterGradeForm", "99", 0));
        pb_sure->setText(QApplication::translate("EnterGradeForm", "\347\241\256\350\256\244\345\275\225\345\205\245", 0));
    } // retranslateUi

};

namespace Ui {
    class EnterGradeForm: public Ui_EnterGradeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERGRADEFORM_H
