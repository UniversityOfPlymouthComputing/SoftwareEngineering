#include <iostream>
using namespace std;

//global x
//int x = 0;

//Project namespace for both variables and code
namespace COMP1000 {
    int x;
    int addOne(int u) {
        return u + 1;
    }
}

int main()
{
    //Fully qualified name is COMP1000::x
    COMP1000::x = 20;
    cout << "x = " << COMP1000::x << endl;
    COMP1000::x = COMP1000::addOne(COMP1000::x);
    cout << "x = " << COMP1000::x << endl;

    //Now infer COMP1000 as the namespace to save on typing and clutter
    using namespace COMP1000;
    x = addOne(x);
    cout << "x = " << x << endl;
}
