#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //Create a string
    char moduleName[] = "Comp1000";
    const char institutionName[] = "University of Plymouth";

    //Print a string 
    printf("Module: %s\n", moduleName);
    printf("Institution: %s\n", institutionName);

    //String length vs Array Length
    int L = (int)strlen(moduleName);    //Returns the number of characters to display - NOT the array size
    int N = sizeof(moduleName);         //Returns the array size
    printf("The string length of %s is %d\n", moduleName, L);
    printf("The number of bytes in the string %s is %d\n", moduleName, N);

    //Print as an array of numbers
    puts("Inspecting the array contents");
    for (int n = 0; n < N; n++) {       //Note I am using N and not L
        printf("%d\t", moduleName[n]);  //De-reference the array of characters
    }
    puts(""); puts("*****************************************************************");

    //Copying - with strncpy_s (safer version)
    char anotherModule[sizeof(moduleName)];                     //Another string array of the same size
    memset(anotherModule, 0, sizeof(anotherModule));            //Initialise with all zeros (defensive coding)
    strncpy_s(anotherModule, moduleName, sizeof(moduleName));   //Copy all characters, including the terminating zero

    // How NOT to compare string content - remember the array variables holds an address!
    if (moduleName == anotherModule) {
        puts("moduleName and anotherModule have the same address");
    }
    else {
        puts("moduleName and anotherModule have a different address");
    }

    //Comparing array content - part 1
    int diff = (int)strncmp(moduleName, anotherModule, (int)sizeof(moduleName)-1);
    if ( diff == 0)
    {
        printf("%s is the same as %s\n", moduleName, anotherModule);
    }
    else {
        printf("%s is not the same as %s\n", moduleName, anotherModule);
    }

    //Modify anotherModule to be all upper case
    for (int n = 0; n < (int)sizeof(anotherModule)-1; n++) {    //Note I am not changing the zero by doing this
        char prevChar = anotherModule[n];                       //De-reference the array of characters for read
        char newChar = toupper(prevChar);                       //The C function toupper converts lower case to upper case
        anotherModule[n] = newChar;                             //Overwrite the array by de-referencing
    }
    puts(anotherModule);

    //Comparing array content - part 2
    diff = (int)strncmp(moduleName, anotherModule, (int)sizeof(moduleName) - 1);
    if (diff == 0)
    {
        printf("%s is the same as %s\n", moduleName, anotherModule);
    }
    else {
        printf("%s is not the same as %s\n", moduleName, anotherModule);
    }

    //Concatinating Strings with strncat
    char header[64];                    // More than big enough
    memset(header, 0, sizeof(header));  // Initialise for safety
    
    // 1. Copy first string in larger array
    strncpy_s(header, moduleName, sizeof(moduleName));
    // 2. Concatinate
    strncat_s(header, " ", 2);
    strncat_s(header, institutionName, sizeof(institutionName));
    // 3. Display
    puts(header);

    //Concatinating Strings with sprintf
    sprintf_s(header, "%s %s", moduleName, institutionName);

    //Find substrings
    char* loc = strstr(header, "of");
    puts(loc);
    loc[0] = 0;
    puts(header);

    //Convert numbers to string
    char strYear[] = "0000";
    unsigned int year = 2023;
    sprintf_s(strYear, "%u", year);
    puts(strYear);

    //Convert strings to numbers
    int parsedYear = atoi(strYear);
    printf("The next year is %d\n", parsedYear+1);

}


