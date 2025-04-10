#ifndef BASSGUITAR_H
#define BASSGUITAR_H

#include <string>
#include <iostream>
#include "Guitar.h"

class BassGuitar : public Guitar {

    private:
        static int totalFrets;
        int stringsCount;

    public:
        BassGuitar(const std::string& name, int year, int stringsCount);

        virtual void Play() const override;

        virtual int GetYear() const override;

        std::string GetInfo() const override {
           return Instrument::GetInfo() + ", Number of strings: " + std::to_string(stringsCount);
        }

        static int GetTotalFrets() {
            return totalFrets;
        }
    };

#endif
