# More Inputs

This is the follow-on from the getchar() exercise

## Introduction

The C language does not have a string type, instead strings are created using an array of characters of type char. 

So we start a quick introduction to arrays - they will be covered in more detail in a later lab.

| Task | Details |
| :--- | :---    |
| 1    | As in previous labs create a new project and give it a name "Inputs" or similar. Within main replace the code with the following:
```C++
char monty[] = "sandal";
printf("The string %s has %zd characters\n\n", monty, sizeof(monty));
``` 
| Task | Details |
| :--- | :---    |
|  2   | The code above statements create an array containing characters of type char, the array has the name 'monty'. We then use printf() to output the string to the terminal. Note the '%s' which tells printf() to output a string. Additionally we output the size of the string. Run the program and observe the results. The string named 'monty' has 6 characters so why does the sizeof function give the result 7? The answer is that the compiler adds a null character ('\0' - backslash zero) as the last  character in the array to show where the string ends.  There are lots of ways to manipulate the array which will be covered later .For now lets find out how to allow the user to enter a new string.

| Task | Details |
| :--- | :---    |
|  3   | Add the following lines to your program:
```C++
char buffer[10];
printf("Please enter your first name: \n");
gets_s(buffer, 10);
printf("Hello %s", buffer);
```
| Task | Details |
| :--- | :---    |
|  3   | Note - for those of you with previous programming experience get_s() replaces gets() in the latest versions of C/C++. The code you have just added prints out a prompt on the terminal and allows the user to enter a series of characters followed by the enter key. The string is saved in the array buffer[] and printed out. Note that you need to specify the size of the array in advance. The call to gets_s() specifies not only the array but how many character to read, it will read one less than the number given to allow for the null character at the end. Run the program and see what happens if you enter a name longer than 9 characters.

| Task | Details |
| :--- | :---    |
|  4   | There is however a better way for the user to enter data into your program. Add the following lines to your program:
```C++
int num = 0;

printf("\nPlease enter a number\n");
scanf_s("%d", &num);
printf("\nYou entered the number %d", num);
```
| Task | Details |
| :--- | :---    |
|  5   | The code you have just added defines an integer variable (num) and use the function scanf_s() to read the user input and store it in that variable. The first parameter ("%d") tells scanf_s() to interpret the input as an integer, the second parameter &num uses the '&' operator to provide the address in memory of the variable 'num'. Note - for those of you with previous programming the scanf_s() function is a 'safe' replacement for scanf() in the new C/C++ standard. Run the program and observe the results, what happens if you enter a character that is not a number?

| Task | Details |
| :--- | :---    |
|  6   | The scanf_s() function has a return value which indicates wether the process was successful and if so how many variable were assigned a value, lets make use of this information. Add the following lines to your program:
```C++
int ret = 0;

printf("\nPlease enter a number\n");
ret = scanf_s("%d", &num);
printf("\nYou entered the number %d, return value is %d\n", num, ret);
```
| Task | Details |
| :--- | :---    |
|  7   | Run the program and observe the results, again what happens if you enter non-numeric values? The return value can be used to test for how successful the call to scanf_s() was. We will come on to this in a future lab. First lets record other types of data. Add the following code to your program, again notice the use of the '& operator to pass the address of the variables.
```C++
char ch;
    char newName[30];
    float creditFloat = 0.0;
    double debitDouble = 0.0;

    // This time we are asking for four items, a single character, a string and two numbers 
   
    printf("Please enter a single character\n");
    ret = scanf_s("%c", &ch, 1);
    printf("You entered %c ret = %d\n", ch, ret);

    printf("Please enter a string\n");
    ret = scanf_s("%s", newName, 29);
    printf("You entered %s ret = %d\n", newName, ret);

    printf("Please enter a number\n");
    ret = scanf_s("%f", &creditFloat);
    printf("You entered %f ret = %d\n", creditFloat, ret);

    printf("Please enter a number\n");
    ret = scanf_s("%lf", &debitDouble);
    printf("You entered %lf ret = %d\n", debitDouble, ret);
```

| Task | Details |
| :--- | :---    |
|  8   | Run the program and observe the results, try different values for each variable including ones you think might not be valid. Note - when using scanf_s to assign a value to a string (newName) the '&' operator isn't needed - this is because the name of the array is the address (in memory) of the first value in the array - weird really but there it is.



