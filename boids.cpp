#include "boids.h"

Boid::Boid(int x,int y ,int z){
    this->pos[0] = x;
    this->pos[1] = y;
    this->pos[2]= z;
}

void Boid::Move(int xInc,int yInc,int zInc){
    this->pos[0]+=xInc;
    this->pos[1]+=yInc;
    this->pos[2]+=zInc;
}

int* Boid::Update(){
    this->Move(this->vel[0],this->vel[1],0);

    if(this->pos[0] > this->max[0] ){
        this->pos[0] = this->max[0]-1;
        this->vel[0] = this->vel[0] * -1 ;
    }
    else if(this->pos[0] < this->min[0])
    {
	    this->pos[0] = this->min[0];
        this->vel[0] = this->vel[0] * -1;
    }

   if(this->pos[1] > this->max[1] ){
        this->pos[1] = this->max[1] -1;
        this->vel[1] = this->vel[1] *-1;
    }
    else if(this->pos[1] < this->min[0])
    {
	    this->pos[1] = this->min[0];
        this->vel[1] = this->vel[1] * -1;
    }

    return this->Locate();
}

int* Boid::Locate(){
    return this->pos;
}
