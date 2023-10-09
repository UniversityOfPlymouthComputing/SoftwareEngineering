#include <stdio.h>

//Main function
int main(void) {

	//Define some integer variables
	int a;          //Not initialised
	int b = -2;     //Initialised
	int y;          //Not initialised

	a = 20;         //Set a to 20
	y = a + b;        //Set y (LHS) to result of a+b (RHS)

	//Write result to stdout
	printf("Some basic arithmetic: %d + %d = %d \n", a, b, y);

	//Return (assuming no errors)
	return 0;
}



