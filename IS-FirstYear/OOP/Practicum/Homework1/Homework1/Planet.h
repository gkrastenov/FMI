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
    // default constructor
    Planet();
    // copy constructor
    Planet(const Planet& planet);
    // parametric constructor
    Planet(const char* name, const char* planetSystem, const char* republic);

    // setters and getters
    void setName(const char* name);
    char* getName();

    void setPlanetSystem(const char* planetSystem);
    char* getPlanetSystem();

    void setRepublic(const char* republic);
    char* getRepublic();

    // operatos
    Planet& operator=(const Planet& planet);
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);

    template<class T>
    void print(T print) {
        cout << print << endl;
    }

    // destructor
    ~Planet();
};
