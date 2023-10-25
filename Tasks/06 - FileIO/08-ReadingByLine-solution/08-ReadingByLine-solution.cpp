#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

using namespace std;

//Used to create a file for testing purposes
void createFile(string fn);

int main()
{
    //Let's create a file for test purposes
    createFile("myfile.txt");

    // (i) Open for read
    string fn = "myfile.txt";
    ifstream inputStream;
    inputStream.open(fn);
    if (!inputStream.is_open()) {
        cerr << "Cannot open file " << fn << endl;
        return -1;
    }

    // (ii) Read line-by-line (separated by newline)
    string nextLine;
    string allLines;

    //Read remaining words
    while (getline(inputStream, nextLine)) {
        allLines = allLines + " " + nextLine;         //Append the string
        cout << nextLine << endl;
    }

    cout << "Complete String: " << allLines << endl;

    // (iii) Close the file
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