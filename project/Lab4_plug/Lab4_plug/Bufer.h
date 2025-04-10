#pragma once

class Bufer
{
private:
	int a;
	int b;
public:
	Bufer();
	~Bufer();

	void push();
	void pop();
	void search();
	void compareSize();

	Bufer& operator= (const Bufer& other);
	bool operator> (const Bufer& other);
	bool operator>= (const Bufer& other);
	bool operator< (const Bufer& other);
	bool operator<= (const Bufer& other);
	bool operator== (const Bufer& other);
	Bufer& operator+ (const Bufer& other);
	Bufer& operator- (const Bufer& other);
	Bufer& operator+= (const Bufer& other);
	Bufer& operator-= (const Bufer& other);
};