#include <iostream>
#include <fstream>
#include <string>
#include "PlaneEntry.h"

//Deletes an existing PlaneEntry object from the Planes.db database file

void deleteEntry(unsigned long long Id)
{
    std::ifstream inputFile("Planes.db", std::ios::binary);
    if (!inputFile.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }

    inputFile.seekg(0, std::ios::end);
    if (inputFile.tellg() == 0)
    {
        std::cerr << "The database is empty, can't perform delete.\n";
        inputFile.close();

        return;
    }
    
    std::ofstream newDatabase("temp.db", std::ios::binary);
    if (!newDatabase.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }


   inputFile.seekg(0, std::ios::beg);
   newDatabase.seekp(0, std::ios::beg);

   while (inputFile.peek() != EOF)
   {
        
        PlaneEntry curr;
        inputFile.read((char*) &curr, sizeof(PlaneEntry));
        if (curr.getId() != Id)
        {
            newDatabase.write((char*) &curr, sizeof(PlaneEntry));
        }
   }

    inputFile.close();
    remove("Planes.db");

    newDatabase.close();
    rename("temp.db", "Planes.db");

    std::cout << "A plane entry has been deleted from the database.\n";

}