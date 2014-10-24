QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = LidarLibraryTest
TEMPLATE = app
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
FORMS    += mainwindow.ui

############################ Lidar Library #################################################################################

INCLUDEPATH += $$PWD/../LidarLibrary
DEPENDPATH += $$PWD/../LidarLibrary
PRE_TARGETDEPS += $$OUT_PWD/../LidarLibrary/libLidarLibrary.a
LIBS += -L$$OUT_PWD/../LidarLibrary/ -lLidarLibrary

#############################################################################################################################

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

SOURCES += ../ThirdParty/smc-wrapper/smc.cpp
HEADERS += ../ThirdParty/smc-wrapper/smc.h

#PRE_TARGETDEPS += $$OUT_PWD/../ThirdParty/c_environment/libarduino.a
#LIBS += /home/anton/Robotics/ThirdParty/c_environment/libarduino.so
INCLUDEPATH += /usr/include/
