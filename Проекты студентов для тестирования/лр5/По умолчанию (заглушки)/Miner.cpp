#include "Miner.h"
#include <iostream>
#include <windows.h>
#ifdef max
#undef max
#endif


Miner::Miner() : Employee() {
	this->workerGrade = "Unknown";
	this->mineName = "Unknowns";
	this->workSpecializationExperience = 0;
}

Miner::Miner(std::string name, int age, std::string organizationName, int salary, int workExperience, 
	std::string workerGrade, std::string mineName, int workSpecializationExperience)

	: Employee(name, age, organizationName, salary, workExperience) {
	this->workerGrade = workerGrade;
	this->mineName = mineName;
	if (workSpecializationExperience <= workExperience) {
		this->workSpecializationExperience = workSpecializationExperience;
	}
	else {
		this->workSpecializationExperience = workExperience;
	}
	
}

Miner::~Miner() {
}

std::string Miner::getSpecialization() {
	return this->specialization;
}

std::string Miner::getWorkerGrade() {
	return this->workerGrade;
}

std::string Miner::getMineName() {
	return this->mineName;
}

int Miner::getWorkSpecializationExperience() {
	return this->workSpecializationExperience;
}



void Miner::setWorkerGrade(std::string workerGrade) {
	this->workerGrade = workerGrade;
}

void Miner::setMineName(std::string mineName) {
	this->mineName = mineName;
}

void Miner::setWorkSpecializationExperience(int workSpecializationExperience) {
	this->workSpecializationExperience = workSpecializationExperience;
}





void Miner::getInfo() {
	Employee::getInfo();
	std::cout << "\nШахтерский разряд: " << this->workerGrade << "\nНазвание шахты: " << this->mineName <<"\nСтаж работы по специальности: " << this->workSpecializationExperience << std::endl;
};




void Miner::getAll(Person**& arr) {
	int length = Person::getCount();
	for (int i = 0; i < (length); i++) {
		arr[i]->getInfo();
	}
}

void Miner::addToArr(Miner* tempP, Person**& arr) {
	int length = Person::getCount();
	arr[length] = tempP;
	Person::incrCount();

}
