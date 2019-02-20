#include "preprocessing.h"

Preprocessing::Preprocessing(){}


int Preprocessing::loadImages(QStringList fileNames){
    try{
        for(int i=0;i<fileNames.length();i++){
            this->Images=af::join(2,this->Images,af::loadImage(fileNames[i].toStdString().c_str(),false));
        }
        return 0;
    }
    catch(af::exception e){
        e.what();
        this->Images=NULL;
        return -1;
    }
}

void Preprocessing::setSegmentParams(int threshold, int windowSize){
    this->segmentation.SetBlockParams(windowSize);
    this->segmentation.setThreshold(threshold);
}

void Preprocessing::start(){
    this->Mask=this->segmentation.start(this->Images);
}

QPixmap Preprocessing::getPicture(af::array picture){
    QPixmap image;
    return image;
}
