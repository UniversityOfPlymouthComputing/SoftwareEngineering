#include <iostream>
using namespace std;

class Rect {
    private:
    int width;
    int height;
    long area;

    public:
    Rect(int w, int h) {
        width = w;
        height = h;
        recalculateArea();
    }
    void displayRect() {
        cout << "(" << width << "," << height << ") has the area " << area << endl; 
    }
    void recalculateArea() {
        area = width * height;
    }
    void setWidth(int w) {
        width = w;
        recalculateArea();
    }
    void setHeight(int h) {
        height = h;
        recalculateArea();
    }    

    operator int()
    {
        return area;
    }
};

int main()
{  
    Rect r1(10,10);
    r1.setHeight(20);
    r1.setWidth(10);
    r1.displayRect();

    cout << r1 << endl;
    
    return 0;
}