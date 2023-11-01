#include <iostream>
#include "Rect.h"
using namespace COMP1000;

//Rect r3(5.0f, 6.0f, "r3");

void demo() {
    Rect r0(3.0f, 10.0f,"r0");
    r0.display();
}

int main()
{
    //Using C++ class
    Rect r1(2.0, 3.0, "r1");
    r1.display();

    //Call demo - which creates a temporary Rect
    demo();

    return 0;
}
