#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wheelmotorcontroller.h"
#include "smc.h"

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
    void start();
    void stop();

private:
    Ui::MainWindow *ui;
    WheelMotorController *controller;
    SMC* smc;

};

#endif // MAINWINDOW_H
