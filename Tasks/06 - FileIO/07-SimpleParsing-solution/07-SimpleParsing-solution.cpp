// open4write.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void createFile(string fn);

int main()
{
    // Test file
    createFile("myfile.txt");


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

    //Read another two strings and discard
    for (unsigned int n = 0; n < 2; n++) {
        inputStream >> nextWord;
    }

    //We are now at the position where we find the code
    int code;
    inputStream >> code;    //Let's hope this is in the right place :)
    cout << "New module code will be " << subjectArea << code + 1 << endl;

    // (iii) Close
    inputStream.close();

    return 0;
}

void createFile(string fn)
{
    // (i) Open for write
    ofstream outputStream;
    outputStream.open(fn);
    if (!outputStream.is_open()) {
        cerr << "Cannot create file" << endl;
        throw std::runtime_error("Cannot create " + fn);
    }

    // (ii) Stream characters
    outputStream << "Hello COMP1000" << endl << "--------------" << endl;
    outputStream << "Subject Area: " << "COMP" << endl;
    outputStream << "Module ID: " << 1000 << endl;

    // (iii) Close
    outputStream.close();
}