#include "Book.h"
#include <iostream>
#include <string>


Book::Book() {
	this->pages = 0;
	this->name = "Unknown";
	this->author = "Unknown";
	this->price = 0;
}

Book::Book(int pages, std::string name, std::string author, float price) {
	this->pages = pages;
	this->name = name;
	this->author = author;
	this->price = price;
}

//Конструктор копирования
Book::Book(const Book& other) {
	this->pages = other.pages;
	this->name = other.name;
	this->author = other.author;
	this->price = other.price;
}



Book::~Book() {
	//std::cout << this->getName() << " is deleted" << std::endl;
}

int Book::getPages() {
	return this->pages;
}
std::string Book::getName() {
	return this->name;
}
std::string Book::getAuthor() {
	return this->author;
}
float Book::getPrice() {
	return this->price;
}

void Book::setPages(int pages) {
	this->pages = pages;
}
void Book::setName(std::string name) {
	this->name = name;
}
void Book::setAuthor(std::string author) {
	this->author = author;
}
void Book::setPrice(float price) {
	this->price = price;
}

void Book::showInfo() {
	std::cout << "\nPages: " << this->pages << "\nName: " << this->name << "\nAuthor: " << this->author << "\nPrice: " << this->price << std::endl;
}






