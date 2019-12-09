#include "ComposedShape.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include <memory>

using namespace std;
using namespace hw5Comert;

class file_couldnt_opened: public exception
{};

ofstream& operator<<(ofstream& out, Shape* s)
{
	ComposedShape *cs;
	if((cs = dynamic_cast<ComposedShape*> (s)))//if Shape is a ComposedShape, we must call optimalFit before draw
	{
		cs->optimalFit();
		cs->draw(out);
	}
	else
		s->draw(out);
	return out;
}

void printAll(const vector<Shape*>& vectOfShape, int callingNum) throw (file_couldnt_opened)
{
	string str =  to_string(callingNum);

	ofstream out;
	for(unsigned int i = 0; i < vectOfShape.size(); ++i)
	{
		out.open("outputPrintAll" + to_string(callingNum) + "_" + to_string(i+1) + ".svg");
		if(!out.is_open())
			throw file_couldnt_opened();
		out << vectOfShape[i];
		out.close();
	}
}

void printPoly(const vector<Shape*>& vectOfShape) throw (file_couldnt_opened)
{
	Polygon *p;
	ofstream out;
	for(unsigned int i = 0; i < vectOfShape.size(); ++i)
	{
		if((p = dynamic_cast<Polygon*> (vectOfShape[i])))
		{
			out.open("outputPrintPoly" + to_string(i+1) + ".svg");
			if(!out.is_open())
				throw file_couldnt_opened();
			p->draw(out);
			out.close();
		}
	}
}

vector<Shape*> convertAll(const vector<Shape*>& vectOfShape) noexcept
{
	vector<Shape*> temp;
	Rectangle* r;
	Circle* c;
	Triangle* t;
	Polygon* p;
	for(unsigned int i= 0; i < vectOfShape.size(); ++i)
	{
		if((r = dynamic_cast<Rectangle*>(vectOfShape[i])))
		{
			p = new PolygonDyn(*r);
			temp.push_back(p);
		}
		else if((c = dynamic_cast<Circle*>(vectOfShape[i])))
		{
			p = new PolygonDyn(*c);
			temp.push_back(p);
		}
		else if((t = dynamic_cast<Triangle*>(vectOfShape[i])))
		{
			p = new PolygonDyn(*t);
			temp.push_back(p);
		}
	}
	//delete p;
	delete r;
	delete c;
	delete t;
	return temp;
}

void sortShapes(vector<Shape*>& vectOfShape) noexcept
{
	Shape* tmp;
	for (unsigned int i = 0; i < vectOfShape.size()-1; i++)
	{
		for (unsigned int j = 0; j < vectOfShape.size()-1-i; j++)
		{
			if ((*vectOfShape[j]) > (*vectOfShape[j+1]))
			{
				tmp = vectOfShape[j];
				vectOfShape[j] = vectOfShape[j+1];
				vectOfShape[j+1] = tmp;
			}
		}
	}
}

int main()
{
	vector<Shape*> vectShapePtr;
	vector<Shape*> vectShapePtr2;

	Rectangle *r = new Rectangle(100, 300);
	Circle *c = new Circle(100);
	Triangle *t = new Triangle(100);

	Rectangle *r2 = new Rectangle(10, 15);
	Circle *c2 = new Circle(10);
	Triangle *t2 = new Triangle(15);

	ComposedShape *cs = new ComposedShape(*r, *r2);
	ComposedShape *cs2 = new ComposedShape(*r, *c2);
	ComposedShape *cs3 = new ComposedShape(*r, *t2);
	ComposedShape *cs4 = new ComposedShape(*c, *r2);
	ComposedShape *cs5 = new ComposedShape(*c, *c2);
	ComposedShape *cs6 = new ComposedShape(*c, *t2);
	ComposedShape *cs7 = new ComposedShape(*t, *r2);
	ComposedShape *cs8 = new ComposedShape(*t, *c2);
	ComposedShape *cs9 = new ComposedShape(*t, *t2);

	PolygonDyn *pDyn = new PolygonDyn(*c);//output10.svg
	PolygonVect *pVect = new PolygonVect(*c);
	Polygon *p = new PolygonDyn(*t, 0);//ters üçgen
	Shape *s = new PolygonVect(*r);

	//push composed shapes
	vectShapePtr.push_back(cs);//output1.svg
	vectShapePtr.push_back(cs2);
	vectShapePtr.push_back(cs3);
	vectShapePtr.push_back(cs4);
	vectShapePtr.push_back(cs5);
	vectShapePtr.push_back(cs6);
	vectShapePtr.push_back(cs7);
	vectShapePtr.push_back(cs8);
	vectShapePtr.push_back(cs9);//output9.svg*/


	//convertable to Polygon
	vectShapePtr.push_back(c);//output10.svg
	vectShapePtr.push_back(t);
	vectShapePtr.push_back(r);
	vectShapePtr.push_back(r);
	vectShapePtr.push_back(t2);

	vectShapePtr.push_back(cs);
	vectShapePtr.push_back(pDyn);
	vectShapePtr.push_back(pVect);
	vectShapePtr.push_back(p);
	vectShapePtr.push_back(s);//output17.svg*/

	try{
		//prints outputPrintAll0_1 to prints outputPrintAll0_19
		printAll(vectShapePtr, 0);
		//prints outputPrintPoly16 to prints outputPrintAll19
		printPoly(vectShapePtr);
		//converts to polygons
		vectShapePtr2 = convertAll(vectShapePtr);
		//sorts respect to areas
		sortShapes(vectShapePtr2);
		//prints outputPrintAll1_1 to outputPrintAll1_5
		printAll(vectShapePtr2, 1);
		sortShapes(vectShapePtr);
		//prints  outputPrintAll2_1 to outputPrintAll1_19
		printAll(vectShapePtr, 2);
	}
	catch(exception& e)
	{
		cerr << "Caught: " << e.what() << endl
		     << "Type: " << typeid(e).name() << endl;
	}

	delete r;
	delete r2;
	delete c;
	delete c2;
	delete t;
	delete t2;
	delete cs;
	delete cs2;
	delete cs3;
	delete cs4;
	delete cs5;
	delete cs6;
	delete cs7;
	delete cs8;
	delete cs9;
	
	return 0;
}
