QT       += network
QT       -= gui

TARGET = MovementLibrary
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += movementlibrary.cpp

HEADERS += movementlibrary.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
