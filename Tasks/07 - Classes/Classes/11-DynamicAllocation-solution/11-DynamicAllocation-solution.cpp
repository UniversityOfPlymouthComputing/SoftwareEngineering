#include <iostream>
#include "Rect.h"
using namespace COMP1000;
using namespace std;

int main()
{
    //Static allocation
    Rect r0(2.0f, 3.0f, "static");
    Rect r1(2.0f, 3.0f);

       
    r0.display();
    r1.display(); 
}

