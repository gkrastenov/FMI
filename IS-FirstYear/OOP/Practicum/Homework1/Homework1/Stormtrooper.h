#pragma once
#include <iostream>
#include <cstring>

#include "Planet.h"
#include "StormtrooperRank.h"

using namespace std;
class Stormtrooper {
private:
    char* id;
    StormtrooperRank rank;
    char* type;
    Planet planet;

public:
    Stormtrooper();
    Stormtrooper(const Stormtrooper& stromtrooper);
    Stormtrooper(const char* id, const StormtrooperRank& rank, const char* type, const Planet& planet);
    ~Stormtrooper();

    void setId(const char* id);
    void setRank(const StormtrooperRank rank);
    void setType(const char* type);
    void setPlanet(const Planet planet);

    char* getId();
    StormtrooperRank getRank();
    char* getType();
    Planet getPlanet();

    Stormtrooper& operator = (const Stormtrooper& stromtrooper);

    friend std::ostream& operator<<(std::ostream& os, Stormtrooper& stormtrooper);

    void print() const;

};