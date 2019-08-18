/********************************************************************************
** Form generated from reading UI file 'stuscheduleform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUSCHEDULEFORM_H
#define UI_STUSCHEDULEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StuScheduleForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *StuScheduleForm)
    {
        if (StuScheduleForm->objectName().isEmpty())
            StuScheduleForm->setObjectName(QStringLiteral("StuScheduleForm"));
        StuScheduleForm->resize(540, 450);
        gridLayout = new QGridLayout(StuScheduleForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(StuScheduleForm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(StuScheduleForm);

        QMetaObject::connectSlotsByName(StuScheduleForm);
    } // setupUi

    void retranslateUi(QWidget *StuScheduleForm)
    {
        StuScheduleForm->setWindowTitle(QApplication::translate("StuScheduleForm", "Form", 0));
        label->setText(QApplication::translate("StuScheduleForm", "\350\257\276\347\250\213\345\256\211\346\216\222", 0));
    } // retranslateUi

};

namespace Ui {
    class StuScheduleForm: public Ui_StuScheduleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUSCHEDULEFORM_H
