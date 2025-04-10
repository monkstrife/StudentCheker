#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

// Конструктор
Stack::Stack(int stackSize) : size(0), capacity(stackSize) {
    elements = new Element[capacity];
}

// Конструктор по умолчанию
Stack::Stack() : size(0), capacity(0), elements(nullptr) {}

// Очищение стэка
void Stack::clear() {
    delete[] elements;
    size = 0;
    capacity = 0;
    elements = nullptr;
}

// Конструктор копирования
Stack::Stack(const Stack& other) : size(other.size), capacity(other.capacity) {
    elements = new Element[capacity];
    for (int i = 0; i < size; ++i) {
        elements[i].priority = other.elements[i].priority;
        // Явно преобразуем указатель other.elements[i].data к типу int*
        int* data = new int(*static_cast<int*>(other.elements[i].data));
        elements[i].data = data;
    }
}

// Оператор присваивания
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) { // Проверка на самоприсваивание
        // Освобождаем память от текущих данных
        for (int i = 0; i < size; ++i) delete static_cast<int*>(elements[i].data);
        delete[] elements;

        // Выделяем новую память
        size = other.size;
        capacity = other.capacity;
        elements = new Element[capacity];

        // Копируем данные в другой стэк
        for (int i = 0; i < size; ++i) {
            elements[i].priority = other.elements[i].priority;
            int* data = new int(*static_cast<int*>(other.elements[i].data));
            elements[i].data = data;
        }
    }
    return *this;
}

// Деструктор
Stack::~Stack() {
    for (int i = 0; i < size; ++i) {
        delete static_cast<int*>(elements[i].data);
    }
    delete[] elements;
}

// Получение размера стэка
int Stack::getSize() const {
    return size;
}

// Получение приоритета элемента
int Stack::getPriority(int index) const {
    if ((index >= 0) && (index < size)) return elements[index].priority;
    else {
        cout << "Индекс некорректен" << endl;
        return -1;
    }
}

// Получение значения элемента
void* Stack::getData(int index) const {
    if (index >= 0 && index < size) return elements[index].data;
    else {
        cout << "Индекс некорректен" << endl;
        return nullptr;
    }
}

// Перегрузка ==
bool Stack::operator==(const Stack& other) const {
    // Размеры стэков должны совпадать
    if (size != other.size) {
        return false;
    }
    // Элементы и приоритеты должны совпадать
    for (int i = 0; i < size; ++i) {
        if ((elements[i].data != other.elements[i].data) ||
            (elements[i].priority != other.elements[i].priority)) {
            return false;
        }
    }
    return true;
}

// Перегрузка <=
bool Stack::operator<=(const Stack& other) const {
    return size <= other.size;
}

// Изменение размера стэков для объединения или пересечения
void Stack::resize(int newSize) {
    // Если новый размер не превышает текущую вместимость, ничего не делаем
    if (newSize <= capacity) return;

    // Новый стэк с новым размером
    Element* newElements = new Element[newSize];

    // Копируем существующие элементы в новый стэк
    for (int i = 0; i < size; ++i) newElements[i] = elements[i];

    // Освобождаем старый стэк
    delete[] elements;

    // Обновляем указатель на новый стэк и устанавливаем новую вместимость
    elements = newElements;
    capacity = newSize;
}

// Объединение стэков
void Stack::unionStacks(const Stack& other) {
    // Увеличиваем размер стэка до суммы размеров обоих стэков
    int newSize = size + other.size;
    resize(newSize);

    // Добавляем туда элементы из второго стэка, проверяя на дубликаты
    for (int i = 0; i < other.size; ++i) {
        if (!containsElement(other.elements[i].data, other.elements[i].priority)) {
            elements[size] = other.elements[i];
            ++size;
        }
    }
}

// Пересечение стэков
void Stack::intersectStacks(const Stack& other) {
    // Создаем временный стэк для хранения результата
    Stack result(size);

    // Добавляем туда элементы, если они есть в обоих стэках
    for (int i = 0; i < size; ++i) {
        if (other.containsElement(elements[i].data, elements[i].priority)) {
            result.addElement(elements[i].priority, elements[i].data);
        }
    }

    // Обновляем текущий стэк и удаляем из него старые элементы
    size = result.size;
    capacity = result.capacity;
    delete[] elements;

    // Ставим указатель на elements временного стэка и очищаем его
    elements = result.elements;
    result.elements = nullptr;
    result.size = 0;
    result.capacity = 0;
}

// Добавление элемента в стэк
void Stack::addElement(int priority, void* data) {
    // Если в стэке уже есть такой элемент, ничего не делаем
    for (int i = 0; i < size; ++i) {
        if (elements[i].priority == priority && elements[i].data == data) return;
    }

    // Проверяем, не полон ли стэк
    if (size >= capacity) {
        cout << "Стэк полон. Нельзя добавить больше элементов" << endl;
        return;
    }

    // Добавляем элемент в стэк
    elements[size].priority = priority;
    elements[size].data = data;
    ++size;
}

// Извлечение всех элементов с определенным приоритетом
void Stack::extractAllWithPriority(int priority) {
    // Новый размер стэка после извлечения элементов
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (elements[i].priority != priority) {
            // Оставляем элементы с другими приоритетами в стэке
            elements[newSize] = elements[i];
            ++newSize;
        }
    }
    size = newSize;
}


// Проверка наличия элемента
bool Stack::containsElement(void* data, int priority) const {
    // Используем явное преобразование (int*), чтобы разыменовать указатели и сравнить значения, на которые они указывают
    for (int i = 0; i < size; ++i) {
        if (elements[i].priority == priority && *(int*)elements[i].data == *(int*)data) return true;
    }
    return false;
}

// Извлечение одного элемента из стэка
void Stack::popElement() {
    if (size > 0) {
        // Ищем самый большой индекс
        int highestPriorityIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (elements[i].priority > elements[highestPriorityIndex].priority) highestPriorityIndex = i;
        }

        // Освобождаем память
        delete static_cast<int*>(elements[highestPriorityIndex].data);

        // Если есть несколько элементов с одинаковым приоритетом, извлекаем последний добавленный
        if (highestPriorityIndex != (size - 1)) elements[highestPriorityIndex] = elements[size - 1];

        size--;
    }
    else cout << "Стэк пуст" << endl;
}

// Перегрузка для вывода на консоль
std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    for (int i = 0; i < stack.getSize(); ++i) {
        os << "Элемент: " << stack.getData(i) << 
            "  Его приоритет: " << stack.getPriority(i) << endl;
        return os; // Ссылка на объект потока вывода
    }
}

// Перегрузка для ввода с консоли
std::istream& operator>>(std::istream& is, Stack& stack) {
    int priority;
    void* data;
    is >> priority >> data;
    stack.addElement(priority, data);
    return is; // Ссылка на объект потока ввода
}

// Вывод элементов стэка на консоль
void showStack(Stack stack) {
    cout << "Текущие значения элементов стэка: " << endl;
    for (int i = 0; i < stack.getSize(); ++i) {
        cout << "Значение: " << *static_cast<int*>(stack.getData(i)) <<
            "  Его приоритет: " << stack.getPriority(i) << endl;
    }
}

// Проверка на корректность ввода
bool intInput() {
    if (cin.fail()) {
        cout << "Некорректный ввод. Введите целочисленное значение" << endl;
        cin.clear();  // Сброс состояния ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка буфера ввода
        return false;
    }
    return true;
}