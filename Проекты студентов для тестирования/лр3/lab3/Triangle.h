#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h" // ���������� ����������� ������ Point
#include <vector>

using namespace std;

class Triangle {
private:
    Point a, b, c; // ��� �����, ���������� �����������

public:
    Triangle(const Point& a, const Point& b, const Point& c); // �����������
    float area() const; // ����� ��� ���������� ������� ������������
    float perimeter() const; // ����� ��� ���������� ��������� ������������
    const Point& getA() const; // ������ ��� ����� A
    const Point& getB() const; // ������ ��� ����� B
    const Point& getC() const; // ������ ��� ����� C

};

vector<Triangle> createTrianglesFromPoints(int& size); // ������� ������������

void printTriangles(const vector<Triangle>& triangles);//������� ������ �������������

float sideLength(const Point& a, const Point& b); // ������� ��� ���������� ����� ������� ������������

bool isIsosceles(const Triangle& t); // ������� ��� ��������, �������� �� ����������� ��������������

vector<Triangle> findIsoscelesTriangles(const vector<Triangle>& triangles); // ���������� �������������� ������������� � �������.

#endif // TRIANGLE_H