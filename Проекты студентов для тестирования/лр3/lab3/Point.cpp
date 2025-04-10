#include "Point.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

//реализация функций определенных в файре h

Point::Point(float x, float y) : x(x), y(y) {} // Инициализация членов класса

float Point::getX() const { return x; } // Возвращаем значение координаты X
float Point::getY() const { return y; } 

void Point::setX(float value) { x = value; } // Устанавливаем значение координаты X
void Point::setY(float value) { y = value; } 




// фукнция для рандомного заполнения массива точек для определения параллельных линий далее...
void fillWithRandomPoints(Point* points, int size) { 
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел текущим временем

    for (int i = 0; i < size; ++i) {
        // Генерация случайных координат от 0 до 99
        float x = rand() % 100; // Генерируем целое число от 0 до 99
        float y = rand() % 100; // Генерируем целое число от 0 до 99

        // Приведение целых чисел к float
        points[i] = Point(static_cast<float>(x), static_cast<float>(y)); // Создаем точку и сохраняем в массиве
    }
}

// для вывода точек создаваемых в массиве, если интересно попало ли совпадение линий
void printPoints(const Point* points, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Point " << i + 1 << ": (" << points[i].getX() << ", " << points[i].getY() << ")\n";
    }
}

// Вспомогательная функция для расчета углового коэффициента линии, проходящей через две точки
float slope(const Point& p1, const Point& p2) {
    if (p1.getX() == p2.getX()) { // Проверка на вертикальную линию (бесконечный угловой коэффициент)
        return INFINITY; // Возвращаем бесконечность для вертикальной линии
    }
    return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
}

// определение функции нахождения параллельных линий
bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22) {
    for (int i = 0; i < size - 1; i++) { // Перебираем все пары точек
        for (int j = i + 1; j < size; j++) {
            float slope1 = slope(points[i], points[j]); // Находим угловой коэффициент первой линии

            for (int k = 0; k < size - 1; k++) { // Перебираем все остальные пары точек
                for (int l = k + 1; l < size; l++) {
                    if (i == k && j == l) continue; // Пропускаем ту же пару точек

                    float slope2 = slope(points[k], points[l]); // Находим угловой коэффициент второй линии

                    if (slope1 == slope2) { // Если угловые коэффициенты равны, линии параллельны
                        p11 = points[i]; // Задаем первую точку первой линии
                        p12 = points[j];
                        p21 = points[k];
                        p22 = points[l];
                        cout << "Угловой коэфициент 1 линии: " << slope1 << endl;
                        cout << "Угловой коэфициент 2 линии: " << slope2 << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false; // Если параллельные линии не найдены, возвращаем false
}


float distance(const Point& a, const Point& b) {
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}


Point getMinCirclePoint(Point* points, int size, int R) {
    int minCount = 100; // Инициализируем минимальное количество точек найденных в пределах окружности
    Point minPoint;

    // Перебираем каждую точку, чтобы проверить, как много точек она содержит внутри окружности радиусом R
    for (int i = 0; i < size; ++i) {
        int count = 0; // Счетчик для подсчета точек внутри окружности
        for (int j = 0; j < size; ++j) {
            if (distance(points[i], points[j]) <= R) {
                ++count; // Увеличиваем счетчик, если точка находится внутри окружности
            }
        }
        // Если текущая окружность содержит меньше точек, чем предыдущий минимум, обновляем минимум
        if (count < minCount) {
            minCount = count;
            minPoint = points[i];
        }
    }

    return minPoint; // Возвращаем точку с минимальным количеством точек внутри окружности
}