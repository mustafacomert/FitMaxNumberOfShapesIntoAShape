#Mustafa Cömert 151044028 hw5
CC = g++
STD = -std=c++11
FLAGS = -c -Wall

all: hw5

hw5: main.o Circle.o Triangle.o ComposedShape.o Rectangle.o Shape.o Polygon.o PolygonDyn.o PolygonVect.o
	$(CC) $(STD) main.o Circle.o Triangle.o ComposedShape.o Rectangle.o Shape.o Polygon.o PolygonDyn.o PolygonVect.o -o hw5

main.o: main.cpp ComposedShape.h
	$(CC) $(STD) $(FLAGS) main.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CC) $(STD) $(FLAGS) Rectangle.cpp

Circle.o: Circle.cpp Circle.h
	$(CC) $(STD) $(FLAGS) Circle.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CC) $(STD) $(FLAGS) Triangle.cpp

ComposedShape.o: ComposedShape.cpp ComposedShape.h
	$(CC) $(STD) $(FLAGS) ComposedShape.cpp

Shape.o: Shape.cpp Shape.h
	$(CC) $(STD) $(FLAGS) Shape.cpp

Polygon.o: Polygon.cpp Polygon.h
	$(CC) $(STD) $(FLAGS) Polygon.cpp

PolygonDyn.o: PolygonDyn.cpp PolygonDyn.h
	$(CC) $(STD) $(FLAGS) PolygonDyn.cpp

PolygonVect.o: PolygonVect.cpp PolygonVect.h
	$(CC) $(STD) $(FLAGS) PolygonVect.cpp
clean:
	rm -rf *o hw5

run:
	./hw5
