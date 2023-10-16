#include <iostream>
using namespace std;

#include <stdio.h>
#include <math.h>
double y;

double squareThis(double u) {
    y = u * u;
    cout << "y = %f\n" << y << endl;
    return y;
}

int main() {
    y = 3.0;
    double res = squareThis(y);
    cout << y << " * " << y << " = " << res << endl;
}

