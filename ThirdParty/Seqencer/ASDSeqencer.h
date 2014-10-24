#ifndef ASDSEQENSER_H
#define ASDSEQENSER_H

#include "opencv2/highgui/highgui.hpp"

class ASDFrameSequencer
{
public:
    virtual ~ASDFrameSequencer();
    virtual IplImage *getNextImage();
    virtual void close();
    virtual bool isOpen();
    virtual void getFrameCaption(char *caption);
};

#endif // ASDSEQENSER_H
