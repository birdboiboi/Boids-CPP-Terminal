#pragma once


namespace simple{
    template <typename T> class Vect3d{
        public:
            Vect3d(const &T x,const &T y, const &T z);
            T magnitude();
            bool operator<(const &Vect3d other);
        private:
            T x;
            T y;
            T z;
    };
}

template <typename T> class KDtree{
    public:
        KDtree(int listLength);
        void prepareData(T* xPoints,T* yPoints,T* zPoints);
        simple::Vect3d<T> *points;

    private:
        

};
