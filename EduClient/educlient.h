#ifndef EDUCLIENT_H
#define EDUCLIENT_H

#include <QMainWindow>
#include <QCloseEvent>
#include "msgsocket.h"

#include "teachplanform.h"
#include "teachangepswdform.h"
#include "teascheduleform.h"
#include "teacherinfoform.h"

namespace Ui {
class EduClient;
}

class LoginForm;

class TeacherInfoForm;
class TeaScheduleForm;
class TeachPlanForm;
class EnterGradeForm;
class TeaChangePswdForm;

class StudentInfoForm;
class StuScheduleForm;
class PickCourseForm;
class QueryGradeForm;
class StuChangePswdForm;

class EduClient : public QMainWindow
{
    Q_OBJECT

public slots:
    void slotUserLogin(QString id, QString pswd);
    void slotUserLoginResult(bool res);
    void slotUserLogout(void);
    void slotUserLogoutResult(bool res);
    void slotChangePswd(QString);
    void slotChangedPswdResult(bool res);
    void slotEnterGrade(QString,QString,QString,QString);
    void slotEnterGradeResult(bool res);

public:
    explicit EduClient(QWidget *parent = 0);
    ~EduClient();

protected:
    void closeEvent(QCloseEvent *ev);

private slots:
    void on_actionTeacherInfo_triggered();
    void on_actionTeaSchedule_triggered();
    void on_actionTeachPlan_triggered();
    void on_actionEnterGrade_triggered();
    void on_actionTeaChangPswd_triggered();

    void on_actionStudentInfo_triggered();
    void on_actionStuSchedule_triggered();
    void on_actionPickCourse_triggered();
    void on_actionQueryGrade_triggered();
    void on_actionStuChangePswd_triggered();

private:
    Ui::EduClient *ui;

    bool m_isCloseSystem;
    LoginForm *m_loginForm;
    MsgSocket *m_msgSocket;

    TeacherInfoForm *m_teacherInfoForm;
    TeaScheduleForm *m_teaScheduleForm;
    TeachPlanForm *m_teachPlanForm;
    EnterGradeForm *m_enterGradeForm;
    TeaChangePswdForm *m_teaChangePswdForm;
    void initTeachearMS(void);

    StudentInfoForm *m_studentInfoForm;
    StuScheduleForm *m_stuScheduleForm;
    PickCourseForm *m_pickCourseForm;
    QueryGradeForm *m_queryGradeForm;
    StuChangePswdForm *m_stuChangePswdForm;
    void initStudentMS(void);
};

#endif // EDUCLIENT_H
