#include "Country.h"

Country::Country(std::string& nm, int pop, float gd) : name(nm), population(pop), gdp(gd)
{}

std::string Country::GetName() const
{
	return name;
}

int Country::GetPopulation() const
{
	return population;
}

float Country::GetGdp() const
{
	return gdp;
}