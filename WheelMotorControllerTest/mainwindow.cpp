#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->cmdStart, SIGNAL(clicked()), SLOT(start()));
    connect(ui->cmdStop, SIGNAL(clicked()), SLOT(stop()));

    this->controller = new WheelMotorController();
    ui->statusBar->showMessage("ready");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    ui->statusBar->showMessage("started");
}

void MainWindow::stop()
{
    ui->statusBar->showMessage("stopped");
}
