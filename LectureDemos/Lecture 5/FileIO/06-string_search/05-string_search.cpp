#include <iostream>
#include <fstream>
#include <sstream>
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

