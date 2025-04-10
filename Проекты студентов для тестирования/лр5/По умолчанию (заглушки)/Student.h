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
        
        //�������
        std::string getUniversityName();
        std::string getFieldOfStudy();
        int getCourseYear();

        void getInfo() override;

        //�������
        void setUniversityName(std::string universityName);
        void setFieldOfStudy(std::string universityName);
        void setCourseYear(int courseYear);
        
        Student* getEarliestYearStudent(Person**& arr);//���������� �������� � ����� ������ ����� �����������

        void getAll(Person**& arr);//����� ����� ���������� ������� �������, � ���������������� ������������ ������
        void addToArr(Student* tempP, Person**& arr);//���������� ������� � ������
        
        Student& operator= (Student& other);
};
