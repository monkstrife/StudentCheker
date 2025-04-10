#include <iostream>
#include "Instrument.h"

Instrument::Instrument(const std::string &name, int year)
    : name_(name), year_(year) {}

void Instrument::Play() const {
    std::cout << "Playing " << name_ << " (" << year_ << ")" << std::endl;
}

std::string Instrument::GetInfo() const {
    return "Name: " + name_ + ", Year: " + std::to_string(year_);
}

int Instrument::GetYear() const {
    return year_;
}
