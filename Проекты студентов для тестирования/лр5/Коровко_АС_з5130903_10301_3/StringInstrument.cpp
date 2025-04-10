#include <iostream>
#include "StringInstrument.h"

StringInstrument::StringInstrument(const std::string &name, int year, int stringsCount)
    : Instrument(name, year), stringsCount(stringsCount) {}

void StringInstrument::Play() const {
    Instrument::Play();
    std::cout << "Playing string instrument with " << stringsCount << " strings." << std::endl;
}

int StringInstrument::GetYear() const {
    return year_;
}
