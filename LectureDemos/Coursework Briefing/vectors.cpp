#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    vector<Point> vec;

    vec.push_back({2,3});
    vec.push_back({4,5});
    vec.push_back({5,6});

    for (Point p : vec) {
        cout << "(" << p.x << "," << p.y << ")" << endl;
    }
    

    return 0;
}