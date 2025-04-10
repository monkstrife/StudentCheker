#ifndef GUITAR_H
#define GUITAR_H

#include <string>
#include <iostream>
#include "StringInstrument.h"

class Guitar : public StringInstrument {

    public:
        Guitar(const std::string& name, int year, int stringsCount);

        virtual void Play() const override;

        virtual int GetYear() const override;
    };

#endif
