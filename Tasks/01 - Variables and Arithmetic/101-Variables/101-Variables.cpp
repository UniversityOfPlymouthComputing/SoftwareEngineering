#include <stdio.h>

// This is a single line comment - it does nothing

/*
   This is a block comment. 
   It also does nothing.
*/

//Entry point for your code
int main()
{ // Block opening brace

	char c = 88;				// Character
	short year = 2023;			// Short integer
	int age = 23;				// Integer
	long bigNumber = 123456789;	// Long integer
	long long veryBigNumber = 1LL << 30;	//2^30

	//Floating point numbers
	float pi_f   = 3.1415926535; //Does this work?
	double pi_df = 3.1415926535; //This one is "double precision"

	// The following are not initialised inline
	int serialNumber;			//What value is stored in here at this point?
	serialNumber = 50;


	// TASK: Use the debugger to step through the lines above. 
	//   Hover the mouse over each line to see it's value BEFORE and AFTER each line
	//   Note any discrepencies between the value in the source code and the value reported by the debugger

} // Block closing brace