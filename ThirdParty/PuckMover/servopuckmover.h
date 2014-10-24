#ifndef SERVOPUCKMOVER_H
#define SERVOPUCKMOVER_H

#include "maestro-wrapper/maestro.h"
#include "smc-wrapper/smc.h"
#include "PuckMover.h"

struct SServoPuckMoverParams
{
    int ServoController_sorter_channel;
    int ServoController_sorter_open;
    int ServoController_sorter_red;
    int ServoController_sorter_blue;
    Maestro *pMaestro;
};

class ServoPuckMover : public PuckMover
{
public:
    ServoPuckMover(const SServoPuckMoverParams& params);
    ~ServoPuckMover();
    virtual void toLeft();
    virtual void toRight();
    virtual void toOpen();

private:    //ServoController
    SServoPuckMoverParams m_Params;
    Maestro               *m_pMaestro;
    Servo                 *m_pSorterServo;
};

#endif // SERVOPUCKMOVER_H
