#pragma once
#include "Point.h"

class Square {
private:
	//Точки квадрата
	Point p1;
	Point p2;
	Point p3;
	Point p4;


public:
	Square();
	Square(Point x, Point y, Point z, Point t);

	void SetSquare(Point x, Point y, Point z, Point t);
	Point GetP1();
	Point GetP2();
	Point GetP3();
	Point GetP4();
};

// Square

Square* getMaxSquare(Point* points, int size);
bool getSquare(Point* points, Square& figure);
void getClosestSquares(Square* figures, int size, Square& f1, Square& f2);
bool checkSquareCrossing(const Square& f1, const Square& f2);