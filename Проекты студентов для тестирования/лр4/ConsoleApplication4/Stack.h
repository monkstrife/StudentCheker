#pragma once
#include <iostream>

class Stack {
private:
    // У элемента стэка есть значение и приоритет
    struct Element {
        int priority;
        void* data;
    };
    // У стэка есть размер и вместимость (максимальный размер)
    Element* elements;
    int size;
    int capacity;

public:
    // Конструктор
    Stack(int stackSize);

    // Конструктор по умолчанию
    Stack();

    // Очищение стэка
    void clear();

    // Конструктор копирования
    Stack(const Stack& other);

    // Оператор присваивания
    Stack& operator=(const Stack& other);

    // Деструктор
    ~Stack();

    // Методы доступа к закрытым полям
    int getSize() const;    // Получение размера стэка
    int getPriority(int index) const;   // Получение приоритета элемента
    void* getData(int index) const;     // Получение значения элемента

    // Перегрузка операторов - нам понадобятся == и <=
    bool operator==(const Stack& other) const;
    bool operator<=(const Stack& other) const;

    // Объединение и пересечение стэков
    void resize(int newSize);   // Изменение размера стэка
    void unionStacks(const Stack& other);   // объединение
    void intersectStacks(const Stack& other);   // Пересечение

    // Операции с элементами
    void addElement(int priority, void* data);  // Добавление элемента в стэк
    void extractAllWithPriority(int priority);  // Извлечение всех элементов с определенным приоритетом
    bool containsElement(void* data, int priority) const;   // Проверка наличия элемента
    void popElement();  // Извлечение одного элемента из стэка

    // Перегрузки для ввода-вывода
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
    friend std::istream& operator>>(std::istream& is, Stack& stack);
};

void showStack(Stack stack); // Вывод элементов стэка на консоль
bool intInput(); // Проверка на корректность ввода