#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
using namespace std;

//Used to create a file for testing purposes
void createFile(string fn);
int readFileIntoString(string fn, string& allLines);

int main()
{
    // Let's create a file for test purposes
    createFile("myfile.txt");

    // String to hold file content
    string dataString;
    int errCode = readFileIntoString("myfile.txt", dataString);

    // If successful, display contents
    if (errCode != 0) {
        cerr << "Error: " << errCode << endl;
        return errCode;
    }

    //Display
    cout << dataString << endl;

    // Find the substring "ID:"
    int pos = dataString.find("ID:");
    if (pos == -1) {
        cerr << "Identifier ID: is missing from file" << endl;
        return -1;
    }

    //Now extract the string from this point forwards
    cout << "Found \"ID:\" at character position " << pos << endl;
    string previous = dataString.substr(0, pos);   //Up to the location pos-1
    string following = dataString.substr(pos);      //From pos to the end

    //Now read the next two words
    istringstream iss(following);   //From ID: onwards
    string strTag;
    string strCode;
    iss >> strTag >> strCode;             //Read both
    if (iss.fail()) {
        cerr << "Could not read module code" << endl;
        cout << "Time for coffee" << endl;
        return -1;
    }
    cout << "Found " << strTag << endl;
    cout << "Followed by " << strCode << endl;

    //Conversion
    int code;
    try {
        code = stoi(strCode);
        cout << "New Module ID: " << code + 1 << endl;
    }
    catch (exception e)
    {
        cerr << e.what() << endl;
        cout << "That broke. Time for coffee" << endl;
        return -1;
    }

    // SOLUTION HERE - Now find 
    pos = dataString.find("Area:");
    if (pos == -1) {
        cerr << "Identifier Area: is missing from file" << endl;
        return -1;
    }

    //Extract
    following = dataString.substr(pos);      //From pos to the end

    //Now read the next two words

    istringstream iss2(following);
    iss2 >> strTag >> strCode;
    if (iss2.fail()) {
        cerr << "Could not locate subject group" << endl;
        cout << "Time for coffee" << endl;
        return -1;
    }
    cout << "Subject group is " << strCode << endl;

    // Done
    cout << "All is well!" << endl;
    return 0;
}

// Create a test file with filename fn
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
    //We've switched to back to regular numerals - as discussed by the water cooler
    outputStream << "Module ID: " << "1000" << endl;

    // (iii) Close
    outputStream.close();
}

// Read the test file into a string
int readFileIntoString(string fn, string& allLines)
{
    // (i) Open for read
    ifstream inputStream;
    inputStream.open(fn);
    if (!inputStream.is_open()) {
        cerr << "Cannot open file " << fn << endl;
        return -1;
    }

    // (ii) Read line-by-line (separated by newline)
    string nextLine;    //String to hold each line
    allLines = "";      //Reset to empty string

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

    // (iii) Close the file
    inputStream.close();

    return 0;
}