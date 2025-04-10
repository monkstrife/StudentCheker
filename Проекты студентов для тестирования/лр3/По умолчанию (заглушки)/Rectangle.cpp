#include <iostream>
#include "Rectangle.h"
#include "Point.h"
#include <cmath>

Rectangle::Rectangle() {
	p1 = Point();
	p2 = Point();
	p3 = Point();
	p3 = Point();
}

Rectangle::Rectangle(Point x, Point y, Point z, Point t) {
	SetRectangle(x, y, z, t);
}

void Rectangle::SetRectangle(Point x, Point y, Point z, Point t) {
	p1 = x;
	p2 = y;
	p3 = z;
	p4 = t;
}

Point Rectangle::GetP1() {
	return p1;
}

Point Rectangle::GetP2() {
	return p2;
}

Point Rectangle::GetP3() {
	return p3;
}

Point Rectangle::GetP4() {
	return p4;
}

// Rect

Rectangle* getMaxRectangle(Point* points, int size)
{
	Rectangle* ret = new Rectangle[1];
	ret[0].SetRectangle(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));
	return ret;
}

bool getRectangle(Point* points, Rectangle& rectangle)
{
	rectangle = Rectangle(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));
	return true;
}

void getClosestRectangles(Rectangle* rectangles, int size, Rectangle& f1, Rectangle& f2)
{
	f1 = rectangles[0];
	f2 = rectangles[1];
	return;
}

bool checkRectangleCrossing(const Rectangle& f1, const Rectangle& f2)
{
	return true;
}