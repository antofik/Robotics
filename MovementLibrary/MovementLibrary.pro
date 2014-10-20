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

########## Whell motor controller ##################################

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../WheelMotorController/release/ -lWheelMotorController
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../WheelMotorController/debug/ -lWheelMotorController
else:unix:!macx: LIBS += -L$$OUT_PWD/../WheelMotorController/ -lWheelMotorController

INCLUDEPATH += $$PWD/../WheelMotorController
DEPENDPATH += $$PWD/../WheelMotorController

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WheelMotorController/release/libWheelMotorController.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WheelMotorController/debug/libWheelMotorController.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WheelMotorController/release/WheelMotorController.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WheelMotorController/debug/WheelMotorController.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../WheelMotorController/libWheelMotorController.a

####################################################################
