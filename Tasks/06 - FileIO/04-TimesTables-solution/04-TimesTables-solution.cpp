#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream op;
	op.open("tables.txt");
	if (op.is_open() == false) {
		cerr << "Cannot create file" << endl;
		return -1;
	}

	for (unsigned int r = 2; r <= 12; r++) {
		for (unsigned int c = 2; c <= 12; c++) {
			op << r * c << "\t";
		}
		op << endl;
	}
	op << endl;

	op.close();

	return 0;
}
