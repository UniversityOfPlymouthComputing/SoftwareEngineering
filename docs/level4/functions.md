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

| Task | Details |
| :--- | :--- |
| 5 | Change your source code to that below, withing the main() function add a for loop that runs through the array nums[] and adds up all the values and put the result in the variable 'total'. print out the total to the terminal

```C++
#include <iostream>


int main()
{
    int nums[10] = { 12, 5, 77, 23, 102, 42, 98, 64, 17, 59};
    int total = 0;
    // your code below here

}

```
Something like this would work:

```C++
for (int i = 0; i <= 9; i++)
{
    total += a[i];
}

printf("Total is %d", total);

```

| Task | Details |
| :--- | :--- |
| 6 | The task now is to put the code that sums the array into a function, to do this we need to pass the address of the array to the function like this:

```C++
#include <iostream>

void sumArray(int *a)
{
    int total = 0;
    
    for (int i = 0; i <= 9; i++)
    {
        total += a[i];
    }

    printf("Total is %d", total);
}


int main()
{
    int nums[] = { 12, 5, 77, 23, 102, 42, 98, 64, 17, 59};
    
    sumArray(nums); 
}

```

Copy the code above into Visual Studio and compile.

| Task | Details |
| :--- | :--- |
| 7 | The function sumArray in the code above works but only for an array with 10 elements. Amend the code so that the function sumArray now accepts two arguments, the second argument tells the function the size of the array. Also change the function such that it returns the result (total) to the function main().

Something like this:
```C++

#include <iostream>

int sumArray(int *a, int s)
{
    int total = 0;
    printf("s = %d\n", s);
    
    for (int i = 0; i <= (s - 1); i++)
    {
        total += a[i];
        printf("%d %d\n", i, a[i]);
    }

    return total;
}


int main()
{
    int nums[] = { 12, 5, 77, 23, 102, 42, 98, 64, 17, 59};
    int arraySize = sizeof(nums) / sizeof(nums[0]);
    printf("Array size %d\n", arraySize);
    int result = 0;

    result = sumArray(nums, arraySize); 

    printf("Total is %d\n", result);
}

```

| Task | Details |
| :--- | :--- |
| 7 | Finally, it's better to have the body of the functions(s) after main() with the 'prototype' of the function(s) before main(). Amend the code to achieve this.

Something like this:

```C++
#include <iostream>

int sumArray(int* , int );      // Don't forget the semicolon after the prototype !!

int main()
{
    int nums[] = { 12, 5, 77, 23, 102, 42, 98, 64, 17, 59};
    int arraySize = sizeof(nums) / sizeof(nums[0]);
    printf("Array size %d\n", arraySize);
    int result = 0;

    result = sumArray(nums, arraySize); 

    printf("Total is %d\n", result);
}

int sumArray(int* a, int s)
{
    int total = 0;
    printf("s = %d\n", s);

    for (int i = 0; i <= (s - 1); i++)
    {
        total += a[i];
        printf("%d %d\n", i, a[i]);
    }

    return total;
}

```