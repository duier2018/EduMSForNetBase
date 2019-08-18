#include "msgserver.h"
#include "globalvars.h"

#include "execsql.h"
#include <QStringBuilder>

MsgServer::MsgServer(QObject *parent):
    QObject(parent)
{
    m_server = new QTcpServer(this);
    connect(m_server, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));
    m_server->listen(QHostAddress::Any, 55555);
}

MsgServer::~MsgServer()
{
}

void MsgServer::slotNewConnection()
{
    qDebug() << "MsgServer::slotNewConnection()";
    QTcpSocket *socket = m_server->nextPendingConnection();
    MsgSocket *msgSocket = new MsgSocket(socket);
    connect(socket, SIGNAL(disconnected()),
            socket, SLOT(deleteLater()));
}
