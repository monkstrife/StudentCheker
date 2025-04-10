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
        std::cout << "1. �������� ������\n"
            "2. ������� ������\n"
            "3. �������� ������\n"
            "4. ����������� ������\n"
            "5. ������ � ������������ � ����������� ���\n"
            "6. ���������� ����� ��������\n"
            "7. ����������� ������ �� ���������� ���\n"
            "8. ����� ������ �� ���\n"
            "9. �������� ������� � ����\n"
            "10. ��������� ������� �� �����\n"
            "0. �����\n"
            "������� ��� �����: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            int population;
            float gdp; 

            std::cout << "������� �������� ������: ";
            std::cin >> name;
            std::cout << "������� ���������: ";
            std::cin >> population;
            std::cout << "������� ���: ";
            std::cin >> gdp;

            countries.emplace_back(name, population, gdp);
            break;
        }
        case 2: {
            if (!countries.empty()) {
                std::cout << "������� ����� ��������� ������: ";
                int index;
                std::cin >> index;

                if (index >= 0 && index < countries.size()) {
                    countries.erase(countries.begin() + index);
                    std::cout << "������ ������� �������.\n";
                }
                else {
                    std::cout << "�������� �����\n";
                }
            }
            else {
                std::cout << "������ ����� ������.\n";
            }
            break;
        }
        case 3: {
            for (const auto& country : countries) {
                std::cout << "��������: " << country.GetName() << ", ���������: " << country.GetPopulation()
                    << ", ���: " << country.GetGdp() << std::endl;
            }
            break;
        }
        case 4: {
            std::sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) {
                return a.GetName() < b.GetName();
                });
            std::cout << "������ ������������� �� �����.\n";
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

                std::cout << "������ � ������������ ���: " << maxGDPCountry->GetName() << " GDP: " << maxGDPCountry->GetGdp() << std::endl;
                std::cout << "������ � ����������� ���: " << minGDPCountry->GetName() << " GDP: " << minGDPCountry->GetGdp() << std::endl;
            }
            else {
                std::cout << "������ ����� ������.\n";
            }
            break;
        }
        case 6: {
            if (!countries.empty()) {
                int totalPopulation = std::accumulate(countries.begin(), countries.end(), 0,
                    [](int accumulator, const Country& country) {
                        return accumulator + country.GetPopulation();
                    });

                std::cout << "��������� ���� �����: " << totalPopulation << std::endl;
            }
            else {
                std::cout << "������ ����� ������.\n";
            }
            break;
        }
        case 7: {
            if (!countries.empty()) {
                float threshold;
                std::cout << "������� ��������� ���: ";
                std::cin >> threshold;

                std::vector<Country> filteredCountries;
                std::copy_if(countries.begin(), countries.end(), std::back_inserter(filteredCountries),
                    [threshold](const Country& country) {
                        return country.GetGdp() >= threshold;
                    });

                if (filteredCountries.empty()) {
                    std::cout << "��� ����� � ��� ���� ������.\n";
                }
                else {
                    std::cout << "������ � ��� ���� ������:\n";
                    for (const auto& country : filteredCountries) {
                        std::cout << "��������: " << country.GetName() << ", ���: " << country.GetGdp() << std::endl;
                    }
                }
            }
            else {
                std::cout << "������ ����� ������.\n";
            }
            break;
        }
        case 8: {
            if (!countries.empty()) {
                float value;
                std::cout << "������� ��� ��� ������: ";
                std::cin >> value;

                auto foundCountry = std::find_if(countries.begin(), countries.end(), [value](const Country& country) {
                    return country.GetGdp() == value;
                    });

                if (foundCountry != countries.end()) {
                    std::cout << "������� ������: " << foundCountry->GetName() << " ���: " << foundCountry->GetGdp() << std::endl;
                }
                else {
                    std::cout << "�� ������� ������ � �������� ���.\n";
                }
            }
            else {
                std::cout << "������ ����� ������.\n";
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
                std::cout << "������ �������� � ����.\n";
            }
            else {
                std::cout << "������ ��� �������� �����.\n";
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
                std::cout << "������ ��������� �� �����.\n";
            }
            else {
                std::cout << "������ ��� �������� �����.\n";
            }
            break;
        }

        case 0:
            return 0;
        default:
            std::cout << "������� ���� �� �����, ������������� � ����.\n";
        }
    }
        return 0;
}
