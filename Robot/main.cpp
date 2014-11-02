#include <QCoreApplication>
//#include "Arduino.h"
//#include "Serial.h"
#include <Qt>
#include <QDebug>
#include <QtCore>
#include "settings.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Robot" << "v"+ Settings::getStringValue("version") << "launched";

    return a.exec();
}

void setup(){}

void loop() {}
