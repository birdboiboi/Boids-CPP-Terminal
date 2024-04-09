
#pragma once
#include <cmath>
template <typename T> class Vect3d{
    public:
        Vect3d(T x,T y,T z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        ~Vect3d(){
            
        }
        T magnitude(){
            return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
        }
        bool operator<(Vect3d &other){
            return(pow(this->x,2)+pow(this->y,2)+pow(this->z,2)<pow(other.x,2)+pow(other.y,2)+pow(other.z,2));
        }
        bool operator!=(Vect3d &other){
            return (this->x != other.x && this->y != other.y && this->z != other.z);
        }
        Vect3d<T> operator-(Vect3d &other){
            return Vect3d<T>(this->x - other.x , this->y - other.y, this->z - other.z);
        }
        T x;
        T y;
        T z;
    private:
        
};

