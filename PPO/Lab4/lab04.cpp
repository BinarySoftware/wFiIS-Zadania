#include "lab04.h"

#include <iostream>
#include <cmath>

MapPoint * construct(std::string name, double lat, double lon){
  MapPoint * point = new(MapPoint);
  point->name = name;
  point->lat = lat;
  point->lon = lon;
  return point;
}

void print(MapPoint* point){
  std::string name = point->name;
  double lat       = point->lat;
  double lon       = point->lon;
  std::cout << "Position of " << name << ". Latitude: " << lat << ". Longitude: " << lon << std::endl;
}

MapPoint inTheMiddle(MapPoint * p1, MapPoint * p2, std::string name){
  double lat = (p1->lat + p2->lat)/2.0;
  double lon = (p1->lon + p2->lon)/2.0;
  MapPoint p = {name,lat,lon};
  return p;
}

MapPoint closestFrom(MapPoint * from, MapPoint * to_1,MapPoint * to_2){
  MapDist d1 = distance(from,*to_1);
  MapDist d2 = distance(from,*to_2);
  if (distanceMag(d1) < distanceMag(d2)){
    return *to_1;
  } else {
    return *to_2;
  }
}

std::string name(MapPoint p){
  return p.name;
}

void move(MapPoint ** point, double dLat, double dLon){
  (*point)->lat += dLat;
  (*point)->lon += dLon;
}

void clear(MapPoint * point){
  delete point;
}

void clear(MapPoint * points[], double size){
  for (int i = 0; i < size; i++){
    clear(points[i]);
  }
}




MapDist distance(MapPoint * p1, MapPoint p2){
  double dLat = p1->lat - p2.lat;
  double dLon = p1->lon - p2.lon;
  MapDist d = {dLat,dLon};
  return d;
}

double distanceMag(MapDist d){
  return sqrt(pow(d.latitude,2) + pow(d.longitude,2));
}