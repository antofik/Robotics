QT       -= gui

TARGET = LidarLibrary
TEMPLATE = lib
CONFIG += staticlib c++11

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += datafilereader.cpp \
            serialreader.cpp \
            lidar.cpp \
            lidarlibrary.cpp


HEADERS  += datafilereader.h \
            serialreader.h \
            lidar.h \
            lidarlibrary.h

unix{
    SOURCES += ../ThirdParty/smc-wrapper/smc.cpp
    HEADERS += ../ThirdParty/smc-wrapper/smc.h
    LIBS += /home/ubuntu/c_enviroment/*.so
    INCLUDEPATH += /usr/include/
    INCLUDEPATH += smc-wrapper
    INCLUDEPATH += /home/ubuntu/c_enviroment/hardware
    INCLUDEPATH += /home/ubuntu/c_enviroment/hardware/arduino
    INCLUDEPATH += /home/ubuntu/c_enviroment/hardware/arduino/cores
    INCLUDEPATH += /home/ubuntu/c_enviroment/hardware/arduino/cores/arduino
    INCLUDEPATH += /home/ubuntu/c_enviroment/hardware/arduino/variants
    INCLUDEPATH += /home/ubuntu/c_enviroment/hardware/arduino/variants/sunxi
    INCLUDEPATH += /home/ubuntu/c_enviroment/libraries
    INCLUDEPATH += /home/ubuntu/c_enviroment/libraries/SPI
    INCLUDEPATH += /home/ubuntu/c_enviroment/ibraries/Wire
    INCLUDEPATH += /home/ubuntu/c_enviroment/libraries/PN532_SPI
}

win32 {

}
