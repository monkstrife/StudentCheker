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
        const static inline int retirementAge = 65;//�����������, ����������� ���� ���������� �� ����� ���������� �������
        
        Employee();
        Employee(std::string name, int age, std::string organizationName, int salary, int workExperience);
        virtual ~Employee();
        
        //�������
        virtual std::string getOrganizationName();
        virtual int getSalary();
        virtual int getWorkExperience();

        virtual void getInfo() override;

        //�������
        void setOrganizationName(std::string organizationName);
        void setSalary(int salary);
        void setWorkExperience(int workExperience);

        virtual Employee* getMostPaidEmployee(Person**& arr);//���������� �������� ������������� ���������
        virtual void getRetirementEmployee(Person**& arr);//���������� ���������� ��������������� ��������
        
        virtual void getAll(Person**& arr);//����� ����� ���������� ������� �������, � ���������������� ������������ ������ 
        virtual void addToArr(Employee* tempP, Person**& arr);//���������� ������� � ������
};

