#include "PolygonDyn.h"

using namespace std;

namespace hw5Comert {

PolygonDyn::PolygonDyn(): Polygon(),size(0)//useless
{
	arrPoint2D = new Point2D;
}

//copy constructor
PolygonDyn::PolygonDyn(const PolygonDyn& pDyn): Polygon(pDyn.p2DObj), size(pDyn.size)
{
	arrPoint2D = new Point2D[size];
	for(int i = 0; i < size; ++i)
	{
		arrPoint2D[i] = pDyn.arrPoint2D[i];
	}
}

PolygonDyn::PolygonDyn(const std::vector<Point2D>& vectPoint2D): Polygon()
{
	if((int) ((vectPoint2D.size())) != size) {
		delete[] arrPoint2D;
		size = vectPoint2D.size();
		arrPoint2D = new Point2D[size];
		for (int i = 0; i < size; ++i) {
			arrPoint2D[i] = vectPoint2D[i];
		}
	}

	for (int i = 0; i < size; ++i) {
		arrPoint2D[i] = vectPoint2D[i];
	}
}

PolygonDyn::PolygonDyn(const Point2D& p2D): Polygon(p2D), size(1)
{
	arrPoint2D = new Point2D[size];
	arrPoint2D[size - 1] = p2D;
}

PolygonDyn::PolygonDyn(const Rectangle& r) :Polygon(r.area(), r.perimeter()), size(4)
{
	arrPoint2D = new Point2D[size];
	arrPoint2D[0] = Point2D(r.getXCoor(), r.getYCoor());
	arrPoint2D[1] = Point2D(r.getXCoor() + r.getWidth(), r.getYCoor());
	arrPoint2D[2] = Point2D(r.getXCoor() + r.getWidth(),
			r.getYCoor() + r.getHeight());
	arrPoint2D[3] = Point2D(r.getXCoor(), r.getYCoor() + r.getHeight());
}

PolygonDyn::PolygonDyn(const Circle& c): Polygon(c.area(), c.perimeter()), size(100)
{
	int k = 0;
	arrPoint2D = new Point2D[size];
	for (double i = 0; i < 360; i += 3.6) {
		Point2D p2DObj(c.getXCoor() + c.getRadius() * sin(i * PI / 180),
				c.getYCoor() + c.getRadius() * cos(i * PI / 180));
		arrPoint2D[k++] = p2DObj;
	}
}

PolygonDyn::PolygonDyn(const Triangle& t, int status): Polygon(t.area(), t.perimeter()), size(3)
{
	arrPoint2D = new Point2D[size];
	if (status == 1)
	{
		Point2D p2D(t.getXCoor(), t.getYCoor());
		arrPoint2D[0] = p2D;
		Point2D p2D2(t.getXCoor() + t.getEdge()/2, t.getYCoor()+t.getEdge()*sqrt(3)/2);
		arrPoint2D[1] = p2D2;
		Point2D p2D3(t.getXCoor() - t.getEdge()/2, t.getYCoor()+t.getEdge()*sqrt(3)/2);
		arrPoint2D[2] = p2D3;
	}
	else if (status == 0)
	{
		Point2D p2D(0, 0);
		arrPoint2D[0] = p2D;
		Point2D p2D2(t.getEdge(), 0);
		arrPoint2D[1] = p2D2;
		Point2D p2D3(+ t.getEdge()/2, t.getEdge()*sqrt(3)/2);
		arrPoint2D[2] = p2D3;
	} else {
		cout << "Error in Triangle to PolygonDyn conversion constructor"
				<< endl;
		exit(1);
	}
}

PolygonDyn::Point2D& PolygonDyn::operator[](const int i) throw(std::out_of_range)
{
	if (i < 0 || i >= size) {
		throw std::out_of_range("");
	}
	return arrPoint2D[i];
}

const PolygonDyn::Point2D& PolygonDyn::operator[](const int i) const throw(std::out_of_range)
{
	if (i < 0 || i >= size) {
		throw std::out_of_range("");
	}
	return arrPoint2D[i];
}

/*bool PolygonDyn::operator==(const PolygonDyn& polyObj) const
{
	bool flag = true;
	if (size != polyObj.size) {
		return false;
	} else {
		for (int i = 0; i < size; ++i) {
			if (arrPoint2D[i] != polyObj.arrPoint2D[i]) {
				flag = false;
			}
		}

	}

	return flag;
}

bool PolygonDyn::operator!=(const PolygonDyn& polyObj) const
{
	return !(*this == polyObj);
}*/

PolygonDyn PolygonDyn::operator+(PolygonDyn polyObj)
{
	PolygonDyn tmpPoly;
	tmpPoly.size = size + polyObj.size;
	tmpPoly.arrPoint2D = new Point2D[tmpPoly.size];
	for (int i = 0; i < size; ++i) {
		tmpPoly.arrPoint2D[i] = arrPoint2D[i];
	}
	for (int i = size; i < size + polyObj.size; ++i) {
		tmpPoly.arrPoint2D[i] = polyObj.arrPoint2D[i];
	}
	return tmpPoly;
}
//assingment operator
PolygonDyn& PolygonDyn::operator=(const PolygonDyn& rhs) {
	if (*this == rhs) {
		return *this;
	}
	if (size != rhs.size) {
		size = rhs.size;
		delete arrPoint2D;
		arrPoint2D = new Point2D[size];
	}
	// deep copy
	for (int i = 0; i < size; ++i) {
		arrPoint2D[i] = rhs.arrPoint2D[i];
	}
	setAreaOfShape(rhs.area());
	return *this;
}

//functions
void PolygonDyn::draw(std::ofstream& out) const
{
	out << "<svg version=\"1.1\"" << endl
	    << "baseProfile=\"full\" " << endl
		<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
		<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\"" << endl;
	m_draw(out);
	out << "</svg>";
}

void PolygonDyn::m_draw(std::ofstream& out) const {
	out << "<polygon points = \"";
	for (int i = 0; i < size; ++i) {
		out << arrPoint2D[i].getX() << " " << arrPoint2D[i].getY() << ", ";
	}
	out << "\" fill = \"green\" stroke = \"yellow\" stroke-width = \"0.1\"/>"
			<< endl;
}

double PolygonDyn::perimeter() const
{
	return getPerimeterOfPolygon();
}
//destructor
PolygonDyn::~PolygonDyn()
{
	delete[] arrPoint2D;
}

PolygonDyn& PolygonDyn::operator ++()
{
	setXCoor(getXCoor()+1);
	setYCoor(getYCoor()+1);
	return *this;
}

const PolygonDyn& PolygonDyn::operator ++(int x)
{
	std::shared_ptr<PolygonDyn> temp = std::make_shared<PolygonDyn>(*this);
	++(*this);
	return *temp;
}

PolygonDyn& PolygonDyn::operator --()
{
	setXCoor(getXCoor()-1);
	setYCoor(getYCoor()-1);
	return *this;
}

const PolygonDyn& PolygonDyn::operator--(int x)
{
	std::shared_ptr<PolygonDyn> temp = std::make_shared<PolygonDyn>(*this);
	--(*this);
	return *temp;
}
} /* namespace hw5Comert */
