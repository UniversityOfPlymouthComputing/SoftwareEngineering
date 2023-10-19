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