#-------------------------------------------------
#
# Project created by QtCreator 2016-10-07T11:46:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tickets
TEMPLATE = app
3
#SOURCES += ../../src/*.cpp
SOURCES += main.cpp\
        mainwindow.cpp
#HEADERS  += ../../src/*.h
HEADERS  += mainwindow.h
LIBS += ../../src/*.o

FORMS    += mainwindow.ui
