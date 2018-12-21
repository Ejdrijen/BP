#include "segmentation.h"
using namespace af;

Segmentation::Segmentation(){

}

Segmentation::Segmentation(int blockSize=10,int Threshold=130):blockSize(blockSize), Threshold(Threshold)
{}


void Segmentation::SetBlockParams(int blockSize)
{
    this->blockSize=blockSize;
}

void Segmentation::setThreshold(int Threshold){
    this->Threshold=Threshold;
}
array Segmentation::picMask(array picture){
    array variance;
    array unwrapped=unwrap(picture,this->blockSize,this->blockSize,this->blockSize,this->blockSize,0,0); // unwraps picture
    variance=var(unwrapped,false,0); // variances for each slice

    variance=variance-this->Threshold; // difference between variance of each slice and threshold

    variance=1+(-sign(variance)); //sign(variances) - swhow which values are negative (1=negative value,0=positive value)
                                    //-sign(variance) - negation of above operation(get -1 on places of negative values)
                                    //1+(-sign(variance)) - get zeros on columns where variance < threshold | value 1 on columns where variance >= threshold
    unwrapped=tile(variance,unwrapped.dims(0),1);//clone the values so the matrix have the same size as original matrix
    wrap(unwrapped,picture.dims(0),picture.dims(1),this->blockSize,this->blockSize,this->blockSize,this->blockSize,0,0); //wrap picture back

    return wrap(unwrapped,picture.dims(0),picture.dims(1),this->blockSize,this->blockSize,this->blockSize,this->blockSize,0,0); //wrap picture back

}

array Segmentation::start(array pictures){

    if(pictures.isempty()|| this->Threshold==0 || this->blockSize==0) return NULL;
    gfor(seq i,pictures.dims(2)-1){
        try{
            this->mask =join(2,this->mask,this->picMask(pictures(span,span,i)));
        }
        catch(af::exception e){
            e.what();
            return NULL;
        }
    }

    return this->mask;
}
