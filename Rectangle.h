#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"
#include <fstream>
#include <iostream>
#include <cmath>
namespace hw5Comert
{
class Rectangle: public Shape
{
public:
	//constructors
	Rectangle();//no param constructor
	Rectangle(double w, double h);
	Rectangle(double w, double h, double x, double y) throw(std::invalid_argument);
	//functions
	double perimeter() const;//implements
	double area() const;//implements
	void m_draw(std::ofstream& out) const;
	void draw(std::ofstream& out) const;
	//static functions
	static double totalArea();
	static double totalPerimeter();
	//operator overloadings
	//friend std::ofstream& operator<<(std::ofstream &out, const Rectangle &rect);

	Rectangle& operator+(double);
	Rectangle& operator-(double);

	//accessors
	inline double getWidth() const;
	inline double getHeight() const;
	//modifiers
	inline void setWidth(double w) throw(std::invalid_argument);
	inline void setHeight(double h) throw(std::invalid_argument);
	Rectangle& operator++();//prefix //overrides
	const Rectangle& operator++(int x);//postfix, overrides
	Rectangle& operator--();//prefix //overrides
	const Rectangle& operator--(int x);//postfix, overrides
private:
	double width;
	double height;
	//static member variables
	static double totalarea;
	static double totalperimeter;
};

//accessors
double Rectangle::getWidth() const
{ return width; }

double Rectangle::getHeight() const
{ return height; }
//modifiers
void Rectangle::setWidth(double w) throw(std::invalid_argument)
{
	if(w < 0)
		throw std::invalid_argument("");
	width = w;
}

void Rectangle::setHeight(double h) throw(std::invalid_argument)
{
	if(h < 0)
		throw std::invalid_argument("");
	height = h;
}
}/*namespace*/
#endif
