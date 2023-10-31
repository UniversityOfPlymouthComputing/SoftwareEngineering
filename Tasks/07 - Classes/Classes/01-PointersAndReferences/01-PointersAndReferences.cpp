#include <iostream>
using namespace std;

int main()
{
    // TASK (a) - value types

    //Create and initialise value-type a
    int a = 100;

    //Create and initialise value-type n
    int b = a;

    //Display
    cout << "a=" << a << ", b=" << b << endl;

    //Modify a
    a++;

    //Can you predict the output of the following? Will b change as well?
    cout << "a=" << a << ", b=" << b << endl;





    // TASK (b) - pointers

    // Create a pointer type
    int* p1;

    // Store the address of a in p1
    p1 = &a;

    // Display value of a
    cout << "a=" << a << endl;

    // Display address of a
    cout << "Address of a = " << p1 << endl;

    // Display data at address p1 using the * operator - Can you predict the output?
    cout << "Data at address p1 = " << *p1 << endl;

    // Modify a
    a++;

    // Display value of a
    cout << "a=" << a << endl;

    // Display data at address p1 - Again, can you predict the output?
    cout << "Data at address p1 = " << *p1 << endl;

    // Now create another pointer
    int* p2;

    // Use equals to copy the address of p1 into p2
    p2 = p1;

    // Display p2 
    cout << "Address p2 = " << p2 << endl;

    // Display data at address p2 - Again, can you predict the output?
    cout << "Data at address p2 = " << *p2 << endl;

    // Modify data at address p2
    *p2 = 200;

    // Display value of a - can you predict the output?
    cout << "a=" << a << endl;






    // Task (c) - References

    // Let refA be a reference to variable a. This means they HAVE THE SAME ADDRESS
    int& refA = a;

    // Display both (no star needed)
    cout << "a = " << a << ", refA = " << refA << endl;

    // Update a
    a++;

    // Display both
    cout << "a = " << a << ", refA = " << refA << endl;

    // Update refA
    refA++;

    // Display both
    cout << "a = " << a << ", refA = " << refA << endl;


}

