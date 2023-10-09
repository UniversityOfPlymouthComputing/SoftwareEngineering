#include <stdio.h>
#include "../../comp1000/comp1000utils.h"

int main()
{
	//Read the terminal input
	unsigned char c = 0b10101100;
	displayAndCompare(c);

	//Shift left 56 bits and store in a 64bit variable
	//
	//We expect the output to be 0b10101100 00000000 00000000 00000000 00000000 00000000 00000000 00000000
	unsigned long long x = c << 56;
	displayAndCompare(x);

	//Solution is in the lab notes

	//This also needs fixing
	int p = 123;
	int q = 2;
	double y = p / q;
	printf("y = %f\n", y);
}
