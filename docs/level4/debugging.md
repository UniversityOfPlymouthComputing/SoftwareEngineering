In this task you are going to open a "Solution" from within Visual Studio and run the first project. With the help of the built in debugger you will view how the variables are created as the program runs.

| Task | Details |
| :--- | :---   |
| 1    | Open Visual Studio |
| 2    | From the list of options below "Get started", select "Open a project or solution" |
|3     | Navigate to where you cloned the "Software Engineering" repository and select "Tasks" then "01 - Variables and Arithmetic", open the file "variablesAndArithmetic.sln"|
| 4    | From the "Solution Explorer" right-click the line "101-Variables" and select "Set as Startup Project". Then use the small arrow on the left of the line to open up that project.|
| 5    | Under the section "Source Files" click on the line containing "101-Variables.cpp". The editing window should now show the code below.|
| | |

```C
#include <stdio.h>

// This is a single line comment - it does nothing

/*
   This is a block comment. 
   It also does nothing.
*/

//Entry point for your code
int main()
{ // Block opening brace

	char c = 88;				// Character
	short year = 2023;			// Short integer
	int age = 23;				// Integer
	long bigNumber = 123456789;	// Long integer
	long long veryBigNumber = 1LL << 30;	//2^30

	//Floating point numbers
	float pi_f   = 3.1415926535; //Does this work?
	double pi_df = 3.1415926535; //This one is "double precision"

	// The following are not initialised inline
	int serialNumber;			//What value is stored in here at this point?
	serialNumber = 50;


	// TASK: Use the debugger to step through the lines above. 
	//   Hover the mouse over each line to see it's value BEFORE and AFTER each line
	//   Note any discrepancies between the value in the source code and the value reported by the debugger


} // Block closing brace

```
| Task | Details |
| :--- | :---   |
| 6    | Set a 'break point', as the name suggests this is a point in the program (set by you) where the program execution will pause. To do this hover the cursor over the vertical grey bar on the far left of the edit window alongside line 14. A black disc will appear which will turn red if you click it. You have now set a break point on line 14. To remove break point simply click it.  |
| 7    | From the "Debug" menu select "Start debugging" (shortcut F5), the program will now be compiled and run in debug mode. A command window will open with the name of the program that is running in the title bar. The program has no output so all you should see is a flashing cursor in the top left corner. Minimise this window.
|8     | Look for a yellow arrow on top off your break point red disc. The arrow shows the next line the program will execute when you tell it to.|
| 9    | Below the edit window you should see section marked "Autos" and within it a greyed line with a lowercase "c" at the left edge. The column "Value" shows a decimal number and maybbe a character. The far right column "Type" shows char. All this data refers to the variable 'c' on line 14. Why do you think the value is not shown as 88 as set on line 14?|
| 10    | Now lets move the program on one line. Under the "Debug" menu select "Step Over" (shortcut F10). Where is the yellow arrow now? What value does the variable 'c' have now? What value does the variable 'year' have now? You can also see the values of the variables by hovering over them.|
| 11    | Continue to use the "Step Over" command to advance the yellow arrow one line at a time watching the variables as they change. When you go beyond the last line the program will exit. You may have noticed that some of the results are a bit strange, more on that below.|
| 12    | Run the program again with the breakpoint on line 15 so that the variable 'c' has been assigned a value.  Hover the cursor over the 'c' in the source code and the value should show as 88 'X'.  Under the "Debug" menu select "Stop Debugging" (shortcut Shift-F5). Now change line 14 to read: `char c = 'X'    // Character;` Run the program again. What value does 'c' have now? Try the same thing with different values for 'c' and see what happens - referring to an 'ASCII' table (online search) will help explain the results. Note - the range of values that make sense for this is 0 to 127. |
