#include <iostream>
#include <fstream>
#include "Rectangle.h"

using namespace COMP1000;

void demo() {
    Rectangle r0(1.0, 3.0, "r0");
    r0.setHeight(2.0);
    r0.setWidth(5.0);
    cout << r0.getArea() << endl;
}

int main()
{
    demo();
    Rectangle r1(2.0,3.0,"r1");
    Rectangle r2(1.0, 3.0, "r2");

    Rectangle* r3 = new Rectangle(5.0, 3.0, "r3");
    if (r3 == nullptr) {
        return -1;
    }
    Rectangle& myRectangle = *r3;
    double a = myRectangle.getArea();
    cout << "a = " << a << endl;
    delete r3; r3 = nullptr;

    if (r3 == nullptr) {
        throw exception("Pointer was null - expected non-null!");
    }
    r3->setHeight(2.0);
    

}

