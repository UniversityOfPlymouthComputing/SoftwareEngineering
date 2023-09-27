#pragma once
#include <stdio.h>
#include <iostream>

//Pass value type u, and display the binary encoding in the terminal
template<class T>
void displayAsBinary(T u)
{
	unsigned int Nbits = sizeof(T) * 8;				//Number of bits for datatype T
	for (int n = Nbits - 1; n >= 0; n--) {
		unsigned int mask = (1 << n);
		printf("%c", (u & mask) ? '1' : '0');
	}
	printf("\n");
}

//Pass intever value type u and display using the appropriate format string
template<class T>
void displayAsDecimal(T u)
{
	printf("%u\n", u);
}

template<>
void displayAsDecimal<unsigned long>(unsigned long u)
{
	printf("%lu\n", u);
}

