#-------------------------------------------------
#
# Project created by QtCreator 2018-09-03T12:53:27
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stocks_lister
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    htmldownloader.cpp

HEADERS  += mainwindow.h \
    htmldownloader.h

FORMS    += mainwindow.ui
