#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <memory>

namespace hw5Comert {

class Shape {
public:
	Shape();
	Shape(double a, double x, double y);//initiliaze coordinates and area
	//functions
	virtual double area() const;
	virtual double perimeter() const = 0;
	virtual void draw(std::ofstream& out) const = 0;
	virtual void m_draw(std::ofstream& out) const = 0;
	//comparison operators overloading
	bool operator==(const Shape& other) const;
	bool operator!=(const Shape& other) const;
	bool operator<(const Shape& other) const;
	bool operator>(const Shape& other) const;
	bool operator<=(const Shape& other) const;
	bool operator>=(const Shape& other) const;
	//incrementing operators overloading
	virtual Shape& operator++() = 0;//prefix
	virtual const Shape& operator++(int x) = 0;//postfix
	virtual Shape& operator--() = 0;//prefix
	virtual const Shape& operator--(int x) = 0;//postfix
	//assingment operator overloading
	virtual Shape& operator=(const Shape& rhs) = default;
	virtual ~Shape() = default;
	//accessors
	//it didn't work when i make protected these setter and getters
	inline double getXCoor() const;
	inline double getYCoor() const;
	inline double getAreaOfShape() const;
	//modifiers
	inline void setXCoor(double x) throw(std::invalid_argument);
	inline void setYCoor(double y) throw(std::invalid_argument);
	inline void setAreaOfShape(double a) throw(std::invalid_argument);
private:
	double areaOfShape;
	double xCoor;
	double yCoor;
};

//accessors
double Shape::getXCoor() const
{ return xCoor; }
double Shape::getYCoor() const
{ return yCoor; }
double Shape::getAreaOfShape() const
{ return areaOfShape; }

//modifiers
void Shape::setXCoor(double x) throw(std::invalid_argument)
{
	if(x < 0)
		throw std::invalid_argument("");
	xCoor = x;
}
void Shape::setYCoor(double y) throw(std::invalid_argument)
{
	if(y < 0)
		throw std::invalid_argument("");
	yCoor = y;
}
void Shape::setAreaOfShape(double a) throw(std::invalid_argument)
{
	if(a < 0)
		throw std::invalid_argument("");
	areaOfShape = a;
}

}/* namespace hw5Comert */

#endif /* SHAPE_H_ */
