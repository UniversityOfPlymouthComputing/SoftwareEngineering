// sizeof.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <cstdint>

int main()
{
    puts("Windows 11, Microsoft Compiler: type sizes");
    printf("Size of char is %llu\n", sizeof(char));
    printf("Size of short is %llu\n", sizeof(short));
    printf("Size of int is %llu\n", sizeof(int));
    printf("Size of long is %llu\n", sizeof(long));
    printf("Size of long long is %llu\n", sizeof(long long));
    printf("Size of float is %llu\n", sizeof(float));
    printf("Size of double is %llu\n", sizeof(double));
    printf("Size of long double is %llu\n", sizeof(long double));

    //Maybe use these
    uint16_t mySixteenBitNumber = 0;
    uint64_t veryBigNumber = 0;
}

