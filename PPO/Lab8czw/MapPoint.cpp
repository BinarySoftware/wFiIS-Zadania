#include "MapPoint.h"
#include <iostream>

void MapPoint::set_coordinates(double x, double y){
    this->x = x;
    this->y = y;
}

void MapPoint::print(){
    std::cout << "Point: (" << this->x << ", " << this->y << ")" << std::endl;
}

MapDistance MapPoint::distance(MapPoint &p){
    double dLat = this->x - p.x;
    double dLon = this->y - p.y;
    MapDistance d;
    d.set(dLat,dLon);
    return d;
}

MapPoint MapPoint::half_way_to(MapPoint &p){
    double lat = (this->x + p.getX())/2.0;
    double lon = (this->y + p.getY())/2.0;
    MapPoint pmid;
    pmid.set_coordinates(lat,lon);
    return pmid;
}

double MapPoint::getX(){
    return this->x;
}

double MapPoint::getY(){
    return this->y;
}