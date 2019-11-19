#-------------------------------------------------
#
# Project created by QtCreator 2019-11-16T16:13:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 09_event
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS  += mywidget.h \
    mylabel.h \
    mybutton.h

FORMS    += mywidget.ui

CONFIG +=C++11
