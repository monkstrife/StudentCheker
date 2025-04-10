#pragma once
#include "Point.h"

class Trapeze {
private:
	//Точки трапеции
	Point p1;
	Point p2;
	Point p3;
	Point p4;


public:
	Trapeze();
	Trapeze(Point x, Point y, Point z, Point t);

	void SetTrapeze(Point x, Point y, Point z, Point t);
	Point GetP1();
	Point GetP2();
	Point GetP3();
	Point GetP4();
};

// Trapeze

Trapeze* getMaxTrapeze(Point* points, int size);
bool getTrapeze(Point* points, Trapeze& figure);
void getClosestTrapezes(Trapeze* figures, int size, Trapeze& f1, Trapeze& f2);
bool checkTrapezeCrossing(const Trapeze& f1, const Trapeze& f2);