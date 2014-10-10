#include "puckcontroller.h"


PuckController::PuckController(QObject *parent, bool myColorIsRed) : QObject(parent)
{
    this->myColorIsRed = myColorIsRed;
}

int PuckController::getMyPucksCount()
{
    return this->myPucksCount;
}

int PuckController::getEnemyPuckCount()
{
    return this->enemyPuckCount;
}
