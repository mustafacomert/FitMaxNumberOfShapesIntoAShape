#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <fstream>
#include <cmath>
#include "Shape.h"

namespace hw5Comert
{
class Triangle: public Shape
{
public:
	//constructors
	Triangle();
	Triangle(double a) throw(std::invalid_argument);
	Triangle(double a, double x, double y, int s) throw(std::invalid_argument);// s demonstrates status
	//functions
	double perimeter() const;//implements
	double area() const;//overrides
	void m_draw(std::ofstream& out) const;
	void draw(std::ofstream& out) const;//implements
	//static functions
	static double totalArea();
	static double totalPerimeter();
	//overloadings
	//friend std::ofstream& operator<<(std::ofstream &out, const Triangle &tri);
	const Triangle& operator+(double);
	const Triangle& operator-(double);

	//increment decrement operators
	virtual Triangle& operator++();//prefix
	virtual const Triangle& operator++(int x);//postfix
	virtual Triangle& operator--();//prefix
	virtual const Triangle& operator--(int x);//postfix
	//accessors
	inline double getEdge() const;
	//modifiers
	inline void setEdge(double a) throw(std::invalid_argument);
private:
	double edge;
	//there are 2 different draw method,
	//status variable determines which situation will execute, it can be 0 or 1
	int status;
	//static member
	static double totalarea;
	static double totalperimeter;
};

//accessors
double Triangle::getEdge() const  { return edge; }
//modifiers
void Triangle::setEdge(double a) throw(std::invalid_argument) { if(a<0) throw std::invalid_argument(""); edge = a; }
}/*namespace*/
#endif
