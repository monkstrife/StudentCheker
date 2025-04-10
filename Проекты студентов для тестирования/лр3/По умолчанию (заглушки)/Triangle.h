#pragma once
#include "Point.h"

class Triangle {
	private:
		//����� ������������
		Point p1;
		Point p2;
		Point p3;

		//����� ������
		double firstSide;
		double secondSide;
		double thirdSide;

		//������� �������� ����������������
		bool isIsosceles = false;
	public:
		Triangle();
		Triangle(Point x, Point y, Point z);

		void SetTriangle(Point x, Point y, Point z);
		void setIsIsosceles(bool s);
		void setSideLength();
		void getSides();
		void getPoints();

		bool getIsIsosceles();
};

// T
int getRectTriangles(Triangle* t, int size);
int getIsoscelesTriangles(Triangle* t, int size);
Point* getMaxLengthTriangle(Point* points, int size);
Point* getMinLengthTriangle(Point* points, int size);

// F

