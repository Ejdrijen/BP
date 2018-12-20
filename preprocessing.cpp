#include "preprocessing.h"


Preprocessing::Preprocessing()
{
}


void Preprocessing::loadImages(QStringList fileNames){
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
