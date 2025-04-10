#pragma once
#include <iostream>

class Stack {
private:
    // � �������� ����� ���� �������� � ���������
    struct Element {
        int priority;
        void* data;
    };
    // � ����� ���� ������ � ����������� (������������ ������)
    Element* elements;
    int size;
    int capacity;

public:
    // �����������
    Stack(int stackSize);

    // ����������� �� ���������
    Stack();

    // �������� �����
    void clear();

    // ����������� �����������
    Stack(const Stack& other);

    // �������� ������������
    Stack& operator=(const Stack& other);

    // ����������
    ~Stack();

    // ������ ������� � �������� �����
    int getSize() const;    // ��������� ������� �����
    int getPriority(int index) const;   // ��������� ���������� ��������
    void* getData(int index) const;     // ��������� �������� ��������

    // ���������� ���������� - ��� ����������� == � <=
    bool operator==(const Stack& other) const;
    bool operator<=(const Stack& other) const;

    // ����������� � ����������� ������
    void resize(int newSize);   // ��������� ������� �����
    void unionStacks(const Stack& other);   // �����������
    void intersectStacks(const Stack& other);   // �����������

    // �������� � ����������
    void addElement(int priority, void* data);  // ���������� �������� � ����
    void extractAllWithPriority(int priority);  // ���������� ���� ��������� � ������������ �����������
    bool containsElement(void* data, int priority) const;   // �������� ������� ��������
    void popElement();  // ���������� ������ �������� �� �����

    // ���������� ��� �����-������
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
    friend std::istream& operator>>(std::istream& is, Stack& stack);
};

void showStack(Stack stack); // ����� ��������� ����� �� �������
bool intInput(); // �������� �� ������������ �����