#ifndef MSGSOCKET_H
#define MSGSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QMap>

class MsgSocket : public QObject
{
    Q_OBJECT
signals:
    void signalRegisterSocket(QString id, MsgSocket *socket);
    void signalLogoutSocket(QString id, MsgSocket *socket);

public slots:
    void slotReadyRead();
    bool slotSendMsg(QString msg);

public:
    explicit MsgSocket(QTcpSocket *socket, QObject *parent = 0);
    ~MsgSocket();

    QString m_localUid;

private:
    quint16 m_tcpBlockSize;
    QTcpSocket *m_socket;

    void parseUserAsk(QString msg);
    ///通用请求命令 - 登录退出在MsgSocket中实现
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

typedef QMap<QString, MsgSocket*> SocketMap;//id, socket

#endif // MSGSOCKET_H
