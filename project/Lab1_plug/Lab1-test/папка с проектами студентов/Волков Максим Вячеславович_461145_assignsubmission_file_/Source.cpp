#include "Source.h"

int main()
{
    char symbol, letter;
    float fx, bottom, top, ffirst, fsecond;
    int x, first, second;

    while (true)
    {
        cout << "=============================" << endl;
        cout << "Нажмите клавишу для проверки функции:" << endl;
        cout << "b - Принадлежность значения к интервалу" << endl;
        cout << "m - Минимальное значение из двух целочисленных аргументов" << endl;
        cout << "f - Минимальное значение из двух вещественных аргументов" << endl;
        cout << "o - Порядок числа" << endl;
        cout << "c - Числовое представление символа" << endl;
        cout << "t - Информация о типах" << endl;
        cout << "e - Выход из программы" << endl;

        cin >> symbol;

        // В случае если введено несколько символов,
        // необходимо очистить оставшиеся уже прочитанное лишнее
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (symbol)
        {
            case 'b':
                cout << "Введите значение: ";
                if (!(cin >> fx))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Введите нижнюю границу: ";
                if (!(cin >> bottom))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Введите верхнюю границу: ";
                if (!(cin >> top))
                {
                    handleInvalidInput();
                    break;
                }

                if (belongsToInterval(fx, top, bottom))
                    cout << "Значение принадлежит интервалу" << endl;
                else
                    cout << "Значение не принадлежит интервалу" << endl;

                break;
            
            case 'm':
                cout << "Введите первое значение: ";
                if (!(cin >> first))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Введите второе значение: ";
                if (!(cin >> second))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Минимальное значение: " << minValue(first, second) << endl;
                break;

            case 'f':
                cout << "Введите первое значение: ";
                if (!(cin >> ffirst))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Введите второе значение: ";
                if (!(cin >> fsecond))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Минимальное значение: " << minValue(ffirst, fsecond) << endl;
                break;

            case 'o':
                cout << "Введите значение: ";
                if (!(cin >> x))
                {
                    handleInvalidInput();
                    break;
                }

                cout << "Порядок числа (количество знаков): " << order(x) << endl;
                break;

            case 'c':
                cout << "Введите символ: ";
                cin >> letter;                

                cout << "Числовой код символа: " << getLetterCode(letter) << endl;

                // В случае если введено несколько символов,
                // необходимо очистить оставшиеся уже прочитанное лишнее
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;

            case 't':
                showTypeInfo();
                break;

            case 'e':
                exit(0);
                break;

            default:
                cout << "Введен некорректный или отсутствующий в меню символ. Попробуйте снова" << endl;
                break;
        }
    }
}
