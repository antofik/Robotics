QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LidarLibraryTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LidarLibrary/release/ -lLidarLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LidarLibrary/debug/ -lLidarLibrary
else:unix:!macx: LIBS += -L$$OUT_PWD/../LidarLibrary/ -lLidarLibrary

INCLUDEPATH += $$PWD/../LidarLibrary
DEPENDPATH += $$PWD/../LidarLibrary

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LidarLibrary/release/libLidarLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LidarLibrary/debug/libLidarLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LidarLibrary/release/LidarLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LidarLibrary/debug/LidarLibrary.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../LidarLibrary/libLidarLibrary.a
