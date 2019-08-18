#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "teacherform.h"
#include "classform.h"
#include "studentform.h"
#include "courseform.h"
#include "loginform.h"
#include "userform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_loginForm = new LoginForm(ui->widget);
    m_userForm = new UserForm(ui->widget);
    m_teacherForm = new TeacherForm(ui->widget);
    m_classForm = new ClassForm(ui->widget);
    m_studentForm = new StudentForm(ui->widget);
    m_courseForm = new CourseForm(ui->widget);

    connect(m_loginForm, SIGNAL(signalUserLogin(QString,QString)),
            this, SLOT(slotUserLogin(QString,QString)));

    m_loginForm->show();
    m_userForm->hide();
    m_teacherForm->hide();
    m_classForm->hide();
    m_studentForm->hide();
    m_courseForm->hide();

    ui->mainToolBar->hide();
    ui->menuBar->hide();
    ui->statusBar->hide();
    this->setContextMenuPolicy(Qt::NoContextMenu); //去掉工具栏的右键菜单
    this->setCentralWidget(ui->widget);

    m_msgServer = new MsgServer;
}

MainWindow::~MainWindow()
{
    delete m_msgServer;
    delete ui;
}

void MainWindow::on_actionUser_triggered()
{
    m_loginForm->hide();
    m_userForm->show();
    m_teacherForm->hide();
    m_classForm->hide();
    m_studentForm->hide();
    m_courseForm->hide();

    ui->actionUser->setEnabled(false);
    ui->actionClass->setEnabled(true);
    ui->actionCourse->setEnabled(true);
    ui->actionTeacher->setEnabled(true);
    ui->actionStudent->setEnabled(true);
}

void MainWindow::on_actionTeacher_triggered()
{
    m_loginForm->hide();
    m_userForm->hide();
    m_teacherForm->show();
    m_classForm->hide();
    m_studentForm->hide();
    m_courseForm->hide();

    ui->actionUser->setEnabled(true);
    ui->actionClass->setEnabled(true);
    ui->actionCourse->setEnabled(true);
    ui->actionTeacher->setEnabled(false);
    ui->actionStudent->setEnabled(true);
}

void MainWindow::on_actionClass_triggered()
{
    m_loginForm->hide();
    m_userForm->hide();
    m_teacherForm->hide();
    m_classForm->show();
    m_studentForm->hide();
    m_courseForm->hide();
    ui->actionUser->setEnabled(true);
    ui->actionClass->setEnabled(false);
    ui->actionCourse->setEnabled(true);
    ui->actionTeacher->setEnabled(true);
    ui->actionStudent->setEnabled(true);
}

void MainWindow::on_actionStudent_triggered()
{
    m_loginForm->hide();
    m_userForm->hide();
    m_teacherForm->hide();
    m_classForm->hide();
    m_studentForm->show();
    m_courseForm->hide();
    ui->actionUser->setEnabled(true);
    ui->actionClass->setEnabled(true);
    ui->actionCourse->setEnabled(true);
    ui->actionTeacher->setEnabled(true);
    ui->actionStudent->setEnabled(false);
}

void MainWindow::on_actionCourse_triggered()
{
    m_loginForm->hide();
    m_userForm->hide();
    m_teacherForm->hide();
    m_classForm->hide();
    m_studentForm->hide();
    m_courseForm->show();
    ui->actionUser->setEnabled(true);
    ui->actionClass->setEnabled(true);
    ui->actionCourse->setEnabled(false);
    ui->actionTeacher->setEnabled(true);
    ui->actionStudent->setEnabled(true);
}


void MainWindow::slotUserLogin(QString id, QString pswd)
{
    if((id == "admin") && (pswd == "admin"))
    {
        ui->mainToolBar->show();
        on_actionUser_triggered();
    }else
    {
        m_loginForm->userLoginFail();
    }
}
