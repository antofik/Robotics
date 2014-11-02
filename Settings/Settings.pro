QT       -= gui

TARGET = Settings
TEMPLATE = lib
CONFIG += staticlib

SOURCES += settings.cpp

HEADERS += settings.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
