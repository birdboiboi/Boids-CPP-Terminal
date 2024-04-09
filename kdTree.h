#pragma once
#include "vect3d.h"
#include <algorithm>
#include <vector>

template <typename T> class KDtree{
    public:
        std::vector<Vect3d<T>> points;
        int pointLength;

        KDtree(T *xPoints,T *yPoints,T *zPoints,const int size){
            this->pointLength = size;//sizeof(xPoints)/sizeof(xPoints[0]);
            for (int i = 0; i < this->pointLength; i++){
                this->points.push_back( Vect3d<T>(xPoints[i],yPoints[i],zPoints[i]));
            }
            std::sort(this->points.begin(),this->points.end());
        }

        void updateData(T *xPoints,T *yPoints,T *zPoints){
            for (int i = 0; i < this->pointLength; i++){
                this->points.at(i) = Vect3d<T>(xPoints[i],yPoints[i],zPoints[i]);
            }
            std::sort(this->points.begin(),this->points.end());
        }
    private:
        
};












 