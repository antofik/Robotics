#include "servopuckmover.h"
#include <ctime>

ServoPuckMover::ServoPuckMover(const SServoPuckMoverParams& params)
    : m_Params(params)
    , m_pMaestro(params.pMaestro)
{
    m_pSorterServo = new Servo(m_Params.ServoController_sorter_channel, 4000, 8000);
    //m_pMaestro->setPosition(m_pSorterServo, m_Params.ServoController_sorter_open);
}

ServoPuckMover::~ServoPuckMover()
{
    delete m_pSorterServo;
}

void ServoPuckMover::toLeft()
{
    int sorter_position;
    sorter_position = m_Params.ServoController_sorter_red;
    m_pMaestro->setPosition( m_pSorterServo, sorter_position);
}

void ServoPuckMover::toRight()
{
    int sorter_position;
    sorter_position = m_Params.ServoController_sorter_blue;
    m_pMaestro->setPosition( m_pSorterServo, sorter_position);
}


void ServoPuckMover::toOpen()
{
    int sorter_position;
    sorter_position = m_Params.ServoController_sorter_open;
    m_pMaestro->setPosition( m_pSorterServo, sorter_position);
}
