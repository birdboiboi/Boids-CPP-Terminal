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
	    
           // std::sort(this->points.begin(),this->points.end());
            this->construct();
	}

        void updateData(T *xPoints,T *yPoints,T *zPoints){
            for (int i = 0; i < this->pointLength; i++){
                this->points.at(i) = Vect3d<T>(xPoints[i],yPoints[i],zPoints[i]);
            }
	    
            //std::sort(this->points.begin(),this->points.end());
	    this->construct();
        }
	void construct(int begin,int end,int axisToSort){

	    //TODO: switch structure to a property in vect3 so memory can be saved
	    //ex: Vect3d<int> vect[median].leftChild = vect[median/2] 
	    //start tree at length-1 = median
	    int median = (end-begin)/2;
	  
	    node<T> parent;
	    parent.idx = median;
	    parent.magnitude = this->points.at(parent.idx);
	//TODO: right now theres an infinte loop....sort this
	    parent.leftChild = construct(points.at(begin),points.at(median),
			    [](const Vect3d<T> lhs,const Vect3d<T>){
			    lhs.axis = axisToSort;
			    return lhs<rhs;
			    });
	   parent.rightChild = construct(points.at(median),points.at(end),
                            [](const Vect3d<T> lhs,const Vect3d<T>){
                            lhs.axis = axisToSort;
                            return lhs<rhs;
                            }); 
	    
	}
    private:
	void sort(){

	}
        
};












 
