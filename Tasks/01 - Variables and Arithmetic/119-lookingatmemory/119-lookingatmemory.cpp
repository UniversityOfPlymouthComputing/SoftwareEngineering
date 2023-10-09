// lookingatmemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    unsigned int myVariable;
    myVariable = 15;    // 000F in Hex, 0000000011111111 in binary
    
    printf("The value of myVariable is: %d\n", myVariable);
    printf("The value of myVariable in base 16 (hex) is: %x\n", myVariable);

    printf("The address (in hex) of myVariable is %p\n", &myVariable);
    printf("Size of an integer is %d\n", sizeof(myVariable));
}


