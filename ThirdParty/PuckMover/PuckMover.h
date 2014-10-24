#ifndef PUCK_MOVER_H
#define PUCK_MOVER_H

class PuckMover
{
public:
    virtual void toLeft() = 0;
    virtual void toRight() = 0;
    virtual void toOpen() = 0;
};

#endif // PUCK_MOVER_H
