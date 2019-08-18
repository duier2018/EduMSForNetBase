/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

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

class Ui_LoginForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *lb_userName;
    QLineEdit *le_pswd;
    QLineEdit *le_uid;
    QLabel *label;
    QLabel *lb_pswd;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pb_login;
    QLabel *label_2;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->resize(610, 450);
        LoginForm->setStyleSheet(QLatin1String("*{\n"
"	background-color: transparent;\n"
"}\n"
"QWidget#LoginForm{\n"
"	background-image: url(:/images/back.jpg);\n"
"}"));
        layoutWidget = new QWidget(LoginForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 190, 241, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        lb_userName = new QLabel(layoutWidget);
        lb_userName->setObjectName(QStringLiteral("lb_userName"));

        gridLayout->addWidget(lb_userName, 2, 0, 1, 1);

        le_pswd = new QLineEdit(layoutWidget);
        le_pswd->setObjectName(QStringLiteral("le_pswd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_pswd->sizePolicy().hasHeightForWidth());
        le_pswd->setSizePolicy(sizePolicy);
        le_pswd->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 100);"));
        le_pswd->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(le_pswd, 3, 1, 1, 1);

        le_uid = new QLineEdit(layoutWidget);
        le_uid->setObjectName(QStringLiteral("le_uid"));
        sizePolicy.setHeightForWidth(le_uid->sizePolicy().hasHeightForWidth());
        le_uid->setSizePolicy(sizePolicy);
        le_uid->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(le_uid, 2, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lb_pswd = new QLabel(layoutWidget);
        lb_pswd->setObjectName(QStringLiteral("lb_pswd"));

        gridLayout->addWidget(lb_pswd, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        pb_login = new QPushButton(layoutWidget);
        pb_login->setObjectName(QStringLiteral("pb_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pb_login->sizePolicy().hasHeightForWidth());
        pb_login->setSizePolicy(sizePolicy1);
        pb_login->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(pb_login, 5, 0, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        QWidget::setTabOrder(le_uid, le_pswd);
        QWidget::setTabOrder(le_pswd, pb_login);

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Login", 0));
        lb_userName->setText(QApplication::translate("LoginForm", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        le_pswd->setText(QApplication::translate("LoginForm", "admin", 0));
        le_uid->setText(QApplication::translate("LoginForm", "admin", 0));
        label->setText(QApplication::translate("LoginForm", "\346\225\231\345\212\241\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        lb_pswd->setText(QApplication::translate("LoginForm", "\345\257\206  \347\240\201\357\274\232", 0));
        pb_login->setText(QApplication::translate("LoginForm", "\347\231\273\345\275\225", 0));
        label_2->setText(QApplication::translate("LoginForm", "\346\234\215\345\212\241\347\253\257", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
