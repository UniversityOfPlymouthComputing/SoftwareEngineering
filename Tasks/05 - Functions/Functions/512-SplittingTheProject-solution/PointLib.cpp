#include "PointLib.h"

// Displays a point as an x,y coordinate
void displayPoint(Point p)
{
    int xPos = p.x;
    int yPos = p.y;

    cout << "(" << xPos << "," << yPos << ")";
}

// Calculate and return the distance of p from the origin (0,0)
void calculateLength(Point& p)
{
    float h = sqrt(p.x * p.x + p.y * p.y);
    p.length = h; //This would be pointless as p is a copy
}

// Swap the x and y coordinates of p inplace
void flipPoint(Point& p)
{
    //Note that p is the address of a structure in memory
    //
    // De-reference each member using the -> operator when using a pointer
    //
    int prevX = p.x;   //Keep a copy of the previous x member value
    p.x = p.y;        //Update x
    p.y = prevX;       //Update y

    //No need to return anything as we've modified the original!
}

// SOLUTION
Point addPoint(Point p1, Point p2)
{
    Point result = p1;      // Copy p1 into result
    result.x += p2.x;       // Add on the x member value of p2
    result.y += p2.y;       // Add on the y member value of p2
    calculateLength(result);    //Update the length

    return result;
}