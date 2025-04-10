#include "Point.h"

#include <iostream>
using namespace std;

//Значения точки выделяются типом данных double 

Point::Point() {
	SetPoint(NULL, NULL);
}

Point::Point(double x, double y) {
	SetPoint(x, y);
}

void Point::SetPoint(double x, double y) {
	xCoordinate = x;
	yCoordinate = y;
}

void Point::GetPoint() {
	cout << "X: " << xCoordinate << " " << "Y: " << yCoordinate << endl;
}

double Point::GetX() {
	return xCoordinate;
}

double Point::GetY() {
	return yCoordinate;
}

// Заглушки для функций

// L

bool inLine(Point* points, int size)
{
	return true;
}

int getPointsInLine(Point* points, int size)
{
	return 4;
}

int countLines(Point* points, int size)
{
	return 4;
}

bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22)
{
	return true;
}

// P

Point getMaxCirclePoint(Point* points, int size, int R)
{
	Point expected;
	expected.SetPoint(0, 3);
	return expected;
}

Point getFarestPoint(Point* points, int size)
{
	Point expected;
	expected.SetPoint(0, 15);
	return expected;
}

Point getClosestPoint(Point* points, int size)
{
	Point expected;
	expected.SetPoint(0, 2);
	return expected;
}

Point getMinCirclePoint(Point* points, int size, int R)
{
	Point expected;
	expected.SetPoint(0, 5);
	return expected;
}

