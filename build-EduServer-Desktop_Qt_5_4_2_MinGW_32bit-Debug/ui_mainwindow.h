/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTeacher;
    QAction *actionClass;
    QAction *actionStudent;
    QAction *actionCourse;
    QAction *actionLogin;
    QAction *actionUser;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuSub_system;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(610, 450);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/lhlogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionTeacher = new QAction(MainWindow);
        actionTeacher->setObjectName(QStringLiteral("actionTeacher"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/my.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTeacher->setIcon(icon1);
        actionClass = new QAction(MainWindow);
        actionClass->setObjectName(QStringLiteral("actionClass"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/class.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClass->setIcon(icon2);
        actionStudent = new QAction(MainWindow);
        actionStudent->setObjectName(QStringLiteral("actionStudent"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/learn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStudent->setIcon(icon3);
        actionCourse = new QAction(MainWindow);
        actionCourse->setObjectName(QStringLiteral("actionCourse"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/task.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCourse->setIcon(icon4);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/portal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogin->setIcon(icon5);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QStringLiteral("actionUser"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUser->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 610, 23));
        menuSub_system = new QMenu(menuBar);
        menuSub_system->setObjectName(QStringLiteral("menuSub_system"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea|Qt::TopToolBarArea);
        mainToolBar->setIconSize(QSize(50, 50));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSub_system->menuAction());
        menuSub_system->addAction(actionLogin);
        menuSub_system->addAction(actionTeacher);
        menuSub_system->addAction(actionClass);
        menuSub_system->addAction(actionStudent);
        menuSub_system->addAction(actionCourse);
        menuSub_system->addAction(actionUser);
        mainToolBar->addAction(actionUser);
        mainToolBar->addAction(actionTeacher);
        mainToolBar->addAction(actionStudent);
        mainToolBar->addAction(actionClass);
        mainToolBar->addAction(actionCourse);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionTeacher->setText(QApplication::translate("MainWindow", "teacher", 0));
        actionClass->setText(QApplication::translate("MainWindow", "class", 0));
        actionStudent->setText(QApplication::translate("MainWindow", "student", 0));
        actionCourse->setText(QApplication::translate("MainWindow", "course", 0));
        actionLogin->setText(QApplication::translate("MainWindow", "login", 0));
        actionUser->setText(QApplication::translate("MainWindow", "user", 0));
        menuSub_system->setTitle(QApplication::translate("MainWindow", "sub_system", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
