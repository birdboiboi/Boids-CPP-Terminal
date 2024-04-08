#include "vect3d.h"
#include <math.h>

template <typename T> Vect3d<T>::Vect3d(T x,T y,T z){
    this->x = x;
    this->y = y;
    this->z = z;
}

template<typename T> T Vect3d<T>::magnitude(){
    return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}

template <typename T> bool Vect3d<T>::operator<(const Vect3d &other){
    return(pow(this->x,2)+pow(this->y,2)+pow(this->z,2)<pow(other->x,2)+pow(other->y,2)+pow(other->z,2));
}
