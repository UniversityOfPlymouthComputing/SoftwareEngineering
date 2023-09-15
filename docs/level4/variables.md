## Variables
Lets look at the variables in a little more detail. 

| Table of Contents |
| - |
| [Integers](#integers) |
| [Floating Point Numbers](#floating-point-numbers) |
| [Char](#char) |
| |

### Integers.

| Task | Details |
| :--- | :---    |
| 1    | First you need to create a new project. From the "Solution Explorer" right click the Solution (VariablesAndArithmetic) and select "Add -> New Project". From the list on the right of the window that opens select "Console App" and then "Next". For Project Name enter IntegerFun (or similar) then "Create". The new project will appear at the bottom of the Solution Explorer window with a source file "IntegerFun.cpp". Right click on the first line of the new project "IntegerFun" and select "Set as Startup project" The file IntegerFun.cpp should now be in the edit window. |
| 2    | The body of the function main() is between the curly braces {}, replace the code there with the following code here:
```C++
int a, b = 8, c;
printf("a = %d , b = %d , c = %d\n", a ,b ,c);
```
Your code should now look something like this:
```C++
#include <iostream>

int main()
{
    int a, b = 8, c;
    printf("a = %d , b = %d , c = %d\n", a, b, c);
}
```
To save space all the comments have been removed, don't worry about the first line for now but the printf() function needs a little explanation - all of the text between the "" quotes will be displayed on the terminal with the exception of the %d characters. These are 'place holders' for the three variables a, b and c. The values of these variables will be printed where the place holders are. The d character after the % tells printf to expect an integer. The '\n' will insert a new line into the output.
| Task | Details |
| :--- | :---    |
| 3    | Now select "Start without debugging" from the Debug menu. In the window at the bottom of the screen (labelled "Output") you should see 2 error messages. These give detail the filename (IntegerFun.cpp) the line number (6) and the error (uninitialised local variable used). This compiler is setup to warn you that variables a and c have been defined but no values have been assigned, be aware that not all compilers will do this and will happily let you use variables that have a random value. It is good practice to always initialise variables when they are defined. So now lets change line 5 to this: 
```C++
int a = 3, b = 8, c = a * b;
```
A word of explanation here, the '*' character is the multiplication operator so the variable c is being set to the value of a multiplied by b. We can do this because a and b already have values. Now run the program and observe the output.
|
| Task | Details |
| :--- | :---    |
| 4    | The variables a, b and c are fine and easy to type but they don't convey much about your intention as a programmer. Let's assume you are working on a program that needs to calculate the area of something. Now change lines 5 and 6 to this:
```C++
int width = 3, length = 8, area = width * length;
printf("width = %d , length = %d , area = %d\n", width, length, area);
``` 
This change doesn't affect the program functions (the compiler doesn't care what you call your variables) but it makes more sense to anyone reading the code. |
| Task | Details |
| :--- | :---    |
| 5    | Not all software runs on large PCs with virtually unlimited memory, you might be working on an embedded device for the next Android device for example where the memory is fixed and might be very limited. So how much space are your variables using?

Insert the following line at the end of your code:
```C++
printf("Size of a int is %zd bytes\n", sizeof(int));
```
The sizeof() function returns (in this case) how much memory (in bytes) an integer uses in this envornment. Run the program.
You should see that an integer here takes 4 bytes (32 bits). Integers variables can be signed or unsigned the maximum values as follows:
unsigned int    0 to 4294967295
signed int      -2147483648 to 2147483647 
(source https://learn.microsoft.com/en-us/cpp/cpp/integer-limits?view=msvc-170)
As the programmer it's up to you to decide which to use, in this case negative values (for the sides of  box) doesn't make sense so you would probable choose unsigned. |
| Task | Details |
| :--- | :---    |
| 6    | Now lets assume you have to save some memory there is a smaller integer variable called a short which in unsigned form has a maximum value of 65535, you checked the specification of the project and that is sufficient. Change  line 5 to this:
```C++
unsigned short width = 3, length = 8, area = width * length;
```
and add this line to the end of the code:
```C++
printf("Size of a short is %zd bytes\n", sizeof(short));
```
Run the program - it still works as before and as you can see short only uses 2 bytes. But there is a potential problem! |
| Task | Details |
| :--- | :---    |
| 7    | Try changing the values of width and length to say 32000 and see what happens. What do you think has happened? The value you are now trying to store in area is too big for a short int. Change the definition of area as below and run the code again.
```C++
unsigned short width = 32000, length = 32000; 
unsigned int area = width * length;
```
You can see from this that the type of variables you use must be chosen carefully!

There are larger integers available, refer to the link above for more details.

Add the following lines to the code and run the program again.
```C++
printf("Size of a long is %zd bytes\n", sizeof(long));
printf("Size of a long long is %zd bytes\n", sizeof(long long));
```
In this environment long takes 4 bytes and long long takes 8 bytes. |

### Floating Point Numbers

Reference link: https://learn.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-170

| Task | Details |
| :--- | :---    |
| 1    |   Repeat Task 1 from above and create a new Project called "FloatingFun" or similar, I'm sure there is humour in there somewhere! Make sure you set it as the Startup Project!       |
|2     | There are 3 floating point variable types available (float double and long double) Note (from the link above) that double and long double take the same amount of memory (8 bytes) and offer the same range of values. Update your source code in the recently created project to this:
```C++
#include <iostream>

int main()
{
    // float 
    float pi_float = 3.14159265358979323846;
    printf("The value of pi is approximately %f\n", pi_float);

    // double
    double pi_double = 3.14159265358979323846L;
    printf("The value of pi is approximately %lf\n", pi_double);
}
```


| Task | Details |
| :--- | :---    |
|3     | The output on the terminal shows both variables limited to 6 decimal digits but that is limited by the way printf works. Now set a breakpoint on the line where pi_float is defined and run the debugger. See what values are in both variables.     |
|4    |  It is possible to get printf to output more of the decimal digits - change the place holder in the second printf to this  %.12lf.      |
|5    |  Finally add the following to your source code to check the size of the floating point variables:
  ```C++
  printf("Size of a float is %zd bytes\n", sizeof(float));
printf("Size of a double is %zd bytes\n", sizeof(double));
  ``` 
 | Task | Details |
| :--- | :---    |  
|6    |  Run the program once more and it should show that a float takes 4 bytes and a double 8 bytes. Keep this project open - we will use it for the next Tasks as well.


### Char

As the name suggests the 'char' variable is commonly used to store a single character. A char takes only one byte in memory.

By default char is signed with a range of -128 to 127, when defined as unsigned the range is 0 - 255.
| Task | Details |
| :--- | :---    |
|7     | Add the following lines to your source code:
```C++
char c = 65;
printf("c has the value %d and is the %c character\n\n", c, c);

printf("Size of a char is %zd bytes\n", sizeof(char));
```
| Task | Details |
| :--- | :---    |
|8    |  Run the program and observe the output. You can see that printf can output the char variable 'c' as either an integer or a single character from the ASCII table - in this case the uppercase 'A'. It also confirms that a char takes up only one byte in memory     