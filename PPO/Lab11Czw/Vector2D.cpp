#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(double x, double y):
 _x(x),
 _y(y){
	count++;
}

Vector2D::~Vector2D(){
	count--;
}

Vector2D::Vector2D(const Vector2D &other){
	_x = other._x;
	_y = other._y;
	std::cout << "copying  (" << _x << "," << _y << ")" << std::endl; 
	count++;
}

Vector2D::Vector2D(Vector2D &&other):
_x(std::move(other._x)),
_y(std::move(other._y)){
	std::cout << "moving  (" << _x << "," << _y << ")" << std::endl; 
	count++;
}

Vector2D Vector2D::fromCarthesian(double x, double y){
	Vector2D wyn(x,y);
	return wyn;
}

Vector2D Vector2D::fromPolar(double r, double phi){
	double rad = phi/180 * M_PI;
	double x = r*cos(rad);
	double y = r*sin(rad);
	Vector2D wyn(x,y);
	return wyn;
}

void Vector2D::print(std::string begin) const{
	std::cout << begin << "(" << _x << ", " << _y << ")" << std::endl;
}

int Vector2D::number_vertices(){
	return count;
}

Vector2D Vector2D::add(const Vector2D &other) const{
	double x = _x + other._x;
	double y = _y + other._y;
	Vector2D wyn(x,y);
	return wyn;
}

double Vector2D::dot(const Vector2D &other) const{
	return _x*other._x + _y*other._y;
}