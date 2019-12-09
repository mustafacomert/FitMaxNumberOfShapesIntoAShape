#include "Rectangle.h"

using namespace std;

namespace hw5Comert
{

double Rectangle::totalarea = 0;
double Rectangle::totalperimeter = 0;

//constructors
Rectangle::Rectangle(): Rectangle(10, 10)
{/*intentionally left blank*/}

Rectangle::Rectangle(double w, double h): Rectangle(w, h, 0, 0)
{/*empty*/}

Rectangle::Rectangle(double w, double h, double x, double y) throw(std::invalid_argument): Shape(w*h, x, y), width(w), height(h)
{
	if(w < 0 || h < 0)
		throw std::invalid_argument("");
	totalarea += area(); totalperimeter += perimeter(); }

//functions
void Rectangle::m_draw(std::ofstream& out) const
{
	out << "<rect x = \"" << getXCoor() << "\" y = \"" << getYCoor() << "\" width=\""
		<< width << "\" height=\""
		<< height << "\" fill=\"green\" stroke = \"yellow\" stroke-width=\"0.6\" />" << endl;
}

double Rectangle::perimeter() const
{
	double perimeter = 2*width+2*height;
	return perimeter;
}

double Rectangle::area() const
{
	double area = width*height;
	return area;
}

void Rectangle::draw(std::ofstream& out) const
{
	out<< "<svg version=\"1.1\"" << endl
		   << "baseProfile=\"full\" " << endl
		   << "xmlns=\"http://www.w3.org/2000/svg\">" << endl
		   << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\"" << endl;
	m_draw(out);
	out << "</svg>";
}
//static functions
double Rectangle::totalArea()
{
	return totalarea;
}

double Rectangle::totalPerimeter()
{
	return totalperimeter;
}
//overloadings
/*std::ofstream& operator<<(std::ofstream &out, const Rectangle &rect)
{
	rect.draw(out);
	return out;
}*/
//comparisons
Rectangle& Rectangle::operator+(double add)
{
	width += add;
	height += add;
	return *this;
}
Rectangle& Rectangle::operator-(double eject)
{
	width -= eject;
	height -= eject;
	return *this;
}
/*
bool Rectangle::operator==(const Shape& other) const
{
	return (this->area() == other.area()) ? true : false;
}
bool Rectangle::operator!=(const Shape& other) const
{
	return (!(*this == other)) ? true : false;// i like to call one operator overloading in the other
}
bool Rectangle::operator<(const Shape& other) const
{
	return (this->area() < other.area()) ? true : false;
}
bool Rectangle::operator>(const Shape& other) const
{
	return (this->area() > other.area()) ? true : false;
}
bool Rectangle::operator<=(const Shape& other) const
{
	return (this->area() <= other.area()) ? true : false;
}
bool Rectangle::operator>=(const Shape& other) const
{
	return (this->area() >= other.area()) ? true : false;
}*/
//incrementing decrementing operators
Rectangle& Rectangle::operator++()
{
	setXCoor(getXCoor()+1);
	setYCoor(getYCoor()+1);
	return *this;
}
const Rectangle& Rectangle::operator++(int x)
{
	std::shared_ptr<Rectangle> temp = std::make_shared<Rectangle>(*this);
	++(*this);
	return *temp;
}
Rectangle& Rectangle::operator--()
{
	setXCoor(getXCoor()-1);
	setYCoor(getYCoor()-1);
	return *this;
}
const Rectangle& Rectangle::operator--(int x)
{
	std::shared_ptr<Rectangle> temp = std::make_shared<Rectangle>(*this); // copy constructor
	--(*this);
	return *temp;
}
}
