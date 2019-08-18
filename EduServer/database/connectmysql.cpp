#include "connectmysql.h"

#include <QSqlDatabase>
#include <QSqlError>

ConnectMySQL::ConnectMySQL()
{

}

bool ConnectMySQL::createConnection()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("tempdb");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()){
        qCritical("Can't open database: %s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());

        return false;
    }
    return true;
}

void ConnectMySQL::closeConnection()
{
    QSqlDatabase::database().close();
}



