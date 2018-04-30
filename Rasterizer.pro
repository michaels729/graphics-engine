#-------------------------------------------------
#
# Project created by QtCreator 2018-02-14T23:08:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rasterizer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        fileuploadwidget.cpp \
        drawwidget.cpp \
    cameraspace.cpp \
    ndcspace.cpp \
    screenspace.cpp \
    projector.cpp \
    rasterspace.cpp \
    cameraspace.cpp \
    ndcspace.cpp \
    rasterspace.cpp \
    screenspace.cpp

HEADERS += \
        mainwindow.h \
        fileuploadwidget.h \
        drawwidget.h \
    primitive.h \
    ndcspace.h \
    screenspace.h \
    rasterspace.h \
    projector.h \
    cameraspace.h \
    ndcspace.h \
    rasterspace.h \
    screenspace.h

FORMS += \
        mainwindow.ui \
        fileuploadwidget.ui \
        drawwidget.ui

INCLUDEPATH += $$PWD/include
