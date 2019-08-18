#include "connectsqilte.h"

#include <QSqlDatabase>
#include <QSqlError>

ConnectSQilte::ConnectSQilte()
{

}

bool ConnectSQilte::createConnection()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EduServer/database/ugedu.db");

    if(!db.open()){
        qCritical("Can't open database: %s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());

        return false;
    }
    return true;
}

void ConnectSQilte::closeConnection()
{
    QSqlDatabase::database().close();
}



