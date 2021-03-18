#include<iostream>
#include"Planet.h"

using namespace std;

Planet::Planet()
{
    this->name = nullptr;
    this->planetSystem = nullptr;
    this->republic = nullptr;
}


Planet::Planet(const Planet& planet)
{
    setName(planet.name);
    setPlanetSystem(planet.planetSystem);
    setRepublic(planet.republic);
}


Planet::Planet(const char* name, const char* planetSystem, const char* republic)
{
    setName(name);
    setPlanetSystem(planetSystem);
    setRepublic(republic);
}

void Planet::setName(const char* name) {
    size_t lengthName = strlen(name) + 1;
    this->name = new char[lengthName];
    strcpy_s(this->name, lengthName, name);
}

char* Planet::getName() {
    return this->name;
}

void Planet::setPlanetSystem(const char* planetSystem) {
    size_t lengthPlanetSystem = strlen(planetSystem) + 1;
    this->planetSystem = new char[lengthPlanetSystem];
    strcpy_s(this->planetSystem, lengthPlanetSystem, planetSystem);
}

char* Planet::getPlanetSystem() {
    return this->planetSystem;
}

void Planet::setRepublic(const char* republic) {
    size_t lengthRepublic = strlen(republic) + 1;
    this->republic = new char[lengthRepublic];
    strcpy_s(this->republic, lengthRepublic, republic);
}

char* Planet::getRepublic() {
    return this->republic;
}

std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << planet.name << endl;
    os << planet.planetSystem << endl;
    os << planet.republic << endl;
    switch (planet.type) {
    case Chthonian: os << "Chthonian Planet" << endl; break;
    case Carbon: os << "Carbon Planet" << endl; break;
    case Coreless: os << "Coreless Planet" << endl; break;
    case Desert: os << "Desert Planet" << endl; break;
    case GasDwarf: os << "Gas Dwarf" << endl; break;
    case GasGiant: os << "Gas Giant" << endl; break;
    case Helium: os << "Helium Planet" << endl; break;
    case IceGiant: os << "Ice Giant" << endl; break;
    case Ice: os << "Ice Planet" << endl; break;
    case Iron: os << "Iron Planet" << endl; break;
    case Lava: os << "Lava Planet" << endl; break;
    case Ocean: os << "Ocean Planet" << endl; break;
    case Protoplanet: os << "Protopanet" << endl; break;
    case Puffy: os << "Puffy Planet" << endl; break;
    case Silicate: os << "Silicate Planet" << endl; break;
    case Terrestrial: os << "Terrestrial Planet" << endl; break;
    default: os << "Invalid type" << endl; break;
    }
    return os;
}

Planet& Planet::operator=(const Planet& planet) {
    if (this != &planet)
    {
        delete[] name;
        size_t lengthName = strlen(planet.name) + 1;
        this->name = new char[lengthName];
        strcpy_s(this->name, lengthName, planet.name);

        delete[] planetSystem;
        size_t lengthPlanetSystem = strlen(planet.planetSystem) + 1;
        this->planetSystem = new char[lengthPlanetSystem];
        strcpy_s(this->planetSystem, lengthPlanetSystem, planet.planetSystem);

        delete[] republic;
        size_t lengthRepublic = strlen(planet.republic) + 1;
        this->republic = new char[lengthRepublic];
        strcpy_s(this->republic, lengthRepublic, planet.republic);
    }

    return *this;
}

Planet::~Planet() {
    delete[] name;
    delete[] planetSystem;
    delete[] republic;

    this->name = nullptr;
    this->planetSystem = nullptr;
    this->republic = nullptr;
};
