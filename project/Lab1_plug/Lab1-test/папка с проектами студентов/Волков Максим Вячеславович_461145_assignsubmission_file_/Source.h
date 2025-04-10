#pragma once

#include <iostream>
#include <climits>

using namespace std;


bool belongsToInterval(float x, float top, float bottom);
int minValue(int first, int second);
float minValue(float first, float second);
int order(int x);
int getLetterCode(char letter);
void showTypeInfo();
void handleInvalidInput();


bool belongsToInterval(float x, float top, float bottom)
{
    if (x < top && x > bottom)
        return true;
    else
        return false;
}

int minValue(int first, int second)
{
    return first < second ? first : second;
}

float minValue(float first, float second)
{
    return first < second ? first : second;   
}

int order(int x)
{
    int count = 0;

    if (x == 0)
        return 1;

    while (x > 0)
    {
        x /= 10;
        count++;
    }

    return count;
}

int getLetterCode(char letter)
{
    return (int)letter;
}

void showTypeInfo()
{
    cout << "char" << endl;
    cout << "Размер: " << sizeof(char);
    cout << ". Максимальное значение: " << CHAR_MAX;
    cout << ". Минимальное значение: "<< CHAR_MIN << endl << endl;

    cout << "int" << endl;
    cout << "Размер: " << sizeof(int);
    cout << ". Максимальное значение: " << INT_MAX;
    cout << ". Минимальное значение: "<< INT_MIN << endl << endl;

    cout << "short" << endl;
    cout << "Размер: " << sizeof(short);
    cout << ". Максимальное значение: " << CHAR_MAX;
    cout << ". Минимальное значение: "<< CHAR_MIN << endl << endl;

    cout << "long" << endl;
    cout << "Размер: " << sizeof(long);
    cout << ". Максимальное значение: " << LONG_MAX;
    cout << ". Минимальное значение: "<< LONG_MIN << endl << endl;

    cout << "long long" << endl;
    cout << "Размер: " << sizeof(long long);
    cout << ". Максимальное значение: " << LLONG_MAX;
    cout << ". Минимальное значение: "<< LLONG_MIN << endl << endl;
}

void handleInvalidInput()
{
    cout << "Введено некорректное значение" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}