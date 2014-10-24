#include "SorterFabric.h"

#include "Seqencer/seqencer.h"

CPuckSorter* sorterFabric(const SColorDetectorParams& CDParams, const SServoPuckMoverParams& moverParams, int ColorDetector_device)
{
        ASDFrameSequencer* m_pSeqencer = new ASDFrameSequencerWebCam();
        if(!(dynamic_cast<ASDFrameSequencerWebCam*>(m_pSeqencer))->open(ColorDetector_device))
            qDebug() << "Can't change camera resolution";
        if (! m_pSeqencer->isOpen())
        {
            std::cout << std::endl << "Error: Cannot initialize the default Webcam" << std::endl << std::endl;
        }

        PuckMover* m_pMover = new ServoPuckMover(moverParams);

        CColorDetector* m_pDetector = new CColorDetector(CDParams);
        CPuckSorter* pSorter = new CPuckSorter(m_pDetector, m_pMover, m_pSeqencer);

        return pSorter;
};

