#ifndef FICTIONSEQENCER_H
#define FICTIONSEQENCER_H

#include "ASDSeqencer.h"

class FictionSeqencer : public ASDFrameSequencer
{
    public:
        FictionSeqencer()
        {
            m_image = cvCreateImage(cvSize(640,480), IPL_DEPTH_8U, 1);
        }
        ~FictionSeqencer()
        {
            cvReleaseImage(&m_image);
        }
        virtual IplImage *getNextImage()
        {
            return m_image;
        }
        virtual void close() {}
        virtual bool isOpen()
        {
            return true;
        }
    private:
        IplImage *m_image;
};

#endif // FICTIONSEQENCER_H
