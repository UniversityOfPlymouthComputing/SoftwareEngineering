// open4write.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // (i) Open for write
    string fn = "myfile.txt";
    ifstream inputStream;
    inputStream.open(fn);
    if (!inputStream.is_open()) {
        cerr << "Cannot open file " << fn << endl;
        return -1;
    }

    /*
    Hello COMP1000
    --------------
    Subject Area: COMP
    Module ID: 1000
    */

    // (ii) Read word-by-word (separated by spaces)
    string nextWord;
    for (unsigned int n = 0; n < 5; n++) {
        inputStream >> nextWord;
    }
    string subjectArea;
    inputStream >> subjectArea;

    for (unsigned int n = 0; n < 2; n++) {
        inputStream >> nextWord;
    }
    int code;
    inputStream >> code;
    cout << "New module code will be " << subjectArea << code + 1 << endl;

    // (iii) Close
    inputStream.close();

    return 0;
}

