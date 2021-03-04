#include "MapDistance.h"
#include <iostream>

void MapDistance::print(){
    std::cout << "Distance: (" << this->dx << ", " << this->dy << ")" << std::endl;
}

void MapDistance::set(double x,double y){
    this->dx = fabs(x);
    this->dy = fabs(y);
}