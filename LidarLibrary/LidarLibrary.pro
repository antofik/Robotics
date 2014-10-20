QT       -= gui

TARGET = LidarLibrary
TEMPLATE = lib
CONFIG += staticlib

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

win32 {
    ARDUINO = C:\arduino-1.0.5-r2
    #INCLUDEPATH += $$ARDUINO\hardware
    #INCLUDEPATH += $$ARDUINO\hardware\arduino
    #INCLUDEPATH += $$ARDUINO\hardware\arduino\cores
    #INCLUDEPATH += $$ARDUINO\hardware\arduino\cores\arduino
    #INCLUDEPATH += $$ARDUINO\hardware\arduino\variants
    #INCLUDEPATH += $$ARDUINO\hardware\tools\avr\avr\include
    #INCLUDEPATH += $$ARDUINO\hardware\arduino\variants\standard

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
}


unix{
    SOURCES += ../ThirdParty/smc-wrapper/smc.cpp
    HEADERS += ../ThirdParty/smc-wrapper/smc.h
    LIBS += /home/ubuntu/c_environment/*.so
    INCLUDEPATH += /usr/include/
    INCLUDEPATH += smc-wrapper
    INCLUDEPATH += /home/ubuntu/c_environment/hardware
    INCLUDEPATH += /home/ubuntu/c_environment/hardware/arduino
    INCLUDEPATH += /home/ubuntu/c_environment/hardware/arduino/cores
    INCLUDEPATH += /home/ubuntu/c_environment/hardware/arduino/cores/arduino
    INCLUDEPATH += /home/ubuntu/c_environment/hardware/arduino/variants
    INCLUDEPATH += /home/ubuntu/c_environment/hardware/arduino/variants/sunxi
    INCLUDEPATH += /home/ubuntu/c_environment/libraries
    INCLUDEPATH += /home/ubuntu/c_environment/libraries/SPI
    INCLUDEPATH += /home/ubuntu/c_environment/ibraries/Wire
    INCLUDEPATH += /home/ubuntu/c_environment/libraries/PN532_SPI
}

win32 {

}
