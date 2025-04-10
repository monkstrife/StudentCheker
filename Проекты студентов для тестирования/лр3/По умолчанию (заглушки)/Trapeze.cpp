#include <iostream>
#include "Trapeze.h"
#include "Point.h"
#include <cmath>

Trapeze::Trapeze() {
	p1 = Point();
	p2 = Point();
	p3 = Point();
	p3 = Point();
}

Trapeze::Trapeze(Point x, Point y, Point z, Point t) {
	SetTrapeze(x, y, z, t);
}

void Trapeze::SetTrapeze(Point x, Point y, Point z, Point t) {
	p1 = x;
	p2 = y;
	p3 = z;
	p4 = t;
}

Point Trapeze::GetP1() {
	return p1;
}

Point Trapeze::GetP2() {
	return p2;
}

Point Trapeze::GetP3() {
	return p3;
}

Point Trapeze::GetP4() {
	return p4;
}

// Trapeze

Trapeze* getMaxTrapeze(Point* points, int size)
{
	Trapeze* ret = new Trapeze[1];
	ret[0].SetTrapeze(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));
	return ret;
}

bool getTrapeze(Point* points, Trapeze& rectangle)
{
	rectangle = Trapeze(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));
	return true;
}

void getClosestTrapezes(Trapeze* rectangles, int size, Trapeze& f1, Trapeze& f2)
{
	f1 = rectangles[0];
	f2 = rectangles[1];
	return;
}

bool checkTrapezeCrossing(const Trapeze& f1, const Trapeze& f2)
{
	return true;
}