## Arithemtic

When you define a variable withing your C/C++ program the type (integer, float etc) defines what operations can be done on that variable.

The common mathematical operators for numeric variables are:

+ Addition and Increment
+ Subtraction and Decrement
+ Multiplication
+ Division
+ Remainder (modulo) - Integers only

### Addition and Subtraction (with Increment and Decrement)

| Task | Details |
| :--- | :---    |
| 1    | First you need to create a new project. From the "Solution Explorer" right click the Solution (VariablesAndArithmetic) and select "Add -> New Project". From the list on the right of the window that opens select "Console App" and then "Next". For Project Name enter Arithmetic (or similar) then "Create". The new project will appear at the bottom of the Solution Explorer window with a source file "Arithmetic.cpp". Right click on the first line of the new project "Arithmetic" and select "Set as Startup project" The file Arithmetic.cpp should now be in the edit window. |
| 2    | Edit your source code to look like this:
```C++
#include <iostream>

int main()
{
    int startInt = 0, creditInt = 10, debitInt = 0, balanceInt = 0;

    // Use the + operator to add startInt to creditInt and assign the result to balanceInt
    balanceInt = startInt + creditInt;
    printf("Started at %d balance now at %d\n\n", startInt, balanceInt);

    // use the - operator to subtract debitInt from balanceInt and assign the result to balanceInt
    printf("Debit 5\n");
    debitInt = 5;
    balanceInt = balanceInt - debitInt;
    printf("Balance now at %d\n\n", balanceInt);
}
```
| Task | Details |
| :--- | :---    |
| 3   | Run the program in the normal way, note that by default int is signed and so the balance can go negative (just like real life!) try different values.|
| 4   | Add the following to your source code:
```C++
// Use the increment operator to increase the balance by 1
printf("Increment balance by 1\n");
balanceInt++;
printf("Balance now at %d\n\n", balanceInt);

// the increment operator can also be used in this way
printf("Increment balance by 7\n");
balanceInt += 7;            // This is the same as balanceInt = balanceInt + 7
printf("Balance now at %d\n\n", balanceInt);
```
| Task | Details |
| :--- | :---    |
| 5 | Run the program and observe the results|
| 6 | Add the following to your source code:
```C++
// Use the decrement operator to decrease the balance by 1
printf("Decrement balance by 1\n");
balanceInt--;
printf("Balance now at %d\n\n", balanceInt);

// the decrement operator can also be used in this way
printf("Decrement balance by 4\n");
balanceInt -= 4;            // This is the same as balanceInt = balanceInt - 4
printf("Balance now at %d\n\n", balanceInt);
```
| Task | Details |
| :--- | :---    |
| 7 | Run the program and observe the results|

### Multiplication

| Task | Details |
| :--- | :---    |
| 8 | Add the following to your source code:
```C++
// Use the multiply operator (*) to increase creditInt
printf("Credit before is %d\n", creditInt);
printf("Increase credit by factor of 5\n");
creditInt = creditInt * 5;              // This can also be written creditInt *= 5
printf("Credit after is %d\n\n", creditInt);
```
| Task | Details |
| :--- | :---    |
| 9 | Run the program and observe the results|

### Division

| Task | Details |
| :--- | :---    |
| 10 | Add the following to your source code:
```C++
// Use the division operator (/) to decrease creditInt
printf("Credit before is %d\n", creditInt);
printf("Increase credit by factor of 3\n");
creditInt = creditInt / 3;              // This can also be written creditInt /= 3
printf("Credit after is %d\n\n", creditInt);
```
| Task | Details |
| :--- | :---    |
| 11 | Run the program and observe the results, something is wrong! Surely 50/3 is not 16? Well the compiler has done exactly what we asked it to do give the integer value (i.e. throw away the decimal part). To see the correct result we need a floating point variable to hold the result. |
| 12 | Change the last few lines of the code to this:|
```C++
float creditFloat = 0.0;
creditFloat = creditInt / 3.0;              // This can also be written creditInt /= 3.0

printf("Credit after is %f\n\n", creditFloat);
```

| Task | Details |
| :--- | :---    |
| 13 | Run the program and observe the results, note the divisor has changed to 3.0, now the result is correct. Obviously it would make more sense for all the variables to be floating point ones. The operators above work in exactly the same way for floats and doubles.

### Modulus

Note this operator can only be used on integer variables.

| Task | Details |
| :--- | :---    |
| 14 |  Delete all the source code (or comment it out) and copy in the following code:|
```C++
int remainder = 0, sum = 25, divisor = 4;

remainder = sum % divisor;       

printf("Remainder after dividing %d by %d is %d\n\n", sum, divisor, remainder);
```
| Task | Details |
| :--- | :---    |
| 15 | Run the program and observe the results, try different values for yourself. |