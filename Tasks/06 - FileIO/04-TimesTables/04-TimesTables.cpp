#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	for (unsigned int r = 2; r <= 12; r++) {
		for (unsigned int c = 2; c <= 12; c++) {
			cout << r * c << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}