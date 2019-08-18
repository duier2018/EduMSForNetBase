/********************************************************************************
** Form generated from reading UI file 'pickcourseform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKCOURSEFORM_H
#define UI_PICKCOURSEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PickCourseForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *PickCourseForm)
    {
        if (PickCourseForm->objectName().isEmpty())
            PickCourseForm->setObjectName(QStringLiteral("PickCourseForm"));
        PickCourseForm->resize(540, 450);
        gridLayout = new QGridLayout(PickCourseForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(PickCourseForm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(PickCourseForm);

        QMetaObject::connectSlotsByName(PickCourseForm);
    } // setupUi

    void retranslateUi(QWidget *PickCourseForm)
    {
        PickCourseForm->setWindowTitle(QApplication::translate("PickCourseForm", "Form", 0));
        label->setText(QApplication::translate("PickCourseForm", "\351\200\211\344\277\256\350\257\276\347\250\213", 0));
    } // retranslateUi

};

namespace Ui {
    class PickCourseForm: public Ui_PickCourseForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKCOURSEFORM_H
