#include "kdTree.h"
#include <algorithm>
#include <math.h>

template <typename T> simple::Vect3d<T>::Vect3d(const &T x,const &T y,const &T z){
    this->x = x;
    this->y = y;
    this->z = z;
}

template<typename T> T Vect3d<T> simple::Vect3d<T>::magnitude(){
    return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}

template <typename T> bool simple::Vect3d<T>::operator<(const Vect3d &other){
    return(pow(this->x,2)+pow(this->y,2)+pow(this->z,2)<pow(other->x,2)+pow(other->y,2)+pow(other->z,2));
}


KDtree::KDtree(int listLength){

}

void KDtree::prepareData(int* xPoints,int* yPoints, int* zPoints){
    int len = sizeof(xPoints)/sizeof(xPoints[0]);
    int magnitudes[len];
    for (int i = 0; i < len; i){
        magnitudes[i] = simple::Vect3d(xPoints[i],yPoints[i],zPoints[i]);
    }
    std::sort(magnitudes[0],magnitudes[len],magnitudes);
    this->points = magnitudes;
}



