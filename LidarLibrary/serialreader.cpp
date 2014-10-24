#include <Qt>
#include <QtCore>
#include <QTime>
#include <QThread>
#include <iostream>
#include <fstream>
#include "Arduino.h"
#include "Serial.h"
#include "serialreader.h"

serialreader::serialreader(QObject *parent) :
    QObject(parent)
{
    running = false;
    record = false;

    static QThread thread;
    moveToThread(&thread);
    thread.start();
}

void serialreader::start()
{
    Serial.begin(115200);

    std::cout << "serial started" << std::endl;

    running = true;
    while(running)
    {        
        if (Serial.available() > 0)
        {
            int value = Serial.read();

            if (record)
            {
                unsigned char ch = value;
                FILE* fh;
                fh = fopen(filename.toLocal8Bit(),"ab+");
                fwrite(&ch, sizeof(ch),1,fh);
                fclose(fh);
            }
            //std::cout << "~" << value << std::endl;

            emit read(-1, value);
        }
        serialEventRun();
    }
}

void serialreader::stop()
{
    running = false;
}

void serialreader::start_record(QString filename)
{
    this->filename = filename;
    record = true;
}

void serialreader::stop_record()
{
    record = false;
}
