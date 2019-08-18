/********************************************************************************
** Form generated from reading UI file 'educlient.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDUCLIENT_H
#define UI_EDUCLIENT_H

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

class Ui_EduClient
{
public:
    QAction *actionTeacherInfo;
    QAction *actionTeaSchedule;
    QAction *actionTeachPlan;
    QAction *actionEnterGrade;
    QAction *actionTeaChangPswd;
    QAction *actionStudentInfo;
    QAction *actionStuSchedule;
    QAction *actionPickCourse;
    QAction *actionQueryGrade;
    QAction *actionStuChangePswd;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuOption;
    QMenu *menuStudent;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EduClient)
    {
        if (EduClient->objectName().isEmpty())
            EduClient->setObjectName(QStringLiteral("EduClient"));
        EduClient->resize(610, 450);
        actionTeacherInfo = new QAction(EduClient);
        actionTeacherInfo->setObjectName(QStringLiteral("actionTeacherInfo"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/my.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTeacherInfo->setIcon(icon);
        actionTeaSchedule = new QAction(EduClient);
        actionTeaSchedule->setObjectName(QStringLiteral("actionTeaSchedule"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/schedule.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTeaSchedule->setIcon(icon1);
        actionTeachPlan = new QAction(EduClient);
        actionTeachPlan->setObjectName(QStringLiteral("actionTeachPlan"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/teaches.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTeachPlan->setIcon(icon2);
        actionEnterGrade = new QAction(EduClient);
        actionEnterGrade->setObjectName(QStringLiteral("actionEnterGrade"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/exam_system.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnterGrade->setIcon(icon3);
        actionTeaChangPswd = new QAction(EduClient);
        actionTeaChangPswd->setObjectName(QStringLiteral("actionTeaChangPswd"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/acade.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTeaChangPswd->setIcon(icon4);
        actionStudentInfo = new QAction(EduClient);
        actionStudentInfo->setObjectName(QStringLiteral("actionStudentInfo"));
        actionStudentInfo->setIcon(icon);
        actionStuSchedule = new QAction(EduClient);
        actionStuSchedule->setObjectName(QStringLiteral("actionStuSchedule"));
        actionStuSchedule->setIcon(icon1);
        actionPickCourse = new QAction(EduClient);
        actionPickCourse->setObjectName(QStringLiteral("actionPickCourse"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/task_online.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPickCourse->setIcon(icon5);
        actionQueryGrade = new QAction(EduClient);
        actionQueryGrade->setObjectName(QStringLiteral("actionQueryGrade"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/grade.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQueryGrade->setIcon(icon6);
        actionStuChangePswd = new QAction(EduClient);
        actionStuChangePswd->setObjectName(QStringLiteral("actionStuChangePswd"));
        actionStuChangePswd->setIcon(icon4);
        centralWidget = new QWidget(EduClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        EduClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EduClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 610, 23));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuStudent = new QMenu(menuBar);
        menuStudent->setObjectName(QStringLiteral("menuStudent"));
        EduClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EduClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setIconSize(QSize(50, 50));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        EduClient->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        EduClient->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(EduClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EduClient->setStatusBar(statusBar);

        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuStudent->menuAction());
        menuOption->addAction(actionTeacherInfo);
        menuOption->addAction(actionTeaSchedule);
        menuOption->addAction(actionTeachPlan);
        menuOption->addAction(actionEnterGrade);
        menuOption->addAction(actionTeaChangPswd);
        menuStudent->addAction(actionStudentInfo);
        menuStudent->addAction(actionStuSchedule);
        menuStudent->addAction(actionPickCourse);
        menuStudent->addAction(actionQueryGrade);
        menuStudent->addAction(actionStuChangePswd);
        mainToolBar->addAction(actionTeacherInfo);
        mainToolBar->addAction(actionTeaSchedule);
        mainToolBar->addAction(actionTeachPlan);
        mainToolBar->addAction(actionEnterGrade);
        mainToolBar->addAction(actionTeaChangPswd);
        mainToolBar->addAction(actionStudentInfo);
        mainToolBar->addAction(actionStuSchedule);
        mainToolBar->addAction(actionPickCourse);
        mainToolBar->addAction(actionQueryGrade);
        mainToolBar->addAction(actionStuChangePswd);

        retranslateUi(EduClient);

        QMetaObject::connectSlotsByName(EduClient);
    } // setupUi

    void retranslateUi(QMainWindow *EduClient)
    {
        EduClient->setWindowTitle(QApplication::translate("EduClient", "EduClient", 0));
        actionTeacherInfo->setText(QApplication::translate("EduClient", "TeacherInfo", 0));
        actionTeaSchedule->setText(QApplication::translate("EduClient", "TeaSchedule", 0));
        actionTeachPlan->setText(QApplication::translate("EduClient", "TeachPlan", 0));
        actionEnterGrade->setText(QApplication::translate("EduClient", "EnterGrade", 0));
        actionTeaChangPswd->setText(QApplication::translate("EduClient", "TeaChangPswd", 0));
        actionStudentInfo->setText(QApplication::translate("EduClient", "StudentInfo", 0));
        actionStuSchedule->setText(QApplication::translate("EduClient", "StuSchedule", 0));
        actionPickCourse->setText(QApplication::translate("EduClient", "PickCourse", 0));
        actionQueryGrade->setText(QApplication::translate("EduClient", "QueryGrade", 0));
        actionStuChangePswd->setText(QApplication::translate("EduClient", "StuChangePswd", 0));
        menuOption->setTitle(QApplication::translate("EduClient", "Teacher", 0));
        menuStudent->setTitle(QApplication::translate("EduClient", "Student", 0));
    } // retranslateUi

};

namespace Ui {
    class EduClient: public Ui_EduClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDUCLIENT_H
