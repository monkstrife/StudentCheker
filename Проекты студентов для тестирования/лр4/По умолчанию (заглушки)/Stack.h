#pragma once

class Stack
{
private:
	int a;
	int b;
public:
	Stack();
	~Stack();

	void push();
	void pop();
	void search();
	void compareSize();

	Stack& operator= (const Stack& other);
	bool operator> (const Stack& other);
	bool operator>= (const Stack& other);
	bool operator< (const Stack& other);
	bool operator<= (const Stack& other);
	bool operator== (const Stack& other);
	Stack& operator+ (const Stack& other);
	Stack& operator- (const Stack& other);
	Stack& operator+= (const Stack& other);
	Stack& operator-= (const Stack& other);
};