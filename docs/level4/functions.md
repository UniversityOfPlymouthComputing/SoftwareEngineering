# Functions

| Task | Details |
| :--- | :--- |
| 1 | As in previous labs, create a new project called "Functions" or similar, delete the comments and all the code within the function main(). Your program should now look like this:

```C++
#include <iostream>

int main()
{
    
}
```

Your program doesn't do anything yet bu it does contain one function - that is main(), every C/C++ program must have one (and only one) function called main() this is where program execution starts.

| Task | Details |
| :--- | :--- |
| 2 | Modify your program to create two integer variables, add them together store the result in another variable. Use printf() to print the values of the variables and the result.

| Task | Details |
| :--- | :--- |
| 3 | Modify your program to subtract the smaller of your two variables from the larger one. Assign the result of this subtraction to a new variable and use printf() to output all 4 variables. Your code might look a bit like this:

```C++
#include <iostream>

int main()
{
    int var1 = 42, var2 = 12;       // create the two integer variables
    int sum = 0, diff = 0;          // create variables to hold the reslts of the calculation

    sum = var1 + var2;
    if (var1 >= var2)               // check which variable is larger - also this covers the case where they are the same
    {
        diff = var1 - var2;         // do the subtraction
    }
    else
    {
        diff = var2 - var1;         // do the subtraction
    }
    // print out the results
    printf("var1 = %d, var2 = %d sum = %d diff = %d\n\n", var1, var2, sum, diff);
}
```

| Task | Details |
| :--- | :--- |
| 4 | The two operations (addition and subtraction) are good candidates for putting into functions. This will clean up the code in main() and allow the functions to be called from multiple places in your program. Lets start with the addition, add this code to your program before main()

```C++
int add( int a, int b)
{
  int result;
  result = a + b;
  return result;
}
```

This defines a function called add() that takes two parameters (both type int) and returns an integer.

To use this functio we need to 'call' it from within main() and process the value it returns.

Here is the complete program now:

```C++
#include <iostream>

int add(int a, int b)
{
    int result;
    result = a + b;
    return result;
}

int main()
{
    int var1 = 42, var2 = 12;       // create the two integer variables
    int sum = 0, diff = 0;          // create variables to hold the reslts of the calculation

    sum = add(var1, var2);

    if (var1 >= var2)               // check which variable is larger - also this covers the case where they are the same
    {
        diff = var1 - var2;         // do the subtraction
    }
    else
    {
        diff = var2 - var1;         // do the subtraction
    }
    // print out the results
    printf("var1 = %d, var2 = %d sum = %d diff = %d\n\n", var1, var2, sum, diff);
}
```
The line sum = add(var1, var2) calls the function add() passing it the two variables (var1 and var2) the return variable is assigned to sum.

| Task | Details |
| :--- | :--- |
| 4 | Repeat the process above to add a function called difference() that takes as parameters the two variables var1 and var2 and returns the difference between them. Call your new function from within main().


To be continued...