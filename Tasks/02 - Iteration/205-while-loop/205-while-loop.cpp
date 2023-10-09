#include <stdio.h>

int main()
{
    int i = 0;

    puts("Start while loop");

    while (i < 5)
    {
        printf("i = %d\n", i);
        i++;        // same as i = i + 1 but more concise;
    }

    printf("Exiting with i=%d\n", i);
}

