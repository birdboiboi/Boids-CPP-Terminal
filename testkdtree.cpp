#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <unistd.h>
#include "boids.h"
#include "kdTree.h"

unsigned int microsecond = 25000;

struct testObj{
    std::vector<int> x_cordinates;
    std::vector<int> y_cordinates;
    std::vector<int> z_cordinates;
};

void printTestObj(testObj* objIn){
    //std::cout << "\nXaxis\n";
    for (auto it = objIn->x_cordinates.begin(); it != objIn->x_cordinates.end(); ++it) 
        std::cout << ' ' << *it; 
    std::cout << "\n";
    for (auto it = objIn->y_cordinates.begin(); it != objIn->y_cordinates.end(); ++it) 
        std::cout << ' ' << *it; 
    //std::cout << "\nZaxis\n";
    //for (auto it = objIn->z_cordinates.begin(); it != objIn->z_cordinates.end(); ++it) 
    //    std::cout << ' ' << *it; 
    
}

void retarded2dPlot(std::vector<int>& x, std::vector<int>& y,char symbol){
    std::cout << "\nplotstart\n";
    int mat[10][10] ={};
    for (int i = 0; i < x.size(); i++){
        mat[x.at(i)][y.at(i)]= 1;
    } 
    for (int j = 0; j< 10; j++){
        for (int i =0;i < 20;i++){
            if(mat[j][i] ==1){
                std::cout<<"<"<<j<<","<<i<<">";
                //std::cout<<symbol<<" ";
            }else{
                std::cout<<"_____";
            }
        }
        std::cout<<"\n\n";
    }    
}

void boidToObject(int *coordinates,testObj *structRef, int idx){
    structRef->x_cordinates[idx] = coordinates[0];
    structRef->y_cordinates[idx] = coordinates[1];
    structRef->z_cordinates[idx] = coordinates[2];
}

testObj randVect;
std::vector<Boid> boids;

void setup(){
    
    //test code
    for(int i = 0; i < 10 ; i++){
        boids.push_back(Boid(static_cast<int>(rand()%10),
                        static_cast<int>(rand()%10),
                        static_cast<int>(rand()%10)));
        randVect.x_cordinates.push_back(0);
        randVect.y_cordinates.push_back(0);
        randVect.z_cordinates.push_back(0);
        boids[i].max[0] = 19;
        boids[i].max[1] = 19;
        boids[i].min[0] = 1;
        boids[i].min[1] = 1;
        boids[i].vel[0] = rand()%4-2;
        boids[i].vel[1] = rand()%4-2;
    }
}

void loop(){
    system("clear"); 
    int xList[boids.size()-1];
    int yList[boids.size()-1];
    int zList[boids.size()-1];
    for (int i = 0; i < boids.size()-1; i++) {
        boidToObject(boids[i].Update(),&randVect,i);
        xList[i] = boids[i].Locate()[0]; 
        yList[i] = boids[i].Locate()[1]; 
        zList[i] = boids[i].Locate()[2]; 
	    std::cout<< xList[i]<<","<<yList[i]<<","<<zList[i];
    }
    KDtree treeBoi;
    treeBoi.prepareData(xList,yList,zList);
    for (int i = 0; i < boids.size()-1; i++) {
       std::cout<< treeBoi.xPoints[i]<<","<<treeBoi.yPoints[i]<<","<<treeBoi.zPoints[i];
    }
    printTestObj(&randVect);
    retarded2dPlot(randVect.x_cordinates,randVect.y_cordinates,'X');



}

int main(){
    setup();
    for( int i = 1; i < 100; i++){
        loop();
        usleep( 2* microsecond);
    }
    return 1;

}
