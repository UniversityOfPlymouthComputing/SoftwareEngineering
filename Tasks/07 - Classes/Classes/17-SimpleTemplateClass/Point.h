#pragma once
#include <iostream>
using namespace std;

class Point {

private:
    int x;
    int y;

public:
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }

    //Swap x and y coortinates
    void swap() {
        int temp = x;
        x = y;
        y = temp;
    }

    //Return the max of x and y
    int max() {
        if (x >= y) {
            return x;
        }
        else {
            return y;
        }
    }

    //Display
    void display() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
