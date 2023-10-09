#include <stdio.h>

int main()
{
    printf("Let's Go\n");

    int a = 1;
    int b = 2;

    while (a<5) 
    {
        printf("The value of a is %d\n", a);
        a = a + 1;
        b = b - 1;
    }
    printf("Done (a = %d)\n", a);
}