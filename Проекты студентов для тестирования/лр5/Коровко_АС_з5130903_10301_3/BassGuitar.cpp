#include <iostream>
#include "BassGuitar.h"

int BassGuitar::totalFrets = 5;

BassGuitar::BassGuitar(const std::string &name, int year, int stringsCount)
    : Guitar(name, year, stringsCount), stringsCount(stringsCount) {}

void BassGuitar::Play() const {
    Guitar::Play();
    std::cout << "Playing bass guitar with " << totalFrets << " frets." << std::endl;
}

int BassGuitar::GetYear() const {
    return year_;
}
