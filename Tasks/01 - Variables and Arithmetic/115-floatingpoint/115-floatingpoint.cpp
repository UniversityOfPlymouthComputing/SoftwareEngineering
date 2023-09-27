#include <stdio.h>

int main()
{
    float fFractional = 0.123;
    printf("fFractional = %f\n", fFractional);

    //To 6 decimal places
    printf("fFractional (6dp) = %.6f\n", fFractional);

    //Let's try 9 decimal places 
    fFractional = 0.123456789;
    printf("fFractional = %.9f\n", fFractional);

    //Compare with double
    double dfFractional = 0.123456789;
    printf("dfFractional = %.9f\n", dfFractional);

    //Push double further into the smaller fractions (18 decimal places)
    dfFractional = 0.123456789123456789;
    printf("dfFractional = %.18f\n", dfFractional);

    //Push double further into the large numbers (9 decimal places)
    dfFractional = 10000000000.123456789;
    printf("dfFractional = %.9f\n", dfFractional);

    //Caluclations
    double x = 1.234;
    printf("x = %f\n", x);

    //Multiply
    x = x * 10.0;
    printf("x = %f\n", x);

    //Divide
    x = x / 0.0;      //Error!!!!????
    printf("x = %f\n", x);

}


