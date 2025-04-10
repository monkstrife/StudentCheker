#pragma once
#include <string>
#include <iostream>

class Book
{
	private:
		int pages;
		std::string name;
		std::string author;
		float price;
	public:

		Book();
		Book(int pages, std::string name, std::string author, float price);
		Book(const Book& other);
		~Book();

		int getPages();
		std::string getName();
		std::string getAuthor();
		float getPrice();

		void setPages(int pages);
		void setName(std::string name);
		void setAuthor(std::string author);
		void setPrice(float price);

		void showInfo();

		//Операция присваивания
		int operator()(int a, int b)
    		{
        		return a < b;
    		}
		Book& operator= (const Book& other)
		{
			if (&other == this) return *this;
			this->pages = other.pages;
			this->name = other.name;
			this->author = other.author;
			this->price = other.price;
			return *this;
		}

		friend std::ostream& operator << (std::ostream& os, const Book& book)
		{
			return os << "\nPages: " << book.pages << "\nName: " << book.name << "\nAuthor: " << book.author << "\nPrice: " << book.price << std::endl;
		}
};

