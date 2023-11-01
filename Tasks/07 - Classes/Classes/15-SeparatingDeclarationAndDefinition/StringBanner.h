#pragma once
#include <iostream>
using namespace std;

class StringBanner
{
private:
	string msg;
	char bannerChar;
	void displayLine();

public:
	//This is the ONLY constructor, so you must use it
	StringBanner(string txt, char bannerCharacter = '*');

	//We finally want to move this one
	void display() {
		displayLine();
		cout << endl;
		cout << bannerChar << " " << msg << " " << bannerChar << endl;
		displayLine();
		cout << endl;
	}
};


