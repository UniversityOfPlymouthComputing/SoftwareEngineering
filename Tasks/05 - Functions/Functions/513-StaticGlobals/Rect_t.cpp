#include "Rect_t.h"

//These are PRIVATE to this source file
static uint32_t calcCount = 0;
static void updateArea(Rect_t& r);

//Globals
Rect_t CreateRect(int w, int h)
{
	Rect_t r = { w,h };
	updateArea(r);
	return r;
}

static void updateArea(Rect_t& r)
{
	//Extended arithmetic to avoid overflow
	r.area = (uint64_t)r.height * (uint64_t)r.width;

	//Keep track of how many times this function is called
	calcCount++;
}

void updateWidth(Rect_t& r, int w)
{
	if (r.width != w) {
		r.width = w;
		updateArea(r);
	}
}

void updateHeight(Rect_t& r, int h)
{
	if (r.height != h) {
		r.height = h;
		updateArea(r);
	}
}

void display(Rect_t& r)
{
	cout << "Width: " << r.width << ", Height: " << r.height << ", Area: " << r.area << endl;
}

int getCount() {
	return calcCount;
}