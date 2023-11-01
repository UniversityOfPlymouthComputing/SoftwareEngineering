#include "StringBanner.h"
using namespace std;

void StringBanner::displayLine() {
	for (unsigned int n = 0; n < (msg.length() + 4); n++) {
		cout << bannerChar;
	}
}

StringBanner::StringBanner(string txt, char bannerCharacter) {
	//Copy message
	msg = txt;
	bannerChar = bannerCharacter;
}


void StringBanner::display() {
	displayLine();
	cout << endl;
	cout << bannerChar << " " << msg << " " << bannerChar << endl;
	displayLine();
	cout << endl;
}