QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MovementLibraryTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

########## Movement library ##################################

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MovementLibrary/release/ -lMovementLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MovementLibrary/debug/ -lMovementLibrary
else:unix:!macx: LIBS += -L$$OUT_PWD/../MovementLibrary/ -lMovementLibrary

INCLUDEPATH += $$PWD/../MovementLibrary
DEPENDPATH += $$PWD/../MovementLibrary

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MovementLibrary/release/libMovementLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MovementLibrary/debug/libMovementLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MovementLibrary/release/MovementLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MovementLibrary/debug/MovementLibrary.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../MovementLibrary/libMovementLibrary.a

##############################################################
