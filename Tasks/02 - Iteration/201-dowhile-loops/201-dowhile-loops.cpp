#include <stdio.h>

//This is the main entry point for my code
int main()

{
    int i = 0;

    printf("Start while loop\n");

    do
    {
        printf("i = %d\n", i);
        i = i + 1;              // Alternatively, write i++;
    } while (i < 5);            //Repeat if condition is met

    printf("Finished: i = %d\n", i);
 }
int main()
{
    int i = 0;

    printf("Start while loop\n");

    do
    {
        printf("i =%d\n", i);
        i = i + 2;
    } while (i < 6);

    printf("Finish: i = %d\n", i);
}



