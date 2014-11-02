#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/imgproc/imgproc_c.h"
#include <Qt>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_camera = cvCreateCameraCapture(0);
    if ((void*)m_camera == 0) {
        qDebug() << "Cannot create camera";
        qApp->quit();
        return;
    }
    cvSetCaptureProperty(m_camera, CV_CAP_PROP_FRAME_WIDTH, 320);
    cvSetCaptureProperty(m_camera, CV_CAP_PROP_FRAME_HEIGHT, 240);
    //IplImage *image = cvQueryFrame(m_camera);
    //cvSaveImage("~/camera_image.png", image);
    startTimer(1000/25);
}

void MainWindow::timerEvent(QTimerEvent *)
{
    IplImage *image = cvQueryFrame(m_camera);
    analyze(image);
    cvShowImage("camera", image);
}

// Анализирует картинку на предмет наличия
// шайбы или базы
void MainWindow::analyze(IplImage *image)
{
    MainWindow::Color leftUpperCorner = getAreaColor(image, 0.1, 0.1, 0.2, 0.2);
    MainWindow::Color rightUpperCorner = getAreaColor(image, 0.7, 0.1, 0.2, 0.2);
    MainWindow::Color center = getAreaColor(image, 0.4, 0.4, 0.2, 0.2);
    if (center==MainWindow::Other)
        setState(MainWindow::None);
    // если цвет одинаков в центре и по краям, то мы находимся на базе
    else if (center == leftUpperCorner && center == rightUpperCorner)
        setState(center==MainWindow::Red ? MainWindow::RedBase : MainWindow::BlueBase);
    else
        setState(center==MainWindow::Red ? MainWindow::RedPuck : MainWindow::BluePuck);
}

// Возвращает цвет квадрата
// Координаты начала и размеры передаются в процентах (0..1) от абсолютной величины
MainWindow::Color MainWindow::getAreaColor(IplImage *image, float x, float y, float width, float height)
{
    int x1 = x * image->width;
    int y1 = y * image->height;
    int x2 = x1 + width*image->width;
    int y2 = y1 + height*image->height;
    ulong sumR = 0, sumB = 0, sumG = 0;
    uint8_t* data = (uint8_t*) image->imageData;
    int channels = image->nChannels * image->depth/8;

    // считаем, сколько каждой компоненты цвета в заданном квадрате
    for(int i=x1;i<=x2;i++)
       for(int j=y1;j<=y2;j++)
       {
           sumB += data[j*image->widthStep + i*channels + 0];
           sumG += data[j*image->widthStep + i*channels + 1];
           sumR += data[j*image->widthStep + i*channels + 2];
       }


    // находим удельное значение цвета на точку
    int total = (x2 - x1) * (y2 - y1);
    sumB /= total;
    sumG /= total;
    sumR /= total;
    qDebug() << sumB << sumG << sumR << total;

    // уровень шума - значение компоненты должно быть больше
    // этой величины для её детектирования
    const int lowLevel = 50;

    // если все компоненты очень близки по значению, считаем это
    // серым с неразличимым оттенком
    if (abs(sumB-sumG) < lowLevel &&
        abs(sumG-sumR) < lowLevel &&
        abs(sumR-sumB) < lowLevel)
        return MainWindow::Other;


    // если больше всего мы нашли синего...
    if (sumB > sumG && sumB > sumR) {
        if (sumB > lowLevel)
            return MainWindow::Blue;
    }
    // или красного...
    else if (sumR > sumG) {
        if (sumR > lowLevel)
            return MainWindow::Red;
    }
    return MainWindow::Other;
}

void MainWindow::setState(MainWindow::State state)
{
    if (state == this->_currentState) return;
    this->_currentState = state;
    emit stateChanged(this->_currentState);

    switch(this->_currentState) {
    case MainWindow::None:
        ui->txtState->setText("ждём...");
        break;
    case MainWindow::RedBase:
        ui->txtState->setText("красная база");
        break;
    case MainWindow::BlueBase:
        ui->txtState->setText("синяя база");
        break;
    case MainWindow::RedPuck:
        ui->txtState->setText("красная шайба");
        break;
    case MainWindow::BluePuck:
        ui->txtState->setText("синяя шайба");
        break;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
