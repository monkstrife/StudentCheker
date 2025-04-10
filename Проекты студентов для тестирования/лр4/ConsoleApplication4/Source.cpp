#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU");
    int V = abs(int("M") - int("O")) % 5;
    cout << "Вариант: " << V << endl; // 4 вариант: приоритетный стэк

    char choice;
    int stackSize;
    cout << "Введите максимальный размер стэка (int): "; // Здесь и далее элементы стэка будут иметь формат int
    cin >> stackSize;
    Stack myStack(stackSize);
    char addMore = 'y';

    do {
        cout << "\nВыберите операцию:\n";
        cout << "a - Добавить элемент\n";
        cout << "e - Извлечь один элемент\n";
        cout << "r - Извлечь все элементы с приоритетом\n";
        cout << "c - Проверить наличие элемента\n";
        cout << "u - Объединить стэки\n";
        cout << "i - Пересечь стэки\n";
        cout << "s - Сравнить стэки по размеру\n";
        cout << "p - Вывести на экран стэк\n";
        cout << "q - Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 'a': {
            do {
                int* data = new int;
                cout << "Введите значение элемента (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода элемента

                int priority;
                cout << "Введите приоритет (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода приоритета

                myStack.addElement(priority, data);

                cout << "Нажмите Y, чтобы добавить еще элемент: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');
            showStack(myStack);
            break;
        }
        case 'r': {
            int priority;
            cout << "Введите приоритет для извлечения: ";
            cin >> priority;

            myStack.extractAllWithPriority(priority);
            showStack(myStack);
            break;
        }
        case 'e': {
            myStack.popElement();
            cout << "Был извлечен один элемент с наивысшим приоритетом.\n";
            showStack(myStack);
            break;
        }
        case 'c': {
            cout << "Введите значение элемента для проверки: ";
            int* data = new int;
            cin >> *data;
            if (!intInput()) { delete data; continue; } // Проверка на корректность ввода элемента

            int priority;
            cout << "Введите приоритет элемента для проверки: ";
            cin >> priority;
            if (!intInput()) { delete data; continue; } // Проверка на корректность ввода приоритета

            if (myStack.containsElement(data, priority)) cout << "Элемент есть в стэке\n";
            else cout << "Элемента нет в стэке\n";

            delete data; // Освобождаем память
            break;
        }
        case 'u': {
            // Создаем новый стэк для объединения
            int newSize;
            cout << "Введите максимальный размер второго стэка для объединения: ";
            cin >> newSize;

            Stack otherStack(newSize);

            // Заполняем другой стэк элементами
            char addMore;
            do {
                // Вводим элемент в стэк
                int* data = new int;
                cout << "Введите значение элемента (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода элемента

                int priority;
                cout << "Введите приоритет (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода приоритета

                otherStack.addElement(priority, data);

                cout << "Нажмите Y, чтобы добавить еще элемент: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            // Объединяем стэки
            myStack.unionStacks(otherStack);
            showStack(myStack);
            break;
        }
        case 'i': {
            // Создаем новый стэк для пересечения
            int newSize;
            cout << "Введите максимальный размер второго стэка для пересечения: ";
            cin >> newSize;

            Stack otherStack(newSize);

            // Заполняем другой стэк элементами
            char addMore;
            do {
                // Вводим элемент в стэк
                int* data = new int;
                cout << "Введите значение элемента (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода элемента

                int priority;
                cout << "Введите приоритет (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода приоритета

                otherStack.addElement(priority, data);

                cout << "Нажмите Y, чтобы добавить еще элемент: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            // Пересекаем стэки
            myStack.intersectStacks(otherStack);
            showStack(myStack);
            break;
        }

        case 's': {
            int newSize;
            cout << "Введите максимальный размер второго стэка перед вводом: ";
            cin >> newSize;

            Stack otherStack(newSize);

            // Заполняем другой стэк элементами
            char addMore;
            do {
                // Вводим элемент в стэк
                int* data = new int;
                cout << "Введите значение элемента (int): ";
                cin >> *data;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода элемента

                int priority;
                cout << "Введите приоритет (int): ";
                cin >> priority;
                if (!intInput()) { delete data; continue; } // Проверка на корректность ввода приоритета

                otherStack.addElement(priority, data);

                cout << "Нажмите Y, чтобы добавить еще элемент: ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            // Вывод размеров стэков
            cout << "Размер первого стэка: " << myStack.getSize() << endl;
            cout << "Размер второго стэка: " << otherStack.getSize() << endl;

            // Сравнение и вывод результата
            if (myStack <= otherStack) cout << "Размер первого стэка меньше или равен размеру второго стэка\n";
            else cout << "Размер первого стэка больше размера второго стэка\n";
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
            cout << "\nНекорректный выбор. Нажмите Enter\n";
            break;
        }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Очистка буфера ввода
        cout << "Операция завершена. Нажмите Enter";
        cin.get();  // Ожидаем ввода, чтобы консоль не закрылась
        system("cls");  // Очистка экрана
    } while (choice != 'q');

    return 0;
}
