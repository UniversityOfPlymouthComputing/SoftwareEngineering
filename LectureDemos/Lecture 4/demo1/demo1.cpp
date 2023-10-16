#include <iostream>
using namespace std;

double squareThis(double u) {
    double y = u * u;
    cout << "y = " << y << endl;
    return y;
}

int main() {
    double y = 3.0;
    double res = squareThis(y);
    cout << "res = " << res << endl;
    cout << "y = " << y << endl;
    cout << "y is " << y << endl;
}
