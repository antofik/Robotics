QT       += core
QT       -= gui

TARGET = Robot
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


INCLUDEPATH += ../ThirdParty/c_environment/hardware/arduino/cores/arduino
INCLUDEPATH += ../ThirdParty/c_environment/hardware
INCLUDEPATH += ../ThirdParty/c_environment/hardware/arduino
INCLUDEPATH += ../ThirdParty/c_environment/hardware/arduino/cores
INCLUDEPATH += ../ThirdParty/c_environment/hardware/arduino/cores/arduino
INCLUDEPATH += ../ThirdParty/c_environment/hardware/arduino/variants
INCLUDEPATH += ../ThirdParty/c_environment/hardware/arduino/variants/sunxi
INCLUDEPATH += ../ThirdParty/c_environment/libraries
INCLUDEPATH += ../ThirdParty/c_environment/libraries/SPI
INCLUDEPATH += ../ThirdParty/c_environment/ibraries/Wire
INCLUDEPATH += ../ThirdParty/c_environment/libraries/PN532_SPI
INCLUDEPATH += ../ThirdParty/smc-wrapper

#SOURCES += ../ThirdParty/smc-wrapper/smc.cpp
#HEADERS += ../ThirdParty/smc-wrapper/smc.h

#LIBS += $$PWD/../ThirdParty/c_environment/libarduino.so
#INCLUDEPATH += /usr/include/
#PRE_TARGETDEPS += $$PWD/../ThirdParty/c_environment/libarduino.a

LIBS += -L$$OUT_PWD/../Settings/ -lSettings
INCLUDEPATH += $$PWD/../Settings
DEPENDPATH += $$PWD/../Settings
PRE_TARGETDEPS += $$OUT_PWD/../Settings/libSettings.a
