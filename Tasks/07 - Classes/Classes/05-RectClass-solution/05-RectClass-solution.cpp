#include <iostream>
using namespace std;
#include "Rect_t.h" //C   Version
#include "Rect.h"   //C++ Version

int main()
{
    //Using C structures
    Rect_t r1 = CreateRect(2.0, 3.0);
    display(r1);
    setHeight(r1, 10.0);
    display(r1);

    //Using C++ class
    Rect r2(2.0, 3.0);
    r2.display();
    r2.setHeight(10.0);
    r2.setWidth(5.0);
    r2.display();

    
}

