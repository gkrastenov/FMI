#include "Jedi.h"
#include<cstring>
#include<iostream>

Jedi::Jedi()
{
        this->name = nullptr;
        this->midiChlorian = 0.0;
        this->species = nullptr;
        this->militaryRank = nullptr;
}

Jedi::Jedi(const Jedi& jedi)
 {
        setName(jedi.name);
        setRank(jedi.rank);
        setMidiChlorian(jedi.midiChlorian);
        setPlanet(jedi.planet);
        setSpicies(jedi.species);
        setMilitaryRank(jedi.militaryRank);
}

Jedi::Jedi(const char* name, const JediRank& rank, const double midiChlorian, const Planet& planet,
    const char* spicies, const char* militaryRank)
{
    setName(name);
    setRank(rank);
    setMidiChlorian(midiChlorian);
    setPlanet(planet);
    setSpicies(spicies);
    setMilitaryRank(militaryRank);
}

void Jedi::setName(const char* name) {
    size_t lengthName = strlen(name) + 1;
    this->name = new char[lengthName];
    strcpy_s(this->name, lengthName, name);
}

char* Jedi::getName() {
      return this->name;
}

void Jedi::setRank(const JediRank rank) {
     this->rank = rank;
}

JediRank Jedi::getJediRank() {
     return this->rank;
}

void Jedi::setMidiChlorian(const double midi_chlorian) {
     this->midiChlorian, midi_chlorian;
}

double Jedi::getMidiChlorian() {
       return this->midiChlorian;
}

void Jedi::setPlanet(const Planet planet) {
      this->planet = planet;
}

Planet Jedi::getPlanet() {
       return this->planet;
}

void Jedi::setSpicies(const char* spicies) {
    size_t lengthSpicies = strlen(spicies) + 1;
    this->species = new char[lengthSpicies];
    strcpy_s(this->species, lengthSpicies, spicies);
}

char* Jedi::getSpicies() {
       return this->species;
}

void Jedi::setMilitaryRank(const char* militaryRank) {
    size_t lengthMilitaryRank = strlen(militaryRank) + 1;
    this->militaryRank = new char[lengthMilitaryRank];
    strcpy_s(this->militaryRank, lengthMilitaryRank, militaryRank);
}

char* Jedi::getMilitaryRank() {
      return this->militaryRank;
}

Jedi& Jedi::operator = (const Jedi& jedi) {
     if (this != &jedi)
     {
        delete[] name;
        size_t lengthName = strlen(jedi.name) + 1;
        this->name = new char[lengthName];
        strcpy_s(this->name, lengthName, jedi.name);

        this->rank = jedi.rank;
        this->midiChlorian = jedi.midiChlorian;
        this->planet = jedi.planet;

        delete[] species;
        size_t lengthSpicies = strlen(jedi.species) + 1;
        this->species = new char[lengthSpicies];
        strcpy_s(this->species, lengthSpicies, jedi.species);

        delete[] militaryRank;
        size_t lengthMilitaryRank = strlen(jedi.militaryRank) + 1;
        this->militaryRank = new char[lengthMilitaryRank];
        strcpy_s(this->militaryRank, lengthMilitaryRank, jedi.militaryRank);
     }
     return *this;
}

std::ostream& operator<<(std::ostream& os, Jedi& jedi) {
    os << jedi.name << endl;
    switch (jedi.rank) {
    case Youngling: os << "Youngling" << endl; break;
    case Padawan: os << "Padawan" << endl; break;
    case Knight: os << "Knight" << endl; break;
    case Consular: os << "Consular" << endl; break;
    case Guardian: os << "Guardian" << endl; break;
    case Sentinel: os << "Sentinel" << endl; break;
    case Master: os << "Master" << endl; break;
    default: os << "Invalid rank" << endl; break;
    }
    os << jedi.midiChlorian << endl;
    os << jedi.planet.getName() << endl;
    os << jedi.species << endl;
    os << jedi.militaryRank << endl;
    return os;
}

/*
void Jedi::print(Jedi& jedi){
    std::cout << jedi;
}
*/

Jedi::~Jedi()
{
      delete[] name;
      midiChlorian = 0.00;
      delete[] species;
      delete[] militaryRank;

      this->name = nullptr;
      this->species = nullptr;
      this->militaryRank = nullptr;
 };