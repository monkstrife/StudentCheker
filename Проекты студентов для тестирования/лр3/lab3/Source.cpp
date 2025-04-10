#include <iostream>
#include <vector>
#include "Point.h"
#include "Triangle.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "RU_ru");

    int intV = (int('M') + int('A')) % 12;
    cout << "Мой вариант с учетом Фамилии Мишланов и имени Александр: " << intV << endl;


    const int size = 100; // Размер массива
    Point points[size]; // Объявляем массив точек
    fillWithRandomPoints(points, size); // Заполняем массив случайными точками

    int size_triangle = 1000; // размер массива треугольников
    vector<Triangle> triangles = createTrianglesFromPoints(size_triangle); // создаем треугольники каждый раз рандомные

 
    int choice;
    do {
        cout << "Выберите действие:\n";
        cout << "1. Найти параллельные линии\n";
        cout << "2. Найти точку для минимального круга\n";
        cout << "3. Найти равнобедренные треугольники\n";
        cout << "4. Вывести массив точек\n";
        cout << "5. Вывести массив треугольников\n";
        cout << "6. Вывод всех площадей треугольников\n";
        cout << "7. Нахождение периметра всех треугольников\n";
        cout << "0. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            // нахождение параллельных линий
            Point p11, p12, p21, p22;
            if (getParallelLines(points, size, p11, p12, p21, p22)) {
                // Если нашли пары параллельных линий, выводим их
                cout << "Параллельные линии найдены между точками:" << endl;
                cout << "Линия 1: (" << p11.getX() << ", " << p11.getY() << ") и (" << p12.getX() << ", " << p12.getY() << ")" << endl;
                cout << "Линия 2: (" << p21.getX() << ", " << p21.getY() << ") и (" << p22.getX() << ", " << p22.getY() << ")" << endl;
            }
            else {
                cout << "Параллельные линии не найдены." << endl;
            }
            break;
        }
        case 2: {
            // Здесь будет код для нахождения точки для минимального круга
            cout << "Задай радиус окружности (радиус должен быть в пределах 99)\n";
            int unsigned R = 0;
            cin >> R;
            Point pr = getMinCirclePoint(points, size, R);
            cout << "Точка с минимальным количеством точек в окружности радиусом R:" << " (" << pr.getX() << ", " << pr.getY() << ")" << endl;

            break;
        }
        case 3: {
            // Здесь будет код для нахождения равнобедренных треугольников
            vector<Triangle> isoscelesTriangles = findIsoscelesTriangles(triangles);
            printTriangles(isoscelesTriangles);
            cout << "Равнобедренных треугольников получилось: " << isoscelesTriangles.size() << 
                " Из " << size_triangle << endl;
            break;
        }
        case 4: {
            // вывод точек массива
            printPoints(points, size);

            break;
        }
        
        case 5: {
            // вывод всех треугольников которые есть
            printTriangles(triangles);
            break;
        }
        case 6: {
            // вывод всех площадей существующих треугольников
            for (const Triangle& triangle : triangles) {
                cout << triangle.area() << endl;
            }
        }
        case 7: {
            // вывод периметра существующих треугольников
            for (const Triangle& triangle : triangles) {
                cout << triangle.perimeter() << endl;
            }
        }

        case 0: {
            cout << "Выход из программы...\n";
            break;
        }
        default: {
            cout << "Неверный ввод, попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
