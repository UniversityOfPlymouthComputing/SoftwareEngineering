#include <iostream>
using namespace std;

int addOneByValue(int u) {
    u = u + 1;
    return u;
}

void addOneByPointer(int* pointerToU) {
    *pointerToU = *pointerToU + 1;
}

void addOneByReference(int& refToU) {
    refToU = refToU + 1;
}

int main()
{
    // Create and initialise a
    int a = 100;

    // (a) - by value - will a be affected?
    int b = addOneByValue(a);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // (b) - by pointer - will a be affected?
    addOneByPointer(&a);
    cout << "a = " << a << endl;

    // (c) - by reference - will a be affected?
    addOneByReference(a);
    cout << "a = " << a << endl;

}



