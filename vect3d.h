
#pragma once
template <typename T> class Vect3d{
    public:
        Vect3d(T x,T y,T z);
        T magnitude();
        bool operator<(const Vect3d &other);
        T x;
        T y;
        T z;
    private:
        
};

template <typename T> class Vect3d;
