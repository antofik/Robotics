#ifndef CPUCKSORTER_H
#define CPUCKSORTER_H

#include <QThread>
#include "colordetector.h"
#include "PuckMover/PuckMover.h"
#include "Seqencer/ASDSeqencer.h"

class CPuckSorter : public QThread
{
public:
    CPuckSorter(CColorDetector* detector, PuckMover* mover, ASDFrameSequencer* seqencer);
    ~CPuckSorter();
    void run();
private:
    CColorDetector*     m_pColorDetector;
    PuckMover*          m_puckMover;
    ASDFrameSequencer*  m_sequencer;
};

#endif // CPUCKSORTER_H
