// Лабораторная работа №6. Алеев А.А.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Вариант 1 Book

#include "Book.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <windows.h>
#include <limits>
#include <fstream>

#ifdef max
#undef max
#endif

int main()
{
	std::vector<Book> bookVector;
	bookVector.push_back(Book(550, "Maritime", "Phillip", 999.99f));
    bookVector.push_back(Book(376, "Arabia", "John", 555.99f));
    bookVector.push_back(Book(68, "Cousine", "Mark", 432.99f));
    bookVector.push_back(Book(25, "Map", "Thomas", 254.99f));
    bookVector.push_back(Book(250, "Channel", "Jean", 1999.99f));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool isActive = true;
    std::cout << "Начало работы программы...\n";
    while (isActive) {
        std::cout << "\nВведите символ для проверки функции приложения: \n"
            "a - Добавление элемента в конец вектора\n"
            "b - Сортировка элементов (пользователь выбирает характеристику для сортировки)\n"
            "c - Поиск максимального или минимального элемента по выбранной характеристике объектов\n"
            "d - Вычисление агрегированного значения\n"
            "f - Отбор элементов по заданному условию\n"
            "g - Поиск элемента с заданным значением характеристики\n"
            "w - Вывести информацию о книгах\n"
            "t - Удалить элемент вектора\n"
            "x - Чтение/запись данных\n"
            "e - Выход\n" << std::endl;
        char a;
        std::cin >> a;
        switch (a) {
        case 'a': {
            std::cout << "\nДобавление книги в конец вектора\n";
            int pages;
            std::cout << "\nВведите кол-во страниц\n";
            while (!(std::cin >> pages) || (pages < 0)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведены неверные данные" << std::endl;
            };
            std::string name;
            std::cout << "\nВведите название" << std::endl;
            while (!(std::cin >> name)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведены неверные данные" << std::endl;
            }
            std::string author;
            std::cout << "\nВведите имя автора" << std::endl;
            while (!(std::cin >> author)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведены неверные данные" << std::endl;
            };
            float price;
            std::cout << "\nВведите цену книги\n";
            while (!(std::cin >> price) || (price < 0)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведены неверные данные" << std::endl;
            };
            Book book(pages, name, author, price);
            bookVector.push_back(book);
            break;
        }
        case 'b': {
            std::cout << "\nВыберите характеристику для сортировки по возрастанию\n"
                      << "\nu - сортировка по цене\n"
                      << "\np - сортировка по кол-ву страниц\n";
            std::cin >> a;
            switch (a) {
            case 'u': {
                auto comparisonPrice = [](Book& a, Book& b)
                {
                    return a.getPrice() <= b.getPrice();
                };
                std::sort(bookVector.begin(), bookVector.end(), comparisonPrice);
                for (const auto& book : bookVector) {
                    std::cout << book << std::endl;
                }
                break;
            }
            case 'p': {
                auto comparisonPages = [](Book& a, Book& b)
                {
                    return a.getPages() <= b.getPages();
                };
                std::sort(bookVector.begin(), bookVector.end(), comparisonPages);
                for (const auto& book : bookVector) {
                    std::cout << book << std::endl;
                }
                break;
            }
            default:
                std::cout << "\nВведены неверные данные" << std::endl;
                break;
            }
            break;
        }
        case 'c': {
            std::cout << "\nВыберите характеристку для поиска максимального значения\n"
                << "\nu - поиск по максимальной цене\n"
                << "\nx - поиск по минимальной цене\n"
                << "\nr - поиск по максимальному кол-ву страниц\n"
                << "\np - поиск по минимальному кол-ву страниц\n";
            std::cin >> a;
            switch (a) {
            case 'u': {
                auto comparisonPrice = [](Book& a, Book& b)
                {
                    return a.getPrice() < b.getPrice();
                };
                auto result = std::max_element(bookVector.begin(), bookVector.end(), comparisonPrice);;//Нахождение элемента с максимальной ценой
                std::cout << *result << std::endl;
                break;
            }
            case 'x': {
                auto comparisonPrice = [](Book& a, Book& b)
                {
                    return a.getPrice() > b.getPrice();
                };
                auto result = std::max_element(bookVector.begin(), bookVector.end(), comparisonPrice);//Нахождение элемента с минимальной ценой
                std::cout << *result << std::endl;
                break;
            }
            case 'r': {
                auto comparisonPages = [](Book& a, Book& b)
                {
                    return a.getPages() < b.getPages();
                };
                auto result = std::max_element(bookVector.begin(), bookVector.end(), comparisonPages);//Нахождение элемента с максимальным кол-вом страниц
                std::cout << *result << std::endl;
                break;
            }
            case 'p': {
                auto comparisonPages = [](Book& a, Book& b)
                {
                    return a.getPages() > b.getPages();
                };
                auto result = std::max_element(bookVector.begin(), bookVector.end(), comparisonPages);//Нахождение элемента с минимальной кол-вом страниц
                std::cout << *result << std::endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 'd': {
            std::cout << "\nВыберите характеристику для агрегирования значений\n"
                << "\nu - агрегирование значения кол-ва страниц\n"
                << "\np - агрегирование значения цен книг\n";
            std::cin >> a;
            switch (a) {
            case 'u': {
                auto accumulatePages = [](int accumulator, Book& a)
                {
                    return accumulator + a.getPages();
                };
                auto pagesRes = std::accumulate(bookVector.begin(), bookVector.end(), 0, accumulatePages);
                std::cout << pagesRes << std::endl;
                break;
            }
            case 'p': {
                auto accumulatePrices = [](float accumulator, Book& a)
                {
                    return accumulator + a.getPrice();
                };
                auto priceRes = std::accumulate(bookVector.begin(), bookVector.end(), 0, accumulatePrices);
                std::cout << priceRes << std::endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 'f': {
            std::cout << "\nВыберите характеристику для отбора\n"
                      << "\nu - отбор по кол-ву страниц\n"
                      << "\np - отбор по ценам книг\n";
            std::cin >> a;
            switch (a) {
            case 'u': {
                int i;
                std::cout << "\nВведите минимальное кол-во страниц\n";
                while (!(std::cin >> i) || (i < 0)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nВведены неверные данные" << std::endl;
                };
                for (Book& book : bookVector) {
                    if (book.getPages() >= i) {
                        std::cout << book << std::endl;
                    }
                }
                break;
            }
            case 'p': {
                float i;
                std::cout << "\nВведите минимальную цену книги\n";
                while (!(std::cin >> i) || (i < 0)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nВведены неверные данные" << std::endl;
                };
                for (Book& book : bookVector) {
                    if (book.getPrice() >= i) {
                        std::cout << book << std::endl;
                    }
                }
                break;
            }
            default:
                break;
            }
            break;
        }
        case 'g': {
            std::cout << "\nВыберите характеристику для поиска по значению(первый попавшийся экземпляр)\n"
                << "\nu - поиск по названию книги\n"
                << "\np - поиск по кол-ву страниц\n";
            std::cin >> a;
            switch (a) {
            case 'u': {
                std::string i;
                std::cout << "\nВведите название" << std::endl;
                while (!(std::cin >> i)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nВведены неверные данные" << std::endl;
                }
                for (Book& book : bookVector) {
                    if (book.getName() == i) {
                        std::cout << book << std::endl;
                        break;
                    }
                }
                break;
            }
            case 'p': {
                int i;
                std::cout << "\nВведите кол-во страниц\n";
                while (!(std::cin >> i) || (i < 0)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nВведены неверные данные" << std::endl;
                };
                for (Book& book : bookVector) {
                    if (book.getPages() == i) {
                        std::cout << book << std::endl;
                        break;
                    }
                }
                break;
            }
            default:
                break;
            }
            break;
        }
        case 'w': {
            //Использование итератора для перебора вектора
            for (std::vector<Book>::iterator it = bookVector.begin(); it != bookVector.end(); it++) {
                std::cout << *it << std::endl;
            };
            break;
        }
        case 't': {
            int q = 0;
            for (std::vector<Book>::iterator it = bookVector.begin(); it != bookVector.end(); it++) {
                std::cout<<"ID: " << q <<"\n" << *it << std::endl;
                q++;
            };
            int id;
            std::cout << "\nВведите номер элемента для удаления\n";
            while (!(std::cin >> id) || (id > bookVector.size())) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведены неверные данные" << std::endl;
            };
            bookVector.erase(bookVector.begin()+id);
            break;
        }
        case 'x': {
            std::cout << "\nВыберите функцию\n"
                << "\nu - Запись данных в файл\n"
                << "\np - Чтение данных из файла\n"
                << "\nr - Очистка файла от данных\n";
            std::cin >> a;
            switch (a) {
            case 'u': {
                //Создание файла в случае его отстутствия
                std::string path = "test.txt";
                std::ifstream p(path);
                if (p.fail()) {
                    std::ofstream out("test.txt");
                    out.close();
                    std::cout << "\nФайл создан\n" << std::endl;
                }
                p.close();
                //
                std::ofstream out;// поток для записи данных из вектора
                out.open("test.txt");// открываем файл для записи
                if (out.is_open())
                {
                    for (std::vector<Book>::iterator it = bookVector.begin(); it != bookVector.end(); it++) {
                        out << *it << std::endl;
                    }
                }
                out.close();
                std::cout << "\nЗапись завершена\n" << std::endl;
                break;
            }
            case 'p': {
                std::string path = "test.txt";
                std::ifstream p(path);
                if (p.fail()) {
                    std::ofstream out("test.txt");
                    out.close();
                    std::cout << "\nФайл создан\n" << std::endl;
                }
                p.close();
                std::string fileString;

                std::ifstream in("test.txt"); //окрываем файл для чтения
                std::cout << "\nДанные из файла\n" << std::endl;
                if (in.is_open())
                {
                    while (std::getline(in, fileString))
                    {
                        std::cout << fileString << std::endl;
                    }
                }
                in.close();
                break;
            }
            case 'r': {
                std::string path = "test.txt";
                std::ifstream p(path);
                if (p.fail()) {
                    std::ofstream out("test.txt");
                    out.close();
                    std::cout << "\nФайл создан\n" << std::endl;
                }
                p.close();
                std::ofstream out;
                out.open("test.txt", std::ofstream::out | std::ofstream::trunc); //С помощью опции truncate производим очистку файла
                out.close();
                std::cout << "\nОчистка завершена\n" << std::endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 'e': {
            isActive = false;
            break;
        }
        default:
            break;
        }
    }

}

