#include "PointLib.h"


int main()
{
    //Create two variables of type Point
    Point p1 = { 3, 4, 5.0f };      //Initialised inline

    //Now demonstrate returning a structure
    displayPoint(p1);               //Showing p1
    flipPoint(p1);                  //Pass the address so p1 can be modified by the function
    displayPoint(p1);               //Showing p4

    //Break the length on purpose
    p1.length = 0.0f;

    //Recalculate
    calculateLength(p1);            //Pass the address to the function can modify the structure in-place
    cout << endl << "Length of p1 = " << p1.length << endl; //Simply write it out

}

