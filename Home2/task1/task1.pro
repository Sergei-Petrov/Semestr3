#-------------------------------------------------
#
# Project created by QtCreator 2012-09-25T15:21:01
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   += qtestlib
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Computer.cpp \
    Network.cpp

HEADERS += \
    OS.h \
    Linux.h \
    Windows.h \
    Computer.h \
    Network.h \
    NetworkTest.h \
    MacOS.h \
    Sleeper.h \
    Random.h
