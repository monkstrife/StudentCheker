#include <iostream>
#include <map>
#include <vector>
#include <typeinfo>
#include "Instrument.h"
#include "Piano.h"
#include "BassGuitar.h"

Instrument* createInstrumentOfType(int choice) {
    Instrument* instrument = nullptr;

    switch (choice) {
        case 1: {
            std::string name;
            int year, numKeys;
            
            std::cout << "Enter piano details:\n";
            std::cout << "Name: ";
            std::cin.ignore(); 
            std::getline(std::cin, name); 
            std::cout << "Year: ";
            std::cin >> year;
            std::cout << "Number of keys: ";
            std::cin >> numKeys;
            
            instrument = new Piano(name, year, numKeys);
            break;
        } 
        case 2: {
            std::string name;
            int year, stringsCount;

            std::cout << "Enter bass guitar details:\n";
            std::cout << "Name: ";
            std::cin.ignore(); 
            std::getline(std::cin, name);
            std::cout << "Year: ";
            std::cin >> year;
            std::cout << "Number of strings: ";
            std::cin >> stringsCount;

            instrument = new BassGuitar(name, year, stringsCount);
            break;
        } 
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
    return instrument;
}

void printNewestInstruments(std::vector<Instrument*> instruments) {
    Guitar* newestGuitar = nullptr;
    Piano* newestPiano = nullptr;

    for (Instrument* inst : instruments) {
        Guitar* guitar = dynamic_cast<Guitar*>(inst);
        if (guitar && (!newestGuitar || guitar->GetYear() > newestGuitar->GetYear())) {
            newestGuitar = guitar;
        }

        Piano* piano = dynamic_cast<Piano*>(inst);
        if (piano && (!newestPiano || piano->GetYear() > newestPiano->GetYear())) {
            newestPiano = piano;
        }
    }

    if (newestGuitar) {
        std::cout << "Newest Guitar: " << newestGuitar->GetInfo() << std::endl;
    } else {
        std::cout << "No Guitar found!" << std::endl;
    }

    if (newestPiano) {
        std::cout << "Newest Piano: " << newestPiano->GetInfo() << std::endl;
    } else {
        std::cout << "No Piano found!" << std::endl;
    }
}

int main() {
    std::vector<Instrument*> instruments;

    int choice;
    do {
        std::cout << "Menu:\n"
                  << "1. Create an instrument\n"
                  << "2. Print information about each instrument\n"
                  << "3. Count the number of each instrument\n"
                  << "4. Print newest instruments\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Choose the type of instrument to create:\n"
                          << "1. Piano\n"
                          << "2. Bass Guitar\n"
                          << "Enter your choice: ";
                int instrumentChoice;
                std::cin >> instrumentChoice;

                Instrument* newInstrument = createInstrumentOfType(instrumentChoice);
                if (newInstrument != nullptr) {
                    instruments.push_back(newInstrument);
                }
                break;
            }
            case 2: {
                std::cout << "Printing information about each instrument:\n";
                for (Instrument* inst : instruments) {
                    std::cout << inst->GetInfo() << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Counting the number of each instrument:\n";

                std::map<std::string, int> instrumentCount;

                for (Instrument* inst : instruments) {
                    std::string typeName = typeid(*inst).name();
                    instrumentCount[typeName]++;
                }

                for (const auto& count : instrumentCount) {
                    std::cout << "Type: " << count.first << ", Count: " << count.second << std::endl;
                }
                break;
            }
            case 4:
                printNewestInstruments(instruments);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 4);

    for (Instrument* inst : instruments) {
        delete inst;
    }

    return 0;
}
