#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

enum enumType {R, C, T};

using namespace std;

namespace hw5Comert
{
class ComposedShape: public Shape
{
public:
	//inner class
	//constructors
	ComposedShape();
	ComposedShape(Rectangle& rectCon, Rectangle& rectSmall);
	ComposedShape(Rectangle &rectCon, Circle &circSmall);
	ComposedShape(Rectangle &rectCon, Triangle &triSmall);
	ComposedShape(Circle &circCon, Rectangle &rectSmall);
	ComposedShape(Circle &circCon, Circle &circSmall);
	ComposedShape(Circle &circCon, Triangle &triSmall);
	ComposedShape(Triangle &triCon, Rectangle &rectSmall);
	ComposedShape(Triangle &triCon, Circle &circSmall);
	ComposedShape(Triangle &triCon, Triangle &triSmall);
	//functions
	double area() const;//overrides
	double perimeter() const;//implements
	void optimalFit();
	inline void m_draw(ofstream& out) const{cout << "Calling ComposedShape::m_draw undesirable behaviour"; }
	void draw(ofstream& out) const;//implements

	//overloadings
	ComposedShape& operator++();//prefix
	const ComposedShape& operator++(int x);//postfix
	ComposedShape& operator--();//prefix
	const ComposedShape& operator--(int x);//postfix
	//friend std::ofstream& operator<<(std::ofstream &out, const ComposedShape &composed);
	ComposedShape& operator+=(const ComposedShape& other);
private:
	//functions
	int numOfRC(double containerRadius, double smallShapeWidth, double smallShapeHeight, bool rotate) const;
	double distanceTwoPoints(double x1, double x2, double y1, double y2) const;
	bool CompareSlopeOfLine(double x1, double y1, double x2, double y2) const;
	//container type
	Rectangle rectConObj;
	//xor
	Circle circConObj;
	//xor
	Triangle triConObj;

	//inner shape type
	Rectangle rectSmallObj;
	//xor
	Circle circSmallObj;
	//xor
	Triangle triSmallObj;

	//type; one digit for every situation(0-8)
	int type;
	//vector of Shape*, holds every inner shape
	vector <Shape*> shapeVect;
};
}/*namespace*/
#endif
