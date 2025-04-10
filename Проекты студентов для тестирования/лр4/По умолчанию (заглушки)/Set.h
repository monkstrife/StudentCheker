#pragma once

class Set
{
private:
	int a;
	int b;
public:
	Set();
	~Set();

	void push();
	void pop();
	void search();
	void compareSize();

	Set& operator= (const Set& other);
	bool operator> (const Set& other);
	bool operator>= (const Set& other);
	bool operator< (const Set& other);
	bool operator<= (const Set& other);
	bool operator== (const Set& other);
	Set& operator+ (const Set& other);
	Set& operator- (const Set& other);
	Set& operator+= (const Set& other);
	Set& operator-= (const Set& other);
};