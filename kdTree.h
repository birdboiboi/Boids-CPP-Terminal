#pragma once
#include "vect3d.h"
#include <algorithm>
#include <vector>
template <typename T>struct node{
	T magnitude;
	int idx;
	node* leftChild;
	node* rightChild;	
};

template <typename T> class KDtree{
    public:
        std::vector<Vect3d<T>> points;
        int pointLength;
        KDtree(const int size){
            this->pointLength = size;//sizeof(xPoints)/sizeof(xPoints[0]);
            for (int i = 0; i < this->pointLength; i++){
                this->points.push_back( Vect3d<T>(0,0,0));
            }
        }
        KDtree(T *xPoints,T *yPoints,T *zPoints,const int size){
            this->pointLength = size;//sizeof(xPoints)/sizeof(xPoints[0]);
            for (int i = 0; i < this->pointLength; i++){
                this->points.push_back( Vect3d<T>(xPoints[i],yPoints[i],zPoints[i]));
            }
	    
            std::sort(this->points.begin(),this->points.end());
            this->construct();
	}

        void updateData(T *xPoints,T *yPoints,T *zPoints){
            for (int i = 0; i < this->pointLength; i++){
                this->points.at(i) = Vect3d<T>(xPoints[i],yPoints[i],zPoints[i]);
            }
	    
            std::sort(this->points.begin(),this->points.end());
	    this->construct();
        }
	void construct(Vect3d<T> next, int median){

	    //TODO: switch structure to a property in vect3 so memory can be saved
	    //ex: Vect3d<int> vect[median].leftChild = vect[median/2] 
	    //start tree at length-1 = median
	    node<T> parent;
	    parent.idx = (this->length-1)/2;
	    parent.magnitude = this->points.at(parent.idx);
	    parent.leftChild = 
	    
	}
    private:
	void sort(){

	}
        
};












 
