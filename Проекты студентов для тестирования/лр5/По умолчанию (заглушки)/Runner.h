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
        const static inline int marathonDistance = 42;//Статическое, константное поле отвечающее за дистанцию марафона
        
        Runner();
        Runner(std::string name, int age, int coveredDistance, int sportYears);
        virtual ~Runner();

        //Геттеры
        virtual int getCoveredDistance();
        virtual int getSportYears();
        virtual int getCompletedMarathons();

        virtual void getInfo() override;

        //Сеттеры
        void setCoveredDistance(int coveredDistance);
        void setSportYears(int sportYears);
        void setCompletedMarathons(int completedMarathons);

        int calculateMarathons(int coveredDistance);//Метод расчета пройденных марафонов

        virtual Runner* getMostSuccessfullRunner(Person**& arr);//Марафонец пробежавший наибольшую дистанцию

        virtual void getAll(Person**& arr);//Вывод общей информации каждого объекта, с переопределением виртуального метода
        virtual void addToArr(Runner* tempP, Person**& arr);//Добавление объекта в массив
};

