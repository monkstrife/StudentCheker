#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <iostream>

class Instrument {

    protected:
        std::string name_;
        int year_;

    public:
        Instrument(const std::string& name, int year);
    
        virtual ~Instrument() {}

        virtual void Play() const;

        virtual std::string GetInfo() const;

        virtual int GetYear() const;
};

#endif
