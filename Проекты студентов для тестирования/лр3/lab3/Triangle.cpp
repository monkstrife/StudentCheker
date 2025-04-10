#include "Triangle.h"
#include <cmath> 
#include <cstdlib> 
#include <ctime>   
#include <iostream>


Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {} // ������������� ����� ������������

float Triangle::area() const {
    // ���������� ���������� ������� ������������ �� ������� ������
    float ab = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2)); 
    float bc = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getY() - c.getY(), 2)); 
    float ca = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2)); 
    float s = (ab + bc + ca) / 2; // ��������� ������������
    return sqrt(s * (s - ab) * (s - bc) * (s - ca)); // ���������� �������
}

float Triangle::perimeter() const {
    // ���������� ���������� ��������� ������������

    float ab = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2)); 
    float bc = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getY() - c.getY(), 2)); 
    float ca = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2)); 
    return ab + bc + ca; 
}

const Point& Triangle::getA() const {
    return a; 
}
const Point& Triangle::getB() const {
    return b; 
}
const Point& Triangle::getC() const {
    return c; 
}

// ������� ������������
vector<Triangle> createTrianglesFromPoints(int& size) {

    vector<Triangle> triangles;
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++) {
              
        float x1 = rand() % 100;
        float x2 = rand() % 100;
        float x3 = rand() % 100;
        float y1 = rand() % 100;
        float y2 = rand() % 100;
        float y3 = rand() % 100;

        triangles.push_back(Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3)));
    }
    return triangles;
}

//������� ������ �������������
void printTriangles(const vector<Triangle>& triangles) {
    for (const auto& triangle : triangles) {
        const Point& a = triangle.getA();
        const Point& b = triangle.getB();
        const Point& c = triangle.getC();
        cout << "Triangle: "
            << "A(" << a.getX() << ", " << a.getY() << "), "
            << "B(" << b.getX() << ", " << b.getY() << "), "
            << "C(" << c.getX() << ", " << c.getY() << ")" << endl;
    }
}

// ������� ��� ���������� ����� ������� ������������
float sideLength(const Point& a, const Point& b) {
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY()));
}

// ������� ��� ��������, �������� �� ����������� ��������������
bool isIsosceles(const Triangle& t) {
    float ab = sideLength(t.getA(), t.getB());
    float bc = sideLength(t.getB(), t.getC());
    float ca = sideLength(t.getC(), t.getA());

    // ���������, ����� �� �����-���� ��� �������
    return (ab == bc) || (ab == ca) || (bc == ca);
}


vector<Triangle> findIsoscelesTriangles(const vector<Triangle>& triangles) {
    vector<Triangle> isoscelesTriangles;

    for (const Triangle& triangle : triangles) {
        if (isIsosceles(triangle)) {
            isoscelesTriangles.push_back(triangle);
        }
    }

    return isoscelesTriangles;
}