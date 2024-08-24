#include <iostream>
#include <fstream>
#include <string>
#include "PlaneEntry.h"

//Updates an attribute of an existing PlaneEntry object in the Planes.db database file

void updateEntry(unsigned long long Id)
{
    
    std::cout<<"Enter the attribute you'd like to update: ";
    std::string attribute;
    std::cin>>attribute;

    while (attribute !=  "Id" && attribute != "Plane" && attribute != "Type" && attribute != "Flights")
    {
        std::cout << "Invalid attribute input. Retry query with correct input.\n";
        std::cout<<"Enter the attribute you'd like to update: ";
        attribute.clear();
        std::cin>>attribute;
    }

    std::cout<<"Enter the new value of " << attribute << ": ";
    std::string newValue;
    std::cin>>newValue;

    std::ifstream inputFile("Planes.db", std::ios::binary);
    if (!inputFile.good())
    {
        std::cerr << "File couldn't be opened.";
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
            
            if (curr.getId() == Id)
            {
                if (attribute == "Id")
                {
                    curr.setId(stoi(newValue));
                    optimized = false;
                }

                else if (attribute == "Plane")
                {
                    char plane[MAX_NAME_LEN];
                    int len = newValue.length();
                    for(int i = 0; i < len; ++i)
                    {
                        plane[i] = newValue[i];
                    }

                    curr.setPlane(plane);
                }

                else if (attribute == "Type")
                {
                    char type[MAX_NAME_LEN];
                    int len = newValue.length();
                    for(int i = 0; i < len; ++i)
                    {
                        type[i] = newValue[i];
                    }

                    curr.setType(type);
                }

                else if (attribute == "Flights")
                {
                    curr.setFlights(stoi(newValue));
                }

                
            }

            newDatabase.write((char*) &curr, sizeof(PlaneEntry));
    }

    inputFile.close();
    remove("Planes.db");

    newDatabase.close();
    rename("temp.db", "Planes.db");

    std::cout << "A plane entry has been updated.\n";
}