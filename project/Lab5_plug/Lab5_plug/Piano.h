#ifndef PIANO_H
#define PIANO_H

#include <string>
#include <iostream>
#include "Instrument.h"

class Piano : public Instrument {

    private:
        int keysCount;

public:
    Piano(const std::string& name, int year, int keysCount);

    virtual void Play() const override;

    virtual int GetYear() const override;

    std::string GetInfo() const override {
        return Instrument::GetInfo() + ", Number of keys: " + std::to_string(keysCount);
    }

    static bool IsStandardKeyCount(int keysCount) {
        return (keysCount >= 88 && keysCount <= 108);
    }
};

#endif
