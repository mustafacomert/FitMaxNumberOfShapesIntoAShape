#include "ComposedShape.h"
#include <typeinfo>
using namespace std;

namespace hw5Comert
{
//constructors
ComposedShape::ComposedShape() {}

ComposedShape::ComposedShape(Rectangle& rectCon, Rectangle& rectSmall)
: Shape(rectCon.getWidth()*rectCon.getHeight(), 0, 0), rectConObj(rectCon), rectSmallObj(rectSmall), type(0)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Rectangle &rectCon, Circle &circSmall)
:Shape(rectCon.getWidth()*rectCon.getHeight(), 0, 0), rectConObj(rectCon), circSmallObj(circSmall), type(1)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Rectangle &rectCon, Triangle &triSmall)
:Shape(rectCon.getWidth()*rectCon.getHeight(), 0, 0), rectConObj(rectCon), triSmallObj(triSmall), type(2)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Circle &circCon, Rectangle &rectSmall)
:Shape(PI*circCon.getRadius()*circCon.getRadius(), circCon.getRadius(), circCon.getRadius()),
 circConObj(circCon),rectSmallObj(rectSmall), type(3)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Circle &circCon, Circle &circSmall)
:Shape(PI*circCon.getRadius()*circCon.getRadius(), circCon.getRadius(), circCon.getRadius()),
 circConObj(circCon), circSmallObj(circSmall), type(4)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Circle &circCon, Triangle &triSmall)
:Shape(PI*circCon.getRadius()*circCon.getRadius(), circCon.getRadius(), circCon.getRadius()),
 circConObj(circCon), triSmallObj(triSmall), type(5)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Triangle& triCon, Rectangle& rectSmall)
:Shape(triCon.getEdge()*triCon.getEdge()*sqrt(3)/4, triCon.getEdge()/2, 0),
 triConObj(triCon),rectSmallObj(rectSmall), type(6)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Triangle& triCon, Circle& circSmall)
:Shape(triCon.getEdge()*triCon.getEdge()*sqrt(3)/4, triCon.getEdge()/2, 0),
 triConObj(triCon), circSmallObj(circSmall), type(7)
{/*intentionally left blank*/}

ComposedShape::ComposedShape(Triangle& triCon, Triangle& triSmall)
:Shape(triCon.getEdge()*triCon.getEdge()*sqrt(3)/4, triCon.getEdge()/2, 0),
 triConObj(triCon),triSmallObj(triSmall), type(8)
{/*intentionally left blank*/}

//functions
double ComposedShape::area() const
{
	/*double area;
	if(type == 0 || type == 1 || type == 2)
	{
		area = rectConObj.getWidth()*rectConObj.getHeight();
	}
	else if(type == 3 || type == 4 || type == 5)
	{
		area = PI*circConObj.getRadius()*circConObj.getRadius();
	}
	else if(type == 6 || type == 7 || type == 8)
	{
		area = triConObj.getEdge()*triConObj.getEdge()*sqrt(3)/4;
	}*/
	return getAreaOfShape();
}

double ComposedShape::perimeter() const
{
	double perimeter;
	if(type == 0 || type == 1 || type == 2)
	{
		perimeter = 2*(rectConObj.getWidth()+rectConObj.getHeight());
	}
	else if(type == 3 || type == 4 || type == 5)
	{
		perimeter = 2*PI*circConObj.getRadius();
	}
	else if(type == 6 || type == 7 || type == 8)
	{
		perimeter = 3*triConObj.getEdge();
	}
	return perimeter;
}
void ComposedShape::optimalFit()
{
	if(type == 0)
	{
		bool isRotate1; // if small shapes must rotate to a better fit, this is true;
		bool isRotate2;
		int num; //biggest one number of smallShapes fits into container
		double i, j;
		double x, y; // starting coordinates for emptyArea
		double emptyArea;
		double tmp;


		if(rectConObj.getWidth()*rectConObj.getHeight() <
		   rectSmallObj.getWidth()*rectSmallObj.getHeight())
		{
			cout << "I can't fit any small rectangle into this container(rectangle)"
				 << endl;
			return;
		}
		if(rectSmallObj.getWidth() < rectSmallObj.getHeight())// must be >= rectSmallObj.getHeight()
				{
			tmp = rectSmallObj.getHeight();
			rectSmallObj.setHeight(rectSmallObj.getWidth());
			rectSmallObj.setWidth(tmp);
		}
		if ((int) ((rectConObj.getWidth() / rectSmallObj.getWidth()))
				* (int) ((rectConObj.getHeight() / rectSmallObj.getHeight()))
				>= (int) ((rectConObj.getWidth() / rectSmallObj.getHeight()))
						* (int) ((rectConObj.getHeight()
								/ rectSmallObj.getWidth()))) {
			num =
					(int) ((rectConObj.getWidth() / rectSmallObj.getWidth()))
							* (int) ((rectConObj.getHeight()
									/ rectSmallObj.getHeight()));
			isRotate1 = false;
		} else {
			num =
					(int) ((rectConObj.getWidth() / rectSmallObj.getHeight()))
							* (int) ((rectConObj.getHeight()
									/ rectSmallObj.getWidth()));
			isRotate1 = true;
		}
		if (isRotate1) {
			for (j = 0; j < rectConObj.getHeight(); j +=
					rectSmallObj.getWidth()) {
				for (i = 0; i < rectConObj.getWidth();
						i += rectSmallObj.getHeight()) {
					if (!(rectConObj.getWidth() < i + rectSmallObj.getHeight()
							|| rectConObj.getHeight()
									< j + rectSmallObj.getWidth())) {
						Rectangle* small = new Rectangle(
								rectSmallObj.getHeight(),
								rectSmallObj.getWidth(), i, j);
						shapeVect.push_back(small);
					}
				}

			}

			isRotate2 = false;
			y = (rectConObj.getHeight() / rectSmallObj.getWidth())
					* rectSmallObj.getWidth();
		} else {
			for (j = 0; j < rectConObj.getHeight(); j +=
					rectSmallObj.getHeight()) {
				for (i = 0; i < rectConObj.getWidth();
						i += rectSmallObj.getWidth()) {
					if (!(rectConObj.getWidth() < i + rectSmallObj.getWidth()
							|| rectConObj.getHeight()
									< j + rectSmallObj.getHeight())) {
						Rectangle* small = new Rectangle(
								rectSmallObj.getWidth(),
								rectSmallObj.getHeight(), i, j);
						shapeVect.push_back(small);
					}
				}

			}

			isRotate2 = true;
			x = (rectConObj.getWidth() / rectSmallObj.getWidth())
					* rectSmallObj.getWidth(); //x coordinate
		}

		emptyArea = rectConObj.getHeight() * rectConObj.getWidth()
				- rectSmallObj.getWidth() * rectSmallObj.getHeight() * num;
		if (emptyArea != 0) {
			if (isRotate2) {
				for (int j = 0; j < rectConObj.getHeight();
						j += rectSmallObj.getWidth()) {
					for (int i = x; i < rectConObj.getWidth();
							i += rectSmallObj.getHeight()) {
						if (!(rectConObj.getWidth()
								< i + rectSmallObj.getHeight()
								|| rectConObj.getHeight()
										< j + rectSmallObj.getWidth())) {
							Rectangle* small = new Rectangle(
									rectSmallObj.getHeight(),
									rectSmallObj.getWidth(), i, j);
							shapeVect.push_back(small);
							++num;
						}
					}

				}

			} else {
				for (j = y; j < rectConObj.getHeight();
						j += rectSmallObj.getHeight()) {
					for (i = 0; i < rectConObj.getWidth();
							i += rectSmallObj.getWidth()) {
						if (!(rectConObj.getWidth()
								< i + rectSmallObj.getWidth()
								|| rectConObj.getHeight()
										< j + rectSmallObj.getHeight())) {
							Rectangle* small = new Rectangle(
									rectSmallObj.getWidth(),
									rectSmallObj.getHeight(), i, j);
							shapeVect.push_back(small);
							++num;
						}
					}

				}

			}

		}

		emptyArea = rectConObj.getWidth() * rectConObj.getHeight()
				- rectSmallObj.getWidth() * rectSmallObj.getHeight() * num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} //end of type0(rect into rect)

	if (type == 1) {
		if (rectConObj.getWidth() * rectConObj.getHeight()
				<= PI * circSmallObj.getRadius() * circSmallObj.getRadius()) {
			cout
					<< "I can't fit any small circle into this container(rectangle)"
					<< endl;
			return;
		}
		double emptyArea;
		int num;
		int num1 = 0;
		int num2 = 0;
		int r = 0;
		for (double j = circSmallObj.getRadius();
				j <= (rectConObj.getHeight() - circSmallObj.getRadius());
				j += 2 * circSmallObj.getRadius() * sqrt(3) / 2) {
			if (r % 2 == 0) {
				for (double i = circSmallObj.getRadius();
						i <= (rectConObj.getWidth() - circSmallObj.getRadius());
						i += 2 * circSmallObj.getRadius()) {
					++num1;
				}
			} else //r %2 == 1
			{
				for (double i = circSmallObj.getRadius() * 2;
						i <= (rectConObj.getWidth() - circSmallObj.getRadius());
						i += 2 * circSmallObj.getRadius()) {
					++num1;
				}
			}

			++r;
		}

		num2 =
				(int) (rectConObj.getWidth()) / (2 * circSmallObj.getRadius())
						>= (int) (rectConObj.getHeight())
								/ (2 * circSmallObj.getRadius()) ?
						(int) ((rectConObj.getWidth()
								/ (2 * circSmallObj.getRadius())))
								* (int) ((rectConObj.getHeight()
										/ (2 * circSmallObj.getRadius()))) :
						(int) ((rectConObj.getHeight()
								/ (2 * circSmallObj.getRadius())))
								* (int) ((rectConObj.getWidth()
										/ (2 * circSmallObj.getRadius())));
		if (num1 >= num2) {
			num = num1;
			for (double j = circSmallObj.getRadius();
					j <= (rectConObj.getHeight() - circSmallObj.getRadius());
					j += 2 * circSmallObj.getRadius() * sqrt(3) / 2) {
				if (r % 2 == 0) {
					for (double i = circSmallObj.getRadius();
							i
									<= (rectConObj.getWidth()
											- circSmallObj.getRadius());
							i += 2 * circSmallObj.getRadius()) {
						Circle* small = new Circle(circSmallObj.getRadius(), i,
								j);
						shapeVect.push_back(small);
					}
				} else //r %2 == 1
				{
					for (double i = circSmallObj.getRadius() * 2;
							i
									<= (rectConObj.getWidth()
											- circSmallObj.getRadius());
							i += 2 * circSmallObj.getRadius()) {
						Circle* small = new Circle(circSmallObj.getRadius(), i,
								j);
						shapeVect.push_back(small);
					}
				}

				++r;
			}

		} else {
			num = num2;
			for (double j = circSmallObj.getRadius();
					j <= (rectConObj.getHeight() - circSmallObj.getRadius());
					j += 2 * circSmallObj.getRadius()) {
				for (double i = circSmallObj.getRadius();
						i <= (rectConObj.getWidth() - circSmallObj.getRadius());
						i += 2 * circSmallObj.getRadius()) {
					Circle* small = new Circle(circSmallObj.getRadius(), i, j);
					shapeVect.push_back(small);
				}
			}

		}

		emptyArea = rectConObj.getHeight() * rectConObj.getWidth()
				- PI * circSmallObj.getRadius() * circSmallObj.getRadius()
						* num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} //end of type1(circ into rect)

	if (type == 2) {
		int r = 0;
		int num = 0;
		double emptyArea;
		for (double j = 0;
				j
						<= rectConObj.getHeight()
								- triSmallObj.getEdge() * sqrt(3) / 2;
				j += triSmallObj.getEdge() * sqrt(3) / 2) {
			if (r % 2 == 0) {
				for (double t = 0;
						t <= rectConObj.getWidth() - triSmallObj.getEdge(); t +=
								triSmallObj.getEdge()) {
					++num;
					Triangle* small = new Triangle(triSmallObj.getEdge(), t, j,
							0);
					shapeVect.push_back(small);
				}
				for (double d = triSmallObj.getEdge();
						d <= rectConObj.getWidth() - triSmallObj.getEdge() / 2;
						d += triSmallObj.getEdge()) {
					++num;
					Triangle* small = new Triangle(triSmallObj.getEdge(), d, j,
							1);
					shapeVect.push_back(small);
				}
			} else //r%2 == 1
			{
				for (double t = triSmallObj.getEdge() / 2;
						t <= rectConObj.getWidth() - triSmallObj.getEdge() / 2;
						t += triSmallObj.getEdge()) {
					++num;
					Triangle* small = new Triangle(triSmallObj.getEdge(), t, j,
							1);
					shapeVect.push_back(small);
				}
				for (double d = triSmallObj.getEdge() / 2;
						d <= rectConObj.getWidth() - triSmallObj.getEdge(); d +=
								triSmallObj.getEdge()) {
					++num;
					Triangle* small = new Triangle(triSmallObj.getEdge(), d, j,
							0);
					shapeVect.push_back(small);
				}
			}

			++r;
		}

		emptyArea = rectConObj.getWidth() * rectConObj.getHeight()
				- (triSmallObj.getEdge() * triSmallObj.getEdge() * sqrt(3) / 4)
						* num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} else if (type == 3) {
		bool isRotate1; // if small shapes must rotate to a better fit, this is true;
		bool isRotate2;
		int num; //biggest one number of smallShapes fits into container
		double i, j;
		double x, y; // starting coordinates for emptyArea
		double emptyArea;
		double containerWidth;
		double containerHeight;
		double xCoor, yCoor;
		double d1, d2, d3, d4;
		double tmp;
		//rectSmallObj.getWidth() must be > or = rectSmallObj.getHeight()
		if (rectSmallObj.getWidth() < rectSmallObj.getHeight()) {
			tmp = rectSmallObj.getHeight();
			rectSmallObj.setHeight(rectSmallObj.getWidth());
			rectSmallObj.setWidth(tmp);
		}
		containerWidth = circConObj.getRadius() * 2;
		containerHeight = circConObj.getRadius() * 2;
		xCoor = 0;
		yCoor = 0;
		if (numOfRC(circConObj.getRadius(), rectSmallObj.getWidth(),
				rectSmallObj.getHeight(), true)
				>= numOfRC(circConObj.getRadius(), rectSmallObj.getWidth(),
						rectSmallObj.getHeight(), false)) {
			num = numOfRC(circConObj.getRadius(), rectSmallObj.getWidth(),
					rectSmallObj.getHeight(), true);
			isRotate1 = true;
		} else {
			num = numOfRC(circConObj.getRadius(), rectSmallObj.getWidth(),
					rectSmallObj.getHeight(), false);
			isRotate1 = false;
		}
		if (isRotate1) {
			for (j = yCoor;
					j <= yCoor + containerHeight - rectSmallObj.getWidth(); j +=
							rectSmallObj.getWidth()) {
				for (i = xCoor;
						i <= xCoor + containerWidth - rectSmallObj.getHeight();
						i += rectSmallObj.getHeight()) {
					d1 = distanceTwoPoints(circConObj.getRadius(), i,
							circConObj.getRadius(), j);
					d2 = distanceTwoPoints(circConObj.getRadius(),
							i + rectSmallObj.getHeight(),
							circConObj.getRadius(), j);
					d3 = distanceTwoPoints(circConObj.getRadius(),
							i + rectSmallObj.getHeight(),
							circConObj.getRadius(),
							j + rectSmallObj.getWidth());
					d4 = distanceTwoPoints(circConObj.getRadius(), i,
							circConObj.getRadius(),
							j + rectSmallObj.getWidth());
					if (d1 <= circConObj.getRadius()
							&& d2 <= circConObj.getRadius()
							&& d3 <= circConObj.getRadius()
							&& d4 <= circConObj.getRadius()) {
						Rectangle* small = new Rectangle(
								rectSmallObj.getHeight(),
								rectSmallObj.getWidth(), i, j);
						shapeVect.push_back(small);
					}
				}

			}

			isRotate2 = false;
			y = yCoor
					+ (containerHeight / rectSmallObj.getWidth())
							* rectSmallObj.getWidth(); //y coordinate
		} else {
			for (j = yCoor;
					j <= yCoor + containerHeight - rectSmallObj.getHeight();
					j += rectSmallObj.getHeight()) {
				for (i = xCoor;
						i <= xCoor + containerWidth - rectSmallObj.getWidth();
						i += rectSmallObj.getWidth()) {
					d1 = distanceTwoPoints(circConObj.getRadius(), i,
							circConObj.getRadius(), j);
					d2 = distanceTwoPoints(circConObj.getRadius(),
							i + rectSmallObj.getWidth(), circConObj.getRadius(),
							j);
					d3 = distanceTwoPoints(circConObj.getRadius(),
							i + rectSmallObj.getWidth(), circConObj.getRadius(),
							j + rectSmallObj.getHeight());
					d4 = distanceTwoPoints(circConObj.getRadius(), i,
							circConObj.getRadius(),
							j + rectSmallObj.getHeight());
					if (d1 <= circConObj.getRadius()
							&& d2 <= circConObj.getRadius()
							&& d3 <= circConObj.getRadius()
							&& d4 <= circConObj.getRadius()) {
						Rectangle* small = new Rectangle(
								rectSmallObj.getWidth(),
								rectSmallObj.getHeight(), i, j);
						shapeVect.push_back(small);
					}
				}

			}

			isRotate2 = true;
			x = xCoor
					+ (containerWidth / rectSmallObj.getWidth())
							* rectSmallObj.getWidth(); //x coordinate
		}

		emptyArea = containerHeight * containerWidth
				- rectSmallObj.getWidth() * rectSmallObj.getHeight() * num;
		if (emptyArea != 0) {
			if (isRotate2) {
				for (int j = yCoor;
						j <= yCoor + containerHeight - rectSmallObj.getWidth();
						j += rectSmallObj.getWidth()) {
					for (int i = x;
							i <= containerWidth - rectSmallObj.getHeight(); i +=
									rectSmallObj.getHeight()) {
						d1 = distanceTwoPoints(circConObj.getRadius(), i,
								circConObj.getRadius(), j);
						d2 = distanceTwoPoints(circConObj.getRadius(),
								i + rectSmallObj.getHeight(),
								circConObj.getRadius(), j);
						d3 = distanceTwoPoints(circConObj.getRadius(),
								i + rectSmallObj.getHeight(),
								circConObj.getRadius(),
								j + rectSmallObj.getWidth());
						d4 = distanceTwoPoints(circConObj.getRadius(), i,
								circConObj.getRadius(),
								j + rectSmallObj.getWidth());
						if (d1 <= circConObj.getRadius()
								&& d2 <= circConObj.getRadius()
								&& d3 <= circConObj.getRadius()
								&& d4 <= circConObj.getRadius()) {
							Rectangle* small = new Rectangle(
									rectSmallObj.getHeight(),
									rectSmallObj.getWidth(), i, j);
							shapeVect.push_back(small);
						}
					}

				}

			} else {
				for (j = y; j <= containerHeight - rectSmallObj.getHeight();
						j += rectSmallObj.getHeight()) {
					for (i = xCoor;
							i
									<= xCoor + containerWidth
											- rectSmallObj.getWidth(); i +=
									rectSmallObj.getWidth()) {
						d1 = distanceTwoPoints(circConObj.getRadius(), i,
								circConObj.getRadius(), j);
						d2 = distanceTwoPoints(circConObj.getRadius(),
								i + rectSmallObj.getWidth(),
								circConObj.getRadius(), j);
						d3 = distanceTwoPoints(circConObj.getRadius(),
								i + rectSmallObj.getWidth(),
								circConObj.getRadius(),
								j + rectSmallObj.getHeight());
						d4 = distanceTwoPoints(circConObj.getRadius(), i,
								circConObj.getRadius(),
								j + rectSmallObj.getHeight());
						if (d1 <= circConObj.getRadius()
								&& d2 <= circConObj.getRadius()
								&& d3 <= circConObj.getRadius()
								&& d4 <= circConObj.getRadius()) {
							Rectangle* small = new Rectangle(
									rectSmallObj.getWidth(),
									rectSmallObj.getHeight(), i, j);
							shapeVect.push_back(small);
						}
					}

				}

			}

		}

		emptyArea = circConObj.getRadius() * circConObj.getRadius() * PI
				- rectSmallObj.getWidth() * rectSmallObj.getHeight() * num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} else if (type == 4) {
		if (circConObj.getRadius() < circSmallObj.getRadius()) {
			cout << "I can't fit any small shape into this container" << endl;
			return;
		}
		double emptyArea;
		double containerWidth = circConObj.getRadius() * 2;
		double containerHeight = circConObj.getRadius() * 2;
		double xCoor = 0;
		double yCoor = 0;
		double distance;
		int r = 0;
		int num = 0;
		for (double j = circSmallObj.getRadius() + yCoor;
				j <= (yCoor + containerHeight - circSmallObj.getRadius());
				j += 2 * circSmallObj.getRadius()) {
			if (r % 2 == 0) {
				for (double i = xCoor + circSmallObj.getRadius();
						i <= (xCoor + containerWidth - circSmallObj.getRadius());
						i += 2 * circSmallObj.getRadius()) {
					distance = distanceTwoPoints(circConObj.getRadius(), i,
							circConObj.getRadius(), j);
					if (distance
							<= circConObj.getRadius()
									- circSmallObj.getRadius()) {
						++num;
						Circle* small = new Circle(circSmallObj.getRadius(), i,
								j);
						shapeVect.push_back(small);
					}
				}

			} else //r %2 == 1
			{
				for (double i = xCoor + circSmallObj.getRadius() * 2;
						i
								<= (xCoor + circSmallObj.getRadius()
										+ containerWidth
										- circSmallObj.getRadius());
						i += 2 * circSmallObj.getRadius()) {
					distance = distanceTwoPoints(circConObj.getRadius(), i,
							circConObj.getRadius(), j);
					if (distance
							<= circConObj.getRadius()
									- circSmallObj.getRadius()) {
						++num;
						Circle* small = new Circle(circSmallObj.getRadius(), i,
								j);
						shapeVect.push_back(small);
					}
				}

			}

		}

		emptyArea = PI * circConObj.getRadius() * circConObj.getRadius()
				- PI * circSmallObj.getRadius() * circSmallObj.getRadius()
						* num;
		cout << std::fixed;
		cout << setprecision(3);
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} else if (type == 5) {
		double edge = triSmallObj.getEdge();
		double containerRadius = circConObj.getRadius();
		if (edge * edge * sqrt(3) / 4
				>= PI * containerRadius * containerRadius) {
			cout << "I can't fit any small shape into this container" << endl;
			return;
		}
		int r = 0;
		int num = 0;
		double emptyArea;
		double containerWidth = containerRadius * 2;
		double containerHeight = containerRadius * 2;
		double xCoor = 0;
		double yCoor = 0;
		double distance1;
		double distance2;
		double distance3;
		for (double j = yCoor;
				j <= yCoor + containerHeight - edge * sqrt(3) / 2;
				j += edge * sqrt(3) / 2) {
			if (r % 2 == 0) {
				for (double t = xCoor; t <= xCoor + containerWidth - edge; t +=
						edge) {
					distance1 = distanceTwoPoints(containerRadius, t,
							containerRadius, j);
					distance2 = distanceTwoPoints(containerRadius, t + edge,
							containerRadius, j);
					distance3 = distanceTwoPoints(containerRadius, edge / 2 + t,
							containerRadius, j + edge * sqrt(3) / 2);
					if (distance1 <= containerRadius
							&& distance2 <= containerRadius
							&& distance3 <= containerRadius) {
						++num;
						Triangle* small = new Triangle(edge, t, j, 0);
						shapeVect.push_back(small);
					}
				}

				for (double d = xCoor + edge;
						d <= xCoor + containerWidth - edge / 2; d += edge) {
					distance1 = distanceTwoPoints(containerRadius, d,
							containerRadius, j);
					distance2 = distanceTwoPoints(containerRadius, d + edge / 2,
							containerRadius, j + edge * sqrt(3) / 2);
					distance3 = distanceTwoPoints(containerRadius, d - edge / 2,
							containerRadius, j + edge * sqrt(3) / 2);
					if (distance1 <= containerRadius
							&& distance2 <= containerRadius
							&& distance3 <= containerRadius) {
						++num;
						Triangle* small = new Triangle(edge, d, j, 1);
						shapeVect.push_back(small);
					}
				}

			} else //r%2 == 1
			{
				for (double t = xCoor + edge / 2;
						t <= xCoor + containerWidth - edge / 2; t += edge) {
					distance1 = distanceTwoPoints(containerRadius, t,
							containerRadius, j);
					distance2 = distanceTwoPoints(containerRadius, t + edge / 2,
							containerRadius, j + edge * sqrt(3) / 2);
					distance3 = distanceTwoPoints(containerRadius, t - edge / 2,
							containerRadius, j + edge * sqrt(3) / 2);
					if (distance1 <= containerRadius
							&& distance2 <= containerRadius
							&& distance3 <= containerRadius) {
						++num;
						Triangle* small = new Triangle(edge, t, j, 1);
						shapeVect.push_back(small);
					}
				}

				for (double d = xCoor + edge / 2;
						d <= xCoor + containerWidth - edge; d += edge) {
					distance1 = distanceTwoPoints(containerRadius, d,
							containerRadius, j);
					distance2 = distanceTwoPoints(containerRadius, d + edge,
							containerRadius, j);
					distance3 = distanceTwoPoints(containerRadius, d + edge / 2,
							containerRadius, j + edge * sqrt(3) / 2);
					if (distance1 <= containerRadius
							&& distance2 <= containerRadius
							&& distance3 <= containerRadius) {
						++num;
						Triangle* small = new Triangle(edge, d, j, 0);
						shapeVect.push_back(small);
					}
				}

			}

			++r;
		}

		emptyArea = PI * containerRadius * containerRadius
				- (edge * edge * sqrt(3) / 4) * num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} else if (type == 6) {
		double smallShapeWidth = rectSmallObj.getWidth();
		double smallShapeHeight = rectSmallObj.getHeight();
		double containerEdge = triConObj.getEdge();
		bool isRotate1; // if small shapes must rotate to a better fit, this is true;
		bool isRotate2;
		int num = 0;
		double i, j;
		double x, y; // starting coordinates for emptyArea
		double emptyArea;
		double containerWidth;
		double containerHeight;
		double xCoor, yCoor;
		double tmp;
		double xCoorForA = 0.0;
		double yCoorForA = triConObj.getEdge() * sqrt(3) / 2;
		containerWidth = containerEdge;
		containerHeight = containerEdge * sqrt(3) / 2;
		xCoor = 0.0;
		yCoor = 0.0;
		if (smallShapeWidth < smallShapeHeight) {
			tmp = smallShapeHeight;
			rectSmallObj.setHeight(smallShapeWidth);
			rectSmallObj.setWidth(tmp);
		}
		if ((int) ((containerWidth / smallShapeWidth))
				* (int) ((containerHeight / smallShapeHeight))
				>= (int) ((containerWidth / smallShapeHeight))
						* (int) ((containerHeight / smallShapeWidth))) {
			isRotate1 = false;
		} else {
			isRotate1 = true;
		}
		if (isRotate1) {
			for (j = yCoor; j <= yCoor + containerHeight - smallShapeWidth; j +=
					smallShapeWidth) {
				for (i = xCoor; i <= xCoor + containerWidth - smallShapeHeight;
						i += smallShapeHeight) {
					if (CompareSlopeOfLine(xCoorForA, yCoorForA, i, j)
							&& CompareSlopeOfLine(xCoorForA, yCoorForA,
									i + smallShapeWidth, j)) {
						Rectangle* small = new Rectangle(smallShapeHeight,
								smallShapeWidth, i, j);
						shapeVect.push_back(small);
						++num;
					}
				}

			}

			isRotate2 = false;
			y = yCoor + (containerHeight / smallShapeWidth) * smallShapeWidth; //y coordinate
		} else {
			for (j = yCoor; j <= yCoor + containerHeight - smallShapeHeight;
					j += smallShapeHeight) {
				for (i = xCoor; i <= xCoor + containerWidth - smallShapeWidth;
						i += smallShapeWidth) {
					if (CompareSlopeOfLine(xCoorForA, yCoorForA, i, j)
							&& CompareSlopeOfLine(xCoorForA, yCoorForA,
									i + smallShapeWidth, j)) {
						Rectangle* small = new Rectangle(smallShapeWidth,
								smallShapeHeight, i, j);
						shapeVect.push_back(small);
						++num;
					}
				}

			}

			isRotate2 = true;
			x = xCoor + (containerWidth / smallShapeWidth) * smallShapeWidth; //x coordinate
		}

		emptyArea = containerHeight * containerWidth
				- smallShapeWidth * smallShapeHeight * num;
		if (emptyArea != 0) {
			if (isRotate2) {
				for (int j = yCoor;
						j <= yCoor + containerHeight - smallShapeWidth; j +=
								smallShapeWidth) {
					for (int i = x; i <= containerWidth - smallShapeHeight; i +=
							smallShapeHeight) {
						{
							if (CompareSlopeOfLine(xCoorForA, yCoorForA, i, j)
									&& CompareSlopeOfLine(xCoorForA, yCoorForA,
											i + smallShapeWidth, j)) {
								Rectangle* small = new Rectangle(
										smallShapeHeight, smallShapeWidth, i,
										j);
								shapeVect.push_back(small);
								++num;
							}
						}
					}

				}

			} else {
				for (j = y; j <= containerHeight - smallShapeHeight; j +=
						smallShapeHeight) {
					for (i = xCoor;
							i <= xCoor + containerWidth - smallShapeWidth; i +=
									smallShapeWidth) {
						{
							if (CompareSlopeOfLine(xCoorForA, yCoorForA, i, j)
									&& CompareSlopeOfLine(xCoorForA, yCoorForA,
											i + smallShapeWidth, j)) {
								Rectangle* small = new Rectangle(
										smallShapeWidth, smallShapeHeight, i,
										j);
								shapeVect.push_back(small);
								++num;
							}
						}
					}

				}

			}

		}

		emptyArea = containerEdge * containerEdge * sqrt(3) / 4
				- smallShapeWidth * smallShapeHeight * num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} else if (type == 7) {
		int num = 0;
		double emptyArea;
		double containerWidth;
		double containerHeight;
		double xCoor;
		double yCoor;
		double xCoorForA = 0.0;
		double yCoorForA = triConObj.getEdge() * sqrt(3) / 2;
		double r45 = circSmallObj.getRadius() / sqrt(2);
		containerWidth = triConObj.getEdge();
		containerHeight = triConObj.getEdge() * sqrt(3) / 2;
		xCoor = 0;
		yCoor = 0;
		for (double j = circSmallObj.getRadius() + yCoor;
				j <= (yCoor + containerHeight - circSmallObj.getRadius());
				j += 2 * circSmallObj.getRadius()) {
			for (double i = xCoor + circSmallObj.getRadius();
					i <= (xCoor + containerWidth - circSmallObj.getRadius());
					i += 2 * circSmallObj.getRadius()) {
				if (CompareSlopeOfLine(xCoorForA, yCoorForA, i, j)
						&& CompareSlopeOfLine(xCoorForA, yCoorForA, i - r45,
								j - r45)
						&& CompareSlopeOfLine(xCoorForA, yCoorForA, i - r45,
								j + r45)
						&& CompareSlopeOfLine(xCoorForA, yCoorForA, i + r45,
								j - r45)
						&& CompareSlopeOfLine(xCoorForA, yCoorForA, i + r45,
								j + r45)) {
					Circle* small = new Circle(circSmallObj.getRadius(), i, j);
					shapeVect.push_back(small);
					++num;
				}
			}

		}

		emptyArea = triConObj.getEdge() * triConObj.getEdge() * sqrt(3) / 4
				- PI * circSmallObj.getRadius() * circSmallObj.getRadius()
						* num;
		cout << "I can fit at most " << num
				<< " small shapes into the main container. The empty area(red) in"
				<< endl << "container is " << emptyArea << "." << endl;
	} else if (type == 8) {
		double emptyArea;
		double containerWidth;
		double containerHeight;
		double xCoor;
		double yCoor;
		double xCoorForA = 0.0;
		double yCoorForA = triConObj.getEdge();
		int num = 0;
		int r = 0;
		double edge = triSmallObj.getEdge();
		double h = triSmallObj.getEdge() * sqrt(3) / 2;
		containerWidth = triConObj.getEdge();
		containerHeight = triConObj.getEdge() * sqrt(3) / 2;
		xCoor = 0.0;
		yCoor = 0.0;
		for (double j = yCoor; j <= yCoor + containerHeight - triSmallObj.getEdge() * sqrt(3) / 2;
			 j += triSmallObj.getEdge() * sqrt(3) / 2)
		{
			if (r % 2 == 0)
			{
				for (double t = xCoor; t <= xCoor + containerWidth - triSmallObj.getEdge();
					 t += triSmallObj.getEdge())
				{
					if (CompareSlopeOfLine(xCoorForA, yCoorForA, t, j) &&
						CompareSlopeOfLine(xCoorForA, yCoorForA, t + edge, j))
					{
						++num;
						Triangle* small = new Triangle(triSmallObj.getEdge(), t, j, 0);
						shapeVect.push_back(small);
					}
				}

				for (double d = xCoor + triSmallObj.getEdge();
					 d <= xCoor + containerWidth - triSmallObj.getEdge() / 2;
					 d += triSmallObj.getEdge())
				{
					if (CompareSlopeOfLine(xCoorForA, yCoorForA, d - edge / 2, j + h) &&
						CompareSlopeOfLine(xCoorForA, yCoorForA, d + edge / 2, j + h))
					{
						++num;
						Triangle* small = new Triangle(triSmallObj.getEdge(), d, j, 1);
						shapeVect.push_back(small);
					}
				}

			}
			else //r%2 == 1
			{
				for (double t = xCoor + triSmallObj.getEdge() / 2;
					 t <= xCoor + containerWidth - triSmallObj.getEdge() / 2;
					 t += triSmallObj.getEdge())
				{
					if (CompareSlopeOfLine(xCoorForA, yCoorForA, t, j) &&
						CompareSlopeOfLine(xCoorForA, yCoorForA, t + edge, j))
					{
						++num;
						Triangle* small = new Triangle(triSmallObj.getEdge(), t, j, 1);
						shapeVect.push_back(small);
					}
				}

				for (double d = xCoor + triSmallObj.getEdge() / 2;
					 d <= xCoor + containerWidth - triSmallObj.getEdge();
					 d += triSmallObj.getEdge())
				{
					if (CompareSlopeOfLine(xCoorForA, yCoorForA, d - edge / 2, j + h) &&
						CompareSlopeOfLine(xCoorForA, yCoorForA, d + edge / 2, j + h))
					{
						++num;
						Triangle* small = new Triangle(triSmallObj.getEdge(), d, j, 0);
						shapeVect.push_back(small);
					}
				}

			}
			++r;
		}

		emptyArea = triConObj.getEdge() * triConObj.getEdge() * sqrt(3) / 4
					- (triSmallObj.getEdge() * triSmallObj.getEdge() * sqrt(3) / 4)
						* num;
		cout << "I can fit at most " << num
			<< " small shapes into the main container. The empty area(red) in"
			<< endl << "container is " << emptyArea << "." << endl;
	}

}

void ComposedShape::draw(ofstream& out) const {
	if (type == 0)
	{
		out << "<svg version=\"1.1\"" << endl
			<< "baseProfile=\"full\"" << endl
			<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
			<< "<rect width=\"" << rectConObj.getWidth() << "\" height=\""
			<< rectConObj.getHeight() << "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect)
		{
			x->m_draw(out); // this calls operator<< in class Rectangle
		}
		out << "</svg>" << endl;
		out.close();
	}
	else if (type == 1)
	{
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<rect width=\"" << rectConObj.getWidth() << "\" height=\""
				<< rectConObj.getHeight() << "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect)
		{
			x->m_draw(out);
		}
	}
	else if (type == 2)
	{
		out << "<svg version=\"1.1\"" << endl
			<< "baseProfile=\"full\"" << endl
			<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
			<< "<rect width=\"" << rectConObj.getWidth() << "\" height=\""
			<<  rectConObj.getHeight() << "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect)
		{
			x->m_draw(out);
		}
	} else if (type == 3) {
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<circle cx = \"" << circConObj.getRadius()
				<< "\" cy = \"" << circConObj.getRadius() << "\" r = \""
				<< circConObj.getRadius() << "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect) {
			x->m_draw(out);
		}
	} else if (type == 4) {
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<circle cx = \"" << circConObj.getRadius()
				<< "\" cy = \"" << circConObj.getRadius() << "\" r = \""
				<< circConObj.getRadius() << "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect) {
			x->m_draw(out);
		}
	} else if (type == 5) {
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<circle cx = \"" << circConObj.getRadius()
				<< "\" cy = \"" << circConObj.getRadius() << "\" r = \""
				<< circConObj.getRadius() << "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect) {
			x->m_draw(out);
		}
	} else if (type == 6) {
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<polygon points = \"0 "
				<< triConObj.getEdge() * sqrt(3) / 2 << ", "
				<< triConObj.getEdge() / 2 << " 0, " << triConObj.getEdge()
				<< " " << triConObj.getEdge() * sqrt(3) / 2
				<< "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect) {
			x->m_draw(out);
		}
	} else if (type == 7) {
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<polygon points = \"0 "
				<< triConObj.getEdge() * sqrt(3) / 2 << ", "
				<< triConObj.getEdge() / 2 << " 0, " << triConObj.getEdge()
				<< " " << triConObj.getEdge() * sqrt(3) / 2
				<< "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect) {
			x->m_draw(out);
		}
	} else if (type == 8) {
		out << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl
				<< "<polygon points = \"0 " << triConObj.getEdge() * sqrt(3) / 2 << ", "
				<< triConObj.getEdge() / 2 << " 0, " << triConObj.getEdge()
				<< " " << triConObj.getEdge() * sqrt(3) / 2
				<< "\" fill = \"red\"/>" << endl;
		for (auto x : shapeVect) {
			x->m_draw(out);
		}
	}

	out << "</svg>" << endl;
	out.close();
}

//comparison
/*
bool ComposedShape::operator ==(const Shape& other) const {
	return (this->area() == other.area()) ? true : false;
}

bool ComposedShape::operator !=(const Shape& other) const {
	return (!(*this == other)) ? true : false; // i like to call one operator overloading in the other
}

bool ComposedShape::operator <(const Shape& other) const {
	return (this->area() < other.area()) ? true : false;
}

bool ComposedShape::operator >(const Shape& other) const {
	return (this->area() > other.area()) ? true : false;
}

bool ComposedShape::operator <=(const Shape& other) const {
	return (this->area() <= other.area()) ? true : false;
}

bool ComposedShape::operator >=(const Shape& other) const {
	return (this->area() >= other.area()) ? true : false;
}*/

double ComposedShape::distanceTwoPoints(double x1, double x2, double y1,
		double y2) const {
	double distance;
	distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return distance;
}

int ComposedShape::numOfRC(double containerRadius, double smallShapeWidth,
		double smallShapeHeight, bool rotate) const {
	bool isRotate1 = rotate; // if small shapes must rotate to a better fit, this is true;
	bool isRotate2 = !(rotate);
	int num = 0;
	double i, j;
	double x, y; // starting coordinates for emptyArea
	double emptyArea;
	double containerWidth;
	double containerHeight;
	double xCoor, yCoor;
	double d1, d2, d3, d4;
	double tmp;
	if (smallShapeWidth < smallShapeHeight) {
		tmp = smallShapeHeight;
		smallShapeHeight = smallShapeWidth;
		smallShapeWidth = tmp;
	}
	containerWidth = containerRadius * 2;
	containerHeight = containerRadius * 2;
	xCoor = 0;
	yCoor = 0;
	if (isRotate1) {
		for (j = yCoor; j <= yCoor + containerHeight - smallShapeWidth; j +=
				smallShapeWidth) {
			for (i = xCoor; i <= xCoor + containerWidth - smallShapeHeight; i +=
					smallShapeHeight) {
				d1 = distanceTwoPoints(containerRadius, i, containerRadius, j);
				d2 = distanceTwoPoints(containerRadius, i + smallShapeHeight,
						containerRadius, j);
				d3 = distanceTwoPoints(containerRadius, i + smallShapeHeight,
						containerRadius, j + smallShapeWidth);
				d4 = distanceTwoPoints(containerRadius, i, containerRadius,
						j + smallShapeWidth);
				if (d1 <= containerRadius && d2 <= containerRadius
						&& d3 <= containerRadius && d4 <= containerRadius) {
					++num;
				}
			}

		}

		isRotate2 = false;
		y = yCoor + (containerHeight / smallShapeWidth) * smallShapeWidth; //y coordinate
	} else {
		for (j = yCoor; j <= yCoor + containerHeight - smallShapeHeight; j +=
				smallShapeHeight) {
			for (i = xCoor; i <= xCoor + containerWidth - smallShapeWidth; i +=
					smallShapeWidth) {
				d1 = distanceTwoPoints(containerRadius, i, containerRadius, j);
				d2 = distanceTwoPoints(containerRadius, i + smallShapeWidth,
						containerRadius, j);
				d3 = distanceTwoPoints(containerRadius, i + smallShapeWidth,
						containerRadius, j + smallShapeHeight);
				d4 = distanceTwoPoints(containerRadius, i, containerRadius,
						j + smallShapeHeight);
				if (d1 <= containerRadius && d2 <= containerRadius
						&& d3 <= containerRadius && d4 <= containerRadius) {
					++num;
				}
			}

		}

		isRotate2 = true;
		x = xCoor + (containerWidth / smallShapeWidth) * smallShapeWidth; //x coordinate
	}

	emptyArea = containerHeight * containerWidth
			- smallShapeWidth * smallShapeHeight * num;
	if (emptyArea != 0) {
		if (isRotate2) {
			for (int j = yCoor; j <= yCoor + containerHeight - smallShapeWidth;
					j += smallShapeWidth) {
				for (int i = x; i <= containerWidth - smallShapeHeight; i +=
						smallShapeHeight) {
					d1 = distanceTwoPoints(containerRadius, i, containerRadius,
							j);
					d2 = distanceTwoPoints(containerRadius,
							i + smallShapeHeight, containerRadius, j);
					d3 = distanceTwoPoints(containerRadius,
							i + smallShapeHeight, containerRadius,
							j + smallShapeWidth);
					d4 = distanceTwoPoints(containerRadius, i, containerRadius,
							j + smallShapeWidth);
					if (d1 <= containerRadius && d2 <= containerRadius
							&& d3 <= containerRadius && d4 <= containerRadius) {
						++num;
					}
				}

			}

		} else {
			for (j = y; j <= containerHeight - smallShapeHeight; j +=
					smallShapeHeight) {
				for (i = xCoor; i <= xCoor + containerWidth - smallShapeWidth;
						i += smallShapeWidth) {
					d1 = distanceTwoPoints(containerRadius, i, containerRadius,
							j);
					d2 = distanceTwoPoints(containerRadius, i + smallShapeWidth,
							containerRadius, j);
					d3 = distanceTwoPoints(containerRadius, i + smallShapeWidth,
							containerRadius, j + smallShapeHeight);
					d4 = distanceTwoPoints(containerRadius, i, containerRadius,
							j + smallShapeHeight);
					if (d1 <= containerRadius && d2 <= containerRadius
							&& d3 <= containerRadius && d4 <= containerRadius) {
						++num;
					}
				}

			}

		}

	}

	return num;
}
//increment drcrement operators
ComposedShape& ComposedShape::operator++()//prefix
{
	setXCoor(getXCoor()+1);
	setYCoor(getYCoor()+1);
	return *this;
}
const ComposedShape& ComposedShape::operator++(int x)//postfix
{
	std::shared_ptr<ComposedShape> temp = std::make_shared<ComposedShape>(*this);
	++(*this);
	return *temp;
}

ComposedShape& ComposedShape::operator--()
{
	setXCoor(getXCoor()-1);
	setYCoor(getYCoor()-1);
	return *this;
}

const ComposedShape& ComposedShape::operator --(int x)
{
	std::shared_ptr<ComposedShape> temp = std::make_shared<ComposedShape>(*this); // copy constructor
	++(*this);
	return *temp;
}

bool ComposedShape::CompareSlopeOfLine(double x1, double y1, double x2,
		double y2) const {
	//2 noktası bilinen doğrunun eğimi normalde (y1 - y2)/(x1-x2) şeklindedir.
	//fakat svg' de y koordinati ters olduğu için (y2 - y1)/(x1-x2) formunda hesapladim.
	// Yukarıdakini ve tan fonksiyonun radyan aldigini fark etmem 4 saat sürdü.
	bool flag = (x2 < triConObj.getEdge() / 2);
	if (flag && (x1 - x2) && (y2 - y1) / (x1 - x2) <= tan(60 * PI / 180.0)) {
		return true;
	} else if (!flag && (x1 + triConObj.getEdge() - x2)
			&& (y2 - y1) / (x1 + triConObj.getEdge() - x2)
					>= tan(-60 * PI / 180.0))
	{
		return true;
	}

	else
	{
		return false;
	}
}
//overloadings
/*std::ofstream& operator<<(std::ofstream &out, const ComposedShape &composed)
{
	/
	return out;
}*/

ComposedShape& ComposedShape::operator+=(const ComposedShape& other)
{
	for(unsigned i = 0; i < other.shapeVect.size(); ++i)
	{
		this->shapeVect.push_back(other.shapeVect[i]);
	}
	return *this;
}
}/*namespace*/
