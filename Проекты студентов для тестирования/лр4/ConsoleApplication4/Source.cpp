#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU");
    int V = abs(int("M") - int("O")) % 5;
    cout << "�������: " << V << endl; // 4 �������: ������������ ����

    char choice;
    int stackSize;
    cout << "������� ������������ ������ ����� (int): "; // ����� � ����� �������� ����� ����� ����� ������ int
    cin >> stackSize;
    Stack myStack(stackSize);
    char addMore = 'y';

    do {
        cout << "\n�������� ��������:\n";
        cout << "a - �������� �������\n";
        cout << "e - ������� ���� �������\n";
        cout << "r - ������� ��� �������� � �����������\n";
        cout << "c - ��������� ������� ��������\n";
        cout << "u - ���������� �����\n";
        cout << "i - �������� �����\n";
        cout << "s - �������� ����� �� �������\n";
        cout << "p - ������� �� ����� ����\n";
        cout << "q - �����\n";
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 'a': {
            do {
                int* data = new int;
                cout << "������� �������� �������� (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ��������

                int priority;
                cout << "������� ��������� (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ����������

                myStack.addElement(priority, data);

                cout << "������� Y, ����� �������� ��� �������: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');
            showStack(myStack);
            break;
        }
        case 'r': {
            int priority;
            cout << "������� ��������� ��� ����������: ";
            cin >> priority;

            myStack.extractAllWithPriority(priority);
            showStack(myStack);
            break;
        }
        case 'e': {
            myStack.popElement();
            cout << "��� �������� ���� ������� � ��������� �����������.\n";
            showStack(myStack);
            break;
        }
        case 'c': {
            cout << "������� �������� �������� ��� ��������: ";
            int* data = new int;
            cin >> *data;
            if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ��������

            int priority;
            cout << "������� ��������� �������� ��� ��������: ";
            cin >> priority;
            if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ����������

            if (myStack.containsElement(data, priority)) cout << "������� ���� � �����\n";
            else cout << "�������� ��� � �����\n";

            delete data; // ����������� ������
            break;
        }
        case 'u': {
            // ������� ����� ���� ��� �����������
            int newSize;
            cout << "������� ������������ ������ ������� ����� ��� �����������: ";
            cin >> newSize;

            Stack otherStack(newSize);

            // ��������� ������ ���� ����������
            char addMore;
            do {
                // ������ ������� � ����
                int* data = new int;
                cout << "������� �������� �������� (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ��������

                int priority;
                cout << "������� ��������� (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ����������

                otherStack.addElement(priority, data);

                cout << "������� Y, ����� �������� ��� �������: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            // ���������� �����
            myStack.unionStacks(otherStack);
            showStack(myStack);
            break;
        }
        case 'i': {
            // ������� ����� ���� ��� �����������
            int newSize;
            cout << "������� ������������ ������ ������� ����� ��� �����������: ";
            cin >> newSize;

            Stack otherStack(newSize);

            // ��������� ������ ���� ����������
            char addMore;
            do {
                // ������ ������� � ����
                int* data = new int;
                cout << "������� �������� �������� (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ��������

                int priority;
                cout << "������� ��������� (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ����������

                otherStack.addElement(priority, data);

                cout << "������� Y, ����� �������� ��� �������: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            // ���������� �����
            myStack.intersectStacks(otherStack);
            showStack(myStack);
            break;
        }

        case 's': {
            int newSize;
            cout << "������� ������������ ������ ������� ����� ����� ������: ";
            cin >> newSize;

            Stack otherStack(newSize);

            // ��������� ������ ���� ����������
            char addMore;
            do {
                // ������ ������� � ����
                int* data = new int;
                cout << "������� �������� �������� (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ��������

                int priority;
                cout << "������� ��������� (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // �������� �� ������������ ����� ����������

                otherStack.addElement(priority, data);

                cout << "������� Y, ����� �������� ��� �������: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            // ����� �������� ������
            cout << "������ ������� �����: " << myStack.getSize() << endl;
            cout << "������ ������� �����: " << otherStack.getSize() << endl;

            // ��������� � ����� ����������
            if (myStack <= otherStack) cout << "������ ������� ����� ������ ��� ����� ������� ������� �����\n";
            else cout << "������ ������� ����� ������ ������� ������� �����\n";
            break;
        }
        case 'p': {
            showStack(myStack);
            break;
        }
        case 'q': {
            break;
        }
        default: {
            cout << "\n������������ �����. ������� Enter\n";
            break;
        }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ������� ������ �����
        cout << "�������� ���������. ������� Enter";
        cin.get();  // ������� �����, ����� ������� �� ���������
        system("cls");  // ������� ������
    } while (choice != 'q');

    return 0;
}
