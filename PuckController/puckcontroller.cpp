#include "puckcontroller.h"


PuckController::PuckController(QObject *parent, bool myColorIsRed) : QObject(parent)
{
    _myColorIsRed = myColorIsRed;
}

int PuckController::getMyPucksCount()
{
    return _myPucksCount;
}

int PuckController::getEnemyPuckCount()
{
    return _enemyPuckCount;
}

void PuckController::start()
{
    _isActive = true;
    // TODO
}

void PuckController::stop()
{
    _isActive = false;
    // TODO
}
