#include "Employee.h"
#include <iostream>
#include <windows.h>
#ifdef max
#undef max
#endif


Employee::Employee() : Person() {
	this->organizationName = "Unknown";
	this->salary = 0;
	this->workExperience = 0;
}

Employee::Employee(std::string name, int age, std::string organizationName, int salary, int workExperience) : Person(name, age) {
	this->organizationName = organizationName;
	this->salary = salary;
	this->workExperience = workExperience;
}

Employee::~Employee() {
	/*std::cout << "*Deleted*" << std::endl;*/
}



std::string Employee::getOrganizationName() {
	return this->organizationName;
}

int Employee::getSalary() {
	return this->salary;
}

int Employee::getWorkExperience() {
	return this->workExperience;
}



void Employee::setOrganizationName(std::string organizationName) {
	this->organizationName = organizationName;
}

void Employee::setSalary(int salary) {
	this->salary = salary;
}

void Employee::setWorkExperience(int workExperience) {
	this->workExperience = workExperience;
}





void Employee::getInfo() {
	Person::getInfo();
	std::cout << "\nНазвание организации: " << this->organizationName << "\nЗарплата: " << this->salary << "\nОбщий стаж работы: " << this->workExperience << std::endl;
};




void Employee::getAll(Person**& arr) {
	int length = Person::getCount();
	for (int i = 0; i < (length); i++) {
		arr[i]->getInfo();
	}
}

void Employee::addToArr(Employee* tempP, Person**& arr) {
	int length = Person::getCount();
	arr[length] = tempP;
	Person::incrCount();

}


Employee* Employee::getMostPaidEmployee(Person**& arr) {
	int salaryMax = 0;
	Employee* tempQ = nullptr;


	for (int i = 0; i < Person::getCount(); i++) {
		
		if (dynamic_cast<Employee*>(arr[i]) != NULL) {
			Employee* temp = dynamic_cast<Employee*>(arr[i]);
			if (salaryMax < temp->getSalary()) {
				salaryMax = temp->getSalary();
				tempQ = temp;
			}
		}

	}
	return tempQ;
}

void Employee::getRetirementEmployee(Person**& arr) {
	std::cout << "Работающие после пенсионного возраста: " << std::endl;

	for (int i = 0; i < Person::getCount(); i++) {
		Employee* temp = dynamic_cast<Employee*>(arr[i]);
		if (temp) {
			if (Employee::retirementAge <= temp->getAge()) {
				temp->getInfo();
			}
		}

	}
}