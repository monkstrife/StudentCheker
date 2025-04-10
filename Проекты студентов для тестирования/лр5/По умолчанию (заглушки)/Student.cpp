#include "Student.h"
#include <iostream>
#include <windows.h>
#ifdef max
#undef max
#endif


Student::Student(): Person() {
	this->universityName = "Unknown";
	this->fieldOfStudy = "Unknown";
	this->courseYear = 1;
}

Student::Student(std::string name, int age, std::string universityName, std::string fieldOfStudy, int courseYear): Person(name, age) {
	this->universityName = universityName;
	this->fieldOfStudy = fieldOfStudy;
	this->courseYear = courseYear;
}


Student::~Student() {
	/*std::cout << "*Deleted*" << std::endl;*/
}



std::string Student::getUniversityName() {
	return this->universityName;
}

std::string Student::getFieldOfStudy() {
	return this->fieldOfStudy;
}

int Student::getCourseYear() {
	return this->courseYear;
}





void Student::setCourseYear(int courseYear) {
	this->courseYear = courseYear;	
}

void Student::setUniversityName(std::string universityName) {
	this->universityName = universityName;
}

void Student::setFieldOfStudy(std::string fieldOfStudy) {
	this->fieldOfStudy = fieldOfStudy;
}



void Student::getInfo() {
	Person::getInfo();
	std::cout << "\nИмя университета: " << this->universityName << "\nНаправление обучения: " << this->fieldOfStudy << "\nКурс обучения: " << this->courseYear << std::endl;
};




void Student::getAll(Person**& arr) {
	int length = Person::getCount();
	for (int i = 0; i < (length); i++) {
		arr[i]->getInfo();

	}
}

void Student::addToArr(Student* tempP, Person**& arr) {
	
	int length = Person::getCount();
	arr[length] = tempP;
	Person::incrCount();
	
}



Student* Student::getEarliestYearStudent(Person**& arr) {
	int eYear = INT_MAX;
	Student* tempQ = nullptr;
	
	
	for (int i = 0; i < Person::getCount(); i++) {
		Student* temp = dynamic_cast<Student*>(arr[i]) ;//динамическое приведение указателя
		if (temp) {
			if (eYear > temp->getCourseYear()) {
				eYear = temp->getCourseYear();
				tempQ = temp;
			}
		}
		
	}
	return tempQ;
}