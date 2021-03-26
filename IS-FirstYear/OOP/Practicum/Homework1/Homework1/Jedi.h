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
    Jedi();
    Jedi(const Jedi& jedi);
    Jedi(const char* name, const JediRank& rank, const double midiChlorian, const Planet& planet,
        const char* species, const char* militaryRank);
    ~Jedi();

    void setName(const char* name);
    void setRank(const JediRank rank);
    void setMidiChlorian(const double midiChlorian);
    void setPlanet(const Planet planet);
    void setSpicies(const char* species);
    void setMilitaryRank(const char* militaryRank);

    char* getName();
    JediRank getJediRank();
    double getMidiChlorian();
    Planet getPlanet();
    char* getSpicies();
    char* getMilitaryRank();

    Jedi& operator = (const Jedi& jedi);

    friend std::ostream& operator<<(std::ostream& os, Jedi& jedi);

    void print(Jedi& jedi){}
};
