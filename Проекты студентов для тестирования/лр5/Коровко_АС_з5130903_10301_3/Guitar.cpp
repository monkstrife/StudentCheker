#include <iostream>
#include "Guitar.h"

Guitar::Guitar(const std::string &name, int year, int stringsCount)
    : StringInstrument(name, year, stringsCount) {}

void Guitar::Play() const {
    StringInstrument::Play();
    std::cout << "Playing guitar." << std::endl;
}

int Guitar::GetYear() const {
    return year_;
}
