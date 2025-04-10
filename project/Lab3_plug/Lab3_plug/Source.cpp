// Лабораторная работа №3. Алеев А.А.
// Вариант 10

#include <iostream>
#include "Triangle.h"
#include "Point.h"
#include <Windows.h>
#include <limits>

#ifdef max
#undef max
#endif


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int intV = (int('M') + int('A')) % 12;
    std::cout << "Мой вариант с учетом Фамилии Мишланов и имени Александр: " << intV;

}