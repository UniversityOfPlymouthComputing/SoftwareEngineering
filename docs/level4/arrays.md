# Arrays, String and Pointers

Computer memory is often considered as a "block device" - that is a block of storage, with each element having a unique numerical address. This is depicted in the figure below:

<figure>
<img src="./img/arrays.jpg" width="500px">
<figcaption>Memory can be viewed as a block of N consecutive bytes in memory with a known start address and length.</figcaption>
</figure>

Each element of memory has a unique address. The address is just a number that can be considered the location of some storage element.

In practice, computers often have multiple memory devices that together form the "memory map". Below shows the example of the Raspberry Pi Pico (RP2040). Here you can see multiple memory devices (SRAM, ROM, Flash). Note that memory is not the only type of device that has an address. 

<figure>
<img src="./img/rp2024-architecture.png" width="500px">
<figcaption>Computers often contain multiple memory devices (ROM, SRAM, DRAM) that together form part of the overall "memory map" (figure source - RP2020 Datasheet, Raspberry Pi Foundation).</figcaption>
</figure>

Within memory, two types of information are stored:

* program code
* data (variables)


Program code and constants are usually stored in a memory area that is protected as read-only. 

> In some computers, such as the RP2040, this may be in "flash memory". Many devices, including modern PC architecture, have hardware mechanisms to protect program code from being overwritten.

For this section, we will focus on memory used to store our program **data**, which are usually considered **variables**. This can be anything from a simple character (`char`) to a complex image. So far, we have looked at the built-in data types (`char, short, int, long, float, double`) and their variants. Each of these occupies a fixed size region of computer memory. For example:

```C++
int x;
```

On the compiler used in this course, we can say the following about the variable `x`:

* It is located in the computers "volatile" memory
* It is in an area of memory that can be written
* It occupies 4 consecutive bytes of memory (4*8 = 32 bits)
* The value stored in that memory is considered a signed whole number, with a range of -2<sup>31</sup>...+2<sup>31</sup>-1
* It will have a unique address in memory (obtained via the expression `&x`). The address is decided for us.
* Once defined, it cannot be moved or resized

What if we want to store larger and more bespoke types of information, such as text, images or tables of information? For that, we need more complex *data stuctures*, the most fundamental of which is the **array**.

## Introduction to Arrays

An array is list of `N` data values, where `N>0`. It is stored as a reserved block of memory. You would create a *statically allocated* array of `N` values as follows:

```C++
<data type> array_name[N];
```

For example, a list of 20 integers would be defined as follows:

```C++
int dat[20];
```

In this example, we can say the following:

* The array `dat` represents a block of writable memory with start address `dat`.
* The array has space for 20 integers. This consumes `20*sizeof(int)` = 80 bytes.
* Each element of `dat` is a single integer

You can write to any element in the array by **de-referencing** the array with the `[]` operator. For example:

```C++
dat[3] = 10;    //Write value 10 in the element 3 of the array
int p = dat[0]; //Read element 0 of the array, and copy the value into variable p
```

We say the array `dat` is a **reference type**. The variable `dat` (without any dereferencing) represents the **start address** of the array, which itself is also an integer value. In C/C++ terms, this is known as a **pointer**

<figure>
<img src="./img/organisation_of_arrays.jpg" width="600px">
<figcaption>Array variables are actually integers that hold an address.</figcaption>
</figure>

You can see in the figure above that arrays are really split into two parts: the array variable and the data itself. 

* The array data is a reserved block of memory where the data will be stored.
* The array variable `dat` is actually just an integer that holds an address of that memory so it can be found.  

> We say the array variable `dat` **points** to the block of array data, which is why it is also known as a **pointer** type.

## Creating, reading and writing arrays

| Task | Details |
| :--- | :--- |
|  7 | Now lets revisit the arrays from a previous lab and use the for loop to look at the individual elements. Change the code within main() to the following:

```C++
char name[6] = "Monty";                                     // an arrays of 5 chars that becomes a string
int nums[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };   // an array of 10 integers

// The sizeof() function returns the number of bytes taken up by the array, to calculate the 
// number of elements divide by the sizeof one element.
printf("The number of elements in name and nums are %zd and %zd\n", sizeof(name)/sizeof(name[0]), sizeof(nums) / sizeof(nums[0]));

printf("The letters in the string are\n");  // Remember it's a string so 5 chars plus the null
for (int i = 0; i <= 4; i++)                // The positions of the chars is 0 to 4 (5 in total)
{
    printf("%c - ", name[i]);       //select each character in turn from the array name[]
    if (i == 4)                     // after the last one print a new line
    {
        printf("\n");
    }
}

int sum = 0;                        // summation of all the array elements
float average = 0.0;                // Average of all the array elements

printf("The numbers in the array are\n");
for (int i = 0; i <= 9; i++)        // There are 10 values in the array in positions 0 to 9
{
    printf("%d - ", nums[i]);       //select each value in turn from the array nums[]
    sum += nums[i];                 // same as sum = sum + nums[i] but more concise    
    if (i == 9)                     // after the last one print a new line or two
    {
        printf("\nSum = %d Average = %f\n", sum, sum/10.0);     // calculate the average and print
    }
}

```

| Task | Details |
| :--- | :--- |
|  8 | There is a bit more going on in this example but this time we have added comments in the code to explain help understanding. Comments are a good way to explain to others what the code does and equally when you come back to your code at a later date they will help you as well. Run the code and observe the results. The important lesson here is the way each element of the array is accessed using it's place. For example the first letter in the array name[] is accessed by the construct name[0]. We use a short 'if'  statement to determine when the for loops get to the end.

# Continued

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
