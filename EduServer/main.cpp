#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>

#include "globalvars.h"
#include "connectsqilte.h"
#include "connectmysql.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if USE_DATABASE
    ConnectMySQL sql;
    if(sql.createConnection())
    {
        qDebug() << "Success: connect DB!!";
    }
#else
    FileOper fop;
    fop.readAndInitBuffers();
#endif //USE_DATABASE

    QTranslator translator;
    translator.load(":/ch2en.qm");
    app.installTranslator(&translator);

    MainWindow w;
    w.show();

    int res = app.exec();
#if USE_DATABASE
    sql.closeConnection();
#else
    fop.saveAndCloseBuffers();
#endif //USE_DATABASE

    return res;
}
