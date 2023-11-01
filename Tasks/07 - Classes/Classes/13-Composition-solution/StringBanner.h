#pragma once
#include <iostream>
using namespace std;

namespace COMP1000 {
	class StringBanner
	{
	private:
		string msg;
		char bannerChar;
		void displayLine() {
			for (unsigned int n = 0; n < (msg.length() + 4); n++) {
				cout << bannerChar;
			}
		}
	public:
		//This is the ONLY constructor, so you must use it
		StringBanner(string txt, char bannerCharacter = '*') {
			//Copy message
			msg = txt;
			bannerChar = bannerCharacter;
		}
		void display() {
			displayLine();
			cout << endl;
			cout << bannerChar << " " << msg << " " << bannerChar << endl;
			displayLine();
			cout << endl;
		}
	};
}

