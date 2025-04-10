#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h" // Подключаем определение класса Point
#include <vector>

using namespace std;

class Triangle {
private:
    Point a, b, c; // Три точки, образующие треугольник

public:
    Triangle(const Point& a, const Point& b, const Point& c); // Конструктор
    float area() const; // Метод для вычисления площади треугольника
    float perimeter() const; // Метод для вычисления периметра треугольника
    const Point& getA() const; // Геттер для точки A
    const Point& getB() const; // Геттер для точки B
    const Point& getC() const; // Геттер для точки C

};

vector<Triangle> createTrianglesFromPoints(int& size); // создаем треугольники

void printTriangles(const vector<Triangle>& triangles);//Функция вывода треугольников

float sideLength(const Point& a, const Point& b); // Функция для вычисления длины стороны треугольника

bool isIsosceles(const Triangle& t); // Функция для проверки, является ли треугольник равнобедренным

vector<Triangle> findIsoscelesTriangles(const vector<Triangle>& triangles); // нахождение равнобедренных треугольников в массиве.

#endif // TRIANGLE_H