#include <iostream>
#include <string>
using namespace std;

void starryLine(int N);
void banner(string text);

int main()
{
    banner("Hello COMP1000");
    banner("Hello PROJ200");

    return 0;
}

void starryLine(int N)
{
    for (unsigned int n=0; n<N; n++) {
        cout << "*";
    }
    cout << endl;   
}

void banner(string text)
{
    int N = 4+text.length();

    starryLine(N);
    cout << "* " << text << " *" << endl;
    starryLine(N);
    cout << endl;   
}