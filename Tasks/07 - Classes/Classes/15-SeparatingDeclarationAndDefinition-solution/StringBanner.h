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
	void display();
};


