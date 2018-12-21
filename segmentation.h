#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <arrayfire.h>
#include <QStringList>


class Segmentation
{

    int blockSize;
    int Threshold;
    af::array mask;
    af::array picMask(af::array picture);//called from start for each picture
public:
    Segmentation();
    Segmentation(int blockSize, int Threshold);
    void SetBlockParams(int blockSize);
    void setThreshold(int Threshold);
    af::array start(af::array pictures);//starts the proccess
};

#endif // SEGMENTATION_H
