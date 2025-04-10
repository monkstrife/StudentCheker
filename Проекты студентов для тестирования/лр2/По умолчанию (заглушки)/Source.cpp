#include <iostream>
#include "Source.h"
using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������ �.�. ������� �" << int('M') % 8 << endl;
    int row = 0;
    int column = 0;
    int** matrix1 = nullptr;
    int** matrix2 = nullptr;
    bool isEmpty = true;
    cout << "������� ��������:\n" << "i - ���� �������� ������\n" << "o - ����� �������� ������\n" << "s - ����� �������� ������\n" << "e - ���������� ���������" << endl;
    while (true) {
        cout << "________________________\n" << "   ������� ������� : ";
        char command;
        cin >> command;

        switch (command) {

        case 'i': {

            //�������� ������ ��� ����������
            if (!isEmpty) {
                matrixDelete(matrix1, matrix2, row);
                cout << "������ �����." << endl;
            }

            cout << "������� ���-�� ����� �������: ";
            cin >> row;
            cout << "������� ���-�� �������� �������: ";
            cin >> column;
            matrix1 = new int* [row];
            matrix2 = new int* [row];

            matrixIn(matrix1, matrix2, row, column);
            isEmpty = false;
            break;
        }

        case 'o': {
            if (isEmpty) {
                cout << "�������� ������� �����. ������� ������." << endl;
            }
            else {
                matrixOut(matrix1, matrix2, row, column);
            }
            break;
        }

        case 's': {
            if (isEmpty) {
                cout << "�������� ������� �����. ������� ������." << endl;
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
            cout << "������� �� ����������. ���������� �����" << endl;
        }

    }
    return 0;
}

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
    //���� ��������� �������1
    cout << "������� �������� ������ �������, ���-�� ��������� - " << row * column << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix1[i][j];
        }
    }

    //���� ��������� �������2
    cout << "������� �������� ������ �������, ���-�� ��������� - " << row * column << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix2[i][j];
        }
    }

}

void matrixOut(int** matrix1, int** matrix2, int row, int column) {
    //����� ��������, �������� ����������
    cout << "�������� �������� ������:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << *(*(matrix1 + i) + j) << " ";
        }
        cout << "    ";
        for (int j = 0; j < column; j++) {
            cout << *(*(matrix2 + i) + j) << " ";
        }
        cout << endl;
    }
}

void subtraction(int** matrix1, int** matrix2, int row, int column) {
    //����� ��������
    cout << "�������� ������:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix1[i][j] - matrix2[i][j] << " ";
        }
        cout << endl;
    }
}