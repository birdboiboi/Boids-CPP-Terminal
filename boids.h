#pragma once

class Boid{
	
	public:
		Boid(int x,int y,int z);
		void Move(int xInc,int yInc,int zInc);
		void ChangeDir(int x,int y,int z);
		int* Update();
		int* Locate();
		int vel[3] = {0,0,0};
		int max[3] = {10,10,10};
		int min[3] = {0,0,0};
		
		
	private:
		int pos[3] ={0,0,0};

};
