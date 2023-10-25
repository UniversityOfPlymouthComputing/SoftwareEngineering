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

    // Parse String word by word
    istringstream iss(dataString);

    // Read the first word
    int moduleNumber;
    string nextWord;

    while (iss.eof() == false)
    {
        //Try to read the next word
        iss >> nextWord;
        if (iss.fail()) {
            //Jump to the end of the while loop
            continue;
        }
        // Display the word
        cout << nextWord << endl;

        //Look for the string that comes before the module code
        if (nextWord == "ID:") {
            cout << "Found \"ID:\". The code should be next...." << endl;
            // Read the next word - it "should" be the module number, encoded as a string
            iss >> nextWord;
            if (!iss.fail()) {
                //TRY to Convert a string to an integer
                try {
                    moduleNumber = stoi(nextWord);
                    //Write the new module code
                    cout << "COMP" << moduleNumber + 1 << endl;
                    //We are done! Break from the outer loop
                    break;
                }
                catch (exception e)
                {
                    // It seems stoi() has thrown an exception - suspect the file is corrupt or the format has changed

                    //Detailed info to the error stream
                    cerr << "Error! Data file format was not as expected. Exception thrown = " << e.what() << endl;
                    cerr << "String value following \"ID:\" was expected to be numeric, and not \"" << nextWord << "\"" << endl;
                    //User focused feedback to stdout
                    cout << "The code has decided to break today. Please report this to the developers" << endl;
                    cout << "Take the rest of the day off" << endl;
                    return -1;
                }
            }
            else {
                // Case where we've hit the end of the file
                // This should not happen of course
                 
                //Detailed info to the error stream
                cerr << "String value following \"ID:\" was expected to be numeric, not empty" << endl;
                cout << "Your data file seems to be missing imporant information." << endl;
                //User focused feedback to stdout
                cout << "Please report this to the developers" << endl;
                cout << "By all means try turning it all off and on again, but I don't think it will make much difference" << endl;
                return -1;
            }
        }
    }

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
    //We've switched to Roman Numerals - did I mention that in my last email?
    outputStream << "Module ID: " << "M" << endl;   

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