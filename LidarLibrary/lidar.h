#ifndef LIDARREADER_H
#define LIDARREADER_H

#include <QObject>
#include <Qt>
#include <QtCore>
#include <QTimer>
#include <QThread>
#include <iostream>
#include <fstream>
#include "smc.h"
#include "serialreader.h"
#include "datafilereader.h"

class Lidar : public QObject
{
    Q_OBJECT
public:
    explicit Lidar(QObject *parent = 0);
    int distance[360];
    void start_record(QString filename);
    void stop_record();

signals:
    void data(int,int,int,int,int,int);

public slots:
    void start_from_serial();
    void start_from_file();
    void stop();

private slots:
    void read(int,int);

private:
    QTimer timer;
    bool from_file;
    FILE* file;
    int checksum(int data[]);
    bool started;
    bool serial;
    serialreader* serial_reader;
    datafilereader* data_file_reader;
    SMC *LidarMotor;
};

#endif // LIDARREADER_H
