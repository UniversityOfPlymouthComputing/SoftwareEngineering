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
    string fullText;
    string nextWord;
    inputStream >> nextWord;
    while (inputStream.eof() == false) {
        fullText = fullText + nextWord + " ";
        inputStream >> nextWord;
    }
    cout << fullText << endl;
    // (iii) Close
    inputStream.close();

    //Find the preceding tag
    size_t loc = fullText.find("ID:");
    string remainingString = fullText.substr(loc);
    cout << "Getting close? : " << endl;
    cout << remainingString << endl;

    //Read string word by word
//    string nextWord;
    istringstream iss(remainingString);
    iss >> nextWord;
    int moduleCode;
    iss >> moduleCode;
    cout << "Is the new module code " << moduleCode + 1 << " ?" << endl;
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

/*

    //Within each line, we can extract the individual words (separated by spaces)
    istringstream iss(nextLine);          //Create a "string stream"
    string nextWord;                      //Read first work from the string
    iss >> nextWord;
    cout << "Word 1:" << nextWord << endl;
    iss >> nextWord;
    cout << "Word 2:" << nextWord << endl;
    iss >> nextWord;
    if (iss.eof() == true) {
        cout << "Ok, moving on..." << endl;
    }

*/