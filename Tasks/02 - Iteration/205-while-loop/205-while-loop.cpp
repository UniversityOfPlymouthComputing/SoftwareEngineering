#include <stdio.h>

int main()
{
    int i = 10;

    puts("Start while loop");

    while (i != 0)
    {
        printf("i = %d\n", i);
        i--, i--;        // same as i = i + 1 but more concise;
    }

    printf("Exiting with i=%d\n", i);
}

