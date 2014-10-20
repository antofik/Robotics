#ifndef PUCKCONTROLLER_H
#define PUCKCONTROLLER_H

#include <QObject>

class PuckController : public QObject
{
    Q_OBJECT

public:
    explicit PuckController(QObject *parent = 0, bool myColorIsRed = true);

    /**
     * @brief Count of already collected my pucks
     */
    int getMyPucksCount();

    /**
     * @brief Count of already collected enemy pucks
     */
    int getEnemyPuckCount();

signals:

    /**
     * @brief Triggers when my puck collected
     */
    void MyPuckCollected();

    /**
     * @brief Triggers when new enemy puck collected
     */
    void EnemyPuckCollected();

public slots:

    /**
     * @brief Start module
     */
    void start();

    /**
     * @brief Stop module
     */
    void stop();

    /**
     * @brief Lift up the flap, releasing my pucks
     */
    void releaseMyPucks();

    /**
     * @brief List up the flap, releasing enemy pucks
     */
    void releaseEnemyPucks();

private:
    bool _isActive;
    bool _myColorIsRed;
    int _myPucksCount;
    int _enemyPuckCount;

};

#endif // PUCKCONTROLLER_H
