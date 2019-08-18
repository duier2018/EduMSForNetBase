#include "educlient.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load(":/ch2en.qm");
    app.installTranslator(&translator);

    EduClient w;
    w.show();

    return app.exec();
}
