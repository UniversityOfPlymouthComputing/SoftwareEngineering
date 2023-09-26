# Variables and Arithmetic

This this session, the objective as follows:

* Store data in local and global variables
* Display variables in the terminal
* Read data from the terminal intput (keyboard) and store
* Use the debugger to inspect and change variable values
* Perform basic arithmetic

## Writing to the Console

Without input or output, a computer cannot fulfill a useful function.

> Philosophically speaking, is a computer actually a computer if it has no input or output? Discuss<sup>**</sup> (max. 2000 words)

> **<sub>Only joking. If you ever hear me ask for an essay, assume I have been abducted by aliens and replaced with a extra-terrestrial imitation.<sub> 

So it is that we cannot begin to learn a programming language without some form of input and output.

### HelloWorld with `puts` (put string)

In this task, we will learn to do two things:

* Open, build and run a lab project  
* Write "strings" to the terminal

| TASK | HelloWorld-101 |
| - | - |
| 1. | Watch this video to see how to open, build and run the HelloWorld-101 task |
| 2. | Replicate what you saw in the video |
| 3. | Modify the code such that the output reads as follows: |
| - | A solution is provided |


```
**********
Hello World
***********
```

### Writing to the Console with `printf` (print formatted)

One of the most well known *functions* you get with C (and C++) is the `printf` function.

| TASK | 103-WritingToTheConsole |
| - | - |
| 1. | Make `103-WritingToTheConsole` the startup project |
| 2.  | Set a breakpoint on line 6 and step through the code, observing what each line does |
| (a) | In the line that reads `printf("Hello Everyone. We are using C\nHow are things?\n")`, remove the \n characters and run the code again. What does this do? |
| | <p title="It removes the line breaks">Hover over this to see the answer</p> |
| | Now put the `\n` characters back |
| (b) | Use `printf` to display the value of the variable `area`. |
| - | Note that `area` is type `float`, so you will need the %f placeholder |
| - | Referring to the lecture slides, modify this to only display 3 decimal places |
| (c) |  Using `printf`, display the radius and the area using a **single** `printf` statement |
| - | Hint: use more than one place holder |
| 3. | Now look at the solution and read the code and comments |


### Writing to the Console with `cout` (C++)

So far, we have only looked at code from the C language and "standard library"

> A library is a collection of pre-written code that you can reuse in your own projects. `printf` is part of the "Standard C library"

The language C++ is a **superset** of C. What we mean is that is contains all the C language elements, and adds some more. To keep things simple, we want to avoid C++ until later in the module, but as a *sneak peek*, let's look at how C++ helps us write to the terminal output

| EXPERIMENT | 105-WritingToTheConsoleWithC++ |
| - | - |
| 1. | Make 105-WritingToTheConsoleWithC++ the startup project. |
| - | Read the code. Use the debugger to step through the code to see what each line does |
| - | Do not worry if you find it confusing. Many people prefer to stick with `printf`!

The C++ streams (as they are known) are not something we will use except in very simple cases. There is a lot to unpack to understand them, and we are not there yet.

### Reading from the console with `getchar` (read a character)

We have looked at some basic terminal output using `puts`, `printf` and `cout`. Let's not look at how we might receive input via the keyboard.

The simplest function of all is `getchar()`

| TASK | 107-ReadingTheKeyboardWithGetChar |
| - | - |
| 1. | [Watch this video first](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=447a0c2f-9cda-4e14-9357-b08900fd7152) |
| 2. | Build and step through this project as shown in the video. This is good practice using the debugger |
| | |

In the video we met the *function* `getchar()`. Specifically, we saw these lines:

```C++
char c = 0;
```

This creates a variable names `c`. It's **type** is char, which means it can store whole numbers in the range -128..127. It is typically used to store ASCII characters.

This line both reserves the memory storage, but also assigns the value zero in the same line.

> We say that `c` is initialised with the literal value 0

We could equally have written this:

```C++
char c;
c = 0;
```

The first line allocates (reserves) the memory. The second line performs an **assignment with the = operator**.

> Assignments with the `=` operator are always performed right to left. 
>
> The expression on the right hand side is first evaluated (very simple in this case). 
> 
> The result is then copied from right to left, in this case, setting the value of `c`.

In this case, we set `c` to a constant numerical value (known as literal constant). It does not have to be constant values. We can also set values that are calculated when the code runs. We see this below:

```C++
c = getchar();
```

Once again, the right-hand-side is evaluated first. In this case, the function `getchar()` is invoked. 

When this function completes, the function is said to **return a value**. This is the ASCII code of the character typed in. This value is then copied into the variable `c`.

> This is similar to how a pocket calculator works. For example, when you press the number 9, then you press the *square root* button, the square root **function** is called. This calculates and **returns** the result 3. This result can then be used for the next part of the calculation. 

Once we have the value stored in `c`, we can use it in our code. In this case, we write a string:

```C++
printf("You typed %c\n", c);
printf("This has ASCII code %d\n", c);
```

* The first line uses `printf` to **convert** the ASCII code 42 into it's equivalent character (`*`) and display it.
* The second line simply displays it as a number (42)

> Note that `printf` placeholders often perform conversions 

## Integers and Arithmetic

Integers are the formal name for "decimal whole numbers", that is, numbers without a decimal point. The word "decimal" refers to base 10 (popular, as we typically have ten toes :).



## Signed and Unsigned

## Type casting

## Floating Point Arithmetic

## Using `sizeof`

## Structures

## Constants

## Pre-processor constants

## Numerical Errors

## Debugging

### Watching Variables

### Inspecting Memory

All variables are numbers stored in the  memory of a computer. Whatever **type** of data they are, they all end up stored as binary numbers (grouped together, these make integers) stored in the volatile or persistent memory of the computer.

Some development tools allow us to look inside the computer memory so we can see how the binary data is organised internally.

## The `&` operator

Now we have seen data in memory, you will note once more the two key properties of computer data:

* **address** - this is the *location* of the data in the computer memory. In C and C++, it is always an integer value

* value

### `scanf` (scan formatted)

## Challenges

## Advanced Topics

### Unions

### Bitfields

### Endienness

### Compiler warnings

