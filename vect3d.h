
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
        Vect3d<T> operator-(Vect3d &other){
            return Vect3d<T>(this->x - other.x , this->y - other.y, this->z - other.z);
	}
        bool operator!=(Vect3d &other){
            return (this->x != other.x && this->y != other.y && this->z != other.z);
        }
        bool  operator<(Vect3d &other){
	    switch(this->axis){
	    	case 1:
            		return(this->x < other.x);
            case 2:
                        return(this->y<other.y);
            case 3:
                return(this->z<other.z);
            default:
                return(pow(this->x,2)+pow(this->y,2)+pow(this->z,2)<pow(other.x,2)+pow(other.y,2)+pow(other.z,2));
	    }
	}
    
	int axis = 0;
    T x;
    T y;
    T z;
    //Node<T> node;
    
    Vect3d<T>* leftChild;
    Vect3d<T>* rightChild;
    private:
        
};
