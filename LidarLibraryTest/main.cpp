#include "mainwindow.h"
#include <QApplication>
#include "Arduino.h"
#include "Serial.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void setup(){}

void loop() {}
