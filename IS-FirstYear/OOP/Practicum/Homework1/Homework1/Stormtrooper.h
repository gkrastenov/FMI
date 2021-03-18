#pragma once
#include <iostream>
#include <cstring>

#include "Planet.h"
#include "JediRank.h"
#include "StormtrooperRank.h"

using namespace std;
class Stormtrooper {
private:
    char* id;
    StormtrooperRank rank;
    char* type;
    Planet planet;

public:
    // default constructor
    Stormtrooper();
    // copy constructor
    Stormtrooper(const Stormtrooper& stromtrooper);
    // parametric constructor
    Stormtrooper(const char* id, const StormtrooperRank& rank, const char* type, const Planet& planet);

    void setId(const char* id);
    char* getId();

    void setRank(const StormtrooperRank rank);
    StormtrooperRank getRank();

    void setType(const char* type);
    char* getType();

    void setPlanet(const Planet planet);
    Planet getPlanet();

    // operators
    Stormtrooper& operator = (const Stormtrooper& stromtrooper);
    friend std::ostream& operator<<(std::ostream& os, Stormtrooper& stormtrooper);

    // methods
    void print() const;

    // destructor
    ~Stormtrooper();
};