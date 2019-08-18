#include "educlient.h"
#include "ui_educlient.h"

#include "loginform.h"

#include "teacherinfoform.h"
#include "teascheduleform.h"
#include "teachplanform.h"
#include "entergradeform.h"
#include "teachangepswdform.h"

#include "pickcourseform.h"
#include "querygradeform.h"
#include "studentinfoform.h"
#include "stuchangepswdform.h"
#include "stuscheduleform.h"

#include "globalvars.h"
#include <QStringBuilder>
#include <QMessageBox>

EduClient::EduClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EduClient)
{
    ui->setupUi(this);

    m_isCloseSystem = false;

    ui->menuBar->hide();
    ui->statusBar->hide();
    ui->mainToolBar->hide();
    this->setContextMenuPolicy(Qt::NoContextMenu); //去掉工具栏的右键菜单
    this->setCentralWidget(ui->widget);

    m_loginForm = new LoginForm(ui->widget);
    m_msgSocket = new MsgSocket;
    connect(m_loginForm, SIGNAL(signalUserLogin(QString,QString)),
            this, SLOT(slotUserLogin(QString,QString)));
    connect(m_msgSocket, SIGNAL(signalUserLoginResult(bool)),
            this, SLOT(slotUserLoginResult(bool)));
    connect(m_loginForm, SIGNAL(signalUserLogout()),
            this, SLOT(slotUserLogout()));
    connect(m_msgSocket, SIGNAL(signalUserLogoutResult(bool)),
            this, SLOT(slotUserLogoutResult(bool)));
}

EduClient::~EduClient()
{
    delete ui;
}

void EduClient::slotUserLogin(QString id, QString pswd)
{
    ///用户登录请求
    QString msg = QString(CMD_UserLogin_L)
            % QString("#") % id
            % QString("|") % pswd;
    m_msgSocket->slotSendMsg(msg);
}

void EduClient::slotChangePswd(QString pswd)
{
    qDebug() << "4";
    ///学生修改密码
    QString msg = QString(CMD_ChangePswd_H)
            % QString("#") % GlobalVars::g_localUser.getID()
            % QString("|") % pswd;
    m_msgSocket->slotSendMsg(msg);
}

void EduClient::slotChangedPswdResult(bool res)
{
    qDebug() << "触发";
    if(res)
    {
        if(GlobalVars::g_localUser.getRole() == "教职工")
        {
            m_teacherInfoForm->hide();
            m_teaScheduleForm->hide();
            m_teachPlanForm->hide();
            m_enterGradeForm->hide();
            m_teaChangePswdForm->hide();
        }else if(GlobalVars::g_localUser.getRole() == "学生")
        {
            m_studentInfoForm->hide();
            m_stuScheduleForm->hide();
            m_pickCourseForm->hide();
            m_queryGradeForm->hide();
            m_stuChangePswdForm->hide();
        }

        ui->mainToolBar->hide();
        m_loginForm->show();
    }
}

void EduClient::slotEnterGradeResult(bool res)
{
    if(res == true)
    {
        QMessageBox::information(this,"結果","录入信息成功！",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this,"結果","录入信息失败！",QMessageBox::Yes);
    }
}

void EduClient::slotUserLoginResult(bool res)
{
    if(res)
    {
        if(GlobalVars::g_localUser.getRole() == "教职工")
        {
            initTeachearMS();
        }else if(GlobalVars::g_localUser.getRole() == "学生")
        {
            initStudentMS();
        }

        ui->mainToolBar->show();
        m_loginForm->hide();

        ///个人信息请求
        QString msg = QString(CMD_UserInfo_I)
            % QString("#") % GlobalVars::g_localUser.getID()
            % QString("|") % GlobalVars::g_localUser.getRole();
        m_msgSocket->slotSendMsg(msg);
    }else
    {
        m_loginForm->userLoginFail();
    }
}

void EduClient::slotUserLogout(void)
{
    ///用户退出请求
    QString msg = QString(CMD_UserExit_X)
            % QString("#") % GlobalVars::g_localUser.getID();
    m_msgSocket->slotSendMsg(msg);
}

void EduClient::slotUserLogoutResult(bool res)
{
    qDebug() << "EduClient::slotUserLogoutResult(bool res)";
    m_isCloseSystem = res;
    this->close();
}

void EduClient::closeEvent(QCloseEvent *ev)
{
//    if(!m_isCloseSystem)
//    {
//        slotUserLogout();
//        ev->ignore();
//    }else
//    {
//        ev->accept();
//    }
}

void EduClient::initTeachearMS()
{
    this->setWindowTitle(tr("教务管理系统[教师端]"));
    m_teacherInfoForm = new TeacherInfoForm(ui->widget);
    m_teaScheduleForm = new TeaScheduleForm(ui->widget);
    m_teachPlanForm = new TeachPlanForm(ui->widget);
    m_enterGradeForm = new EnterGradeForm(ui->widget);
    m_teaChangePswdForm = new TeaChangePswdForm(ui->widget);

    connect(m_msgSocket, SIGNAL(signalGainTeacherInfo(bool)),
            m_teacherInfoForm, SLOT(slotGainTeacherInfo(bool)));
    connect(m_enterGradeForm, SIGNAL(signalEnterGrade(QString,QString,QString,QString)),
            this, SLOT(slotEnterGrade(QString,QString,QString,QString)));
    connect(m_msgSocket,&MsgSocket::signalEntryGradeReasult,this,&EduClient::slotEnterGradeResult);

    ui->mainToolBar->removeAction(ui->actionStudentInfo);
    ui->mainToolBar->removeAction(ui->actionStuSchedule);
    ui->mainToolBar->removeAction(ui->actionPickCourse);
    ui->mainToolBar->removeAction(ui->actionQueryGrade);
    ui->mainToolBar->removeAction(ui->actionStuChangePswd);

    on_actionTeacherInfo_triggered();
}

void EduClient::slotEnterGrade(QString stu_id,QString class_id,QString course_id,QString grade)
{
    QString msg = QString(CMD_EntryGrade_Y)
            % QString("#") % stu_id
            % QString("|") % class_id
            % QString("|") % course_id
            % QString("|") % grade;

    m_msgSocket->slotSendMsg(msg);
}

void EduClient::initStudentMS(void)
{
    this->setWindowTitle(tr("教务管理系统[学生端]"));
    m_studentInfoForm = new StudentInfoForm(ui->widget);
    m_stuScheduleForm = new StuScheduleForm(ui->widget);
    m_pickCourseForm = new PickCourseForm(ui->widget);
    m_queryGradeForm = new QueryGradeForm(ui->widget);
    m_stuChangePswdForm = new StuChangePswdForm(ui->widget);

    connect(m_msgSocket, SIGNAL(signalGainStudentInfo(bool)),
            m_studentInfoForm, SLOT(slotGainStudentInfo(bool)));
    connect(m_stuChangePswdForm,SIGNAL(signalChangePswd(QString)),
            this,SLOT(slotChangePswd(QString)));
    connect(m_msgSocket,SIGNAL(signalChangedPswdResult(bool)),
            this,SLOT(slotChangedPswdResult(bool)));

    ui->mainToolBar->removeAction(ui->actionTeacherInfo);
    ui->mainToolBar->removeAction(ui->actionTeaSchedule);
    ui->mainToolBar->removeAction(ui->actionTeachPlan);
    ui->mainToolBar->removeAction(ui->actionEnterGrade);
    ui->mainToolBar->removeAction(ui->actionTeaChangPswd);

    on_actionStudentInfo_triggered();
}

void EduClient::on_actionTeacherInfo_triggered()
{
    m_teacherInfoForm->show();
    m_teaScheduleForm->hide();
    m_teachPlanForm->hide();
    m_enterGradeForm->hide();
    m_teaChangePswdForm->hide();

    ui->actionTeacherInfo->setEnabled(false);
    ui->actionTeaSchedule->setEnabled(true);
    ui->actionTeachPlan->setEnabled(true);
    ui->actionEnterGrade->setEnabled(true);
    ui->actionTeaChangPswd->setEnabled(true);
}

void EduClient::on_actionTeaSchedule_triggered()
{
    m_teacherInfoForm->hide();
    m_teaScheduleForm->show();
    m_teachPlanForm->hide();
    m_enterGradeForm->hide();
    m_teaChangePswdForm->hide();

    ui->actionTeacherInfo->setEnabled(true);
    ui->actionTeaSchedule->setEnabled(false);
    ui->actionTeachPlan->setEnabled(true);
    ui->actionEnterGrade->setEnabled(true);
    ui->actionTeaChangPswd->setEnabled(true);
}

void EduClient::on_actionTeachPlan_triggered()
{
    m_teacherInfoForm->hide();
    m_teaScheduleForm->hide();
    m_teachPlanForm->show();
    m_enterGradeForm->hide();
    m_teaChangePswdForm->hide();

    ui->actionTeacherInfo->setEnabled(true);
    ui->actionTeaSchedule->setEnabled(true);
    ui->actionTeachPlan->setEnabled(false);
    ui->actionEnterGrade->setEnabled(true);
    ui->actionTeaChangPswd->setEnabled(true);
}

void EduClient::on_actionEnterGrade_triggered()
{
    m_teacherInfoForm->hide();
    m_teaScheduleForm->hide();
    m_teachPlanForm->hide();
    m_enterGradeForm->show();
    m_teaChangePswdForm->hide();

    ui->actionTeacherInfo->setEnabled(true);
    ui->actionTeaSchedule->setEnabled(true);
    ui->actionTeachPlan->setEnabled(true);
    ui->actionEnterGrade->setEnabled(false);
    ui->actionTeaChangPswd->setEnabled(true);
}

void EduClient::on_actionTeaChangPswd_triggered()
{
    m_teacherInfoForm->hide();
    m_teaScheduleForm->hide();
    m_teachPlanForm->hide();
    m_enterGradeForm->hide();
    m_teaChangePswdForm->show();

    ui->actionTeacherInfo->setEnabled(true);
    ui->actionTeaSchedule->setEnabled(true);
    ui->actionTeachPlan->setEnabled(true);
    ui->actionEnterGrade->setEnabled(true);
    ui->actionTeaChangPswd->setEnabled(false);
}

void EduClient::on_actionStudentInfo_triggered()
{
    m_studentInfoForm->show();
    m_stuScheduleForm->hide();
    m_pickCourseForm->hide();
    m_queryGradeForm->hide();
    m_stuChangePswdForm->hide();

    ui->actionStudentInfo->setEnabled(false);
    ui->actionStuSchedule->setEnabled(true);
    ui->actionPickCourse->setEnabled(true);
    ui->actionQueryGrade->setEnabled(true);
    ui->actionStuChangePswd->setEnabled(true);
}

void EduClient::on_actionStuSchedule_triggered()
{
    m_studentInfoForm->hide();
    m_stuScheduleForm->show();
    m_pickCourseForm->hide();
    m_queryGradeForm->hide();
    m_stuChangePswdForm->hide();

    ui->actionStudentInfo->setEnabled(true);
    ui->actionStuSchedule->setEnabled(false);
    ui->actionPickCourse->setEnabled(true);
    ui->actionQueryGrade->setEnabled(true);
    ui->actionStuChangePswd->setEnabled(true);
}

void EduClient::on_actionPickCourse_triggered()
{
    m_studentInfoForm->hide();
    m_stuScheduleForm->hide();
    m_pickCourseForm->show();
    m_queryGradeForm->hide();
    m_stuChangePswdForm->hide();

    ui->actionStudentInfo->setEnabled(true);
    ui->actionStuSchedule->setEnabled(true);
    ui->actionPickCourse->setEnabled(false);
    ui->actionQueryGrade->setEnabled(true);
    ui->actionStuChangePswd->setEnabled(true);
}

void EduClient::on_actionQueryGrade_triggered()
{
    m_studentInfoForm->hide();
    m_stuScheduleForm->hide();
    m_pickCourseForm->hide();
    m_queryGradeForm->show();
    m_stuChangePswdForm->hide();

    ui->actionStudentInfo->setEnabled(true);
    ui->actionStuSchedule->setEnabled(true);
    ui->actionPickCourse->setEnabled(true);
    ui->actionQueryGrade->setEnabled(false);
    ui->actionStuChangePswd->setEnabled(true);
}

void EduClient::on_actionStuChangePswd_triggered()
{
    m_studentInfoForm->hide();
    m_stuScheduleForm->hide();
    m_pickCourseForm->hide();
    m_queryGradeForm->hide();
    m_stuChangePswdForm->show();

    ui->actionStudentInfo->setEnabled(true);
    ui->actionStuSchedule->setEnabled(true);
    ui->actionPickCourse->setEnabled(true);
    ui->actionQueryGrade->setEnabled(true);
    ui->actionStuChangePswd->setEnabled(false);
}
