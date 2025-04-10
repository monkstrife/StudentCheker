#include "Point.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

//���������� ������� ������������ � ����� h

Point::Point(float x, float y) : x(x), y(y) {} // ������������� ������ ������

float Point::getX() const { return x; } // ���������� �������� ���������� X
float Point::getY() const { return y; } 

void Point::setX(float value) { x = value; } // ������������� �������� ���������� X
void Point::setY(float value) { y = value; } 




// ������� ��� ���������� ���������� ������� ����� ��� ����������� ������������ ����� �����...
void fillWithRandomPoints(Point* points, int size) { 
    srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� ����� ������� ��������

    for (int i = 0; i < size; ++i) {
        // ��������� ��������� ��������� �� 0 �� 99
        float x = rand() % 100; // ���������� ����� ����� �� 0 �� 99
        float y = rand() % 100; // ���������� ����� ����� �� 0 �� 99

        // ���������� ����� ����� � float
        points[i] = Point(static_cast<float>(x), static_cast<float>(y)); // ������� ����� � ��������� � �������
    }
}

// ��� ������ ����� ����������� � �������, ���� ��������� ������ �� ���������� �����
void printPoints(const Point* points, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Point " << i + 1 << ": (" << points[i].getX() << ", " << points[i].getY() << ")\n";
    }
}

// ��������������� ������� ��� ������� �������� ������������ �����, ���������� ����� ��� �����
float slope(const Point& p1, const Point& p2) {
    if (p1.getX() == p2.getX()) { // �������� �� ������������ ����� (����������� ������� �����������)
        return INFINITY; // ���������� ������������� ��� ������������ �����
    }
    return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
}

// ����������� ������� ���������� ������������ �����
bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22) {
    for (int i = 0; i < size - 1; i++) { // ���������� ��� ���� �����
        for (int j = i + 1; j < size; j++) {
            float slope1 = slope(points[i], points[j]); // ������� ������� ����������� ������ �����

            for (int k = 0; k < size - 1; k++) { // ���������� ��� ��������� ���� �����
                for (int l = k + 1; l < size; l++) {
                    if (i == k && j == l) continue; // ���������� �� �� ���� �����

                    float slope2 = slope(points[k], points[l]); // ������� ������� ����������� ������ �����

                    if (slope1 == slope2) { // ���� ������� ������������ �����, ����� �����������
                        p11 = points[i]; // ������ ������ ����� ������ �����
                        p12 = points[j];
                        p21 = points[k];
                        p22 = points[l];
                        cout << "������� ���������� 1 �����: " << slope1 << endl;
                        cout << "������� ���������� 2 �����: " << slope2 << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false; // ���� ������������ ����� �� �������, ���������� false
}


float distance(const Point& a, const Point& b) {
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}


Point getMinCirclePoint(Point* points, int size, int R) {
    int minCount = 100; // �������������� ����������� ���������� ����� ��������� � �������� ����������
    Point minPoint;

    // ���������� ������ �����, ����� ���������, ��� ����� ����� ��� �������� ������ ���������� �������� R
    for (int i = 0; i < size; ++i) {
        int count = 0; // ������� ��� �������� ����� ������ ����������
        for (int j = 0; j < size; ++j) {
            if (distance(points[i], points[j]) <= R) {
                ++count; // ����������� �������, ���� ����� ��������� ������ ����������
            }
        }
        // ���� ������� ���������� �������� ������ �����, ��� ���������� �������, ��������� �������
        if (count < minCount) {
            minCount = count;
            minPoint = points[i];
        }
    }

    return minPoint; // ���������� ����� � ����������� ����������� ����� ������ ����������
}