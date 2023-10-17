#pragma once
#include <iostream>
using namespace std;

struct Rect_t
{
	uint32_t width;
	uint32_t height;
	uint64_t area;
};

//Global function prototypes
Rect_t CreateRect(int w, int h);		//Create a rec of with width and height
void updateWidth(Rect_t& r, int w);		//Set the width
void updateHeight(Rect_t& r, int h);		//Set the height
void display(Rect_t& r);
int getCount();
