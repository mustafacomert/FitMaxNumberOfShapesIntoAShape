#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <fstream>
#include <iostream>
#include "Shape.h"
const double PI = 3.14159265359;

namespace hw5Comert
{
class Circle: public Shape
{
public:
	//constructors
	Circle();
	Circle(double r);
	Circle(double r, double x, double y) throw(std::invalid_argument);
	//functions
	double perimeter() const;//implements
	double area() const;//implements
	//static functions
	static double totalArea();
	static double totalPerimeter();
	void m_draw(std::ofstream& out) const;
	void draw(std::ofstream& out) const;//implements
	//overloadings
	//friend std::ofstream& operator<<(std::ofstream &out, const Circle &circ);
	const Circle& operator+(double);
	const Circle& operator-(double);
	//compares with areas
	/*
	bool operator==(const Shape& other) const;//implements
	bool operator!=(const Shape& other) const;//implements
	bool operator<(const Shape& other) const;//implements
	bool operator>(const Shape& other) const;//implements
	bool operator<=(const Shape& other) const;//implements
	bool operator>=(const Shape& other) const;//implements*/
	//accessor
	inline double getRadius() const;
	//modifier
	inline void setRadius(double r);
	//increment decrement
	Circle& operator++();//prefix
	const Circle& operator++(int x);//postfix
	Circle& operator--();//prefix
	const Circle& operator--(int x);//postfix
private:
	double radius;
	//static member varible
	static double totalarea;
	static double totalperimeter;
};

//accessor
double Circle::getRadius() const
{ return radius; }
//modifier
void Circle::setRadius(double r)
{ radius = r; }
}/*namespace*/
#endif
