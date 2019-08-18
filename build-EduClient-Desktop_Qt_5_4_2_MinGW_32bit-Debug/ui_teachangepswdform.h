/********************************************************************************
** Form generated from reading UI file 'teachangepswdform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHANGEPSWDFORM_H
#define UI_TEACHANGEPSWDFORM_H

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

class Ui_TeaChangePswdForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *le_name;
    QLabel *label;
    QLineEdit *le_post;
    QLabel *label_4;
    QLineEdit *le_id;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pb_changePswd;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *TeaChangePswdForm)
    {
        if (TeaChangePswdForm->objectName().isEmpty())
            TeaChangePswdForm->setObjectName(QStringLiteral("TeaChangePswdForm"));
        TeaChangePswdForm->resize(540, 450);
        layoutWidget = new QWidget(TeaChangePswdForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 90, 321, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        le_name = new QLineEdit(layoutWidget);
        le_name->setObjectName(QStringLiteral("le_name"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_name->sizePolicy().hasHeightForWidth());
        le_name->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_name, 4, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        le_post = new QLineEdit(layoutWidget);
        le_post->setObjectName(QStringLiteral("le_post"));
        sizePolicy.setHeightForWidth(le_post->sizePolicy().hasHeightForWidth());
        le_post->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_post, 6, 1, 1, 1);

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

        le_id = new QLineEdit(layoutWidget);
        le_id->setObjectName(QStringLiteral("le_id"));
        sizePolicy.setHeightForWidth(le_id->sizePolicy().hasHeightForWidth());
        le_id->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_id, 2, 1, 1, 1);

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


        retranslateUi(TeaChangePswdForm);

        QMetaObject::connectSlotsByName(TeaChangePswdForm);
    } // setupUi

    void retranslateUi(QWidget *TeaChangePswdForm)
    {
        TeaChangePswdForm->setWindowTitle(QApplication::translate("TeaChangePswdForm", "Form", 0));
        label_3->setText(QApplication::translate("TeaChangePswdForm", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        label->setText(QApplication::translate("TeaChangePswdForm", "\346\227\247 \345\257\206 \347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("TeaChangePswdForm", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        label_2->setText(QApplication::translate("TeaChangePswdForm", "\346\226\260 \345\257\206 \347\240\201\357\274\232", 0));
        pb_changePswd->setText(QApplication::translate("TeaChangePswdForm", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class TeaChangePswdForm: public Ui_TeaChangePswdForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHANGEPSWDFORM_H
