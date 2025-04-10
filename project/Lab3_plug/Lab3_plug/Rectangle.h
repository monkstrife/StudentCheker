#pragma once
#include "Point.h"

class Rectangle {
private:
	//Точки прямоугольника
	Point p1;
	Point p2;
	Point p3;
	Point p4;

	
public:
	Rectangle();
	Rectangle(Point x, Point y, Point z, Point t);

	void SetRectangle(Point x, Point y, Point z, Point t);
	Point GetP1();
	Point GetP2();
	Point GetP3();
	Point GetP4();
};


// Rect

Rectangle* getMaxRectangle(Point* points, int size);
bool getRectangle(Point* points, Rectangle& figure);
void getClosestRectangles(Rectangle* figures, int size, Rectangle& f1, Rectangle& f2);
bool checkRectangleCrossing(const Rectangle& f1, const Rectangle& f2);
