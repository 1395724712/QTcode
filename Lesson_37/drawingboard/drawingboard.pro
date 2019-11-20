#-------------------------------------------------
#
# Project created by QtCreator 2019-11-19T13:15:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drawingboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    mywidget.h

FORMS    += mainwindow.ui

CONFIG +=C++11
