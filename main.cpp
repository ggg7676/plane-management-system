#include <iostream>
#include <fstream>
#include "PlaneEntry.h"
#include "create.h"
#include "delete.h"
#include "update.h"
#include "search.h"
#include "show.h"
#include "optimize.h"
using namespace std;

int main()
{
    cout << "Welcome to the plane management system!\n";

    string command;
    getline(cin, command);

    while (command != "exit")
    {
        if(command == "create")
        {
            cout << "Enter the plane's id, name, type and number of flights: ";

            unsigned long long Id;
            char Plane[MAX_NAME_LEN];
            char Type[MAX_NAME_LEN];
            unsigned long long Flights;

            cin >> Id >> Plane >> Type >> Flights;
            
            createEntry(Id, Plane, Type, Flights);
        }

        else if (command == "delete")
        {
            cout << "Enter the plane's id: ";

            unsigned long long Id;
            cin >> Id;
            deleteEntry(Id);
        }

        else if (command == "update")
        {
            cout << "Enter the plane's id: ";

            unsigned long long Id;
            cin >> Id;
            updateEntry(Id);
        }

        else if (command == "search")
        {
            cout << "Enter the plane's id: ";

            unsigned long long Id;
            cin >> Id;
            searchEntry(Id);
        }

        else if (command == "show")
        {
            cout << "Enter the offset and number of entries to be shown: ";
            unsigned offset;
            cin >> offset;

            unsigned limit;
            cin >> limit;

            showEntries(offset, limit);
        }

        else if (command == "optimize")
        {
            optimize();
        }

        else 
        {
            cout << "Invalid command. Retry with valid inut.\n";
        }

        command.clear();
        cin >> command;
    }

    return 0;
}