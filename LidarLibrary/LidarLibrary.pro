QT       -= gui

TARGET = LidarLibrary
TEMPLATE = lib
CONFIG += staticlib

target.path = /usr/lib
INSTALLS += target

SOURCES += datafilereader.cpp \
            serialreader.cpp \
            lidar.cpp \
            lidarlibrary.cpp


HEADERS  += datafilereader.h \
            serialreader.h \
            lidar.h \
            lidarlibrary.h

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

#LIBS += ../ThirdParty/c_environment/*.so
INCLUDEPATH += /usr/include/
