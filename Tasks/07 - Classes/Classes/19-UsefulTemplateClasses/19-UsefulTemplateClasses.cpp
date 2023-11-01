#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <stdexcept>

using namespace std;


int main()
{
    // ******************************
    // Useful template class 1: array
    // ******************************

    //Create an array of data - must specify type AND size in advance (very fast)
    array<float, 5> someData;       //Create an array
    someData.fill(0.0f);            //Fill with zeros
    array<float, 5> moreData;       //Another array
    moreData = someData;            //Copy

    //Perform some maths
    for (unsigned int n = 1; n < someData.size(); n++) {
        moreData[n]=moreData[n-1]+n;
    }
    
    //Output to the terminal

    cout << endl << endl << "------------ array ------------" << endl << endl;

    // (a) The standard way
    for (unsigned int n = 0; n < moreData.size(); n++) {
        cout << moreData[n] << endl;
    }
    
    cout << endl;

    // (b) The "modern" way
    for (float x : moreData) {
        cout << x << endl;
    }




    // *******************************
    // Useful template class 2: vector
    // *******************************

    //Create a vector - size is NOT specified as it can grow! Not as fast, but super useful!
    vector<double> vec;


    //Perform some maths
    vec.push_back(0.0);                             //Add first value to the vector
    for (unsigned int n = 1; n < 5; n++) {
        double nextVal = vec[n-1] + (double)n;      
        vec.push_back(nextVal);                     //Append another value to the vector
    }

    //Output to the terminal

    cout << endl << endl << "------------ vector ------------" << endl << endl;

    //The standard way
    for (unsigned int n = 0; n < moreData.size(); n++) {
        cout << vec[n] << endl;
    }

    cout << endl;
    
    //The "modern" way
    for (float x : vec) {
        cout << x << endl;
    }
    
    // ****************************
    // Useful template class 3: map
    // ****************************

    // map is a clever mechanism to "look up" data
    map<string, int> ageMap;

    //Add some values
    ageMap["Jo"]  = 51;
    ageMap["Les"] = 35;
    ageMap["Sam"] = 21;
    ageMap.insert(pair<string, int>("Pat", 33));

    //Loop up some values
    int ageNick = ageMap["Les"];
    cout << "Les is " << ageNick << endl;
    cout << "Pat is " << ageMap["Pat"] << endl;

    //It can fail!
    if (ageMap.count("Dave") > 0) {
        cout << "Dave is " << ageMap["Dave"] << endl;
    }
    else {
        cerr << "Never heard of Dave" << endl;
    }

}

