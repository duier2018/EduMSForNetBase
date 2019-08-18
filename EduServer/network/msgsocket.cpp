#include "msgsocket.h"
#include "globalvars.h"

#include <QStringBuilder>
#include "execsql.h"
#include "userinfo.h"

MsgSocket::MsgSocket(QTcpSocket *socket, QObject *parent):
    QObject(parent)
{
    qDebug() << "MsgSocket::MsgSocket";
    m_tcpBlockSize = 0;

    m_socket = socket;
    connect(m_socket, SIGNAL(disconnected()),
            m_socket, SLOT(deleteLater()));
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
}

MsgSocket::~MsgSocket()
{
    delete m_socket;
}

void MsgSocket::slotReadyRead()
{
    qDebug() << "MsgSocket::slotReadyRead()";
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_4_6);

    if(m_tcpBlockSize == 0)
    {
        if(m_socket->bytesAvailable()<sizeof(quint16))
            return;

        in >> m_tcpBlockSize;
    }

    if(m_socket->bytesAvailable() < m_tcpBlockSize)
        return;

    QString msg;
    in >> msg;
    qDebug() << "Server Recv: " << msg;
    parseUserAsk(msg);

//    if(msg.at(0) == CMD_UserLogin_L)
//    {
//        parseUserLogin(msg);
//    }else if(msg.at(0) == CMD_UserExit_X)
//    {
//        parseUserExit(msg);
//    }else
//    {
//        GlobalVars::g_msgQueue.enqueue(msg);
//    }
    m_tcpBlockSize = 0;
}

///解析通用请求命令
void MsgSocket::parseUserAsk(QString msg)
{
    QStringList list = msg.split("#");
    int cmd = msg.at(0).toLatin1();
    qDebug() << cmd;
    switch (cmd) {
    ///通用请求命令
    case CMD_UserLogin_L: parseUserLogin(list.at(1)); break;
    case CMD_UserInfo_I: parseUserInfo(list.at(1)); break;
    case CMD_ChangePswd_H: parseChangePswd(list.at(1)); break;
    case CMD_UserExit_X: parseUserExit(list.at(1)); break;
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

void MsgSocket::parseUserLogin(QString msg)
{
    qDebug() << "MsgSocket::parseUserLogin" << msg;

    QStringList list = msg.split("|");
    QString id = list.at(0);
    QString pswd = list.at(1);

    if(GlobalVars::g_userInfoMap.contains(id))
    {
        UserInfoList::iterator it = GlobalVars::g_userInfoMap[id];
        it->display();
        if(it->getPswd() == pswd)
        {
            QString msg = QString(CMD_UserLogin_L)
                    % QString("#!|") % it->getID()
                    % "|" % it->getPswd()
                    % "|" % it->getRole()
                    % "|" % it->getDate();
            this->slotSendMsg(msg);
        }else
        {
            QString msg = QString(CMD_UserLogin_L)
                    % QString("#?|") % QString("Error: UID Or Pswd!");
            this->slotSendMsg(msg);
        }
    }
}

void MsgSocket::parseUserInfo(QString data)
{
    qDebug() << "MsgSocket::parseUserInfo" << data;
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
            slotSendMsg(msg);
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
            slotSendMsg(msg);
        }
    }else
    {
        QString msg = QString(CMD_UserInfo_I)
                % QString("#?|") % QString("Error: DataError");
        slotSendMsg(msg);
    }

}

void MsgSocket::parseChangePswd(QString msg)
{
    qDebug() << "MsgSocket::parseChangePswd" << msg;
    msg.remove("H#");
    QStringList list = msg.split('|');
    if(ExecSQL::modifyUserInfoForPswd(list.at(0),list.at(1)))
    {
        GlobalVars::g_userInfoMap[list.at(0)]->setPswd(list.at(1));
        QString msg1 = QString(CMD_ChangePswd_H)
                % QString("#!|") % list.at(0) % "|" % list.at(1);
        slotSendMsg(msg1);
    }
}

void MsgSocket::parseUserExit(QString msg)
{
    qDebug() << "MsgSocket::parseUserExit" << msg;
    msg.remove("X#");

    emit signalLogoutSocket(msg, this);
    QString msg1 = QString(CMD_UserExit_X)
            % QString("#!|") % msg;
    if(this->slotSendMsg(msg1))
    {
        delete this;
    }
}

///解析学生请求命令
void MsgSocket::parseStudentSchedule(QString data)
{

}

void MsgSocket::parseOptionCourse(QString data)
{

}

void MsgSocket::parseSelectedCourse(QString data)
{

}

void MsgSocket::parsePickCourse(QString data)
{

}
void MsgSocket::parseQueryGrade(QString data)
{

}
///解析老师请求命令
void MsgSocket::parseTeahcerSchedule(QString data)
{

}
void MsgSocket::parseGrantCourse(QString data)
{

}
void MsgSocket::parseExistClass(QString data)
{

}
void MsgSocket::parseNewClass(QString data)
{

}
void MsgSocket::parseAddTeaches(QString data)
{

}
void MsgSocket::parsePickResult(QString data)
{

}
void MsgSocket::parseEntryGrade(QString data)
{
    qDebug() << "parseEntryGrade" << data;

    QStringList list = data.split('|');
    if(ExecSQL::EntryGrade(list.at(0),list.at(1),list.at(2),list.at(3)))
    {
//        GlobalVars::g_userInfoMap[list.at(0)]->setPswd(list.at(1));
        QString msg1 = QString(CMD_EntryGrade_Y)
                % QString("#!|") % list.at(0) % "|" % "true";
        slotSendMsg(msg1);
    }
    else
    {
        QString msg1 = QString(CMD_EntryGrade_Y)
                % QString("#!|") % list.at(0) % "|" % "false";
        slotSendMsg(msg1);
    }
}

bool MsgSocket::slotSendMsg(QString msg)
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out << (quint16)0;
    out << msg;
    out.device()->seek(0);
    out << (quint16)(buffer.size() - sizeof(quint16));

    qDebug() << "Server Send: " << msg;
    return m_socket->write(buffer);
}

