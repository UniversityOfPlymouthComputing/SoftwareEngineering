# Flow Control

We need a way to control the 'flow of execution' of our programs. 

## If .. else

Deciding how to control the program flow is based on a 'condition' being true. A few examples using the comparison operators:

| Condition | Value |
| :--- | :--- |
| a < b  | true if a is less than b |
| a <= b | true if a is less than or equal to b    |
| a > b  | true if a is greater than b    |
| a >= b | true if a is greater than or equal to b    |
| a == b | true if a is equal to b    |
| a != b | true if a is not equal to b    |

The if() statement is written like this:

```C++
if (condition is true)
{
  // execute these statements
}
```

| Task | Details |
| :--- | :--- |
|  1 | As in previous labs - create a new project, call it 'flowcontrol' or similar and make sure you set it as the Startup Project. Delete the comments and replace the code within main() with the following: 

```C++
int high = 100, level = 25, low = 10;

// start filling the tank 

level = 5;

if (level <= low)                       // check the level
{
    printf("Tank needs filling\n\n");
}

level = 25;

if (level > low)                       // monitor the level
{
    printf("That's better\n\n");
}

level = 100;

if (level == high)                       // monitor the level
{
    printf("Tank is full\n");
}

```

| Task | Details |
| :--- | :--- |
|  2 | Run the program and observe the results, try changing the values and use the other comparison operators until you understand how they all work.

| Task | Details |
| :--- | :--- |
|  3 | Now lets explore some other ways to use if and else. Replace the code within main() with the following:

```C++
int high = 100, level = 25, low = 10;

if (level == high)                          // This is the condition
{
    printf("The tank is full\n\n");         // If the condition is true 
}
else
{
    printf("The tank needs a top up\n\n");  // If the condition is false
}

```

| Task | Details |
| :--- | :--- |
|  4 | Run the program and observe the results, change the value of the variable 'level' to demonstrate the condition both true and false. Using the 'else' statement adds the option to take action when the condition is false. The final construct is the 'else if' which allows for more than two options. The syntax for the 'else - if' statement is like this:

```C++
if (condition1)
{
  // execute this code if condition1 is true
}
else if (condition2)
{
  // execute this code if condition1 is false and condition2 is true
}
else
{
  // execute this code if condition1 is false and condition2 is false
}
```

Note you can have more than one else if but it can soon get hard to read

| Task | Details |
| :--- | :--- |
|  5 |Replace the code within main() with the following:

```C++
int time = 22;

if (time < 10)                          // This is the condition
{
    printf("It is too early\n\n");         // If the condition is true 
}
else if (time < 18)
{
    printf("It is still daytime\n\n");  // If the condition is false
}
else
{
    printf("It is late\n");
}
```

| Task | Details |
| :--- | :--- |
|  6 | Run the program and change the vale of the variable 'time' to see how the else - if construct works. Whist the example above works and can be extended to more complex decisions there is a better way....

## Switch statement

The switch statement is a much better way (than else - if) to select one of many code blocks to executed. The syntax is as below:

```C++
switch (expression)
{
  case a:
    // code block to execute if expression is equal to a
    break;
  case b: c:
    // code block to execute if expression is equal to b or c
    break;
  case d:
    // code block to execute if expression is equal to d
    break;
  default:
    // code block to execute if expression none of the above
}

```

| Task | Details |
| :--- | :--- |
|  7 | Replace the code within main() with the following:

```C++
 switch (option)
 {
 case 'a':
     // code block to execute if 'option' is equal to a
     printf("Option is a\n");
     break;
 case 'b':
 case 'c':
     // code block to execute if 'option' is equal to b or c
     printf("Option is b or c\n");
     break;
 case 'd':
     // code block to execute if 'option' is equal to d
     printf("Option is d\n");
     break;
 default:
     // code block to execute if 'option' is none of the above
     printf("Option is unknown\n");
 }
```

| Task | Details |
| :--- | :--- |
|  8 | Run the program, change the value of variable 'option' and see what happens. First thing to note is the presence of the break statement after each option (or group of options), missing the break statement is a common mistake. Also note (as in the case of b and c above) that you can have more than one option grouped together executing the same code block. Finally notice the default option at the end, this has it's own code block which executes if no option is correct.
