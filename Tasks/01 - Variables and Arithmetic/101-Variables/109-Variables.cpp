#include <stdio.h>

int main()
{ // Block opening brace

	char c = 88;				// Character (1 byte)
	short year = 2023;			// Short integer
	int age = 23;				// Integer
	long bigNumber = 123456789;	// Long integer
	long long veryBigNumber = 1LL << 30;	//2^30 - challenge (advanced), why have I put 1LL?

	printf("c=%d\n", c);
	printf("year = %hd\n", year);
	printf("age = %d\n", age);
	printf("bigNumber = %ld\n", bigNumber);
	printf("veryBigNumber = %lld\n", veryBigNumber);

	//Addition
	int ageNextYear;
	ageNextYear = age + 1;
	printf("Next birthday, you will be %d\n", ageNextYear);

	//Increment
	ageNextYear++;
	printf("And then after that, you will be %d\n", ageNextYear);

	//Overflow
	year = 32767;
	year = year + 1;
	printf("year = %d\n", year);

	//Divide
	age = 50;
	age = age / 2;
	printf("Half of 50 is %d\n", age);
	 
	//Divide and remainder
	age = 51;
	age = age / 2;
	int remainder = age % 2;
	printf("Half of 51 is %d, remainder %d\n", age, remainder);

} 