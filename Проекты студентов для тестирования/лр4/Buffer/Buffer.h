#pragma once
#include <array>
#include <iostream>

const int MAX_SIZE = 100;

class CircularBuffer {
private:
    int bufferSize;
    std::array<int, MAX_SIZE> buffer;
    int head;
    int tail;
    int count;

public:
    CircularBuffer(int size);
    CircularBuffer(const CircularBuffer& other);
    ~CircularBuffer();

    void addElement(int element);
    int removeElement();
    std::array<int, MAX_SIZE> removeMultipleElements(int numElements);
    void printFreeSpace();
    bool contains(int element);
    void merge(const CircularBuffer& other);
    void intersect(const CircularBuffer& other);
    bool operator>(const CircularBuffer& other) const;
    friend std::ostream& operator<<(std::ostream& os, const CircularBuffer& buffer) {
        os << "Buffer Content: ";
        for (int i = 0; i < buffer.count; ++i) {
            os << buffer.buffer[(buffer.head + i) % buffer.bufferSize] << " ";
        }
        os << std::endl;
        return os;
    }
};


