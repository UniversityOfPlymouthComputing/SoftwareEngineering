// open4write.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Write stream of characters to the terminal
    cout << "Hello World!\n";

    //Now a file

    // (i) Open for write
    ofstream outputStream;
    outputStream.open("myfile.txt"/*, ios::app*/);
    if (!outputStream.is_open()) {
        cerr << "Cannot create file" << endl;
        return -1;
    }

    // (ii) Stream characters
    outputStream << "Hello COMP1000" << endl << "--------------" << endl;
    outputStream << "Subject Area: " << "COMP" << endl;
    outputStream << "Module ID: " << 1000 << endl;
    // (iii) Close
    outputStream.close();

    return 0;
}

