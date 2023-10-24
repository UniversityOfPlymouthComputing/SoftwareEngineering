// open4write.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Write stream of characters to the terminal
    cout << "Hello World!\n";

    // (i) Open for write
    string fn = "myfile.txt";
    ifstream inputStream;
    inputStream.open(fn);
    if (!inputStream.is_open()) {
        cerr << "Cannot open file " << fn << endl;
        return -1;
    }

    // (ii) Read word-by-word (separated by spaces)
    string nextWord;
    inputStream >> nextWord;
    while (inputStream.eof() == false) {
        cout << nextWord << endl;
        inputStream >> nextWord;
    }

    // (iii) Close
    inputStream.close();

    return 0;
}

