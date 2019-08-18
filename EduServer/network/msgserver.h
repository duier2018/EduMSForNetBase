#ifndef MSGSERVER_H
#define MSGSERVER_H

#include <QObject>
#include <QTcpServer>

#include "msgproc.h"
#include "msgsocket.h"

class MsgServer : public QObject
{
    Q_OBJECT
public slots:
    void slotNewConnection();

public:
    explicit MsgServer(QObject *parent = 0);
    ~MsgServer();

private:
    QTcpServer *m_server;
};

#endif // MSGSERVER_H
