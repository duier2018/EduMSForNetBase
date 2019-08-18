#-------------------------------------------------
#
# Project created by QtCreator 2019-03-07T11:07:11
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EduServer
TEMPLATE = app

INCLUDEPATH += $$PWD/include
include(subinfos/subinfos.pri)
include(subwidgets/subwidgets.pri)
include(sublogin/sublogin.pri)
#include(datafiles/datafiles.pri)
include(database/database.pri)
include(network/network.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    globalvars.cpp

HEADERS  += mainwindow.h \
    globalvars.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc \
    config.qrc

TRANSLATIONS += ch2en.ts

DISTFILES += \
    datafiles/class.txt \
    datafiles/course.txt \
    datafiles/grade.txt \
    datafiles/student.txt \
    datafiles/teacher.txt \
    ch2en.ts
