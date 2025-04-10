#pragma once

class Point {

    private:
        double xCoordinate = 0;
        double yCoordinate = 0;

    public:
        Point();
        Point(double x, double y);
        void SetPoint(double x, double y);
        void GetPoint();

        double GetX();
        double GetY();
};

// L
bool inLine(Point* points, int size);
int getPointsInLine(Point* points, int size);
int countLines(Point* points, int size);
bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22);

// P
Point getMaxCirclePoint(Point* points, int size, int R);
Point getFarestPoint(Point* points, int size);
Point getClosestPoint(Point* points, int size);
Point getMinCirclePoint(Point* points, int size, int R);