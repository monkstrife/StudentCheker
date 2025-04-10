#include "Runner.h"
#include <iostream>
#include <windows.h>
#ifdef max
#undef max
#endif


Runner::Runner() : Person() {
	this->coveredDistance = 0;
	this->sportYears = 0;
	this->completedMarathons = 0;
}

Runner::Runner(std::string name, int age, int coveredDistance, int sportYears) : Person(name, age) {
	this->coveredDistance = coveredDistance;
	this->sportYears = sportYears;
	this->completedMarathons = calculateMarathons(coveredDistance);
}

Runner::~Runner() {
}



int Runner::getCoveredDistance() {
	return this->coveredDistance;
}

int Runner::getSportYears() {
	return this->sportYears;
}

int Runner::getCompletedMarathons() {
	return this->completedMarathons;
}



void Runner::setCoveredDistance(int coveredDistance) {
	this->coveredDistance = coveredDistance;
}

void Runner::setSportYears(int sportYears) {
	this->sportYears = sportYears;
}

void Runner::setCompletedMarathons(int completedMarathons) {
	this->completedMarathons = completedMarathons;
}





void Runner::getInfo() {
	Person::getInfo();
	std::cout << "\nОбщая пройденная дистанция: " << this->coveredDistance << "\nЛет спорта: " << this->sportYears 
			  << "\nПройденных марафонов: " << this->completedMarathons << std::endl;
};




void Runner::getAll(Person**& arr) {
	int length = Person::getCount();
	for (int i = 0; i < (length); i++) {
		arr[i]->getInfo();
	}
}

void Runner::addToArr(Runner* tempP, Person**& arr) {
	int length = Person::getCount();
	arr[length] = tempP;
	Person::incrCount();

}


Runner* Runner::getMostSuccessfullRunner(Person**& arr) {
	int covDistTemp = 0;
	Runner* tempQ = nullptr;


	for (int i = 0; i < Person::getCount(); i++) {

		if (dynamic_cast<Runner*>(arr[i]) != NULL) {
			Runner* temp = dynamic_cast<Runner*>(arr[i]);
			if (covDistTemp < temp->getCoveredDistance()) {
				covDistTemp = temp->getCoveredDistance();
				tempQ = temp;
			}
		}

	}
	return tempQ;
}

int Runner:: calculateMarathons(int coveredDistance) {
	return coveredDistance / Runner::marathonDistance;//обращение к статическому константному полю для вычисления пройденных марафонов
};