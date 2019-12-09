#include "Triangle.h"

using namespace std;

namespace hw5Comert
{
double Triangle::totalarea = 0;
double Triangle::totalperimeter = 0;

//constructors
Triangle::Triangle(): Shape(10*10*sqrt(3)/4, 5, 5*sqrt(3)/2), edge(10)
{ totalarea += area(); totalperimeter += perimeter(); }

Triangle::Triangle(double a) throw(std::invalid_argument): Shape(a*a*sqrt(3)/4, a/2, 0), edge(a), status(1)
{
	if(a < 0)
		throw std::invalid_argument("");
	totalarea += area(); totalperimeter += perimeter(); }

Triangle::Triangle(double a, double x, double y, int s) throw(std::invalid_argument): Shape(a*a*sqrt(3)/4, x, y), edge(a), status(s)
{
	if(a < 0)
		throw std::invalid_argument("");
	totalarea += area(); totalperimeter += perimeter(); }

//functions
void Triangle::m_draw(std::ofstream& out) const
{
	if(status == 0)//ters
	{
		out << "<polygon points = \"" << getXCoor() << " " << getYCoor() << ", "
				<< getXCoor() + edge << " " << getYCoor() << ", "
				<< edge/2+getXCoor() << " "<< getYCoor()+edge*sqrt(3)/2
				<< "\" fill = \"green\" stroke = \"yellow\" stroke-width = \"0.6\"/>" << endl;
	}
	else if(status == 1)//düz
	{
		out << "<polygon points = \"" << getXCoor() << " " << getYCoor() << ", "
				<< getXCoor() + edge/2 << " "<< getYCoor()+edge*sqrt(3)/2 << ", "
				<< getXCoor() - edge/2 << " "<< getYCoor()+edge*sqrt(3)/2
				<< "\" fill = \"green\" stroke = \"yellow\" stroke-width = \"0.6\"/>" << endl;
	}
}

double Triangle::perimeter() const
{
	double perimeter = 3*edge;
	return perimeter;
}

double Triangle::area() const
{
	double area = edge*edge*sqrt(3)/4;
	return area;
	//or just return getAreaOfShape();
}

void Triangle::draw(std::ofstream& out) const
{
	out<< "<svg version=\"1.1\"" << endl
	   << "baseProfile=\"full\" " << endl
	   << "xmlns=\"http://www.w3.org/2000/svg\">" << endl
	   << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\"" << endl;
	m_draw(out);
	out << "</svg>";
}
//static functions
double Triangle::totalArea()
{
	return totalarea;
}

double Triangle::totalPerimeter()
{
	return totalperimeter;
}
//overloadings
/*std::ofstream& operator<<(std::ofstream &out, const Triangle &tri)
{
	tri.draw(out);
	return out;
}*/

const Triangle& Triangle::operator+(double add)
{
	edge += add;
	return *this;
}
const Triangle& Triangle::operator-(double eject)
{
	edge -= eject;
	return *this;
}
/*
bool Triangle::operator==(const Shape& other) const
{
	return (this->area() == other.area()) ? true : false;
}
bool Triangle::operator!=(const Shape& other) const
{
	return (!(*this == other)) ? true : false;// i like to call one operator overloading in the other
}
bool Triangle::operator<(const Shape& other) const
{
	return (this->area() < other.area()) ? true : false;
}
bool Triangle::operator>(const Shape& other) const
{
	return (this->area() > other.area()) ? true : false;
}
bool Triangle::operator<=(const Shape& other) const
{
	return (this->area() <= other.area()) ? true : false;
}
bool Triangle::operator>=(const Shape& other) const
{
	return (this->area() >= other.area()) ? true : false;
}*/
//increment decrement operators
Triangle& Triangle::operator++()
{
	setXCoor(getXCoor()+1);
	setYCoor(getYCoor()+1);
	return *this;
}
const Triangle& Triangle::operator++(int x)
{
	std::shared_ptr<Triangle> temp = std::make_shared<Triangle>(*this);
	++(*this);
	return *temp;
}
Triangle& Triangle::operator--()
{
	setXCoor(getXCoor()-1);
	setYCoor(getYCoor()-1);
	return *this;
}
const Triangle& Triangle::operator--(int x)
{
	std::shared_ptr<Triangle> temp = std::make_shared<Triangle>(*this);
	--(*this);
	return *temp;
}
}
