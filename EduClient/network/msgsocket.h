#ifndef MSGSOCKET_H
#define MSGSOCKET_H

#include <QObject>
#include <QTcpSocket>

#include "userinfo.h"

class MsgSocket : public QObject
{
    Q_OBJECT

signals:
    void signalUserLoginResult(bool res);
    void signalUserLogoutResult(bool res);
    void signalGainTeacherInfo(bool res);
    void signalGainStudentInfo(bool res);
    void signalChangedPswdResult(bool res);
    void signalEntryGradeReasult(bool res);

public slots:
    void slotReadyRead();
    void slotSendMsg(QString msg);

public:
    explicit MsgSocket(QObject *parent = 0);
    ~MsgSocket();

//protected:
//    void run();

private:
//    bool m_isExit;
    quint16 m_tcpBlockSize;
    QTcpSocket *m_tcpSocket;

    void parseUserAsk(QString msg);
    ///解析通用请求命令
    void parseUserLogin(QString data);
    void parseUserInfo(QString data);
    void parseChangePswd(QString data);
    void parseUserExit(QString data);
    ///解析学生请求命令
    void parseStudentSchedule(QString data);
    void parseOptionCourse(QString data);
    void parseSelectedCourse(QString data);
    void parsePickCourse(QString data);
    void parseQueryGrade(QString data);
    ///解析老师请求命令
    void parseTeahcerSchedule(QString data);
    void parseGrantCourse(QString data);
    void parseExistClass(QString data);
    void parseNewClass(QString data);
    void parseAddTeaches(QString data);
    void parsePickResult(QString data);
    void parseEntryGrade(QString data);
};

#endif // MSGSOCKET_H
