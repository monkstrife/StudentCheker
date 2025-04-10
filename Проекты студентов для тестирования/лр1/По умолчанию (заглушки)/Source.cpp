#include "Source.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool isActive = true;
    while (isActive) {
        std::cout << "Нажмите клавишу для проверки функции :\n"
            "t - Информация по типам\n"
            "m - Минимальное значение из двух аргументов\n"
            "с - Кодировка символа\n"
            "s - Порядок числа\n"
            "e - Выход из программы\n" << std::endl;
        std::string userInput;
        std::cin >> userInput;
        if (userInput.length() == 1) {
            switch (userInput[0]) {
            case 'm':
            {
                std::cout << "Минимальное значение двух аргументов" << std::endl;
                std::string a, b;
                //Ввод двух аргументов с учетом пробелов
                //Т.е. если введено 1.42 1 0.5, то будут прочитаны только 1.42 и 1
                std::cin >> a >> b;
                if (isInt(a) && isInt(b)) {
                    //Приведение string к типу данных int
                    int intA = std::stoi(a);
                    int intB = std::stoi(b);
                    std::cout << "Минимальное значение из введенных аргументов: " << minValue(intA, intB) << std::endl << std::endl;
                }
                else if (isFloat(a) && isFloat(b)) {
                    //Приведение string к типу данных float
                    float floatA = std::stof(a);
                    float floatB = std::stof(b);
                    std::cout << "Минимальное значение из введенных аргументов: " << minValue(floatA, floatB) << std::endl << std::endl;
                }
                else {
                    std::cout << "Введены неверные данные" << std::endl << std::endl;
                }
            }
            std::cin.clear();
            break;
            case 'c':
                std::cout << "Кодировка первого введенного символа" << std::endl;
                char userChar;
                std::cin >> userChar;
                std::cout << "Код символа " << userChar << " :" << getLetterCode(userChar) << std::endl << std::endl;
                std::cin.clear();
                break;
            case 't':
                std::cout << "Информация по типам данных" << std::endl << std::endl;
                showTypeInfo();
                break;
            case 's':
            {
                std::cout << "Порядок числа" << std::endl;
                std::string input;
                //Ввод и прочтение первого аргумента 
                //Т.е. если введено 1234 99 5, то будет прочитано только 1234
                std::cin >> input;
                if (isLL(input)) {
                    long long inputLL = std::stoll(input);
                    std::cout << "Порядко заданного числа: " << order(inputLL) << std::endl << std::endl;
                }
                else {
                    std::cout << "Введены неверные данные" << std::endl;
                }
            }
            std::cin.clear();
            break;
            case 'e':
                std::cout << "Работа приложения прекращена" << std::endl;
                isActive = false;
                break;
            default:
                std::cout << "Введены неверные данные, попробуйте снова" << std::endl;
            }
        }
    }
}

