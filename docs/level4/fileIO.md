# User Input and File IO

Reading and writing files is a very common task in computer science. In this lab, you will cover the basics of file input and output (IO). We will also look at some methods for extracting information stored within files, and some of the challenges as well.

Follow the instructions and perform all tasks in order. All tasks have starter code and solutions.

**Contents**

* [Streams](#streams)
   1. [Low Level Streams in C](#low-level-streams-in-c)
   1. [C++ Streams with `iostream`](#c-streams-with-iostream)
      1. [Writing with `ofstream`](#writing-with-ofstream)
      1. [Objects](#objects)
      1. [Reading with `ifstream`](#reading-with-ifstream)
      1. [Using Flags](#using-flags)
   1. [Parsing Files](#parsing-files)
      1. [Parsing - one word at a time](#parsing---one-word-at-a-time)
      1. [Reading one line at a time](#reading-one-line-at-a-time)
         1. [String Concatenation](#string-concatenation)
      1. [String Streams](#string-streams)
      1. [String Conversion](#string-conversion)
      1. [Exception Handling](#exception-handling)
      1. [Using find](#using-find)
      1. [Regular expressions (advanced)](#regular-expressions-advanced)
* [Challenges](#challenges)

## Streams

A stream is computing concept that turns up in many places, including file processing and network programming. Conceptually, a stream is a sequence of bytes are are either read from a data source, or sent to data destination (sometimes known as a data sink).

> You can think of a *stream* as a pipe down which you send data one byte at a time. The first to be written in is the first to be read out. We say it follows a "First In First Out" (FIFO) principle.

<figure>
<img src="./img/binarystream.jpg" width="600px">
<figcaption>Visualising a data stream as a pipe connecting a data source and destination</figcaption>
</figure>

The the source and destination could be:

* Terminal (keyboard input or text output)
* A File on a disk
* A block of memory
* A "network socket"
* Another connected device (e.g. audio playback or mouse)

The pipe itself also has some properties we need to be aware of:

* Data flow is typically one-direction 
* Data ordering follows a "First In First Out" (FIFO) pattern.
* The "pipe" itself usually has it's own storage capacity. 
  * It can hold data until the destination is ready to read it (known as **buffering**)
  * It has finite storage capacity (the pipe can get full)
  * Write operations will block in the event of a full pipe.
  * Read operations will typically block if the pipe is empty.

With this in mind, the following sections will introduce you to some of the most common uses of streams.

* User Input and Output (IO)
* File IO
* String processing

Note - Although these are different types of data source and destination, from the view of the computer, these will appear as virtual identical.

## Low Level Streams in C

We will begin with C streams as the workings are less hidden than the C++ equivalent. Going forward, we will use C++ of course.

| Task | 01-LowLevelIO |
| - | - | 
| 1. | Open the solution `FileIO` in Visual Studio |
| 2. | Make `01-LowLevelIO` the start up project |
| 3. | Step through the code with a debugger, and read the comments |
| 4. | [Watch this video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=86b895f8-de6e-4822-92f7-b0a500db567a) |
| 5. | Note the commentary below |

**Key Points:**

We've been using streams all along! There are two streams that are already open:

* `stdin` which is the default stream for read when you use the standard input functions, such as `scanf()` and `getchar()`
* `stdout` which is the default stream for write when you use the standard output functions, such as `puts()`, `printf()` and `putchar()`.

The declarations for all these functions (and type `FILE`) are all in the header file `stdio.h`. That is why it is included at the top of almost every C program.

We saw how the following were identical:

```C++
printf("Hello");
fprintf(stdout, "Hello");
```

Equally, the following are identical:

```C++
int a;
scanf_s("%d", &a);
fscanf_s(stdin, "%d", &a);
```

The filetype for a stream is a structure named `FILE`. We usually work with a pointer (address) to a stream (type `FILE*`). 

> I know pointers are confusing. Don't worry about this as we won't be working with FILE* for much longer

The stream `stdout` is already created for us, and by default, it pointed to the terminal output. However, when writing to a *file*, we need a new stream with a file as it's destination. To obtain such a stream, we can use the standard function `fopen_s`, specifying the file path and mode:

```C++
FILE* outputStream;
fopen_s(&outputStream, "lowlevel_io.txt", "wt"); //"wt" refers to write text
```
This will prompt the operating system to create/overwrite a file "lowlevel_io.txt" and open it in write mode. If this succeeds, `outputStream` will be a pointer to a structure of type `FILE`. If it fails, it will simply be zero (`nullptr`):

```C++
if (outputStream == nullptr) {
    puts("Could not open that file for write");
    return -1;
}
```

Once we have the stream, we can write to it just as before:

```C++
fprintf(outputStream, "12345\n");
```

This writes data to the stream buffer, which in turn will get written into a file on your computer filing system. Once we are finished writing to the file, we must remember to close it. This ensures all the data in the stream buffer is written (known as *flushed*).

```C++
fclose(outputStream);           
```

Reading is very similar. First we once obtain a stream by "opening" a file, only this time in read mode:

```C++
FILE* inputStream;
fopen_s(&inputStream, "lowlevel_io.txt", "rt");
```

Again, we check that this has been successful:

```C++
if (inputStream == nullptr) {
    puts("Could not open that file for read");
    return -1;
}
```

If successful, we can now read the stream (and hence the contents of the file):

```C++
int number;
fscanf_s(inputStream, "%d", &number);
```

As with `scanf` (where the input stream is `stdin`), the string value is read as a string, converted to an integer and written into the variable `number`. Once you have finished reading, you should close the file:

```C++
fclose(inputStream);
```

The syntax of C streams can be a bit off-putting. The good news is that C++ has a much more tidy system for doing the same thing. Being an object orientated language, it is able to hide many of the details.

## C++ Streams with `iostream`

We have already encountered streams in C++. Every time we use `cout` or `cin`, we are using the stream `stdout` and `stdin`.

> Both `cout` and `cin` are declared in the header file `iostream`. This is why this file is included in almost every C++ program you see

### Writing with `ofstream`

| Task | 02-OpenForWrite |
| - | - |
| 1. | Make 02-OpenForWrite the start up project |
| 2. | Step through the code and read the comments |
| 3. | Using the file explorer, file the file "myfile.txt" and inspect it's contents |

**Key Points:**

To open a file to write, we use the data type `ofstream` (short for *output file stream*) and the `open` function as follows:

```C++
ofstream outputStream;
outputStream.open("myfile.txt");
```

> There is no mode to say if we are writing or reading. `ofstream` is only used for writing.

Again, we check to see if this worked. In order to hide away the underlying stream, a function `is_open()` is provided:

```C++
//Check to see if it worked
if (outputStream.is_open() == false) {
    cerr << "Cannot create the file" << endl;
    return -1;
}
```

|  |  |
| - | - |
| 4. | <a title="It contains the declaration for `ofstream`">Why do you think we also include the header file `fstream`?</a> |
| | |

> **Additional**
>
> Note how I've used `cerr` instead of `cout`? This uses another pre-existing stream called `stderr`. This is used for error messages, and separates them from application output.
>
> It is possible to redirect `cerr` so the user does not see it. This won't be done in this lab, but be aware this is possible

Now we write to the file just like using `cout`:

```C++
//Write a string to the file
outputStream << "12345" << endl;
outputStream << "-----";
```

Finally, when we have finished writing, we must remember to close the file:

```C++
//Close
outputStream.close();
```

### Objects

Did you notice how the "dot notation" was used in the code above? This is because we are using a special type of variable known as an **object**. For example:

```C++
ofstream outputStream; //Object
```

We did something similar in the previous lab, when we created new data types using **structures**.

```C++
struct Point {
    int x;
    int y;
};

Point dot;
dot.x = dot.y;  //Modify the member x
dot.y = 0;      //Modify the member y
```

Structure types have *members* (`x` and `y` in this case) that we can read and write. 

`ofstream` is also a custom type, and will have members as well (some of them hidden). This will include data relating to the underlying file stream etc.. 

> Unlike a C structure however, it also contains *member functions* which operate on its member data. One example is shown below: 

```C++
outputStream.open("myfile.txt");
```

The *member function* `open` performs all the tasks to create a stream for writing to the file "myfile.txt". The details are hidden from you. You just use it!

> `outputStream` is a **class type**. C++ classes are similar to structures, but are much more powerful, and are the topic of the next lab.

When you create a variable with a custom data type like this, we often call it an **object**. It is part of **object orientated programming**.

|  |  |
| - | - |
| 5. | <a title="`is_open()` and `close()`">Identify two other member functions used in this code</a> |
| | |

Now we write to the file using a familiar syntax:

```C++
//Write a string to the file
outputStream << "12345" << endl;
outputStream << "-----" << endl;
```

> This will probably remind you of the `cout` syntax?

Finally, we close the file

```C++
//Close
outputStream.close();
```

The syntax might seem a little strange, including the use of the `<<` operator. Later in the course, we will meet a nice feature of C++ (and other languages) known as *operator overloading*, where you will learn to create your own objects that behave in a similar way.

### Reading with `ifstream`

Let's now read the data from our newly created file and display it in the terminal

| Task | 02-OpenForRead |
| - | - |
| 1. | Make 03-OpenForRead the start up project |
| 2. | Build and run the code. <a title="There is no file myfile.txt in the folder">Why does it display an error?</a> |
| 3. | Correct the error by copying `myfile.txt` from the `02-OpenForWrite` project into the `02-OpenForRead` project |
| 4. | Build and run again to confirm the file is read and displayed |

File reading is a little more complex. If the file does not exist, an attempt to open it will fail. Furthermore, you need to know if you reach the end of the file.

**Key Points**

First we create an object of type `ifstream`. Whereas `ofstream` is used for output (writing), `ifstream` is used for input (reading).

```C++
string fn = "myfile.txt";
ifstream inputStream
```

Then we open and check as before:

```C++
inputStream.open(fn);
if (!inputStream.is_open()) {
    cerr << "Cannot open file " << fn << endl;
    return -1;
}
```

Note again how we are using *member functions* to both open and confirm. Next we read the data:

```C++
string nextWord;
inputStream >> nextWord;
while (inputStream.eof() == false) {
    cout << nextWord << endl;
    inputStream >> nextWord;
}
```

|  | |
| - | - |
| 5. | Step through the code. <a title="Two words. The final read fails to read any new data as the end of file is detected">How many reads are performed?</a> |
| | |

Similar to `cin`, we read using the `>>` operator. Each time we do this, we then check for an end of file using the `eof()` member function. This continues until the end of the file is reached.

The final read will fail to read any data. This also flags that the end of the file has been reached. Only then will the `eof()` function return a `true`.

| Task | 04-TimesTables |
| - | - |
| 1. | Make 04-TimesTables the start up project. Build and run |
| 2. | Currently all output is sent to the terminal. Change the code so all output is instead written into the file `tables.txt` |
| - | A solution is provided |
| - | *hint* - you need to replace `cout` with a different object of type `ofstream`. |
| | |

```C++
int main()
{
	for (unsigned int r = 2; r <= 12; r++) {
		for (unsigned int c = 2; c <= 12; c++) {
			cout << r * c << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
```

### Using Flags

In the task [writing with ofstream](#writing-with-ofstream), the file was recreated every time, overwriting the existing file if present. This is the default behavior. Sometimes we wish to modify the behavior, such as appending to the end of an existing file.

For this, we can use special *flags* to modify file IO.

| Experiment | 05-AppendingFiles |
| - | - |
| 1. | Make 05-AppendingFiles the start up project. |
| 2. | Build and run the code. Confirm it has created a file called `myfile.txt` |
| 3. | Inspect the contents of `myfile.txt` |
| 4. | Change the module code from `1000` to `2000` | 
| 5. | Re-run the code again. What happened to the file? |
| 6. | Now comment out the line that reads: `outputStream.open("myfile.txt");` |
| 7. | Uncomment the line that reads: `outputStream.open("myfile.txt", ios::app);` |
| 8. | Re-run the experiment and note the change in behaviour |

**Key Points**

* The default behaviour of `open()` is to delete any existing content and re-write the file.
* We can change this behaviour by specifying an addition flag parameter. In this case, we used `ios::app` so the file would be appended.

For your reference, a table of flags have been included:

| Mode | Description |
| :--- | :--- |
|  ios::in| Open file for input (default mode for ifstream)
|  ios::out| Open file for output (default mode for ofstream)
|  ios::binary| Open file in binary mode 
|  ios::ate| Set initial file position at the end, if not set the initial file position is the start
|  ios::app| All output is appended to the end of the file
|  ios::trunc| If file is opened for output and already exists it's content is deleted before writing new data

You can combine these flags with the **or** operator `|`

```C++
outputStream.open("myfile.txt", ios::app | ios:binary );
```
## Parsing Files

Very often, we want to extract a particular piece of information from a file. We may also want to convert it from a string into a number. The expression *parsing data* includes reading structured string data and extracting relevant information for further processing.

This is an important topic, so we will do some basic file parsing in the following sections. In most these sections, we start with the following file contents:

```
Hello COMP1000
--------------
Subject Area: COMP
Module ID: 1000
```

The structure is described as follows:
* Text before the underline are just comments 
* Then you will find the term `Subject Area:` followed by the subject area code (string)
* Then you will find the term `Module ID:` followed by the module code (integer)

We wish to extract both the subject area string and module ID, and use this to create a new module string ("COMP1001").

### Parsing - one word at a time

With this method, we will read one string at a time:

| Task | 07-SimpleParsing |
| - | - |
| 1. | Make 07-SimpleParsing the start up project |
| 2. | Build and run the code to see what it does. Read all comments |

So far, it reads each string at a time until it gets to the subject area (COMP).

|  |  |
| - | - |
| 3. | Continue reading strings until you find the module code ID. Read this into the integer `code` |
| 4. | Calculate a new module code which is one number higher and write to the terminal. The correct answer should be COMP1001 |
| - | A solution is provided |
| | |

**Key Points**

* This approach relied on knowing precisely how many words there were, and in what order.
* If the file format were to change slightly, this code might fail. We might say this is *fragile* 
* This demonstrated one of the methods for converting strings to integers

```C++
    int code;
    inputStream >> code;
```

The downside of this is that if it fails, it will do so *silently*. There are other more *robust* techniques that we will meet later.

### Reading one line at a time

So far, we have read files "one word at a time", where words are strings separated by white space or new lines. We actually throw away the spaces and new line characters in doing so.

Sometimes we want to read in each line, separating reads by just newline characters (`\n`). For this, we can use the `getline()` function.

| Task | 08-ReadingByLine |
| - | - |
| 1. | Make `06-getline` the startup project |
| 2. | Build and step through the code. Read the comments to try and understand it |
| 3. | <a title="Use the fail function `fail()` function">How do you know if you've successfully read a line?</a> |
| 4. | <a title="You add them with +">How do you join two strings together in C++?</a> |
| 5. | Now write a loop to read all lines from the file and append them to the `allLines` string. When the program completes, `allLines` should contain the complete contents of the file. |
| Hint | Look carefully at the `fail()` and `eof()` member functions. You might struggle with this task at first. |
| - | A solution is provided |

**Key Points**

In this task, we use the function `getline()` to read one line at a time, and store the result in one large string.

```C++
getline(inputStream, nextLine);
```
where `inputStream` is a stream we are reading, and `nextLine` is a string. As `nextLine` is modified by this function, we can probably assume it is *passed by reference* (although it is not obvious).

One of the complexities of reading files is that (unlike `cin`) a file stream will eventually reach the end of the file. 

> The end of every stream has an **End Of File** (EOF) marker. 
> 
> * When you read the last item in a stream, this *might* include the EOF character. If so, you can stop reading. 
> * If there is a space or newline after the last item, you will need to *try* and read another item in order to detect EOF marker
>
> Any attempt to read *beyond* the last item will silently fail (it will not crash) and will simply not modify the string. 

* To test if an item was successfully read, use the function `fail()`.
* To test if a stream has encountered the EOF marker, we use the function `eof()`

|  |  |
| - | - |
| 6. | Now build and run the solution. Step through the code and read all comments |
| | |

#### String Concatenation

We also saw how we can use the `+` operator to join strings together in C++. For example:

```C++
string s1 = "Hello";
string s2 = "World";
string s3 = s1 + " " + s2;
cout << s3;
```

This would display `Hello World` in the terminal. 

> How this works will be revealed when we write our own C++ class types and perform some *operator overloading*. 
>
> For now, we can enjoy the simplicity this brings!

### String Streams

So far we have met the following types of stream:

* `stdin` - read via `cin`, this defaults to the terminal input
* `stdout` - written via `cout`, this defaults to the terminal output
* `ifstream` - read only, where the source is a file
* `ofstream` - write only, where the destination is a file

We have more more for you!

* `istringstream` - read only, where the source is a string (of words separated by whitespace).

This is very useful for reading individual words from a longer string. Let's look at it now:

| Task | 09-StringStreams |
| - | - |
| 1. | Make `09-StringStreams` the start up project. Build and step through the code, reading all comments |
| 2. | Write a loop to read all words in the string, and count how many there are. |
| -  | Within your loop, write each word on a separate line. When you read the word "Always.", add an extra line break. |
| 3. | Display how many words were read |
| - | Again, make use of the `eof()` and `fail()` functions. A solution is provided |

The output should look like this:

```
May
the
force
be
with
you.
Always.

Ok,
maybe
that's
asking
too
much.
How
about
3
days-a-week
with
time
off
for
birthdays?
Total Number of Word: 22
```

**Key Points**

* This time, the stream was not a file, but another string. Despite this, it behaves in exactly the same way. We even use the "end of file" function `eof()`.
   * Whether working with a keyboard, file, network or some other device, most basic operations are identical if you can obtain a `stream` object.
   * `cout` and `cin` do not ever end, so `eof()` always returns `false`. You can call it however.

* We also saw how to compare a string with another.

```C++
if (nextWord == "May") {
    cout << "That is what I expected" << endl;
}
else {
    cout << "Something weird is happening?" << endl;
}
```
> This is *another* example of *operator overloading*. C++ strings can use the `==` operator to compare the *string contents*. This is different to testing if they are the same object.

### String Conversion

So far we have looked at ways of reading text data into a string, either one word at a time, or one line at a time. A common requirement is often to extract relevant data for further processing or storage. In the case of numerical data, this will require an attempt to "convert" a string to some numerical data type. To write robust code (that does not crash or return incorrect values silently), we also need to consider conditions where this is not possible.

> When we write software, we often need to be *defensive*. This means anticipating conditions where something might fail, and taking necessary actions if they do.
>
> This is a fundamental of good practice.

There are a number of string conversion functions available. Some of them are listed below

* `stoi()` - convert string to integer
* `stol()` - convert string to long
* `stof()` - convert string to float
* `stod()` - convert string to double

Consider the following code extract:

```C++
string strNum = "123";
int num = stoi(strNum);     //Attempt to convert a string to an integer
cout << num + 1 << endl;    //Write the result + 1
```

We will now use the `stoi()` function to construct a new module code. First we will find the string with the module number ("1000"). We will read this, convert it to an integer, add one, then display a new module code as "COMP1001"

| TASK | 10-StringConversion |
| - | - |
| 1. | Make 10-StringConversion the startup project |
| 2. | Build the code. Then step through each line, reading the comments |
| 3. | Complete the code to read the module code as a string (it is the next one), convert it to an integer with `stoi()`, add 1 to the result, and display a new module code. |
| - | See the comments for further guidance |
| - | The correct output should be COMP1001 |
| - | A solution is provided |

**Key Points**

* Note how some of the code is now moved out into functions?
  * This was done (in part) to keep the main function simple, so the reader can focus on the aspects that are important.
 * At this point, we are assuming the file format to be perfect and predictable

### Exception Handling

In the previous example, we performed a conversion from type `string` to type `int`. However, there is a potential problem here. What if the string cannot be converted to an integer? Maybe the file format changed and this was not accounted for in the software?

In this task, we will demonstrate just this:

| TASK | 11-ExceptionHandling |
| - | - |
| 1. | Make 11-ExceptionHandling the startup project |
| 2. | Build and run the code. Note that it crashes |
| 3. | Use the debugger to find WHERE the code crashes |
| - | <a title="moduleNumber = stoi(nextWord);">On what line does it crash?</a> |
| 4. | Use the debugger to find WHY it crashes |
| - | <a title="nextWord is not a number. It is a letter (Roman Numeral)">Why does it crash?</a> |
| 5 | Now inspect the `createFile()` function. Read through it and especially the comments. Can you see the problem? |

This might look a bit drastic, but it is helpful that the code has crashed so that you are alerted to the problem.

> The worst thing would be for this to fail silently. Code could get deployed to a customer with unpredictable consequences

However, all is not lost. We have another (powerful) method of detecting these errors so that they can be handled more *gracefully*. This is known as **exception handling**.

The writers of `stoi()` decided that in the event of a failure, it would **throw an exception**. 

> Exceptions are a special type of error that make it easier to communicate errors in software no matter how deeply hidden they may be. 

As we **try** to use the `stoi()` function in our code, so we are able to **catch** any errors and find out more details about them.

The concept works as follows:

* We "try" to execute some code that we know can/might fail either now, or sometime in the future (e.g. someone changes a file format!). 
   * If it does not crash, the code may continue
   * If it does crash, we get the opportunity to run another block of code, and handle the error in the way we deem suitable

For example:

```C++
try {
    // "try" this
    moduleNumber = stoi(nextWord);
    cout << moduleNumber + 1 << endl;
} 
catch (exception e)
{
    // If stoi() fails, then this code runs
    cerr << "That failed with error \"" << e.what() << "\"" << endl;
    return -1;
}
```


|   |   |
| - | - |
| 6 | Add try-catch blocks to the code to handle the error more gracefully. |
| - | A solution is provided |
| | |

**Key Points**

* try-catch is an advanced, but very important technique.
   * It is far from unique to C++. Almost every modern languages has a try-catch equivalent (most use very similar syntax)
* It is hoped that you were able to use the debugger to track down the line that crashed.
   * This is a **vital skill** that you are encouraged to practise during these labs AND when you attempt your coursework.
* Again, note how `cout` and `cerr` are both used. One is developer focused (to aid crash reporting and diagnostics) and the other is user focused (so they can report the bug).

### Using find

In this section, we introduce you to a couple other useful functions:

* `find()` - can search for a string within another string, returning the character position (if successful) or -1 if not successful.
* `substr()` - can be used to extract a smaller string from within another larger string

| TASK | 12-findAndSubstr |
| - | - |
| 1. | Make 12-findAndSubstr the start up project |
| 2. | Build and step through the code. Read all comments |
| 3. | Note how the substring "ID:" is located |
| 4. | Now add more code to find "Area:" and the string that follows (the subject group) |
| 5. | Display the result in the terminal |
| - | A solution is provided |

**Key Points**

* Note the two forms of `substr()`

```C++
string previous = dataString.substr(a, b);    //from a ... (b-1)
string following = dataString.substr(b);      //From b... end
```
With two parameters, it returns a string in the range to `a...b-1`.
 With one parameter, it returns a string in the range `b...N`, where `N` is the position of the last character in the string.

* Note also that each search used a separate instance of `istringstream`. This is safer than trying to reuse the same one (the documentation was vague!)
* This method is somewhat more robust than before, and much better than simply counting words. It is more tolerant to the file format changing. 

### Regular expressions (advanced)

You may have noticed that the code in the previous sections was getting longer, especially with all the error checking. 

> String parsing can get very tedious and can become error prone.

A response to this is something known as "regular expressions". These are a way to specify a way to find and extract certain patterns found in string data.

Some examples have been included in the following experiment:

| Experiment | 13-regex |
| - | - |
| 1. | Make 13-regex the start up project |
| 2. | Step through the code and read the comments |
| 3. | Can you add more code to extract the Subject Area name? |
| - | The extracted string should read "COMP" |
| - | The pattern should be the following sequence: |
| (i) | Any number of spaces |
| (ii) | The word Subject |
| (iii) | Any number of spaces |
| (iv) | The work Area: |
| (v) | Any number of spaces |
| (vi) | A word (use \\w*) |
| (vii) | At least one space after |
| Solution | Read the discussion below. A solution is also provided |
| | |

Here is a key extract from this task:

```C++
    regex  pattern("Module\\s*(ID):\\s*(\\d+)");
    smatch match;
    string tag;
    string strCode;
    int code;

    //look for the pair "ID:" and <module number>
    if (regex_search(dataString, match, pattern)) {
        cout << "Full Match:" << match[0] << endl;
        if (match.size() >= 3) {
            tag = match[1];
            strCode = match[2];
            cout << "Pair found: (" << tag << ", " << strCode << ")" << endl;
```

The function `regex_search()` takes three parameters:

* The string being searched
* A special type `smatch` which presents as an array of matched substrings (more C++ cleverness)
* A search pattern of type `regex`

The tricky part is getting the search pattern right. This is a VERY big topic, but some basics are presented here. Our pattern is as follows:

`Module\\s*(ID):\\s*(\\d+)`

This can be interpreted as: 

* The literal string "Module", 
* followed by any number of spaces \\s* (including zero spaces), 
* followed by the string "ID:", 
* followed by *any* number of spaces `\\s*`, 
* followed by *at least one* digit `\\d+`

The parenthesis `()` capture the components of the search we wish to extract in `match`. In this case, we expect to capture "ID" and "1000"

> Note - normally, regular expressions use a single \\. For C++, you use two \\\

**Key Points**

* It should be stressed - this is an ADVANCED task. At this stage, it is probably useful to know regular expressions exist and have an idea of what they are. It would be ambitious to use them at this stage.
   * If you are interested, do experiment with https://regex101.com/
* Nearly every language has a regular expression library you can use. At some point you might want to take some time to experiment with them. They can save a LOT of code. 

# Challenges

Challenges are for self-study only. Solutions are not usually provided. They are intended to encourage you to explore new ideas. By all means use AI tools to help you .  

| Challenge 1 - File Copy |
| - | 
| Can you write a program to read a file and write the same contents into another |
| This will (in effect) perform a file copy |
| This is one example where the C function `getchar()` makes things simpler |

| Challenge 2 - Web Scraping |
| - |
| In the folder for challenge 2 is a file `Fake Python.html` (source: https://realpython.com/beautiful-soup-web-scraper-python/) |
| Read this file and extract the location using the attribute id="location" |
| The correct answer is "Stewartbury" |

| Challenge 3 - Web Scraping with regex (advanced) |
| - |
| Use regex to extract the location. Try and make it as robust as you can |
| Even with this, note how *fragile* the solution can be |

---

[Back to Table of Contents](./README.md)

