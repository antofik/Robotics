#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv/cv.h"
#include "opencv/highgui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage m_image;

    enum Color {
        Other,
        Red,
        Blue
    };

    enum State {
        None,
        RedBase,
        BlueBase,
        RedPuck,
        BluePuck
    };

signals:
    void stateChanged(MainWindow::State state);

private:
    Ui::MainWindow *ui;
    CvCapture *m_camera;
    void timerEvent(QTimerEvent*);
    void analyze(IplImage* image);
    MainWindow::Color getAreaColor(IplImage *image, float x, float y, float width, float height);
    MainWindow::State _currentState;
    void setState(MainWindow::State state);
};

#endif // MAINWINDOW_H
