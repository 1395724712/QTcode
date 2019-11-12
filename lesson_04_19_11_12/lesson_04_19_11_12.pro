#-------------------------------------------------
#
# Project created by QtCreator 2019-11-12T14:19:40
#
#-------------------------------------------------

#模块，F1去官网找
QT       += core gui

#我当前是QT5.5.1高于Qt4,添加QT+=widgets是为了兼容QT4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#应用程序的名字，是可以改的
TARGET = lesson_04_19_11_12

#通过makefile生成可执行程序，这里指定makefile的类型，app
TEMPLATE = app

#源文件
SOURCES += main.cpp\
        mywidget.cpp

#头文件
HEADERS  += mywidget.h
