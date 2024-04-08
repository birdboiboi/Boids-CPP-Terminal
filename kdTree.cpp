#include "kdTree.h"
#include <algorithm>



template<class T> KDtree<T>::KDtree(T *xPoints[],T *yPoints[],T* zPoints[]){
    int len = sizeof(xPoints)/sizeof(xPoints[0]);
    int magnitudes[len];
    for (int i = 0; i < len; i++){
        magnitudes[i] = Vect3d<int>(xPoints[i],yPoints[i],zPoints[i]);
    }
    std::sort(magnitudes[0],magnitudes[len],magnitudes);
    this->points = magnitudes;
}






