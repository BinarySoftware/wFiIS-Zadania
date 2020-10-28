#pragma once

#include <iostream>

/**
 * Structure holding MapPoint.
 *
 * @field name - point's name
 * @field lat - latitude
 * @field lon - longitude
 */
struct MapPoint{
  std::string name;
  double lat;
  double lon;
};

/**
 * Creates new MapPoint from given data.
 */
MapPoint * construct(std::string name, double lat, double lon);

/**
 * Prints out MapPoint in human-readable format.
 */
void print(MapPoint* point);

/**
 * Calculates MapPoint in the middle of other two MapPoints.
 */
MapPoint inTheMiddle(MapPoint * p1, MapPoint * p2, std::string name);

/**
 * Calculates MapPoint closest to given `from` MapPoint out of 
 * `to_1` and `to_2` MapPoint's.
 */
MapPoint closestFrom(MapPoint * from, MapPoint * to_1,MapPoint * to_2);

/**
 * Getter for MapPoint's name.
 */
std::string name(MapPoint p);

/**
 * Moves MapPoint by given latitude and longitude.
 */
void move(MapPoint ** point, double dLat, double dLon);

/**
 * Deletes given MapPoint from memory.
 */
void clear(MapPoint * point);

/**
 * Deletes all of given MapPoints from memory.
 */
void clear(MapPoint * points[], double size);



/**
 * Structure holding MapDist.
 *
 * @field latitude - MapPoint's latitude's delta's
 * @field longitude - MapPoint's longitude's delta's
 */
struct MapDist{
  double latitude;
  double longitude;
};

/**
 * Creates new MapDist from given data.
 */
MapDist distance(MapPoint * p1, MapPoint p2);

/**
 * Calculates distance from data stored in helper MapDist.
 */
double distanceMag(MapDist d);