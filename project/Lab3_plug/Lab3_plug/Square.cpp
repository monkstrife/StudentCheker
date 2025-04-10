#include <iostream>
#include "Square.h"
#include "Point.h"
#include <cmath>

Square::Square() {
	p1 = Point();
	p2 = Point();
	p3 = Point();
	p3 = Point();
}

Square::Square(Point x, Point y, Point z, Point t) {
	SetSquare(x, y, z, t);
}

void Square::SetSquare(Point x, Point y, Point z, Point t) {
	p1 = x;
	p2 = y;
	p3 = z;
	p4 = t;
}

Point Square::GetP1() {
	return p1;
}

Point Square::GetP2() {
	return p2;
}

Point Square::GetP3() {
	return p3;
}

Point Square::GetP4() {
	return p4;
}

// Square

Square* getMaxSquare(Point* points, int size)
{
	Square* ret = new Square[1];
	ret[0].SetSquare(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));
	return ret;
}

bool getSquare(Point* points, Square& rectangle)
{
	rectangle = Square(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));
	return true;
}

void getClosestSquares(Square* rectangles, int size, Square& f1, Square& f2)
{
	f1 = rectangles[0];
	f2 = rectangles[1];
	return;
}

bool checkSquareCrossing(const Square& f1, const Square& f2)
{
	return true;
}