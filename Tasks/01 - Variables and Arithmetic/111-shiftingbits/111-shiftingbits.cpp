#include <stdio.h>
#include <iostream>
#include "comp1000utils.h"

int main()
{
	//Create and initialise a 16-bit variable
	unsigned short number = 0b0000000000001011;

	//Write to the terminal (using the tutors bespoke function)
	displayAndCompare(number);

	//Shift it left 1 bit position (binary operator)
	number = number << 1;
	displayAndCompare(number);

	//And again, only using the unary operator
	number <<= 1;
	displayAndCompare(number);

	//Shift left 2 bits
	number <<= 2;
	displayAndCompare(number);

	//Right right 4 bits
	number >>= 4;
	displayAndCompare(number);

	//TASKS:

	//Shift right by 1 and display


	//Shift left by 1 and display

}