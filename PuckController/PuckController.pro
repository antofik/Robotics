QT       += network
QT       -= gui

TARGET = PuckController
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += puckcontroller.cpp

HEADERS += puckcontroller.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
