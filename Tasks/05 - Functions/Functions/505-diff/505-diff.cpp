#include <iostream>
using namespace std;

int main()
{
    int var1, var2;

    //Prompt the user
    cout << endl << "Enter value 1: ";
    cin >> var1;
    cout << endl << "Enter value 2: ";
    cin >> var2;

    // create variables to hold the reslts of the calculation
    int sum = var1 + var2;
    int diff = 0;

    if (var1 >= var2)               // check which variable is larger - also this covers the case where they are the same
    {
        diff = var1 - var2;         // do the subtraction
    }
    else
    {
        diff = var2 - var1;         // do the subtraction
    }

    // print out the results
    cout << "var1 = " << var1;
    cout << ", var2 = " << var2;
    cout << ", sum = " << sum;
    cout << ", absolute diff = " << diff << endl;
}