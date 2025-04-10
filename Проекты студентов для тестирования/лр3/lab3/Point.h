#ifndef POINT_H
#define POINT_H

// ����� ��� ������ � ������� � ��������� ������������
class Point {
private:
    float x, y; // ��������� ���������� ��� ��������� �����

public:
    Point(float x = 0.0, float y = 0.0); // ����������� � ����������� �� ���������
    float getX() const; 
    float getY() const; 
    void setX(float value); 
    void setY(float value); 

};

void fillWithRandomPoints(Point* points, int size); // ������� ��� ���������� ���������� ������� ����� ��� ����������� ������������ ����� �����...
void printPoints(const Point* points, int size); // ��� ������ ����� ����������� � �������, ���� ��������� ������ �� ���������� �����
float slope(const Point& p1, const Point& p2); // ��������������� ������� ��� ������� �������� ������������ �����, ���������� ����� ��� �����
bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22); // ����������� ������� ���������� ������������ �����

float distance(const Point& a, const Point& b); // ��������������� ������� ��� ���������� ���������� ����� ����� �������
Point getMinCirclePoint(Point* points, int size, int R); // �������, ������������ �����, ��� ������� ���������� ������� R �������� ����������� ���������� �����

#endif // POINT_H