#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T19:08:41
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EduClient
TEMPLATE = app

INCLUDEPATH += $$PWD/include
include(subteacher/subteacher.pri)
include(substudent/substudent.pri)
include(sublogin/sublogin.pri)
include(subinfos/subinfos.pri)
include(network/network.pri)

SOURCES += main.cpp\
        educlient.cpp \
    globalvars.cpp

HEADERS  += educlient.h \
    globalvars.h

FORMS    += educlient.ui

RESOURCES += \
    icons.qrc \
    language.qrc

TRANSLATIONS += ch2en.ts

DISTFILES += \
    ch2en.ts
