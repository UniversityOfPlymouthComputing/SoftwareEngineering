// 513-StaticGlobals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Rect_t.h"

int main()
{
	Rect_t r1 = CreateRect(10, 20);
	display(r1);
	Rect_t r2 = CreateRect(50, 100);
	display(r2);
	updateWidth(r1, 100);
	display(r1);
	updateWidth(r1, 100);
	display(r1);
	cout << "Number of multiplications performed: " << getCount() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
