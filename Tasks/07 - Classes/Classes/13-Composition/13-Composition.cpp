#include <iostream>
#include "Rect.h"
#include "StringBanner.h"
using namespace COMP1000;
using namespace std;

int main()
{
    //Static allocation
    Rect r0(2.0f, 3.0f, "static");
    Rect r1(2.0f, 3.0f);

    r0.display();
    r1.display();

    StringBanner bnr1("HELLO COMP1000");
    bnr1.display();

    StringBanner bnr2("Welcome to the middle of the module");
    bnr2.display();

}
