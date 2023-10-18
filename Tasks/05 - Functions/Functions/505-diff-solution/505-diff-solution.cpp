#include <iostream>
using namespace std;

//Function prototypes
int sub(int u, int v);
int absDiff(int u, int v);


int main()
{
    int var1, var2;

    //Prompt the user
    cout << endl << "Enter value 1: ";
    cin >> var1;
    cout << endl << "Enter value 2: ";
    cin >> var2;

    // ***1***
    // This code has been moved out of main
    // ***2***

    //Calculate the absolute difference
    int diff = absDiff(var1, var2);

    // print out the results
    cout << "Absolute diff = " << diff << endl;
}

// Simple function to subtract
// return result is u-v
int sub(int u, int v)
{
    int y = u - v;
    return y;
}

// Returns the absolute difference between u and v
int absDiff(int u, int v)
{
    // create variables to hold the reslts of the calculation
    int diff = 0;

    // Calculate the difference
    if (u >= v)               // check which variable is larger - also this covers the case where they are the same
    {
        diff = sub(u, v);     // do the subtraction
    }
    else
    {
        diff = sub(v, u);     // do the subtraction
    }

    return diff;
}