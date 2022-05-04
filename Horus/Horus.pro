#-------------------------------------------------
#
# Project created by QtCreator 2022-03-08T15:07:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TARGET = Horus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR     = $$PWD/../bin

SOURCES += \
        main.cpp \
        widget.cpp \
    appinit.cpp \
    settings.cpp \
    cameramanagement.cpp \
    syssettings.cpp \
    iconhelper.cpp \
    yolov5.cpp \
    monitor.cpp \
    aidetect.cpp \
    mainwindow.cpp

HEADERS += \
        widget.h \
    appinit.h \
    settings.h \
    cameramanagement.h \
    syssettings.h \
    iconhelper.h \
    yolov5.h \
    monitor.h \
    aidetect.h \
    mainwindow.h

FORMS += \
    widget.ui \
    settings.ui \
    cameramanagement.ui \
    syssettings.ui \
    monitor.ui \
    aidetect.ui \
    mainwindow.ui

CONFIG += warn_off

INCLUDEPATH += $$PWD/ffmpeg
include ($$PWD/ffmpeg/ffmpeg.pri)

RESOURCES += \
    res.qrc


    INCLUDEPATH += D:\opencv\build\install\include\
                   D:\opencv\build\install\include\opencv2





