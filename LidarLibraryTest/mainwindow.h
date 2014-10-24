#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lidar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void start_click();
    void record_click();

private:
    Ui::MainWindow *ui;
    bool running;
    bool recording;
    Lidar* lidar;
    void start_recording();
    void stop_recording();

};

#endif // MAINWINDOW_H
