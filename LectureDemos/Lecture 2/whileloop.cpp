#include <stdio.h>

int main()
{
    printf("Let's Go\n");

    int a = 1;

    while (a<5) 
    {
        printf("The value of a is %d\n", a);
        a = a + 1;
    }
    printf("Done (a = %d)\n", a);
}