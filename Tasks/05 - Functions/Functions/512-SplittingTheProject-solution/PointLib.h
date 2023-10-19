#pragma once

#include <iostream>
using namespace std;

// Create a new data type Point, made up of existing data types (2 integers and a float)
struct Point {
    int x;
    int y;
    float length;
};

//Function prototypes
void displayPoint(Point p);
void calculateLength(Point& p);
void flipPoint(Point& p);
Point addPoint(Point p1, Point p2);
