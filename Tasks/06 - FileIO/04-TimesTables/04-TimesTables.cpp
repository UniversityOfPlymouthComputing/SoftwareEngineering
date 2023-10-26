#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream outputStream;
	outputStream.open("tables.txt");
	if (outputStream.is_open() == false) {
		cerr << "Cannot create file" << endl;
		return -1;
	}
	for (unsigned int r = 2; r <= 12; r++) {
		for (unsigned int c = 2; c <= 12; c++) {
			outputStream << r * c << "\t";
		}
		outputStream << endl;
	}
	outputStream << endl;

	outputStream.close();
	return 0;
}