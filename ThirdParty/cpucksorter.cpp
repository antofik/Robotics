#include "cpucksorter.h"
#include "QTime"
#include <ctime>

CPuckSorter::CPuckSorter(CColorDetector* detector, PuckMover* mover, ASDFrameSequencer* seqencer)
    : m_pColorDetector(detector)
    , m_puckMover(mover)
    , m_sequencer(seqencer)
{
    m_pColorDetector = new CColorDetector();
}

CPuckSorter::~CPuckSorter()
{
    delete m_pColorDetector;
}

void CPuckSorter::run(){
    while(1)
    {
        IplImage *img = m_sequencer->getNextImage();
        if(img == 0)
            continue;

        QTime Time;
        Time.restart();
        SColorDetectorResult ColorDetectorResult = m_pColorDetector->detect(img);
        int clock1 = Time.elapsed();

        if(ColorDetectorResult.PuckResult != Nothing)
        {
            if(ColorDetectorResult.PuckResult == Red)
            {
                m_puckMover->toRight();                
            }
            else if(ColorDetectorResult.PuckResult == Blue)
            {
                m_puckMover->toLeft();
            };
            QThread::msleep(150);
            m_puckMover->toOpen();
        }
        //cvShowImage ("Color Detect", img);
        cvReleaseImage(&img);
    }
}
