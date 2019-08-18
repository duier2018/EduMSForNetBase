/********************************************************************************
** Form generated from reading UI file 'teachplanform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHPLANFORM_H
#define UI_TEACHPLANFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeachPlanForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *TeachPlanForm)
    {
        if (TeachPlanForm->objectName().isEmpty())
            TeachPlanForm->setObjectName(QStringLiteral("TeachPlanForm"));
        TeachPlanForm->resize(540, 450);
        gridLayout = new QGridLayout(TeachPlanForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(TeachPlanForm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(TeachPlanForm);

        QMetaObject::connectSlotsByName(TeachPlanForm);
    } // setupUi

    void retranslateUi(QWidget *TeachPlanForm)
    {
        TeachPlanForm->setWindowTitle(QApplication::translate("TeachPlanForm", "Form", 0));
        label->setText(QApplication::translate("TeachPlanForm", "\350\257\276\347\250\213\350\256\241\345\210\222", 0));
    } // retranslateUi

};

namespace Ui {
    class TeachPlanForm: public Ui_TeachPlanForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHPLANFORM_H
