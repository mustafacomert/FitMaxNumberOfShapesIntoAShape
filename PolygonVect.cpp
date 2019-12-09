#include "PolygonVect.h"

using namespace std;

namespace hw5Comert
{

PolygonVect::PolygonVect(): Polygon()
{
}

PolygonVect::PolygonVect(const PolygonVect& pv): Polygon(pv.p2DObj), vectPoint2D(pv.vectPoint2D)//copy constructor
{}

PolygonVect::PolygonVect(const std::vector<Point2D>& v2D): Polygon(), vectPoint2D(v2D) //vector assign
{}

PolygonVect::PolygonVect(const Point2D& p2D): Polygon(p2D)
{
	vectPoint2D.push_back(p2D);
}

PolygonVect::PolygonVect(const Rectangle& r): Polygon(r.area(), r.perimeter())
{
	vectPoint2D.push_back(Point2D(r.getXCoor(), r.getYCoor()));
	vectPoint2D.push_back(Point2D(r.getXCoor() + r.getWidth(), r.getYCoor()));
	vectPoint2D.push_back(Point2D(r.getXCoor() + r.getWidth(), r.getYCoor()+r.getHeight()));
	vectPoint2D.push_back(Point2D(r.getXCoor(), r.getYCoor() + r.getHeight()));
}

PolygonVect::PolygonVect(const Circle& c): Polygon(c.area(), c.perimeter())
{
	for (double i = 0; i < 360; i += 3.6)
	{
		Point2D p2DObj(c.getXCoor() + c.getRadius() * sin(i * PI / 180),
					   c.getYCoor() + c.getRadius() * cos(i * PI / 180));
		vectPoint2D.push_back(p2DObj);
	}
}

PolygonVect::PolygonVect(const Triangle& t, int status):  Polygon(t.area(), t.perimeter())
{
		if (status == 1) {
			Point2D p2D(t.getXCoor(), t.getYCoor());
			vectPoint2D.push_back(p2D);
			Point2D p2D2(t.getXCoor() + t.getEdge() / 2,
						 t.getYCoor() + t.getEdge() * sqrt(3) / 2);
			vectPoint2D.push_back(p2D2);
			Point2D p2D3(t.getXCoor() - t.getEdge() / 2,
					t.getYCoor() + t.getEdge() * sqrt(3) / 2);
			vectPoint2D.push_back(p2D3);
		} else if (status == 0) {
			Point2D p2D(t.getXCoor(), t.getYCoor());
			vectPoint2D.push_back(p2D);
			Point2D p2D2(t.getXCoor() + t.getEdge(), t.getYCoor());
			vectPoint2D.push_back(p2D2);
			Point2D p2D3(t.getXCoor() + t.getEdge() / 2,
					t.getYCoor() + t.getEdge() * sqrt(3) / 2);
			vectPoint2D.push_back(p2D3);
		} else {
			std::cout << "Error in Triangle to PolygonDyn conversion constructor" << std::endl;
			exit(1);
		}
}

void PolygonVect::m_draw(std::ofstream& out) const {
	out << "<polygon points = \"";
	for (unsigned int i = 0; i < vectPoint2D.size(); ++i) {
		out << vectPoint2D[i].getX() << " " << vectPoint2D[i].getY() << ", ";
	}
	out << "\" fill = \"green\" stroke = \"yellow\" stroke-width = \"0.1\"/>" << std::endl;
}

void PolygonVect::draw(std::ofstream& out) const
{
	out<< "<svg version=\"1.1\"" << endl
		   << "baseProfile=\"full\" " << endl
		   << "xmlns=\"http://www.w3.org/2000/svg\">" << endl
		   << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\"" << endl;
	m_draw(out);
	out << "</svg>";
}
//indexing operators

PolygonVect::Point2D& PolygonVect::operator[](const int i) throw(std::out_of_range)
{
	return vectPoint2D.at(i);
}
const PolygonVect::Point2D& PolygonVect::operator[](const int i) const throw(std::out_of_range)
{
	return vectPoint2D.at(i);
}
//functions

double PolygonVect::perimeter() const
{ return getPerimeterOfPolygon(); }


PolygonVect& PolygonVect::operator++()
{
	setXCoor(getXCoor()+1);
	setYCoor(getYCoor()+1);
	return *this;
}

const PolygonVect& PolygonVect::operator++(int x)
{
	std::shared_ptr<PolygonVect> temp = std::make_shared<PolygonVect>(*this);
	++(*this);
	return *temp;
}

PolygonVect& PolygonVect::operator--()
{
	setXCoor(getXCoor()-1);
	setYCoor(getYCoor()-1);
	return *this;
}

const PolygonVect& PolygonVect::operator --(int x)
{
	std::shared_ptr<PolygonVect> temp = std::make_shared<PolygonVect>(*this);
	--(*this);
	return *temp;
}
} /* namespace hw5Comert */
