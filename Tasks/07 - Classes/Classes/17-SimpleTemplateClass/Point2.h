#pragma once
#include <iostream>
using namespace std;

template<class DataType>
class Point2 {

private:
    DataType x;
    DataType y;

public:
    Point2(DataType xx, DataType yy) {
        x = xx;
        y = yy;
    }

    //Swap x and y coortinates
    void swap() {
        DataType temp = x;
        x = y;
        y = temp;
    }

    //Return the max of x and y
    DataType max() {
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
