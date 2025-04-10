#ifndef STRINGINSTRUMENT_H
#define STRINGINSTRUMENT_H

#include <string>
#include <iostream>
#include "Instrument.h"

class StringInstrument : public Instrument {

    private:
        int stringsCount;

    public:
        StringInstrument(const std::string& name, int year, int stringsCount);
        
        virtual void Play() const override;

        virtual int GetYear() const override;
};

#endif
