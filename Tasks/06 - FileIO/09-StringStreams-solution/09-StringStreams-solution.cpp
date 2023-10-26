// 09-StringStreams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
using namespace std;


int main()
{
    //Create two strings.
    string nextWord;

    //Note how a long string can be broken over several lines to aid writing. Note the \ character never features in the string.
    string sentence = "May the force be with you. " \
        "Always. Ok, maybe that's asking too much. " \
        "How about 3 days-a-week with time off for birthdays? ";

    //Write the complete string to the the terminal
    cout << sentence << endl;

    //Read first word (words are separated by spaces or newlines)
    istringstream iss(sentence);
    int count = 0;
    
    //Keep looping as long as we are NOT at the end of the file
    while (!iss.eof()) {
        iss >> nextWord;
        if (iss.fail()) {
            //The last try did not read a word - skip to the end
            continue;
        }
        //We must have read a word and not an end of file character
        count++;

        //Write each word if available
        cout << nextWord << endl;
        //Write an extra newline if we just output "Always."
        if (nextWord == "Always.") {
            cout << endl;
        }
        
    }

    //Finally, the word count
    cout << "Total Number of Words: " << count << endl;

    //Done
    return 0;

}

