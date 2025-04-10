#pragma once
#include "Employee.h"
class Miner :
    public Employee
{
    private:
        const std::string specialization = "Miner";
        std::string workerGrade;
        std::string mineName;
        int workSpecializationExperience;

    public:
        Miner();
        Miner(std::string name, int age, std::string organizationName, int salary, int workExperience, 
              std::string workerGrade, std::string mineName, int workSpecializationExperience);
        virtual ~Miner();

        //Геттеры
        std::string getSpecialization();
        std::string getWorkerGrade();
        std::string getMineName();
        int getWorkSpecializationExperience();

        virtual void getInfo() override;

        //Сеттеры
        void setWorkerGrade(std::string workerGrade);
        void setMineName(std::string mineName);
        void setWorkSpecializationExperience(int workSpecializationExperience);

        virtual void getAll(Person**& arr);//Вывод общей информации каждого объекта, с переопределением виртуального метода 
        virtual void addToArr(Miner* tempP, Person**& arr);//Добавление объекта в массив
};

