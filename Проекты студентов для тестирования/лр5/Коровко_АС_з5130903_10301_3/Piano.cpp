#include <iostream>
#include "Piano.h"

Piano::Piano(const std::string &name, int year, int keysCount)
    : Instrument(name, year), keysCount(keysCount) {}

void Piano::Play() const {
    Instrument::Play();
    std::cout << "Playing piano with " << keysCount << " keys.";
}

int Piano::GetYear() const {
    return year_;
}
