#include "Rect_t.h"

int main()
{
	Rect_t r1 = CreateRect(10, 20);
	display(r1);
	Rect_t r2 = CreateRect(50, 100);
	display(r2);
	updateWidth(r1, 100);
	display(r1);
	updateHeight(r1, 15);
	display(r1);
	cout << "Number of multiplications performed: " << getCount() << endl;

	// Task - uncomment this and try to build the code
	//updateArea(r1);
}
