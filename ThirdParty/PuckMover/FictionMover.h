#ifndef FICTIONMOVER_H
#define FICTIONMOVER_H

#include "PuckMover.h"

class FictionMover : public PuckMover
{
public:
    virtual void toLeft(){ }
    virtual void toRight(){ }
    virtual bool finished()
    {
        return true;
    }
};

#endif // FICTIONMOVER_H
