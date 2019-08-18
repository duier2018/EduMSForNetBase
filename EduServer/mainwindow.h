#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "msgserver.h"

class TeacherForm;
class ClassForm;
class StudentForm;
class CourseForm;
class LoginForm;
class UserForm;

namespace Ui {
class MainWindow;
}

enum Index_Stack{
    Index_Welcome = 0,
    Index_Teacher,
    Index_Class,
    Index_Student,
    Index_Course,
    Index_Grade
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void slotUserLogin(QString id, QString pswd);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionTeacher_triggered();
    void on_actionClass_triggered();
    void on_actionStudent_triggered();
    void on_actionCourse_triggered();

    void on_actionUser_triggered();

private:
    Ui::MainWindow *ui;

    UserForm *m_userForm;
    LoginForm *m_loginForm;
    TeacherForm *m_teacherForm;
    ClassForm *m_classForm;
    StudentForm *m_studentForm;
    CourseForm *m_courseForm;

    MsgServer *m_msgServer;
};

#endif // MAINWINDOW_H
