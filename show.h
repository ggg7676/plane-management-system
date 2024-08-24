#include <iostream>
#include <fstream>
#include "PlaneEntry.h"

//Finds and prints as many PlaneEntry objects as limit is set to be, starting the count from offset

void showEntries(unsigned offset, unsigned limit)
{
    std::ifstream inputFile("Planes.db", std::ios::binary);

    if (!inputFile.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }

    inputFile.seekg(0, std::ios::end);
    unsigned countAllEntries = (unsigned)inputFile.tellg() / (unsigned)sizeof(PlaneEntry);

    if (offset >= countAllEntries)
    {
        std::cout << "Offset is bigger than or equal to the number of database entries.\n";
        return;
    }

    inputFile.seekg((unsigned)sizeof(PlaneEntry) * offset, std::ios::beg);

    limit = (limit + offset > countAllEntries) ? countAllEntries - offset : limit;
    
    unsigned count = 0;
    while(count < limit)
    {
        PlaneEntry curr;
        inputFile.read((char*) &curr, sizeof(PlaneEntry));

        std::cout << curr.getId() << " " << curr.getPlane() << " " << curr.getType() << " " << curr.getFlights() << std::endl;

        ++count;
    }

    inputFile.close();

}