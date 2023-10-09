#include <stdio.h>

int main()
{
    bool quitEarly = false;
    for (int i = 0; i <= 10; i++)   // potentially loop from 1 to 10  
    {
        char c = getchar(); //Read character
        char _ = getchar(); //Read and discard newline (nice little hack :)
        if (c == 'q')
        {
            printf("\tUser stopped the loop early at %d\n", i);
            quitEarly = true;       //Flag that indicated the loop was exited
            break;                  // break out of the for loop
        }
        printf("Loop counter = %d\n", i);
    }

    //Was the loop exited with a break?
    if (quitEarly == true) {
        puts("The loop was exited early");
    }

    puts("Done");
}
