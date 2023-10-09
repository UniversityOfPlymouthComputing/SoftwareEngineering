#include <stdio.h>

int main()
{
    printf("Let's Go\n");

    // Old method
    int n;
    for (n=0; n < 5; n++) {
        printf("Hello - n = %d\n", n);
    }

    //Bad practice - using a variable post-for loop
    printf("Done (n = %d)\n", n);
}