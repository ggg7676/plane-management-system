#include <iostream>
#include <fstream>
#include "PlaneEntry.h"

//Creates a new PlaneEntry object and adds it to the Planes.db database file

void createEntry(unsigned long long Id, char Plane[MAX_NAME_LEN], char Type[MAX_NAME_LEN], unsigned long long Flights)
{
    std::ofstream outputFile("Planes.db", std::ios::app | std::ios::binary);
    if (!outputFile.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }

    PlaneEntry newPlane;
    newPlane.setId(Id);
    newPlane.setPlane(Plane);
    newPlane.setType(Type);
    newPlane.setFlights(Flights);
    
    outputFile.write((char*) &newPlane, sizeof(PlaneEntry));
 
    outputFile.close();

    std::cout<<"A new plane entry has been added to the database.\n";
    optimized = false;
    
}