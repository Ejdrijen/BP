#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "preprocessing_global.h"
#include <QStringList>
#include <QPixmap>
#include <arrayfire.h>
#include "segmentation.h"

class PREPROCESSINGSHARED_EXPORT Preprocessing
{
private:
    //results
    af::array Images;
    af::array Mask;


    //modules
    Segmentation segmentation;

public:
    QPixmap getPicture(af::array picture);//convert single image from af::array to QPixmap
    Preprocessing();
    void setSegmentParams(int threshold,int windowSize); //set parameters of segmentation proccess
    int loadImages(QStringList fileNames);// return 0 on success, -1 on failure
    void start(); // starts the proccess
};

#endif // PREPROCESSING_H
