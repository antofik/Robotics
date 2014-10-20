QT       += network
QT       -= gui

TARGET = WheelMotorController
TEMPLATE = lib
CONFIG += staticlib

SOURCES += wheelmotorcontroller.cpp

HEADERS += wheelmotorcontroller.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
