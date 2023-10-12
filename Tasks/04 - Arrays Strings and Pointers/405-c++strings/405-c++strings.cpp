// 405-c++strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //Create a string
    string moduleName = "Comp1000";
    const string institutionName = "University of Plymouth";

    //Print a string 
    cout << "Module: " << moduleName << endl;
    cout << "Institution: " << institutionName << endl;

    //String length vs Array Length
    int L = (int)moduleName.length();        //Returns the number of characters to display - NOT the array size
    int N = sizeof(moduleName);         //Returns the array size
    cout << "The length of \"" << moduleName << "\" is " << L << endl;
    cout << "sizeof(moduleName) returns " << N << endl;

    //Read as if it was an array of characters
    puts("Inspecting the string elements");
    for (int n = 0; n < L; n++) {       //Note I am using L
        cout << moduleName[n] << " ";
    }
    cout << endl;

    //Write as if an array of characters
    moduleName[0] = 'c';
    cout << "Modified version is " << moduleName << endl;
    // institutionName[0] = 'u'; //You cannot do this

    //Copying
    string anotherModule;       //Create another string
    anotherModule = moduleName; //It's that easy!

    // How to compare string content - type string behaves as a VALUE type
    if (moduleName == anotherModule) {
        cout << "moduleName and anotherModule have the same content!" << endl;
    }
    else {
        cout << "moduleName and anotherModule have different same content!" << endl;
    }

    //Modify anotherModule to be all upper case
    std::transform(anotherModule.begin(), anotherModule.end(), anotherModule.begin(), std::toupper);
    cout << anotherModule << endl;

    //Concatinating Strings
    string header;                   
    header = moduleName + " " + institutionName;
    cout << header << endl;

    //Find substrings
    size_t loc = header.find("of");
    cout << "\"of\" is found at location " << loc << endl;

    //Extract subsctrings
    string firstHalf = header.substr(0, loc);
    string secondHalf = header.substr(loc);
    cout << "First part is " << firstHalf << endl;
    cout << "Second part is " << secondHalf << endl;

    //Convert numbers to string
    string strYear = "0000";
    unsigned int year = 2023;
    strYear = to_string(year);
    cout << strYear << " has " << strYear.length() << " characters." << endl;

    //Convert strings back to numbers
    int parsedYear = stoi(strYear);
    printf("The next year is %d\n", parsedYear + 1);

    //Extract the c string (read only)
    const char* str = strYear.c_str();

    cout << "C string version is " << str << endl;
}

