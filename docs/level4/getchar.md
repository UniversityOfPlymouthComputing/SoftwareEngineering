# Simple single character input and output

|
| Task | Details |
| :--- | :--- |
| 1 | First you need to create a new project. From the "Solution Explorer" right click the Solution (VariablesAndArithmetic) and select "Add -> New Project". From the list on the right of the window that opens select "Console App" and then "Next". For Project Name enter GetChar (or similar) then "Create". The new project will appear at the bottom of the Solution Explorer window with a source file "GetChar.cpp". Right click on the first line of the new project "GetChar" and select "Set as Startup project" The file GetChar.cpp should now be in the edit window. |
| 2 | For simplicity delete all the comments and replace the code within the body of the main() function with the following: |

```C++
int character;
printf("Enter any random character between a-z: ");
character = getchar();

printf("The entered character is : \n");
putchar(character);
printf("The character is char %c and the integer %d from the ASCII table\n", character, character);
return 0;
```

| Task | Details                                                                                                                                                                                                                                                                                       |
| :--- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 3    | Notes: The getchar return value is typecast (converted) to an int. The function waits for the enter key, if more than one key is pressed before that only the first character entered is used, the rest are discarded. Before you run the program make sure your source code looks like this: |

```C++
#include <iostream>

int main()
{
    int character;
    printf("Enter any random character between a-z: ");
    character = getchar();

    printf("The entered character is : \n");
    putchar(character);
    printf("The character is char %c and the integer %d from the ASCII table\n", character, character);
    return 0;

}
```

| Task | Details                                                                                                                                                                                                                                                         |
| :--- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 4    | Run the program, try entering some data, what happens if you enter ctrl-g for example, can you explain the output then? Note that the character entered is stored as an int but printf() can be configured to print the ASCII character using the %c construct. |
