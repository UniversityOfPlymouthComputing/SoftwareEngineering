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

    //Read a complete line into the nextLine string
    getline(inputStream, nextLine);

    //Now add on the the allLines string
    if (inputStream.fail() == false) {
        cout << "Read in the line: " << nextLine;
        allLines = allLines + nextLine + "\n";
    }
    else {
        cout << "Did not read a line. End of File?" << endl;
    }

    //Use a loop to read all remaining lines
    do {
        //Read a line from the stream `inputString` into the string `nextLine`
        getline(inputStream, nextLine);

        //Did we successfully read a line?
        if (!inputStream.fail()) {
            //If so, append to the string `allLines` and add a newline character on the end
            allLines = allLines + nextLine + "\n";
        }
        //The last read MIGHT include an EOF character
    } while (!inputStream.eof());   //Loop condition is if we have NOT reached the end of the file

    cout << endl << endl << "Complete String: " << endl << allLines << endl;

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