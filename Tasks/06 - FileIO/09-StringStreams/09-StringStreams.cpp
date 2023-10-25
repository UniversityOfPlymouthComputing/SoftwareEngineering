// 09-StringStreams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
using namespace std;


int main()
{
    string nextWord;
    string sentence = "May the force be with you. " \
                      "Always.Ok, maybe that's asking too much. " \
                      "How about 3 days - a - week with time off for birthdays ? ";

    cout << sentence << endl;
    istringstream iss(sentence);
    iss >> nextWord;

}

