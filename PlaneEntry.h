#pragma once
#include <cstring>

bool optimized = false;
const int MAX_NAME_LEN = 256;

class PlaneEntry
{
    unsigned long long Id;
    char Plane[MAX_NAME_LEN];
    char Type[MAX_NAME_LEN];
    unsigned long long Flights;

public:

    void setId(unsigned long long Id);
    void setPlane(char* Plane);
    void setType(char* Type);
    void setFlights(unsigned long long Flights);

    unsigned long long getId();
    char* getPlane();
    char* getType();
    unsigned long long getFlights();
};


void PlaneEntry::setId(unsigned long long Id)
{
    this->Id = Id;
}

void PlaneEntry::setPlane(char* Plane)
{
    strcpy(this->Plane, Plane);
}

void PlaneEntry::setType(char* Type)
{
    strcpy(this->Type, Type);
}

void PlaneEntry::setFlights(unsigned long long Flights)
{
    this->Flights = Flights;
}

unsigned long long PlaneEntry:: getId()
{
    return Id;
}

char* PlaneEntry::getPlane()
{
    return Plane;
}

char* PlaneEntry::getType()
{
    return Type;
}

unsigned long long PlaneEntry::getFlights()
{
    return Flights;
}