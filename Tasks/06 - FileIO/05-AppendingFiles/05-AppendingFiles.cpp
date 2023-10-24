#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // (i) Open for write
    ofstream outputStream;
    outputStream.open("myfile.txt");
    //outputStream.open("myfile.txt", ios::app);
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
