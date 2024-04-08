#pragma once
#include "vect3d.h"


template <typename T> class KDtree{
    public:
        KDtree(T *xPoints[],T *yPoints[],T* zPoints[]);
        Vect3d<T> *points;

    private:
};



 