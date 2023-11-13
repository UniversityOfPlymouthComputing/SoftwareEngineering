#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "You ran the following program: " << endl;
	cout << argv[0] << endl << endl;

	cout << "With parameters:" << endl;
	for (unsigned int n = 1; n < argc; n++) {
		//cout << argv[n] << endl;
		string str = argv[n];
		cout << str << endl;
	}

}

