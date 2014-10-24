#include "seqencer.h"

//-------------------- ASDFrameSequencer -----------------------//

ASDFrameSequencer::~ASDFrameSequencer()
{
    close();
};

IplImage *ASDFrameSequencer::getNextImage()
{
    return NULL;
};

void ASDFrameSequencer::close()
{

};

bool ASDFrameSequencer::isOpen()
{
    return false;
};

void ASDFrameSequencer::getFrameCaption(char* /*caption*/) {
    return;
};

IplImage* ASDCVFrameSequencer::getNextImage()
{
    IplImage *image;

    image = cvQueryFrame(capture);

    if (image != NULL)
    {
        return cvCloneImage(image);
    }
    else
    {
        return NULL;
    }
};

void ASDCVFrameSequencer::close()
{
    if (capture != NULL)
    {
        cvReleaseCapture(&capture);
    }
};

bool ASDCVFrameSequencer::isOpen()
{
    return (capture != NULL);
};


//-------------------- ASDFrameSequencerWebCam -----------------------//

bool ASDFrameSequencerWebCam::open(int cameraIndex)
{
    close();

    capture = cvCaptureFromCAM(cameraIndex);

    if (!capture)
    {
        return false;
    }
    else
    {
        if(!cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320))
            return false;
        if(!cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240))
            return false;
        return true;
    }
};


//-------------------- ASDFrameSequencerVideoFile -----------------------//

bool ASDFrameSequencerVideoFile::open(const char *fileName)
{
    close();

    capture = cvCaptureFromFile(fileName);
    if (!capture)
    {
        return false;
    }
    else
    {
        return true;
    }
};


//-------------------- ASDFrameSequencerImageFile -----------------------//

void ASDFrameSequencerImageFile::open(const char *fileNameMask, int startIndex, int endIndex)
{
    nCurrentIndex = startIndex-1;
    nStartIndex = startIndex;
    nEndIndex = endIndex;

    std::sprintf(sFileNameMask, "%s", fileNameMask);
};

void ASDFrameSequencerImageFile::getFrameCaption(char *caption) {
    std::sprintf(caption, sFileNameMask, nCurrentIndex);
};

IplImage* ASDFrameSequencerImageFile::getNextImage()
{
    char fileName[2048];

    nCurrentIndex++;

    if (nCurrentIndex > nEndIndex)
        return NULL;

    std::sprintf(fileName, sFileNameMask, nCurrentIndex);

    IplImage* img = cvLoadImage(fileName);

    return img;
};

void ASDFrameSequencerImageFile::close()
{
    nCurrentIndex = nEndIndex+1;
};

bool ASDFrameSequencerImageFile::isOpen()
{
    return (nCurrentIndex <= nEndIndex);
};
