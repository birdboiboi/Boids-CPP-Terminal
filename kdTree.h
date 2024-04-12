#pragma once
#include "vect3d.h"
#include <algorithm>
#include <vector>
#include <cmath>


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
            
            this->construct(0,this->pointLength-1,1);
	}

        void updateData(T *xPoints,T *yPoints,T *zPoints){
            for (int i = 0; i < this->pointLength; i++){
                this->points.at(i) = Vect3d<T>(xPoints[i],yPoints[i],zPoints[i]);
            }
	    
            //std::sort(this->points.begin(),this->points.end());

            this->construct(0,this->pointLength-1,1,);
        }
	void construct(int begin,int end,int axisToSort){

	    //TODO: switch structure to a property in vect3 so memory can be saved
	    //ex: Vect3d<int> vect[median].leftChild = vect[median/2] 
	    //start tree at length-1 = median
         
        int depth = trunc(log2((end-begin) +1));
        if(depth > 1){
            int median = (end-begin)/2;
            
            std::sort(this->points.at(begin),this->points.at(end),
                    [](const Vect3d<T> lhs,const Vect3d<T>){
                    lhs.axis = axisToSort;
                    return lhs<rhs;
                    });

            int medianLow = (median - begin)/2
            int medianHigh =(end-begin)/2

            this->points.at(median)->node.leftChild = this->points.at(medianLow);
            this->points.at(median)->node.rightChild = this->points.at(medianHigh);

            if(axisToSort == 1){
                axisToSort = 2;
            }else{
                axisToSort = 1;
            }

            this->construct(medianLow,median,axisToSort);
            this->construct(median,medianHigh,axisToSort);

        }else{
            return;
        }
	    
	    
	}
    private:
	void sort(){

	}
        
};












 
