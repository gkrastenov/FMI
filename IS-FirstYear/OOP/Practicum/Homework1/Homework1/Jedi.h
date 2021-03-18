#pragma once
#include <iostream>
#include <cstring>

#include "Planet.h"
#include "JediRank.h"

using namespace std;
class Jedi {
private:
    char* name;
    JediRank rank;
    double midiChlorian;
    Planet planet;
    char* species;
    char* militaryRank;

public:
    // default constructor
    Jedi();
    // copy constructor
    Jedi(const Jedi& jedi);
    // parametric constructor
    Jedi(const char* name, const JediRank& rank, const double midiChlorian, const Planet& planet,
        const char* species, const char* militaryRank);

    // setters and getters
    void setName(const char* name);
    char* getName();

    void setRank(const JediRank rank);
    JediRank getJediRank();

    void setMidiChlorian(const double midiChlorian);
    double getMidiChlorian();

    void setPlanet(const Planet planet);
    Planet getPlanet();

    void setSpicies(const char* species);
    char* getSpicies();

    void setMilitaryRank(const char* militaryRank);
    char* getMilitaryRank();

    // operators
    Jedi& operator = (const Jedi& jedi);
    friend std::ostream& operator<<(std::ostream& os, Jedi& jedi);

    // methods
    void print(Jedi& jedi){}

    // destructor
    ~Jedi();
};
