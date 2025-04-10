#pragma once

class Heap
{
private:
	int a;
	int b;
public:
	Heap();
	~Heap();

	void push();
	void pop();
	void search();
	void compareSize();

	Heap& operator= (const Heap& other);
	bool operator> (const Heap& other);
	bool operator>= (const Heap& other);
	bool operator< (const Heap& other);
	bool operator<= (const Heap& other);
	bool operator== (const Heap& other);
	Heap& operator+ (const Heap& other);
	Heap& operator- (const Heap& other);
	Heap& operator+= (const Heap& other);
	Heap& operator-= (const Heap& other);
};