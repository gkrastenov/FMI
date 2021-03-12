#include <iostream>
using namespace std;


class Jedi {
private:
    char* name;
    Rank rank;
    double midi_chlorian;
    Planet planet;
    char* spicies;
    char* militaryRank;

public:
    // default constructor
    Jedi()
    {
        this->name = nullptr;
        this->midi_chlorian = 0.0;
        this->spicies = nullptr;
        this->militaryRank = nullptr;
    }

    // copy constructor
    Jedi(const Jedi& jedi)
    {
        set_name(jedi.name);
        set_rank(jedi.rank);
        set_midi_chlorian(jedi.midi_chlorian);
        set_planet(jedi.planet);
        set_spicies(jedi.spicies);
        set_militaryRank(jedi.militaryRank);
    }

    // parametric constructor
    Jedi(const char* name, const Rank& rank, const double midi_chlorian, const Planet& planet,
        const char* spicies, const char* militaryRank)
    {
        set_name(name);
        set_rank(rank);
        set_midi_chlorian(midi_chlorian);
        set_planet(planet);
        set_spicies(spicies);
        set_militaryRank(militaryRank);
    }

    void set_name(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

    }

    char* get_name() {
        return this->name;
    }

    void set_rank(const Rank rank) {
        this->rank = rank;
    }

    Rank get_rank() {
        return this->rank;
    }

    void set_midi_chlorian(const double midi_chlorian) {
        this->midi_chlorian, midi_chlorian;
    }

    double get_midi_chlorian() {
        return this->midi_chlorian;
    }

    void set_planet(const Planet planet) {
        this->planet = planet;
    }

    Planet get_planet() {
        return this->planet;
    }

    void set_spicies(const char* spicies) {
        this->spicies = new char[strlen(spicies) + 1];
        strcpy(this->spicies, spicies);
    }

    char* get_spicies() {
        return this->spicies;
    }

    void set_militaryRank(const char* militaryRank) {
        this->militaryRank = new char[strlen(militaryRank) + 1];
        strcpy(this->militaryRank, militaryRank);
    }

    char* get_militaryRank() {
        return this->militaryRank;
    }

    Jedi& operator = (const Jedi& jedi) {
        if (this != &jedi)
        {
            delete[] name;
            this->name = new char[strlen(jedi.name) + 1];
            strcpy(this->name, jedi.name);

            this->rank = jedi.rank;
            this->midi_chlorian = jedi.midi_chlorian;
            this->planet = jedi.planet;

            delete[] spicies;
            this->spicies = new char[strlen(jedi.spicies) + 1];
            strcpy(this->spicies, jedi.spicies);

            delete[] militaryRank;
            this->militaryRank = new char[strlen(jedi.militaryRank) + 1];
            strcpy(this->militaryRank, jedi.militaryRank);
        }

        return *this;
    }

    void print() const {
        cout << "Name: " << name << "Rank: ";
        printRank(rank);
        cout << "Midi Chlorian: " << midi_chlorian;
        planet.print();
        cout << "Spicies: " << spicies << "Military rank" << militaryRank;
    }

    // destructor
    ~Jedi()
    {
        delete[] name;
        midi_chlorian = 0.00;
        delete[] spicies;
        delete[] militaryRank;

        this->name = nullptr;
        this->spicies = nullptr;
        this->militaryRank = nullptr;
    };
};

enum Rank
{
    service_corps,
    knight,
    consular,
    guardian,
    sentinel,
    master
};

class Stromtrooper {
private:
    char* id;
    Rank rank;
    char* type;
    Planet planet;
public:
    // default constructor
    Stromtrooper()
    {
        this->id = nullptr;
        this->type = nullptr;
    }

    // copy constructor
    Stromtrooper(const Stromtrooper& stromtrooper)
    {
        set_id(stromtrooper.id);
        set_rank(stromtrooper.rank);
        set_type(stromtrooper.type);
        set_planet(stromtrooper.planet);
    }

    // parametric constructor
    Stromtrooper(const char* id, const Rank& rank, const char* type, const Planet& planet)
    {
        set_id(id);
        set_rank(rank);
        set_type(type);
        set_planet(planet);
    }

    void set_id(const char* id) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
    }

    char* get_id() {
        return this->id;
    }

    void set_rank(const Rank rank) {
        this->rank = rank;
    }

    Rank get_rank() {
        return this->rank;
    }

    void set_type(const char* type) {
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
    }

    char* get_type() {
        return this->type;
    }

    void set_planet(const Planet planet) {
        this->planet = planet;
    }

    Planet get_planet() {
        return this->planet;
    }

    Stromtrooper& operator = (const Stromtrooper& stromtrooper) {
        if (this != &stromtrooper)
        {
            delete[] id;
            this->id = new char[strlen(stromtrooper.id) + 1];
            strcpy(this->id, stromtrooper.id);

            this->rank = stromtrooper.rank;

            delete[] type;
            this->type = new char[strlen(stromtrooper.type) + 1];
            strcpy(this->type, stromtrooper.type);

            this->planet = stromtrooper.planet;

        }

        return *this;
    }

    void print() const{
        cout << "Id: " << id << "Rank: ";
        printRank(rank);
        cout << "Type: " << type;
        planet.print();
    }

    // destructor
    ~Stromtrooper()
    {
        delete[] id;
        delete[] type;

        this->id = nullptr;
        this->type = nullptr;
    };
};

class Planet {
private:
    char* name;
    char* planetSystem;
    // ��� �� ������������� � ���������.
    char* republic;
public:
    // default constructor
    Planet()
    {
        this->name = nullptr;
        this->planetSystem = nullptr;
        this->republic = nullptr;
    }

    // copy constructor
    Planet(const Planet& planet)
    {
        set_name(planet.name);
        set_planetSystem(planet.planetSystem);
        set_republic(planet.republic);
    }

    // parametric constructor
    Planet(const char* name, const char* planetSystem, const char* republic)
    {
        set_name(name);
        set_planetSystem(planetSystem);
        set_republic(republic);
    }

    void set_name(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    char* get_name() {
        return this->name;
    }

    void set_planetSystem(const char* planetSystem) {
        this->planetSystem = new char[strlen(planetSystem) + 1];
        strcpy(this->planetSystem, planetSystem);
    }

    char* get_planetSystem() {
        return this->planetSystem;
    }

    void set_republic(const char* republic) {
        this->republic = new char[strlen(republic) + 1];
        strcpy(this->republic, republic);
    }

    char* get_republic() {
        return this->republic;
    }

    void print() const {
        cout << "Name: " << name << "Planet System" << planetSystem
            << "republic: " << republic;
    }

    Planet& operator = (const Planet& planet) {
        if (this != &planet)
        {
            delete[] name;
            this->name = new char[strlen(planet.name) + 1];
            strcpy(this->name, planet.name);

            delete[] planetSystem;
            this->planetSystem = new char[strlen(planet.planetSystem) + 1];
            strcpy(this->planetSystem, planet.planetSystem);

            delete[] republic;
            this->republic = new char[strlen(planet.republic) + 1];
            strcpy(this->republic, planet.republic);
        }

        return *this;
    }

    // destructor
    ~Planet() {
        delete[] name;
        delete[] planetSystem;
        delete[] republic;

        this->name = nullptr;
        this->planetSystem = nullptr;
        this->republic = nullptr;
    };
};


void printRank(Rank rank) {
    switch (rank)
    {
    case service_corps:
         cout << "Service Corps";
        break;
    case knight:
        cout << "Knight";
        break;
    case consular:
        cout << "Consular";
        break;
    case guardian:
        cout << "Guardian";
        break;
    case sentinel:
        cout << "Sentinel";
        break;
    case master:
        cout << "Master";
        break;
    default:
        cout << "Without rank";
        break;
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
