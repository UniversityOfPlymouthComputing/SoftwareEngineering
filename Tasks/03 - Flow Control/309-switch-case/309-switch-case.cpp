#include <iostream>

using namespace std;

// Some "mocking" functions to help us test our logic
void redirect(int number) {
    cout << "Phone redirects to " << number << endl;
}
void hangup() {
    cout << "Bye" << endl;
}

// Main code
int main()
{
    // start filling the tank 
    int selection = 0;

    // Read the keyboad to get the option
    // Repeat until a valid value has been added
    do {
        cout << "Please enter one of the following options:" << endl;
        cout << "0 - Opening Hours" << endl;
        cout << "1 - Help with online shopping" << endl;
        cout << "2 - In-store enquirey" << endl;
        cout << "3 - Customer Service Desk" << endl;
        cout << "4 - All other options" << endl;
        cin >> selection;
    } while ((selection < 0) || (selection > 4)); // Repeat until a valid number is entered

    // Mutuallly Exclusive Decision Pathway
    if (selection == 0)
    {
        cout << "9 to 5, Monday to Saturday. 10 to 4 on Sundays and Bank Holidays" << endl;
    }
    else if (selection == 1)                       
    {
        cout << "Redirecting you now" << endl;
        redirect(100);
    }
    else if (selection == 2)
    {
        cout << "Sorry - you will need to come to the store for that." << endl;
        hangup();
    }
    else if ((selection == 3) || (selection == 4)) {
        cout << "Redirecting you now" << endl;
        redirect(220);
    } 
    else 
    {
        // Defensive coding! Catch the unexpected - in theory, this code cannot be reached
        cerr << "Error - invalided variable" << endl;
    }
}
