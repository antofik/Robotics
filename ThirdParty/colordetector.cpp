#include "colordetector.h"

SColorDetectorParams defaultColorDetectorParams()
{
    SColorDetectorParams params;
    params.m_uBlueTrash = 25;
    params.m_uRedTrash = 35;
    params.m_bWithImages = 1;
    params.m_nHorizontalNumberPoints = 10;
    params.m_nVerticalNumberPoints = 10;
    params.m_uBKoeff = 180;
    params.m_uRedKoeff = 130;
    params.m_PuckArea = cvRect(270,100,100,100);
    params.m_FieldAreas.push_back(cvRect(10,70,50,50));
    params.m_FieldAreas.push_back(cvRect(580,80,50,50));
    return params;
}

CColorDetector::CColorDetector(const SColorDetectorParams& params)
    : m_params(params)
{
    m_uBluePercentPuck = 0;
    m_uRedPercentPuck = 0;
    m_uBluePercentField = 0;
    m_uRedPercentField = 0;
//    cvNamedWindow("red", CV_WINDOW_AUTOSIZE);
//    cvNamedWindow("blue", CV_WINDOW_AUTOSIZE);
}

void putTextWithShadow(IplImage *img, const char *str, CvPoint point, CvFont *font, CvScalar color)
{
    cvPutText(img, str, cvPoint(point.x-1,point.y-1), font, CV_RGB(0, 0, 0));
    cvPutText(img, str, point, font, color);
}


SColorDetectorResult CColorDetector::detect(IplImage *src){
    SColorDetectorResult Result;
    EResult FieldDetectResult, PuckDetectResult;

    char string[50];
    CvFont base_font, small_font;
    cvInitFont( &base_font, CV_FONT_VECTOR0, 0.5, 0.5);
    cvInitFont( &small_font, CV_FONT_VECTOR0, 0.3, 0.3);

//----   Field detection
    FieldDetectResult = Empty;
    for(int i=0; i < m_params.m_FieldAreas.size(); i++){
        SCalculateResult FieldResult = calculate(src, m_params.m_FieldAreas[i]);
        m_uBluePercentField = FieldResult.uBlueSumm/FieldResult.uSumm;
        m_uRedPercentField  = FieldResult.uRedSumm/FieldResult.uSumm;
        if((m_uBluePercentField > m_params.m_uBlueTrash) && (m_uRedPercentField <= 0)){
            if(FieldDetectResult == Nothing)
                FieldDetectResult = Nothing;
            else if(FieldDetectResult == Error)
                FieldDetectResult = Error;
            else if(FieldDetectResult == Red)
                FieldDetectResult = Error;
            else
                FieldDetectResult = Blue;
        }
        else if((m_uRedPercentField > m_params.m_uRedTrash) && (m_uBluePercentField <= 0)){
            if(FieldDetectResult == Nothing)
                FieldDetectResult = Nothing;
            else if(FieldDetectResult == Error)
                FieldDetectResult = Error;
            else if(FieldDetectResult == Blue)
                FieldDetectResult = Error;
            else
                FieldDetectResult = Red;
        }
        else{
           if(FieldDetectResult == Error)
                FieldDetectResult = Error;
           else
                FieldDetectResult = Nothing;
        }


        if(m_params.m_bWithImages){

                if((m_uBluePercentField > m_params.m_uBlueTrash) && (m_uRedPercentField <= 0)){
                    sprintf(string, "blue");
                }
                else if((m_uRedPercentField > m_params.m_uRedTrash) && (m_uBluePercentField <= 0)){
                   sprintf(string, "red");
                }
                else
                   sprintf(string, "nothing");

                    putTextWithShadow(src, string,
                                      cvPoint(m_params.m_FieldAreas[i].x+m_params.m_FieldAreas[i].width/2-15, m_params.m_FieldAreas[i].y+m_params.m_FieldAreas[i].height/2),
                                      &base_font);

            }
    }

//----   Puck detection
    SCalculateResult PuckResult = calculate(src, m_params.m_PuckArea);
    m_uBluePercentPuck = PuckResult.uBlueSumm/PuckResult.uSumm;
    m_uRedPercentPuck  = PuckResult.uRedSumm/PuckResult.uSumm;

    if((m_uBluePercentPuck > m_params.m_uBlueTrash) && (m_uRedPercentPuck <= 0)){
        if(FieldDetectResult == Blue)
            PuckDetectResult = Nothing;
        else
            PuckDetectResult = Blue;
    }
    else if((m_uRedPercentPuck > m_params.m_uRedTrash) && (m_uBluePercentPuck <= 0)){
        if(FieldDetectResult == Red)
            PuckDetectResult = Nothing;
        else
            PuckDetectResult = Red;
    }
    else{
       PuckDetectResult = Nothing;
    }

    Result.FieldResult = FieldDetectResult;
    Result.PuckResult = PuckDetectResult;

    if(m_params.m_bWithImages){
        if(Result.PuckResult == Blue){
            sprintf(string, "blue");
        }
        else if(Result.PuckResult == Red){
           sprintf(string, "red");
        }
        else
           sprintf(string, "nothing");

        CvRect puckArea = m_params.m_PuckArea;
        putTextWithShadow(src, string,
                          cvPoint(puckArea.x+puckArea.width/2-15, puckArea.y+puckArea.height/2),
                          &base_font);
 //        putTextWithShadow(src, string, cvPoint(10, src->height-55), &base_font);

         std::sprintf(string, "%d x %d",  src->width, src->height);
         putTextWithShadow(src, string, cvPoint(10, src->height-35), &small_font);

         sprintf(string, "blue: %d  red %d ", (int)m_uBluePercentPuck, (int)m_uRedPercentPuck);
         putTextWithShadow(src, string, cvPoint(10, src->height-15), &base_font);

         cvRectangle( src, cvPoint(puckArea.x,puckArea.y),
                           cvPoint(puckArea.x+puckArea.width,puckArea.y+puckArea.height),
                           cvScalar(0xff,0xff,0xff));
         cvPutText( src, "Puck", cvPoint(puckArea.x+3,puckArea.y + 10),
                                 &small_font,
                                 cvScalar(0xff,0xff,0xff));

         for(int i=0; i < m_params.m_FieldAreas.size(); i++){
             CvRect fieldArea = m_params.m_FieldAreas[i];
             cvRectangle( src, cvPoint(fieldArea.x,fieldArea.y),
                               cvPoint(fieldArea.x+fieldArea.width,fieldArea.y+fieldArea.height),
                               cvScalar(0xff,0xff,0xff));
             cvPutText( src, "Field", cvPoint(fieldArea.x+3,fieldArea.y + 10),
                                      &small_font,
                                      cvScalar(0xff,0xff,0xff));
         }
     }



    return Result;
}

CColorDetector::SCalculateResult CColorDetector::calculate(IplImage *src, CvRect& Rect){

//    IplImage *red, *blue;
//    red = cvCreateImage(cvSize(src->width, src->height), 8, 1);
//    blue = cvCreateImage(cvSize(src->width, src->height), 8, 1);
    long long uBSumm = 0;
    long long uRSumm = 0;
    unsigned long long uCntr = 0;
    unsigned int nHStep = Rect.width/m_params.m_nHorizontalNumberPoints;
    unsigned int nVStep = Rect.height/m_params.m_nVerticalNumberPoints;
    uint8_t* pSrc = (uint8_t*)src->imageData;
//    uint8_t* pRed = (uint8_t*)red->imageData;
//    uint8_t* pBlue = (uint8_t*)blue->imageData;
    int iSrcChnls = src->nChannels * src->depth/8;
    for(int i = Rect.y; i < Rect.y + Rect.height; i+=nVStep)  {
        for(int j = Rect.x; j < Rect.x + Rect.width; j+=nHStep)
        {
            int uR, uG, uB;
            uB = pSrc[i*src->widthStep + j*iSrcChnls + 0]; // B
            uG = pSrc[i*src->widthStep + j*iSrcChnls + 1]; // G
            uR = pSrc[i*src->widthStep + j*iSrcChnls + 2]; // R


            uR = uR * 2 * m_params.m_uBKoeff / (m_params.m_uRedKoeff + m_params.m_uBKoeff) ;
            uB = uB * 2 * m_params.m_uRedKoeff / (m_params.m_uRedKoeff + m_params.m_uBKoeff);

            int uY = (uR+uB)/2;

            int iRDetect = (uR - uY);
            if(iRDetect < 0)
                iRDetect = 0;

            int iBDetect = (uB - uY);
            if(iBDetect < 0)
                iBDetect = 0;

            uBSumm += iBDetect;
            uRSumm += iRDetect;
//            pRed[i*src->width + j] = iRDetect;
//            pBlue[i*src->width + j] = iBDetect;

            uCntr++;
        }
    }
    SCalculateResult result;
    result.uBlueSumm = uBSumm;
    result.uRedSumm = uRSumm;
    result.uSumm = uCntr;

//    cvShowImage ("red", red);
//    cvReleaseImage(&red);
//    cvShowImage ("blue", blue);
//    cvReleaseImage(&blue);

    return result;
}

void CColorDetector::SetPuckArea(CvRect Area){

}

void CColorDetector::AddFieldArea(CvRect Area){

}
