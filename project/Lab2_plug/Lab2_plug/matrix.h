#pragma once
#include <iostream>
using namespace std;

void subtraction(int** matrix1, int** matrix2, int row, int column);
void matrixOut(int** matrix1, int** matrix2, int row, int column);
void matrixIn(int** matrix1, int** matrix2, int row, int column);
void matrixDelete(int** matrix1, int** matrix2, int row);

void matrixDelete(int** matrix1, int** matrix2, int row) {
    for (int i = 0; i < row; i++) {
        delete[]matrix1[i];
        delete[]matrix2[i];
    }
    delete[]matrix1;
    delete[]matrix2;
}

void matrixIn(int** matrix1, int** matrix2, int row, int column) {

    for (int i = 0; i < row; i++) {
        matrix1[i] = new int[column];
        matrix2[i] = new int[column];
    }
    //Ввод элементов Матрицы1
    cout << "Введите значения первой матрицы, кол-во элементов - " << row * column << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix1[i][j];
        }
    }

    //Ввод элементов Матрицы2
    cout << "Введите значения второй матрицы, кол-во элементов - " << row * column << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix2[i][j];
        }
    }

}

void matrixOut(int** matrix1, int** matrix2, int row, int column) {
    //Вывод значений, адресная арифметика
    cout << "Значения введённых матриц:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout <<  *(*(matrix1 + i) + j) << " ";
        }
        cout << "    ";
        for (int j = 0; j < column; j++) {
            cout << *(*(matrix2 + i) + j) << " ";
        }
        cout << endl;
    }
}

void subtraction(int** matrix1, int** matrix2, int row, int column) {
    //Вывод разности
    cout << "Разность матриц:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix1[i][j] - matrix2[i][j] << " ";
        }
        cout << endl;
    }
}