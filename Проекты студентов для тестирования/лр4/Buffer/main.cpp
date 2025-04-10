#include <iostream>
#include "Buffer.h"
#include "windows.h"

void printMenu() {
    std::cout << "Меню:\n";
    std::cout << "1. Добавить элемент в буфер 1\n";
    std::cout << "2. Удалить элемент из буфера 1\n";
    std::cout << "3. Удалить несколько элементов из буфера 1\n";
    std::cout << "4. Вывести свободное место в буфере 1\n";
    std::cout << "5. Проверить элемент в буфере 1\n";
    std::cout << "6. Добавить элемент в буфер 2\n";
    std::cout << "7. Удалить элемент из буфера 2\n";
    std::cout << "8. Удалить несколько элементов из буфера 2\n";
    std::cout << "9. Вывести свободное место в буфере 2\n";
    std::cout << "10. Проверить элемент в буфере 2\n";
    std::cout << "11. Объединить буферы\n";
    std::cout << "12. Найти пересечение буферов\n";
    std::cout << "13. Сравнить размеры буферов\n";
    std::cout << "14. Вывести буферы\n";
    std::cout << "0. Выход\n";
    std::cout << "Введите ваш выбор: ";
}

int main() {
    SetConsoleOutputCP(1251);
    int size1, size2;
    std::cout << "Введите размер первого буфера: ";
    std::cin >> size1;
    std::cout << "Введите размер второго буфера: ";
    std::cin >> size2;

    CircularBuffer buffer1(size1);
    CircularBuffer buffer2(size2);
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int element;
            std::cout << "Введите элемент: ";
            std::cin >> element;
            buffer1.addElement(element); 
            std::cout << "Элемент добавлен." << std::endl;
            break;
        }
        case 2:
            buffer1.removeElement();
            std::cout << "Элемент удален." << std::endl;
            break;
        case 3: {
            int numElements;
            std::cout << "Количеств элементов для извлечения: ";
            std::cin >> numElements;
            buffer1.removeMultipleElements(numElements);
            std::cout << "Элементы извлечены" << std::endl;
            break;
        }
        case 4:
            buffer1.printFreeSpace();
            break;
        case 5: {
            int checkElement;
            std::cout << "Введите элемент для проверки: ";
            std::cin >> checkElement;
            if (buffer1.contains(checkElement)) {
                std::cout << "Элемент найден." << std::endl;
            }
            else {
                std::cout << "Элемент не найден." << std::endl;
            }
            break;
        }
        case 6: {
            int element;
            std::cout << "Введите элемент: ";
            std::cin >> element;
            buffer2.addElement(element); // Добавление элемента в буфер 2
            std::cout << "Элемент добавлен." << std::endl;
            break;
        }
        case 7:
            buffer2.removeElement();
            std::cout << "Элемент удален." << std::endl;
            break;
        case 8: {
            int numElements;
            std::cout << "Количество элементов для извлечения: ";
            std::cin >> numElements;
            buffer2.removeMultipleElements(numElements);
            break;
        }
        case 9:
            buffer2.printFreeSpace();
            break;
        case 10: {
            int checkElement;
            std::cout << "Введите элемент для проверки: ";
            std::cin >> checkElement;
            if (buffer2.contains(checkElement)) {
                std::cout << "Элемент найден" << std::endl;
            }
            else {
                std::cout << "Элемент не найден." << std::endl;
            }
            break;
        }
        case 11:
            buffer1.merge(buffer2);
            std::cout << "Буферы объединены." << std::endl;
            break;
        case 12:
            buffer1.intersect(buffer2);
            break;
        case 13:
            if (buffer1 > buffer2) {
                std::cout << "Буфер 1 больше." << std::endl;
            }
            else if (buffer2 > buffer1) {
                std::cout << "Буфер 2 больше." << std::endl;
            }
            else {
                std::cout << "Размер буферов одинаковый." << std::endl;
            }
            break;
        case 14:
            std::cout << buffer1;
             std::cout << buffer2;

            break;
        case 0:
            break;
        default:
            std::cout << "Нет такого" << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
