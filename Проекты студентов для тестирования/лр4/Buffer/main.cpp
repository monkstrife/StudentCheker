#include <iostream>
#include "Buffer.h"
#include "windows.h"

void printMenu() {
    std::cout << "����:\n";
    std::cout << "1. �������� ������� � ����� 1\n";
    std::cout << "2. ������� ������� �� ������ 1\n";
    std::cout << "3. ������� ��������� ��������� �� ������ 1\n";
    std::cout << "4. ������� ��������� ����� � ������ 1\n";
    std::cout << "5. ��������� ������� � ������ 1\n";
    std::cout << "6. �������� ������� � ����� 2\n";
    std::cout << "7. ������� ������� �� ������ 2\n";
    std::cout << "8. ������� ��������� ��������� �� ������ 2\n";
    std::cout << "9. ������� ��������� ����� � ������ 2\n";
    std::cout << "10. ��������� ������� � ������ 2\n";
    std::cout << "11. ���������� ������\n";
    std::cout << "12. ����� ����������� �������\n";
    std::cout << "13. �������� ������� �������\n";
    std::cout << "14. ������� ������\n";
    std::cout << "0. �����\n";
    std::cout << "������� ��� �����: ";
}

int main() {
    SetConsoleOutputCP(1251);
    int size1, size2;
    std::cout << "������� ������ ������� ������: ";
    std::cin >> size1;
    std::cout << "������� ������ ������� ������: ";
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
            std::cout << "������� �������: ";
            std::cin >> element;
            buffer1.addElement(element); 
            std::cout << "������� ��������." << std::endl;
            break;
        }
        case 2:
            buffer1.removeElement();
            std::cout << "������� ������." << std::endl;
            break;
        case 3: {
            int numElements;
            std::cout << "��������� ��������� ��� ����������: ";
            std::cin >> numElements;
            buffer1.removeMultipleElements(numElements);
            std::cout << "�������� ���������" << std::endl;
            break;
        }
        case 4:
            buffer1.printFreeSpace();
            break;
        case 5: {
            int checkElement;
            std::cout << "������� ������� ��� ��������: ";
            std::cin >> checkElement;
            if (buffer1.contains(checkElement)) {
                std::cout << "������� ������." << std::endl;
            }
            else {
                std::cout << "������� �� ������." << std::endl;
            }
            break;
        }
        case 6: {
            int element;
            std::cout << "������� �������: ";
            std::cin >> element;
            buffer2.addElement(element); // ���������� �������� � ����� 2
            std::cout << "������� ��������." << std::endl;
            break;
        }
        case 7:
            buffer2.removeElement();
            std::cout << "������� ������." << std::endl;
            break;
        case 8: {
            int numElements;
            std::cout << "���������� ��������� ��� ����������: ";
            std::cin >> numElements;
            buffer2.removeMultipleElements(numElements);
            break;
        }
        case 9:
            buffer2.printFreeSpace();
            break;
        case 10: {
            int checkElement;
            std::cout << "������� ������� ��� ��������: ";
            std::cin >> checkElement;
            if (buffer2.contains(checkElement)) {
                std::cout << "������� ������" << std::endl;
            }
            else {
                std::cout << "������� �� ������." << std::endl;
            }
            break;
        }
        case 11:
            buffer1.merge(buffer2);
            std::cout << "������ ����������." << std::endl;
            break;
        case 12:
            buffer1.intersect(buffer2);
            break;
        case 13:
            if (buffer1 > buffer2) {
                std::cout << "����� 1 ������." << std::endl;
            }
            else if (buffer2 > buffer1) {
                std::cout << "����� 2 ������." << std::endl;
            }
            else {
                std::cout << "������ ������� ����������." << std::endl;
            }
            break;
        case 14:
            std::cout << buffer1;
             std::cout << buffer2;

            break;
        case 0:
            break;
        default:
            std::cout << "��� ������" << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
