/********************************************************************************
** Form generated from reading UI file 'stuchangepswdform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUCHANGEPSWDFORM_H
#define UI_STUCHANGEPSWDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StuChangePswdForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *le_newpswd;
    QLabel *label;
    QLineEdit *le_cmppswd;
    QLabel *label_4;
    QLineEdit *le_oldpswd;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pb_changePswd;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *StuChangePswdForm)
    {
        if (StuChangePswdForm->objectName().isEmpty())
            StuChangePswdForm->setObjectName(QStringLiteral("StuChangePswdForm"));
        StuChangePswdForm->resize(540, 450);
        layoutWidget = new QWidget(StuChangePswdForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 100, 321, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        le_newpswd = new QLineEdit(layoutWidget);
        le_newpswd->setObjectName(QStringLiteral("le_newpswd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_newpswd->sizePolicy().hasHeightForWidth());
        le_newpswd->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_newpswd, 4, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        le_cmppswd = new QLineEdit(layoutWidget);
        le_cmppswd->setObjectName(QStringLiteral("le_cmppswd"));
        sizePolicy.setHeightForWidth(le_cmppswd->sizePolicy().hasHeightForWidth());
        le_cmppswd->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_cmppswd, 6, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setFamily(QStringLiteral("Acens"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        le_oldpswd = new QLineEdit(layoutWidget);
        le_oldpswd->setObjectName(QStringLiteral("le_oldpswd"));
        sizePolicy.setHeightForWidth(le_oldpswd->sizePolicy().hasHeightForWidth());
        le_oldpswd->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_oldpswd, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(10, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        pb_changePswd = new QPushButton(layoutWidget);
        pb_changePswd->setObjectName(QStringLiteral("pb_changePswd"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pb_changePswd->sizePolicy().hasHeightForWidth());
        pb_changePswd->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pb_changePswd, 8, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 7, 1, 1, 1);


        retranslateUi(StuChangePswdForm);

        QMetaObject::connectSlotsByName(StuChangePswdForm);
    } // setupUi

    void retranslateUi(QWidget *StuChangePswdForm)
    {
        StuChangePswdForm->setWindowTitle(QApplication::translate("StuChangePswdForm", "Form", 0));
        label_3->setText(QApplication::translate("StuChangePswdForm", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        label->setText(QApplication::translate("StuChangePswdForm", "\346\227\247 \345\257\206 \347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("StuChangePswdForm", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        label_2->setText(QApplication::translate("StuChangePswdForm", "\346\226\260 \345\257\206 \347\240\201\357\274\232", 0));
        pb_changePswd->setText(QApplication::translate("StuChangePswdForm", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class StuChangePswdForm: public Ui_StuChangePswdForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUCHANGEPSWDFORM_H
