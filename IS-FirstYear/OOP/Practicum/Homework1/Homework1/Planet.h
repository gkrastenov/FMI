#pragma once
#include <iostream>
#include"PlanetType.h"

using namespace std;

class Planet {
private:
    char* name;
    char* planetSystem;
    char* republic;
    PlanetType type;

public:
    Planet();
    Planet(const Planet& planet);
    Planet(const char* name, const char* planetSystem, const char* republic);
    ~Planet();

    void setName(const char* name);
    void setPlanetSystem(const char* planetSystem);
    void setRepublic(const char* republic);

    char* getName();
    char* getPlanetSystem();
    char* getRepublic();

    Planet& operator=(const Planet& planet);

    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);

    template<class T>
    void print(T print) {
        cout << print << endl;
    }
};
