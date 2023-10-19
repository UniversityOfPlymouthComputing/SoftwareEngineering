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
void calculateLength(Point* p);
void flipPoint(Point* p);
Point addPoint(Point p1, Point p2);


int main()
{
    //Create two variables of type Point
    Point p1 = { 3, 4, 5.0f };      //Initialised inline

    //Now demonstrate returning a structure
    displayPoint(p1);               //Showing p1
    flipPoint(&p1);                 //Pass the address so p1 can be modified by the function
    displayPoint(p1);               //Showing p4

    calculateLength(&p1);           //Pass the address to the function can modify the structure in-place
    cout << endl << "Length of p1 = " << p1.length << endl; //Simply write it out

}


// Displays a point as an x,y coordinate
void displayPoint(Point p)
{
    int xPos = p.x;
    int yPos = p.y;

    cout << "(" << xPos << "," << yPos << ")";
}

// Calculate and return the distance of p from the origin (0,0)
void calculateLength(Point* p)
{
    float h = sqrt(p->x * p->x + p->y * p->y);
    p->length = h; //This would be pointless as p is a copy
}

// Swap the x and y coordinates of p inplace
void flipPoint(Point* p)
{
    //Note that p is the address of a structure in memory
    //
    // De-reference each member using the -> operator when using a pointer
    //
    int prevX = p->x;   //Keep a copy of the previous x member value
    p->x = p->y;        //Update x
    p->y = prevX;       //Update y

    //No need to return anything as we've modified the original!
}

// SOLUTION
Point addPoint(Point p1, Point p2)
{
    Point result = p1;      // Copy p1 into result
    result.x += p2.x;       // Add on the x member value of p2
    result.y += p2.y;       // Add on the y member value of p2
    calculateLength(&result);    //Update the length

    return result;
}