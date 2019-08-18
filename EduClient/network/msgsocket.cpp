#include "msgsocket.h"

#include <QDebug>
#include "globalvars.h"

MsgSocket::MsgSocket(QObject *parent) :
    QObject(parent)
{
    m_tcpBlockSize = 0;
    m_tcpSocket = new QTcpSocket(this);

    connect(m_tcpSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));

    m_tcpSocket->connectToHost("127.0.0.1", 55555);
}

MsgSocket::~MsgSocket()
{

}

//void MsgSocket::run()
//{
//    while(!m_isExit)
//    {
//        if(!GlobalVars::g_msgQueue.isEmpty())
//        {
//            QString msg = GlobalVars::g_msgQueue.dequeue();
//            parseUserAsk(msg);
//        }
//        msleep(20);
//    }
//}

void MsgSocket::slotReadyRead()
{
    QDataStream in(m_tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);

    if(m_tcpBlockSize == 0)
    {
        if(m_tcpSocket->bytesAvailable()<sizeof(quint16))
            return;

        in >> m_tcpBlockSize;
    }

    if(m_tcpSocket->bytesAvailable() < m_tcpBlockSize)
        return;

    QString msg;
    in >> msg;
    qDebug() << "Client Recv: " << msg;
//    GlobalVars::g_msgQueue.enqueue(msg);
    parseUserAsk(msg);
    m_tcpBlockSize = 0;
}

///解析通用请求命令
void MsgSocket::parseUserAsk(QString msg)
{
    QStringList list = msg.split("#");
    int cmd = msg.at(0).toLatin1();
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

void MsgSocket::parseUserLogin(QString data)
{
    qDebug() << "MsgSocket::parseUserLogin" << data;
    QStringList list = data.split("|");
    int res = data.at(0).toLatin1();
    if(RES_Down == res)
    {
        GlobalVars::g_localUser.setID(list.at(1));
        GlobalVars::g_localUser.setPswd(list.at(2));
        GlobalVars::g_localUser.setRole(list.at(3));
        GlobalVars::g_localUser.setDate(list.at(4));
        emit signalUserLoginResult(true);
    }else
    {
        emit signalUserLoginResult(false);
    }
}

void MsgSocket::parseUserInfo(QString data)
{
    qDebug() << "MsgSocket::parseUserInfo" << data;
    QStringList list = data.split("|");
    int res = data.at(0).toLatin1();
    if(RES_Down == res)
    {
        if(GlobalVars::g_localUser.getRole() == "教职工")
        {
            GlobalVars::g_localTeacher.setID(list.at(1));
            GlobalVars::g_localTeacher.setName(list.at(2));
            GlobalVars::g_localTeacher.setDept(list.at(3));
            GlobalVars::g_localTeacher.setPost(list.at(4));
            emit signalGainTeacherInfo(true);
        }else
        {
            GlobalVars::g_localStudent.setID(list.at(1));
            GlobalVars::g_localStudent.setName(list.at(2));
            GlobalVars::g_localStudent.setDegree(list.at(3));
            GlobalVars::g_localStudent.setMajor(list.at(4));
            emit signalGainStudentInfo(true);
        }
    }
}

void MsgSocket::parseChangePswd(QString data)
{
    qDebug() << "------------parseChangePswd" << data;
    emit signalChangedPswdResult(true);
}

void MsgSocket::parseUserExit(QString data)
{
    QStringList list = data.split("|");
    int res = data.at(0).toLatin1();
    QString uid = list.at(1);
    if((RES_Down == res)&&(uid == GlobalVars::g_localUser.getID()))
    {
        emit signalUserLogoutResult(true);
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
    qDebug() << "MsgSocket::parseEntryGrade" << data;

    QStringList list = data.split('|');
    if(list.at(2) == "true")
    {
        emit signalEntryGradeReasult(true);
    }
    else
    {
        emit signalEntryGradeReasult(false);
    }
}

void MsgSocket::slotSendMsg(QString msg)
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out << (quint16)0;
    out << msg;
    out.device()->seek(0);
    out << (quint16)(buffer.size() - sizeof(quint16));

    qDebug() << "Client Send: " << msg;
    m_tcpSocket->write(buffer);
}

