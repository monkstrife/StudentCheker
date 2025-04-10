#include "matrix.h"
#include <iostream>
using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Малова А.С. Вариант №" << int('M') % 8 << endl;
    int row = 0;
    int column = 0;
    int** matrix1 = nullptr;
    int** matrix2 = nullptr;
    bool isEmpty = true;
    cout << "Клавиши действий:\n" << "i - Ввод значений матриц\n" << "o - Вывод значений матриц\n" << "s - Вывод разности матриц\n" << "e - Завершение программы" << endl;
    while (true) {
        cout << "________________________\n" << "   Введите команду : ";
        char command;
        cin >> command;

        switch (command) {

        case 'i': {

            //Очищение памяти при перезаписи
            if (!isEmpty) {
                matrixDelete(matrix1, matrix2, row);
                cout << "Данные стёрты." << endl; 
            }

            cout << "Введите кол-во строк матрицы: ";
            cin >> row;
            cout << "Введите кол-во столбцов матрицы: ";
            cin >> column;
            matrix1 = new int* [row];
            matrix2 = new int* [row];

            matrixIn(matrix1, matrix2, row, column);
            isEmpty = false;
            break;
        }

        case 'o': {
            if (isEmpty) {
                cout << "Исходные матрицы пусты. Введите данные." << endl;
            }
            else {
                matrixOut(matrix1, matrix2, row, column);
            }
            break;
        }

        case 's': {
            if (isEmpty) {
                cout << "Исходные матрицы пусты. Введите данные." << endl;
            }
            else {
                subtraction(matrix1, matrix2, row, column);
            }
            break;
        }

        case 'e': {
            exit(1);
        }

        default:
            cout << "Команды не существует. Попробуйте снова" << endl;
        }

    }
    return 0;
}