#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_

#include "Polygon.h"
#include <vector>

namespace hw5Comert {

class PolygonVect: public Polygon
{
public:
	PolygonVect(); // no parameter constructor
	PolygonVect(const PolygonVect& p);// copy constructor
	PolygonVect(const std::vector<Point2D>& v2D);
	PolygonVect(const Point2D& p2D); // conversion constructor from Point2D
	PolygonVect(const Rectangle& rect); // conversion constructor from Rectangle
	PolygonVect(const Circle& circ); // conversion constructor from Circle
	PolygonVect(const Triangle& tri, int status = 0); // conver. const. from Triangle since c++11
	//functions
	virtual double perimeter() const;//implements
	virtual void m_draw(std::ofstream& out) const;
	virtual void draw(std::ofstream& out) const;//implements
	//indexing operator
	Point2D& operator[](const int i) throw(std::out_of_range);//for using as a lhs
	const Point2D& operator[](const int i) const throw(std::out_of_range);//for printing on the screen etc.
	//decrement increment
	PolygonVect& operator++();//prefix
	const PolygonVect& operator++(int x);//postfix
	PolygonVect& operator--();//prefix
	const PolygonVect& operator--(int x);//postfix
private:
	std::vector<Point2D> vectPoint2D;
};

} /* namespace hw5Comert */
#endif /* POLYGONVECT_H_ */
