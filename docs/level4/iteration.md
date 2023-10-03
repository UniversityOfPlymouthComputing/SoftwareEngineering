# Iteration - looping

Something a computer is very suited to it repetition. A number of terms are used for this, including:

* Looping
* Iteration
* Recursing

There are many uses for iteration and it is something that is common to almost every computer language.

> Iteration is so fundamental to computer programming, you will find that at machine code level, there are special instructions to support it.
>
> Applications that require the same set of operations to be repeated millions (or billions) of times are often very sensitive to small inefficiencies. Examples  include those used in media processing, encryption, AI and game physics. 
>
> Iteration in the C and C++ languages are easily compiled and optimised into efficient machine code, which is partly what makes them so efficient. Iteration is often a lot slower in interpreted languages such as Python and functional languages such as Haskell.

The good news is that the language syntax (programming language grammar) is almost identical in C, C++, Java and C# (to name just some examples). Many languages have syntax that derives from C. They all tend to borrow ideas from each other.

## Do-While loop

In the lecture we started with the `do-while` loop. Perform the following tasks. Hover the mouse over any questions to see the answers.

| TASK | 201-dowhile-loops |
| - | - |
| 1 | Open the solution file in the folder 02 - Iteration |
| 2 | Make project 201-dowhile-loops the start up project |  
| 3 | Build, set a breakpoint and step through the code to see what it does |
| 4 | <a title="5 times">How many times does the loop repeat?</a> |
| 5 | <a title="5">What is the final value of `i` when the code exits?</a> |
| 6 | Change the initial value of the variable `i` to `6` and step through. <a title="It never repeats">What do you notice?</a> |

Let's now look at it more closely:

```C++
#include <stdio.h>

int main()
{
    int i = 0;

    printf("Start while loop\n");

    do
    {
        printf("i = %d\n", i);
        i = i + 1;              // Alternatively, write i++;
    } while (i < 5);            //Repeat if condition is met

    printf("Finished: i = %d\n", i);
}
```


**Key Points:**

1. The 'do - while loop' executes the code between the braces `{}` **at least once**. 
2. The loop condition is then used to decide whether to repeat.

| TASK |
| - |
| Now watch [this video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=44be4830-aa25-4afa-aafa-b09000e4fc0b) summarizing the function of a do-while loop |

| Challenge |
| - |
| Modify the code to count from 5 down to zero |
| A solution is provided |
| |

The output should appear as follows:

```
Start while loop
i = 5
i = 4
i = 3
i = 2
i = 1
i = 0
Finished: i = -1
```

| TASK | 203-dowhile-getchar |
| - | - |
| 1. | Make 203-dowhile-getchar the start up project. Build and run. |
| - | In the terminal, type a single key and then press the return key. Note the output |
| 2. | New press the `q` key and press return, and the program should exit |
| 3. | Uncomment line 17 and repeat |
| - | <a title="Decimal 10">What is the ASCII code for the return key?</a> |
| 4. | Now [watch the following video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=a5816fe7-92a1-4db8-858e-b09000e7486d) to ensure you understand this fully |
| 5. | Can you modify the code so that the user can press `q` or `Q` to exit? |
| Hint | A clue is to rephrase the question in terms of the *condition to repeat the code*. Repeat the code when the user input is not a `q` **and** not a `Q`. |
| | Another way to think of it is the *condition to not exit* |
| | A solution is provided |
| 6. | Now [watch the follow debrief video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=6c895b7f-0e5b-4ac3-a35c-b09000e90883) |
| |

Remember we use the following *conditional operators* to build complex conditions.

| Operator | Meaning | Type |
| - | - | - |
| `&&` | AND | Binary |
| `\|\|` | OR | Binary |
| `!` | NOT | Unary |
| `==` | EQUALS | Binary |
| `!=` | NOT EQUALS | Binary |

Let's reflect on the task above, as it can be confusing. 

* Remember that in a do-while loop, we provide a *condition to repeat* the code.
* This is the logical opposite of the *condition to exit* the loop.

Sometimes it is more natural / intuitive to think of the exit condition instead of the repeat condition. If so, that is fine. We can easily convert one to the other.

> We can say that if `A` is the condition to *exit* the loop, then `!A` is the condition to *reenter* it.

Breaking this down:

1 First write down the condition to **exit** the loop: 

`(userEnteredCharacter == 'q') || (userEnteredCharacter == 'Q')`

2 Invert the logic to get the expression to **re-enter** the loop: 

`!( (userEnteredCharacter == 'q') || (userEnteredCharacter == 'Q') )`

### De-Morgan's Theorem

We can actually take this further and re-write the expression in another form using something known as De-Morgan's Theorem. This allows us to remove the outer `!` operator, and might result in an expression that is more natural (matter of opinion).

Start with the expression we wish to transform:

`!( (userEnteredCharacter == 'q') || (userEnteredCharacter == 'Q') )`

1 Invert the whole expression by removing the NOT (`!`)

`(userEnteredCharacter == 'q') || (userEnteredCharacter == 'Q')`

2 If the logical operator is an AND, make it an OR. If the operator is an OR, make it an AND.

`(userEnteredCharacter == 'q') && (userEnteredCharacter == 'Q')`

3 Finally, invert the logic of the parameters:

`(userEnteredCharacter != 'q') && (userEnteredCharacter != 'Q')`

So the condition to repeat the loop reads as follows:

> "if `userEnteredCharacter` is not a `q` **and** `userEnteredCharacter` is not a `Q`, then repeat"

| Challenge |
| - |
| Change the code above to use this AND based logic. Run the code to check it works. |
| |

For a more formal treatment, see https://en.wikipedia.org/wiki/De_Morgan%27s_laws

## While loop

Similar is the while-loop. This was also covered in the lecture.

| TASK | 205-while-loop |
| - | - |
| 1 | Make project 205-while-loop the start up project |  
| 2 | Build, set a breakpoint and step through the code to see what it does |
| 3 | <a title="5 times">How many times does the loop repeat?</a> |
| 4 | <a title="5">What is the final value of `i` when the code exits?</a> |
| 5 | Change the initial value of the variable `i` to `6` and step through. <a title="The code in the while loop block is never run">What do you notice that is different to the do-while loop?</a> |

Let's now look at it more closely:

```C++
int main()
{
    int i = 0;

    puts("Start while loop");

    while (i < 5)
    {
        printf("i = %d\n", i);
        i++;        // same as i = i + 1 but more concise;
    }

    printf("Exiting with i=%d\n", i);
}

```

Here are some more conditional operators:

| Operator | Name  |
| - | - |
| ==   |Equal to |
| !=   | Not equal         |
| >    | Greater than          |
| <    | Less than         |
| >=   | Greater than or equal to |
| <=   | Less than or equal to         |

| TASK | 205-while-loop (continued) |
| - | - |
| 6 | Modify the code to count down from 10 to 0 is steps of 2 |
| | A solution is provided |
| 7 | Now [watch this de-brief video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=f25e602c-03e5-4b35-b6b4-b09000ef2ebc) |
| |

## For loop

The final looping construct is the 'for loop' especially useful when you know how many times you want to repeat a block of code.

| TASK | 207-looping-N-times | 
| - | - |
| 1. | First, [watch this video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=20878d15-7172-4c28-a32d-b09000f4935f) |
| 2. | Now make 207-looping-N-times the start up project |
| 3. | Build the code, set a break point and step through |
| 4. | Read the A-E tasks in the comments in the code attempt them all  |
| - | Solutions are provided |
| | |

The 'for loop' takes this form:

```C++
for (statement1; statement2; statement3)
{

}
```

| Statement | Action  |
| :--- | :--- |
| statement1 | Executed (once) before the execution of the code block |
| statement2 | Is the condition that must be true for the code block to execute |
| statement3 | Executes every time *after* the code block is executed |

### C99 Standard Loops

In the previous example, we used an existing variable as a loop index. Since the C99 version of the C language, a much better (and safer) alternative has been introduced.

Pre-C99, we might write a loop as follows:

```C++
int i;

for (i = 0; i < 5; i++)
{
    printf("i = %d\n", i);
}
```

Since C99, it is preferred if the variable is declared as part of the loop as follows:

```C++
for (int i = 0; i < 5; i++)
{
    printf("i = %d\n", i);
}
```

| TASK | 207-looping-N-times (continued) |
| - | - |
| 5 | [Watch this video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=b8f5d62a-2d92-4266-9218-b09001008d4e) to see how to use C99 loops and why |
|  6 |  Change all the loops in the code to use this style (as shown in the video) |
| - | - |


## Break and Continue

Sometimes there is a need for finer control over how loops execute, for this we have the statements `break` and `continue`. They can be used in do-while loops, while loops and for loops.

> `break` is used to leave the current loop early. It is said to "break out" of the loop.
> 
> `continue` skips the remaining code in the code block, and re-evaluates whether to re-enter the loop

To use this, we also meet the keyword `if` (which will be covered more formally in the next lab) 

> STOP
> 
> I AM HERE - DO NOT WORK BEYOND THIS POINT
> 
> STOP



| Task | Details |
| :--- | :--- |
|  1 | Replace the code within main() with the following:

```C++
int main()
{
    for (int i = 0; i <= 10; i++)   // potentially loop from 1 to 10  
    {
        char c = getchar(); //Read character
        char _ = getchar(); //Read and discard newline
        if (c == 'q')          
        {
            printf("\tUser stopped the loop early at %d\n", i);
            break;                  // break out of the for loop
        }
        printf("Loop counter = %d\n", i);
    }
    puts("Done");
}
```
| Task | Details |
| :--- | :--- |
|  12 | Run the program and observe the results, try changing the value of the variable stopHere. The last line of the code is commented out because it causes a compiler error - why? The task now is to be able to tell wether the loop exited because it had finished it's 10 loops or because it hit the break statement. See if you can amend the program such that the printf() statement at the end can tell how the loop exited. Hint - you need access to the loop variable after it has finished counting - variable scope?

| Task | Details |
| :--- | :--- |
|  13 | The 'continue' statement allows us to control the loop execution in another way. Replace the code within main() with the following:

```C==
int missThis = 5;                                   // these variables could be set by another part of your application
int andMissThis = 7;

for (int i = 1; i <= 10; i++)                       // loop from 1 to 10  
{
    if (i == missThis || i == andMissThis)          // check loop counter (i) against the continue variables
    {                                               // using the 'or' (||) operator. 
    
        printf("\tLoop continue statement\n");
        continue;                                   // continue to the next iteration 
    }
    printf("Loop counter = %d\n", i);
}
// program execution from here when loop exits
```
| Task | Details |
| :--- | :--- |
|  14 | Run the program and observe the results, note that for the loop counter values 5 and 7 the printf() doesn't execute because the continue statement causes the loop to skip straight to the next iteration. The loop still does all 10 loops. Try changing the values of the two variables. Note the use of the 'logical or' operator in the if() statement.




## Nested loops

It is possible to put loop inside another - this is known as nested loops.

| Task | Details |
| :--- | :--- |
|  9 | Here is a simple example of nested loops. Change the code within main() to the following:

```C++
// Outer loop 
for (int i = 1; i <= 2; i++)        // Outer loop executes twice
{
    printf("Outer loop number %d\n", i);

    // Inner loop
    for (int j = 1; j <= 5; j++)    // Inner loop executes 5 times for each outer loop run so 10 time in total
    {
        printf("\tInner loop number %d\n", j);  // note the use of the tab (\t) option at the start to improve the layout
    }
}
```

| Task | Details |
| :--- | :--- |
|  10 | Run the code and observe the results, try changing the vaulues for the loop variable. Note we have set the initial values of i and j to 1, you can set them to whatever suits your application. Note also the use of the tab (\t) construct in the printf() function. This is the same as pressing the tab key.
|  11 | This task is to use nested loops to output the classic 'times table'
from early school days, the output should look like this:


![times table](image.png)



## Introduction to Arrays

There are many reasons why we use for-loops

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