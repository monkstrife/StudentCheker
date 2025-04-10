#pragma once
#include <iostream>

class Person
{
	private:
		std::string name;
		int age;
		static inline int personCount{ 0 };
	public:
		Person();
		Person(std::string name, int age);
		virtual ~Person();

		virtual std::string getName();
		virtual int getAge();

		virtual void setName(std::string name);
		virtual void setAge(int age);
		
		virtual void getInfo();//Вывод общей информацииы
		virtual void getAll(Person**& arr);//Вывод общей информации каждого объекта
		virtual Person* findOldestPerson(Person**& arr);//Вывод самого старого человека

		virtual void addToArr(Person* tempP, Person**& arr);//Добавление в массив
		static int getCount();//Вывод количества объектов в массиве
		static void incrCount();
		static void decrCount();
		virtual void countTypes(Person**& arr);//Вывод числа типов объектов
};