/********************************************************************************
** Form generated from reading UI file 'querygradeform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYGRADEFORM_H
#define UI_QUERYGRADEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryGradeForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *QueryGradeForm)
    {
        if (QueryGradeForm->objectName().isEmpty())
            QueryGradeForm->setObjectName(QStringLiteral("QueryGradeForm"));
        QueryGradeForm->resize(540, 450);
        gridLayout = new QGridLayout(QueryGradeForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(QueryGradeForm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(QueryGradeForm);

        QMetaObject::connectSlotsByName(QueryGradeForm);
    } // setupUi

    void retranslateUi(QWidget *QueryGradeForm)
    {
        QueryGradeForm->setWindowTitle(QApplication::translate("QueryGradeForm", "Form", 0));
        label->setText(QApplication::translate("QueryGradeForm", "\346\237\245\350\257\242\346\210\220\347\273\251", 0));
    } // retranslateUi

};

namespace Ui {
    class QueryGradeForm: public Ui_QueryGradeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYGRADEFORM_H
