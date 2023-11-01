// 09-Overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rect.h"
using namespace COMP1000;
using namespace std;

int main()
{
    //Pointer - WILL hold the address of some memory that contains a Rect (but not yet)
    Rect* r1 = nullptr;

    //Static allocation
    Rect r0(2.0f, 3.0f, "static");

    //Dynamic allocation with new
    r1 = new Rect(3.0f, 4.0f, "dynamic");
    if (r1) {
        cout << "Successfully allocated memory for a Rect" << endl;
    }
    else {
        //This should not happen unless we are very low on memory
        cerr << "Out of memory error!" << endl;
        return -1;
    }

    //Dynamically allocated objects have a pointer, so use the -> arrow
    r1->display(); //Assumes r1 was sucessfully allocated
    //(*r1).display(); //Read the contents at address r1 (should be an object), then call the `display()` member function

    //Free up memory NOW 
    if (r1) {           // Illustrating a more defensive coding style
        delete r1;      // Free up memory with start address r1
        r1 = nullptr;   // Set to null to we can perform run-time checks
    }

    //Defensive approach can save crashes!
    if (r1) {
        r1->display();
    }

    //Statically allocated objects use dot notation
    r0.display();   //r0 will exist until the end of main
}

