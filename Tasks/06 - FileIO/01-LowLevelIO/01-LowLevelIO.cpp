//Note this is the header file for the standard C library
#include <stdio.h>

int main()
{
    // We've done this before - write a series of characters to the terminal
    int moduleNumber = 1000;
    printf("Hello COMP%d\n", moduleNumber);
    puts("We might say we are sending a \"stream\" of bytes");

    // We can also read a stream of bytes back from the terminal
    int newCode;
    puts("Please enter a new numberical value: ");
    scanf_s("%d", &newCode);
    printf("The new code is COMP%d\n", newCode);

    //There are two "streams" that are already "open" - and you've been using them all this time!
    //
    // They are known as:
    //  stdout - "standard out" - this is currenty set to the terminal output
    //  stdin  - "standard in"  - currently set to the terminal input
    // 
    // BOTH are type FILE*
    //
    // In C, we can use fprintf to illustrate this
    //
    fprintf(stdout, "The function fprintf is just the same as printf, only we explicitly provide the address of the stream\n");

    //The same applies for input
    puts("Please enter a new module code number: ");
    fscanf_s(stdin, "%d", &newCode);

    // *****************************************************************************
    // So we work with STREAMS - and they can be directed to different destinations.
    // In C, a stream as the type FILE*                                            *
    // *****************************************************************************

    // Point the stream at the terminal
    FILE* outputStream = stdout;
    fprintf(outputStream, "12345\n");                   // Note this

    // Now point the stream at a file on a disk
    fopen_s(&outputStream, "lowlevel_io.txt", "wt");     // Open for write
    if (outputStream == nullptr) {
        puts("Could not open that file for write");
        return -1;
    }
    fprintf(outputStream, "12345\n");                   // This is the exact same line as before!
    fclose(outputStream);                               // Never try and close stdout!

    // We could also have a stream that connects to other destinatons, such as a device or a network socket

    // For input, the same concept applies
    FILE* inputStream = stdin;
    int number;
    puts("Enter an integer number");
    fscanf_s(inputStream, "%d", &number);
    printf("You entered %d\n", number);

    // Again, we can use a stream to read a file instead of the terminal
    fopen_s(&inputStream, "lowlevel_io.txt", "rt");     //Open for read - returns a stream if successful
    if (inputStream == nullptr) {
        puts("Could not open that file for read");
        return -1;
    }
    fscanf_s(inputStream, "%d", &number);               //Just as before - only the source of bytes is different
    printf("Found the value %d\n", number);
    fclose(inputStream);                                //For files, we must close

    return 0;
}

