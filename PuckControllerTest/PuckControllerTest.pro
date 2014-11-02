QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PuckControllerTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DEPENDPATH += .
LIBS += -Lcv -Lhighgui
LIBS += /usr/lib/x86_64-linux-gnu/libopencv*.so
#LIBS += /usr/lib/*.so
#LIBS += /usr/local/lib/*.so
