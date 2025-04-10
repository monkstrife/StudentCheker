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
		
		virtual void getInfo();//����� ����� �����������
		virtual void getAll(Person**& arr);//����� ����� ���������� ������� �������
		virtual Person* findOldestPerson(Person**& arr);//����� ������ ������� ��������

		virtual void addToArr(Person* tempP, Person**& arr);//���������� � ������
		static int getCount();//����� ���������� �������� � �������
		static void incrCount();
		static void decrCount();
		virtual void countTypes(Person**& arr);//����� ����� ����� ��������
};