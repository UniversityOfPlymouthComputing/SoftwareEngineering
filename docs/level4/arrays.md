# Arrays

In a previous lab we used an array (of chars) to allow us to construct a string. Something like this:

char name[6] = "Monty";

Here we have created an array of 6 chars which has been initialised with the name 'Monty' plus the null character which the compiler adds.

Equally this statement:

int nums[10] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};

Creates an array of 10 integers. There is not null character at the end - that is only for strings.

Now lets manipulate these two arrays.

| Task | Details |
| :--- | :--- |
| 1 | As in previous labs, create a new project called "Arrays" or similar, delete the comments and replace the code within the function main() with the following:

```C++
char name[6] = "Monty";
int nums[10] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};

printf("The first letter in the array name[] is %c the last is %c\n", name[0], name[5]);
printf("The Second number in the array nums[] is %d the one from the last is %d\n", nums[1], nums[8]);

```

| Task | Details |
| :--- | :--- |
| 2 | Run the program and observe the results. The important thing here is that arrays in C/C++ are numbered from 0 and the last character in the array name[](because it's a string) is a null (\0). The expression name[0] means the first character in the array name[]. The expression nums[1] gives the second value in the array nums[]. Try changing the values within the square brackets to confirm this. The C/C++ languages will not stop you accessing values outside the arrays - try accessing nums[10] to see what happens. Accessing an array outside it's bounds is a common error and can cause serious problems with your program.

| Task | Details |
| :--- | :--- |
| 3 | In a similar way we can change the contents of the array. Add the following lines to your program:

```C++
name[1] = 'i';
nums[3] = 3333;

printf("Name is now %s\n", name);
printf("The 4th number in the array nums[] is %d\n", nums[3]);
```

| Task | Details |
| :--- | :--- |
| 4 |  Run the program and observe the results. Try changing other elements in the arrays. Remember, array elements are numbered from zero and it's your responsibility to only reference elements inside the arrays - otherwise very bad things will happen and curry will never taste the same again!|
