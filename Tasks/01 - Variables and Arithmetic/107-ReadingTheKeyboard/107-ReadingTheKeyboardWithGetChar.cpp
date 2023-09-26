#include <stdio.h>

int main()
{
    //Create a variable of type char (8-bit integer)
    char c = 0;
    
    //Read the keyboard and copy the ASCII code into c
    c = getchar();

    //Write the decimal and ASCII representation to the terminal
    printf("You typed %c\n", c);
    printf("This has ASCII code %d\n", c);

}
