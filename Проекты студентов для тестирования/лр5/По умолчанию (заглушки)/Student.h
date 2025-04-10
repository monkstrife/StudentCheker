#pragma once
#include "Person.h"
#include <iostream>



class Student :
    public Person
{
    private:
        std::string universityName;
        std::string fieldOfStudy;
        int courseYear;
        
    public:
        Student();
        Student(std::string name, int age, std::string universityName, std::string fieldOfStudy, int courseYear);
        virtual ~Student();
        
        //Геттеры
        std::string getUniversityName();
        std::string getFieldOfStudy();
        int getCourseYear();

        void getInfo() override;

        //Сеттеры
        void setUniversityName(std::string universityName);
        void setFieldOfStudy(std::string universityName);
        void setCourseYear(int courseYear);
        
        Student* getEarliestYearStudent(Person**& arr);//Нахождение студента с самым ранним годом поступления

        void getAll(Person**& arr);//Вывод общей информации каждого объекта, с переопределением виртуального метода
        void addToArr(Student* tempP, Person**& arr);//Добавление объекта в массив
        
        Student& operator= (Student& other);
};
