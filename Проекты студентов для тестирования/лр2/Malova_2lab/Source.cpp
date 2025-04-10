#include "matrix.h"
#include <iostream>
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