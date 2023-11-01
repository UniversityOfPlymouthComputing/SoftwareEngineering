#include "StringBanner.h"
using namespace std;

void StringBanner::displayLine() {
	for (unsigned int n = 0; n < (msg.length() + 4); n++) {
		cout << bannerChar;
	}
}

// NOTE that any default parameter values are provided in the header declaration, and not here.
StringBanner::StringBanner(string txt, char bannerCharacter) {
	//Copy message
	msg = txt;
	bannerChar = bannerCharacter;
}

//Move display() here