# Functions and Function Scope

Fundamentals of Functions
 Functions as subroutines
 Functions with parameters
 Functions with return types
 Passing by value and reference
 Working with complex data structures
Function Scope
 Global Functions
 Static Global Functions
 Lambda Functions (local)
 namespaces

## Fundamentals

You have already used a function: `main`

```C++
int main()
{
    cout << "Hello World << endl;
}
```

It has a name `main`, empty parenthesis (more on this later) and an *integer return type*. Again, more on this later. Every executable C and C++ program must have a `main` function.

In C#, it might look like this:

```C#
class HelloWorld {
  static void Main(string[] args) {
    System.Console.WriteLine("Hello World");
  }
}
```

In Java, it might look like this:

```JAVA
class HelloWorld {
    public static void main(String args[]) {
        System.out.println("Hello, World"); 
    }
}
```

In rust, it is similar to C and C++

```RUST
fn main() {
    println!("Hello World!");
}
```

Most *compiled* languages have a similar mechanism. They do share the same lineage of course.

| Task | 501-function |
| :--- | :--- |
| 1 | Open the solution file "Functions" in Visual Studio. |
| 2 | Make `501-function` the startup project |
| 3 | Build and run to see what it does |
| 4 | Change the string to something longer |
| Question | <a title="The for loop uses the length property of the string to know how many * characters to write">How is this able to adapt?</a>
| 5 | Note where the variable `L` is declared |
| Question | <a title="Global Scope - that is, visible anywhere in the program">The variable `L` has a particular type of *scope*. What is this known as?</a>

A key point to note here is that there is some repetition in this code. The following appears twice:

```C++
	for (unsigned int n = 0; n < (L + 4); n++) {
		cout << "*";
	}
	cout << endl;
```

* The first occasion draws the top edge of the box
* The second occasion draws the bottom edge of the box

Both are *semantically* similar - they perform the same basic function. So, let's create a function and give it a name that reflects it's purpose!

| Task | 501-function (continued) |
| :--- | :--- |
| 6 | Create a function `displayBanner()` to perform the repetitive code. |
| - | Use this function to remove code repetition in the main function |
| - | Place this function just before `main` (see code snippet below) |
| - | A solution is provided |

Code Snippet


```C++
#include <iostream>
using namespace std;

int L;		//This is not an ideal location - we will soon address this

void displayBanner()
{
//WRITE YOUR SOLUTION HERE
}

int main()
{
    .
    .
    .
```

> **Note**
> 
> You might have noticed how the length of the string is calculated via `message.length()`.
>
> The `length()` function is a special type known as a *member function* (aka *method* in other languages). 
>
> We will meet this when you begin object orientated programming

Note the position of the **global variable** `L` is not ideal. This variable can be both read and written from anywhere in your project. This means that you cannot reuse the variable name `L` elsewhere without causing ambiguity. 

> As a general rule, only use global variables when absolutely necessary.

Let's now remove the need for the global `L` by *passing it as a parameter*.

### Parsing Parameters

In the previous section, our function was parameterless:

```C++
void displayBanner()
{
...
}
```

We will now pass the string length as a parameter:

```C++
void displayBanner(int L)
{
	for (unsigned int n = 0; n < (L + 4); n++) {
		cout << "*";
	}
	cout << endl;
}
```

We can then invoke this from main, passing in the length of the string.

| Task | 503-passing-parameters |
| - | - |
| 1 | First, [watch this video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=bbbe23dc-d1b3-48c2-a311-b09e00af056f) |
| 1 | Make 503-passing-parameters the start up project |
| 2 | Step through the code using the debugger as shown in the video. |

> **Note** that the variable `L` is now declared inside the `main` function. We say is it a local variable, and only visible within the **scope** of `main`.

What if we really wanted to make the function more useable, so that we can simply pass in the string, and have it displayed with the surrounding banner?

|  |  |
| - | - |
| 3 | Add an addition function `displayWithinBanner` that accepts a single parameter of type `string` |

```C++
void displayWithinBanner(string message)
{
    //Code here
}
```

|  |  |
| - | - |
| 4 | Place it below `displayBanner` and above `main` | 
| 5 | Modify main to simplify it. Your main function should be simplied as follows: |

```C++
int main()
{
	const string message = "Welcome to Computer Science";

	//Write to console
	displayWithinBanner(message);

	//Tell the calling shell all is well
	return 0;
}
```

| |  |
| - | - |
| 6 | Now compare with the solution |

### Function Prototypes

In the previous task, there were specific instructions on **where** to put your functions. Try the following experiment:

| Experiment | 
| - |
| Make 503-passing-parameters-solution the start up project |
| Move the functions `displayBanner` and `displayWithinBanner` to the bottom of the file (below main) |
| Try and build the code |

You will note that the code no longer builds. You may get an error such as:

` 'displayWithinBanner': identifier not found`

The compiler performs one-pass through the file. If it encounters a function call (e.g. inside main) before it has seen the function, it has no way to check the data types are correct and compatible. Therefore, in C and C++, you usually **declare** your functions first.

| |
| - |
| Now modify the top of your file such that it reads as follows: |

```C++
#include <iostream>
using namespace std;

//Function declarations
void displayBanner(int stringLen);
void displayWithinBanner(string message);
```

In doing this, we have pre-informed the compiler about these functions.

* The name
* The number of parameters
* The data types of each parameter
* The return type

Now when you try and call these functions in your code (where ever they are located), the compiler can perform the necessary checks.

> **Note**
>
> This highlights an important difference between **strongly typed** languages (such as C,C++,Rust,Swift,C#,Java) and **loosely typed** languages (such as Python and JavaScript)
>
> Compilers try and perform checking at compiled time, and will not build your code unless it conforms to certain (sometimes strict) rules.
>
> Interpreted languages do not have compile phase, so such errors are typically found at *run time*. They also tend to be loosely typed, performing conversions automatically where it can (or crashing if it cannot be done).
>
> There is a place for both. As you can probably appreciate, safety or business critical applications tend to prefer the compiled type-safe languages.  

### Returning Values



### Challenges

Your program doesn't do anything yet bu it does contain one function - that is main(), every C/C++ program must have one (and only one) function called main() this is where program execution starts.

| Task | Details |
| :--- | :--- |
| 2 | Modify your program to create two integer variables, add them together store the result in another variable. Use printf() to print the values of the variables and the result.

| Task | Details |
| :--- | :--- |
| 3 | Modify your program to subtract the smaller of your two variables from the larger one. Assign the result of this subtraction to a new variable and use printf() to output all 4 variables. Your code might look a bit like this:

```C++
int main()
{
    int var1, var2;

    //Prompt the user
    cout << endl << "Enter value 1: ";
    cin >> var1;
    cout << endl << "Enter value 2: ";
    cin >> var2;

    // create variables to hold the reslts of the calculation
    int sum = var1 + var2;
    int diff = 0;          

    if (var1 >= var2)               // check which variable is larger - also this covers the case where they are the same
    {
        diff = var1 - var2;         // do the subtraction
    }
    else
    {
        diff = var2 - var1;         // do the subtraction
    }

    // print out the results
    cout << "var1 = " << var1;
    cout << ", var2 = " << var2;
    cout << ", sum = " << sum; 
    cout << ", absolute diff = " << diff << endl;
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