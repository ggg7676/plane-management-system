#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PlaneEntry.h"

struct sortById
{
    inline bool operator() (PlaneEntry& a, PlaneEntry& b)
    {
        return a.getId() < b.getId();
    }
};

//Creates an index on Id fro all the entries in Planes.db, thus speeding up the search functionality O(n) -> O(lg n)

void optimize()
{

    std::ifstream inputFile("Planes.db", std::ios::binary);
    if (!inputFile.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }

    inputFile.seekg(0, std::ios::beg);
    std::vector<PlaneEntry> allEntries;
    
    
    while (inputFile.peek() != EOF)
    {
        
        PlaneEntry curr;
        inputFile.read((char*) &curr, sizeof(PlaneEntry));
        allEntries.push_back(curr);
    }

    std::sort(allEntries.begin(), allEntries.end(), sortById());


    
    std::ofstream newDatabase("temp.db", std::ios::binary);
    if (!newDatabase.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }

    newDatabase.seekp(0, std::ios::beg);
    int size = allEntries.size();
    for (int i = 0; i < size; ++i)
    {
        PlaneEntry curr = allEntries[i];
        newDatabase.write((char*) &curr, sizeof(PlaneEntry));
    }

    inputFile.close();
    remove("Planes.db");

    newDatabase.close();
    rename("temp.db", "Planes.db");

    std::cout << "The database has been optimized.\n";
    optimized = true;

}