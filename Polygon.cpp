#include "Polygon.h"

using namespace std;

namespace hw5Comert {

//POINT2D CLASS
//functions
Polygon::Point2D::Point2D(): Point2D(0,0)
{ /*left blank*/ }

Polygon::Point2D::Point2D(double x, double y): xCoor(x), yCoor(y)
{ /*left blank*/ }

bool Polygon::Point2D::operator==(const Point2D& p2DObj) const
{
	if(xCoor == p2DObj.xCoor && yCoor == p2DObj.yCoor)
		{ return true; }
	return false;
}

bool Polygon::Point2D::operator !=(const Point2D& p2DObj) const
{
	return !(*this == p2DObj);
}

//POLYGON CLASS
Polygon::Polygon(): p2DObj(0, 0), perimeterOfPolygon(0)
{
	setAreaOfShape(0);
}

Polygon::Polygon(const Point2D& p2D): p2DObj(p2D),  perimeterOfPolygon(0)
{
	setAreaOfShape(0);
}

Polygon::Polygon(double a, double p) throw(std::invalid_argument):  perimeterOfPolygon(p)
{
	if(a < 0 || p < 0)
		throw std::invalid_argument("");
	setAreaOfShape(a);
}

}/* namespace hw5Comert */
