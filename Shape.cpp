#include "Shape.h"

namespace hw5Comert
{

Shape::Shape(): areaOfShape(0), xCoor(0), yCoor(0)
{/*left blank*/}

Shape::Shape(double a, double x, double y): areaOfShape(a), xCoor(x), yCoor(y)
{ /*left blank*/}

//function
double Shape::area() const
{
	return areaOfShape;
}
//incrementing operators overloading

/*Shape& Shape::operator++()
{
	++xCoor;
	++yCoor;
	return *this;
}

Shape& Shape::operator--()
{
	--xCoor;
	--yCoor;
	return *this;
}*/
//comparision operators
bool Shape::operator==(const Shape& other) const
{
	return ((int)area() == (int)other.area()) ? true : false;
}
bool Shape::operator!=(const Shape& other) const
{
	return !(*this == other);
}

bool Shape::operator<(const Shape& other) const
{
	return (area() < other.area()) ? true : false;
}

//friend
bool Shape::operator>(const Shape& other) const
{
	return !(*this < other) && (*this != other);
}

bool Shape::operator<=(const Shape& other) const
{
	return (*this < other) && (*this == other);
}

bool Shape::operator>=(const Shape& other) const
{
	return (*this > other) && (*this == other);
}

} /* namespace hw5Comert */
