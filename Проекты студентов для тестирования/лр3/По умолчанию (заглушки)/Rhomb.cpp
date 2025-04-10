#include <iostream>
#include "Rhomb.h"
#include "Point.h"
#include <cmath>

Rhomb::Rhomb() {
	p1 = Point();
	p2 = Point();
	p3 = Point();
	p3 = Point();
}

Rhomb::Rhomb(Point x, Point y, Point z, Point t) {
	SetRhomb(x, y, z, t);
}

void Rhomb::SetRhomb(Point x, Point y, Point z, Point t) {
	p1 = x;
	p2 = y;
	p3 = z;
	p4 = t;
}


Point Rhomb::GetP1() {
	return p1;
}

Point Rhomb::GetP2() {
	return p2;
}

Point Rhomb::GetP3() {
	return p3;
}

Point Rhomb::GetP4() {
	return p4;
}

// Rhomb

Rhomb* getMaxRhomb(Point* points, int size)
{
	Rhomb* ret = new Rhomb[1];
	ret[0].SetRhomb(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));
	return ret;
}

bool getRhomb(Point* points, Rhomb& rectangle)
{
	rectangle = Rhomb(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));
	return true;
}

void getClosestRhombs(Rhomb* rectangles, int size, Rhomb& f1, Rhomb& f2)
{
	f1 = rectangles[0];
	f2 = rectangles[1];
	return;
}

bool checkRhombCrossing(const Rhomb& f1, const Rhomb& f2)
{
	return true;
}