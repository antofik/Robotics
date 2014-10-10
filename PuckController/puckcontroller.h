#ifndef PUCKCONTROLLER_H
#define PUCKCONTROLLER_H

#include <QObject>

class PuckController : public QObject
{
    Q_OBJECT

public:
    explicit PuckController(QObject *parent = 0, bool myColorIsRed = true);


signals:
    /**
     * Triggers when my puck collected
     */
    void MyPuckCollected();

    /**
     * Triggers when new enemy puck collected
     */
    void EnemyPuckCollected();


    /**
     * Count of already collected my pucks
     */
    int getMyPucksCount();

    /**
     * Count of already collected enemy pucks
     */
    int getEnemyPuckCount();

private:
    bool myColorIsRed;
    int myPucksCount;
    int enemyPuckCount;

};

#endif // PUCKCONTROLLER_H
