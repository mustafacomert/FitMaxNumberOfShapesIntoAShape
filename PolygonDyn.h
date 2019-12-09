#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_

#include "Polygon.h"
#include <iostream>

namespace hw5Comert {

class PolygonDyn: public Polygon
{
public:
	//constructors
	PolygonDyn(); //no parameter constructor
	PolygonDyn(const PolygonDyn& p);//copy constructor
	PolygonDyn(const std::vector<Point2D>& vectPoint2D);
	PolygonDyn(const Point2D& p2D); //conversion constructor from Point2D
	PolygonDyn(const Rectangle& rect); //conversion constructor from Rectangle
	PolygonDyn(const Circle& circ); //conversion constructor from Circle
	PolygonDyn(const Triangle& tri, int status = 0); //conver. const. from Triangle since c++11
	//operator overloadings
	Point2D& operator[](const int i) throw(std::out_of_range);//for using as a lhs
	const Point2D& operator[](const int i) const throw(std::out_of_range);//for printing on the screen etc.
	/*
	bool operator==(const PolygonDyn& polyObj) const;
	bool operator!=(const PolygonDyn& polyObj) const;*/
	PolygonDyn operator+(PolygonDyn polObj); //concenates arrays
	PolygonDyn& operator=(const PolygonDyn& rhs);
	//function
	double perimeter() const;
	inline int getSize() const { return size; }
	void draw(std::ofstream& out) const;
	void m_draw(std::ofstream& out) const;
	//decrement increment
	PolygonDyn& operator++();//prefix
	const PolygonDyn& operator++(int x);//postfix
	PolygonDyn& operator--();//prefix
	const PolygonDyn& operator--(int x);//postfix
	//desctructor
	~PolygonDyn();
private:
	Point2D *arrPoint2D; // array of Point2D objects
	int size;// i should make unsigned int it
};

} /* namespace hw5Comert */
#endif /* POLYGONDYN_H_ */
