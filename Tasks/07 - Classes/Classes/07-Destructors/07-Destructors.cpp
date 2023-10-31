#include <iostream>
#include "Rect.h"

void demo()
{
    Rect r(3.0f, 10.0f);
    r.display();
}

int main()
{
    //Using C++ class
    Rect r1(2.0, 3.0);
    r1.display();

    //Call demo - which creates a temporary Rect
    demo();

    return 0;
}
