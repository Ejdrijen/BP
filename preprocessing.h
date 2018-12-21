#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "preprocessing_global.h"
#include <QStringList>
#include <arrayfire.h>
#include "segmentation.h"

class PREPROCESSINGSHARED_EXPORT Preprocessing
{
private:

    af::array Images;
    af::array Mask;
    Segmentation segmentation;

public:
    Preprocessing();
    void setSegmentParams(int threshold,int windowSize); //set parameters of segmentation proccess
    int loadImages(QStringList fileNames);// return 0 on success, -1 on failure
    void start(); // starts the proccess
};

#endif // PREPROCESSING_H
