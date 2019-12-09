#include "Circle.h"

using namespace std;

namespace hw5Comert
{
double Circle::totalarea = 0;// static member variable init.
double Circle::totalperimeter = 0;
//constructors
Circle::Circle() : Shape(PI*10*10, 10, 10), radius(10)
{ totalarea += area(); totalperimeter += perimeter(); }

Circle::Circle(double r): Shape(PI*r*r, r, r) ,radius(r)
{ totalarea += area(); totalperimeter += perimeter(); }

Circle::Circle(double r, double x, double y) throw(std::invalid_argument): Shape(PI*r*r, x, y) ,radius(r)
{
	if(r < 0)
		throw std::invalid_argument("");
	totalarea += area(); totalperimeter += perimeter();
}

//functions
void Circle::m_draw(ofstream& out) const
{
	out << "<circle cx = \"" << getXCoor() << "\" cy = \"" << getYCoor() << "\" r=\""
		<< radius << "\" fill=\"green\" stroke = \"yellow\" stroke-width = \"0.6\"/>" << endl;
}

double Circle::perimeter() const
{
	double perimeter =  2*PI*radius;
	return perimeter;
}
double Circle::area() const
{
	double area = PI*radius*radius;
	return area;
}

void Circle::draw(std::ofstream& out) const
{
	out<< "<svg version=\"1.1\"" << endl
		   << "baseProfile=\"full\" " << endl
		   << "xmlns=\"http://www.w3.org/2000/svg\">" << endl
		   << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\"" << endl;
	m_draw(out);
	out << "</svg>";
}

//static functions
double Circle::totalArea()
{
	return totalarea;
}

double Circle::totalPerimeter()
{
	return totalperimeter;
}
//overloadings
/*std::ofstream& operator<<(std::ofstream &out, const Circle &circ)
{
	circ.draw(out);
	return out;
}*/
const Circle& Circle::operator+(double add)
{
	radius += add;
	return *this;
}
const Circle& Circle::operator-(double eject)
{
	radius -= eject;
	return *this;
}

/*bool Circle::operator==(const Shape& other) const
{
	return (this->area() == other.area()) ? true : false;
}
bool Circle::operator!=(const Shape& other) const
{
	return (!(*this == other)) ? true : false;// i like to call one operator overloading in the other
}
bool Circle::operator<(const Shape& other) const
{
	return (this->area() < other.area()) ? true : false;
}
bool Circle::operator>(const Shape& other) const
{
	return (this->area() > other.area()) ? true : false;
}
bool Circle::operator<=(const Shape& other) const
{
	return (this->area() <= other.area()) ? true : false;
}
bool Circle::operator>=(const Shape& other) const
{
	return (this->area() >= other.area()) ? true : false;
}*/

//increment decrement
Circle& Circle::operator ++()
{
	setXCoor(getXCoor()+1);
	setYCoor(getYCoor()+1);
	return *this;
}

const Circle& Circle::operator ++(int x)
{
	std::shared_ptr<Circle> temp = std::make_shared<Circle>(*this);
	++(*this);
	return *temp;
}

Circle& Circle::operator --()
{
	setXCoor(getXCoor()-1);
	setYCoor(getYCoor()-1);
	return *this;
}

const Circle& Circle::operator --(int x)
{
	std::shared_ptr<Circle> temp = std::make_shared<Circle>(*this);
	--(*this);
	return *temp;
}

}/*namespace*/
