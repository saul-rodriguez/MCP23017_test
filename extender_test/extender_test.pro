#-------------------------------------------------
#
# Project created by QtCreator 2014-04-20T21:23:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = extender_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mcp23017_isr.cpp \
    mcp23017.cpp

LIBS    += -lwiringPi

HEADERS  += mainwindow.h \
    mcp23017_isr.h \
    mcp23017.h \
    hardware_conf.h

FORMS    += mainwindow.ui
