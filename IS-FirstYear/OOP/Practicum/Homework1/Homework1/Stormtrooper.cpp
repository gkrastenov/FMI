#include<iostream>
#include "Stormtrooper.h"

Stormtrooper::Stormtrooper()
{
     this->id = nullptr;
     this->type = nullptr;
}

Stormtrooper::Stormtrooper(const Stormtrooper& stromtrooper)
{
    setId(stromtrooper.id);
    setRank(stromtrooper.rank);
    setType(stromtrooper.type);
    setPlanet(stromtrooper.planet);
}

Stormtrooper::Stormtrooper(const char* id, const StormtrooperRank& rank, const char* type, const Planet& planet)
{
    setId(id);
    setRank(rank);
    setType(type);
    setPlanet(planet);
}

void Stormtrooper::setId(const char* id) {
    size_t length_id = strlen(id) + 1;
    this->id = new char[length_id];
    strcpy_s(this->id, length_id, id);
}

char* Stormtrooper::getId() {
    return this->id;
}

void Stormtrooper::setRank(const StormtrooperRank rank) {
    this->rank = rank;
}

StormtrooperRank Stormtrooper::getRank() {
    return this->rank;
}

void Stormtrooper::setType(const char* type) {
    size_t length_type = strlen(type) + 1;
    this->type = new char[length_type];
    strcpy_s(this->type, length_type, type);
}

char* Stormtrooper::getType() {
    return this->type;
}

void Stormtrooper::setPlanet(const Planet planet) {
    this->planet = planet;
}

Planet Stormtrooper::getPlanet() {
    return this->planet;
}

Stormtrooper& Stormtrooper::operator = (const Stormtrooper& stromtrooper) {
    if (this != &stromtrooper)
    {
        delete[] id;
        size_t length_id = strlen(stromtrooper.id) + 1;
        this->id = new char[length_id];
        strcpy_s(this->id, length_id, stromtrooper.id);

        this->rank = stromtrooper.rank;

        delete[] type;
        size_t length_type = strlen(stromtrooper.type) + 1;
        this->type = new char[length_type];
        strcpy_s(this->type, length_type, stromtrooper.type);

        this->planet = stromtrooper.planet;

    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, Stormtrooper& stormtrooper) {
    os << stormtrooper.id << endl;
    switch (stormtrooper.rank) {
    case Cadet: os << "Cadet" << endl; break;
    case Private: os << "Private" << endl; break;
    case LanceCorporal: os << "Lance Corporal" << endl; break;
    case Corporal: os << "Corporal" << endl; break;
    case Sergeant: os << "Sergeant" << endl; break;
    case StaffSergeant: os << "Staff Sergeant" << endl; break;
    case MasterSergeant: os << "Master Sergeant" << endl; break;
    default: os << "Invalid rank" << endl; break;
    }
    os << stormtrooper.type << endl;
    os << stormtrooper.planet.getName() << endl;
    return os;
}

/*
void Stormtrooper::print() const {
    cout << this;
}*/

Stormtrooper::~Stormtrooper() {
    delete[] id;
    delete[] type;

    this->id = nullptr;
    this->type = nullptr;
};

