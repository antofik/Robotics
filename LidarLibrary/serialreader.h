#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>

class serialreader : public QObject
{
    Q_OBJECT
public:
    explicit serialreader(QObject *parent = 0);    
    void start_record(QString filename);
    void stop_record();

signals:
    void read(int index, int value);

public slots:
    void start();
    void stop();

private:
    bool running;
    QString filename;
    bool record;

};

#endif // SERIALREADER_H
