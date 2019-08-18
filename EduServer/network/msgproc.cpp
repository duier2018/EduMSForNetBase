#include "msgproc.h"

#include "execsql.h"
#include <QStringBuilder>

MsgProc::MsgProc(QThread *parent) :
    QThread(parent)
{
    m_isExit = false;
}

void MsgProc::exitThread(void)
{
    m_isExit = true;
}

void MsgProc::run()
{
    while(!m_isExit)
    {
        if(!GlobalVars::g_msgQueue.isEmpty())
        {
            QString msg = GlobalVars::g_msgQueue.dequeue();
            parseUserAsk(msg);
        }
        msleep(20);
    }
}

///解析通用请求命令
void MsgProc::parseUserAsk(QString msg)
{
    QStringList list = msg.split("#");
    int cmd = msg.at(0).toLatin1();
    switch (cmd) {
    ///通用请求命令
//    case CMD_UserLogin_L: parseUserLogin(list.at(1)); break;
    case CMD_UserInfo_I: parseUserInfo(list.at(1)); break;
    case CMD_ChangePswd_H: parseChangePswd(list.at(1)); break;
//    case CMD_UserExit_X: parseUserExit(list.at(1)); break;
    ///学生请求命令
    case CMD_StudentSchedule_U: parseStudentSchedule(list.at(1)); break;
    case CMD_OptionzCourse_O: parseOptionCourse(list.at(1)); break;
    case CMD_SelectedCourse_S: parseSelectedCourse(list.at(1)); break;
    case CMD_PickCourse_P: parsePickCourse(list.at(1)); break;
    case CMD_QueryGrade_Q: parseQueryGrade(list.at(1)); break;
    ///老师请求命令
    case CMD_TeacherSchedule_T: parseTeahcerSchedule(list.at(1)); break;
    case CMD_GrantCourse_G: parseGrantCourse(list.at(1)); break;
    case CMD_ExistClass_E: parseExistClass(list.at(1)); break;
    case CMD_NewClass_N: parseNewClass(list.at(1)); break;
    case CMD_AddTeaches_A: parseAddTeaches(list.at(1)); break;
    case CMD_PickResult_R: parsePickResult(list.at(1)); break;
    case CMD_EntryGrade_Y: parseEntryGrade(list.at(1)); break;
    default:
        break;
    }
}

//void MsgProc::parseUserLogin(QString data)
//{
//}

void MsgProc::parseUserInfo(QString data)
{
    qDebug() << "MsgProc::parseUserInfo" << data;
    QStringList list = data.split("|");
    QString id = list.at(0);
    QString role = list.at(1);
    if(role == "教职工")
    {
        if(GlobalVars::g_teacherInfoMap.contains(id))
        {
            TeacherInfoList::iterator it = GlobalVars::g_teacherInfoMap[id];
            QString msg = QString(CMD_UserInfo_I)
                    % QString("#!|") % it->getID()
                    % "|" % it->getName()
                    % "|" % it->getDept()
                    % "|" % it->getPost();
            emit signalSendMsgToClient(id, msg);
        }
    }else if(role == "学生")
    {
        if(GlobalVars::g_studentInfoMap.contains(id))
        {
            StudentInfoList::iterator it = GlobalVars::g_studentInfoMap[id];
            QString msg = QString(CMD_UserInfo_I)
                    % QString("#!|") % it->getID()
                    % "|" % it->getName()
                    % "|" % it->getDegree()
                    % "|" % it->getMajor();
            emit signalSendMsgToClient(id, msg);
        }
    }else
    {
        QString msg = QString(CMD_UserInfo_I)
                % QString("#?|") % QString("Error: DataError");
        emit signalSendMsgToClient(id, msg);
    }

}

void MsgProc::parseChangePswd(QString data)
{

}

//void MsgProc::parseUserExit(QString data)
//{
//}

///解析学生请求命令
void MsgProc::parseStudentSchedule(QString data)
{

}

void MsgProc::parseOptionCourse(QString data)
{

}

void MsgProc::parseSelectedCourse(QString data)
{

}

void MsgProc::parsePickCourse(QString data)
{

}
void MsgProc::parseQueryGrade(QString data)
{

}
///解析老师请求命令
void MsgProc::parseTeahcerSchedule(QString data)
{

}
void MsgProc::parseGrantCourse(QString data)
{

}
void MsgProc::parseExistClass(QString data)
{

}
void MsgProc::parseNewClass(QString data)
{

}
void MsgProc::parseAddTeaches(QString data)
{

}
void MsgProc::parsePickResult(QString data)
{

}
void MsgProc::parseEntryGrade(QString data)
{

}

