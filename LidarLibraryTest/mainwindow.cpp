#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
#ifdef ARDUINO
    lidar = new Lidar();
#endif

    ui->setupUi(this);
    recording = false;
    running = false;
    connect(ui->cmdStart, SIGNAL(clicked()), SLOT(start_click()));
    connect(ui->cmdRecord, SIGNAL(clicked()), SLOT(record_click()));
}

MainWindow::~MainWindow()
{
    delete ui;    
}

void MainWindow::start_click()
{
    if (!running) {
        ui->cmdStart->setText("Stop");
        #ifdef ARDUINO
            lidar->start_from_serial();
        #endif
        ui->statusBar->showMessage("Started reading from serial port");
    } else {
        ui->cmdStart->setText("Start");
        #ifdef ARDUINO
            lidar->stop();
        #endif
        ui->statusBar->showMessage("Stopped");
        if (recording) {
            recording = false;
            stop_recording();
        }
    }    
    running ^= true;
    ui->cmdRecord->setEnabled(running);
}

void MainWindow::record_click()
{
    if (!recording) {
        start_recording();
    } else {
        stop_recording();
    }
    recording ^= true;
}

void MainWindow::start_recording()
{
    ui->cmdRecord->setText("Stop recording");
    QString filename = QFileDialog::getSaveFileName(this, "Record to file...", "", "Files (*.bin)");

#ifdef ARDUINO
    lidar->start_record(filename);
#endif
}

void MainWindow::stop_recording()
{
    ui->cmdRecord->setText("Start recording");
#ifdef ARDUINO
    lidar->stop_record();
#endif
}
