/********************************************************************************
** Form generated from reading UI file 'studentinfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTINFOFORM_H
#define UI_STUDENTINFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentInfoForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QLineEdit *le_degree;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *le_id;
    QLabel *label_4;
    QLineEdit *le_major;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *le_name;
    QLineEdit *le_date;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *StudentInfoForm)
    {
        if (StudentInfoForm->objectName().isEmpty())
            StudentInfoForm->setObjectName(QStringLiteral("StudentInfoForm"));
        StudentInfoForm->resize(540, 450);
        layoutWidget = new QWidget(StudentInfoForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 100, 291, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 7, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        le_degree = new QLineEdit(layoutWidget);
        le_degree->setObjectName(QStringLiteral("le_degree"));
        le_degree->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_degree->sizePolicy().hasHeightForWidth());
        le_degree->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_degree, 6, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(10, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        le_id = new QLineEdit(layoutWidget);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setEnabled(false);
        sizePolicy.setHeightForWidth(le_id->sizePolicy().hasHeightForWidth());
        le_id->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_id, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setFamily(QStringLiteral("Acens"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        le_major = new QLineEdit(layoutWidget);
        le_major->setObjectName(QStringLiteral("le_major"));
        le_major->setEnabled(false);
        sizePolicy.setHeightForWidth(le_major->sizePolicy().hasHeightForWidth());
        le_major->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_major, 8, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 10, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        le_name = new QLineEdit(layoutWidget);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setEnabled(false);
        sizePolicy.setHeightForWidth(le_name->sizePolicy().hasHeightForWidth());
        le_name->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_name, 4, 1, 1, 1);

        le_date = new QLineEdit(layoutWidget);
        le_date->setObjectName(QStringLiteral("le_date"));
        le_date->setEnabled(false);
        sizePolicy.setHeightForWidth(le_date->sizePolicy().hasHeightForWidth());
        le_date->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_date, 10, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 9, 1, 1, 1);


        retranslateUi(StudentInfoForm);

        QMetaObject::connectSlotsByName(StudentInfoForm);
    } // setupUi

    void retranslateUi(QWidget *StudentInfoForm)
    {
        StudentInfoForm->setWindowTitle(QApplication::translate("StudentInfoForm", "Form", 0));
        label_5->setText(QApplication::translate("StudentInfoForm", "\345\271\264    \347\272\247\357\274\232", 0));
        label_2->setText(QApplication::translate("StudentInfoForm", "\345\247\223    \345\220\215\357\274\232", 0));
        label_4->setText(QApplication::translate("StudentInfoForm", "\345\255\246\347\261\215\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("StudentInfoForm", "\345\255\246    \347\261\215\357\274\232", 0));
        label_6->setText(QApplication::translate("StudentInfoForm", "\346\263\250\345\206\214\346\227\266\351\227\264\357\274\232", 0));
        label_3->setText(QApplication::translate("StudentInfoForm", "\344\270\223    \344\270\232\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentInfoForm: public Ui_StudentInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTINFOFORM_H
