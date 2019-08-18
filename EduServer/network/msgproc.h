#ifndef MSGPROC_H
#define MSGPROC_H

#include <QThread>

class MsgProc : public QThread
{
    Q_OBJECT

signals:
    void signalSendMsgToClient(QString id, QString msg);

public:
    explicit MsgProc(QThread *parent = 0);
    void exitThread(void);

protected:
    void run();

private:
    bool m_isExit;

    void parseUserAsk(QString msg);
    ///通用请求命令 - 登录退出在MsgSocket中实现
//    void parseUserLogin(QString data);
    void parseUserInfo(QString data);
    void parseChangePswd(QString data);
//    void parseUserExit(QString data);
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

#endif // MSGPROC_H
