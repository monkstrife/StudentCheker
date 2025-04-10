#ifndef POINT_H
#define POINT_H

//  ласс дл€ работы с точками в двумерном пространстве
class Point {
private:
    float x, y; // ѕриватные переменные дл€ координат точки

public:
    Point(float x = 0.0, float y = 0.0); //  онструктор с параметрами по умолчанию
    float getX() const; 
    float getY() const; 
    void setX(float value); 
    void setY(float value); 

};

void fillWithRandomPoints(Point* points, int size); // фукнци€ дл€ рандомного заполнени€ массива точек дл€ определени€ параллельных линий далее...
void printPoints(const Point* points, int size); // дл€ вывода точек создаваемых в массиве, если интересно попало ли совпадение линий
float slope(const Point& p1, const Point& p2); // ¬спомогательна€ функци€ дл€ расчета углового коэффициента линии, проход€щей через две точки
bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22); // определение функции нахождени€ параллельных линий

float distance(const Point& a, const Point& b); // ¬спомогательна€ функци€ дл€ вычислени€ рассто€ни€ между двум€ точками
Point getMinCirclePoint(Point* points, int size, int R); // ‘ункци€, возвращающа€ точку, дл€ которой окружность радиуса R содержит минимальное количество точек

#endif // POINT_H