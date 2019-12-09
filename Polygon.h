#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <iostream>
#include <vector>
//#include <cstdlib> // for exit()

namespace hw5Comert {

class Polygon: public Shape
{
public:
	class Point2D
	{
	public:
		Point2D();
		Point2D(double x, double y);
		// accessors
		inline double getX() const{ return xCoor; }
		inline double getY() const{ return yCoor; }
		// modifiers
		inline void setX(double x) { xCoor = x; }
		inline void setY(double y) { yCoor = y; }
		// overloadings
		bool operator==(const Point2D& p2DObj) const;
		bool operator!=(const Point2D& p2DObj) const;
		//constructors
	private:
		double xCoor;
		double yCoor;
	}p2DObj;
	//constructors
	Polygon(); // no parameter constructor
	Polygon(const Point2D& p2D); // conversion constructor from Point2D
	Polygon(double a, double p) throw(std::invalid_argument);// a for area, p for perimeter
	virtual ~Polygon() = default;
protected:
	inline double getPerimeterOfPolygon() const noexcept { return perimeterOfPolygon; }
	inline void setPerimeterOfPolygon(double p) throw(std::invalid_argument)
	{
		if(p < 0)
			throw std::invalid_argument("");
		perimeterOfPolygon = p;
	}
private:
	double perimeterOfPolygon;
};
} /* namespace hw5Comert */
#endif /* POLYGON_H_ */
