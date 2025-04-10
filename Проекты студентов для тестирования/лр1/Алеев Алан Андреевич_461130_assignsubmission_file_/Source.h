#pragma once

#include <iostream>
#include <typeinfo>
#include <climits>(<limits.h>)
#include <Windows.h>
#include <string>
#include <sstream>

bool belongsToInterval(int x, int top, int bottom);
int minValue(int x, int y);
float minValue(float x, float y);
short order(long long x);
int getLetterCode(char c);
void showTypeInfo();
bool isFloat(std::string userString);
bool isInt(std::string userString);
bool isLL(std::string userString);

//Функция проверки интервала с тернарным оператором, значение в интервале учитывается включительно 
bool belongsToInterval(int x, int top, int bottom) {
    return (x > top) ? false : (x < bottom ? false : true);
}
//Функция возвращающая минимальное значение из двух аргументов
//Первая перегрузка принимающая целочисленные значения
int minValue(int x, int y) {
    return (x > y) ? y : x;
}
//Вторая перегрузка принимающая значения с плавающей запятой
float minValue(float x, float y) {
    return (x > y) ? y : x;
}
//Функция определения порядка числа, осуществлена с помощью логарифмической функции
//В условиях задачи четко не указан тип вводимых данных, представляющих целочисленное значение, поэтому взят тип данных long long как наибольший
//Метод "trunc" возвращает ближайшее целое число равное или меньшее заданному, log имеет тип данных double преобразуемых short
//По итогу получаем целочисленные результат на единицу меньше чем порядок заданного числа, поэтому добавляем единицу
short order(long long x) {
    x = std::llabs(x);
    return trunc(log10(x)) + 1;
}

//Функция возвращающая значение символа в виде числового представления
//При введении кириллических символов будет выдаваться отрицательное значение кодового представление
//Этого можно избежать добавив к типу char модификатор unsigned,т.к. типы данных с данным модификатором могут быть только неотрицательных численных значений
//Но в данном примере мы это делать не будем, т.к. по заданию не указана необходимость использования вышеназванного модификатора
int getLetterCode(char c) {
    return (int)c;
}
//Функция возвращающая информацию о типах данных
void showTypeInfo() {
    std::cout << "\nМинимальное значение типа char:" << CHAR_MIN << std::endl;
    std::cout << "Максимальное значение типа char:" << CHAR_MAX << std::endl;
    std::cout << "Размер типа данных char: " << sizeof(char) << std::endl;

    std::cout << "\nМинимальное значение типа int:" << INT_MIN << std::endl;
    std::cout << "Максимальное значение типа int:" << INT_MAX << std::endl;
    std::cout << "Размер типа данных int: " << sizeof(int) << std::endl;

    std::cout << "\nМинимальное значение типа short:" << SHRT_MIN << std::endl;
    std::cout << "Максимальное значение типа short:" << SHRT_MAX << std::endl;
    std::cout << "Размер типа данных short: " << sizeof(short) << std::endl;

    std::cout << "\nМинимальное значение типа long:" << LONG_MIN << std::endl;
    std::cout << "Максимальное значение типа long:" << LONG_MAX << std::endl;
    std::cout << "Размер типа данных long: " << sizeof(long) << std::endl;

    std::cout << "\nМинимальное значение типа long long:" << LLONG_MIN << std::endl;
    std::cout << "Максимальное значение типа long long:" << LLONG_MAX << std::endl;
    std::cout << "Размер типа данных long long: " << sizeof(long long) << std::endl << std::endl;
}
//Функция проверки соответствия значения строки типу данных float
//Если удается привести значение string к типу данных float, то функция возвращает true, иначе false
bool isFloat(std::string userString) {
    std::istringstream iss(userString);
    float f;
    iss >> f;
    return iss.eof() && !iss.fail();
}
//Функция проверки соответствия значения строки типу данных int
//Если удается привести значение string к типу данных int, то функция возвращает true, иначе false
bool isInt(std::string userString) {
    std::istringstream iss(userString);
    int i;
    iss >> i;
    return iss.eof() && !iss.fail();
}
//Функция проверки соответствия значения строки типу данных long long
//Если удается привести значение string к типу данных long long, то функция возвращает true, иначе false
bool isLL(std::string userString) {
    std::istringstream iss(userString);
    long long ll;
    iss >> ll;
    return iss.eof() && !iss.fail();
}
