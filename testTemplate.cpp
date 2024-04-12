#include "kdTree.h"
#include <iostream>
#include "vect3d.h"

//template <class T> KDtree<int>;
int main(){

    int x[] = { 8 ,2 ,7};
    int y[] =  { 8 ,3 ,7};
    int z[] =  { 8 ,4 ,7};
    Vect3d<int> birdman(x[0],y[0],z[0]);
    std::cout<<birdman.z<<"birdtime\n";
    KDtree<int> treeBoi(x,y,z,3);
    for (int i = 0; i < 3; i++) {
       std::cout<< treeBoi.points[i].x<<","<<treeBoi.points[i].y<<","<<treeBoi.points[i].z<<"\n";
    }

    int x1[] = { 23 ,2 ,7};
    int y1[] =  { 8 ,23 ,7};
    int z1[] =  { 8 ,4 ,23};
    treeBoi.updateData(x1,y1,z1);
    //for (int i = 0; i < 3; i++) {
    //   std::cout<< treeBoi.points[i].x<<","<<treeBoi.points[i].y<<","<<treeBoi.points[i].z<<"\n";
    //}
    return 1;
}
