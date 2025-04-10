#pragma once
#include "Person.h"
class Runner :
    public Person
{
    private:
        int coveredDistance;
        int sportYears;
        int completedMarathons;

    public:
        const static inline int marathonDistance = 42;//�����������, ����������� ���� ���������� �� ��������� ��������
        
        Runner();
        Runner(std::string name, int age, int coveredDistance, int sportYears);
        virtual ~Runner();

        //�������
        virtual int getCoveredDistance();
        virtual int getSportYears();
        virtual int getCompletedMarathons();

        virtual void getInfo() override;

        //�������
        void setCoveredDistance(int coveredDistance);
        void setSportYears(int sportYears);
        void setCompletedMarathons(int completedMarathons);

        int calculateMarathons(int coveredDistance);//����� ������� ���������� ���������

        virtual Runner* getMostSuccessfullRunner(Person**& arr);//��������� ����������� ���������� ���������

        virtual void getAll(Person**& arr);//����� ����� ���������� ������� �������, � ���������������� ������������ ������
        virtual void addToArr(Runner* tempP, Person**& arr);//���������� ������� � ������
};

