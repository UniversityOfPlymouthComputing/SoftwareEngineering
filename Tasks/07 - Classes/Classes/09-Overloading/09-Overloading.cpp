// 09-Overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rect.h"
using namespace COMP1000;
using namespace std;

int main()
{
    Rect r0(2.0f, 3.0f, "r0");
    Rect r1(3.0f, 4.0f);

    r0.display();
    r1.display();
}

