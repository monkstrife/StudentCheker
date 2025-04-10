#include <iostream>
#include "Triangle.h"
#include "Point.h"
#include <cmath>

//В качестве координат класс Triangle принимает пользовательский тип данных Point(точки)

Triangle::Triangle() {
	p1 = Point();
	p2 = Point();
	p3 = Point();

	firstSide = NULL;
	secondSide = NULL;
	thirdSide = NULL;
}

Triangle::Triangle(Point x, Point y, Point z) {
	SetTriangle(x, y, z);
}

void Triangle::SetTriangle(Point x, Point y, Point z) {
	p1 = x;
	p2 = y;
	p3 = z;
	setSideLength();
}

//Изменения булевого значения равнобедренности
void Triangle::setIsIsosceles(bool s) {
	isIsosceles = s;
}

bool Triangle::getIsIsosceles() {
	return isIsosceles;
}

//Функция поиска длин сторон треугольника через формулу длины вектора
void Triangle::setSideLength() {
	firstSide = sqrt(pow((p1.GetX() - (p2.GetX())), 2) + pow((p1.GetY() - (p2.GetY())), 2));
	secondSide = sqrt(pow((p2.GetX() - (p3.GetX())), 2) + pow((p2.GetY() - (p3.GetY())), 2));
	thirdSide= sqrt(pow((p3.GetX() - (p1.GetX())), 2) + pow((p3.GetY() - (p1.GetY())), 2));
	//Если есть две одинаковых стороны, то треугольник равнобедренный
	if (((firstSide == secondSide)||(secondSide == thirdSide)||(thirdSide == firstSide)) && ((firstSide != 0) && (secondSide != 0) && (thirdSide != 0))) {
		setIsIsosceles(true);
	}
}

void Triangle::getSides() {
	std::cout << "\nДлина первой стороны: " << firstSide << "\nДлина второй стороны: " << secondSide << "\nДлина третьей стороны: " << thirdSide << std::endl;
}

void Triangle::getPoints() {
	p1.GetPoint();
	p2.GetPoint();
	p3.GetPoint();
}

// Func
int getRectTriangles(Triangle* t, int size)
{
	return 2;
}

int getIsoscelesTriangles(Triangle* t, int size)
{
	return 3;
}

Point* getMaxLengthTriangle(Point* points, int size)
{
	Point* ret = new Point[3];
	ret[0].SetPoint(0, 0);
	ret[1].SetPoint(0, 5);
	ret[2].SetPoint(10, 0);
	return ret;
}

Point* getMinLengthTriangle(Point* points, int size)
{
	Point* ret = new Point[3];
	ret[0].SetPoint(0, 0);
	ret[1].SetPoint(0, 5);
	ret[2].SetPoint(9, 0);
	return ret;
}

