#include <stdio.h>

int main()
{
	char x = 10;
	short s = -12345;
	int integerValue = 1234567891;
	long bigValue = 1234567891;
	long long veryBigValue = -123456789123456789;
	unsigned long long sillyBigPositiveValue = 12345678912345678912;

	//How to write values to the terminal
	printf("x = %d\n", x);
	printf("s = %d\n", s);
	printf("integerValue = %d\n", integerValue);
	printf("bigValue = %ld\n", bigValue);
	printf("veryBigValue = %lld\n", veryBigValue);
	printf("sillyBigPositiveValue = %llu\n", sillyBigPositiveValue);

	//Extra newline
	printf("\n");

	//Display a table of date types and sizes
	printf("Type\t\tSize(Bytes)\n");	//The \t character is a TAB
	printf("----\t\t-----------\n");

	//TASK: Display the size of ALL the integer data types
	// Write your solution below here. The first one is done for you.
	printf("char\t\t%llu\n", sizeof(char));	//sizeof() returns a value of type unsigned long long

}