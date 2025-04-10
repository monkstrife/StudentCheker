#pragma once

class Queue
{
private:
	int a;
	int b;
public:
	Queue();
	~Queue();

	void push();
	void pop();
	void search();
	void compareSize();

	Queue& operator= (const Queue& other);
	bool operator> (const Queue& other);
	bool operator>= (const Queue& other);
	bool operator< (const Queue& other);
	bool operator<= (const Queue& other);
	bool operator== (const Queue& other);
	Queue& operator+ (const Queue& other);
	Queue& operator- (const Queue& other);
	Queue& operator+= (const Queue& other);
	Queue& operator-= (const Queue& other);
};