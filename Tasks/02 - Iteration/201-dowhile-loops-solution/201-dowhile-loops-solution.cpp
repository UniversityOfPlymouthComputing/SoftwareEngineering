#include <stdio.h>

int main()
{
    int i = 5;

    printf("Start while loop\n");

    do
    {
        printf("i = %d\n", i);
        i = i - 1;              // Alternatively, write i++;
    } while (i >= 0);            //Repeat if condition is met

    printf("Finished: i = %d\n", i);
}