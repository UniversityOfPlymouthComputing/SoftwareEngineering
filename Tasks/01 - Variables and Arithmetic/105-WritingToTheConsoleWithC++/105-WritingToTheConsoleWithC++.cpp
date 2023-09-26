#include <iostream>
#include <iomanip>

//This is a prefix needed for cout and endl
using namespace std;

int main()
{
    // ************************ Using cout *******************************
    cout << "Hello World!" << endl;   // Write Hello World to the terminal

    // ***************** Using cout with newlines ************************
    cout << "Hello Everyone.We are using C++\nWe can still use \\n?\n";

    // ********************** Setting Precision **************************
    int age = 23;
    cout << "My age is  " << age << endl;

    // Setting precision is not so easy?
    float radius = 10.0f;
    float area = 3.415926 * radius * radius;

    cout << fixed;
    cout << setprecision(1);
    cout << "The area of a circle with radius " << radius << " is " << area << endl;

    // You can output complex strings to the terminal
    int p = 3;
    int q = 4;
    cout << "p=" << p << ", q=" << q << endl;
}


