# User Input and File IO

**Contents**

* [Streams](#streams)
   1. [Low Level Streams in C](#low-level-streams-in-c)
   1. [C++ Streams with `iostream`]
* [File IO in C++]
   1. [File Streams with `fstream`]
   1. Appending Files with Flags
   1. [Basic File Parsing]
   1. [String Parsing]
   1. [String Streams with `sstream`]
   1. [Regular Expressions]
* [Challenges]

## Streams

A stream is computing concept that turns up in many places, including file processing and network programming. Conceptually, a stream is a sequence of bytes are are either read from a data source, or sent to data destination (sometimes known as a data sink).

> You can think of a *stream* as a pipe down which you send data one byte at a time. The first to be written in is the first to be read out.

<figure>
<img src="./img/binarystream.jpg" width="600px">
<figcaption>Visualising a data stream as a pipe connecting a data source and destination</figcaption>
</figure>

The the source and destination could be:

* Terminal (keyboard or output)
* File on a disk
* A block of memory
* A "network socket"
* A device connected (e.g. audio playback or mouse)

The pipe itself also has some properties to be aware of:

* Data flow is typically one-direction 
* Data ordering follows a "First In First Out" (FIFO) pattern.
* The "pipe" itself usually has it's own storage capacity. 
  * It can hold data until the destination is ready to read it (known as **buffering**)
  * It has finite storage capacity (the pipe can get full)
  * Write operations will block in the event of a full pipe.
  * Read operations will typically block if the pipe is empty.

With this in mind, the following sections will introduce you to two of the most common uses of streams.

* User Input and Output (IO)
* File IO

Remember - both are conceptually the same. What differs are the types of data source and destination.

## Low Level Streams in C

We will use C streams as the workings are less hidden than the C++ equivalent. Going forward, we will use C++ of course.

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
* The declarations for all these functions (and type `FILE`) are all in the header file `stdio.h`. That is why it is included at the top of almost every C program.

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

The stream `stdout` is already created for us. However, when writing to a file, we need a new stream with a file as it's destination. To obtain such a stream, we can use the standard function `fopen_s`, specifying the file path and mode:

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

If successful, we can now ready the stream (and hence the contents of the file):

```C++
int number;
fscanf_s(inputStream, "%d", &number);
```

As with `scanf` (where the input stream is `stdin`), the string value is read as a string, converted to an integer and written into the variable `number`. Once you have finished reading, you should close the file:

```C++
fclose(inputStream);
```

The syntax of C streams can be a bit off-putting. The good news is that C++ has a much more tidy system for doing the same thing.

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

To open a file to write, we use the data type `ofstream` and the `open` function as follows:

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

> Additional
>
> Note how I've used `cerr` instead of `cout`? This uses another pre-existing stream called `stderr`. This is used for error messages, and separates them from application output.

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

Did you notice how the "dot notation" was used in the code above? For example:

```C++
ofstream outputStream;
```

In the previous lab, we created new data types using **structures**.

```C++
struct Point {
    int x;
    int y;
};

Point dot;
dot.x = dot.y;  //Modify the member x
dot.y = 0;      //Modify the member y
```

Structure types have members (`x` and `y` in this case) that we can read and write. 

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

### Reading with `ifstream`

Let's now read the data from out newly created file and display it in the terminal

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
| 5. | Step through the code. <a title="Two words. The final read fails as the end of file is detected">How many reads are performed?</a> |
| | |

Similar to `cin`, we read using the `>>` operators. Each time we do this, we then check for an end of file using the `eof()` member function. This continues until the end of the file is reached.

The final read will fail to read any data. This is what flags that the end of the file has been reached. Only then will the `eof()` function return a `true`.

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

In the task [writing with ofstream](#writing-with-ofstream), the file was recreated every time. This is the default behavior. Sometimes we wish to modify the behavior, such as appending to the end of an existing file.

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
| 8. | Rerun the experiment and note the change in behaviour |

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

### Reading one line at a time

So far, we have read files "one word at a time", where words are strings separated by white space or new lines

# DO NOT READ BEYOND THIS POINT

## Fundamentals of Functions

In C++ writing to and reading from files is handled by the 'fstream' library in a very similar way to the way you have used 'cin' and 'cout'. By that we mean it handles the data as a stream and uses the '<<' and '>>' operators to control the flow.

By way of a refresher this short program accepts a user name and outputs a greeting.

```C++
#include <iostream>

using namespace std;

int main()
{
    string fname;

    cout << "Please enter your first name: ";                    // Prompt for user input
    cin >> fname;                                                // Accept user input 
    cout << "Hi " << fname << " welcome to the lab on file IO";  // Display the input  
}

```

Now lets add some file output, the 'fstream' library has 3 classes to create the file and read/write the data they areas follows:

| Class | Function |
| :--- | :--- |
|  ofstream| Create file and write data
|  ifstream| Read data
|  fstream| Create file and read/write data (a combination of the first two classes)

Compile and run the program below, from within Visual Studio 'File' right click on your project name and select 'Open Folder in File Explorer' - you should see a file 'names.txt' - you can open this in any text editor - it is currently empty.

```C++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fname;

    cout << "Please enter your first name: ";                    // Prompt for user input
    cin >> fname;                                                // Accept user input 
    cout << "Hi " << fname << " welcome to the lab on file IO";  // Display the input  

    ofstream outFile;           // Create the output stream called 'outFile'
    outFile.open("names.txt");  // Using this stream create and open a file called 'names.txt'
    outFile.close();            // Close the file - easy to forget this, if so file corruption is possible
}
```

Now before writing to the file lets add a bit of error checking:

```C++

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fname;

    cout << "Please enter your first name: ";                    // Prompt for user input
    cin >> fname;                                                // Accept user input 
    cout << "Hi " << fname << " welcome to the lab on file IO";  // Display the input  

    ofstream outFile;           // Create the output stream called 'outFile'
    outFile.open("names.txt");  // Using this stream create and open a file called 'names.txt'

    if (outFile.is_open())      // check to see if the file has been opened
    {
        outFile.close();        // Close the file - easy to forget this
    }
    else
    {
        cout << "Unable to open file names.txt";    // Inform user of file error
    }
    return 0;
}
    
```

If you now look at the folder where names.txt was created (you may need to refresh the output) you will see by the timestamp that the file was overwritten (but still empty). Now we are more confident that the file is open lets write some data.

```C++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fname;

    cout << "Please enter your first name: ";                    // Prompt for user input
    cin >> fname;                                                // Accept user input 
    cout << "Hi " << fname << " welcome to the lab on file IO";  // Display the input  

    ofstream outFile;           // Create the output stream called 'outFile'
    outFile.open("names.txt");  // Using this stream create and open a file called 'names.txt'

    if (outFile.is_open())      // check to see if the file has been opened
    {
        outFile << "This is line one";      // Three lines of data
        outFile << "Line two";
        outFile << "User is " << fname;

        outFile.close();        // Close the file - easy to forget this, if so file corruption is possible
    }
    else
    {
        cout << "Unable to open file names.txt";    // Inform user of file error
    }
    return 0;
}

```

If you open the file names.txt you should see this:

This is line oneLine twoUser is fred

The three lines of text have been added on the same line, this may be what you wanted, if however you wanted each on it's own line then we can amend the way data is written in the same way we use 'cout' - see below:

```C++

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fname;

    cout << "Please enter your first name: ";                    // Prompt for user input
    cin >> fname;                                                // Accept user input 
    cout << "Hi " << fname << " welcome to the lab on file IO";  // Display the input  

    ofstream outFile;           // Create the output stream called 'outFile'
    outFile.open("names.txt");  // Using this stream create and open a file called 'names.txt'

    if (outFile.is_open())      // check to see if the file has been opened
    {
        outFile << "This is line one\n";              // Line one with new line added
        outFile << "Line two" << endl;                // Line two with new line added
        outFile << "User is " << fname;

        outFile.close();        // Close the file - easy to forget this, if so file corruption is possible
    }
    else
    {
        cout << "Unable to open file names.txt";    // Inform user of file error
    }
    return 0;
}
    
```

You should now find the file contains three lines of data. Like this:

This is line one  
Line two  
User is fred

When the file is opened there are various options (called modes) which can be set as follows:

| Mode | Description |
| :--- | :--- |
|  ios::in| Open file for input (default mode for ifstream)
|  ios::out| Open file for output (default mode for ofstream)
|  ios::binary| Open file in binary mode 
|  ios::ate| Set initial file position at the end, if not set the initial file position is the start
|  ios::app| All output is appended to the end of the file
|  ios::trunc| If file is opened for output and already exists it's content is deleted before writing new data

Text files (non binary) may have some translations applied by special characters (e.g. newline) whereas binary files are written without any formatting.

This time lets open the same file and add another line.

```C++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fname;

    cout << "Please enter your first name: ";                    // Prompt for user input
    cin >> fname;                                                // Accept user input 
    cout << "Hi " << fname << " welcome to the lab on file IO";  // Display the input  

    ofstream outFile;           // Create the output stream called 'outFile'
    outFile.open("names.txt", ios::app);  // Using this stream open the file called 'names.txt in append mode'

    if (outFile.is_open())      // check to see if the file has been opened
    {
        outFile << "\nAppended line\n";              // Line appended

        outFile.close();        // Close the file - easy to forget this, if so file corruption is possible
    }
    else
    {
        cout << "Unable to open file names.txt";    // Inform user of file error
    }
    return 0;
}

```
The file contents should now look like this:

This is line one  
Line two  
User is fred  
Appended line

if you want to combine file modes then use this syntax:

outFile.open("names.txt", ios::app | ios:binary)

This uses the '|' or operator to combine the modes.

| Task | Details |
| :--- | :--- |
|  1 | Adapt the code above to create a text file, (name the file test.txt) open it for writing and use a for loop to accept 5 words from the user and write each word to the file on a new line - add at the beginning of each line the number of the counter you are using within the for loop. This number should count from 1 to 5. So the file contents should start something like this:

1 : The    
2 : Life    
3 : of  
4 : Brian  
5 : *****

Remember to check the file has opened and don't forget to close it after use.

Keep this file we will be using it soon...

------>>>> Solution here <<<<<---------

```C++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string inputstr;

    ofstream outFile;           // Create the output stream called 'outFile'
    outFile.open("test.txt");  // Using this stream open the file called 'test.txt'

    if (outFile.is_open())      // check to see if the file has been opened
    {
        for (int i = 1; i <= 5; i++)
        {
            cout << "Please enter line " << i << endl;
            cin >> inputstr;
            outFile << i << " : " << inputstr << endl;
        }

        outFile.close();        // Close the file - easy to forget this, if so file corruption is possible
    }
    else
    {
        cout << "Unable to open file test.txt";    // Inform user of file error
    }
    return 0;
}
 

```


Now we have a file with some data in it we can explore how to read some of that data. Initially we will just open the file and check to see if this is successful.

```C++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string inputstr;

    ifstream inFile;           // Create the input stream called 'inFile'
    inFile.open("test.txt");   // Using this stream open the file called 'test.txt'

    if (inFile.is_open())      // check to see if the file has been opened
    {
        cout << "File test.txt has been opened\n";
        inFile.close();        // Close the file
    }
    else
    {
        cout << "Unable to open file test.txt";    // Inform user of file error
    }
    return 0;
}
```    

Note that we are using 'ifstream' rather than 'fstream' - both can be used for reading but if the program does not need to write then it's safer to use 'ifstream'. The call to getline() returns false when we get to the end of the file.

```C++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string inputstr;
    int linecounter = 0;

    ifstream inFile;           // Create the input stream called 'inFile'
    inFile.open("test.txt");   // Using this stream open the file called 'test.txt'

    if (inFile.is_open())      // check to see if the file has been opened
    {
        cout << "File test.txt has been opened\n";
        while (getline(inFile, inputstr))
        {
            cout << inputstr << endl;
        }
        inFile.close();        // Close the file
    }
    else
    {
        cout << "Unable to open file test.txt";    // Inform user of file error
    }
    return 0;
}
```
| Task | Details |
| :--- | :--- |
|  2 | Adapt the code above to add a counter that records the number of lines read, print out this count once the file is closed

Solution here:

```C++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string inputstr;
    int linecounter = 0;

    ifstream inFile;           // Create the input stream called 'inFile'
    inFile.open("test.txt");   // Using this stream open the file called 'test.txt'

    if (inFile.is_open())      // check to see if the file has been opened
    {
        cout << "File test.txt has been opened\n";
        while (getline(inFile, inputstr))
        {
            cout << inputstr << endl;
            linecounter++;
        }
        inFile.close();        // Close the file
        cout << "The file had " << linecounter << " lines" << endl;
    }
    else
    {
        cout << "Unable to open file test.txt";    // Inform user of file error
    }
    return 0;
}
    



```