#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    // (i) Open for read with ifstream
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