// open4write.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    // (i) Open for read
    string fn = "myfile.txt";
    ifstream inputStream;
    inputStream.open(fn);
    if (!inputStream.is_open()) {
        cerr << "Cannot open file " << fn << endl;
        return -1;
    }

    // (ii) Read word-by-word (separated by spaces)
    string nextLine;
    while (getline(inputStream, nextLine)) {
        cout << nextLine << endl;
    }

    // (iii) Close
    inputStream.close();

    return 0;
}

