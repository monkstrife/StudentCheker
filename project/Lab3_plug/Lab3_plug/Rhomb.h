#pragma once
#include "Point.h"

class Rhomb {
private:
	//Точки ромба
	Point p1;
	Point p2;
	Point p3;
	Point p4;


public:
	Rhomb();
	Rhomb(Point x, Point y, Point z, Point t);

	void SetRhomb(Point x, Point y, Point z, Point t);
	Point GetP1();
	Point GetP2();
	Point GetP3();
	Point GetP4();
};

// Rhomb

Rhomb* getMaxRhomb(Point* points, int size);
bool getRhomb(Point* points, Rhomb& figure);
void getClosestRhombs(Rhomb* figures, int size, Rhomb& f1, Rhomb& f2);
bool checkRhombCrossing(const Rhomb& f1, const Rhomb& f2);
