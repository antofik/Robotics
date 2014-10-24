#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include "opencv/highgui.h"
#include "opencv/cv.h"
#include "QDebug"


enum EResult{
    Red,
    Blue,
    Nothing,
    Error,
    Empty
};

struct SColorDetectorResult{
    EResult PuckResult;
    EResult FieldResult;
};

struct SColorDetectorParams{
    unsigned char       m_uBlueTrash;
    unsigned char       m_uRedTrash;
    bool                m_bWithImages;
    unsigned int        m_nHorizontalNumberPoints;
    unsigned int        m_nVerticalNumberPoints;
    CvRect              m_PuckArea;
    std::vector<CvRect> m_FieldAreas;
    unsigned char       m_uBKoeff;
    unsigned char       m_uRedKoeff;
};

SColorDetectorParams defaultColorDetectorParams();

class CColorDetector
{
public:
    CColorDetector(const SColorDetectorParams& params = defaultColorDetectorParams());
    SColorDetectorResult detect(IplImage *src);
    void SetPuckArea(CvRect Area);
    void AddFieldArea(CvRect Area);

private:
    struct SCalculateResult{
        long long   uBlueSumm;
        long long   uRedSumm;
        long        uSumm;
    };

    unsigned char           m_uBluePercentPuck;
    unsigned char           m_uRedPercentPuck;
    unsigned char           m_uBluePercentField;
    unsigned char           m_uRedPercentField;
    SColorDetectorParams    m_params;

    SCalculateResult calculate(IplImage *src, CvRect& Rect);
};

void putTextWithShadow(IplImage *img, const char *str, CvPoint point, CvFont *font, CvScalar color = CV_RGB(255, 255, 128));

#endif // COLORDETECTOR_H
