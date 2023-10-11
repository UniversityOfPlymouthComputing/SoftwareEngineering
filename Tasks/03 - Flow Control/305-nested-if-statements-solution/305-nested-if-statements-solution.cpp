/*

    If statements

    Note here that I am using the C++ cout to write to the console. You can use printf if you prefer,
    but I want to start moving towards C++ and away from C where there are advantages

*/

#include <iostream>

// The fuly qualified name for cout is actually std::cout
// :: is known as the "scoping operator" - more on this later
// std is known as a "namespace" - it is a prefix that helps us avoid replicating names
// The standard C++ library uses std:: prefix for many of it's functions
// It is tedious to write this every time, so we make the default namespace std
using namespace std;

int main()
{
    //Some constants 
    const int high = 100, low = 10;

    // start filling the tank 
    int level = 5;

    //Read the keyboad to get the level
    //Repeat until a valid value has been added
    do {
        cout << "Please enter a level (between 0 and 100)" << endl;
        cin >> level;
    } while ((level < 0) || (level > 100)); //Repeat until a valid number is entered


    if (level <= low)                       // check the level
    {
        cout << "Tank needs filling ";
        if (level == 0) {
            cout << "urgently as you your tank is actually empty!" << endl;
        }
        else {
            cout << "very soon as it is low" << endl;
        }
    }
    else //Ok, it is > low, so do the following.....
    {
        cout << "Tank has sufficient fuel for now. ";
        if (level < 100) {
            cout << "You could top it up if you wish." << endl;
        } else {
            cout << "It is actually full." << endl;
        }
    }
}
