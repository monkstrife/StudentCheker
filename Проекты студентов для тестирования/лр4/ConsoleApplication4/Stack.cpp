#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

// �����������
Stack::Stack(int stackSize) : size(0), capacity(stackSize) {
    elements = new Element[capacity];
}

// ����������� �� ���������
Stack::Stack() : size(0), capacity(0), elements(nullptr) {}

// �������� �����
void Stack::clear() {
    delete[] elements;
    size = 0;
    capacity = 0;
    elements = nullptr;
}

// ����������� �����������
Stack::Stack(const Stack& other) : size(other.size), capacity(other.capacity) {
    elements = new Element[capacity];
    for (int i = 0; i < size; ++i) {
        elements[i].priority = other.elements[i].priority;
        // ���� ����������� ��������� other.elements[i].data � ���� int*
        int* data = new int(*static_cast<int*>(other.elements[i].data));
        elements[i].data = data;
    }
}

// �������� ������������
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) { // �������� �� ����������������
        // ����������� ������ �� ������� ������
        for (int i = 0; i < size; ++i) delete static_cast<int*>(elements[i].data);
        delete[] elements;

        // �������� ����� ������
        size = other.size;
        capacity = other.capacity;
        elements = new Element[capacity];

        // �������� ������ � ������ ����
        for (int i = 0; i < size; ++i) {
            elements[i].priority = other.elements[i].priority;
            int* data = new int(*static_cast<int*>(other.elements[i].data));
            elements[i].data = data;
        }
    }
    return *this;
}

// ����������
Stack::~Stack() {
    for (int i = 0; i < size; ++i) {
        delete static_cast<int*>(elements[i].data);
    }
    delete[] elements;
}

// ��������� ������� �����
int Stack::getSize() const {
    return size;
}

// ��������� ���������� ��������
int Stack::getPriority(int index) const {
    if ((index >= 0) && (index < size)) return elements[index].priority;
    else {
        cout << "������ �����������" << endl;
        return -1;
    }
}

// ��������� �������� ��������
void* Stack::getData(int index) const {
    if (index >= 0 && index < size) return elements[index].data;
    else {
        cout << "������ �����������" << endl;
        return nullptr;
    }
}

// ���������� ==
bool Stack::operator==(const Stack& other) const {
    // ������� ������ ������ ���������
    if (size != other.size) {
        return false;
    }
    // �������� � ���������� ������ ���������
    for (int i = 0; i < size; ++i) {
        if ((elements[i].data != other.elements[i].data) ||
            (elements[i].priority != other.elements[i].priority)) {
            return false;
        }
    }
    return true;
}

// ���������� <=
bool Stack::operator<=(const Stack& other) const {
    return size <= other.size;
}

// ��������� ������� ������ ��� ����������� ��� �����������
void Stack::resize(int newSize) {
    // ���� ����� ������ �� ��������� ������� �����������, ������ �� ������
    if (newSize <= capacity) return;

    // ����� ���� � ����� ��������
    Element* newElements = new Element[newSize];

    // �������� ������������ �������� � ����� ����
    for (int i = 0; i < size; ++i) newElements[i] = elements[i];

    // ����������� ������ ����
    delete[] elements;

    // ��������� ��������� �� ����� ���� � ������������� ����� �����������
    elements = newElements;
    capacity = newSize;
}

// ����������� ������
void Stack::unionStacks(const Stack& other) {
    // ����������� ������ ����� �� ����� �������� ����� ������
    int newSize = size + other.size;
    resize(newSize);

    // ��������� ���� �������� �� ������� �����, �������� �� ���������
    for (int i = 0; i < other.size; ++i) {
        if (!containsElement(other.elements[i].data, other.elements[i].priority)) {
            elements[size] = other.elements[i];
            ++size;
        }
    }
}

// ����������� ������
void Stack::intersectStacks(const Stack& other) {
    // ������� ��������� ���� ��� �������� ����������
    Stack result(size);

    // ��������� ���� ��������, ���� ��� ���� � ����� ������
    for (int i = 0; i < size; ++i) {
        if (other.containsElement(elements[i].data, elements[i].priority)) {
            result.addElement(elements[i].priority, elements[i].data);
        }
    }

    // ��������� ������� ���� � ������� �� ���� ������ ��������
    size = result.size;
    capacity = result.capacity;
    delete[] elements;

    // ������ ��������� �� elements ���������� ����� � ������� ���
    elements = result.elements;
    result.elements = nullptr;
    result.size = 0;
    result.capacity = 0;
}

// ���������� �������� � ����
void Stack::addElement(int priority, void* data) {
    // ���� � ����� ��� ���� ����� �������, ������ �� ������
    for (int i = 0; i < size; ++i) {
        if (elements[i].priority == priority && elements[i].data == data) return;
    }

    // ���������, �� ����� �� ����
    if (size >= capacity) {
        cout << "���� �����. ������ �������� ������ ���������" << endl;
        return;
    }

    // ��������� ������� � ����
    elements[size].priority = priority;
    elements[size].data = data;
    ++size;
}

// ���������� ���� ��������� � ������������ �����������
void Stack::extractAllWithPriority(int priority) {
    // ����� ������ ����� ����� ���������� ���������
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (elements[i].priority != priority) {
            // ��������� �������� � ������� ������������ � �����
            elements[newSize] = elements[i];
            ++newSize;
        }
    }
    size = newSize;
}


// �������� ������� ��������
bool Stack::containsElement(void* data, int priority) const {
    // ���������� ����� �������������� (int*), ����� ������������ ��������� � �������� ��������, �� ������� ��� ���������
    for (int i = 0; i < size; ++i) {
        if (elements[i].priority == priority && *(int*)elements[i].data == *(int*)data) return true;
    }
    return false;
}

// ���������� ������ �������� �� �����
void Stack::popElement() {
    if (size > 0) {
        // ���� ����� ������� ������
        int highestPriorityIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (elements[i].priority > elements[highestPriorityIndex].priority) highestPriorityIndex = i;
        }

        // ����������� ������
        delete static_cast<int*>(elements[highestPriorityIndex].data);

        // ���� ���� ��������� ��������� � ���������� �����������, ��������� ��������� �����������
        if (highestPriorityIndex != (size - 1)) elements[highestPriorityIndex] = elements[size - 1];

        size--;
    }
    else cout << "���� ����" << endl;
}

// ���������� ��� ������ �� �������
std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    for (int i = 0; i < stack.getSize(); ++i) {
        os << "�������: " << stack.getData(i) << 
            "  ��� ���������: " << stack.getPriority(i) << endl;
        return os; // ������ �� ������ ������ ������
    }
}

// ���������� ��� ����� � �������
std::istream& operator>>(std::istream& is, Stack& stack) {
    int priority;
    void* data;
    is >> priority >> data;
    stack.addElement(priority, data);
    return is; // ������ �� ������ ������ �����
}

// ����� ��������� ����� �� �������
void showStack(Stack stack) {
    cout << "������� �������� ��������� �����: " << endl;
    for (int i = 0; i < stack.getSize(); ++i) {
        cout << "��������: " << *static_cast<int*>(stack.getData(i)) <<
            "  ��� ���������: " << stack.getPriority(i) << endl;
    }
}

// �������� �� ������������ �����
bool intInput() {
    if (cin.fail()) {
        cout << "������������ ����. ������� ������������� ��������" << endl;
        cin.clear();  // ����� ��������� ������
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� ������ �����
        return false;
    }
    return true;
}