#pragma once
#include <string>
class Country
{
public:
    Country(std::string&, int, float);
    void SetName(std::string&);
    void SetPopulation(int);
    void SetGdp(float);
    std::string GetName() const;
    int GetPopulation() const;
    float GetGdp() const;
        
private:
    std::string name;
    int population;
    float gdp;
};

inline
void Country::SetName(std::string& str)
{
    name = str;
}

inline
void Country::SetPopulation(int pop)
{
    population = pop;
}

inline
void Country::SetGdp(float gd)
{
    gdp = gd;
}


