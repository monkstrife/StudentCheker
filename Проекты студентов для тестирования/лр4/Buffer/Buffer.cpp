#include "Buffer.h"
#include <iostream>

CircularBuffer::CircularBuffer(int size) : bufferSize(size), head(0), tail(0), count(0) {
    if (size > MAX_SIZE || size <= 0) {
        bufferSize = MAX_SIZE;
    }
}

CircularBuffer::CircularBuffer(const CircularBuffer& other)
    : bufferSize(other.bufferSize), buffer(other.buffer), head(other.head),
    tail(other.tail), count(other.count) {}

CircularBuffer::~CircularBuffer() {}

void CircularBuffer::addElement(int element) {
    if (count < bufferSize) {
        buffer[tail] = element;
        tail = (tail + 1) % bufferSize;
        count++;
    }
}

int CircularBuffer::removeElement() {
    if (count > 0) {
        int removed = buffer[head];
        head = (head + 1) % bufferSize;
        count--;
        return removed;
    }
        return -1;
}

std::array<int, MAX_SIZE> CircularBuffer::removeMultipleElements(int numElements) {
    std::array<int, MAX_SIZE> elements;
    if (numElements <= count) {
        for (int i = 0; i < numElements; ++i) {
            elements[i] = removeElement();
        }
    }
    return elements;
}

void CircularBuffer::printFreeSpace() {
    std::cout << "Свободное место: " << bufferSize - count << std::endl;
}

bool CircularBuffer::contains(int element) {
    for (int i = 0; i < count; ++i) {
        if (buffer[i] == element) {
            return true;
        }
    }
    return false;
}

void CircularBuffer::merge(const CircularBuffer& other) {
    if (count + other.count <= bufferSize) {
        for (int i = 0; i < other.count; ++i) {
            addElement(other.buffer[(other.head + i) % other.bufferSize]);
        }
        std::cout << "Да." << std::endl;
    }
    else {
        std::cout << "Нет." << std::endl;
    }
}

void CircularBuffer::intersect(const CircularBuffer& other) {
    std::array<int, MAX_SIZE> intersectedBuffer;
    int intersectCount = 0;

    for (int i = 0; i < other.count; ++i) {
        int element = other.buffer[(other.head + i) % other.bufferSize];
        if (contains(element) && intersectCount < bufferSize) {
            intersectedBuffer[intersectCount] = element;
            intersectCount++;
        }
    }

    count = intersectCount;
    for (int i = 0; i < intersectCount; ++i) {
        buffer[i] = intersectedBuffer[i];
    }
    head = 0;
    tail = intersectCount;

    std::cout << "Да." << std::endl;
}

bool CircularBuffer::operator>(const CircularBuffer& other) const {
    return bufferSize > other.bufferSize;
}
