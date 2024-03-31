#include "kdTree.h"
#include <algorithm>

KDtree::KDtree(){

}

void KDtree::prepareData(int *xPoints,int *yPoints, int *zPoints){
    int len = sizeof(xPoints)/sizeof(xPoints[0]);
    std::sort(xPoints,xPoints+len);
    std::sort(yPoints,yPoints+len);
    std::sort(zPoints,zPoints+len);
    this->xPoints = xPoints;
    this->yPoints = yPoints;
    this->zPoints = zPoints;
}
