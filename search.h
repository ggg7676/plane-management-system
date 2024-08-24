#include <iostream>
#include <fstream>
#include "PlaneEntry.h"

//Finds and prints all atributes of an existing PlaneEntry object from the Planes.db database file

void searchEntry(unsigned long long Id)
{   
    std::ifstream inputFile("Planes.db", std::ios::binary);

    if (!inputFile.good())
    {
        std::cerr << "File couldn't be opened.";
        return;
    }

    inputFile.seekg(0, std::ios::beg);

    //If the database has not been optimized since the last new or chaged entry,
    //searching for an entry takes O(n) time
    if (!optimized)
    {
        while(inputFile.peek() != EOF)
        {
            PlaneEntry curr;

            inputFile.read((char*) &curr, sizeof(PlaneEntry));
            if(curr.getId() == Id)
            {
                std::cout << curr.getId() << " " << curr.getPlane() << " " << curr.getType() << " " << curr.getFlights() << std::endl;
            }
        }
    }

    //If the database has been optimized and no new entries have been added or current ones changed since then,
    //searching for an entry takes O(lg n) time
    else 
    {
        inputFile.seekg(0, std::ios::end);
        int countAllEntries = inputFile.tellg() / sizeof(PlaneEntry);
        
        inputFile.seekg(0, std::ios::beg);

        int left = 0;
        int right = countAllEntries - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            PlaneEntry curr;

            inputFile.seekg(mid * sizeof(PlaneEntry), std::ios::beg);
            inputFile.read((char*) &curr, sizeof(PlaneEntry));

            if (curr.getId() == Id)
            {
                std::cout << curr.getId() << " " << curr.getPlane() << " " << curr.getType() << " " << curr.getFlights() << std::endl;
                break;
            }

            else if (curr.getId() > Id)
            {
                right = mid - 1;
            }

            else 
            {
                left = mid + 1;
            }
        }
        
    }

    inputFile.close();
}