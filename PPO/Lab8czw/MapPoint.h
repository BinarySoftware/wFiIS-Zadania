#pragma once

#include "MapDistance.h"

/**
 * 
 */
class MapPoint {
    public:
        /**
         * 
         */
        void set_coordinates(double, double);
        void print();
        MapDistance distance(MapPoint&);
        MapPoint half_way_to(MapPoint&);
        double getX();
        double getY();
    
    private:
        double x; /**< Chuj ci w dupe */
        double y;
};