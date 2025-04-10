#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include "Country.h" 

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Country> countries;

    while (true) {
        std::cout << "1. Добавить страну\n"
            "2. Удалить страну\n"
            "3. Показать страны\n"
            "4. Сортировать страны\n"
            "5. Страны с максимальным и минимальным ВВП\n"
            "6. Подсчитать общие значения\n"
            "7. Фильтровать страны по пороговому ВВП\n"
            "8. Поиск Страны по ВВП\n"
            "9. Записать объекты в файл\n"
            "10. Прочитать объекты из файла\n"
            "0. Выход\n"
            "Введите ваш выбор: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            int population;
            float gdp; 

            std::cout << "Введите название страны: ";
            std::cin >> name;
            std::cout << "Введите население: ";
            std::cin >> population;
            std::cout << "Введите ВВП: ";
            std::cin >> gdp;

            countries.emplace_back(name, population, gdp);
            break;
        }
        case 2: {
            if (!countries.empty()) {
                std::cout << "Введите номер удаляемой страны: ";
                int index;
                std::cin >> index;

                if (index >= 0 && index < countries.size()) {
                    countries.erase(countries.begin() + index);
                    std::cout << "Страна успешно удалена.\n";
                }
                else {
                    std::cout << "Неверный номер\n";
                }
            }
            else {
                std::cout << "Список стран пустой.\n";
            }
            break;
        }
        case 3: {
            for (const auto& country : countries) {
                std::cout << "Название: " << country.GetName() << ", Население: " << country.GetPopulation()
                    << ", ВВП: " << country.GetGdp() << std::endl;
            }
            break;
        }
        case 4: {
            std::sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) {
                return a.GetName() < b.GetName();
                });
            std::cout << "Страны отсортированы по имени.\n";
            break;
        }
        case 5: {
            if (!countries.empty()) {
                auto maxGDPCountry = std::max_element(countries.begin(), countries.end(), [](const Country& a, const Country& b) {
                    return a.GetGdp() < b.GetGdp();
                    });
                auto minGDPCountry = std::min_element(countries.begin(), countries.end(), [](const Country& a, const Country& b) {
                    return a.GetGdp() < b.GetGdp();
                    });

                std::cout << "Страна с максимальным ВВП: " << maxGDPCountry->GetName() << " GDP: " << maxGDPCountry->GetGdp() << std::endl;
                std::cout << "Страна с минимальным ВВП: " << minGDPCountry->GetName() << " GDP: " << minGDPCountry->GetGdp() << std::endl;
            }
            else {
                std::cout << "Список стран пустой.\n";
            }
            break;
        }
        case 6: {
            if (!countries.empty()) {
                int totalPopulation = std::accumulate(countries.begin(), countries.end(), 0,
                    [](int accumulator, const Country& country) {
                        return accumulator + country.GetPopulation();
                    });

                std::cout << "Население всех стран: " << totalPopulation << std::endl;
            }
            else {
                std::cout << "Список стран пустой.\n";
            }
            break;
        }
        case 7: {
            if (!countries.empty()) {
                float threshold;
                std::cout << "Введите пороговое ВВП: ";
                std::cin >> threshold;

                std::vector<Country> filteredCountries;
                std::copy_if(countries.begin(), countries.end(), std::back_inserter(filteredCountries),
                    [threshold](const Country& country) {
                        return country.GetGdp() >= threshold;
                    });

                if (filteredCountries.empty()) {
                    std::cout << "Нет стран с ВВП выше порога.\n";
                }
                else {
                    std::cout << "Страны с ВВП выше порога:\n";
                    for (const auto& country : filteredCountries) {
                        std::cout << "Название: " << country.GetName() << ", ВВП: " << country.GetGdp() << std::endl;
                    }
                }
            }
            else {
                std::cout << "Список стран пустой.\n";
            }
            break;
        }
        case 8: {
            if (!countries.empty()) {
                float value;
                std::cout << "Введите ВВП для поиска: ";
                std::cin >> value;

                auto foundCountry = std::find_if(countries.begin(), countries.end(), [value](const Country& country) {
                    return country.GetGdp() == value;
                    });

                if (foundCountry != countries.end()) {
                    std::cout << "Найдена страна: " << foundCountry->GetName() << " ВВП: " << foundCountry->GetGdp() << std::endl;
                }
                else {
                    std::cout << "Не найдено страны с заданным ВВП.\n";
                }
            }
            else {
                std::cout << "Список стран пустой.\n";
            }
            break;
        }
        case 9: {
            std::ofstream outFile("countries.txt");
            if (outFile.is_open()) {
                for (const auto& country : countries) {
                    outFile << country.GetName() << " " << country.GetPopulation() << " " << country.GetGdp() << "\n";
                }
                outFile.close();
                std::cout << "Страны записаны в файл.\n";
            }
            else {
                std::cout << "Ошибка при открытии файла.\n";
            }
            break;
        }
        case 10: {
            std::ifstream inFile("countries.txt");
            if (inFile.is_open()) {
                std::string name;
                int population;
                float gdp;

                while (inFile >> name >> population >> gdp) {
                    countries.emplace_back(name, population, gdp);
                }
                inFile.close();
                std::cout << "Страны прочитаны из файла.\n";
            }
            else {
                std::cout << "Ошибка при открытии файла.\n";
            }
            break;
        }

        case 0:
            return 0;
        default:
            std::cout << "Введите одну из опций, перечисленных в меню.\n";
        }
    }
        return 0;
}
