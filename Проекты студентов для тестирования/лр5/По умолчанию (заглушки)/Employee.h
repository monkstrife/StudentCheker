#pragma once
#include "Person.h"

class Employee :
    public Person
{
    private:
        std::string organizationName;
        int salary;
        int workExperience;

    public:
        const static inline int retirementAge = 65;//Статическое, константное поле отвечающее за общий пенсионный возраст
        
        Employee();
        Employee(std::string name, int age, std::string organizationName, int salary, int workExperience);
        virtual ~Employee();
        
        //Геттеры
        virtual std::string getOrganizationName();
        virtual int getSalary();
        virtual int getWorkExperience();

        virtual void getInfo() override;

        //Сеттеры
        void setOrganizationName(std::string organizationName);
        void setSalary(int salary);
        void setWorkExperience(int workExperience);

        virtual Employee* getMostPaidEmployee(Person**& arr);//Нахождение наиболее оплачиваемого работника
        virtual void getRetirementEmployee(Person**& arr);//Нахождение работников постпенсионного возраста
        
        virtual void getAll(Person**& arr);//Вывод общей информации каждого объекта, с переопределением виртуального метода 
        virtual void addToArr(Employee* tempP, Person**& arr);//Добавление объекта в массив
};

