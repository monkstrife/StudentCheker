#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Miner.h"
#include "Runner.h"
#include <iostream>


Person::Person() {
	this->name = "Unknown";
	this->age = NULL;
}

Person::Person(std::string name, int age) {
	this->name = name;
	this->age = age;
}

Person::~Person() {
}

std::string Person::getName() {
	return this->name;
}

int Person::getAge() {
	return this->age;
}



void Person::setName(std::string name) {
	this->name = name;
}

void Person::setAge(int age) {
	this->age = age;
}



void Person::getAll(Person**& arr) {
	int length = personCount;
	for (int i = 0; i < (length); i++) {
		arr[i]->getInfo();
		
	}
}

void Person::getInfo() {
	std::cout << "\n//////////////////" << std::endl;
	std::cout << "\nИмя: " << this->name << "\nВозраст: " << this->age << std::endl;
};

void Person::addToArr(Person* tempP, Person**& arr) {
	int length = personCount;
	arr[length] = tempP;
	++personCount;
}

int Person::getCount() {
	return personCount;
}
void Person::incrCount() {
	++personCount;
}
void Person::decrCount() {
	--personCount;
}

Person* Person::findOldestPerson(Person**& arr) {
	int maxAge = 0;
	Person* tempP = nullptr;
	for (int i = 0; i < personCount; i++) {
		if (maxAge < arr[i]->getAge()) {
			tempP = arr[i];
			maxAge = arr[i]->getAge();
		}
	}
	return tempP;
}

//Счетчик типов классов
void Person::countTypes(Person**& arr) {
	Person tempP;
	Student tempS;
	Employee tempE;
	Miner tempM;
	Runner tempR;
	int count = 0;
	int personTypeCounter = 0;
	int studentTypeCounter = 0;
	int employeeTypeCounter = 0;
	int minerTypeCounter = 0;
	int runnerTypeCounter = 0;


	for (int i = 0; i < Person::getCount(); i++) {
		//Проверка типа класса с помощью его имени
		if (typeid(*arr[i]).name() == typeid(tempP).name()) {
			personTypeCounter++;
			count++;
		} 
		else if(typeid(*arr[i]).name() == typeid(tempS).name()) {
			studentTypeCounter++;
			count++;
		} 
		else if(typeid(*arr[i]).name() == typeid(tempE).name()) {
			employeeTypeCounter++;
			count++;
		}
		else if(typeid(*arr[i]).name() == typeid(tempM).name()) {
			minerTypeCounter++;
			count++;
		}
		else if(typeid(*arr[i]).name() == typeid(tempR).name()) {
			runnerTypeCounter++;
			count++;
		}
	}
	std::cout << "\nPerson: " << personTypeCounter << "\nStudent: " << studentTypeCounter << "\nEmployee: " << employeeTypeCounter 
			  << "\nMiner: " << minerTypeCounter << "\nRunner: " << runnerTypeCounter << "\nВсего: " << count << std::endl;
}