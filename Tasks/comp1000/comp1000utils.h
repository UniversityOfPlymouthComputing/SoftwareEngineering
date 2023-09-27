#pragma once
#include <stdio.h>
#include <iostream>

/*

STUDENTS - YOU DO NOT NEED TO LOOK AT THIS OR UNDERSTAND IT

*/

//Pass value type u, and display the binary encoding in the terminal
template<class T>
void displayAsBinary(T u)
{
	unsigned int Nbits = sizeof(T) * 8;				//Number of bits for datatype T
	for (int n = Nbits - 1; n >= 0; n--) {
		T mask = ((T)1 << n);
		printf("%c", (u & mask) ? '1' : '0');
	}
}

//Pass intever value type u and display using the appropriate format string
template<class T>
void displayAsDecimal(T u)
{
	printf("%u", u);
}

template<>
void displayAsDecimal<unsigned long>(unsigned long u)
{
	printf("%lu", u);
}

template<>
void displayAsDecimal<unsigned long long>(unsigned long long u)
{
	printf("%llu", u);
}

template<class T>
void displayAndCompare(T u)
{
	printf("Binary value ");
	displayAsBinary(u);
	printf(" is decimal ");
	displayAsDecimal(u);
	printf("\n");
}

