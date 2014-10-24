#ifndef SEQENSER_H
#define SEQENSER_H

#include "ASDSeqencer.h"
#include "opencv2/highgui/highgui.hpp"
#include <cstdio>

class ASDCVFrameSequencer : public ASDFrameSequencer
{
protected:
    CvCapture *capture;

public:
    virtual IplImage *getNextImage();
    virtual void close();
    virtual bool isOpen();
};


class ASDFrameSequencerWebCam : public ASDCVFrameSequencer
{
public:
    virtual bool open(int cameraIndex);
};

class ASDFrameSequencerVideoFile : public ASDCVFrameSequencer
{
public:
    virtual bool open(const char *fileName);
};

class ASDFrameSequencerImageFile : public ASDFrameSequencer {
private:
    char sFileNameMask[2048];
    int nCurrentIndex, nStartIndex, nEndIndex;

public:
    virtual void open(const char *fileNameMask, int startIndex, int endIndex);
    virtual void getFrameCaption(char *caption);
    virtual IplImage *getNextImage();
    virtual void close();
    virtual bool isOpen();
};

#endif // SEQENSER_H
