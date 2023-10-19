# Functions and Function Scope

**Contents**

* [Fundamentals of Functions](#fundamentals)
   1.  [Simple Functions](#simple-functions)
   1.  [Functions with parameters](#functions-with-parameters)
   1.  [Function Prototypes](#function-prototypes)
   1.  [Functions with return types](#returning-values)
   1.  [Working with complex data structures](#working-with-complex-data-structures)
   1.  [Passing Parameters by Pointer](#passing-parameters-by-pointer)
   1.  [Passing Parameters by Reference](#passing-parameters-by-reference)
* [Function Scope](#function-scope)
   1.  [Global Functions](#global-functions)
   1. [Static Global Functions and Variables](#static-global-variables-and-functions)
* [Challenges](#challenges)
 
## Fundamentals of Functions

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

### Simple Functions

Let's first look at a simple example of a function.

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
| 6 | Create a function `displayBanner()` to perform the repetitive code (see code below). |
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

Note the position of the **global variable** `L` is not ideal. This variable can be both read and written from anywhere in your project. This means that you cannot reuse the variable name `L` elsewhere without causing ambiguity or errors.  

> When the same global variable name is used twice by mistake, this is known as a **name collision**
>
> As a general rule, only use global variables when absolutely necessary.

Let's now remove the need for the global `L` by *passing it as a parameter*.

### Functions with Parameters

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

> **Note** that the variable `L` is now declared inside the `main` function. We say is it a **local variable**, and only visible within the **scope** of `main`.
>
> `L` is now local to main.

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
| Make `503-passing-parameters-solution` the start up project |
| Move the functions `displayBanner` and `displayWithinBanner` to the bottom of the file (below main) |
| Try and build the code |

You will note that the code no longer builds. You may get an error such as:

` 'displayWithinBanner': identifier not found`

The compiler performs one-pass through the file. If it encounters a function name (e.g. inside `main`) before it has seen the function, it has no way to check the parameter and return data types are correct (or compatible). Therefore, in C and C++, you usually **declare** your functions first.

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

Note the semi-colons at the end of each line. These are known as function **declarations**. They do not contain the code, just the *interface*. The function itself (currently at the bottom of main) is called the function **definition**.

| |
| - |
| Now build the code again and check it runs |
| |

In doing this, we have pre-informed the compiler about these functions.

* The name
* The number of parameters
* The data types of each parameter
* The return type

Now when you try and call these functions in your code (where ever they are located), the compiler can perform the necessary checks.

> **Note**
>
> This highlights an important difference between **strongly typed** languages (such as C,C++,Rust,Swift,C#,Java) and **loosely typed** languages (such as Python, PHP and JavaScript)
>
> Compilers try and perform checks at compile time, and will not build your code unless it conforms to certain (sometimes strict) rules. This makes them harder to write, but is also safer in some respects.
>
> Interpreted languages do not have compile phase, so such errors are typically found at *run time*. They also tend to be loosely typed, performing conversions automatically where it can (or crashing if it cannot be done). This makes testing challenging.
>
> Both have merits. As you can probably appreciate, safety or business critical applications tend to prefer the compiled type-safe languages. The downside is you need to compile your code for each platform you run it on. Web applications need to run on all types of machine, so tend to us interpreted languages.
>
> Check out [web assembly](https://developer.mozilla.org/en-US/docs/WebAssembly) to see how type-safe languages are now being used in web applications.
>
> Also, see the [Type Script Language](https://www.typescriptlang.org/) which *transpiles* into JavaScript. 

### Returning Values
In the examples so far, we have seen functions where the output is the terminal. Often, we want to retrieve information back from functions, such as the result of a calculation or an error code.

| Task | `505-diff` |
| - | - |
| 1 | Make the project `505-diff` the start up project |
| 2 | Build and step through the program. When you encounter a function called `sub`, step IN |
| - | Note how the result is passed back using the `return` statement |
| - | Note also how the function is written, with an integer (`int`) return type as well as parameters |

```C++
int sub(int u, int v)
{
    int y = u - v;
    return y;
}
```

In general, we write a function in the form:

`<return type> function_name(parameters)`

Let's now add another function to try and make `main` simpler.

| | |
| - | - |
| 3 | Create another function `absDiff` that accepts two integer parameters, and returns an integer. Don't forget the declaration (aka function prototype) at the top of the file. |
| | The code should calculate the difference between the two parameters, such that the smaller value is always subtracted from the larger |
| *hint* | Move and modify the code between the comments \*\*1\*\* and \*\*2\*\* out of main and into this new function. Don't forget to call this function from `main` |
| - |  A solution is available |

### Working with complex data structures

So far, we've written functions to accept parameters and return a single result (where appropriate). With the exception of `string`, these were *baked in* value types (`int` being one of these).

The datatype `string` is not a built-in data type, but part of the standard C++ library of *collections*. This is a large topic, which we will start to look at using C++ structures (we are leaving C behind at this point).

To explain a structure, let's begin with an example:

```C++
struct Point {
    int x;
    int y;
    float length;
};
```

The new data type is called `Point`. It is composed of three separate storage elements (two of type `int` and another of type `float`). We call these **members**.

We create a variable of type `Point` in the usual way (`<data type> <variable_name>[=initial value(s)];`):

```C++
Point p;
```

We can write values into `p` as follows:

```C++
p.x = 3;
p.y = 4;
p.length = 5.0f;
```

We can initialise a structure type as follows:

```C++
Point p = { 3, 4, 5.0f }; 
```

> Variations in Standards
>
> There have been multiple updates to the C++ language standard. In C++ 20 (and onwards), we can (officially!) label the initial values:
>
> `Point pp = { .x = 3, .y = 4, .length= 5.0f };`
> 
> Some compilers have added this as an extension to older standards. 

We can read values from `p` as follows:

```C++
int xx = p.x;
int yy = p.y;
float zz = p.length;
```

Note how the `dot notation` is used to access each member of the structure. As well as packaging multiple data values into one variable, this also makes for very readable code.

Finally, we can copy from structure to another with ease:

```C++
Point p2 = p;
```

This will copy each member value from `p` into `p2`. Note that `p` and `p2` are separate independent variables, with different addresses in memory.

> **Terminology**
>
> We say that the data type `Point` **encapsulates** it's members (two integers and a floating point value in this case).

| Task | 507-UsingStructures |
| - | - |
| 1 | Make 507-UsingStructures the start up project. Step through the code, reading the comments and observing the output |
| - | Step IN to the functions `displayPoint`, `calculateLength` and `flipPoint` to see how they work |
| 2 | Now write another function `addPoint` that accepts two parameters `p1` and `p2` of type `Point`. The returned result is a new structure with it's `x` member being equal `p1.x + p2.x`  and it's `y` member being equal `p1.y + p2.y`. You should also calculate the length. |
| - | A solution is provided |

Note how structures can be both passed as parameters and returned from functions.

> **FAQ**
>
> A common questions is "how do I return more than one value from a function"?
>
> One solution is to use a `struct`. You will find `struct` in many languages.

### Passing Parameters by Pointer

Like the baked-in data types, structures are **value types**. When you equate one to the the other, a copy is performed. Passing and returning structures therefore involves a lot of copy operations, at least that is the logic. 

> One the face of it, this sounds inefficient and expensive in terms of CPU time. In practise, modern compilers use a process known as **optimisation** to make it more efficient.

We will now look at technique that avoid/reduce the copy operations. These are used more for convenience than performance. 

The first method is to use a **pointer**. We will illustrate this in the next example.

| Task | 509-passing-by-pointer |
| - | - |
| 1. | Make 509-passing-by-pointer the startup project |
| 2. | Step through the code, and into any functions that are part of this project |
| 3. | Read the comments and observe the code |

Let's look at main:

```C++
    //Create two variables of type Point
    Point p1 = { 3, 4, 5.0f };      //Initialised inline

    //Now demonstrate returning a structure
    displayPoint(p1);               //Showing p1
    flipPoint(&p1);                 //Pass the address so p1 can be modified by the function
    displayPoint(p1);               //Showing p4
```

The focus point of this code is as follows:

```C++
flipPoint(&p1);
```

Note that is the **address** of a structure variable that is passed (as a copy), not the data values. This is always a 32-bit value (on our compiler), irrespective of how complex the structure is. 

> Pointers are known as **reference types**. When using the `=` operator, it is the address of the data that is copied, NOT the data itself.

Why we do this may become apparent when we look at the function:

```C++
// Swap the x and y coordinates of p in-place
void flipPoint(Point* p)
{
    int prevX = p->x;   //Keep a copy of the previous x member value
    p->x = p->y;        //Update x
    p->y = prevX;       //Update y
}
```

As the function `flipPoint` has the address of `p` (and not a copy of the data!), it has the capability to directly modify it's memory, and hence it's data members. It therefore has the ability to overwrite whatever is passed to it.

> We say that `p1` has been passed **by reference** (as opposed to **by value**)

Note that when the variable is not a structure type (`Point`), but a pointer to a structure (`Point*`), you must use the **arrow notation** `->` to differentiate for both read and write operations.

> **Pointer Types**
>
> These are often confusing. The type `Point*` is just an integer that holds an address. Look at the memory at that address, and you will just find numbers. In fact all pointers are just the same, whether it is `char*`, `float*` or `Point*`. They are all just integers that store addresses of some data in memory.
>
> So what is the difference between them?
>
> The pointer variable holds an address, but the type provides further information to the compiler about the type of data stored at that address. So when we go to read or write *values* stored at that memory address (known as de-referencing), it knows about the type (size, layout etc..).
>
> * For a `char*`, you read/write the data as a single 8-bit integer
> * For a `float*`, you read/write the data as 32-bit floating point value
> * For a `Point*`, you read/write the data in the knowledge the layout is two integers and a float.
>
> For example, you can only read the `x` member value using `p->x` because it knows the type of the data at the address `p`. If the pointer was `int* p`, then `p->x` would have no meaning (compiler error).
>
> It also allows the compiler to check for type-safety of course.

| | |
| - | - |
| 4. | Modify the `calculateLength` function so that it does not need to return a value, but instead updates the length member value (in place modification) |
| - | For your reference, the current version is shown below |
| - | A solution is provided |

```C++
float calculateLength(Point p)
{
    float h = sqrt(p.x * p.x + p.y * p.y);
    //p.length = h; //This would be pointless as p is a copy
    return h;
}
```

### Passing Parameters by Reference

Pointers exist in both the C and C++ languages, and are fundamental to how programs manipulate memory. Many people find them confusing, and find their syntax unpleasant to read. In other languages pointers will still be there, but are usually hidden from view.  

Luckily, in C++, there is another way of achieving much the same thing, and that is using **references**.

Again, we will begin with an example.

| Task | 511-passing-by-reference |
| - | - |
| 1. | Make 511-passing-by-reference the start up project |
| 2. | Build and then step through the code, stepping into any custom functions |
| 3. | Note how all the pointer notation has been replaced |

Take the function `flipPoint` as an example. We invoke it as follows:

```C++
flipPoint(p1);
```

Doing this actually modified `p1`. 

> Looking at this line, it would be understandable if you did not expect `p1` to be modified!.
> 
> This is point of some controversy. When using pointers, it is apparent that you are passing an address by the presence of the `&` operator (e.g. `flipPoint(&p1);`)
> 
> With references, you just have to know.

How was this possible? The answer lies in the parameter type for function `flipPoint`:

```C++
void flipPoint(Point& p)
{
    int prevX = p.x;   //Keep a copy of the previous x member value
    p.x = p.y;         //Update x
    p.y = prevX;       //Update y
}
```

The data type `Point& p` is a reference type, backed by a hidden pointer. This brings C++ closer to the syntax of other languages. It gets you reference type behavior, without the pointer syntax. It is cleaner and easier to read (and there are some safety benefits as well).

## Function Scope

So far we have kept all our code in a single file. In practise, this is only done in the case of very simple projects. Most projects are build from multiple source files. There are many reasons for this:

* **Build Time** - the compiler on builds files that have changed. If everything is in one file, everything has to be recompiled even with the slightest change.
* **Separation of Concerns** - it is good to keep related code together. It helps navigate large complex projects, and maybe divide work between different individuals.
* **Reuse** - if functions are all in one file, then to reuse those functions would need the sharing of all code with other projects. When factored into separate files, you can selectively reuse just the functions that you need. This also applies if you are reusing someone elses code (such as a complex library).
* **Safety** - some functions can be made hidden from the rest of the project while others are shared. This might be because they are for "internal use only", and for others to use them directly risks breaking the internal state of the program.

Splitting our project into separate files is sometimes confusing, but an essential skill as our projects grow larger.

### Global Functions

All the functions we have written so far have been **global**. This is the default, and makes our function potentially accessible from anywhere within the project.

This also makes it quite simple to move our functions into separate files within our project.

| Task | 512-SplittingTheProject |
| - | - |
| 1. | [Watch this video on how to split your code in separate concerns](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=b3c3f6c9-e104-470f-9740-b09e00fd8b42) |
| 2. | Create a project `512-SplittingTheProject` as shown in the video |
| 3. | Try and replicate what you saw in the video |
| - | A solution is available |

Now that we've split our functions into separate files, they can all be accessed anywhere in the project. We say they have **global scope**.

### Static Global Variables and Functions

Global functions are quite common, but sometimes we don't want them to be global. Global variables are actually not to be encouraged at all (try and use local). 

There is an another option known as a **static global** scope that applies to both functions and variables.

In the next task (`513-StaticGlobals`), another `struct` is used to represent a rectangle.

```C++
struct Rect_t
{
	uint32_t width;
	uint32_t height;
	uint64_t area;
};
```

The data type is `Rect_t` (the capitalisation of `R` and the `_t` suffix are a convention for a *type*). This data type encapsulates three members:

* width of the rectangle `width`
* height of the rectangle `height`
* area of the rectangle `area`

Let's see this working in this simple example.

| TASK | 513-StaticGlobals |
| - | - |
| 1. | Make 513-StaticGlobals the startup project. |
| 2. | Step through the code, reading the comments and observing the output |
|  | Step into each function (except `cout`) | 
| 3. | There is a function called `updateArea`. It is never called in main. <a title="It is called when ever the area of the rectangle needs to be recalculated, such as when first created, or when one of the sides changes length.">When is it called and why?</a> |
| 4. | Try calling `updateArea` from within main (uncomment the line at the end of main). <a title="Because it is a static function. It is only visible within the file in which it is defined">Why do you think this is now permitted?</a>|

**Key Points:**

The function `updateArea` is declared as `static`. This means it is only visible within the file in which is is defined, which in this case is `Rect_t.cpp`. It is not visible in any other file (this also means the function name `updateArea` could also be re-used in another file).

We can use the `static` keyword to limit the **scope** of a function (or global variable). To understand *why* we limit scope, note the following:

* In main,  the `width` and `height` are be set to literal values.
   * They are never changed directly. It is always done via the functions `CreateRect`, `updateHeight` and `updateWidth`
   * If either `width` or `height` are changed via these functions, the area is always re-calculated automatically by these functions. This is done so we cannot forget!
   * For each combination of `height` and `width`, there is only one solution to area.
* The member `area` is only re-calculated on need (when one of it's dependents changes). For more complex problems, where the cost of calculations is much higher, this technique is useful to maximise performance.
* We never set the area from main (more strictly, anywhere outside `Rec_t.cpp`)
   * There is no function provided for this (`updateArea` is static, so cannot be accessed from outside `Rec_t.cpp`)
   * If we allowed this, what would the correct height and width be? For any chosen value of area, there can be many combinations of height and width
* **If we stick to the functions provided**, the above is always enforced, and **the data integrity of a rectangle data structure cannot be broken**.

What has been created here is an **Application Programming Interface** (known as **API**).

> **Limitation**
>  
> We can still break this code by not using the API. The compiler cannot stop us modifying the area directly. 

```C++
	Rect_t r1 = CreateRect(10, 20);
    r1.area = -99;
	display(r1);
```

The good news is that there is a way to enforce these rules, but for that, we have to leave `C` completely and embrace the C++ way, which is Object Orientated Programming (OOP).

## Challenges

Below are a set of challenges for you to work on in your own time. Solutions will become available at a later date.

| Challenge 1 | Simple API |
| :--- | :--- |
| 1 | Write a program to create two integer variables, add them together store the result in another variable. Use `cout` to print the values of the variables and the result.
| 2 | Now create a simple API to add, subtract, multiply and divide integers |
| - | These should be written in a separate source file `MyLib.cpp`. Create a header to list all the function declarations |
| 3 | Modify main to test your API |
| 4 | What happens if you accidentally divide by zero? Try it and think about how you might handle this. | 

Here is the first API to get you stared:

```C++
int add( int a, int b)
{
  int result;
  result = a + b;
  return result;
}
```

| Challenge 2 | Working with Arrays |
| :--- | :--- |
| 1 | Create a new project. Within the `main()` function, add a for loop that runs through an array of integers such that it adds up all the values and stores the result in the variable `total`. Print out the total to the terminal

```C++
int main()
{
    int nums[10] = { 12, 5, 77, 23, 102, 42, 98, 64, 17, 59};
    int total = 0;
    // your code below here
}
```

| | |
| - | - |
| 2 | Can you write a function that takes an array as a parameter and returns the sum. |
| - | You may struggle with this at first. Remember that an `array` variable is really a pointer (address). |
| 3 | Add a second parameter to your function that specifies the length of the array.  Your function might look something like this |

```C++
int sumArray(int* arrayPointer, int N)
```

| Challenge 3 (advanced) | C++ Collections |
| - | - |
| 1. | Look at the project `ArrayAndVector`. Build and read the comments |
| 2. | Modify challenge 2 to use the `array<>` type? |


---

[Back to Table of Contents](./README.md)

